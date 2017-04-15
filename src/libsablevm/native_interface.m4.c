/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */

/*
----------------------------------------------------------------------
m4svm_NewArray
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_NewArray:])";

/*
-----------------------------------m4_dnl
-----------------------------------
New$1Array
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static j$2Array JNICALL
New$1Array (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.$2_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}

m4svm_define_end v = ":])";

/* m4svm_NewArray(Boolean, boolean) */
/* m4svm_NewArray(Byte, byte) */
/* m4svm_NewArray(Short, short) */
/* m4svm_NewArray(Char, char) */
/* m4svm_NewArray(Int, int) */
/* m4svm_NewArray(Long, long) */
/* m4svm_NewArray(Float, float) */
/* m4svm_NewArray(Double, double) */

/* m4_undefine([:m4svm_NewArray:]) */

/*
----------------------------------------------------------------------
m4svm_GetField
----------------------------------------------------------------------
*/
m4svm_define_begin v = ":], [:m4svm_GetField:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Get$1Field
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static $2 JNICALL
Get$1Field (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  $2 value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_$3_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}

m4svm_define_end v = ":])";

/* m4svm_GetField(Boolean, jboolean, BOOLEAN) */
/* m4svm_GetField(Byte, jbyte, BYTE) */
/* m4svm_GetField(Short, jshort, SHORT) */
/* m4svm_GetField(Char, jchar, CHAR) */
/* m4svm_GetField(Int, jint, INT) */
/* m4svm_GetField(Long, jlong, LONG) */
/* m4svm_GetField(Float, jfloat, FLOAT) */
/* m4svm_GetField(Double, jdouble, DOUBLE) */

/* m4_undefine([:m4svm_GetField:]) */

/*
----------------------------------------------------------------------
m4svm_SetField
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_SetField:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Set$1Field
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static void JNICALL
Set$1Field (JNIEnv *_env, jobject obj, jfieldID fieldID, $2 value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_$3_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}

m4svm_define_end v = ":])";

/* m4svm_SetField(Boolean, jboolean, BOOLEAN) */
/* m4svm_SetField(Byte, jbyte, BYTE) */
/* m4svm_SetField(Short, jshort, SHORT) */
/* m4svm_SetField(Char, jchar, CHAR) */
/* m4svm_SetField(Int, jint, INT) */
/* m4svm_SetField(Long, jlong, LONG) */
/* m4svm_SetField(Float, jfloat, FLOAT) */
/* m4svm_SetField(Double, jdouble, DOUBLE) */

/* m4_undefine([:m4svm_SetField:]) */

/*
----------------------------------------------------------------------
m4svm_GetStaticField
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_GetStaticField:])";

/*
-----------------------------------m4_dnl
-----------------------------------
GetStatic$1Field
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static $2 JNICALL
GetStatic$1Field (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  $2 value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.$3;

  _svmm_stopping_java (env);

  return value;
}

m4svm_define_end v = ":])";

/* m4svm_GetStaticField(Boolean, jboolean, z) */
/* m4svm_GetStaticField(Byte, jbyte, b) */
/* m4svm_GetStaticField(Short, jshort, s) */
/* m4svm_GetStaticField(Char, jchar, c) */
/* m4svm_GetStaticField(Int, jint, i) */
/* m4svm_GetStaticField(Long, jlong, j) */
/* m4svm_GetStaticField(Float, jfloat, f) */
/* m4svm_GetStaticField(Double, jdouble, d) */

/* m4_undefine([:m4svm_GetStaticField:]) */

/*
----------------------------------------------------------------------
m4svm_SetStaticField
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_SetStaticField:])";

/*
-----------------------------------m4_dnl
-----------------------------------
SetStatic$1Field
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStatic$1Field (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  $2 value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.$3 = value;

  _svmm_stopping_java (env);
}

m4svm_define_end v = ":])";

/* m4svm_SetStaticField(Boolean, jboolean, z) */
/* m4svm_SetStaticField(Byte, jbyte, b) */
/* m4svm_SetStaticField(Short, jshort, s) */
/* m4svm_SetStaticField(Char, jchar, c) */
/* m4svm_SetStaticField(Int, jint, i) */
/* m4svm_SetStaticField(Long, jlong, j) */
/* m4svm_SetStaticField(Float, jfloat, f) */
/* m4svm_SetStaticField(Double, jdouble, d) */

/* m4_undefine([:m4svm_SetStaticField:]) */

/*
----------------------------------------------------------------------
m4svm_internal_CallNonvirtualMethod
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_internal_CallNonvirtualMethod:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_internal_CallNonvirtual$1Method$2
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:methodID, m4_dnl
 * m4_ifelse($:][:2, A, jvalue *args,
 * $:][:2, V, va_list args)[::]m4_dnl
 * :]:]) */
JNIEXPORT svm_static $3 JNICALL
_svmf_internal_CallNonvirtual$1Method$2 (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID m4svm_arglist)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  /* m4svm_comment_define([:m4svm_result_decl:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * $:][:1, Object, $:][:3 result = NULL;
   * ,
   * $:][:3 result = 0;
   * )m4_:][:dnl:]:]) */
  m4svm_result_decl dummy;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
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
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    /* m4svm_comment_define([:m4svm_arg_decl:],
     * [:[:m4_ifelse(
     * $:][:2, A, jint arg = 0;
     * ,
     * )m4_:][:dnl:]:]) */
    m4svm_arg_decl dummy;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != '[:):]')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* m4svm_comment_define([:m4svm_arg_comment:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, locals,
	       * /[::]* Take into account ISO C's default argument promotion. *[::]/
	       *                 locals)[::]m4_dnl
	       * :]:]) */
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].z,
	       * va_arg (args, jint))[::]m4_dnl
	       * :]:]) */
	      m4svm_arg_comment[i++].jint = m4svm_arg;
	    }
	    break;

	  case 'B':
	    {
	      /* m4svm_comment_define([:m4svm_arg_comment:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, locals,
	       * /[::]* Take into account ISO C's default argument promotion. *[::]/
	       *                 locals)[::]m4_dnl
	       * :]:]) */
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].b,
	       * va_arg (args, jint))[::]m4_dnl
	       * :]:]) */
	      m4svm_arg_comment[i++].jint = m4svm_arg;
	    }
	    break;

	  case 'S':
	    {
	      /* m4svm_comment_define([:m4svm_arg_comment:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, locals,
	       * /[::]* Take into account ISO C's default argument promotion. *[::]/
	       *                 locals)[::]m4_dnl
	       * :]:]) */
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].s,
	       * va_arg (args, jint))[::]m4_dnl
	       * :]:]) */
	      m4svm_arg_comment[i++].jint = m4svm_arg;
	    }
	    break;

	  case 'C':
	    {
	      /* m4svm_comment_define([:m4svm_arg_comment:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, locals,
	       * /[::]* Take into account ISO C's default argument promotion. *[::]/
	       *                 locals)[::]m4_dnl
	       * :]:]) */
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].c,
	       * va_arg (args, int))[::]m4_dnl
	       * :]:]) */
	      m4svm_arg_comment[i++].jint = m4svm_arg;
	    }
	    break;

	  case 'I':
	    {
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].i,
	       * va_arg (args, jint))[::]m4_dnl
	       * :]:]) */
	      locals[i++].jint = m4svm_arg;
	    }
	    break;

	  case 'J':
	    {
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].j,
	       * va_arg (args, jlong))[::]m4_dnl
	       * :]:]) */
	      *((jlong *) (void *) &locals[i]) = m4svm_arg;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* m4svm_comment_define([:m4svm_arg_comment:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, locals,
	       * /[::]* Take into account ISO C's default argument promotion. *[::]/
	       *                 locals)[::]m4_dnl
	       * :]:]) */
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].f,
	       * va_arg (args, jdouble))[::]m4_dnl
	       * :]:]) */
	      m4svm_arg_comment[i++].jfloat = m4svm_arg;
	    }
	    break;

	  case 'D':
	    {
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].d,
	       * va_arg (args, jdouble))[::]m4_dnl
	       * :]:]) */
	      *((jdouble *) (void *) &locals[i]) = m4svm_arg;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].l,
	       * va_arg (args, jobject))[::]m4_dnl
	       * :]:]) */
	      jobject obj = m4svm_arg;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      /* m4svm_comment_define([:m4svm_arg:],
	       * [:[:m4_ifelse(
	       * $:][:2, A, args[arg++].l,
	       * va_arg (args, jobject))[::]m4_dnl
	       * :]:]) */
	      jobject obj = m4svm_arg;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
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
	goto end;
      }
    /* m4svm_comment_define([:m4svm_returnvalue:],
     * [:[:m4svm_returnvalue_1($:][:3):]m4_dnl:]) */
    /* m4svm_comment_define([:m4svm_returnvalue_1:],
     * [:m4_ifelse($1, void, ,
     * [:
     *       /[::]* set the return value *[::]/
     *       {
     *         _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
     *           (((char *) frame) + frame->end_offset);
     *
     *         m4_ifelse(
     *
     * $1, jlong,
     * [:result = *((jlong *) (void *) ptr_ret);:],
     *
     * $1, jfloat,
     * [:result = ptr_ret->jfloat;:],
     *
     * $1, jdouble,
     * [:result = *((jdouble *) (void *) ptr_ret);:],
     *
     * $1, jobject,
     * [:if (ptr_ret->reference != NULL)
     *           {
     *             _svmt_object_instance *ref = ptr_ret->reference;
     * #if defined (MAGIC)
     *             assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
     * #endif
     *             result = _svmf_get_jni_frame_native_local (env);
     *             *result = ref;
     *           }:],
     *
     * [:result = ptr_ret->jint;:])
     *       }:]):]) */
    m4svm_returnvalue = dummy;

  }

end:
  /* m4svm_comment_define([:m4svm_result_return:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ;
   * ,
   * [::]
   *   return result;
   * )m4:][:_dnl:]:]) */
  m4svm_result_return dummy;

}

m4svm_define_end v = ":])";

/* m4svm_internal_CallNonvirtualMethod(Void, A, void) */
/* m4svm_internal_CallNonvirtualMethod(Void, V, void) */

/* m4svm_internal_CallNonvirtualMethod(Object, A, jobject) */
/* m4svm_internal_CallNonvirtualMethod(Object, V, jobject) */

/* m4svm_internal_CallNonvirtualMethod(Boolean, A, jboolean) */
/* m4svm_internal_CallNonvirtualMethod(Boolean, V, jboolean) */

/* m4svm_internal_CallNonvirtualMethod(Byte, A, jbyte) */
/* m4svm_internal_CallNonvirtualMethod(Byte, V, jbyte) */

/* m4svm_internal_CallNonvirtualMethod(Short, A, jshort) */
/* m4svm_internal_CallNonvirtualMethod(Short, V, jshort) */

/* m4svm_internal_CallNonvirtualMethod(Char, A, jchar) */
/* m4svm_internal_CallNonvirtualMethod(Char, V, jchar) */

/* m4svm_internal_CallNonvirtualMethod(Int, A, jint) */
/* m4svm_internal_CallNonvirtualMethod(Int, V, jint) */

/* m4svm_internal_CallNonvirtualMethod(Long, A, jlong) */
/* m4svm_internal_CallNonvirtualMethod(Long, V, jlong) */

/* m4svm_internal_CallNonvirtualMethod(Float, A, jfloat) */
/* m4svm_internal_CallNonvirtualMethod(Float, V, jfloat) */

/* m4svm_internal_CallNonvirtualMethod(Double, A, jdouble) */
/* m4svm_internal_CallNonvirtualMethod(Double, V, jdouble) */

/* m4_undefine([:m4svm_internal_CallNonvirtualMethod:]) */

/*
----------------------------------------------------------------------
m4svm_CallNonvirtualMethod
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_CallNonvirtualMethod:])";

/*
-----------------------------------m4_dnl
-----------------------------------
CallNonvirtual$1Method$2
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:methodID, m4_dnl
 * m4_ifelse($:][:2, , ...,
 * $:][:2, A, jvalue *args,
 * $:][:2, V, va_list args)[::]m4_dnl
 * :]:]) */
JNIEXPORT svm_static $3 JNICALL
CallNonvirtual$1Method$2 (JNIEnv *_env, jobject this, jclass class,
			  jmethodID m4svm_arglist)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  /* m4svm_comment_define([:m4svm_result_decl:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * $:][:1, Object, $:][:3 result;
   * ,
   * $:][:3 result;
   * )m4_:][:dnl:]:]) */
  m4svm_result_decl dummy;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    /* m4svm_comment_define([:m4svm_arg_decl:],
     * [:[:m4_ifelse(
     * $:][:2, , va_list args;
     * 
     *     va_start (args, methodID);
     *
     *     m4_ifelse(
     * $:][:1, Void,
     * ,
     * result = )m4_dnl
     * _svmf_internal_CallNonvirtual$:][:1Method$:][:2V,
     * m4_ifelse(
     * $:][:1, Void,
     * ,
     * result = )m4_dnl
     * _svmf_internal_CallNonvirtual$:][:1Method$:][:2):]:]) */
    m4svm_arg_decl (env, this, class, methodID, args);
    /* m4svm_comment_define([:m4svm_arg_end:],
     * [:[:m4_ifelse(
     * $:][:2, ,[::]
     *     va_end (args);,)m4_:][:dnl:]:]) */
    m4svm_arg_end = dummy;

  }

  _svmm_stopping_java (env);
  /* m4svm_comment_define([:m4svm_result_return:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * [::]
   *   return result;
   * )m4:][:_dnl:]:]) */
  m4svm_result_return dummy;

}

m4svm_define_end v = ":])";

/* m4svm_CallNonvirtualMethod(Void,  , void) */
/* m4svm_CallNonvirtualMethod(Void, A, void) */
/* m4svm_CallNonvirtualMethod(Void, V, void) */

/* m4svm_CallNonvirtualMethod(Object,  , jobject) */
/* m4svm_CallNonvirtualMethod(Object, A, jobject) */
/* m4svm_CallNonvirtualMethod(Object, V, jobject) */

/* m4svm_CallNonvirtualMethod(Boolean,  , jboolean) */
/* m4svm_CallNonvirtualMethod(Boolean, A, jboolean) */
/* m4svm_CallNonvirtualMethod(Boolean, V, jboolean) */

/* m4svm_CallNonvirtualMethod(Byte,  , jbyte) */
/* m4svm_CallNonvirtualMethod(Byte, A, jbyte) */
/* m4svm_CallNonvirtualMethod(Byte, V, jbyte) */

/* m4svm_CallNonvirtualMethod(Short,  , jshort) */
/* m4svm_CallNonvirtualMethod(Short, A, jshort) */
/* m4svm_CallNonvirtualMethod(Short, V, jshort) */

/* m4svm_CallNonvirtualMethod(Char,  , jchar) */
/* m4svm_CallNonvirtualMethod(Char, A, jchar) */
/* m4svm_CallNonvirtualMethod(Char, V, jchar) */

/* m4svm_CallNonvirtualMethod(Int,  , jint) */
/* m4svm_CallNonvirtualMethod(Int, A, jint) */
/* m4svm_CallNonvirtualMethod(Int, V, jint) */

/* m4svm_CallNonvirtualMethod(Long,  , jlong) */
/* m4svm_CallNonvirtualMethod(Long, A, jlong) */
/* m4svm_CallNonvirtualMethod(Long, V, jlong) */

/* m4svm_CallNonvirtualMethod(Float,  , jfloat) */
/* m4svm_CallNonvirtualMethod(Float, A, jfloat) */
/* m4svm_CallNonvirtualMethod(Float, V, jfloat) */

/* m4svm_CallNonvirtualMethod(Double,  , jdouble) */
/* m4svm_CallNonvirtualMethod(Double, A, jdouble) */
/* m4svm_CallNonvirtualMethod(Double, V, jdouble) */

/* m4_undefine([:m4svm_CallNonvirtualMethod:]) */

/*
----------------------------------------------------------------------
m4svm_CallMethod
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_CallMethod:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Call$1Method$2
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:methodID, m4_dnl
 * m4_ifelse($:][:2, , ...,
 * $:][:2, A, jvalue *args,
 * $:][:2, V, va_list args)[::]m4_dnl
 * :]:]) */
JNIEXPORT svm_static $3 JNICALL
Call$1Method$2 (JNIEnv *_env, jobject this, jmethodID m4svm_arglist)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  /* m4svm_comment_define([:m4svm_result_decl:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * $:][:1, Object, $:][:3 result = NULL;
   * ,
   * $:][:3 result = 0;
   * )m4_:][:dnl:]:]) */
  m4svm_result_decl dummy;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
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
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      /* m4svm_comment_define([:m4svm_arg_decl:],
       * [:[:m4_ifelse(
       * $:][:2, , va_list args;
       * 
       *       va_start (args, methodID);
       * ,
       * $:][:2, A, jint arg = 0;
       * ,
       * )m4_:][:dnl:]:]) */
      m4svm_arg_decl dummy;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != '[:):]')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].z,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'B':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].b,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'S':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].s,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'C':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].c,
		 * va_arg (args, int))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'I':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].i,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		locals[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'J':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].j,
		 * va_arg (args, jlong))[::]m4_dnl
		 * :]:]) */
		*((jlong *) (void *) &locals[i]) = m4svm_arg;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].f,
		 * va_arg (args, jdouble))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jfloat = m4svm_arg;
	      }
	      break;

	    case 'D':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].d,
		 * va_arg (args, jdouble))[::]m4_dnl
		 * :]:]) */
		*((jdouble *) (void *) &locals[i]) = m4svm_arg;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].l,
		 * va_arg (args, jobject))[::]m4_dnl
		 * :]:]) */
		jobject obj = m4svm_arg;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].l,
		 * va_arg (args, jobject))[::]m4_dnl
		 * :]:]) */
		jobject obj = m4svm_arg;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      /* m4svm_comment_define([:m4svm_arg_end:],
       * [:[:m4_ifelse(
       * $:][:2, , va_end (args);
       * ,
       * )m4_:][:dnl:]:]) */
      m4svm_arg_end = dummy;

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

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      /* m4svm_comment_define([:m4svm_returnvalue:],
       * [:[:m4svm_returnvalue_1($:][:3):]m4_dnl:]) */
      /* m4svm_comment_define([:m4svm_returnvalue_1:],
       * [:m4_ifelse($1, void, ,
       * [:
       *       /[::]* set the return value *[::]/
       *       {
       *         _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
       *           (((char *) frame) + frame->end_offset);
       *
       *         m4_ifelse(
       *
       * $1, jlong,
       * [:result = *((jlong *) (void *) ptr_ret);:],
       *
       * $1, jfloat,
       * [:result = ptr_ret->jfloat;:],
       *
       * $1, jdouble,
       * [:result = *((jdouble *) (void *) ptr_ret);:],
       *
       * $1, jobject,
       * [:if (ptr_ret->reference != NULL)
       *           {
       *             _svmt_object_instance *ref = ptr_ret->reference;
       * #if defined (MAGIC)
       *             assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
       * #endif
       *             result = _svmf_get_jni_frame_native_local (env);
       *             *result = ref;
       *           }:],
       *
       * [:result = ptr_ret->jint;:])
       *       }:]):]) */
      m4svm_returnvalue = dummy;

    }
  }

end:
  _svmm_stopping_java (env);
  /* m4svm_comment_define([:m4svm_result_return:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * [::]
   *   return result;
   * )m4:][:_dnl:]:]) */
  m4svm_result_return dummy;

}

m4svm_define_end v = ":])";

/* m4svm_CallMethod(Void,  , void) */
/* m4svm_CallMethod(Void, A, void) */
/* m4svm_CallMethod(Void, V, void) */

/* m4svm_CallMethod(Object,  , jobject) */
/* m4svm_CallMethod(Object, A, jobject) */
/* m4svm_CallMethod(Object, V, jobject) */

/* m4svm_CallMethod(Boolean,  , jboolean) */
/* m4svm_CallMethod(Boolean, A, jboolean) */
/* m4svm_CallMethod(Boolean, V, jboolean) */

/* m4svm_CallMethod(Byte,  , jbyte) */
/* m4svm_CallMethod(Byte, A, jbyte) */
/* m4svm_CallMethod(Byte, V, jbyte) */

/* m4svm_CallMethod(Short,  , jshort) */
/* m4svm_CallMethod(Short, A, jshort) */
/* m4svm_CallMethod(Short, V, jshort) */

/* m4svm_CallMethod(Char,  , jchar) */
/* m4svm_CallMethod(Char, A, jchar) */
/* m4svm_CallMethod(Char, V, jchar) */

/* m4svm_CallMethod(Int,  , jint) */
/* m4svm_CallMethod(Int, A, jint) */
/* m4svm_CallMethod(Int, V, jint) */

/* m4svm_CallMethod(Long,  , jlong) */
/* m4svm_CallMethod(Long, A, jlong) */
/* m4svm_CallMethod(Long, V, jlong) */

/* m4svm_CallMethod(Float,  , jfloat) */
/* m4svm_CallMethod(Float, A, jfloat) */
/* m4svm_CallMethod(Float, V, jfloat) */

/* m4svm_CallMethod(Double,  , jdouble) */
/* m4svm_CallMethod(Double, A, jdouble) */
/* m4svm_CallMethod(Double, V, jdouble) */

/* m4_undefine([:m4svm_CallMethod:]) */

/*
----------------------------------------------------------------------
m4svm_CallStaticMethod
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_CallStaticMethod:])";

/*
-----------------------------------m4_dnl
-----------------------------------
CallStatic$1Method$2
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:methodID, m4_dnl
 * m4_ifelse($:][:2, , ...,
 * $:][:2, A, jvalue *args,
 * $:][:2, V, va_list args)[::]m4_dnl
 * :]:]) */
JNIEXPORT svm_static $3 JNICALL
CallStatic$1Method$2 (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID m4svm_arglist)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  /* m4svm_comment_define([:m4svm_result_decl:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * $:][:1, Object, $:][:3 result = NULL;
   * ,
   * $:][:3 result = 0;
   * )m4_:][:dnl:]:]) */
  m4svm_result_decl dummy;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
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
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      /* m4svm_comment_define([:m4svm_arg_decl:],
       * [:[:m4_ifelse(
       * $:][:2, , va_list args;
       * 
       *       va_start (args, methodID);
       * ,
       * $:][:2, A, jint arg = 0;
       * ,
       * )m4_:][:dnl:]:]) */
      m4svm_arg_decl dummy;

      while ((c = descriptor[++current]) != '[:):]')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].z,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'B':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].b,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'S':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].s,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'C':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].c,
		 * va_arg (args, int))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'I':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].i,
		 * va_arg (args, jint))[::]m4_dnl
		 * :]:]) */
		locals[i++].jint = m4svm_arg;
	      }
	      break;

	    case 'J':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].j,
		 * va_arg (args, jlong))[::]m4_dnl
		 * :]:]) */
		*((jlong *) (void *) &locals[i]) = m4svm_arg;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* m4svm_comment_define([:m4svm_arg_comment:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, locals,
		 * /[::]* Take into account ISO C's default argument promotion. *[::]/
		 *                 locals)[::]m4_dnl
		 * :]:]) */
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].f,
		 * va_arg (args, jdouble))[::]m4_dnl
		 * :]:]) */
		m4svm_arg_comment[i++].jfloat = m4svm_arg;
	      }
	      break;

	    case 'D':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].d,
		 * va_arg (args, jdouble))[::]m4_dnl
		 * :]:]) */
		*((jdouble *) (void *) &locals[i]) = m4svm_arg;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].l,
		 * va_arg (args, jobject))[::]m4_dnl
		 * :]:]) */
		jobject obj = m4svm_arg;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		/* m4svm_comment_define([:m4svm_arg:],
		 * [:[:m4_ifelse(
		 * $:][:2, A, args[arg++].l,
		 * va_arg (args, jobject))[::]m4_dnl
		 * :]:]) */
		jobject obj = m4svm_arg;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      /* m4svm_comment_define([:m4svm_arg_end:],
       * [:[:m4_ifelse(
       * $:][:2, , va_end (args);
       * ,
       * )m4_:][:dnl:]:]) */
      m4svm_arg_end = dummy;

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

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      /* m4svm_comment_define([:m4svm_returnvalue:],
       * [:[:m4svm_returnvalue_1($:][:3):]m4_dnl:]) */
      /* m4svm_comment_define([:m4svm_returnvalue_1:],
       * [:m4_ifelse($1, void, ,
       * [:
       *       /[::]* set the return value *[::]/
       *       {
       *         _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
       *           (((char *) frame) + frame->end_offset);
       *
       *         m4_ifelse(
       *
       * $1, jlong,
       * [:result = *((jlong *) (void *) ptr_ret);:],
       *
       * $1, jfloat,
       * [:result = ptr_ret->jfloat;:],
       *
       * $1, jdouble,
       * [:result = *((jdouble *) (void *) ptr_ret);:],
       *
       * $1, jobject,
       * [:if (ptr_ret->reference != NULL)
       *           {
       *             _svmt_object_instance *ref = ptr_ret->reference;
       * #if defined (MAGIC)
       *             assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
       * #endif
       *             result = _svmf_get_jni_frame_native_local (env);
       *             *result = ref;
       *           }:],
       *
       * [:result = ptr_ret->jint;:])
       *       }:]):]) */
      m4svm_returnvalue = dummy;

    }
  }

end:
  _svmm_stopping_java (env);
  /* m4svm_comment_define([:m4svm_result_return:],
   * [:[:m4_ifelse(
   * $:][:1, Void, ,
   * [::]
   *   return result;
   * )m4:][:_dnl:]:]) */
  m4svm_result_return dummy;

}

m4svm_define_end v = ":])";

/* m4svm_CallStaticMethod(Void,  , void) */
/* m4svm_CallStaticMethod(Void, A, void) */
/* m4svm_CallStaticMethod(Void, V, void) */

/* m4svm_CallStaticMethod(Object,  , jobject) */
/* m4svm_CallStaticMethod(Object, A, jobject) */
/* m4svm_CallStaticMethod(Object, V, jobject) */

/* m4svm_CallStaticMethod(Boolean,  , jboolean) */
/* m4svm_CallStaticMethod(Boolean, A, jboolean) */
/* m4svm_CallStaticMethod(Boolean, V, jboolean) */

/* m4svm_CallStaticMethod(Byte,  , jbyte) */
/* m4svm_CallStaticMethod(Byte, A, jbyte) */
/* m4svm_CallStaticMethod(Byte, V, jbyte) */

/* m4svm_CallStaticMethod(Short,  , jshort) */
/* m4svm_CallStaticMethod(Short, A, jshort) */
/* m4svm_CallStaticMethod(Short, V, jshort) */

/* m4svm_CallStaticMethod(Char,  , jchar) */
/* m4svm_CallStaticMethod(Char, A, jchar) */
/* m4svm_CallStaticMethod(Char, V, jchar) */

/* m4svm_CallStaticMethod(Int,  , jint) */
/* m4svm_CallStaticMethod(Int, A, jint) */
/* m4svm_CallStaticMethod(Int, V, jint) */

/* m4svm_CallStaticMethod(Long,  , jlong) */
/* m4svm_CallStaticMethod(Long, A, jlong) */
/* m4svm_CallStaticMethod(Long, V, jlong) */

/* m4svm_CallStaticMethod(Float,  , jfloat) */
/* m4svm_CallStaticMethod(Float, A, jfloat) */
/* m4svm_CallStaticMethod(Float, V, jfloat) */

/* m4svm_CallStaticMethod(Double,  , jdouble) */
/* m4svm_CallStaticMethod(Double, A, jdouble) */
/* m4svm_CallStaticMethod(Double, V, jdouble) */

/* m4_undefine([:m4svm_CallStaticMethod:]) */

/*
----------------------------------------------------------------------
m4svm_GetArrayRegion
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_GetArrayRegion:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Get$1ArrayRegion
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static void JNICALL
Get$1ArrayRegion (JNIEnv *_env, $2Array array, jsize start, jsize len,
		  $2 * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    $2 *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      ($2 *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof ($2));
  }

end:
  _svmm_stopping_java (env);
}

m4svm_define_end v = ":])";

/* m4svm_GetArrayRegion(Byte, jbyte) */
/* m4svm_GetArrayRegion(Short, jshort) */
/* m4svm_GetArrayRegion(Char, jchar) */
/* m4svm_GetArrayRegion(Int, jint) */
/* m4svm_GetArrayRegion(Long, jlong) */
/* m4svm_GetArrayRegion(Float, jfloat) */
/* m4svm_GetArrayRegion(Double, jdouble) */

/* m4_undefine([:m4svm_GetArrayRegion:]) */

/*
----------------------------------------------------------------------
m4svm_SetArrayRegion
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_SetArrayRegion:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Set$1ArrayRegion
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static void JNICALL
Set$1ArrayRegion (JNIEnv *_env, $2Array array, jsize start, jsize len,
		  $2 * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    $2 *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      ($2 *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof ($2));
  }

end:
  _svmm_stopping_java (env);
}

m4svm_define_end v = ":])";

/* m4svm_SetArrayRegion(Byte, jbyte) */
/* m4svm_SetArrayRegion(Short, jshort) */
/* m4svm_SetArrayRegion(Char, jchar) */
/* m4svm_SetArrayRegion(Int, jint) */
/* m4svm_SetArrayRegion(Long, jlong) */
/* m4svm_SetArrayRegion(Float, jfloat) */
/* m4svm_SetArrayRegion(Double, jdouble) */

/* m4_undefine([:m4svm_SetArrayRegion:]) */

/*
----------------------------------------------------------------------
m4svm_GetArrayElements
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_GetArrayElements:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Get$1ArrayElements
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static $2 * JNICALL
Get$1ArrayElements (JNIEnv *_env, $2Array array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  $2 *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = ($2 *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof ($2));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof ($2));
  }

end:
  _svmm_stopping_java (env);

  return result;
}

m4svm_define_end v = ":])";

/* m4svm_GetArrayElements(Byte, jbyte) */
/* m4svm_GetArrayElements(Short, jshort) */
/* m4svm_GetArrayElements(Char, jchar) */
/* m4svm_GetArrayElements(Int, jint) */
/* m4svm_GetArrayElements(Long, jlong) */
/* m4svm_GetArrayElements(Float, jfloat) */
/* m4svm_GetArrayElements(Double, jdouble) */

/* m4_undefine([:m4svm_GetArrayElements:]) */

/*
----------------------------------------------------------------------
m4svm_ReleaseArrayElements
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_ReleaseArrayElements:])";

/*
-----------------------------------m4_dnl
-----------------------------------
Release$1ArrayElements
-----------------------------------m4_dnl
-----------------------------------
*/

JNIEXPORT svm_static void JNICALL
Release$1ArrayElements (JNIEnv *_env, $2Array array, $2 * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof ($2));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof ($2));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in Release$1ArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}

m4svm_define_end v = ":])";

/* m4svm_ReleaseArrayElements(Byte, jbyte) */
/* m4svm_ReleaseArrayElements(Short, jshort) */
/* m4svm_ReleaseArrayElements(Char, jchar) */
/* m4svm_ReleaseArrayElements(Int, jint) */
/* m4svm_ReleaseArrayElements(Long, jlong) */
/* m4svm_ReleaseArrayElements(Float, jfloat) */
/* m4svm_ReleaseArrayElements(Double, jdouble) */

/* m4_undefine([:m4svm_ReleaseArrayElements:]) */

/* m4svm_on(0)m4_dnl */

/*
----------------------------------------------------------------------
GetObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetObjectField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;
    _svmt_object_instance *instance;

    instance = _svmf_get_REFERENCE_field (*obj, offset);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
SetObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetObjectField (JNIEnv *_env, jobject obj, jfieldID fieldID, jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_REFERENCE_field (env, *obj, offset,
			       (value == NULL) ? NULL : *value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStaticObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetStaticObjectField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance;

    instance = *(field->data.class_field.value.l);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
SetStaticObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticObjectField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		      jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *(field->data.class_field.value.l) = (value == NULL) ? NULL : *value;

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetFieldID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
GetFieldID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	field =
	  _svmf_resolve_field (vm->class_loading.boot_loader.classes.
			       jlobject, name, sig);
      }
    else
      {
	field = _svmf_resolve_field (_svmf_cast_class (type), name, sig);
      }

    if (field == NULL
	|| _svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field = NULL;
	_svmf_error_NoSuchFieldError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
GetStaticFieldID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
GetStaticFieldID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	field =
	  _svmf_resolve_field (vm->class_loading.boot_loader.classes.
			       jlobject, name, sig);
      }
    else
      {
	field = _svmf_resolve_field (_svmf_cast_class (type), name, sig);
      }

    if (field == NULL
	|| !_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field = NULL;
	_svmf_error_NoSuchFieldError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
DeleteLocalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteLocalRef (JNIEnv *_env, jobject localRef)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (localRef != NULL)
    {
      _svmt_stack_frame *frame = env->stack.current_frame;
      _svmt_stack_native_reference *lrefs =
	(_svmt_stack_native_reference *) (void *) (((char *) frame) +
						   frame->end_offset);
      jint lrefs_count = lrefs[-1].jint;
      size_t lrefs_size = lrefs[-2].size_t;
      jint i;

      lrefs =
	(_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						   lrefs_size);

      for (i = 0; i < lrefs_count; i++)
	{
	  if (lrefs[i].jobject == localRef)
	    {
	      *(lrefs[i].jobject) = NULL;
	      break;
	    }
	}
    }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetObjectClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
GetObjectClass (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    class = _svmf_get_jni_frame_native_local (env);
    *class = *((*obj)->vtable->type->class_instance);
  }

  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
ThrowNew
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
ThrowNew (JNIEnv *_env, jclass cls, const char *message)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    _svmt_method_info *method;
    jobject throwable;
    jstring msg;

    if (_svmf_link_class (env, class) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_class_initialization (env, class) != JNI_OK)
      {
	goto end;
      }

    throwable = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *throwable) != JNI_OK)
      {
	goto end;
      }

    msg = _svmf_get_jni_frame_native_local (env);
    if (_svmf_get_string (env, message, msg) != JNI_OK)
      {
	goto end;
      }

    method = _svmf_resolve_method (class, "<init>", "(Ljava/lang/String;)V");

    if (method == NULL)
      {
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }

    if (_svmm_invoke_specific_nonvirtual_throwinit
	(env, method, throwable, msg) != JNI_OK)
      {
	goto end;
      }

    *(env->throwable) = *throwable;

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewGlobalRef (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (obj == NULL || *obj == NULL)
    {
      goto end;
    }

  if (_svmm_new_native_global (env, result) != JNI_OK)
    {
      *(env->throwable) = NULL;
      goto end;
    }

  *result = *obj;

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringUTFLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetStringUTFLength (JNIEnv *_env, jstring string)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;		/* init just to keep compiler happy */

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_invoke_static_stringcreator_getutflength (env, string, result);

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringUTFChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const char *JNICALL
GetStringUTFChars (JNIEnv *_env, jstring string, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  char *result = NULL;;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    char *chars;

    if (_svmm_galloc_utf_chars (env, string, chars) != JNI_OK)
      {
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    result = chars;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
ReleaseStringUTFChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringUTFChars (JNIEnv *_env, jstring string SVM_UNUSED,
		       const char *utf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    char *chars = (char *) utf;;

    _svmm_gfree_utf_chars (chars);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
ExceptionCheck
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
ExceptionCheck (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = *(env->throwable) != NULL;

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
SetObjectArrayElement
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetObjectArrayElement (JNIEnv *_env, jobjectArray array, jsize indx,
		       jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    /* check array bounds */
    if (((_svmt_u32) indx) >= (_svmt_u32) size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    if (_svmf_set_reference_array_element_no_exception
	(env, *array, indx, (value == NULL) ? NULL : *value) != JNI_OK)
      {
	_svmf_error_ArrayStoreException (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
NewStringUTF
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jstring JNICALL
NewStringUTF (JNIEnv *_env, const char *bytes)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (*(env->throwable) == NULL);

  {
    string = _svmf_get_jni_frame_native_local (env);
    if (_svmf_get_string (env, bytes, string) != JNI_OK)
      {
	string = NULL;
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
NewObjectArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jarray JNICALL
NewObjectArray (JNIEnv *_env, jsize length, jclass elementClass,
		jobject initialElement)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, elementClass);
    _svmt_array_info *array_type;

    if (_svmm_create_array
	(env, type->class_loader_info, type->array_type_name,
	 array_type) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_link_array (env, array_type) != JNI_OK)
      {
	goto end;
      }

    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance (env, array_type, length, *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

    if (initialElement != NULL)
      {
	_svmt_object_instance *value = *initialElement;
	_svmt_object_instance **elements;
	jint i;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	elements = (_svmt_object_instance **) *array;

#else

	elements = (_svmt_object_instance **) (void *)
	  (((char *) *array) +
	   _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

#endif

	for (i = 0; i < length; i++)
	  {
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	    elements[(-1) - i] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	    _svmf_write_barrier
	      (env, (_svmt_object_instance **) (void *) &elements[(-1) - i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
#else

	    elements[i] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	    _svmf_write_barrier
	      (env, (_svmt_object_instance **) &elements[i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
#endif
	  }
      }
  }

end:
  _svmm_stopping_java (env);

  return array;
}

/*
----------------------------------------------------------------------
GetMethodID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
GetMethodID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_method_info *method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	method =
	  _svmf_resolve_method (vm->class_loading.boot_loader.classes.
				jlobject, name, sig);
      }
    else
      {
	method = _svmf_resolve_method (_svmf_cast_class (type), name, sig);
      }

    if (method == NULL
	|| _svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
      {
	method = NULL;
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
GetStaticMethodID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
GetStaticMethodID (JNIEnv *_env, jclass cls, const char *name,
		   const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_method_info *method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	method =
	  _svmf_resolve_method (vm->class_loading.boot_loader.classes.
				jlobject, name, sig);
      }
    else
      {
	method = _svmf_resolve_method (_svmf_cast_class (type), name, sig);
      }

    if (method == NULL
	|| !_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
      {
	method = NULL;
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
ExceptionDescribe
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ExceptionDescribe (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jthrowable throwable = _svmf_get_jni_frame_native_local (env);
    jstring jtext = _svmf_get_jni_frame_native_local (env);
    char *ctext = NULL;


    *throwable = *(env->throwable);
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiondescribe (env, throwable)
	== JNI_OK)
      {
	goto done;
      }

    /* There was an exception thrown while trying to print the stack
       trace using Java code. So, we now try to convert the whole
       exception & stack trace to a string, then print it here */

    /* forget the new exception */
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiondescription
	(env, throwable, jtext) != JNI_OK)
      {
	goto try_again;
      }

    if (_svmm_galloc_utf_chars (env, jtext, ctext) != JNI_OK)
      {
	goto try_again;
      }

    _svmf_printf (env, stderr, "%s\n", ctext);

    _svmm_gfree_utf_chars (ctext);

    goto done;

  try_again:
    /* There was yet again an exception trying to retrieve a full
       stack trace.  So, we try to at least provide the exception
       toString() info. */

    /* forget the new exception */
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiontruncateddescription
	(env, throwable, jtext) != JNI_OK)
      {
	goto try_one_last_time;
      }

    if (_svmm_galloc_utf_chars (env, jtext, ctext) != JNI_OK)
      {
	goto try_one_last_time;
      }

    _svmf_printf (env, stderr, "%s\n", ctext);

    _svmm_gfree_utf_chars (ctext);

    goto done;

  try_one_last_time:
    /* We were unable to get any info from Java. Print some minimal
       info. */

    /* forget the new exception */
    *(env->throwable) = NULL;

    /* print the old exception class name */
    _svmf_printf (env, stderr, "%s\n", (*throwable)->vtable->type->name);

  done:
    _svmm_release_jni_frame_native_local (throwable);
    _svmm_release_jni_frame_native_local (jtext);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
ExceptionOccurred
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jthrowable JNICALL
ExceptionOccurred (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jthrowable throwable = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (*(env->throwable) != NULL)
    {
      throwable = _svmf_get_jni_frame_native_local (env);
      *throwable = *(env->throwable);
    }

  _svmm_stopping_java (env);

  return throwable;
}

/*
----------------------------------------------------------------------
ExceptionClear
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ExceptionClear (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *(env->throwable) = NULL;

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetVersion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetVersion (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_stopping_java (env);

  return JNI_VERSION_1_4;
}

/*
----------------------------------------------------------------------
FindClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
FindClass (JNIEnv *_env, const char *name)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_class_loader_info *class_loader_info;


    /* get class loader */
    if (frame->method == &vm->stack_bottom_method)
      {
	jarray vmdata = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_invoke_static_virtualmachine_getsystemcl
	    (env, _svmf_cast_jobject (vmdata)) != JNI_OK)
	  {
	    goto end;
	  }
	class_loader_info = _svmf_unwrap_pointer (*vmdata);
	_svmm_release_jni_frame_native_local_array (vmdata);
      }
    else
      {
	class_loader_info = frame->method->class_info->class_loader_info;
      }

    /* load, link, and initialize type */
    {
      _svmt_type_info *type;

      if (_svmm_create_type (env, class_loader_info, name, type) != JNI_OK)
	{
	  goto end;
	}

      if (_svmf_link_type (env, type) != JNI_OK)
	{
	  goto end;
	}

      if (!(type->is_array))
	{
	  if (_svmf_class_initialization
	      (env, _svmf_cast_class (type)) != JNI_OK)
	    {
	      goto end;
	    }
	}

      class = _svmf_get_jni_frame_native_local (env);
      *class = *(type->class_instance);
    }
  }

end:
  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
GetArrayLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetArrayLength (JNIEnv *_env, jarray array)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint size;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  size = (*array)->size;

  _svmm_stopping_java (env);

  return size;
}

/*
----------------------------------------------------------------------
DefineClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
DefineClass (JNIEnv *_env, const char *name SVM_UNUSED,
	     jobject loader SVM_UNUSED, const jbyte *buf SVM_UNUSED,
	     jsize bufLen SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
GetSuperclass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
GetSuperclass (JNIEnv *_env, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass super = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  /*
   * Note:
   * implementation very similar to Java_java_lang_VMClass_getSuperclass
   */
  {
    _svmt_JavaVM *vm = env->vm;
    /* Note: Will not work for Class of primitive types */
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (type->is_array)
      {
	super = _svmf_get_jni_frame_native_local (env);
	*super =
	  *(vm->class_loading.boot_loader.classes.jlobject->class_instance);
	goto end;
      }
    if (_svmf_is_set_flag (type->access_flags, SVM_ACC_INTERFACE))
      {
	goto end;
      }

    /* has super type */
    super = _svmf_get_jni_frame_native_local (env);
    {
      _svmt_CONSTANT_Class_info *super_class;
      super_class = *(_svmf_cast_class (type)->super_class);
      if (super_class == NULL)
	{
	  super = NULL;
	  goto end;
	}
      else
	{
	  *super = *(super_class->type->class_instance);
	}
    }

  }
end:
  _svmm_stopping_java (env);

  return super;
}

/*
----------------------------------------------------------------------
IsAssignableFrom
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsAssignableFrom (JNIEnv *_env, jclass cls1, jclass cls2)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean is_assignable;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    /* Note: Will not work for Class of primitive types */
    _svmt_type_info *from = _svmf_unwrap_class_instance (env, cls1);
    _svmt_type_info *to = _svmf_unwrap_class_instance (env, cls2);

    is_assignable = _svmf_is_assignable_from (env, from, to);
  }

  _svmm_stopping_java (env);

  return is_assignable;
}

/*
----------------------------------------------------------------------
Throw
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
Throw (JNIEnv *_env, jthrowable obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    *(env->throwable) = *obj;
  }

  _svmm_stopping_java (env);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
FatalError
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
FatalError (JNIEnv *_env, const char *msg)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmm_fatal_error (msg);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
DeleteGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteGlobalRef (JNIEnv *_env, jobject globalRef)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmm_free_native_global (env, globalRef);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
IsSameObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsSameObject (JNIEnv *_env, jobject ref1, jobject ref2)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = JNI_FALSE;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (ref1 == NULL)
      {
	if (ref2 == NULL)
	  {
	    result = JNI_TRUE;
	  }
	else
	  {
	    result = JNI_FALSE;
	  }
      }
    else
      {
	result = (*ref1 == *ref2) ? JNI_TRUE : JNI_FALSE;
      }
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
AllocObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
AllocObject (JNIEnv *_env, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObject (JNIEnv *_env, jclass cls, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    {
      va_list args;

      va_start (args, methodID);

      _svmf_internal_CallNonvirtualVoidMethodV (env, instance, cls, methodID,
						args);

      va_end (args);
    }

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObjectV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObjectV (JNIEnv *_env, jclass cls, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    _svmf_internal_CallNonvirtualVoidMethodV (env, instance, cls, methodID,
					      args);

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObjectA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObjectA (JNIEnv *_env, jclass cls, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    _svmf_internal_CallNonvirtualVoidMethodA (env, instance, cls, methodID,
					      args);

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
IsInstanceOf
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsInstanceOf (JNIEnv *_env, jobject obj, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	result = JNI_TRUE;
      }
    else
      {
	/* Note: Will not work for Class of primitive types */
	_svmt_type_info *T = _svmf_unwrap_class_instance (env, cls);
	_svmt_type_info *S = (*obj)->vtable->type;

	result = _svmf_is_assignable_from (env, S, T);
      }
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewString
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jstring JNICALL
NewString (JNIEnv *_env, const jchar *unicodeChars, jsize len)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jstring string = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jcharArray data = NULL;

    if (_svmm_new_native_local_array (env, data) != JNI_OK)
      {
	goto end;
      }

    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.char_array, len,
	 *data) != JNI_OK)
      {
	_svmm_free_native_local_array (env, data);
	goto end;
      }

    /* put the string characters into the array */
    if (len > 0)
      {
	memcpy (((char *) *data) +
		_svmf_aligned_size_t (sizeof (_svmt_array_instance)),
		unicodeChars, len * sizeof (jchar));
      }

    string = _svmf_get_jni_frame_native_local (env);

    if (_svmm_invoke_static_stringcreator_createstringfromchars
	(env, _svmf_cast_jobject (data), string) == JNI_ERR)
      {
	_svmm_free_native_local_array (env, data);
	_svmm_release_jni_frame_native_local (string);
	goto end;
      }

    _svmm_free_native_local_array (env, data);
  }

end:
  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
GetStringLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetStringLength (JNIEnv *_env, jstring string)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = -1;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_invoke_static_stringcreator_getlength (env, string, result) !=
      JNI_OK)
    {
      goto end;
    }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const jchar *JNICALL
GetStringChars (JNIEnv *_env, jstring string, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jcharArray chars;
  jchar *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_new_native_local_array (env, chars) != JNI_OK)
    {
      goto end;
    }

  if (_svmm_invoke_static_stringcreator_getchars
      (env, string, _svmf_cast_jobject (chars)) != JNI_OK)
    {
      _svmm_free_native_local_array (env, chars);
      goto end;
    }

  {
    jchar *elements = (jchar *) (void *)
      (((char *) *chars) +
       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
    jint size = (*chars)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	result = elements;

	_svmm_free_native_local_array (env, chars);
	goto end;
      }

    if (_svmm_gmalloc_chars (env, size, result) != JNI_OK)
      {
	_svmm_free_native_local_array (env, chars);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result, elements, size * sizeof (jchar));
    _svmm_free_native_local_array (env, chars);

  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
ReleaseStringChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringChars (JNIEnv *_env, jstring string, const jchar *_chars)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size;

    if (_svmm_invoke_static_stringcreator_getlength (env, string, size) !=
	JNI_OK)
      {
	goto end;
      }

    if (size != 0)
      {
	jchar *chars = (jchar *) _chars;	/* to eliminate compile error */
	_svmm_gmfree_chars (chars);
	_chars = NULL;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetObjectArrayElement
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetObjectArrayElement (JNIEnv *_env, jobjectArray array, jsize indx)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint size;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance;

    if (array == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    size = (*array)->size;

    if (((_svmt_u32) indx) >= (_svmt_u32) size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    instance = _svmf_get_reference_array_element (*array, indx);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
GetBooleanArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean *JNICALL
GetBooleanArrayElements (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
			 jboolean *isCopy SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
ReleaseBooleanArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseBooleanArrayElements (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
			     jboolean *elems SVM_UNUSED, jint mode SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetBooleanArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetBooleanArrayRegion (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
		       jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		       jboolean *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
SetBooleanArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetBooleanArrayRegion (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
		       jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		       jboolean *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
RegisterNatives
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
RegisterNatives (JNIEnv *_env, jclass cls SVM_UNUSED,
		 const JNINativeMethod *methods SVM_UNUSED,
		 jint nMethods SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
UnregisterNatives
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
UnregisterNatives (JNIEnv *_env, jclass cls SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
MonitorEnter
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
MonitorEnter (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_enter_object_monitor (env, *obj) != JNI_OK)
      {
	goto end;
      }

    /* structured locking */
    env->stack.current_frame->lock_count++;

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
MonitorExit
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
MonitorExit (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    /* structured locking */
    if (--(env->stack.current_frame->lock_count) < 0
	&& env->vm->enforce_structured_locking)
      {
	_svmf_error_IllegalMonitorStateException (env);
	goto end;
      }

    if (_svmf_exit_object_monitor (env, *obj) != JNI_OK)
      {
	goto end;
      }

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetJavaVM
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetJavaVM (JNIEnv *_env, JavaVM **vm)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *vm = _svmf_cast_JavaVM (env->vm);

  _svmm_stopping_java (env);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
EnsureLocalCapacity
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
EnsureLocalCapacity (JNIEnv *_env, jint capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = _svmf_ensure_native_local_capacity (env, capacity);

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
PushLocalFrame
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
PushLocalFrame (JNIEnv *_env, jint capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_stack_native_reference *lrefs;

  jint lrefs_count = _svmf_max_jint (capacity, SVM_FRAME_NATIVE_REFS_MIN);
  size_t lrefs_size = _svmf_aligned_size_t
    ((lrefs_count + 2) * sizeof (_svmt_stack_native_reference));
  jint i;
  jint result = JNI_OK;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmf_ensure_stack_capacity (env, lrefs_size) != JNI_OK)
    {
      result = JNI_ERR;
      goto end;
    }

  frame = env->stack.current_frame;

  frame->end_offset += lrefs_size;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame->end_offset);
  lrefs[-1].jint = lrefs_count;
  lrefs[-2].size_t = lrefs_size;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

  /* just in case we've ran out of memory during refs creation */
  memset (lrefs, 0, lrefs_count * sizeof (_svmt_stack_native_reference));

  for (i = 0; i < lrefs_count; i++)
    {
      if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	{
	  result = JNI_ERR;
	  goto end;
	}
    }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
PopLocalFrame
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
PopLocalFrame (JNIEnv *_env, jobject ref)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_stack_native_reference *lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame->end_offset);

  jint lrefs_count = lrefs[-1].jint;
  size_t lrefs_size = lrefs[-2].size_t;

  jint i;
  jobject result = NULL;
  _svmt_object_instance *saved_ref = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  /* temporarily remember the direct address of the result object, if there
     is one, just in case ref is a local ref in the top localref frame 
     (so ref will be freed below). */
  if (ref != NULL)
    {
      /* VERY IMPORTANT: As saved_ref is a direct pointer, we must make sure
         that we do not call any function that could potentially disturb the
         heap and cause GC. */
      saved_ref = *ref;
    }

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

#ifndef NDEBUG
  /* Don't allow to pop the initial native frame. 
   * Normally we don't check this as the JNI code is expected to be well-behaved, 
   * according to the specs. */

  if (!(lrefs > ((_svmt_stack_native_reference *) (void *)
		 (((char *) frame) + _svmv_stack_offset))))
    {
      _svmm_fatal_error ("Trying to pop the initial local native frame.\n"
			 "** This is a bug in the application you are trying to run.\n"
			 "** It is not allowed to call PopLocalFrame() more times than\n"
			 "** PushLocalFrame() has been called.\n");
    }

#endif

  frame->end_offset -= lrefs_size;

  for (i = 0; i < lrefs_count; i++)
    {
      if (lrefs[i].jobject !=NULL)
	{
	  /* Does not affect the heap nor cause GC.  See above
	     comment. */
	  _svmm_free_native_local (env, lrefs[i].jobject);
	}
    }

  if (ref != NULL)
    {
      /* Does not affect the heap nor cause GC (unless FatalError is
         called).  See above comment. */
      result = _svmf_get_jni_frame_native_local (env);
      *result = saved_ref;
    }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewLocalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewLocalRef (JNIEnv *_env, jobject ref SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
NewWeakGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jweak JNICALL
NewWeakGlobalRef (JNIEnv *_env, jobject obj SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
DeleteWeakGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteWeakGlobalRef (JNIEnv *_env, jweak obj SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetPrimitiveArrayCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void *JNICALL
GetPrimitiveArrayCritical (JNIEnv *_env, jarray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  void *result = NULL;

  assert (env == _svmf_get_current_env ());

  /* we only resume java if we are entering the critical section */
  if (env->critical_section_count == 0)
    {
      _svmm_resuming_java (env);
    }

  /* it must be an non-null ref to an array */
  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;
    _svmt_array_info *type = _svmf_cast_array ((*array)->vtable->type);

    assert (type->dimensions == 1);
    assert (type->base_type != SVM_TYPE_VOID);
    assert (type->base_type != SVM_TYPE_REFERENCE);

    /* if array has length 0, return some pointer != NULL */
    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* As the length is 0, we might as well return a direct
	   pointer to the elements.  This way, we'll be sure the
	   pointer is not NULL. */
	result = (void *) (((char *) *array) +
			   _svmf_aligned_size_t (sizeof
						 (_svmt_array_instance)));

	/* we must record the number of times JNI code reenters this
	   critical section. */
	env->critical_section_count++;
      }
    else if (type->base_type != SVM_TYPE_BOOLEAN)
      {
	/* if the array is not a boolean array, simply return a direct
	   pointer to the elements */

	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	result = (void *) (((char *) *array) +
			   _svmf_aligned_size_t (sizeof
						 (_svmt_array_instance)));

	/* we must record the number of times JNI code reenters this
	   critical section. */
	env->critical_section_count++;
      }
    else
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_TRUE;
	  }

	_svmm_fatal_error ("todo");
      }
  }

  /* in a critical section, we do not call _svmm_stopping_java (env); */

  return result;
}

/*
----------------------------------------------------------------------
ReleasePrimitiveArrayCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleasePrimitiveArrayCritical (JNIEnv *_env, jarray array,
			       void *carray SVM_UNUSED, jint mode SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  /* in a critical section, we do not call _svmm_resuming_java (env); */

  /* it must be an non-null ref to an array */
  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;
    _svmt_array_info *type = _svmf_cast_array ((*array)->vtable->type);

    assert (type->base_type != SVM_TYPE_VOID);
    assert (type->base_type != SVM_TYPE_REFERENCE);

    /* if array has length 0, we have nothing to do */
    if (size == 0)
      {
      }
    else if (type->base_type != SVM_TYPE_BOOLEAN)
      {
	/* if the array is not a boolean array, we have nothing to
	   do */
      }
    else
      {
	_svmm_fatal_error ("todo");
      }
  }

  env->critical_section_count--;

  if (env->critical_section_count == 0)
    {
      /* stepping out of a critical section */
      _svmm_stopping_java (env);
    }
}

/*
----------------------------------------------------------------------
GetStringRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetStringRegion (JNIEnv *_env, jstring str SVM_UNUSED, jsize start SVM_UNUSED,
		 jsize len SVM_UNUSED, jchar *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStringUTFRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetStringUTFRegion (JNIEnv *_env, jstring str SVM_UNUSED,
		    jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		    char *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStringCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const jchar *JNICALL
GetStringCritical (JNIEnv *_env, jstring string SVM_UNUSED,
		   jboolean *isCopy SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
ReleaseStringCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringCritical (JNIEnv *_env, jstring string SVM_UNUSED,
		       const jchar *carray SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
FromReflectedMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
FromReflectedMethod (JNIEnv *_env, jobject method)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  _svmt_method_info *method_id;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmf_cast_class ((*method)->vtable->type) ==
      vm->class_loading.boot_loader.classes.jlrmethod)
    {
      method_id = _svmf_unwrap_method_instance (env, method);
    }
  else
    {
      assert (_svmf_cast_class ((*method)->vtable->type) ==
	      vm->class_loading.boot_loader.classes.jlrconstructor);

      method_id = _svmf_unwrap_constructor_instance (env, method);
    }

  _svmm_stopping_java (env);

  return method_id;
}

/*
----------------------------------------------------------------------
FromReflectedField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
FromReflectedField (JNIEnv *_env, jobject field)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field_id;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field_id = _svmf_unwrap_field_instance (env, field);

  _svmm_stopping_java (env);

  return field_id;
}

/*
----------------------------------------------------------------------
ToReflectedMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
ToReflectedMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		   jmethodID methodID, jboolean isStatic SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    method = _svmf_get_jni_frame_native_local (env);

    if (methodID->reflection_instance == NULL)
      {
	/* create Method instance and cache it */

	jbyteArray wrapper;

	wrapper = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_local_wrap_pointer (env, methodID, wrapper) != JNI_OK)
	  {
	    goto end;
	  }

	if (DREF (methodID->name, value)[0] == '<')
	  {
	    /* Constructor */

	    if (_svmm_new_object_instance
		(env,
		 vm->class_loading.boot_loader.classes.jlrconstructor,
		 *method) != JNI_OK)
	      {
		goto end;
	      }

	    if (_svmm_invoke_nonvirtual_jlrconstructor_init
		(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
	      {
		goto end;
	      }

	  }
	else
	  {
	    /* Method */
	    if (_svmm_new_object_instance
		(env,
		 vm->class_loading.boot_loader.classes.jlrmethod,
		 *method) != JNI_OK)
	      {
		goto end;
	      }

	    if (_svmm_invoke_nonvirtual_jlrmethod_init
		(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
	      {
		goto end;
	      }
	  }


	if (_svmm_new_native_global
	    (env, methodID->reflection_instance) != JNI_OK)
	  {
	    goto end;
	  }

	*(methodID->reflection_instance) = *method;

      }
    else
      {
	*method = *(methodID->reflection_instance);
      }

  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
ToReflectedField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
ToReflectedField (JNIEnv *_env, jclass cls SVM_UNUSED,
		  jfieldID fieldID, jboolean isStatic SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    field = _svmf_get_jni_frame_native_local (env);

    if (fieldID->reflection_instance == NULL)
      {
	/* create Field instance and cache it */

	jbyteArray wrapper;

	wrapper = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_local_wrap_pointer (env, fieldID, wrapper) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_new_object_instance
	    (env,
	     vm->class_loading.boot_loader.classes.jlrfield,
	     *field) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_invoke_nonvirtual_jlrfield_init
	    (env, field, _svmf_cast_jobject (wrapper)) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_new_native_global
	    (env, fieldID->reflection_instance) != JNI_OK)
	  {
	    goto end;
	  }

	*(fieldID->reflection_instance) = *field;

      }
    else
      {
	*field = *(fieldID->reflection_instance);
      }

  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
NewDirectByteBuffer
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewDirectByteBuffer (JNIEnv *_env, void *address, jlong capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = _svmf_get_jni_frame_native_local (env);

#if SVM_WORD_BIT_COUNT == 32

  if (_svmm_invoke_static_niobytebuffervm_newbuffer32
      (env, (jint) address, capacity, result) != JNI_OK)
    {
      _svmm_release_jni_frame_native_local (result);
    }

#elif SVM_WORD_BIT_COUNT == 64

  if (_svmm_invoke_static_niobytebuffervm_newbuffer64
      (env, (jlong) address, capacity, result) != JNI_OK)
    {
      _svmm_release_jni_frame_native_local (result);
    }

#else

#error "todo: implement nio for non 32 or 64 bit platforms"

#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetDirectBufferAddress
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void *JNICALL
GetDirectBufferAddress (JNIEnv *_env, jobject buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  void *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

#if SVM_WORD_BIT_COUNT == 32

  {
    jint value;

    if (_svmm_invoke_static_niobytebuffervm_getaddress32 (env, buf, value) ==
	JNI_OK)
      {
	result = (void *) value;
      }
  }

#elif SVM_WORD_BIT_COUNT == 64

  {
    jlong value;

    if (_svmm_invoke_static_niobytebuffervm_getaddress64 (env, buf, value) ==
	JNI_OK)
      {
	result = (void *) value;
      }
  }

#else

#error "todo: implement nio for non 32 or 64 bit platforms"

#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetDirectBufferCapacity
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
GetDirectBufferCapacity (JNIEnv *_env, jobject buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = -1;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_invoke_static_niobytebuffervm_getcapacity (env, buf, result) !=
      JNI_OK)
    {
      result = -1;
    }

  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
_svmv_native_interface
----------------------------------------------------------------------
*/

static const JNINativeInterface _svmv_native_interface = {
  NULL,
  NULL,
  NULL,
  NULL,
  GetVersion,
  DefineClass,
  FindClass,
  FromReflectedMethod,
  FromReflectedField,
  ToReflectedMethod,
  GetSuperclass,
  IsAssignableFrom,
  ToReflectedField,
  Throw,
  ThrowNew,
  ExceptionOccurred,
  ExceptionDescribe,
  ExceptionClear,
  FatalError,
  PushLocalFrame,
  PopLocalFrame,
  NewGlobalRef,
  DeleteGlobalRef,
  DeleteLocalRef,
  IsSameObject,
  NewLocalRef,
  EnsureLocalCapacity,
  AllocObject,
  NewObject,
  NewObjectV,
  NewObjectA,
  GetObjectClass,
  IsInstanceOf,
  GetMethodID,
  CallObjectMethod,
  CallObjectMethodV,
  CallObjectMethodA,
  CallBooleanMethod,
  CallBooleanMethodV,
  CallBooleanMethodA,
  CallByteMethod,
  CallByteMethodV,
  CallByteMethodA,
  CallCharMethod,
  CallCharMethodV,
  CallCharMethodA,
  CallShortMethod,
  CallShortMethodV,
  CallShortMethodA,
  CallIntMethod,
  CallIntMethodV,
  CallIntMethodA,
  CallLongMethod,
  CallLongMethodV,
  CallLongMethodA,
  CallFloatMethod,
  CallFloatMethodV,
  CallFloatMethodA,
  CallDoubleMethod,
  CallDoubleMethodV,
  CallDoubleMethodA,
  CallVoidMethod,
  CallVoidMethodV,
  CallVoidMethodA,
  CallNonvirtualObjectMethod,
  CallNonvirtualObjectMethodV,
  CallNonvirtualObjectMethodA,
  CallNonvirtualBooleanMethod,
  CallNonvirtualBooleanMethodV,
  CallNonvirtualBooleanMethodA,
  CallNonvirtualByteMethod,
  CallNonvirtualByteMethodV,
  CallNonvirtualByteMethodA,
  CallNonvirtualCharMethod,
  CallNonvirtualCharMethodV,
  CallNonvirtualCharMethodA,
  CallNonvirtualShortMethod,
  CallNonvirtualShortMethodV,
  CallNonvirtualShortMethodA,
  CallNonvirtualIntMethod,
  CallNonvirtualIntMethodV,
  CallNonvirtualIntMethodA,
  CallNonvirtualLongMethod,
  CallNonvirtualLongMethodV,
  CallNonvirtualLongMethodA,
  CallNonvirtualFloatMethod,
  CallNonvirtualFloatMethodV,
  CallNonvirtualFloatMethodA,
  CallNonvirtualDoubleMethod,
  CallNonvirtualDoubleMethodV,
  CallNonvirtualDoubleMethodA,
  CallNonvirtualVoidMethod,
  CallNonvirtualVoidMethodV,
  CallNonvirtualVoidMethodA,
  GetFieldID,
  GetObjectField,
  GetBooleanField,
  GetByteField,
  GetCharField,
  GetShortField,
  GetIntField,
  GetLongField,
  GetFloatField,
  GetDoubleField,
  SetObjectField,
  SetBooleanField,
  SetByteField,
  SetCharField,
  SetShortField,
  SetIntField,
  SetLongField,
  SetFloatField,
  SetDoubleField,
  GetStaticMethodID,
  CallStaticObjectMethod,
  CallStaticObjectMethodV,
  CallStaticObjectMethodA,
  CallStaticBooleanMethod,
  CallStaticBooleanMethodV,
  CallStaticBooleanMethodA,
  CallStaticByteMethod,
  CallStaticByteMethodV,
  CallStaticByteMethodA,
  CallStaticCharMethod,
  CallStaticCharMethodV,
  CallStaticCharMethodA,
  CallStaticShortMethod,
  CallStaticShortMethodV,
  CallStaticShortMethodA,
  CallStaticIntMethod,
  CallStaticIntMethodV,
  CallStaticIntMethodA,
  CallStaticLongMethod,
  CallStaticLongMethodV,
  CallStaticLongMethodA,
  CallStaticFloatMethod,
  CallStaticFloatMethodV,
  CallStaticFloatMethodA,
  CallStaticDoubleMethod,
  CallStaticDoubleMethodV,
  CallStaticDoubleMethodA,
  CallStaticVoidMethod,
  CallStaticVoidMethodV,
  CallStaticVoidMethodA,
  GetStaticFieldID,
  GetStaticObjectField,
  GetStaticBooleanField,
  GetStaticByteField,
  GetStaticCharField,
  GetStaticShortField,
  GetStaticIntField,
  GetStaticLongField,
  GetStaticFloatField,
  GetStaticDoubleField,
  SetStaticObjectField,
  SetStaticBooleanField,
  SetStaticByteField,
  SetStaticCharField,
  SetStaticShortField,
  SetStaticIntField,
  SetStaticLongField,
  SetStaticFloatField,
  SetStaticDoubleField,
  NewString,
  GetStringLength,
  GetStringChars,
  ReleaseStringChars,
  NewStringUTF,
  GetStringUTFLength,
  GetStringUTFChars,
  ReleaseStringUTFChars,
  GetArrayLength,
  NewObjectArray,
  GetObjectArrayElement,
  SetObjectArrayElement,
  NewBooleanArray,
  NewByteArray,
  NewCharArray,
  NewShortArray,
  NewIntArray,
  NewLongArray,
  NewFloatArray,
  NewDoubleArray,
  GetBooleanArrayElements,
  GetByteArrayElements,
  GetCharArrayElements,
  GetShortArrayElements,
  GetIntArrayElements,
  GetLongArrayElements,
  GetFloatArrayElements,
  GetDoubleArrayElements,
  ReleaseBooleanArrayElements,
  ReleaseByteArrayElements,
  ReleaseCharArrayElements,
  ReleaseShortArrayElements,
  ReleaseIntArrayElements,
  ReleaseLongArrayElements,
  ReleaseFloatArrayElements,
  ReleaseDoubleArrayElements,
  GetBooleanArrayRegion,
  GetByteArrayRegion,
  GetCharArrayRegion,
  GetShortArrayRegion,
  GetIntArrayRegion,
  GetLongArrayRegion,
  GetFloatArrayRegion,
  GetDoubleArrayRegion,
  SetBooleanArrayRegion,
  SetByteArrayRegion,
  SetCharArrayRegion,
  SetShortArrayRegion,
  SetIntArrayRegion,
  SetLongArrayRegion,
  SetFloatArrayRegion,
  SetDoubleArrayRegion,
  RegisterNatives,
  UnregisterNatives,
  MonitorEnter,
  MonitorExit,
  GetJavaVM,
  GetStringRegion,
  GetStringUTFRegion,
  GetPrimitiveArrayCritical,
  ReleasePrimitiveArrayCritical,
  GetStringCritical,
  ReleaseStringCritical,
  NewWeakGlobalRef,
  DeleteWeakGlobalRef,
  ExceptionCheck,
  NewDirectByteBuffer,
  GetDirectBufferAddress,
  GetDirectBufferCapacity
};

/* end of file *[::]/
   
m4svm_off() */
