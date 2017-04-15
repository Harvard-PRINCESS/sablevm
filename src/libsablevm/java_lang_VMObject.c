/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_VMObject_notify
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMObject
 * Method:    notify
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMObject_notify (JNIEnv *_env, jclass class SVM_UNUSED,
				jobject o)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance = *o;
    _svmt_word lockword = instance->lockword;

    if (_svmf_lockword_is_thin (lockword))
      {
	if (_svmf_lockword_get_thinlock_id (lockword) !=
	    env->thread.thinlock_id)
	  {
	    _svmf_error_IllegalMonitorStateException (env);
	    goto end;
	  }

	/* It's a thinlock; no other thread is possibly waiting on
	   this object's monitor. No need to notify. */
	goto end;
      }

    /* It's a fat lock. */
    {
      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];

      if (fat_lock->owner != env)
	{
	  _svmf_error_IllegalMonitorStateException (env);
	  goto end;
	}

      /* Time to notify. */
      _svmm_mutex_lock (fat_lock->mutex);
      _svmm_cond_signal (fat_lock->notification_cond);
      _svmm_mutex_unlock ();
    }

  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMObject_notifyAll
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMObject
 * Method:    notifyAll
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMObject_notifyAll (JNIEnv *_env, jclass class SVM_UNUSED,
				   jobject o)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance = *o;
    _svmt_word lockword = instance->lockword;

    if (_svmf_lockword_is_thin (lockword))
      {
	if (_svmf_lockword_get_thinlock_id (lockword) !=
	    env->thread.thinlock_id)
	  {
	    _svmf_error_IllegalMonitorStateException (env);
	    goto end;
	  }

	/* It's a thinlock; no other thread is possibly waiting on
	   this object's monitor. No need to notify. */
	goto end;
      }

    /* It's a fat lock. */
    {
      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];

      if (fat_lock->owner != env)
	{
	  _svmf_error_IllegalMonitorStateException (env);
	  goto end;
	}

      /* Time to notify. */
      _svmm_mutex_lock (fat_lock->mutex);
      _svmm_cond_broadcast (fat_lock->notification_cond);
      _svmm_mutex_unlock ();
    }

  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMObject_wait
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMObject
 * Method:    wait
 * Signature: (Ljava/lang/Object;JI)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMObject_wait (JNIEnv *_env, jclass class SVM_UNUSED,
			      jobject o, jlong ms, jint ns)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  int throw_interrupted_requested = JNI_FALSE;

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance = *o;
    _svmt_word lockword = instance->lockword;

    /* If it is a thinlock, we must inflate it. */
    if (_svmf_lockword_is_thin (lockword))
      {
	if (_svmf_lockword_get_thinlock_id (lockword) !=
	    env->thread.thinlock_id)
	  {
	    _svmf_error_IllegalMonitorStateException (env);
	    goto end;
	  }

	if (_svmf_inflate_lock_no_exception (env, instance) != JNI_OK)
	  {
	    _svmf_error_OutOfMemoryError (env);
	    goto end;
	  }

	lockword = instance->lockword;
      }

    /* wait on the fat lock */
    {
      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];
      _svmt_word old_interrupted_status, new_interrupted_status;

      if (fat_lock->owner != env)
	{
	  _svmf_error_IllegalMonitorStateException (env);
	  goto end;
	}

      /* first, handle the any pending contention on a former thinlock. */
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
		      (env,
		       *(current->contention.requester.jobject)) != JNI_OK)
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
	      goto end;
	    }
	}

      /* prepare to sleep... */
      _svmm_stopping_java (env);

      _svmm_mutex_lock (fat_lock->mutex);

      /* in case of Thread.interrupt() put info that we're sleeping */
      env->thread.sleeping_on_fat_lock = fat_lock;

      do
	{
	  old_interrupted_status = env->thread.interrupted_status;
	  new_interrupted_status = old_interrupted_status;

	  new_interrupted_status |= SVM_THREAD_INTERRUPTIBLE_ON_FAT_LOCK;
	  new_interrupted_status &= ~SVM_THREAD_THROW_INTERRUPTED;
	}
      while (!_svmm_compare_and_swap
	     (env->thread.interrupted_status, old_interrupted_status,
	      new_interrupted_status));

      /* Time to wait. */
      {
	jint recursive_count = fat_lock->recursive_count;

	fat_lock->recursive_count = 0;
	fat_lock->owner = NULL;
	_svmm_cond_broadcast (fat_lock->cond);

	if (ms == 0 && ns == 0)
	  {
	    _svmm_cond_wait (fat_lock->notification_cond, fat_lock->mutex);
	  }
	else
	  {
	    /* The following code is unforunately platform dependent.
	       You will have to find some function like gettimeofday()
	       that returns the current time as precisely as possible.
	       In the worst case, simply use the quite imprecise ISO C
	       time() function. */

	    struct timeval now;
	    struct timespec timeout;

	    gettimeofday (&now, NULL);

	    timeout.tv_sec = now.tv_sec;
	    timeout.tv_nsec = now.tv_usec * 1000;

	    timeout.tv_sec = timeout.tv_sec + (ms / 1000);
	    timeout.tv_nsec =
	      timeout.tv_nsec + (ms % 1000) * 1000 * 1000 + ns;

	    /* Watch for overflow of timeout.tv_nsec...

	       OK; I assume that tv_nsec has at least 32 bits (signed or
	       not, I don't care), a reasonable assumption given that it
	       must be able to hold the value 999999999.
	     */
	    if (timeout.tv_nsec >= 1000000000L)
	      {
		timeout.tv_sec++;
		timeout.tv_nsec -= 1000000000L;
	      }

	    /* I don't care about overflow of timeout.tv_sec. */

	    /* Don't count on returned value. According to the OpenGroup specs
	       it should _never_ return EINTR ! Check interrupted_status flag */

	    _svmm_cond_timedwait (fat_lock->notification_cond,
				  fat_lock->mutex, timeout);

	    /* have we been interrupted ? */
	    do
	      {
		old_interrupted_status = env->thread.interrupted_status;
		new_interrupted_status = old_interrupted_status;

		if (old_interrupted_status & SVM_THREAD_THROW_INTERRUPTED)
		  {
		    new_interrupted_status &=
		      ~SVM_THREAD_INTERRUPTIBLE_ON_FAT_LOCK;
		    new_interrupted_status &= ~SVM_THREAD_THROW_INTERRUPTED;
		  }
		else
		  {
		    break;
		  }
	      }
	    while (!_svmm_compare_and_swap
		   (env->thread.interrupted_status,
		    old_interrupted_status, new_interrupted_status));

	    if (old_interrupted_status & SVM_THREAD_THROW_INTERRUPTED)
	      {
		throw_interrupted_requested = JNI_TRUE;
	      }
	  }

	/* wait until no other thread owns the lock */
	while (fat_lock->recursive_count != 0 && fat_lock->owner != env)
	  {
	    _svmm_cond_wait (fat_lock->cond, fat_lock->mutex);
	  }

	fat_lock->recursive_count = recursive_count;
	fat_lock->owner = env;
      }

      env->thread.sleeping_on_fat_lock = NULL;

      _svmm_mutex_unlock ();

      _svmm_resuming_java (env);

      /* throw an InterruptedException if we've been interrupt()ed */
      if (throw_interrupted_requested == JNI_TRUE)
	{
	  _svmf_error_InterruptedException (env);
	}
    }

  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMObject_clone
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMObject
 * Method:    clone
 * Signature: (Ljava/lang/Cloneable;)Ljava/lang/Object;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_VMObject_clone (JNIEnv *_env, jclass class SVM_UNUSED,
			       jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject clone = NULL;

  _svmm_resuming_java (env);

  {
    clone = _svmf_get_jni_frame_native_local (env);
    _svmf_clone_instance (env, obj, clone);
  }

  _svmm_stopping_java (env);

  return clone;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMObject_getClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMObject
 * Method:    getClass
 * Signature: ()Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMObject_getClass (JNIEnv *_env, jclass c SVM_UNUSED,
				  jobject this)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class;

  _svmm_resuming_java (env);

  {
    class = _svmf_get_jni_frame_native_local (env);
    *class = *((*this)->vtable->type->class_instance);
  }

  _svmm_stopping_java (env);

  return class;
}
