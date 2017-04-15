/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_resolve_CONSTANT_Class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_CONSTANT_Class (_svmt_JNIEnv *env, _svmt_class_info *class,
			      _svmt_CONSTANT_Class_info *classref)
{
  _svmt_type_info *type;

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

  if (classref->type != NULL)
    {
      goto ok;
    }

  if (classref->resolution_error != NULL)
    {
      assert (*(classref->resolution_error) != NULL);

      *(env->throwable) = *(classref->resolution_error);
      goto error;
    }

  if (_svmm_new_native_global (env, classref->resolution_error) != JNI_OK)
    {
      goto error;
    }

  if (_svmm_create_type
      (env, class->class_loader_info, DREF (classref->name, value),
       type) != JNI_OK)
    {
      *(classref->resolution_error) = *(env->throwable);
      goto error;
    }

  classref->type = type;
  _svmm_free_native_global (env, classref->resolution_error);

ok:
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
_svmf_resolve_field
----------------------------------------------------------------------
*/

svm_static _svmt_field_info *
_svmf_resolve_field (_svmt_class_info *class, const char *name,
		     const char *descriptor)
{
  jint fields_count = class->fields_count;
  _svmt_field_info *fields = class->fields;
  jint i;

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  for (i = 0; i < fields_count; i++)
    {
      _svmt_field_info *field = &fields[i];

      if (strcmp (name, DREF (field->name, value)) == 0 &&
	  strcmp (descriptor, DREF (field->descriptor, value)) == 0)
	{
	  return field;
	}
    }

  {
    jint interfaces_count = class->interfaces_count;
    _svmt_CONSTANT_Class_info ***interfaces = class->interfaces;

    /* This should be improved to operate like class preparation and
       avoid exponential loopkup. */
    for (i = 0; i < interfaces_count; i++)
      {
	_svmt_class_info *super_interface =
	  _svmf_cast_class (DREF (interfaces[i], type));
	_svmt_field_info *field =
	  _svmf_resolve_field (super_interface, name, descriptor);

	if (field != NULL)
	  {
	    return field;
	  }
      }
  }

  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));

      return _svmf_resolve_field (super_class, name, descriptor);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_resolve_CONSTANT_Fieldref
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_CONSTANT_Fieldref (_svmt_JNIEnv *env, _svmt_class_info *class,
				 _svmt_CONSTANT_Fieldref_info *fieldref)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_object_monitor (env, *(class->class_instance)) !=
	  JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (fieldref->field != NULL)
    {
      goto ok;
    }

  if (fieldref->resolution_error != NULL)
    {
      assert (*(fieldref->resolution_error) != NULL);

      *(env->throwable) = *(fieldref->resolution_error);
      goto error;
    }

  if (_svmm_new_native_global (env, fieldref->resolution_error) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_resolve_CONSTANT_Class (env, class, *(fieldref->class)) != JNI_OK)
    {
      *(fieldref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (_svmf_link_type (env, DREF (fieldref->class, type)) != JNI_OK)
    {
      *(fieldref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (DREF (fieldref->class, type)->is_array)
    {
      fieldref->field = _svmf_resolve_field
	(vm->class_loading.boot_loader.classes.jlobject,
	 DREF (DREF (fieldref->name_and_type, name), value),
	 DREF (DREF (fieldref->name_and_type, descriptor), value));
    }
  else
    {
      fieldref->field = _svmf_resolve_field
	(_svmf_cast_class (DREF (fieldref->class, type)),
	 DREF (DREF (fieldref->name_and_type, name), value),
	 DREF (DREF (fieldref->name_and_type, descriptor), value));
    }

  if (fieldref->field == NULL)
    {
      _svmf_error_NoSuchFieldError (env);

      *(fieldref->resolution_error) = *(env->throwable);
      goto error;
    }

  _svmm_free_native_global (env, fieldref->resolution_error);

ok:
  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_resolve_method
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_resolve_method (_svmt_class_info *class, const char *name,
		      const char *descriptor)
{
  jint methods_count = class->methods_count;
  _svmt_method_info *methods = class->methods;
  jint i;

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  for (i = 0; i < methods_count; i++)
    {
      _svmt_method_info *method = &methods[i];

      if (strcmp (name, DREF (method->name, value)) == 0 &&
	  strcmp (descriptor, DREF (method->descriptor, value)) == 0)
	{
	  return method;
	}
    }

  /* 
     JVM Specification bug: 

     It is important NOT to resolve special <init> and <clinit>
     methods to super classes or interfaces; yet, this is not
     explicited in the specification.  Section 5.4.3.3 should be
     updated appropriately.
   */
  if (name[0] == '<')
    {
      return NULL;
    }

  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));
      _svmt_method_info *method =
	_svmf_resolve_method (super_class, name, descriptor);

      if (method != NULL)
	{
	  return method;
	}
    }

  {
    jint interfaces_count = class->interfaces_count;
    _svmt_CONSTANT_Class_info ***interfaces = class->interfaces;

    for (i = 0; i < interfaces_count; i++)
      {
	_svmt_class_info *super_interface =
	  _svmf_cast_class (DREF (interfaces[i], type));
	_svmt_method_info *method =
	  _svmf_resolve_method (super_interface, name, descriptor);

	if (method != NULL)
	  {
	    return method;
	  }
      }
  }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_resolve_incomplete_method
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_resolve_incomplete_method (_svmt_class_info *class, const char *name,
				 const char *incomplete_descriptor)
{
  jint methods_count = class->methods_count;
  _svmt_method_info *methods = class->methods;
  jint i;
  size_t length = strlen (incomplete_descriptor);

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));
  assert (name[0] != '<');

  for (i = 0; i < methods_count; i++)
    {
      _svmt_method_info *method = &methods[i];

      if (strcmp (name, DREF (method->name, value)) == 0 &&
	  strncmp (incomplete_descriptor, DREF (method->descriptor, value),
		   length) == 0)
	{
	  return method;
	}
    }

  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));
      _svmt_method_info *method =
	_svmf_resolve_incomplete_method (super_class, name,
					 incomplete_descriptor);

      if (method != NULL)
	{
	  return method;
	}
    }

  {
    jint interfaces_count = class->interfaces_count;
    _svmt_CONSTANT_Class_info ***interfaces = class->interfaces;

    for (i = 0; i < interfaces_count; i++)
      {
	_svmt_class_info *super_interface =
	  _svmf_cast_class (DREF (interfaces[i], type));
	_svmt_method_info *method =
	  _svmf_resolve_incomplete_method (super_interface, name,
					   incomplete_descriptor);

	if (method != NULL)
	  {
	    return method;
	  }
      }
  }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_resolve_CONSTANT_Methodref
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_CONSTANT_Methodref (_svmt_JNIEnv *env, _svmt_class_info *class,
				  _svmt_CONSTANT_Methodref_info *methodref)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_object_monitor (env, *(class->class_instance)) !=
	  JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (methodref->method != NULL)
    {
      goto ok;
    }

  if (methodref->resolution_error != NULL)
    {
      assert (*(methodref->resolution_error) != NULL);

      *(env->throwable) = *(methodref->resolution_error);
      goto error;
    }

  if (_svmm_new_native_global (env, methodref->resolution_error) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_resolve_CONSTANT_Class (env, class, *(methodref->class)) !=
      JNI_OK)
    {
      *(methodref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (_svmf_link_type (env, DREF (methodref->class, type)) != JNI_OK)
    {
      *(methodref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (DREF (methodref->class, type)->is_array)
    {
      methodref->method = _svmf_resolve_method
	(vm->class_loading.boot_loader.classes.jlobject,
	 DREF (DREF (methodref->name_and_type, name), value),
	 DREF (DREF (methodref->name_and_type, descriptor), value));
    }
  else
    {
      methodref->method = _svmf_resolve_method
	(_svmf_cast_class (DREF (methodref->class, type)),
	 DREF (DREF (methodref->name_and_type, name), value),
	 DREF (DREF (methodref->name_and_type, descriptor), value));
    }

  if (methodref->method == NULL)
    {
      _svmf_error_NoSuchMethodError (env);

      *(methodref->resolution_error) = *(env->throwable);
      goto error;
    }

  _svmm_free_native_global (env, methodref->resolution_error);

ok:
  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_resolve_imethod
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_resolve_imethod (_svmt_class_info *class, const char *name,
		       const char *descriptor)
{
  jint methods_count = class->methods_count;
  _svmt_method_info *methods = class->methods;
  jint i;

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  for (i = 0; i < methods_count; i++)
    {
      _svmt_method_info *method = &methods[i];

      if (strcmp (name, DREF (method->name, value)) == 0 &&
	  strcmp (descriptor, DREF (method->descriptor, value)) == 0)
	{
	  return method;
	}
    }

  {
    jint interfaces_count = class->interfaces_count;
    _svmt_CONSTANT_Class_info ***interfaces = class->interfaces;

    for (i = 0; i < interfaces_count; i++)
      {
	_svmt_class_info *super_interface =
	  _svmf_cast_class (DREF (interfaces[i], type));
	_svmt_method_info *method =
	  _svmf_resolve_imethod (super_interface, name, descriptor);

	if (method != NULL)
	  {
	    return method;
	  }
      }
  }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_resolve_CONSTANT_InterfaceMethodref
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_CONSTANT_InterfaceMethodref (_svmt_JNIEnv *env,
					   _svmt_class_info *class,
					   _svmt_CONSTANT_InterfaceMethodref_info
					   *imethodref)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_object_monitor (env, *(class->class_instance)) !=
	  JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (imethodref->method != NULL)
    {
      goto ok;
    }

  if (imethodref->resolution_error != NULL)
    {
      assert (*(imethodref->resolution_error) != NULL);

      *(env->throwable) = *(imethodref->resolution_error);
      goto error;
    }

  if (_svmm_new_native_global (env, imethodref->resolution_error) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_resolve_CONSTANT_Class (env, class, *(imethodref->class)) !=
      JNI_OK)
    {
      *(imethodref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (_svmf_link_type (env, DREF (imethodref->class, type)) != JNI_OK)
    {
      *(imethodref->resolution_error) = *(env->throwable);
      goto error;
    }

  if (DREF (imethodref->class, type)->is_array)
    {
      imethodref->method = _svmf_resolve_imethod
	(vm->class_loading.boot_loader.classes.jlobject,
	 DREF (DREF (imethodref->name_and_type, name), value),
	 DREF (DREF (imethodref->name_and_type, descriptor), value));
    }
  else
    {
      imethodref->method = _svmf_resolve_imethod
	(_svmf_cast_class (DREF (imethodref->class, type)),
	 DREF (DREF (imethodref->name_and_type, name), value),
	 DREF (DREF (imethodref->name_and_type, descriptor), value));
    }

  if (imethodref->method == NULL)
    {
      _svmf_error_NoSuchMethodError (env);

      *(imethodref->resolution_error) = *(env->throwable);
      goto error;
    }

  _svmm_free_native_global (env, imethodref->resolution_error);

ok:
  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *(class->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_resolve_CONSTANT_String
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_CONSTANT_String (_svmt_JNIEnv *env,
			       _svmt_CONSTANT_String_info *stringref)
{
  jstring string;

  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_object_monitor
	  (env, *(stringref->class_info->class_instance)) != JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (stringref->value != NULL)
    {
      assert (*(stringref->value) != NULL);

      goto ok;
    }

  if (_svmm_new_native_global (env, string) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_get_interned_string (env, DREF (stringref->string, value), string)
      != JNI_OK)
    {
      _svmm_free_native_global (env, string);
      goto error;
    }

  stringref->value = string;

ok:
  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env, *(stringref->class_info->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env, *(stringref->class_info->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_resolve_special_method
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_resolve_special_method (_svmt_class_info *class, const char *name,
			      const char *descriptor)
{
  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  while (class != NULL)
    {
      jint methods_count = class->methods_count;
      _svmt_method_info *methods = class->methods;
      jint i;

      for (i = 0; i < methods_count; i++)
	{
	  _svmt_method_info *method = &methods[i];

	  if (strcmp (name, DREF (method->name, value)) == 0 &&
	      strcmp (descriptor, DREF (method->descriptor, value)) == 0)
	    {
	      return method;
	    }
	}

      if (CAN_DREF (class->super_class))
	{
	  class = _svmf_cast_class (DREF (class->super_class, type));
	}
      else
	{
	  class = NULL;
	}
    }

  _svmm_fatal_error ("impossible control flow");
  return NULL;
}
