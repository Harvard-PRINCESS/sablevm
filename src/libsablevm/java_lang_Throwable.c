/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_Throwable_nativeGetStackTraceList
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_Throwable
 * Method:    nativeGetStackTraceList
 * Signature: ()Ljava/lang/StackTraceElement;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_Throwable_nativeGetStackTraceList (JNIEnv *_env, jobject this)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    size_t frame_offset = 0;	/* difference (in bytes) between top frame and current frame */
    _svmt_method_info *method;

    jint count = 0;		/* number of newly created elements */
    jint old_length = 0;	/* number of already created elements */
    jboolean done = JNI_FALSE;
    size_t length_field_offset =
      vm->class_loading.boot_loader.fields.jlstacktraceelement_length->data.
      instance_field.offset;
    size_t next_field_offset =
      vm->class_loading.boot_loader.fields.jlstacktraceelement_next->data.
      instance_field.offset;

    jobject stackTraceElement = NULL;

    jobject fileName = NULL;
    jint lineNumber = -1;
    jobject className = NULL;
    jobject methodName = NULL;
    jboolean isNative = JNI_FALSE;

#ifdef COMMENT
    _svmf_printf (env, stderr, "** Exception: %s\n",
		  (*this)->vtable->type->name);
#endif

    /* skip creation frames of this exception */
    while (frame->this == *this)
      {
	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	frame_offset = ((char *) env->stack.current_frame) - ((char *) frame);
      }

    method = frame->method;

    while ((!done) && method != &vm->stack_bottom_method)
      {
	_svmt_class_info *class;

	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    frame_offset =
	      ((char *) env->stack.current_frame) - ((char *) frame);
	    method = frame->method;
	    continue;
	  }

	isNative = _svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE);

	class = method->class_info;

	if (class->file_name != NULL)
	  {
	    fileName = _svmf_get_jni_frame_native_local (env);
	    if (_svmf_get_string (env, class->file_name, fileName) != JNI_OK)
	      {
		goto end;
	      }
	  }

	className = _svmf_get_jni_frame_native_local (env);
	if (_svmf_get_string (env, class->name, className) != JNI_OK)
	  {
	    goto end;
	  }

	methodName = _svmf_get_jni_frame_native_local (env);
	if (_svmf_get_string (env, DREF (method->name, value), methodName) !=
	    JNI_OK)
	  {
	    goto end;
	  }

	/* just in case things moved around */
	frame = (_svmt_stack_frame *) (void *)
	  (((char *) env->stack.current_frame) - ((char *) frame_offset));

	if ((!isNative) && method->data.code_attribute->line_numbers != NULL)
	  {
	    jint table_length =
	      method->data.code_attribute->line_numbers->
	      line_number_table_length;
	    _svmt_line_number_table *table =
	      method->data.code_attribute->line_numbers->line_number_table;
	    _svmt_code *pc = frame->pc;
	    jint i;

	    for (i = 0; i < table_length; i++)
	      {
		if ((pc >= table[i].normal_start && pc <= table[i].normal_end)
		    || (pc >= table[i].prepare_start
			&& pc <= table[i].prepare_end))
		  {
		    lineNumber = table[i].line_number;
		    break;
		  }
	      }
	  }

	stackTraceElement = _svmf_get_jni_frame_native_local (env);
	if (_svmm_new_object_instance
	    (env, vm->class_loading.boot_loader.classes.jlstacktraceelement,
	     *stackTraceElement) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_invoke_nonvirtual_jlstacktraceelement_init
	    (env, stackTraceElement,
	     fileName, lineNumber, className, methodName, isNative) != JNI_OK)
	  {
	    goto end;
	  }

	/* just in case things moved around */
	frame = (_svmt_stack_frame *) (void *)
	  (((char *) env->stack.current_frame) - ((char *) frame_offset));

#ifdef COMMENT
	_svmf_printf (env, stderr, "%s:%d %s.%s %c\n", class->file_name,
		      lineNumber, class->name, DREF (method->name, value),
		      (jint) (isNative ? 'n' : ' '));
#endif

	/* erase invalid cached elements */
	if (frame->stack_trace_element != NULL &&
	    _svmf_get_INT_field (frame->stack_trace_element,
				 length_field_offset) == 0)
	  {
	    frame->stack_trace_element = NULL;
	  }

	/* the first non-NULL cached element must be ignored, so we
	   erase it with this one and we're done creating elements */
	if (frame->stack_trace_element != NULL)
	  {
	    done = JNI_TRUE;
	    old_length =
	      _svmf_get_INT_field (frame->stack_trace_element,
				   length_field_offset) - 1;
	  }
	frame->stack_trace_element = *stackTraceElement;
	count++;

	/* we return the first created element. */
	if (result == NULL)
	  {
	    result = stackTraceElement;
	    stackTraceElement = NULL;
	  }
	else
	  {
	    _svmm_release_jni_frame_native_local (stackTraceElement);
	  }

	if (fileName != NULL)
	  {
	    _svmm_release_jni_frame_native_local (fileName);
	  }
	_svmm_release_jni_frame_native_local (className);
	_svmm_release_jni_frame_native_local (methodName);
	lineNumber = -1;
	isNative = JNI_FALSE;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	frame_offset = ((char *) env->stack.current_frame) - ((char *) frame);
	method = frame->method;
      }

    /* now we must validate the new elements by initializing their "next" and "length" fields. */
    frame = env->stack.current_frame;

    /* skip creation frames of this exception */
    while (frame->this == *this)
      {
	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
      }

    method = frame->method;

    {
      _svmt_object_instance *previous = NULL;

      while (count >= 0 && method != &vm->stack_bottom_method)
	{
	  /* skip internal frames */
	  if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	    {
	      frame = (_svmt_stack_frame *) (void *)
		(((char *) frame) - frame->previous_offset);
	      frame_offset =
		((char *) env->stack.current_frame) - ((char *) frame);
	      method = frame->method;
	      continue;
	    }

	  assert (frame->stack_trace_element != NULL);

	  if (count > 0)
	    {
	      assert (_svmf_get_INT_field (frame->stack_trace_element,
					   length_field_offset) == 0);
	      _svmf_put_INT_field (frame->stack_trace_element,
				   length_field_offset, count + old_length);
	    }

	  if (previous != NULL)
	    {
	      _svmf_put_REFERENCE_field (env, previous, next_field_offset,
					 frame->stack_trace_element);
	    }

	  previous = frame->stack_trace_element;
	  count--;

	  frame = (_svmt_stack_frame *) (void *)
	    (((char *) frame) - frame->previous_offset);
	  method = frame->method;
	}

      assert (count <= 0);
    }
  }

end:

#ifdef COMMENT
  _svmf_printf (env, stderr, "--\n");
#endif

  _svmm_stopping_java (env);

  return result;
}
