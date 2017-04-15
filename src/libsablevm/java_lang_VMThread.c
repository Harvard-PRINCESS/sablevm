/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_yield
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    yield
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMThread_yield (JNIEnv *_env, jclass _class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmm_resuming_java (env);

  if (sched_yield () != 0)
    {
      /* Should we really really throw an error on failure? Maybe we
         could simply ignore the return value, if no harm is implied.
         Suggestions are welcome.  Etienne */

      _svmf_error_InternalError (env);
      goto end;
    }

end:
  _svmm_stopping_java (env);

  return;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_sleep
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    sleep
 * Signature: ()Z
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMThread_sleep (JNIEnv *_env, jclass this SVM_UNUSED, jlong ms,
			       jint ns)
{

  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  struct timespec timeout;
  _svmt_word old_interrupted_status, new_interrupted_status;

  do
    {
      old_interrupted_status = env->thread.interrupted_status;
      new_interrupted_status = old_interrupted_status;

      new_interrupted_status |= SVM_THREAD_INTERRUPTIBLE_BY_SIGNAL;
      new_interrupted_status &= ~SVM_THREAD_THROW_INTERRUPTED;
    }
  while (!_svmm_compare_and_swap
	 (env->thread.interrupted_status, old_interrupted_status,
	  new_interrupted_status));

  timeout.tv_sec = ms / 1000;
  timeout.tv_nsec = (ms % 1000) * 1000 * 1000 + ns;

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

  /* we don't check the return value, as in case of interrupt() that
   * caused a signal that woke us up, we'll have interrupted_status
   * flag set accordingly */
  nanosleep (&timeout, NULL);

  do
    {
      old_interrupted_status = env->thread.interrupted_status;
      new_interrupted_status = old_interrupted_status;

      if (old_interrupted_status & SVM_THREAD_THROW_INTERRUPTED)
	{
	  new_interrupted_status &= ~SVM_THREAD_INTERRUPTIBLE_ON_FAT_LOCK;
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
      _svmm_resuming_java (env);
      _svmf_error_InterruptedException (env);
      _svmm_stopping_java (env);
    }
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_nativeIsAlive
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    nativeIsAlive
 * Signature: ([B)Z
 */

JNIEXPORT static jboolean JNICALL
Java_java_lang_VMThread_nativeIsAlive (JNIEnv *_env, jobject this SVM_UNUSED,
				       jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  result = ((_svmt_JNIEnv *) _svmf_unwrap_pointer (*vmData))->is_alive;

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_nativeStart
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    nativeStart
 * Signature: ()[B
 */

JNIEXPORT static jbyteArray JNICALL
Java_java_lang_VMThread_nativeStart (JNIEnv *_env, jobject this SVM_UNUSED,
				     jobject threadInstance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyteArray result = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JNIEnv *new_env = _svmf_thread_native_start (env, threadInstance);

    if (new_env != NULL)
      {
	result = _svmf_get_jni_frame_native_local_array (env);
	if (_svmf_wrap_pointer (env, new_env, result) != JNI_OK)
	  {
	    result = NULL;
	    goto end;
	  }
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_currentThread
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    currentThread
 * Signature: ()Ljava/lang/Thread;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_VMThread_currentThread (JNIEnv *_env, jclass _class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  _svmm_resuming_java (env);

  {
    if (env->thread.thread_instance == NULL)
      {
	jobject thread;
	jbyteArray wrapper;

	if (_svmm_new_native_local (env, thread) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_local_wrap_pointer (env, env, wrapper) != JNI_OK)
	  {
	    _svmm_free_native_local (env, thread);
	    goto end;
	  }

	if (_svmm_invoke_static_virtualmachine_createrootthread
	    (env, _svmf_cast_jobject (wrapper), thread) != JNI_OK)
	  {
	    _svmm_free_native_local_array (env, wrapper);
	    _svmm_free_native_local (env, thread);
	    goto end;
	  }

	_svmm_free_native_local_array (env, wrapper);
	env->thread.thread_instance = thread;
      }

    result = _svmf_get_jni_frame_native_local (env);
    *result = *(env->thread.thread_instance);
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
Java_java_lang_VMThread_nativeInterrupt
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    interrupt
 * Signature: ()V
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMThread_nativeInterrupt (JNIEnv *_env,
					 jobject this SVM_UNUSED,
					 jbyteArray vmData)
{

  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JNIEnv *target_env = (_svmt_JNIEnv *) _svmf_unwrap_pointer (*vmData);
  _svmt_fat_lock *sleeping_on_fat_lock;
  _svmt_word old_interrupted_status, new_interrupted_status;

  _svmm_resuming_java (env);

again:

  /* where is the target thread possibly sleeping? */
  do
    {
      old_interrupted_status = target_env->thread.interrupted_status;
      new_interrupted_status = old_interrupted_status;

      if (old_interrupted_status & SVM_THREAD_INTERRUPTIBLE_BY_SIGNAL)
	{
	  new_interrupted_status |= SVM_THREAD_THROW_INTERRUPTED;
	  new_interrupted_status &= ~SVM_THREAD_INTERRUPTED;
	}
      else if (old_interrupted_status & SVM_THREAD_INTERRUPTIBLE_ON_FAT_LOCK)
	{
	  /* do nothing, we're not sure yet what the target thread is doing */
	}
      else
	{
	  new_interrupted_status |= SVM_THREAD_INTERRUPTED;
	}

    }
  while (!_svmm_compare_and_swap
	 (target_env->thread.interrupted_status, old_interrupted_status,
	  new_interrupted_status));

  if (old_interrupted_status & SVM_THREAD_INTERRUPTIBLE_ON_FAT_LOCK)
    {
      /* the target thread is probably sleeping on a fat lock */
      sleeping_on_fat_lock = target_env->thread.sleeping_on_fat_lock;
      if (sleeping_on_fat_lock != NULL)
	{
	  if (_svmm_mutex_trylock (sleeping_on_fat_lock->mutex) == 0)
	    {
	      /* make sure the thread is _still_ sleeping on this lock! */
	      if (sleeping_on_fat_lock ==
		  target_env->thread.sleeping_on_fat_lock)
		{
		  /* Only now we can be sure that the target thread is sleeping and we can
		   * effectively interrupt him and tell him to throw InterruptedException */
		  do
		    {
		      old_interrupted_status =
			target_env->thread.interrupted_status;
		      new_interrupted_status = old_interrupted_status;

		      new_interrupted_status |= SVM_THREAD_THROW_INTERRUPTED;
		      new_interrupted_status &= ~SVM_THREAD_INTERRUPTED;
		    }
		  while (!_svmm_compare_and_swap
			 (target_env->thread.interrupted_status,
			  old_interrupted_status, new_interrupted_status));

		  /* free the sleeping/target thread */
		  _svmm_cond_broadcast (sleeping_on_fat_lock->
					notification_cond);
		  _svmm_mutex_unlock_after_try (sleeping_on_fat_lock->mutex);
		}
	      else
		{
		  _svmm_mutex_unlock_after_try (sleeping_on_fat_lock->mutex);
		  /* We haven't managed to block&interrupt the target thread - trying again. */
		  goto again;
		}
	    }
	  else
	    goto again;
	}
      else
	goto again;

    }
  else if (old_interrupted_status & SVM_THREAD_INTERRUPTIBLE_BY_SIGNAL)
    {
      _svmm_kill (target_env->thread.pthread, SVM_INTERRUPT_SIGNAL);
    }

  _svmm_stopping_java (env);

  return;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_nativeIsInterrupted
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    isInterrupted
 * Signature: ()Z
 */
JNIEXPORT static jboolean JNICALL
Java_java_lang_VMThread_nativeIsInterrupted (JNIEnv *_env,
					     jobject this SVM_UNUSED,
					     jbyteArray vmData)
{
  jboolean result;
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  result =
    (((_svmt_JNIEnv *) _svmf_unwrap_pointer (*vmData))->thread.
     interrupted_status) & SVM_THREAD_INTERRUPTED;

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_interrupted
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    interrupted
 * Signature: ()Z
 */
JNIEXPORT static jboolean JNICALL
Java_java_lang_VMThread_interrupted (JNIEnv *_env, jclass this SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_word old_interrupted_status, new_interrupted_status;
  jboolean result;

  _svmm_resuming_java (env);

  /* this is static method that refers to the _current_ thread only,
     so no need to search which thread is referred to by "this"
   */

  do
    {
      old_interrupted_status = env->thread.interrupted_status;
      new_interrupted_status = old_interrupted_status;

      new_interrupted_status &= ~SVM_THREAD_INTERRUPTED;
    }
  while (!_svmm_compare_and_swap (env->thread.interrupted_status,
				  old_interrupted_status,
				  new_interrupted_status));

  result = old_interrupted_status & SVM_THREAD_INTERRUPTED;

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_holdsLock
----------------------------------------------------------------------
*/

/* 
 * Class:     java_lang_VMThread 
 * Method:    holdsLock 
 * Signature: (Ljava/lang/Object;)Z 
 */
JNIEXPORT static jboolean JNICALL
Java_java_lang_VMThread_holdsLock (JNIEnv *_env, jclass class SVM_UNUSED,
				   jobject o)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jboolean result = JNI_TRUE;

  _svmm_resuming_java (env);

  {
    /* Note: the case where o == NULL should be handled before calling this function */
    _svmt_object_instance *instance = *o;
    _svmt_word lockword = instance->lockword;

    if (_svmf_lockword_is_thin (lockword))
      {
	if (_svmf_lockword_get_thinlock_id (lockword) !=
	    env->thread.thinlock_id)
	  {
	    result = JNI_FALSE;
	  }
	goto end;
      }

    /* It's a fat lock. */
    {
      _svmt_word fat_index = _svmf_lockword_get_fatlock_index (lockword);
      _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];

      if (fat_lock->owner != env)
	{
	  result = JNI_FALSE;
	}
    }

  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_suspend
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    suspend
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMThread_suspend (JNIEnv *_env, jclass class SVM_UNUSED,
				 jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  _svmm_resuming_java (env);

  {
    _svmt_JNIEnv *target;

    target = _svmf_unwrap_pointer (*vmData);

    _svmm_mutex_lock (vm->global_mutex);

    _svmf_suspend_thread (env, target);

    _svmm_mutex_unlock ();
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMThread_resume
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMThread
 * Method:    resume
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMThread_resume (JNIEnv *_env, jclass class SVM_UNUSED,
				jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  _svmm_resuming_java (env);

  {
    _svmt_JNIEnv *target;

    target = _svmf_unwrap_pointer (*vmData);

    _svmm_mutex_lock (vm->global_mutex);

    _svmf_resume_thread (env, target);

    _svmm_mutex_unlock ();
  }

  _svmm_stopping_java (env);
}
