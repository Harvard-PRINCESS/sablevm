/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_get_jni_frame_free_native_local_count
----------------------------------------------------------------------
*/

svm_static jint
_svmf_get_jni_frame_free_native_local_count (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  _svmt_JavaVM *vm = env->vm;
#endif

  _svmt_stack_frame *frame = env->stack.current_frame;

#ifndef NDEBUG
  _svmt_method_info *method = frame->method;
#endif
  _svmt_stack_native_reference *lrefs = (_svmt_stack_native_reference *)
    (void *) (((char *) frame) + frame->end_offset);
  jint lrefs_count = lrefs[-1].jint;
  size_t lrefs_size = lrefs[-2].size_t;
  jint i;
  jint free_count = 0;

  assert (method == &vm->stack_bottom_method
	  || _svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE));

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

  for (i = 0; i < lrefs_count; i++)
    {
      if (*(lrefs[i].jobject) == NULL)
	{
	  free_count++;
	}
    }

  return free_count;
}

/*
----------------------------------------------------------------------
_svmh_new_native_local
----------------------------------------------------------------------
*/

svm_static jint
_svmh_new_native_local (_svmt_JNIEnv *env, jobject *pobj)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_native_ref *native_local = NULL;

  /* do we already have a free reference available? */
  if (env->native_locals.free_list != NULL)
    {
      native_local = env->native_locals.free_list;

      env->native_locals.free_list = native_local->next;
      if (env->native_locals.free_list != NULL)
	{
	  assert (env->native_locals.free_list->previous == native_local);

	  env->native_locals.free_list->previous = NULL;
	}

      assert (native_local->previous == NULL);

      native_local->next = env->native_locals.list;
      env->native_locals.list = native_local;
      if (native_local->next != NULL)
	{
	  assert (native_local->next->previous == NULL);

	  native_local->next->previous = native_local;
	}

      *pobj = _svmf_cast_jobject_nref (native_local);
      return JNI_OK;
    }

  /* Can we steal a free global native reference? */
  _svmm_mutex_lock (vm->global_mutex);

  if (vm->native_globals.free_list != NULL)
    {
      native_local = vm->native_globals.free_list;

      vm->native_globals.free_list = native_local->next;
      if (vm->native_globals.free_list != NULL)
	{
	  assert (vm->native_globals.free_list->previous == native_local);

	  vm->native_globals.free_list->previous = NULL;
	}
    }

  _svmm_mutex_unlock ();

  if (native_local != NULL)
    {
      assert (native_local->previous == NULL);

      native_local->next = env->native_locals.list;
      env->native_locals.list = native_local;
      if (native_local->next != NULL)
	{
	  assert (native_local->next->previous == NULL);

	  native_local->next->previous = native_local;
	}

      *pobj = _svmf_cast_jobject_nref (native_local);
      return JNI_OK;
    }

  /* we're out of luck; let's allocate a new reference */
  if (_svmm_gzalloc_native_ref_no_exception (native_local) != JNI_OK)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  native_local->next = env->native_locals.list;
  env->native_locals.list = native_local;

  if (native_local->next != NULL)
    {
      assert (native_local->next->previous == NULL);

      native_local->next->previous = native_local;
    }

  *pobj = _svmf_cast_jobject_nref (native_local);
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_free_native_local
----------------------------------------------------------------------
*/

svm_static void
_svmh_free_native_local (_svmt_JNIEnv *env, jobject *pobj)
{
  _svmt_native_ref *native_local = _svmf_cast_nref_jobject (*pobj);

  if (native_local->next != NULL)
    {
      native_local->next->previous = native_local->previous;
    }

  if (native_local->previous != NULL)
    {
      native_local->previous->next = native_local->next;
    }
  else
    {
      env->native_locals.list = native_local->next;
    }

  native_local->ref = NULL;
  native_local->previous = NULL;
  native_local->next = env->native_locals.free_list;

  env->native_locals.free_list = native_local;

  if (native_local->next != NULL)
    {
      assert (native_local->next->previous == NULL);

      native_local->next->previous = native_local;
    }

  *pobj = NULL;
}

/*
----------------------------------------------------------------------
_svmf_ensure_native_local_capacity
----------------------------------------------------------------------
*/

svm_static jint
_svmf_ensure_native_local_capacity (_svmt_JNIEnv *env,
				    jint needed_lrefs_count)
{
  _svmt_stack_frame *frame = env->stack.current_frame;

  _svmt_stack_native_reference *lrefs = (_svmt_stack_native_reference *)
    (void *) (((char *) frame) + frame->end_offset);
  jint old_lrefs_count = lrefs[-1].jint;
  size_t old_lrefs_size = lrefs[-2].size_t;
  jint free_lrefs_count = _svmf_get_jni_frame_free_native_local_count (env);

  jint new_lrefs_count;
  size_t new_lrefs_size;
  size_t size_increase;
  jint i;


  if (free_lrefs_count >= needed_lrefs_count)
    {
      return JNI_OK;		/* all right, nothing to do */
    }

  new_lrefs_count = old_lrefs_count + (needed_lrefs_count - free_lrefs_count);
  new_lrefs_size = _svmf_aligned_size_t
    ((new_lrefs_count + 2) * sizeof (_svmt_stack_native_reference));

  size_increase = new_lrefs_size - old_lrefs_size;

  if (_svmf_ensure_stack_capacity (env, size_increase) != JNI_OK)
    {
      return JNI_ERR;
    }

  frame = env->stack.current_frame;

  frame->end_offset += size_increase;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame->end_offset);
  lrefs[-1].jint = new_lrefs_count;
  lrefs[-2].size_t = new_lrefs_size;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
					       new_lrefs_size);

  /* point lrefs to the begin of _new_ references */
  lrefs = &lrefs[old_lrefs_count];

  /* just in case we've ran out of memory during refs creation */
  memset (lrefs, 0, (needed_lrefs_count - free_lrefs_count) *
	  sizeof (_svmt_stack_native_reference));

  for (i = 0; i < (needed_lrefs_count - free_lrefs_count); i++)
    {
      if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_get_jni_frame_native_local
----------------------------------------------------------------------
*/

/* It is CRITICAL that this function does not cause garbage
 * collection, or, if it does, it MUST abort execution.
 */

/* NOTE: IT IS IMPORTANT to assign a value OTHER THAN NULL into the
 * returned jobject BEFORE calling this method again. IF YOU DON'T
 * follow rigorously this rule, you will probably experience problems,
 * as this function will repeatedly return the exact same jobject.
 *
 * This function is provided as a convenient way to avoid checking
 * return values (as would be necessary with _svmf_new_native_local),
 * by using stack frame reserved JNI jobjects.  Its primary function
 * is to help implement the JNI mechanism.  So, if you're not sure,
 * simply use _svmm_new_native_local; you'll then be safe.
 */

svm_static jobject
_svmf_get_jni_frame_native_local (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  _svmt_JavaVM *vm = env->vm;
#endif

  _svmt_stack_frame *frame = env->stack.current_frame;

#if !defined(NDEBUG) || defined(_SABLEVM_REAL_LIFE_BROKENNESS)
  _svmt_method_info *method = frame->method;
#endif

  _svmt_stack_native_reference *lrefs = (_svmt_stack_native_reference *)
    (void *) (((char *) frame) + frame->end_offset);
  jint lrefs_count = lrefs[-1].jint;
  size_t lrefs_size = lrefs[-2].size_t;
  jint i;

  assert (method == &vm->stack_bottom_method
	  || _svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE));

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

  for (i = 0; i < lrefs_count; i++)
    {
      if (*(lrefs[i].jobject) == NULL)
	{
	  return lrefs[i].jobject;
	}
    }

/* we've ran out of existing local references */

#ifdef _SABLEVM_REAL_LIFE_BROKENNESS

  if (SVM_FRAME_NATIVE_REFS_AUTOADD_STEP > 0)
    {				/* try to autoadd */

      if (env->vm->verbose_jni)
	{
	  _svmf_printf (env, stderr,
			"[verbose jni: local reference capacity (%i) exceeded]\n",
			lrefs_count -
			method->data.native_method->refargs_count);
	}

      /* The following can change env->stack.start/end/current_frame
         and potentially cause GC on failure to create an Exception
         instance. */
      if (_svmf_ensure_native_local_capacity
	  (env, SVM_FRAME_NATIVE_REFS_AUTOADD_STEP) != JNI_OK)
	{
	  goto end;
	}

      frame = env->stack.current_frame;
      lrefs = (_svmt_stack_native_reference *)
	(void *) (((char *) frame) + frame->end_offset);
      lrefs_size = lrefs[-2].size_t;
      lrefs =
	(_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						   lrefs_size);


      /* get the reference again, it must be available this time */
      return lrefs[i].jobject;
    }

#endif


#ifdef _SABLEVM_REAL_LIFE_BROKENNESS
end:
#endif
  _svmf_dump_stack_trace (env);
  _svmf_jni_fatal_error ("Local reference capacity exceeded.\n"
			 "** This is a bug in your application or in the GNU Classpath Library.\n"
			 "** A virtual machine is only required to provide 16 native local\n"
			 "** references per JNI function call.  To get more, an application must call\n"
			 "** EnsureLocalCapacity().\n"
			 "** Temporarily, you might want to compile SableVM with the configure option:\n"
			 "** --enable-real-life-brokenness\n"
			 "** See: http://java.sun.com/docs/books/jni/html/pitfalls.html#11229\n");

  return NULL;			/* to keep compiler happy. */
}

/*
----------------------------------------------------------------------
_svmm_release_jni_frame_native_local
----------------------------------------------------------------------
*/

#define _svmm_release_jni_frame_native_local(obj) \
_svmh_release_jni_frame_native_local (&obj)

svm_static void
_svmh_release_jni_frame_native_local (jobject *pobj)
{
  **pobj = NULL;
  *pobj = NULL;
}

/*
----------------------------------------------------------------------
_svmf_get_jni_frame_native_local_array
----------------------------------------------------------------------
*/

/* NOTE: IT IS IMPORTANT to assign a value OTHER THAN NULL into the
 * returned jarray BEFORE calling this method again. IF YOU DON'T
 * follow rigorously this rule, you will probably experience problems,
 * as this function will repeatedly return the exact same jarray.
 *
 * This function is provided as a convenient way to avoid checking
 * return values (as would be necessary with
 * _svmf_new_native_local_array), by using stack frame reserved JNI
 * jobjects.  Its primary function is to help implement the JNI
 * mechanism.  So, if you're not sure, simply use
 * _svmf_new_native_local_array; you'll then be safe.
 */

svm_static jarray
_svmf_get_jni_frame_native_local_array (_svmt_JNIEnv *env)
{
  return _svmf_cast_jarray (_svmf_get_jni_frame_native_local (env));
}

/*
----------------------------------------------------------------------
_svmm_release_jni_frame_native_local_array
----------------------------------------------------------------------
*/

#define _svmm_release_jni_frame_native_local_array(array) \
_svmh_release_jni_frame_native_local_array (&array)

svm_static void
_svmh_release_jni_frame_native_local_array (jarray *parray)
{
  **parray = NULL;
  *parray = NULL;
}
