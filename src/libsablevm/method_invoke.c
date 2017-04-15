/* This file has been automatically generated from "method_invoke.list" */

/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlclass_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlclass_init (_svmt_JNIEnv *env, jobject this, jobject param_1, jobject param_2)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlclass_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    locals[i++].reference = (param_2 == NULL) ? NULL : *param_2;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlclass_init_primitive
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlclass_init_primitive (_svmt_JNIEnv *env, jobject this, jint param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlclass_init_primitive;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].jint = param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlclass_initialize
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlclass_initialize (_svmt_JNIEnv *env, jobject this, jint param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlclass_initialize;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].jint = param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlrconstructor_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlrconstructor_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlrconstructor_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlrfield_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlrfield_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlrfield_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlrinvocationtargetexception_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlrinvocationtargetexception_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlrinvocationtargetexception_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlrmethod_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlrmethod_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlrmethod_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_jlstacktraceelement_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_jlstacktraceelement_init (_svmt_JNIEnv *env, jobject this, jobject param_1, jint param_2, jobject param_3, jobject param_4, jint param_5)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.jlstacktraceelement_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    locals[i++].jint = param_2;
    locals[i++].reference = (param_3 == NULL) ? NULL : *param_3;
    locals[i++].reference = (param_4 == NULL) ? NULL : *param_4;
    locals[i++].jint = param_5;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ArithmeticException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ArithmeticException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ArithmeticException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ArrayIndexOutOfBoundsException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ArrayIndexOutOfBoundsException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ArrayIndexOutOfBoundsException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ArrayStoreException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ArrayStoreException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ArrayStoreException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ClassCastException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ClassCastException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ClassCastException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_IllegalMonitorStateException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_IllegalMonitorStateException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.IllegalMonitorStateException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NegativeArraySizeException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NegativeArraySizeException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NegativeArraySizeException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NoSuchFieldException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NoSuchFieldException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NoSuchFieldException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NoSuchMethodException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NoSuchMethodException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NoSuchMethodException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NullPointerException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NullPointerException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NullPointerException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_InterruptedException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_InterruptedException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.InterruptedException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_InliningException_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_InliningException_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.InliningException_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_AbstractMethodError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_AbstractMethodError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.AbstractMethodError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ClassCircularityError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ClassCircularityError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ClassCircularityError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ClassFormatError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ClassFormatError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ClassFormatError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_ExceptionInInitializerError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_ExceptionInInitializerError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.ExceptionInInitializerError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_IncompatibleClassChangeError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_IncompatibleClassChangeError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.IncompatibleClassChangeError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_InternalError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_InternalError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.InternalError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_LinkageError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_LinkageError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.LinkageError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NoClassDefFoundError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NoClassDefFoundError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NoClassDefFoundError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NoSuchFieldError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NoSuchFieldError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NoSuchFieldError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_NoSuchMethodError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_NoSuchMethodError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.NoSuchMethodError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_OutOfMemoryError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_OutOfMemoryError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.OutOfMemoryError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_UnsatisfiedLinkError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_UnsatisfiedLinkError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.UnsatisfiedLinkError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_UnsupportedClassVersionError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_UnsupportedClassVersionError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.UnsupportedClassVersionError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_nonvirtual_VerifyError_init
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_nonvirtual_VerifyError_init (_svmt_JNIEnv *env, jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.VerifyError_init;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_specific_nonvirtual_throwinit
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_specific_nonvirtual_throwinit (_svmt_JNIEnv *env,
				     _svmt_method_info *method,
				     jobject this, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      return JNI_ERR;
    }

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
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
    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_createinternedstring
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_createinternedstring (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_createinternedstring;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_createstring
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_createstring (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_createstring;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_createstringfromchars
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_createstringfromchars (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_createstringfromchars;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_getchars
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_getchars (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_getchars;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_getlength
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_getlength (_svmt_JNIEnv *env, jobject param_1, jint *ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_getlength;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->jint;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_getutfchars
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_getutfchars (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_getutfchars;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_stringcreator_getutflength
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_stringcreator_getutflength (_svmt_JNIEnv *env, jobject param_1, jint *ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.stringcreator_getutflength;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->jint;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_createarray
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_createarray (_svmt_JNIEnv *env, jobject param_1, jobject param_2, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_createarray;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    locals[i++].reference = (param_2 == NULL) ? NULL : *param_2;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_createclass
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_createclass (_svmt_JNIEnv *env, jobject param_1, jobject param_2, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_createclass;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    locals[i++].reference = (param_2 == NULL) ? NULL : *param_2;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_createrootthread
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_createrootthread (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_createrootthread;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_exceptiondescribe
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_exceptiondescribe (_svmt_JNIEnv *env, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescribe;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_exceptiondescription
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_exceptiondescription (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescription;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_exceptiontruncateddescription
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_exceptiontruncateddescription (_svmt_JNIEnv *env, jobject param_1, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_exceptiontruncateddescription;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_getsystemcl
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_getsystemcl (_svmt_JNIEnv *env, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_getsystemcl;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_virtualmachine_runthread
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_virtualmachine_runthread (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.virtualmachine_runthread;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_niobytebuffervm_getcapacity
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_niobytebuffervm_getcapacity (_svmt_JNIEnv *env, jobject param_1, jlong *ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.niobytebuffervm_getcapacity;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = *((jlong *) ptr_ret);
    }
  }

  return JNI_OK;
}


#if SVM_WORD_BIT_COUNT == 32

/*
----------------------------------------------------------------------
_svmh_invoke_static_niobytebuffervm_newbuffer32
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_niobytebuffervm_newbuffer32 (_svmt_JNIEnv *env, jint param_1, jlong param_2, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer32;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].jint = param_1;
    *((jlong *) &locals[i]) = param_2;
    i += 2;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_niobytebuffervm_getaddress32
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_niobytebuffervm_getaddress32 (_svmt_JNIEnv *env, jobject param_1, jint *ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress32;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->jint;
    }
  }

  return JNI_OK;
}


#elif SVM_WORD_BIT_COUNT == 64

/*
----------------------------------------------------------------------
_svmh_invoke_static_niobytebuffervm_newbuffer64
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_niobytebuffervm_newbuffer64 (_svmt_JNIEnv *env, jlong param_1, jlong param_2, jobject ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer64;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    *((jlong *) &locals[i]) = param_1;
    i += 2;
    *((jlong *) &locals[i]) = param_2;
    i += 2;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = ptr_ret->reference;
    }
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_static_niobytebuffervm_getaddress64
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_static_niobytebuffervm_getaddress64 (_svmt_JNIEnv *env, jobject param_1, jlong *ret)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress64;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
    /* set the return value */
    {
      _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
        (((char *) frame) + frame->end_offset);

      *ret = *((jlong *) ptr_ret);
    }
  }

  return JNI_OK;
}


#endif

/*
----------------------------------------------------------------------
_svmh_invoke_specific_static_clinit
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_specific_static_clinit (_svmt_JNIEnv *env,
				 _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_PREPARED));
  assert (strcmp (DREF (method->name, value), "<clinit>") == 0
	  || _svmf_is_set_flag (method->class_info->state,
				SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmh_invoke_specific_static_main
----------------------------------------------------------------------
*/

svm_static jint
_svmh_invoke_specific_static_main (_svmt_JNIEnv *env,
				 _svmt_method_info *method, jobject param_1)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_frame_info *frame_info = method->frame_info;

  assert (_svmf_is_set_flag
	  (method->class_info->state, SVM_TYPE_STATE_PREPARED));
  assert (strcmp (DREF (method->name, value), "<clinit>") == 0
	  || _svmf_is_set_flag (method->class_info->state,
				SVM_TYPE_STATE_INITIALIZED));

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      return JNI_ERR;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->vm_initiated_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->vm_initiated_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;

    locals[i++].reference = (param_1 == NULL) ? NULL : *param_1;
    
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
    frame->this = *(method->class_info->class_instance);
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

    assert (frame->method == &vm->vm_initiated_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	return JNI_ERR;
      }
    
  }

  return JNI_OK;
}

