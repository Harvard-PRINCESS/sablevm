/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */




/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetDeclaringClass
 * Signature: ([B)Ljava/lang/Class;
 */
JNIEXPORT static jclass JNICALL
Java_java_lang_reflect_Constructor_nativeGetDeclaringClass (JNIEnv *_env,
							    jclass _class,
							    jbyteArray vmData)
{
  return Java_java_lang_reflect_Method_nativeGetDeclaringClass (_env,
								_class,
								vmData);
}

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    getModifiers
 * Signature: ()I
 */
JNIEXPORT static jint JNICALL
Java_java_lang_reflect_Constructor_nativeGetModifiers (JNIEnv *_env,
						       jclass _class,
						       jbyteArray vmData)
{
  return Java_java_lang_reflect_Method_nativeGetModifiers (_env,
							   _class, vmData);
}

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetParameterTypes
 * Signature: ([B)[Ljava/lang/Class;
 */
/* This one is done in Java */


/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetExceptionTypes
 * Signature: ([B)[Ljava/lang/Class;
 */
JNIEXPORT static jobjectArray JNICALL
Java_java_lang_reflect_Constructor_nativeGetExceptionTypes (JNIEnv *_env,
							    jclass _class,
							    jbyteArray vmData)
{
  return Java_java_lang_reflect_Method_nativeGetExceptionTypes (_env,
								_class,
								vmData);
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Constructor_constructNative
----------------------------------------------------------------------
*/



/*
 * Class:     java_lang_reflect_Constructor
 * Method:    constructNative
 * Signature: ([B[C[Ljava/lang/Object;)Ljava/lang/Object;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_reflect_Constructor_constructNative (JNIEnv *_env,
						    jclass _class SVM_UNUSED,
						    jbyteArray vmData,
						    jcharArray _params,
						    jobjectArray _args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject current_exception = NULL;
  jobject this = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *constructor = _svmf_unwrap_pointer (*vmData);

    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_frame_info *frame_info = constructor->frame_info;

    if (_svmm_new_native_local (env, current_exception) != JNI_OK)
      {
	goto end;
      }

    /*
     * Note: If class has not been linked, constructor->class_info
     *       is NULL.  We put the link code in getDeclaredConstructors
     *       for simplicity.
     */
    if (_svmf_class_initialization (env, constructor->class_info) != JNI_OK)
      {
	goto end;
      }

    this = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, constructor->class_info, *this) !=
	JNI_OK)
      {
	goto end;
      }

    /* syncronized? */
    if (constructor->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	  {
	    goto end;
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

      locals[i++].reference = *this;

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
      frame->method = constructor;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
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

    }

    goto end;
  }

end:

  if (current_exception != NULL)
    {
      _svmm_free_native_local (env, current_exception);
    }

  _svmm_stopping_java (env);

  return this;
}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Constructor_nativeGetDescriptor
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetDescriptor
 * Signature: ([B)Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_java_lang_reflect_Constructor_nativeGetDescriptor (JNIEnv *_env,
							jclass _class
							SVM_UNUSED,
							jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring descriptor;

  _svmm_resuming_java (env);

  {
    _svmt_method_info *constructor = _svmf_unwrap_pointer (*vmData);

    descriptor = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, DREF (constructor->descriptor, value), descriptor);
  }

  _svmm_stopping_java (env);

  return descriptor;
}
