/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";
m4svm_define_end v = ":])";

/*                                                                                                                                                                                            
----------------------------------------------------------------------                                                                                                                        
m4svm_file_tail                                                                                                                                                                              
----------------------------------------------------------------------                                                                                                                        
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_nonvirtual
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_nonvirtual)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_nonvirtual:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_nonvirtual_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint
_svmh_invoke_nonvirtual_$1 (_svmt_JNIEnv *env, jobject m4svm_arglist)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.$1;
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

    /* m4svm_comment_define([:m4svm_pushargs:],
     * [:[:m4svm_for([:arg:], 3, $:][:#,
     * :]m4svm_lbkt[:m4svm_pushargs_1(
     * m4svm_argn(arg, $:][:@),
     * param_[::]m4_eval(arg - 2)):]m4svm_rbkt[:)[::]m4_dnl
     * :]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_pushargs_1:],
     * [:m4_ifelse(
     *
     * $1, jint,
     * [:locals[i++].jint = $2;
     *     :],
     *
     * $1, jlong,
     * [:*((jlong *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jfloat,
     * [:locals[i++].jfloat = $2;
     *     :],
     *
     * $1, jdouble,
     * [:*((jdouble *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jobject,
     * [:locals[i++].reference = ($2 == NULL) ? NULL : *$2;
     *     :],
     *
     * [:
     * #error The type of $2 must be one of jint, jlong, jfloat, jdouble or jobject
     *     :]):]) */
    locals[i++].reference = *this;
    m4svm_pushargs = dummy;

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
    /* m4svm_comment_define([:m4svm_returnvalue:],
     * [:[:m4svm_returnvalue_1($:][:2):]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_returnvalue_1:],
     * [:m4_ifelse($1, void, ,
     * [:
     *     /[::]* set the return value *[::]/
     *     {
     *       _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
     *         (((char *) frame) + frame->end_offset);
     *
     *       m4_ifelse(
     *
     * $1, jint,
     * [:*ret = ptr_ret->jint;:],
     *
     * $1, jlong,
     * [:*ret = *((jlong *) ptr_ret);:],
     *
     * $1, jfloat,
     * [:*ret = ptr_ret->jfloat;:],
     *
     * $1, jdouble,
     * [:*ret = *((double *) ptr_ret);:],
     *
     * $1, jobject,
     * [:*ret = ptr_ret->reference;:],
     *
     * [:
     * #error the type of ret must be one of jint, m4_dnl
     * jlong, jfloat, jdouble or jobject:])
     *     }:]):]) */
    m4svm_returnvalue = dummy;

  }

  return JNI_OK;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_specific_nonvirtual
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_specific_nonvirtual)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_specific_nonvirtual:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_specific_nonvirtual_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint
_svmh_invoke_specific_nonvirtual_$1 (_svmt_JNIEnv *env,
				     _svmt_method_info *method,
				     jobject m4svm_arglist)
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

    /* m4svm_comment_define([:m4svm_pushargs:],
     * [:[:m4svm_for([:arg:], 3, $:][:#,
     * :]m4svm_lbkt[:m4svm_pushargs_1(
     * m4svm_argn(arg, $:][:@),
     * param_[::]m4_eval(arg - 2)):]m4svm_rbkt[:)[::]m4_dnl
     * :]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_pushargs_1:],
     * [:m4_ifelse(
     *
     * $1, jint,
     * [:locals[i++].jint = $2;
     *     :],
     *
     * $1, jlong,
     * [:*((jlong *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jfloat,
     * [:locals[i++].jfloat = $2;
     *     :],
     *
     * $1, jdouble,
     * [:*((jdouble *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jobject,
     * [:locals[i++].reference = ($2 == NULL) ? NULL : *$2;
     *     :],
     *
     * [:
     * #error The type of $2 must be one of jint, jlong, jfloat, jdouble or jobject
     *     :]):]) */
    locals[i++].reference = *this;
    m4svm_pushargs = dummy;

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
    /* m4svm_comment_define([:m4svm_returnvalue:],
     * [:[:m4svm_returnvalue_1($:][:2):]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_returnvalue_1:],
     * [:m4_ifelse($1, void, ,
     * [:
     *     /[::]* set the return value *[::]/
     *     {
     *       _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
     *         (((char *) frame) + frame->end_offset);
     *
     *       m4_ifelse(
     *
     * $1, jint,
     * [:*ret = ptr_ret->jint;:],
     *
     * $1, jlong,
     * [:*ret = *((jlong *) ptr_ret);:],
     *
     * $1, jfloat,
     * [:*ret = ptr_ret->jfloat;:],
     *
     * $1, jdouble,
     * [:*ret = *((double *) ptr_ret);:],
     *
     * $1, jobject,
     * [:*ret = ptr_ret->reference;:],
     *
     * [:
     * #error the type of ret must be one of jint, m4_dnl
     * jlong, jfloat, jdouble or jobject:])
     *     }:]):]) */
    m4svm_returnvalue = dummy;

  }

  return JNI_OK;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_static
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_static)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_static:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_static_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:env[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint
_svmh_invoke_static_$1 (_svmt_JNIEnv *m4svm_arglist)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = vm->class_loading.boot_loader.methods.$1;
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

    /* m4svm_comment_define([:m4svm_pushargs:],
     * [:[:m4svm_for([:arg:], 3, $:][:#,
     * :]m4svm_lbkt[:m4svm_pushargs_1(
     * m4svm_argn(arg, $:][:@),
     * param_[::]m4_eval(arg - 2)):]m4svm_rbkt[:)[::]m4_dnl
     * :]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_pushargs_1:],
     * [:m4_ifelse(
     *
     * $1, jint,
     * [:locals[i++].jint = $2;
     *     :],
     *
     * $1, jlong,
     * [:*((jlong *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jfloat,
     * [:locals[i++].jfloat = $2;
     *     :],
     *
     * $1, jdouble,
     * [:*((jdouble *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jobject,
     * [:locals[i++].reference = ($2 == NULL) ? NULL : *$2;
     *     :],
     *
     * [:
     * #error The type of $2 must be one of jint, jlong, jfloat, jdouble or jobject
     *     :]):]) */
    m4svm_pushargs = dummy;

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
    /* m4svm_comment_define([:m4svm_returnvalue:],
     * [:[:m4svm_returnvalue_1($:][:2):]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_returnvalue_1:],
     * [:m4_ifelse($1, void, ,
     * [:
     *     /[::]* set the return value *[::]/
     *     {
     *       _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
     *         (((char *) frame) + frame->end_offset);
     *
     *       m4_ifelse(
     *
     * $1, jint,
     * [:*ret = ptr_ret->jint;:],
     *
     * $1, jlong,
     * [:*ret = *((jlong *) ptr_ret);:],
     *
     * $1, jfloat,
     * [:*ret = ptr_ret->jfloat;:],
     *
     * $1, jdouble,
     * [:*ret = *((double *) ptr_ret);:],
     *
     * $1, jobject,
     * [:*ret = ptr_ret->reference;:],
     *
     * [:
     * #error the type of ret must be one of jint, m4_dnl
     * jlong, jfloat, jdouble or jobject:])
     *     }:]):]) */
    m4svm_returnvalue = dummy;

  }

  return JNI_OK;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_specific_static
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_specific_static)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_specific_static:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_specific_static_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:method[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint
_svmh_invoke_specific_static_$1 (_svmt_JNIEnv *env,
				 _svmt_method_info *m4svm_arglist)
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

    /* m4svm_comment_define([:m4svm_pushargs:],
     * [:[:m4svm_for([:arg:], 3, $:][:#,
     * :]m4svm_lbkt[:m4svm_pushargs_1(
     * m4svm_argn(arg, $:][:@),
     * param_[::]m4_eval(arg - 2)):]m4svm_rbkt[:)[::]m4_dnl
     * :]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_pushargs_1:],
     * [:m4_ifelse(
     *
     * $1, jint,
     * [:locals[i++].jint = $2;
     *     :],
     *
     * $1, jlong,
     * [:*((jlong *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jfloat,
     * [:locals[i++].jfloat = $2;
     *     :],
     *
     * $1, jdouble,
     * [:*((jdouble *) &locals[i]) = $2;
     *     i += 2;
     *     :],
     *
     * $1, jobject,
     * [:locals[i++].reference = ($2 == NULL) ? NULL : *$2;
     *     :],
     *
     * [:
     * #error The type of $2 must be one of jint, jlong, jfloat, jdouble or jobject
     *     :]):]) */
    m4svm_pushargs = dummy;

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
    /* m4svm_comment_define([:m4svm_returnvalue:],
     * [:[:m4svm_returnvalue_1($:][:2):]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_returnvalue_1:],
     * [:m4_ifelse($1, void, ,
     * [:
     *     /[::]* set the return value *[::]/
     *     {
     *       _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
     *         (((char *) frame) + frame->end_offset);
     *
     *       m4_ifelse(
     *
     * $1, jint,
     * [:*ret = ptr_ret->jint;:],
     *
     * $1, jlong,
     * [:*ret = *((jlong *) ptr_ret);:],
     *
     * $1, jfloat,
     * [:*ret = ptr_ret->jfloat;:],
     *
     * $1, jdouble,
     * [:*ret = *((double *) ptr_ret);:],
     *
     * $1, jobject,
     * [:*ret = ptr_ret->reference;:],
     *
     * [:
     * #error the type of ret must be one of jint, m4_dnl
     * jlong, jfloat, jdouble or jobject:])
     *     }:]):]) */
    m4svm_returnvalue = dummy;

  }

  return JNI_OK;
}

m4svm_define_end v = ":])";
