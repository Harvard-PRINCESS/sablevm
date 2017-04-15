/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <errno.h>

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_availableProcessors
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    availableProcessors
 * Signature: ()I
 */

JNIEXPORT static jint JNICALL
Java_java_lang_VMRuntime_availableProcessors (JNIEnv *_env SVM_UNUSED,
					      jclass class SVM_UNUSED)
{
  /* to do */
  return 1;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_freeMemory
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    freeMemory
 * Signature: ()J
 */

JNIEXPORT static jlong JNICALL
Java_java_lang_VMRuntime_freeMemory (JNIEnv *_env SVM_UNUSED,
				     jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jlong result = -1;

  _svmm_resuming_java (env);

#if defined (_SABLEVM_COPY_GC)
  {
    size_t heap_free = ((char *) vm->heap.end) - ((char *) vm->heap.alloc);

    result = (jlong) heap_free;
  }
#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_totalMemory
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    totalMemory
 * Signature: ()J
 */

JNIEXPORT static jlong JNICALL
Java_java_lang_VMRuntime_totalMemory (JNIEnv *_env SVM_UNUSED,
				      jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jlong result = -1;

  _svmm_resuming_java (env);

#if defined (_SABLEVM_COPY_GC)
  {
    size_t heap_total = ((char *) vm->heap.end) - ((char *) vm->heap.start);

    result = (jlong) heap_total;
  }
#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_maxMemory
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    maxMemory
 * Signature: ()J
 */

JNIEXPORT static jlong JNICALL
Java_java_lang_VMRuntime_maxMemory (JNIEnv *_env SVM_UNUSED,
				    jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jlong result = -1;

  _svmm_resuming_java (env);

#if defined (_SABLEVM_COPY_GC)
  {
    if (vm->heap.max_size == 0)
      result = SVM_JLONG_MAX;
    else
      result = (jlong) vm->heap.max_size;
  }
#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_gc
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    gc
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_gc (JNIEnv *_env, jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

#ifdef _SABLEVM_NO_GC

  /* do nothing ;-) */

#elif defined (_SABLEVM_COPY_GC)

  {
    _svmt_JavaVM *vm = env->vm;
    jint status = JNI_OK;

    _svmm_mutex_lock (vm->global_mutex);

    _svmf_halt_if_requested (env);

    status = _svmf_copy_gc_no_exception (env, 0);

    _svmm_mutex_unlock ();

    if (status != JNI_OK)
      {
	_svmm_fatal_error ("impossible control flow");
      }
  }

#elif defined (_SABLEVM_GENCOPY_GC)

  {
    _svmt_JavaVM *vm = env->vm;
    jint status = JNI_OK;

    _svmm_mutex_lock (vm->global_mutex);

    _svmf_halt_if_requested (env);

    status = _svmf_gencopy_gc_no_exception (env, 0);

    _svmm_mutex_unlock ();

    if (status != JNI_OK)
      {
	_svmm_fatal_error ("impossible control flow");
      }
  }

#else
#error todo
#endif

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_runFinalization
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalization
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_runFinalization (JNIEnv *_env,
					  jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  /* todo */

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_runFinalizationForExit
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalizationForExit
 * Signature: ()V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_runFinalizationForExit (JNIEnv *_env,
						 jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  /* todo */

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_traceInstructions
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    traceInstructions
 * Signature: (Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_traceInstructions (JNIEnv *_env,
					    jclass class SVM_UNUSED,
					    jboolean on)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

#if !defined(NDEBUG)

  env->vm->verbose_instructions = on;

#endif

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_traceMethodCalls
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    traceMethodCalls
 * Signature: (Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_traceMethodCalls (JNIEnv *_env,
					   jclass class SVM_UNUSED,
					   jboolean on)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

#if !defined(NDEBUG)

  env->vm->verbose_methods = on;

#endif

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_runFinalizersOnExit
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalizersOnExit
 * Signature: (Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_runFinalizersOnExit (JNIEnv *_env,
					      jclass class SVM_UNUSED,
					      jboolean value SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  /* todo */

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_exit
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    exit
 * Signature: (I)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMRuntime_exit (JNIEnv *_env, jclass class SVM_UNUSED,
			       jint status)
{
#if !defined(NDEBUG) || defined(STATISTICS)
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
#endif

#ifdef STATISTICS
  _svmf_print_statistics (env);
#endif /* STATISTICS */

#if !defined(NDEBUG)
  if (env->vm->exit_stack_trace)
    {
      _svmf_printf (env, stderr, "** exit called on thread %d\n",
		    env->thread.id);
      _svmf_dump_stack_trace (env);
    }
#endif

  /* this one is simple! */
  exit (status);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_nativeLoad
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    nativeLoad
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */

JNIEXPORT static jint JNICALL
Java_java_lang_VMRuntime_nativeLoad (JNIEnv *_env, jclass class SVM_UNUSED,
				     jstring _filename,
				     jbyteArray loaderVmData SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  const char *errmsg = "unknown error";

  _svmm_resuming_java (env);

  {
    char *filename;
    _svmt_class_loader_info *class_loader_info =
      _svmf_get_current_class_loader (env);
#ifndef NDEBUG
    _svmt_class_loader_info *class_loader_info2 =
      (loaderVmData ==
       NULL) ? vm->class_loading.boot_loader.
      class_loader_info : _svmf_unwrap_pointer (*loaderVmData);
#endif
    _svmt_native_library *native_library =
      class_loader_info->native_library_list;
    lt_dlhandle handle;
    jboolean monitor_acquired = JNI_FALSE;

    assert (class_loader_info == class_loader_info2);

    if (_svmf_enter_class_loader_monitor (env, class_loader_info) != JNI_OK)
      {
	goto end;
      }

    monitor_acquired = JNI_TRUE;

    if (_svmm_galloc_utf_chars (env, _filename, filename) != JNI_OK)
      {
	goto end;
      }

    handle = lt_dlopenext (filename);

    if (handle == NULL)
      {
	errmsg = lt_dlerror ();
	_svmm_gfree_utf_chars (filename);
	goto end;
      }

    while (native_library != NULL)
      {
	if (native_library->handle == handle)
	  {
	    errmsg = NULL;
	    _svmm_gfree_utf_chars (filename);
	    goto end;
	  }

	native_library = native_library->next;
      }

    /* Call JNI_OnLoad */
    {
      JNIEXPORT jint (JNICALL *JNI_OnLoad) (JavaVM *, void *);

      JNI_OnLoad = SVM_CAST_EXTENSION
	(JNIEXPORT jint (JNICALL *)(JavaVM *, void *)) lt_dlsym (handle,
								 "JNI_OnLoad");

      if (JNI_OnLoad != NULL)
	{
	  jint version = JNI_OnLoad (_svmf_cast_JavaVM (vm), NULL);

	  if (!(version == JNI_VERSION_1_2 || version == JNI_VERSION_1_4))
	    {
	      _svmm_gfree_utf_chars (filename);
	      lt_dlclose (handle);
	      goto end;
	    }
	}
    }

    if (_svmm_cl_zalloc_native_library
	(env, class_loader_info,
	 *(class_loader_info->native_library_list_tail)) != JNI_OK)
      {
	_svmm_gfree_utf_chars (filename);
	goto end;
      }

    (*(class_loader_info->native_library_list_tail))->name = filename;
    (*(class_loader_info->native_library_list_tail))->handle = handle;

    class_loader_info->native_library_list_tail =
      &(*(class_loader_info->native_library_list_tail))->next;

    errmsg = NULL;

  end:

    if (monitor_acquired)
      {
	monitor_acquired = JNI_FALSE;

	if (_svmf_exit_class_loader_monitor (env, class_loader_info) !=
	    JNI_OK)
	  {
	    goto end;
	  }
      }

  }

  _svmm_stopping_java (env);

  return errmsg == NULL ? 1 : 0;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMRuntime_mapLibraryName
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMRuntime
 * Method:    mapLibraryName
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT static jstring JNICALL
Java_java_lang_VMRuntime_mapLibraryName (JNIEnv *_env,
					 jclass _class SVM_UNUSED,
					 jstring libname)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string = NULL;

  _svmm_resuming_java (env);

  {
    /*
     * Note: This functionality is not VM specify.
     *       Could be rewritten in JNI and be added to Classpath native lib.
     */
    char *short_name;
    char *name;
    size_t len;

    if (_svmm_galloc_utf_chars (env, libname, short_name) != JNI_OK)
      {
	goto end;
      }

    /* Assuming standard: "lib" + libname */
    len = 3 + strlen (short_name) + 1;

    if (_svmm_gmalloc_cchars (env, len, name) != JNI_OK)
      {
	_svmm_gfree_utf_chars (short_name);
	goto end;
      }

    strcpy (name, "lib");
    strcat (name, short_name);

    assert (strlen (name) == (len - 1));

    string = _svmf_get_jni_frame_native_local (env);
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    _svmf_get_string (env, name, string);

    _svmm_gfree_utf_chars (short_name);
    _svmm_gmfree_cchars (name);
  }

end:

  _svmm_stopping_java (env);

  return string;
}
