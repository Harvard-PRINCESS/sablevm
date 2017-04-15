/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetDeclaringClass
 * Signature: ([B)Ljava/lang/Class;
 */
JNIEXPORT static jclass JNICALL
Java_java_lang_reflect_Method_nativeGetDeclaringClass (JNIEnv *_env,
						       jclass _class
						       SVM_UNUSED,
						       jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass dclass;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);

    dclass = _svmf_get_jni_frame_native_local (env);
    *dclass = *(method->class_info->class_instance);
  }

  _svmm_stopping_java (env);

  return dclass;
}

/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetName
 * Signature: ([B)Ljava/lang/String;
 */
JNIEXPORT static jstring JNICALL
Java_java_lang_reflect_Method_nativeGetName (JNIEnv *_env,
					     jclass _class SVM_UNUSED,
					     jbyteArray vmData)
{
/*
 * Based on Java_java_lang_Class_nativeGetName
 */
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring name;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);

    name = _svmf_get_jni_frame_native_local (env);
    /* Creates a new string instance with the char[] */
    _svmf_get_string (env, (*(method->name))->value, name);
  }

  _svmm_stopping_java (env);

  return name;
}



/*
 * Class:     java_lang_reflect_Method
 * Method:    getModifiers
 * Signature: ()I
 */
JNIEXPORT static jint JNICALL
Java_java_lang_reflect_Method_nativeGetModifiers (JNIEnv *_env,
						  jclass _class SVM_UNUSED,
						  jbyteArray vmData)
{
/*
 * Note: function prototype changed to make it similar to others
 *       and to simplify coding.
 *
 * Based on Java_java_lang_Class_getModifiers
 *
 */
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint modifiers;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);

    /* make sure not to return any internal flags */
    modifiers = method->access_flags &
      (SVM_ACC_ABSTRACT |
       SVM_ACC_FINAL |
       SVM_ACC_NATIVE |
       SVM_ACC_PRIVATE |
       SVM_ACC_PROTECTED |
       SVM_ACC_PUBLIC | SVM_ACC_STATIC | SVM_ACC_SYNCHRONIZED);
    /* what is the modifier STRICT? */
  }

  _svmm_stopping_java (env);

  return modifiers;

}


/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetExceptionTypes
 * Signature: ([B)[Ljava/lang/Class;
 */
JNIEXPORT static jobjectArray JNICALL
Java_java_lang_reflect_Method_nativeGetExceptionTypes (JNIEnv *_env,
						       jclass _class
						       SVM_UNUSED,
						       jbyteArray vmData)
{

  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobjectArray classes = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);
    _svmt_Exceptions_attribute *exceptions_attribute = NULL;
    jint exceptions_count = 0;
    jint i;

    for (i = 0; i < method->attributes_count; i++)
      {
	_svmt_attribute_info *attribute;

	attribute = method->attributes[i];
	if (strcmp (DREF (attribute->name, value), "Exceptions") == 0)
	  {
	    exceptions_attribute =
	      _svmf_cast_Exceptions_attribute (attribute);
	    exceptions_count = exceptions_attribute->number_of_exceptions;
	  }
      }

    /* Create Class[] array for exceptions */
    {
      static _svmt_array_info *class_array_info = NULL;
      _svmt_class_info *class_class_info;

      class_class_info = vm->class_loading.boot_loader.classes.jlclass;

      /* Load and link Class[] if necessary */
      if (class_array_info == NULL)
	{

	  /* creates type Class[] */
	  if (_svmm_create_array
	      (env,
	       class_class_info->class_loader_info,
	       class_class_info->array_type_name, class_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	  /* link the type Class[] */
	  if (_svmf_link_array (env, class_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	}

      /* create exception Class[] array */
      classes = _svmf_get_jni_frame_native_local_array (env);
      if (_svmm_new_array_instance (env,
				    class_array_info,
				    exceptions_count, *classes) != JNI_OK)
	{
	  goto end;
	}


      for (i = 0; i < exceptions_count; i++)
	{
	  _svmt_CONSTANT_Class_info *info;
	  _svmt_object_instance *class_instance;

	  info = *(exceptions_attribute->exception_table[i]);

	  if (_svmf_resolve_CONSTANT_Class
	      (env, method->class_info, info) != JNI_OK)
	    {
	      _svmm_release_jni_frame_native_local_array (classes);
	      goto end;
	    }


	  class_instance = *(info->type->class_instance);

	  if (_svmf_set_reference_array_element_no_exception
	      (env, *classes, i, class_instance) != JNI_OK)
	    {
	      _svmm_release_jni_frame_native_local_array (classes);
	      goto end;
	    }
	}

    }

  }


end:
  _svmm_stopping_java (env);

  return classes;


}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Method_invokeNative
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Method
 * Method:    invokeNative
 * Signature: ([B[CCLjava/lang/Object;[Ljava/lang/Object;Ljava/lang/Object;)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_reflect_Method_invokeNative (JNIEnv *_env,
					    jclass _class SVM_UNUSED,
					    jbyteArray vmData,
					    jcharArray _params,
					    jchar resultType, jobject obj,
					    jobjectArray _args,
					    jobject result)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject current_exception = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);

    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_frame_info *frame_info = method->frame_info;
    jboolean is_static =
      _svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC);

    if (_svmm_new_native_local (env, current_exception) != JNI_OK)
      {
	goto end;
      }

    if (!is_static)
      {
	if (obj == NULL)
	  {
	    _svmf_error_NullPointerException (env);
	    goto end;
	  }

	if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_PRIVATE))
	  {
	    /* It's not a private or static method. Dynamic lookup required. */
	    size_t method_offset;

	    if (_svmf_is_set_flag
		(method->class_info->access_flags, SVM_ACC_INTERFACE))
	      {
		/* INVOKEINTERFACE */
		method_offset =
		  -((1 + method->method_id) * sizeof (_svmt_method_info *));
	      }
	    else
	      {
		/* INVOKEVIRTUAL */
		method_offset =
		  sizeof (_svmt_vtable) +
		  (method->method_id * sizeof (_svmt_method_info *));
	      }

	    /* replace "method" by appropriate call target. */
	    method =
	      *((_svmt_method_info **) (void *)
		(((char *) (*obj)->vtable) + method_offset));
	    frame_info = method->frame_info;
	  }
      }

    /* make sure the method's class is initialized */
    if (_svmf_link_class (env, method->class_info) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_class_initialization (env, method->class_info) != JNI_OK)
      {
	goto end;
      }

    /* syncronized? */
    if (method->synchronized)
      {
	if (is_static)
	  {
	    if (_svmf_enter_object_monitor
		(env, *(method->class_info->class_instance)) != JNI_OK)
	      {
		goto end;
	      }
	  }
	else
	  {
	    if (_svmf_enter_object_monitor (env, *obj) != JNI_OK)
	      {
		goto end;
	      }
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;

      if (!is_static)
	{
	  locals[i++].reference = *obj;
	}

      {
	_svmt_array_instance *params = *_params;
	_svmt_array_instance *args = *_args;
	jint count = params->size;
	jint j;

	for (j = 0; j < count; j++)
	  {
	    switch (_svmf_get_char_array_element (params, j))
	      {
	      case 'Z':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jint =
		    _svmf_get_boolean_array_element (wrapper, 0);
		}
		break;

	      case 'B':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jint =
		    _svmf_get_byte_array_element (wrapper, 0);
		}
		break;

	      case 'S':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jint =
		    _svmf_get_short_array_element (wrapper, 0);
		}
		break;

	      case 'C':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jint =
		    _svmf_get_char_array_element (wrapper, 0);
		}
		break;

	      case 'I':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jint = _svmf_get_int_array_element (wrapper, 0);
		}
		break;

	      case 'J':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  *((jlong *) (void *) &locals[i]) =
		    _svmf_get_long_array_element (wrapper, 0);
		  i += 2;
		}
		break;

	      case 'F':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  locals[i++].jfloat =
		    _svmf_get_float_array_element (wrapper, 0);
		}
		break;

	      case 'D':
		{
		  _svmt_array_instance *wrapper =
		    _svmf_cast_array_instance
		    (_svmf_get_reference_array_element (args, j));
		  *((jdouble *) (void *) &locals[i]) =
		    _svmf_get_double_array_element (wrapper, 0);
		  i += 2;
		}
		break;

	      case 'L':
		{
		  locals[i++].reference =
		    _svmf_get_reference_array_element (args, j);
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
      }

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      if (is_static)
	{
	  frame->this = *(method->class_info->class_instance);
	}
      else
	{
	  frame->this = *obj;
	}
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  assert (*(env->throwable) != NULL);

	  /* save current exception */
	  *current_exception = *(env->throwable);
	  *(env->throwable) = NULL;

	  /* Exception must be wrapped into a new
	     InvocationTargetException */
	  status =
	    _svmf_wrap_exception_in_invocationte (env, current_exception);

	  assert (status != JNI_OK);

	  goto end;
	}

      /* set the return value */
      {
	_svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
	  (((char *) frame) + frame->end_offset);

	switch (resultType)
	  {
	  case 'Z':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_boolean_array_element (wrapper, 0, ptr_ret->jint);
	    }
	    break;

	  case 'B':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_byte_array_element (wrapper, 0, ptr_ret->jint);
	    }
	    break;

	  case 'S':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_short_array_element (wrapper, 0, ptr_ret->jint);
	    }
	    break;

	  case 'C':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_char_array_element (wrapper, 0, ptr_ret->jint);
	    }
	    break;

	  case 'I':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_int_array_element (wrapper, 0, ptr_ret->jint);
	    }
	    break;

	  case 'J':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_long_array_element (wrapper, 0,
					    *((jlong *) (void *) ptr_ret));
	    }
	    break;

	  case 'F':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_float_array_element (wrapper, 0, ptr_ret->jfloat);
	    }
	    break;

	  case 'D':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_double_array_element (wrapper, 0,
					      *((jdouble *) (void *)
						ptr_ret));
	    }
	    break;

	  case 'L':
	    {
	      _svmt_array_instance *wrapper =
		_svmf_cast_array_instance (*result);
	      _svmf_set_reference_array_element_no_exception (env, wrapper, 0,
							      ptr_ret->
							      reference);
	    }
	    break;

	  case 'V':
	    {
	      /* do nothing */
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }
    }

    goto end;
  }

end:

  if (current_exception != NULL)
    {
      _svmm_free_native_local (env, current_exception);
    }

  _svmm_stopping_java (env);
}


/*
 * Class:     java_lang_reflect_Method
 * Method:    nativeGetDescriptor
 * Signature: ([B)Ljava/lang/String;
 */
JNIEXPORT static jstring JNICALL
Java_java_lang_reflect_Method_nativeGetDescriptor (JNIEnv *_env,
						   jclass _class SVM_UNUSED,
						   jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring descriptor;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *method = _svmf_unwrap_pointer (*vmData);

    descriptor = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, DREF (method->descriptor, value), descriptor);
  }

  _svmm_stopping_java (env);

  return descriptor;
}
