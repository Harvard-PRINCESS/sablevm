/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_error_type
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_error_type)
 */

m4svm_define_begin v = ":], [:m4svm_error_type:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_error_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_$1 (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_$1 == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  (Note that this works even if the frame is
     native or internal). */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_$1)
    {
      env->in_$1 = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_$1);
      return;
    }

  env->in_$1 = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_$1 = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.$1, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_$1 = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_$1_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_$1 = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_$1 = JNI_FALSE;
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_error_$1_msg
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmf_error_$1_msg (_svmt_JNIEnv *env, jstring msg)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->class_loading.boot_loader.instances.default_$1 == NULL)
    {
      _svmf_initialization_unrecoverable_exception (env);
    }

  /* Empty the stack.  Note that this works even if the frame is
     native or internal. */
  env->stack.current_frame->stack_size = 0;

  /* We will override any pending instruction with the new one. */
  *(env->throwable) = NULL;

  if (env->in_$1)
    {
      env->in_$1 = JNI_FALSE;

      *(env->throwable) =
	*(vm->class_loading.boot_loader.instances.default_$1);
      return;
    }

  env->in_$1 = JNI_TRUE;

  {
    jobject error;

    if (_svmm_new_native_local (env, error) != JNI_OK)
      {
	env->in_$1 = JNI_FALSE;
	return;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.$1, *error) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_$1 = JNI_FALSE;
	return;
      }

    if (_svmm_invoke_nonvirtual_$1_init (env, error, msg) != JNI_OK)
      {
	_svmm_free_native_local (env, error);
	env->in_$1 = JNI_FALSE;
	return;
      }

    *(env->throwable) = *error;
    _svmm_free_native_local (env, error);
  }

  env->in_$1 = JNI_FALSE;
}

m4svm_define_end v = ":])";
