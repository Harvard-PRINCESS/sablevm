/* This file has been automatically generated from "error.list" */

/*
----------------------------------------------------------------------
_svmf_error_ArithmeticException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArithmeticException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArithmeticException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArithmeticException)
    {
      env->in_ArithmeticException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArithmeticException);
      return;
    }

  env->in_ArithmeticException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArithmeticException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArithmeticException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArithmeticException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ArithmeticException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArithmeticException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArithmeticException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArithmeticException)
    {
      env->in_ArithmeticException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArithmeticException);
      return;
    }

  env->in_ArithmeticException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArithmeticException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArithmeticException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArithmeticException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArithmeticException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ArrayIndexOutOfBoundsException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArrayIndexOutOfBoundsException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArrayIndexOutOfBoundsException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArrayIndexOutOfBoundsException)
    {
      env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArrayIndexOutOfBoundsException);
      return;
    }

  env->in_ArrayIndexOutOfBoundsException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArrayIndexOutOfBoundsException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ArrayIndexOutOfBoundsException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArrayIndexOutOfBoundsException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArrayIndexOutOfBoundsException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArrayIndexOutOfBoundsException)
    {
      env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArrayIndexOutOfBoundsException);
      return;
    }

  env->in_ArrayIndexOutOfBoundsException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArrayIndexOutOfBoundsException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArrayIndexOutOfBoundsException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ArrayStoreException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArrayStoreException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArrayStoreException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArrayStoreException)
    {
      env->in_ArrayStoreException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArrayStoreException);
      return;
    }

  env->in_ArrayStoreException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayStoreException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArrayStoreException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArrayStoreException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ArrayStoreException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ArrayStoreException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ArrayStoreException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ArrayStoreException)
    {
      env->in_ArrayStoreException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ArrayStoreException);
      return;
    }

  env->in_ArrayStoreException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayStoreException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ArrayStoreException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ArrayStoreException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ArrayStoreException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ClassCastException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassCastException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassCastException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassCastException)
    {
      env->in_ClassCastException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassCastException);
      return;
    }

  env->in_ClassCastException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCastException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassCastException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassCastException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ClassCastException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassCastException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassCastException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassCastException)
    {
      env->in_ClassCastException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassCastException);
      return;
    }

  env->in_ClassCastException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCastException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassCastException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCastException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassCastException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_IllegalMonitorStateException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_IllegalMonitorStateException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_IllegalMonitorStateException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_IllegalMonitorStateException)
    {
      env->in_IllegalMonitorStateException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_IllegalMonitorStateException);
      return;
    }

  env->in_IllegalMonitorStateException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IllegalMonitorStateException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_IllegalMonitorStateException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_IllegalMonitorStateException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_IllegalMonitorStateException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_IllegalMonitorStateException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_IllegalMonitorStateException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_IllegalMonitorStateException)
    {
      env->in_IllegalMonitorStateException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_IllegalMonitorStateException);
      return;
    }

  env->in_IllegalMonitorStateException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IllegalMonitorStateException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_IllegalMonitorStateException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IllegalMonitorStateException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_IllegalMonitorStateException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NegativeArraySizeException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NegativeArraySizeException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NegativeArraySizeException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NegativeArraySizeException)
    {
      env->in_NegativeArraySizeException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NegativeArraySizeException);
      return;
    }

  env->in_NegativeArraySizeException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NegativeArraySizeException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NegativeArraySizeException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NegativeArraySizeException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NegativeArraySizeException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NegativeArraySizeException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NegativeArraySizeException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NegativeArraySizeException)
    {
      env->in_NegativeArraySizeException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NegativeArraySizeException);
      return;
    }

  env->in_NegativeArraySizeException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NegativeArraySizeException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NegativeArraySizeException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NegativeArraySizeException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NegativeArraySizeException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NoSuchFieldException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchFieldException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchFieldException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchFieldException)
    {
      env->in_NoSuchFieldException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchFieldException);
      return;
    }

  env->in_NoSuchFieldException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchFieldException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NoSuchFieldException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchFieldException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchFieldException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchFieldException)
    {
      env->in_NoSuchFieldException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchFieldException);
      return;
    }

  env->in_NoSuchFieldException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchFieldException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NoSuchMethodException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchMethodException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchMethodException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchMethodException)
    {
      env->in_NoSuchMethodException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchMethodException);
      return;
    }

  env->in_NoSuchMethodException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchMethodException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NoSuchMethodException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchMethodException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchMethodException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchMethodException)
    {
      env->in_NoSuchMethodException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchMethodException);
      return;
    }

  env->in_NoSuchMethodException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchMethodException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NullPointerException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NullPointerException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NullPointerException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NullPointerException)
    {
      env->in_NullPointerException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NullPointerException);
      return;
    }

  env->in_NullPointerException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NullPointerException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NullPointerException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NullPointerException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NullPointerException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NullPointerException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NullPointerException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NullPointerException)
    {
      env->in_NullPointerException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NullPointerException);
      return;
    }

  env->in_NullPointerException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NullPointerException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NullPointerException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NullPointerException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NullPointerException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_InterruptedException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InterruptedException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InterruptedException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InterruptedException)
    {
      env->in_InterruptedException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InterruptedException);
      return;
    }

  env->in_InterruptedException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InterruptedException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InterruptedException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InterruptedException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_InterruptedException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InterruptedException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InterruptedException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InterruptedException)
    {
      env->in_InterruptedException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InterruptedException);
      return;
    }

  env->in_InterruptedException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InterruptedException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InterruptedException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InterruptedException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InterruptedException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_InliningException
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InliningException (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InliningException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InliningException)
    {
      env->in_InliningException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InliningException);
      return;
    }

  env->in_InliningException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InliningException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InliningException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InliningException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InliningException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InliningException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InliningException = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_InliningException_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InliningException_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InliningException == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InliningException)
    {
      env->in_InliningException = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InliningException);
      return;
    }

  env->in_InliningException = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InliningException = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InliningException, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InliningException = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InliningException_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InliningException = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InliningException = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_AbstractMethodError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_AbstractMethodError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_AbstractMethodError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_AbstractMethodError)
    {
      env->in_AbstractMethodError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_AbstractMethodError);
      return;
    }

  env->in_AbstractMethodError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.AbstractMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_AbstractMethodError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_AbstractMethodError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_AbstractMethodError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_AbstractMethodError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_AbstractMethodError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_AbstractMethodError)
    {
      env->in_AbstractMethodError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_AbstractMethodError);
      return;
    }

  env->in_AbstractMethodError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.AbstractMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_AbstractMethodError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_AbstractMethodError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_AbstractMethodError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ClassCircularityError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassCircularityError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassCircularityError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassCircularityError)
    {
      env->in_ClassCircularityError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassCircularityError);
      return;
    }

  env->in_ClassCircularityError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCircularityError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassCircularityError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassCircularityError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ClassCircularityError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassCircularityError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassCircularityError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassCircularityError)
    {
      env->in_ClassCircularityError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassCircularityError);
      return;
    }

  env->in_ClassCircularityError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCircularityError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassCircularityError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassCircularityError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassCircularityError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ClassFormatError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassFormatError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassFormatError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassFormatError)
    {
      env->in_ClassFormatError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassFormatError);
      return;
    }

  env->in_ClassFormatError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassFormatError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassFormatError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassFormatError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ClassFormatError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ClassFormatError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ClassFormatError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ClassFormatError)
    {
      env->in_ClassFormatError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ClassFormatError);
      return;
    }

  env->in_ClassFormatError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassFormatError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ClassFormatError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ClassFormatError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ClassFormatError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_ExceptionInInitializerError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ExceptionInInitializerError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ExceptionInInitializerError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ExceptionInInitializerError)
    {
      env->in_ExceptionInInitializerError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ExceptionInInitializerError);
      return;
    }

  env->in_ExceptionInInitializerError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ExceptionInInitializerError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ExceptionInInitializerError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ExceptionInInitializerError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_ExceptionInInitializerError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_ExceptionInInitializerError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_ExceptionInInitializerError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_ExceptionInInitializerError)
    {
      env->in_ExceptionInInitializerError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_ExceptionInInitializerError);
      return;
    }

  env->in_ExceptionInInitializerError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ExceptionInInitializerError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_ExceptionInInitializerError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_ExceptionInInitializerError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_ExceptionInInitializerError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_IncompatibleClassChangeError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_IncompatibleClassChangeError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_IncompatibleClassChangeError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_IncompatibleClassChangeError)
    {
      env->in_IncompatibleClassChangeError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_IncompatibleClassChangeError);
      return;
    }

  env->in_IncompatibleClassChangeError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IncompatibleClassChangeError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_IncompatibleClassChangeError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_IncompatibleClassChangeError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_IncompatibleClassChangeError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_IncompatibleClassChangeError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_IncompatibleClassChangeError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_IncompatibleClassChangeError)
    {
      env->in_IncompatibleClassChangeError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_IncompatibleClassChangeError);
      return;
    }

  env->in_IncompatibleClassChangeError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IncompatibleClassChangeError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_IncompatibleClassChangeError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_IncompatibleClassChangeError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_IncompatibleClassChangeError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_InternalError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InternalError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InternalError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InternalError)
    {
      env->in_InternalError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InternalError);
      return;
    }

  env->in_InternalError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InternalError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InternalError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InternalError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InternalError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InternalError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InternalError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_InternalError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_InternalError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_InternalError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_InternalError)
    {
      env->in_InternalError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_InternalError);
      return;
    }

  env->in_InternalError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_InternalError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InternalError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InternalError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_InternalError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_InternalError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_InternalError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_LinkageError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_LinkageError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_LinkageError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_LinkageError)
    {
      env->in_LinkageError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_LinkageError);
      return;
    }

  env->in_LinkageError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.LinkageError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_LinkageError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_LinkageError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_LinkageError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_LinkageError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_LinkageError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_LinkageError)
    {
      env->in_LinkageError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_LinkageError);
      return;
    }

  env->in_LinkageError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.LinkageError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_LinkageError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_LinkageError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_LinkageError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NoClassDefFoundError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoClassDefFoundError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoClassDefFoundError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoClassDefFoundError)
    {
      env->in_NoClassDefFoundError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoClassDefFoundError);
      return;
    }

  env->in_NoClassDefFoundError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoClassDefFoundError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoClassDefFoundError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoClassDefFoundError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NoClassDefFoundError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoClassDefFoundError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoClassDefFoundError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoClassDefFoundError)
    {
      env->in_NoClassDefFoundError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoClassDefFoundError);
      return;
    }

  env->in_NoClassDefFoundError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoClassDefFoundError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoClassDefFoundError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoClassDefFoundError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoClassDefFoundError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NoSuchFieldError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchFieldError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchFieldError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchFieldError)
    {
      env->in_NoSuchFieldError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchFieldError);
      return;
    }

  env->in_NoSuchFieldError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchFieldError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NoSuchFieldError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchFieldError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchFieldError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchFieldError)
    {
      env->in_NoSuchFieldError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchFieldError);
      return;
    }

  env->in_NoSuchFieldError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchFieldError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchFieldError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_NoSuchMethodError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchMethodError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchMethodError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchMethodError)
    {
      env->in_NoSuchMethodError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchMethodError);
      return;
    }

  env->in_NoSuchMethodError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchMethodError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_NoSuchMethodError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_NoSuchMethodError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_NoSuchMethodError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_NoSuchMethodError)
    {
      env->in_NoSuchMethodError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_NoSuchMethodError);
      return;
    }

  env->in_NoSuchMethodError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_NoSuchMethodError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_NoSuchMethodError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_OutOfMemoryError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_OutOfMemoryError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_OutOfMemoryError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_OutOfMemoryError)
    {
      env->in_OutOfMemoryError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_OutOfMemoryError);
      return;
    }

  env->in_OutOfMemoryError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.OutOfMemoryError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_OutOfMemoryError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_OutOfMemoryError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_OutOfMemoryError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_OutOfMemoryError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_OutOfMemoryError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_OutOfMemoryError)
    {
      env->in_OutOfMemoryError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_OutOfMemoryError);
      return;
    }

  env->in_OutOfMemoryError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.OutOfMemoryError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_OutOfMemoryError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_OutOfMemoryError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_OutOfMemoryError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_UnsatisfiedLinkError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_UnsatisfiedLinkError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_UnsatisfiedLinkError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_UnsatisfiedLinkError)
    {
      env->in_UnsatisfiedLinkError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_UnsatisfiedLinkError);
      return;
    }

  env->in_UnsatisfiedLinkError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsatisfiedLinkError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_UnsatisfiedLinkError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_UnsatisfiedLinkError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_UnsatisfiedLinkError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_UnsatisfiedLinkError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_UnsatisfiedLinkError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_UnsatisfiedLinkError)
    {
      env->in_UnsatisfiedLinkError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_UnsatisfiedLinkError);
      return;
    }

  env->in_UnsatisfiedLinkError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsatisfiedLinkError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_UnsatisfiedLinkError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsatisfiedLinkError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_UnsatisfiedLinkError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_UnsupportedClassVersionError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_UnsupportedClassVersionError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_UnsupportedClassVersionError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_UnsupportedClassVersionError)
    {
      env->in_UnsupportedClassVersionError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_UnsupportedClassVersionError);
      return;
    }

  env->in_UnsupportedClassVersionError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsupportedClassVersionError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_UnsupportedClassVersionError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_UnsupportedClassVersionError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_UnsupportedClassVersionError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_UnsupportedClassVersionError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_UnsupportedClassVersionError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_UnsupportedClassVersionError)
    {
      env->in_UnsupportedClassVersionError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_UnsupportedClassVersionError);
      return;
    }

  env->in_UnsupportedClassVersionError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsupportedClassVersionError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_UnsupportedClassVersionError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_UnsupportedClassVersionError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_UnsupportedClassVersionError = JNI_FALSE;
}


/*
----------------------------------------------------------------------
_svmf_error_VerifyError
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_VerifyError (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_VerifyError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_VerifyError)
    {
      env->in_VerifyError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_VerifyError);
      return;
    }

  env->in_VerifyError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.VerifyError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_VerifyError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_VerifyError = JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_error_VerifyError_msg
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_VerifyError_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_VerifyError == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_VerifyError)
    {
      env->in_VerifyError = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_VerifyError);
      return;
    }

  env->in_VerifyError = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.VerifyError, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_VerifyError_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_VerifyError = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_VerifyError = JNI_FALSE;
}

