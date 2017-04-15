/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMStackWalker_getContextSize
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMStackWalker
 * Method:    getContextSize
 * Signature: ()I
 */

JNIEXPORT static jint JNICALL
Java_gnu_classpath_VMStackWalker_getContextSize (JNIEnv *_env,
						 jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint size = -2;		/* we must ignore the top 2 frames */

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_info *method = frame->method;

    while (method != &vm->stack_bottom_method)
      {
	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	    continue;
	  }

	size++;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	method = frame->method;
      }
  }

  _svmm_stopping_java (env);

  return size;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMStackWalker_fillContext
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMStackWalker
 * Method:    fillContext
 * Signature: ([Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_gnu_classpath_VMStackWalker_fillContext (JNIEnv *_env,
					      jclass _class SVM_UNUSED,
					      jobjectArray context)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    jint size = -2;		/* we must ignore the top 2 frames */
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_info *method = frame->method;

    while (method != &vm->stack_bottom_method)
      {
	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	    continue;
	  }

	if (size >= 0)
	  {
#ifndef NDEBUG
	    int result =
#endif
	      _svmf_set_reference_array_element_no_exception
	      (env, *context, size, *(method->class_info->class_instance));

	    assert (result == JNI_OK);	/* calling java library code *must* be flawless! */
	  }

	size++;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	method = frame->method;
      }
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMStackWalker_fillMethods
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMStackWalker
 * Method:    fillMethods
 * Signature: ([Ljava/lang/String;)V
 */

JNIEXPORT static void JNICALL
Java_gnu_classpath_VMStackWalker_fillMethods (JNIEnv *_env,
					      jclass _class SVM_UNUSED,
					      jobjectArray context)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    jint size = -2;		/* we must ignore the top 2 frames */
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_info *method = frame->method;
    jstring methodName = NULL;

    while (method != &vm->stack_bottom_method)
      {
	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	    continue;
	  }

	if (size >= 0)
	  {
#ifndef NDEBUG
	    int result;
#endif

	    methodName = _svmf_get_jni_frame_native_local (env);
	    if (_svmf_get_string (env, DREF (method->name, value), methodName)
		!= JNI_OK)
	      {
		goto end;
	      }

#ifndef NDEBUG
	    result =
#endif
	      _svmf_set_reference_array_element_no_exception (env, *context,
							      size,
							      *methodName);

	    assert (result == JNI_OK);	/* calling java library code *must* be flawless! */
	    _svmm_release_jni_frame_native_local (methodName);
	  }

	size++;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	method = frame->method;
      }
  }

end:

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMStackWalker_getCallingClass
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMStackWalker
 * Method:    getCallingClass
 * Signature: ()Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_gnu_classpath_VMStackWalker_getCallingClass (JNIEnv *_env,
						  jclass _class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass result = NULL;

  _svmm_resuming_java (env);

  {
    jint size = -2;		/* we must ignore the top 2 frames */
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_info *method = frame->method;

    while (method != &vm->stack_bottom_method)
      {
	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	    continue;
	  }

	if (size == 0)
	  {
	    result = _svmf_get_jni_frame_native_local (env);
	    *result = *(method->class_info->class_instance);
	    goto end;
	  }

	size++;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	method = frame->method;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMStackWalker_getCallingClassLoader
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMStackWalker
 * Method:    getCallingClassLoader
 * Signature: ()Ljava/lang/ClassLoader;
 */

JNIEXPORT static jobject JNICALL
Java_gnu_classpath_VMStackWalker_getCallingClassLoader (JNIEnv *_env,
							jclass _class
							SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  _svmm_resuming_java (env);

  {
    jint size = -2;		/* we must ignore the top 2 frames */
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_method_info *method = frame->method;

    while (method != &vm->stack_bottom_method)
      {
	/* skip internal frames */
	if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	  {
	    frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);
	    method = frame->method;
	    continue;
	  }

	if (size == 0)
	  {
	    jobject class_loader =
	      method->class_info->class_loader_info->class_loader;

	    if (class_loader != NULL)
	      {
		result = _svmf_get_jni_frame_native_local (env);
		*result = *class_loader;
	      }

	    goto end;
	  }

	size++;

	frame = (_svmt_stack_frame *) (void *)
	  (((char *) frame) - frame->previous_offset);
	method = frame->method;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}
