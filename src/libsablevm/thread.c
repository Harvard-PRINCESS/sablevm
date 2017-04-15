/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* Thread specific data */
static pthread_key_t _svmv_env_key;	/* key to access thread specific environment data */

/* stack_offset */
static const size_t _svmv_stack_offset =
  (sizeof (_svmt_stack_frame) +
   (SVM_ALIGNMENT - 1)) & ~((size_t) (SVM_ALIGNMENT - 1));

/*
----------------------------------------------------------------------
_svmf_thread_init
----------------------------------------------------------------------
*/

svm_static jint
_svmf_thread_init (void)
{
  /* create key for thread specific data */
  if (pthread_key_create (&_svmv_env_key, NULL) != 0)
    {
      goto error;
    }

  return JNI_OK;

error:
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_get_current_env
----------------------------------------------------------------------
*/

static _svmt_JNIEnv *
_svmf_get_current_env (void)
{
  return (_svmt_JNIEnv *) pthread_getspecific (_svmv_env_key);
}

/*
----------------------------------------------------------------------
_svmf_set_current_env
----------------------------------------------------------------------
*/

static void
_svmf_set_current_env (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  int error =
#endif
    pthread_setspecific (_svmv_env_key, env);

  assert (!error);
}

/*
----------------------------------------------------------------------
_svmf_stack_init_defaults
----------------------------------------------------------------------
*/

svm_static void
_svmf_stack_init_defaults (_svmt_JavaVM *vm)
{
  vm->stack_min_size = SVM_STACK_DEFAULT_MIN_SIZE;
  vm->stack_max_size = SVM_STACK_DEFAULT_MAX_SIZE;
  vm->stack_allocation_increment = SVM_STACK_DEFAULT_ALLOCATION_INCREMENT;
}

/*
----------------------------------------------------------------------
_svmf_stack_init
----------------------------------------------------------------------
*/

svm_static jint
_svmf_stack_init (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  size_t lrefs_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
  jint lrefs_count = SVM_FRAME_NATIVE_REFS_MIN;
  size_t lrefs_size =
    _svmf_aligned_size_t ((lrefs_count +
			   2) * sizeof (_svmt_stack_native_reference));
  size_t frame_size = lrefs_offset + lrefs_size;
  size_t alloc_size;

  if (frame_size <= vm->stack_min_size)
    {
      alloc_size = vm->stack_min_size;
    }
  else if (vm->stack_max_size == 0 || frame_size <= vm->stack_max_size)
    {
      alloc_size = vm->stack_min_size + _svmf_aligned_to_increment
	(frame_size - vm->stack_min_size, vm->stack_allocation_increment);
    }
  else
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  env->stack.start = _svmf_malloc (alloc_size);

  if (env->stack.start == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  env->stack.current_frame = env->stack.start;
  env->stack.end = ((char *) env->stack.start) + alloc_size;

  env->stack.current_frame->previous_offset = 0;
  env->stack.current_frame->end_offset = frame_size;
  env->stack.current_frame->method = &vm->stack_bottom_method;
  env->stack.current_frame->stack_trace_element = NULL;
  env->stack.current_frame->lock_count = 0;
  env->stack.current_frame->this = NULL;
  env->stack.current_frame->pc = vm->stack_bottom_method.frame_info->code;
  env->stack.current_frame->stack_size = 0;

  {
    _svmt_stack_native_reference *lrefs =
      (_svmt_stack_native_reference *) (void
					*) (((char *) env->stack.
					     current_frame) +
					    env->stack.current_frame->
					    end_offset);
    jint i;

    lrefs[-1].jint = lrefs_count;
    lrefs[-2].size_t = lrefs_size;

    lrefs =
      (_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						 lrefs_size);

    for (i = 0; i < lrefs_count; i++)
      {
	if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	  {
	    return JNI_ERR;
	  }
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_ensure_stack_capacity
----------------------------------------------------------------------
*/

svm_static jint
_svmf_ensure_stack_capacity (_svmt_JNIEnv *env, size_t frame_size)
{
  void *current_frame = env->stack.current_frame;
  void *current_frame_end =
    ((char *) current_frame) + env->stack.current_frame->end_offset;
  void *stack_end = env->stack.end;
  size_t available = ((char *) stack_end) - ((char *) current_frame_end);

  assert (stack_end >= current_frame_end);

#ifdef STATISTICS

  {
    _svmt_JavaVM *vm = env->vm;
    void *stack_start = env->stack.start;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) current_frame;

    size_t current_stack_size = ((char *) frame) - ((char *) stack_start);

    if (current_stack_size > vm->max_stack_size)
      {
	_svmt_method_info *method = env->stack.current_frame->method;

	vm->max_stack_size = current_stack_size;
	vm->stack_local_count = 0;
	vm->stack_local_split_count = 0;

	while (method != &vm->stack_bottom_method)
	  {
	    if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	      {
		vm->stack_local_count += method->frame_info->local_count;
		vm->stack_local_split_count +=
		  method->frame_info->local_split_count;
	      }

	    frame = (_svmt_stack_frame *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	  }
      }
  }

#endif

  if (frame_size > available)
    {
      _svmt_JavaVM *vm = env->vm;
      size_t stack_increment = vm->stack_allocation_increment;

      if (stack_increment == 0)
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}
      else
	{
	  size_t min_growth = frame_size - available;
	  void *stack_start = env->stack.start;
	  size_t current_frame_offset =
	    ((char *) current_frame) - ((char *) stack_start);

	  /* growth sould be a multiple of stack_increment large
	     enough to hold min_growth */
	  size_t growth =
	    _svmf_aligned_to_increment (min_growth, stack_increment);
	  size_t current_size = ((char *) stack_end) - ((char *) stack_start);
	  size_t new_size = current_size + growth;
	  void *new_stack;

	  /* detect overflows */
	  if ((vm->stack_max_size != 0 && new_size > vm->stack_max_size) ||
	      new_size <= current_size)
	    {
	      _svmf_error_OutOfMemoryError (env);
	      return JNI_ERR;
	    }

	  new_stack = _svmf_realloc (stack_start, new_size);

	  /* out of memory */
	  if (new_stack == NULL)
	    {
	      _svmf_error_OutOfMemoryError (env);
	      return JNI_ERR;
	    }

	  env->stack.start = new_stack;
	  env->stack.end = ((char *) new_stack) + new_size;
	  env->stack.current_frame =
	    (_svmt_stack_frame *) (void *) (((char *) new_stack) +
					    current_frame_offset);
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_halt_if_requested
----------------------------------------------------------------------
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function. */

svm_static void
_svmf_halt_if_requested (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  assert (env->thread_status != SVM_THREAD_STATUS_HALTED);
  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED);
  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);

  /* is halting requested by another thread? */
  while (env->thread_status == SVM_THREAD_STATUS_HALT_REQUESTED)
    {
      env->thread_status = SVM_THREAD_STATUS_HALTED;

      /* there must be a reason for halting */
      assert (env->status_flags != SVM_THREAD_STATUS_FLAGS_NONE);

      /* are we halting for (among other things) stopping the world? */
      if (_svmf_is_set_flag
	  (env->status_flags, SVM_THREAD_STATUS_FLAGS_STOP_THE_WORLD))
	{
	  assert (vm->stop_the_world.pending_halt_thread_count > 0);

	  vm->stop_the_world.pending_halt_thread_count--;

	  /* is there any other thread pending halt? */
	  if (vm->stop_the_world.pending_halt_thread_count == 0)
	    {
	      /* no, so signal requesting thread */
	      _svmm_cond_signal (vm->stop_the_world.requesting_thread_cond);
	    }
	}

      /* are we halting for (among other things) suspending this thread? */
      if (_svmf_is_set_flag
	  (env->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND))
	{
	  _svmt_JNIEnv *current;

	  /* signal all threads that requested the suspension of this
	     thread. suspender_list could be NULL if the thread has 
	     suspended itself and is the only that call suspend_thread. */
	  current = env->suspension.suspender_list;

	  while (current != NULL)
	    {
	      _svmm_cond_signal (current->suspension.cond);
	      current = current->suspension.suspender_list_next;
	    }
	}

      /* time to halt the thread */
      do
	{
	  _svmm_cond_wait (env->wakeup_cond, vm->global_mutex);
	}
      while (env->thread_status == SVM_THREAD_STATUS_HALTED);
    }

  assert (env->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);
}

/*
----------------------------------------------------------------------
_svmf_periodic_check
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_periodic_check (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  jint status = env->thread_status;
  assert (status == SVM_THREAD_STATUS_RUNNING_JAVA ||
	  status == SVM_THREAD_STATUS_HALT_REQUESTED);
#endif

  /* is stopping the world requested by another thread? */
  if (env->thread_status == SVM_THREAD_STATUS_HALT_REQUESTED)
    {
      _svmt_JavaVM *vm = env->vm;

      _svmm_mutex_lock (vm->global_mutex);

      _svmf_halt_if_requested (env);

      _svmm_mutex_unlock ();
    }
}

/*   
---------------------------------------------------------------------   
_svmf_is_suspended
---------------------------------------------------------------------   
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function. */

static jboolean
_svmf_is_suspended (_svmt_JNIEnv *target)
{
  jboolean result = JNI_FALSE;

  if (((target->thread_status == SVM_THREAD_STATUS_HALTED) ||
       (target->thread_status ==
	SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED))
      && _svmf_is_set_flag (target->status_flags,
			    SVM_THREAD_STATUS_FLAGS_SUSPEND))
    {
      result = JNI_TRUE;
    }

  return result;
}

/*   
---------------------------------------------------------------------   
_svmf_suspend_thread
---------------------------------------------------------------------   
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function.  Once the thread is
   halted, the calling thread should release the lock until just
   prior the call to resume_thread. 

   returns: 
     JNI_FALSE: the thread was already suspended
     JNI_TRUE: the thread has been suspended by this call
*/

static jboolean
_svmf_suspend_thread (_svmt_JNIEnv *env, _svmt_JNIEnv *target)
{
  jboolean result, succeeded;
  _svmt_JavaVM *vm = env->vm;

  /* halt if requested */
  _svmf_halt_if_requested (env);

  /* suspend the calling thread */
  if (target == env)
    {
      assert (target->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);

      target->thread_status = SVM_THREAD_STATUS_HALTED;

      _svmm_set_flag (target->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND);

      assert (env->suspension.suspender_list_next == NULL);

      /* halt the thread */
      do
	{
	  _svmm_cond_wait (env->wakeup_cond, vm->global_mutex);
	}
      while (_svmf_is_suspended (target));
    }
  /* suspend another thread */
  else
    {
      do
	{
	  switch (target->thread_status)
	    {
	    case SVM_THREAD_STATUS_RUNNING_JAVA:
	      {
		succeeded = _svmm_compare_and_swap
		  (target->thread_status,
		   SVM_THREAD_STATUS_RUNNING_JAVA,
		   SVM_THREAD_STATUS_HALT_REQUESTED);
	      }
	      break;

	    case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED:
	      {
		succeeded = _svmm_compare_and_swap
		  (target->thread_status,
		   SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED,
		   SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);
	      }
	      break;

	    case SVM_THREAD_STATUS_HALT_REQUESTED:
	    case SVM_THREAD_STATUS_HALTED:
	    case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED:
	      {
		succeeded = JNI_TRUE;
	      }
	      break;

	    default:
	      {
		succeeded = JNI_FALSE;	/* to keep compiler happy */
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}
      while (!succeeded);

      if (_svmf_is_suspended (target))
	{
	  /* The thread was already halted for suspension */
	  result = JNI_FALSE;
	  goto end;
	}

      _svmm_set_flag (target->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND);

      if (target->thread_status == SVM_THREAD_STATUS_HALTED ||
	  target->thread_status ==
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED)
	{
	  /* The thread was already halted for some reason or not
	     running java */
	  result = JNI_TRUE;
	  goto end;
	}

      assert (target->thread_status == SVM_THREAD_STATUS_HALT_REQUESTED);
      assert (env->suspension.suspender_list_next == NULL);

      env->suspension.suspender_list_next = target->suspension.suspender_list;
      target->suspension.suspender_list = env;

      /* wait until target is halted */
      do
	{
	  _svmm_cond_wait (env->suspension.cond, vm->global_mutex);
	}
      while (target->thread_status == SVM_THREAD_STATUS_HALT_REQUESTED);

      /* once the target thread is halted (or it has been resumed by
         another thread) */
      {
	_svmt_JNIEnv *previous = NULL;
	_svmt_JNIEnv *current = target->suspension.suspender_list;

	/* remove this thread from the suspender_list */
	while (current != env)
	  {
	    previous = current;
	    current = current->suspension.suspender_list_next;

	    assert (current != NULL);
	  }

	assert (current == env);

	if (previous != NULL)
	  {
	    previous->suspension.suspender_list_next =
	      env->suspension.suspender_list_next;
	  }
	else
	  {
	    target->suspension.suspender_list =
	      env->suspension.suspender_list_next;
	  }

	env->suspension.suspender_list_next = NULL;
      }
    }

  result = JNI_TRUE;

end:

  return result;
}


/*   
---------------------------------------------------------------------   
_svmf_resume_thread
---------------------------------------------------------------------   
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function.

   returns: 
     JNI_FALSE: the thread was already resumed
     JNI_TRUE: the thread has been resumed by this call
*/

static jboolean
_svmf_resume_thread (_svmt_JNIEnv *env, _svmt_JNIEnv *target)
{
  jboolean result;

  /* halt if requested */
  _svmf_halt_if_requested (env);

  assert (env->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);

  if (target == env)
    {
      /* if the current thread calls this function on itself, it cant
         be sleeping */
      assert (!_svmf_is_set_flag
	      (target->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND));

      result = JNI_FALSE;
      goto end;
    }

  if (!_svmf_is_set_flag
      (target->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND))
    {
      /* target thread is not suspended */

      result = JNI_FALSE;
      goto end;
    }

  /* unsuspend target thread */
  _svmm_clear_flag (target->status_flags, SVM_THREAD_STATUS_FLAGS_SUSPEND);

  if (target->thread_status == SVM_THREAD_STATUS_HALT_REQUESTED)
    {
      _svmt_JNIEnv *current;

      /* signal all threads that have requested the suspension of the
         target thread. */
      current = target->suspension.suspender_list;

      while (current != NULL)
	{
	  _svmm_cond_signal (current->suspension.cond);
	  current = current->suspension.suspender_list_next;
	}
    }

  if (target->status_flags != SVM_THREAD_STATUS_FLAGS_NONE)
    {
      /* target must remain halted for some other reason */

      result = JNI_TRUE;
      goto end;
    }

  switch (target->thread_status)
    {
    case SVM_THREAD_STATUS_HALTED:
      {
	target->thread_status = SVM_THREAD_STATUS_RUNNING_JAVA;
	_svmm_cond_signal (target->wakeup_cond);
      }
      break;

    case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED:
      {
	target->thread_status =
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED;
	_svmm_cond_signal (target->wakeup_cond);
      }
      break;

    case SVM_THREAD_STATUS_HALT_REQUESTED:
      {
	target->thread_status = SVM_THREAD_STATUS_RUNNING_JAVA;
      }
      break;

    case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED:
    case SVM_THREAD_STATUS_RUNNING_JAVA:
    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
      break;
    }

  result = JNI_TRUE;

end:
  return result;
}

/*
----------------------------------------------------------------------
_svmf_stop_the_world
----------------------------------------------------------------------
*/

/* IMPORTANT: The calling thread should hold the lock on
   vm->global_mutex when calling this function.  Once the world is
   stopped, the calling thread should release the lock until just
   prior the call to resume_the_world. */

svm_static void
_svmf_stop_the_world (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  jint i;

  /* if another thread beat us to it, halt */
  _svmf_halt_if_requested (env);

  /* ok, now we can proceed */
  assert (env->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);
  assert (vm->stop_the_world.pending_halt_thread_count == 0);

  for (i = 0; i < 2; i++)
    {
      _svmt_JNIEnv *current;

      /* visit all threads */
      for (current = ((i == 0) ? vm->threads.user : vm->threads.system);
	   current != NULL; current = current->next)
	{
	  jboolean succeeded;

	  /* skip the running thread */
	  if (current == env)
	    {
	      continue;
	    }

	  /* request halt */
	  do
	    {
	      switch (current->thread_status)
		{
		case SVM_THREAD_STATUS_RUNNING_JAVA:
		  {
		    succeeded = _svmm_compare_and_swap
		      (current->thread_status, SVM_THREAD_STATUS_RUNNING_JAVA,
		       SVM_THREAD_STATUS_HALT_REQUESTED);

		    if (succeeded)
		      {
			vm->stop_the_world.pending_halt_thread_count++;
		      }
		  }
		  break;

		case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED:
		  {
		    succeeded = _svmm_compare_and_swap
		      (current->thread_status,
		       SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED,
		       SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);
		  }
		  break;

		case SVM_THREAD_STATUS_HALT_REQUESTED:
		case SVM_THREAD_STATUS_HALTED:
		case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED:
		  {
		    succeeded = JNI_TRUE;
		  }
		  break;

		default:
		  {
		    succeeded = JNI_FALSE;	/* to keep compiler happy */
		    _svmm_fatal_error ("impossible control flow");
		  }
		  break;
		}
	    }
	  while (!succeeded);

	  _svmm_set_flag (current->status_flags,
			  SVM_THREAD_STATUS_FLAGS_STOP_THE_WORLD);
	}
    }

  /* wait for other threads to halt */
  while (vm->stop_the_world.pending_halt_thread_count != 0)
    {
      _svmm_cond_wait (vm->stop_the_world.requesting_thread_cond,
		       vm->global_mutex);
    }

  /* the world is stopped! we can resume... */
  return;
}

/*
----------------------------------------------------------------------
_svmf_resume_the_world
----------------------------------------------------------------------
*/

/* IMPORTANT: The calling thread should acquire the lock on
   vm->global_mutex before calling this function.  Of course, this
   function should not be invoked unless the world has been already
   stopped by the calling thread. */

svm_static void
_svmf_resume_the_world (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  jint i;

  assert (env->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);
  assert (vm->stop_the_world.pending_halt_thread_count == 0);

  for (i = 0; i < 2; i++)
    {
      _svmt_JNIEnv *current;

      /* visit all threads */
      for (current = ((i == 0) ? vm->threads.user : vm->threads.system);
	   current != NULL; current = current->next)
	{
	  /* skip the running thread */
	  if (current == env)
	    {
	      continue;
	    }


	  assert (_svmf_is_set_flag
		  (current->status_flags,
		   SVM_THREAD_STATUS_FLAGS_STOP_THE_WORLD));

	  /* clear stop the world status */
	  _svmm_clear_flag (current->status_flags,
			    SVM_THREAD_STATUS_FLAGS_STOP_THE_WORLD);

	  if (current->status_flags == SVM_THREAD_STATUS_FLAGS_NONE)
	    {
	      switch (current->thread_status)
		{
		case SVM_THREAD_STATUS_HALTED:
		  {
		    current->thread_status = SVM_THREAD_STATUS_RUNNING_JAVA;
		    _svmm_cond_signal (current->wakeup_cond);
		  }
		  break;

		case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED:
		  {
		    current->thread_status =
		      SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED;
		    _svmm_cond_signal (current->wakeup_cond);
		  }
		  break;

		case SVM_THREAD_STATUS_HALT_REQUESTED:
		case SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED:
		case SVM_THREAD_STATUS_RUNNING_JAVA:
		default:
		  {
		    _svmm_fatal_error ("impossible control flow");
		  }
		  break;
		}
	    }
	}
    }

  /* the world will resume execution as soon as this thread releases
     the global mutex... */
  return;
}

/*
----------------------------------------------------------------------
_svmf_inflate_lock_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmf_inflate_lock_no_exception (_svmt_JNIEnv *env,
				 _svmt_object_instance *instance)
{
  _svmt_JavaVM *vm = env->vm;
  jint status = JNI_OK;
  _svmt_fat_lock *fat_lock;

  _svmm_mutex_lock (vm->global_mutex);

  fat_lock = vm->fat_locks.free_list;

  if (fat_lock != NULL)
    {
      assert (fat_lock->recursive_count == 0);
      assert (fat_lock->owner == NULL);

      vm->fat_locks.free_list = fat_lock->next;
      fat_lock->next = NULL;
    }
  else
    {
      if (vm->fat_locks.next_fat_lock_id > SVM_MAX_FATLOCK_ID)
	{
	  status = JNI_ERR;
	}
      else
	{
	  if (_svmm_gzalloc_fat_lock_no_exception (fat_lock) != JNI_OK)
	    {
	      status = JNI_ERR;
	    }
	  else
	    {
	      fat_lock->id = vm->fat_locks.next_fat_lock_id++;
	      vm->fat_locks.array[fat_lock->id] = fat_lock;

	      _svmm_mutex_init (fat_lock->mutex);
	      _svmm_cond_init (fat_lock->cond);
	      _svmm_cond_init (fat_lock->notification_cond);
	    }
	}
    }

  _svmm_mutex_unlock ();

  if (status != JNI_OK)
    {
      return JNI_ERR;
    }

  _svmm_mutex_lock (fat_lock->mutex);

  assert (fat_lock->recursive_count == 0);
  assert (fat_lock->owner == NULL);

  fat_lock->owner = env;

  /* Note that we are NOT incrementing the recursive count in the
     following code.  A thin lock recursive count of 0 is equivalent
     to a fat lock recursive count of 1. */
  fat_lock->recursive_count =
    _svmf_lockword_get_thinlock_recursive_count (instance->lockword) + 1;

  instance->lockword = _svmf_lockword_fatlock
    (fat_lock->id, _svmf_lockword_get_extra_bits (instance->lockword));

  _svmm_mutex_unlock ();

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmm_stopping_java
----------------------------------------------------------------------
*/

#ifndef NDEBUG

#if defined(__func__)

#define _svmm_stopping_java(env)				\
_svmm_stopping_java_aux(env, __FILE__, __func__, __LINE__)

#elif defined(__FUNCTION__)

#define _svmm_stopping_java(env)				\
_svmm_stopping_java_aux(env, __FILE__, __FUNCTION__, __LINE__)

#else

#define _svmm_stopping_java(env)				\
_svmm_stopping_java_aux(env, __FILE__, "unknown", __LINE__)

#endif

#define _svmm_stopping_java_aux(env, file_, func_, line_)				\
do											\
{											\
  jint last_index = (env->stop_resume.last_index + 1) % SVM_STOP_RESUME_TRACE_SIZE;	\
  env->stop_resume.last_index = last_index;						\
  env->stop_resume.info[last_index].action = "stop";					\
  env->stop_resume.info[last_index].file = file_;					\
  env->stop_resume.info[last_index].func = func_;					\
  env->stop_resume.info[last_index].line = line_;					\
  env->stop_resume.info[last_index].entry = env->thread_status;				\
  env->stop_resume.info[last_index].exit = -1;						\
  _svmh_stopping_java(env);								\
  env->stop_resume.info[last_index].exit = env->thread_status;				\
} while(JNI_FALSE)

#else

#define _svmm_stopping_java(env)		\
_svmh_stopping_java(env)

#endif

svm_static void
_svmh_stopping_java (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

#ifndef NDEBUG
  jint status = env->thread_status;

  if (status != SVM_THREAD_STATUS_RUNNING_JAVA &&
      status != SVM_THREAD_STATUS_HALT_REQUESTED)
    {
      jint last_index = env->stop_resume.last_index;
      jint current = last_index;

      do
	{
	  current = (current + 1) % SVM_STOP_RESUME_TRACE_SIZE;

	  if (env->stop_resume.info[current].action != NULL)
	    {
	      _svmf_printf (env, stderr, "%s %s %s %d %d %d\n",
			    env->stop_resume.info[current].action,
			    env->stop_resume.info[current].file,
			    env->stop_resume.info[current].func,
			    env->stop_resume.info[current].line,
			    env->stop_resume.info[current].entry,
			    env->stop_resume.info[current].exit);
	      fflush (NULL);
	    }
	}
      while (current != last_index);
    }

  assert (status == SVM_THREAD_STATUS_RUNNING_JAVA ||
	  status == SVM_THREAD_STATUS_HALT_REQUESTED);
#endif

  if (!_svmm_compare_and_swap
      (env->thread_status, SVM_THREAD_STATUS_RUNNING_JAVA,
       SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED))
    {
      _svmm_mutex_lock (vm->global_mutex);

      _svmf_halt_if_requested (env);

      assert (env->thread_status == SVM_THREAD_STATUS_RUNNING_JAVA);

      env->thread_status =
	SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED;

      _svmm_mutex_unlock ();
    }
}

/*
----------------------------------------------------------------------
_svmm_resuming_java
----------------------------------------------------------------------
*/

#ifndef NDEBUG

#if defined(__func__)

#define _svmm_resuming_java(env)				\
_svmm_resuming_java_aux(env, __FILE__, __func__, __LINE__)

#elif defined(__FUNCTION__)

#define _svmm_resuming_java(env)				\
_svmm_resuming_java_aux(env, __FILE__, __FUNCTION__, __LINE__)

#else

#define _svmm_resuming_java(env)				\
_svmm_resuming_java_aux(env, __FILE__, "unknown", __LINE__)

#endif

#define _svmm_resuming_java_aux(env, file_, func_, line_)				\
do											\
{											\
  jint last_index = (env->stop_resume.last_index + 1) % SVM_STOP_RESUME_TRACE_SIZE;	\
  env->stop_resume.last_index = last_index;						\
  env->stop_resume.info[last_index].action = "resume";					\
  env->stop_resume.info[last_index].file = file_;					\
  env->stop_resume.info[last_index].func = func_;					\
  env->stop_resume.info[last_index].line = line_;					\
  env->stop_resume.info[last_index].entry = env->thread_status;				\
  env->stop_resume.info[last_index].exit = -1;						\
  _svmh_resuming_java(env);								\
  env->stop_resume.info[last_index].exit = env->thread_status;				\
} while(JNI_FALSE)

#else

#define _svmm_resuming_java(env)		\
_svmh_resuming_java(env)

#endif

svm_static void
_svmh_resuming_java (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

#ifndef NDEBUG
  jint status = env->thread_status;

  if (status != SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED &&
      status != SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED)
    {
      jint last_index = env->stop_resume.last_index;
      jint current = last_index;

      do
	{
	  current = (current + 1) % SVM_STOP_RESUME_TRACE_SIZE;

	  if (env->stop_resume.info[current].action != NULL)
	    {
	      _svmf_printf (env, stderr, "%s %s %s %d %d %d\n",
			    env->stop_resume.info[current].action,
			    env->stop_resume.info[current].file,
			    env->stop_resume.info[current].func,
			    env->stop_resume.info[current].line,
			    env->stop_resume.info[current].entry,
			    env->stop_resume.info[current].exit);
	      fflush (NULL);
	    }
	}
      while (current != last_index);
    }

  assert (status == SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED ||
	  status == SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);
#endif

  if (!_svmm_compare_and_swap
      (env->thread_status,
       SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED,
       SVM_THREAD_STATUS_RUNNING_JAVA))
    {
      _svmm_mutex_lock (vm->global_mutex);

      while (env->thread_status ==
	     SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED)
	{
	  _svmm_cond_wait (env->wakeup_cond, vm->global_mutex);
	}

      assert (env->thread_status ==
	      SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED);

      env->thread_status = SVM_THREAD_STATUS_RUNNING_JAVA;

      _svmm_mutex_unlock ();
    }
}

/*
----------------------------------------------------------------------
_svmf_enter_object_monitor
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_enter_object_monitor (_svmt_JNIEnv *env,
			    _svmt_object_instance *instance)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_word old_lockword;
#ifndef NDEBUG
  const char *type_name = instance->vtable->type->name;
#endif

  assert (instance != NULL);

retry:
  old_lockword = instance->lockword;

  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED);
  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);

  {
    _svmt_word new_lockword = env->thread.thinlock_id |
      _svmf_lockword_get_extra_bits (old_lockword);

    if (_svmm_compare_and_swap
	(instance->lockword, _svmf_lockword_get_extra_bits (old_lockword),
	 new_lockword))
      {
	/* thin lock acquired */
	return JNI_OK;
      }
  }

  /* Either the object is already locked, or the lock is inflated. */

  if (_svmf_lockword_is_thin (old_lockword))
    {
      /* it is a thin lock */

      if (_svmf_lockword_get_thinlock_id (old_lockword) ==
	  env->thread.thinlock_id)
	{
	  /* the thinlock is already owned by the current thread */

	  jint recursive_count =
	    _svmf_lockword_get_thinlock_recursive_count (old_lockword);

	  assert (recursive_count <= SVM_THINLOCK_MAX_RECURSIVE_COUNT);

	  if (++recursive_count <= SVM_THINLOCK_MAX_RECURSIVE_COUNT)
	    {
	      instance->lockword = _svmf_lockword_thinlock
		(env->thread.thinlock_id, recursive_count,
		 _svmf_lockword_get_extra_bits (old_lockword));

	      /* thin lock re-entered */
	      return JNI_OK;
	    }

	  /* Overflow!  We must inflate the lock. */

	  if (_svmf_inflate_lock_no_exception (env, instance) != JNI_OK)
	    {
	      _svmf_error_OutOfMemoryError (env);
	      return JNI_ERR;
	    }

	  /* OK, retry locking with the new fat lock */
	  goto retry;
	}
      else
	{
	  /* contention: the thinlock is owned by another thread */

	  jint owner_id = _svmf_lockword_get_thread_id (old_lockword);
	  _svmt_JNIEnv *owner = vm->threads.array[owner_id];
	  _svmt_word old_flag;
	  jboolean notified;
	  _svmt_word refetched_lockword;

	  /* If we read "old_lockword" before the thinlock was
	     actually acquired by another thread, retry. */
	  if (owner == NULL)
	    {
	      goto retry;
	    }

	  /* notify owning thread that inflation is requested */
	  _svmm_mutex_lock (owner->contention.owner.mutex);

	  old_flag = owner->contention.owner.flag;

	  owner->contention.owner.flag = 1;

	  /* re-fetch the instance's lockword, now that the thread has
	     been notified */
	  refetched_lockword = instance->lockword;

	  if (_svmf_lockword_is_thin (refetched_lockword)
	      && _svmf_lockword_get_thinlock_id (refetched_lockword) ==
	      owner->thread.thinlock_id)
	    {
	      /* the thinlock owner is still the same and has been notified */

	      notified = JNI_TRUE;

	      /* add this thread into the lock owner's wait_list */
	      env->contention.requester.wait_list_next =
		owner->contention.owner.wait_list;
	      owner->contention.owner.wait_list = env;

	      *(env->contention.requester.jobject) = instance;
	    }
	  else
	    {
	      /* the lock is not thin anymore or the owner has
	         changed, so restore the contention flag to its
	         original value */

	      notified = JNI_FALSE;

	      owner->contention.owner.flag = old_flag;
	    }

	  _svmm_mutex_unlock ();

	  /* if the owner has changed, retry from scratch */
	  if (!notified)
	    {
	      /* retry locking */
	      goto retry;
	    }

	  /* This one is tricky!  To avoid deadlocks, transition to
	     stopping java must be done while the owner's contention
	     mutex is released. */
	  _svmm_stopping_java (env);

	  /* IMPORTANT: From now on, we MUST NOT read or write any
	     value which can be changed by GC or any other "stop the
	     word" dependent operation. */

	  /* transition made; reacquire lock */
	  _svmm_mutex_lock (owner->contention.owner.mutex);

	  /* while thread is still on the owner's wait list, then
	     wait */

#ifndef NDEBUG
	  if (vm->verbose_synchronization)
	    {
	      /* dump a stack trace on contention */

	      _svmf_printf (env, stderr, "*** CONTENTION ***\n");
	      _svmf_printf (env, stderr,
			    "Thread (%d,%d) already owns the thin monitor of type %s seeked by thread (%d,%d)\n",
			    owner->thread.id, owner->thread.pthread,
			    type_name, env->thread.id, env->thread.pthread);

	      _svmf_dump_stack_trace (env);
	    }
#endif

	  do
	    {
	      _svmt_JNIEnv *current = owner->contention.owner.wait_list;

	      while (current != NULL && current != env)
		{
		  current = current->contention.requester.wait_list_next;
		}

	      if (current == NULL)
		{
		  break;
		}

	      assert (current == env);
	      assert (owner->contention.owner.flag == 1);

	      _svmm_cond_wait (env->contention.requester.cond,
			       owner->contention.owner.mutex);
	    }
	  while (JNI_TRUE);

#ifndef NDEBUG
	  if (vm->verbose_synchronization)
	    {
	      /* tell about resolved contention */

	      _svmf_printf (env, stderr, "*** RESOLVED CONTENTION ***\n");
	      _svmf_printf (env, stderr,
			    "Thread (%d,%d) has finally got hold of the monitor.\n",
			    env->thread.id, env->thread.pthread);
	    }
#endif

	  _svmm_mutex_unlock ();

	  _svmm_resuming_java (env);

	  /* GC could have moved things around... */
	  instance = *(env->contention.requester.jobject);
	  *(env->contention.requester.jobject) = NULL;

	  /* retry locking */
	  goto retry;
	}
    }
  else
    {
      /* it is a fat lock */

      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (old_lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];
      jint status = JNI_OK;
      jobject obj;

      if (_svmm_new_native_local (env, obj) != JNI_OK)
	{
	  return JNI_ERR;
	}

      /* save reference in case GC happens */
      *obj = instance;

      _svmm_stopping_java (env);

      /* IMPORTANT: From now on, we MUST NOT read or write any
         value which can be changed by GC or any other "stop the
         word" dependent operation. */

      _svmm_mutex_lock (fat_lock->mutex);

#ifndef NDEBUG
      /* dump a stack trace on contention */

      {
	jboolean contention_happened = JNI_FALSE;

	if (vm->verbose_synchronization)
	  {
	    if (fat_lock->recursive_count != 0 && fat_lock->owner != env)
	      {
		contention_happened = JNI_TRUE;

		_svmf_printf (env, stderr, "*** CONTENTION ***\n");
		_svmf_printf (env, stderr,
			      "Thread (%d,%d) already owns the fat monitor %p of type %s seeked by thread (%d,%d)\n",
			      fat_lock->owner->thread.id,
			      fat_lock->owner->thread.pthread, fat_lock,
			      type_name, env->thread.id, env->thread.pthread);

		_svmf_dump_stack_trace (env);

	      }
	  }
#endif

	/* wait until no other thread owns the lock */
	while (fat_lock->recursive_count != 0 && fat_lock->owner != env)
	  {
	    _svmm_cond_wait (fat_lock->cond, fat_lock->mutex);
	  }

#ifndef NDEBUG
	if (vm->verbose_synchronization)
	  {
	    /* tell about resolved contention */

	    if (contention_happened)
	      {
		_svmf_printf (env, stderr, "*** RESOLVED CONTENTION ***\n");
		_svmf_printf (env, stderr,
			      "Thread (%d,%d) has finally got hold of the monitor.\n",
			      env->thread.id, env->thread.pthread);
	      }
	  }
      }
#endif

      if (fat_lock->recursive_count == 0)
	{
	  fat_lock->recursive_count = 1;
	  fat_lock->owner = env;

#ifndef NDEBUG
	  if (vm->verbose_synchronization)
	    {
	      /* dump a stack trace on fat lock acquisition */

	      _svmf_printf (env, stderr, "*** FAT LOCK ACQUIRED ***\n");
	      _svmf_printf (env, stderr,
			    "Thread (%d,%d) aquires monitor %p of type %s\n",
			    env->thread.id, env->thread.pthread, fat_lock,
			    type_name);

	      _svmf_dump_stack_trace (env);
	    }
#endif
	}
      else
	{
	  assert (fat_lock->owner == env);


	  fat_lock->recursive_count++;

	  /* overflow? */
	  if (fat_lock->recursive_count < 0)
	    {
	      /* restore recursive count */
	      fat_lock->recursive_count--;

	      status = JNI_ERR;
	    }
	}

      _svmm_mutex_unlock ();

      _svmm_resuming_java (env);

      _svmm_free_native_local (env, obj);

      if (status != JNI_OK)
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}

      return JNI_OK;
    }
}

/*
----------------------------------------------------------------------
_svmf_enter_object_monitor_non_blocking
----------------------------------------------------------------------
*/

inline svm_static jint
_svmh_enter_object_monitor_non_blocking (_svmt_JNIEnv *env,
					 _svmt_object_instance *instance,
					 jboolean *succeeded)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_word old_lockword;
#ifndef NDEBUG
  const char *type_name = instance->vtable->type->name;
#endif

  assert (instance != NULL);

retry:
  old_lockword = instance->lockword;

  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED);
  assert (env->thread_status !=
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED);

  {
    _svmt_word new_lockword = env->thread.thinlock_id |
      _svmf_lockword_get_extra_bits (old_lockword);

    if (_svmm_compare_and_swap
	(instance->lockword, _svmf_lockword_get_extra_bits (old_lockword),
	 new_lockword))
      {
	/* thin lock acquired */
	*succeeded = JNI_TRUE;
	return JNI_OK;
      }
  }

  /* Either the object is already locked, or the lock is inflated. */

  if (_svmf_lockword_is_thin (old_lockword))
    {
      /* it is a thin lock */

      if (_svmf_lockword_get_thinlock_id (old_lockword) ==
	  env->thread.thinlock_id)
	{
	  /* the thinlock is already owned by the current thread */

	  jint recursive_count =
	    _svmf_lockword_get_thinlock_recursive_count (old_lockword);

	  assert (recursive_count <= SVM_THINLOCK_MAX_RECURSIVE_COUNT);

	  if (++recursive_count <= SVM_THINLOCK_MAX_RECURSIVE_COUNT)
	    {
	      instance->lockword = _svmf_lockword_thinlock
		(env->thread.thinlock_id, recursive_count,
		 _svmf_lockword_get_extra_bits (old_lockword));

	      /* thin lock re-entered */
	      *succeeded = JNI_TRUE;
	      return JNI_OK;
	    }

	  /* Overflow!  We must inflate the lock. */

	  if (_svmf_inflate_lock_no_exception (env, instance) != JNI_OK)
	    {
	      _svmf_error_OutOfMemoryError (env);
	      return JNI_ERR;
	    }

	  /* OK, retry locking with the new fat lock */
	  goto retry;
	}
      else
	{
	  /* contention: the thinlock is owned by another thread */

	  *succeeded = JNI_FALSE;
	  return JNI_OK;
	}
    }
  else
    {
      /* it is a fat lock */

      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (old_lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];
      jint status = JNI_OK;
      jobject obj;

      if (_svmm_new_native_local (env, obj) != JNI_OK)
	{
	  return JNI_ERR;
	}

      /* save reference in case GC happens */
      *obj = instance;

      _svmm_stopping_java (env);

      /* IMPORTANT: From now on, we MUST NOT read or write any
         value which can be changed by GC or any other "stop the
         word" dependent operation. */

      _svmm_mutex_lock (fat_lock->mutex);

      if (fat_lock->recursive_count == 0)
	{
	  fat_lock->recursive_count = 1;
	  fat_lock->owner = env;
	  *succeeded = JNI_TRUE;

#ifndef NDEBUG
	  if (vm->verbose_synchronization)
	    {
	      /* dump a stack trace on fat lock acquisition */

	      _svmf_printf (env, stderr, "*** FAT LOCK ACQUIRED ***\n");
	      _svmf_printf (env, stderr,
			    "Thread (%d,%d) aquires monitor %p of type %s\n",
			    env->thread.id, env->thread.pthread, fat_lock,
			    type_name);

	      _svmf_dump_stack_trace (env);
	    }
#endif
	}
      else if (fat_lock->owner == env)
	{
	  assert (fat_lock->owner == env);


	  fat_lock->recursive_count++;

	  /* overflow? */
	  if (fat_lock->recursive_count < 0)
	    {
	      /* restore recursive count */
	      fat_lock->recursive_count--;

	      status = JNI_ERR;
	    }
	  else
	    {
	      *succeeded = JNI_TRUE;
	    }
	}
      else
	{
	  *succeeded = JNI_FALSE;
	}

      _svmm_mutex_unlock ();

      _svmm_resuming_java (env);

      _svmm_free_native_local (env, obj);

      if (status != JNI_OK)
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}

      return JNI_OK;
    }
}

/*
----------------------------------------------------------------------
_svmf_exit_object_monitor
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_exit_object_monitor (_svmt_JNIEnv *env, _svmt_object_instance *instance)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_word old_lockword;

  assert (instance != NULL);

  old_lockword = instance->lockword;

  if (_svmf_lockword_is_thin (old_lockword))
    {
      /* it is a thin lock */

      jint recursive_count;

      if (_svmf_lockword_get_thinlock_id (old_lockword) !=
	  env->thread.thinlock_id)
	{
	  _svmf_error_IllegalMonitorStateException (env);
	  return JNI_ERR;
	}

      recursive_count =
	_svmf_lockword_get_thinlock_recursive_count (old_lockword);

      if (recursive_count == 0)
	{
	  /* we're releasing the thin lock */
	  instance->lockword = _svmf_lockword_get_extra_bits (old_lockword);
	  goto handle_contention;
	}
      else
	{
	  instance->lockword = _svmf_lockword_thinlock
	    (env->thread.thinlock_id, recursive_count - 1,
	     _svmf_lockword_get_extra_bits (old_lockword));

	  /* we're done */
	  return JNI_OK;
	}
    }
  else
    {
      /* it is a fat lock */

      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (old_lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];
      jint status = JNI_OK;
      jboolean released = JNI_FALSE;

      _svmm_mutex_lock (fat_lock->mutex);

      assert (fat_lock->recursive_count >= 0);

      if (fat_lock->recursive_count == 0 || fat_lock->owner != env)
	{
	  status = JNI_ERR;
	}
      else
	{
	  if (--(fat_lock->recursive_count) == 0)
	    {
	      released = JNI_TRUE;
	      fat_lock->owner = NULL;
	      _svmm_cond_broadcast (fat_lock->cond);
	    }
	}

      _svmm_mutex_unlock ();

      if (status != JNI_OK)
	{
	  _svmf_error_IllegalMonitorStateException (env);
	  return JNI_ERR;
	}

      if (released)
	{
	  goto handle_contention;
	}

      /* we're done */
      return JNI_OK;
    }

handle_contention:

  if (env->contention.owner.flag)
    {
      _svmt_JNIEnv *current;
      jint status = JNI_OK;

      _svmm_mutex_lock (env->contention.owner.mutex);

      current = env->contention.owner.wait_list;

      while (current != NULL)
	{
	  if ((*(current->contention.requester.jobject)) != instance &&
	      _svmf_lockword_is_thin
	      ((*(current->contention.requester.jobject))->lockword))
	    {
	      assert (_svmf_lockword_get_thinlock_id
		      ((*(current->contention.requester.jobject))->
		       lockword) == env->thread.thinlock_id);

	      if (_svmf_inflate_lock_no_exception
		  (env, *(current->contention.requester.jobject)) != JNI_OK)
		{
		  status = JNI_ERR;
		}
	    }

	  _svmm_cond_signal (current->contention.requester.cond);

	  current = current->contention.requester.wait_list_next;
	}

      env->contention.owner.wait_list = NULL;

      env->contention.owner.flag = 0;

      _svmm_mutex_unlock ();

      if (status != JNI_OK)
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}
    }

  /* we're done */
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_thread_start
----------------------------------------------------------------------
*/

svm_static void *
_svmf_thread_start (void *_env)
{
  _svmt_JNIEnv *env = (_svmt_JNIEnv *) _env;
  _svmt_JavaVM *vm = env->vm;

  assert (env->is_alive == JNI_TRUE);

  env->thread.pthread = pthread_self ();
  _svmf_set_current_env (env);

  _svmm_resuming_java (env);

  _svmm_invoke_static_virtualmachine_runthread (env);

  _svmm_mutex_lock (vm->global_mutex);

  _svmf_halt_if_requested (env);

  env->is_alive = JNI_FALSE;

  if (env->previous != NULL)
    {
      env->previous->next = env->next;
    }
  else
    {
      if (env->thread.is_daemon)
	{
	  vm->threads.system = env->next;
	}
      else
	{
	  vm->threads.user = env->next;
	}
    }

  if (env->next != NULL)
    {
      env->next->previous = env->previous;
    }

  _svmm_cond_signal (vm->threads.vm_destruction_cond);

  /* leak it for now... */

  _svmm_mutex_unlock ();

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_thread_native_start
----------------------------------------------------------------------
*/

svm_static _svmt_JNIEnv *
_svmf_thread_native_start (_svmt_JNIEnv *env, jobject threadInstance)
{
  _svmt_JNIEnv *result = NULL;
  _svmt_JNIEnv *new_env = NULL;
  _svmt_JavaVM *vm = env->vm;

  {
    jint status = JNI_OK;

    _svmm_mutex_lock (vm->global_mutex);

    _svmf_halt_if_requested (env);

    if (vm->threads.free_list != NULL)
      {
	new_env = vm->threads.free_list;
	assert (new_env->previous == NULL);

	vm->threads.free_list = new_env->next;
	if (vm->threads.free_list != NULL)
	  {
	    vm->threads.free_list->previous = NULL;
	  }

	new_env->next = vm->threads.user;
	if (new_env->next != NULL)
	  {
	    assert (new_env->next->previous == NULL);
	    new_env->next->previous = new_env;
	  }

	new_env->thread_status =
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED;
      }
    else if (vm->threads.next_thread_id <= SVM_MAX_THREAD_ID)
      {
	if (_svmm_gzalloc_env_no_exception (new_env) != JNI_OK)
	  {
	    goto unlock;
	  }

	new_env->interface = &_svmv_native_interface;
	new_env->vm = vm;

	new_env->next = vm->threads.user;
	vm->threads.user = new_env;
	if (new_env->next != NULL)
	  {
	    assert (new_env->next->previous == NULL);
	    new_env->next->previous = new_env;
	  }

	new_env->thread.interrupted_status = SVM_THREAD_NOT_INTERRUPTED;
	new_env->thread.sleeping_on_fat_lock = NULL;

	new_env->thread.id = vm->threads.next_thread_id++;
	_svmf_initialize_thinlock_id (new_env);
	vm->threads.array[new_env->thread.id] = new_env;

	_svmm_cond_init (new_env->wakeup_cond);
	_svmm_cond_init (new_env->suspension.cond);
	_svmm_mutex_init (new_env->contention.owner.mutex);
	_svmm_cond_init (new_env->contention.requester.cond);

	new_env->thread_status =
	  SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED;
      }
    else
      {
	status = JNI_ERR;
      }

  unlock:
    _svmm_mutex_unlock ();

    if (status != JNI_OK)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }
  }

  if (_svmm_gzalloc_native_ref_no_exception (new_env->native_locals.list) !=
      JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      _svmf_error_OutOfMemoryError (env);
      goto end;
    }
  new_env->throwable = _svmf_cast_jobject_nref (new_env->native_locals.list);

  if (_svmm_gzalloc_native_ref_no_exception
      (new_env->native_locals.list->next) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      _svmf_error_OutOfMemoryError (env);
      goto end;
    }
  new_env->thread.thread_instance =
    _svmf_cast_jobject_nref (new_env->native_locals.list->next);
  *(new_env->thread.thread_instance) = *(threadInstance);

  if (_svmm_gzalloc_native_ref_no_exception
      (new_env->native_locals.list->next->next) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      _svmf_error_OutOfMemoryError (env);
      goto end;
    }
  new_env->contention.requester.jobject =
    _svmf_cast_jobject_nref (new_env->native_locals.list->next->next);

  if (_svmf_stack_init (new_env) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      *(env->throwable) = *(new_env->throwable);
      goto end;
    }

  /* start it! */
  new_env->is_alive = JNI_TRUE;
  if (pthread_create
      (&new_env->thread.pthread, NULL, &_svmf_thread_start, new_env) != 0)
    {
      /* something went wrong */
      /* we should be cleaning up!  todo ... */
      new_env->is_alive = JNI_FALSE;
      _svmf_error_InternalError (env);
      goto end;
    }

  /* it's started! */
  result = new_env;

end:
  return result;
}
