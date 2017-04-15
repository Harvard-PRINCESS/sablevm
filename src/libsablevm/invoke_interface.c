/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* all created VMs */
static pthread_mutex_t _svmv_vm_list_mutex = PTHREAD_MUTEX_INITIALIZER;	/* protected by a mutex */
static _svmt_JavaVM *_svmv_vm_list = NULL;	/* list of vms */

/* interface table */
static const JNIInvokeInterface _svmv_invoke_interface = {
  NULL,
  NULL,
  NULL,
  DestroyJavaVM,
  AttachCurrentThread,
  DetachCurrentThread,
  GetEnv
};

/*
----------------------------------------------------------------------
JNI_GetDefaultJavaVMInitArgs
----------------------------------------------------------------------
*/

JNIEXPORT jint JNICALL
JNI_GetDefaultJavaVMInitArgs (void *_vm_args)
{
  JavaVMInitArgs *vm_args = (JavaVMInitArgs *) _vm_args;

  if (_svmf_init () != JNI_OK)
    {
      goto error;
    }

  /* we only communicate using the 1.2 and 1.4 interface versions */
  if (!
      (vm_args->version == JNI_VERSION_1_2
       || vm_args->version == JNI_VERSION_1_4))
    {
      goto error;
    }

  return JNI_OK;

error:
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
JNI_GetCreatedJavaVMs
----------------------------------------------------------------------
*/

JNIEXPORT jint JNICALL
JNI_GetCreatedJavaVMs (JavaVM **vmBuf, jsize bufLen, jsize *nVMs)
{
  jsize count = 0;
  _svmt_JavaVM *current;

  if (_svmf_init () != JNI_OK)
    {
      goto error;
    }

  /* get lock, then visit list of vms */
  _svmm_mutex_lock (_svmv_vm_list_mutex);

  current = _svmv_vm_list;

  while (current != NULL && count < bufLen)
    {
      vmBuf[count] = _svmf_cast_JavaVM (current);

      count++;

      current = current->next;
    }

  *nVMs = count;

  _svmm_mutex_unlock ();

  return JNI_OK;

error:
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
JNI_CreateJavaVM
----------------------------------------------------------------------
*/

JNIEXPORT jint JNICALL
JNI_CreateJavaVM (JavaVM **pvm, void **penv, void *_vm_args)
{
  JavaVMInitArgs *vm_args = (JavaVMInitArgs *) _vm_args;

  _svmt_JavaVM *vm = NULL;
  _svmt_JNIEnv *env = NULL;

  if (_svmf_init () != JNI_OK)
    {
      goto error;
    }

  /* we only communicate using the 1.2 and 1.4 interface versions */
  if (!
      (vm_args->version == JNI_VERSION_1_2
       || vm_args->version == JNI_VERSION_1_4))
    {
      goto error;
    }

  /* make sure this thread isn't already attached to a vm */
  if (_svmf_get_current_env () != NULL)
    {
      goto error;
    }

  /* allocate vm struct */

  if (_svmm_gzalloc_vm_no_exception (vm) != JNI_OK)
    {
      goto error;
    }

  vm->interface = &_svmv_invoke_interface;
  _svmm_mutex_init (vm->global_mutex);
  _svmm_cond_init (vm->stop_the_world.requesting_thread_cond);
  vm->vfprintf = vfprintf;
  vm->exit = exit;
  vm->abort = abort;
  vm->boot_working_directory = _svmf_get_current_working_directory ();

  _svmf_heap_init_defaults (vm);
  _svmf_class_loader_init_defaults (vm);
  _svmf_stack_init_defaults (vm);

  if (_svmm_galloc_copy_str_no_exception
      (vm->class_loading.boot_loader.boot_class_path,
       BOOT_CLASS_PATH) != JNI_OK)
    {
      goto error;
    }

  vm->class_loading.boot_loader.boot_class_path_entries = NULL;

  if (_svmm_galloc_copy_str_no_exception
      (vm->class_loading.boot_loader.boot_library_path,
       BOOT_LIBRARY_PATH) != JNI_OK)
    {
      goto error;
    }

  /* allocate initialization struct */
  if (_svmm_gzalloc_initialization_no_exception (vm->initialization) !=
      JNI_OK)
    {
      goto error;
    }

  if (vm_args->nOptions > 0)
    {
      vm->class_loading.boot_loader.system_properties.properties =
	_svmf_calloc (vm_args->nOptions, sizeof (char *));

      if (vm->class_loading.boot_loader.system_properties.properties == NULL)
	{
	  goto error;
	}
    }

  /* process vm_args */
  {
    jint i;
    jint nOptions = vm_args->nOptions;

    for (i = 0; i < nOptions; i++)
      {
	char *optstr = vm_args->options[i].optionString;

#include "vm_args.c"

      }
  }

  /* validate some arguments */
  if (_svmm_validate_min_max_increment
      (vm->stack_min_size,
       vm->stack_max_size, vm->stack_allocation_increment) != JNI_OK)
    {
      goto error;
    }

  if (_svmm_validate_min_max_increment
      (vm->class_loader_min_size,
       vm->class_loader_max_size,
       vm->class_loader_allocation_increment) != JNI_OK)
    {
      goto error;
    }

  if (vm->class_loading.boot_loader.boot_class_path[0] != '/')
    {
      goto error;
    }

  if (vm->class_loading.boot_loader.boot_library_path[0] != '/')
    {
      goto error;
    }


  /* allocate JNIEnv struct */
  if (_svmm_gzalloc_env_no_exception (env) != JNI_OK)
    {
      goto error;
    }

  _svmf_set_current_env (env);
  _svmm_cond_init (vm->threads.vm_destruction_cond);
  vm->threads.user = env;
  vm->threads.next_thread_id = 1;	/* thread IDs must start at 1
					   (i.e. no ID == 0) */

  env->interface = &_svmv_native_interface;
  env->vm = vm;
  env->thread.pthread = pthread_self ();
  env->thread.id = vm->threads.next_thread_id++;
  _svmf_initialize_thinlock_id (env);
  env->thread_status = SVM_THREAD_STATUS_RUNNING_JAVA;
  env->is_alive = JNI_TRUE;

  _svmm_cond_init (env->wakeup_cond);
  _svmm_cond_init (env->suspension.cond);
  _svmm_mutex_init (env->contention.owner.mutex);
  _svmm_cond_init (env->contention.requester.cond);

  if (_svmm_gzmalloc_env_array (env, SVM_MAX_THREAD_ID + 1, vm->threads.array)
      != JNI_OK)
    {
      goto error;
    }

  vm->threads.array[env->thread.id] = env;

  if (_svmm_gzmalloc_fat_lock_array
      (env, SVM_MAX_FATLOCK_ID, vm->fat_locks.array) != JNI_OK)
    {
      goto error;
    }

  if (_svmm_gzalloc_native_ref_no_exception (env->native_locals.list) !=
      JNI_OK)
    {
      goto error;
    }
  env->throwable = _svmf_cast_jobject_nref (env->native_locals.list);

  if (_svmm_gzalloc_native_ref_no_exception (env->native_locals.list->next) !=
      JNI_OK)
    {
      goto error;
    }
  env->contention.requester.jobject =
    _svmf_cast_jobject_nref (env->native_locals.list->next);

  if (sigsetjmp (vm->initialization->unrecoverable_exception_handler, 1))
    {
      goto error;
    }

  /* tell them were're here :-) */
  if (vm->verbose_jni)
    {
      _svmf_printf (env, stderr, "[verbose jni: JNI_CreateJavaVM]\n");
    }

  /* initialize vm->instructions */

  if (_svmm_gzmalloc_instruction_info
      (env, SVM_INSTRUCTION_COUNT, vm->instructions) != JNI_OK)
    {
      goto error;
    }

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS
#ifndef NDEBUG
  env->sigsegv_expected = JNI_TRUE;
#endif
#endif
  if (_svmf_interpreter (env) != JNI_OK)
    {
      goto error;
    }

  /* initialize special methods */
  _svmm_set_flag (vm->stack_bottom_method.access_flags, SVM_ACC_INTERNAL);
  vm->stack_bottom_method.frame_info = &vm->stack_bottom_method.prepared_info;
  vm->stack_bottom_method.frame_info->code =
    &vm->instructions[SVM_INSTRUCTION_ERROR].code;

  _svmm_set_flag (vm->internal_call_method.access_flags, SVM_ACC_INTERNAL);
  vm->internal_call_method.frame_info =
    &vm->internal_call_method.prepared_info;
  vm->internal_call_method.frame_info->code =
    &vm->instructions[SVM_INSTRUCTION_INTERNAL_CALL_END].code;

  _svmm_set_flag (vm->vm_initiated_call_method.access_flags,
		  SVM_ACC_INTERNAL);
  vm->vm_initiated_call_method.frame_info =
    &vm->vm_initiated_call_method.prepared_info;
  vm->vm_initiated_call_method.frame_info->code =
    &vm->instructions[SVM_INSTRUCTION_INTERNAL_CALL_END].code;

  /* initialize the heap */
  if (_svmf_heap_init (env) != JNI_OK)
    {
      goto error;
    }

  /* allocate boot class loader */
  if (_svmm_gzalloc_class_loader_info
      (env, vm->class_loading.boot_loader.class_loader_info) != JNI_OK)
    {
      goto error;
    }

  vm->class_loading.class_loader_list =
    vm->class_loading.boot_loader.class_loader_info;

  if (_svmf_init_cl_alloc
      (env, vm->class_loading.boot_loader.class_loader_info) != JNI_OK)
    {
      goto error;
    }

  /* initialize the stack */
  if (_svmf_stack_init (env) != JNI_OK)
    {
      goto error;
    }

  /* set vm as first native library */
  if (_svmm_cl_zalloc_native_library
      (env, vm->class_loading.boot_loader.class_loader_info,
       vm->class_loading.boot_loader.class_loader_info->
       native_library_list) != JNI_OK)
    {
      goto error;
    }
  vm->class_loading.boot_loader.class_loader_info->
    native_library_list_tail =
    &vm->class_loading.boot_loader.class_loader_info->native_library_list->
    next;

  if (_svmm_galloc_copy_str_no_exception
      (vm->class_loading.boot_loader.class_loader_info->
       native_library_list->name, "SableVM internal library") != JNI_OK)
    {
      goto error;
    }

  vm->class_loading.boot_loader.class_loader_info->native_library_list->
    handle = NULL;

  /* initialize splay_tree of internal methods */
  if (_svmf_initialize_internal_method_tree (env) != JNI_OK)
    {
      goto error;
    }

  /* time to bootstrap! */
  if (_svmf_bootstrap (env) != JNI_OK)
    {
      goto error;
    }

  _svmm_gzfree_initialization_no_exception (vm->initialization);

  *penv = env;
  *pvm = (JavaVM *) env->vm;

#ifdef _SABLEVM_INLINABILITY_TESTING
  _svmf_inlined_testing_initialize (env);
#endif

  _svmm_stopping_java (env);

  return JNI_OK;

error:
  /* should be freeing resources (memory, locks, dynamic libraries,...) */
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
DestroyJavaVM
----------------------------------------------------------------------
*/

JNIEXPORT static jint JNICALL
DestroyJavaVM (JavaVM *_vm)
{
  _svmt_JavaVM *vm = (_svmt_JavaVM *) (void *) _vm;
  _svmt_JNIEnv *env = _svmf_get_current_env ();

  if (env == NULL)
    {
      return JNI_ERR;
    }

  _svmm_resuming_java (env);

  _svmm_mutex_lock (vm->global_mutex);

  /* remove this thread from user thread list */

  _svmf_halt_if_requested (env);

  assert (env->is_alive);

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

  /* wait for all non-deamon threads to die */

  while (vm->threads.user != NULL)
    {
      _svmm_cond_wait (vm->threads.vm_destruction_cond, vm->global_mutex);
    }

  _svmm_mutex_unlock ();

#if defined (_SABLEVM_COPY_GC)

  if (vm->verbose_gc)
    {
      _svmf_printf (env, stderr,
		    "[verbose gc: total gc time = %ld sec %ld usec]\n",
		    vm->heap.total_gc_secs, vm->heap.total_gc_usecs);
    }

#endif

#ifdef STATISTICS
  _svmf_print_statistics (env);
#endif /* STATISTICS */

#ifdef _SABLEVM_INLINABILITY_TESTING
  _svmf_print_inlined_testing_results (env);
#endif

  /* Just for simplicity... */
  return JNI_OK;
}

/*
----------------------------------------------------------------------
AttachCurrentThread
----------------------------------------------------------------------
*/

JNIEXPORT static jint JNICALL
AttachCurrentThread (JavaVM *_vm, void **penv, void *args SVM_UNUSED)
{
  _svmt_JNIEnv *new_env = NULL;
  _svmt_JavaVM *vm = (_svmt_JavaVM *) (void *) _vm;

  /* Make sure this thread isn't already attached to a vm. */
  _svmt_JNIEnv *current_env = _svmf_get_current_env ();
  if (current_env != NULL)
    {
      if (vm == current_env->vm)
	{
	  /* If already attached and vm is valid, set penv and return OK. */
	  *penv = current_env;
	  return JNI_OK;
	}
      else
	{
	  goto end;
	}
    }

  {
    jint status = JNI_OK;

    _svmm_mutex_lock (vm->global_mutex);

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
	    status = JNI_ERR;
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
	goto end;
      }
  }

  new_env->thread.pthread = pthread_self ();
  _svmf_set_current_env (new_env);

  if (_svmm_gzalloc_native_ref_no_exception (new_env->native_locals.list) !=
      JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      goto end;
    }
  new_env->throwable = _svmf_cast_jobject_nref (new_env->native_locals.list);

  if (_svmm_gzalloc_native_ref_no_exception
      (new_env->native_locals.list->next) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      goto end;
    }

  if (_svmm_gzalloc_native_ref_no_exception
      (new_env->native_locals.list->next) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      goto end;
    }
  new_env->contention.requester.jobject =
    _svmf_cast_jobject_nref (new_env->native_locals.list->next);

  if (_svmf_stack_init (new_env) != JNI_OK)
    {
      /* we should be cleaning up!  todo ... */
      goto end;
    }

  new_env->is_alive = JNI_TRUE;

  *penv = new_env;
  return JNI_OK;

end:
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
DetachCurrentThread
----------------------------------------------------------------------
*/

JNIEXPORT static jint JNICALL
DetachCurrentThread (JavaVM *_vm)
{
  _svmt_JNIEnv *env;
  _svmt_JavaVM *vm = (_svmt_JavaVM *) (void *) _vm;

  env = _svmf_get_current_env ();
  /* Make sure this thread attached to a vm. */
  if (env == NULL || !env->vm || env->vm != vm)
    {
      goto error;
    }

  _svmm_mutex_lock (vm->global_mutex);

  _svmf_halt_if_requested (env);

  env->is_alive = JNI_FALSE;
  _svmf_set_current_env (NULL);

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

  return JNI_OK;

error:
  return JNI_ERR;
}

/*
----------------------------------------------------------------------
GetEnv
----------------------------------------------------------------------
*/

/*
  If the current thread is not attached to the VM, sets *env to NULL, and
  returns JNI_EDETACHED. If the specified version is not supported, sets
  *env to NULL, and returns JNI_EVERSION. Otherwise, sets *env to the
  appropriate interface, and returns JNI_OK.
*/

JNIEXPORT static jint JNICALL
GetEnv (JavaVM *vm, void **penv, jint interface_id)
{
  _svmt_JNIEnv *env;

  /* Find the current thread. */
  env = _svmf_get_current_env ();

  if (env == NULL || _svmf_cast_JavaVM (env->vm) != vm)
    {
      /* This thread is not attached to VM */
      (*penv) = NULL;
      return JNI_EDETACHED;
    }

  switch (interface_id)
    {
    case JNI_VERSION_1_4:
    case JNI_VERSION_1_2:
    case JNI_VERSION_1_1:
      break;
    default:
      _svmf_printf (env, stderr,
		    "*** Warning: JNI version requested in GetEnv() is unavailable.\n"
		    "***          Only JNI 1.4, 1.2, and 1.1 are supported here.");
      (*penv) = NULL;
      return JNI_EVERSION;
    }

  (*penv) = env;
  return JNI_OK;
}
