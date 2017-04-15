/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmh_new_native_global
----------------------------------------------------------------------
*/

svm_static jint
_svmh_new_native_global (_svmt_JNIEnv *env, jobject *obj)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_native_ref *native_global = NULL;
  jint status = JNI_OK;

  _svmm_mutex_lock (vm->global_mutex);

  /* do we already have a free reference available? */
  if (vm->native_globals.free_list != NULL)
    {
      native_global = vm->native_globals.free_list;

      vm->native_globals.free_list = native_global->next;
      if (vm->native_globals.free_list != NULL)
	{
	  assert (vm->native_globals.free_list->previous == native_global);

	  vm->native_globals.free_list->previous = NULL;
	}
    }
  else
    {
      status = _svmm_gzalloc_native_ref_no_exception (native_global);
    }

  _svmm_mutex_unlock ();

  if (status != JNI_OK)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  assert (native_global != NULL);
  assert (native_global->previous == NULL);

  native_global->next = vm->native_globals.list;
  vm->native_globals.list = native_global;
  if (native_global->next != NULL)
    {
      assert (native_global->next->previous == NULL);

      native_global->next->previous = native_global;
    }

  *obj = _svmf_cast_jobject_nref (native_global);
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_free_native_global
----------------------------------------------------------------------
*/

svm_static void
_svmh_free_native_global (_svmt_JNIEnv *env, jobject *pglobal_ref)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_native_ref *native_global = _svmf_cast_nref_jobject (*pglobal_ref);

  _svmm_mutex_lock (vm->global_mutex);

  if (native_global->next != NULL)
    {
      native_global->next->previous = native_global->previous;
    }

  if (native_global->previous != NULL)
    {
      native_global->previous->next = native_global->next;
    }
  else
    {
      vm->native_globals.list = native_global->next;
    }

  native_global->ref = NULL;
  native_global->previous = NULL;
  native_global->next = vm->native_globals.free_list;
  vm->native_globals.free_list = native_global;
  if (native_global->next != NULL)
    {
      assert (native_global->next->previous == NULL);

      native_global->next->previous = native_global;
    }

  *pglobal_ref = NULL;

  _svmm_mutex_unlock ();
}
