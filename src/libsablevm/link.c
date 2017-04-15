/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_link_array
----------------------------------------------------------------------
*/

svm_static jint
_svmf_link_array (_svmt_JNIEnv *env, _svmt_array_info *array)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_class_loader_monitor (env, array->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (_svmf_prepare_array (env, array) != JNI_OK)
    {
      goto error;
    }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, array->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, array->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_link_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_link_class (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_class_loader_monitor (env, class->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (_svmf_verify_class (env, class) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_prepare_class (env, class) != JNI_OK)
    {
      goto error;
    }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class->class_loader_info) !=
	  JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_link_type
----------------------------------------------------------------------
*/

svm_static jint
_svmf_link_type (_svmt_JNIEnv *env, _svmt_type_info *type)
{
  if (type->is_array)
    {
      return _svmf_link_array (env, _svmf_cast_array (type));
    }

  return _svmf_link_class (env, _svmf_cast_class (type));
}
