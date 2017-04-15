/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (_SABLEVM_NO_GC)

/*
----------------------------------------------------------------------
_svmf_heap_init_defaults
----------------------------------------------------------------------
*/

svm_static void
_svmf_heap_init_defaults (_svmt_JavaVM *vm)
{
  vm->heap.size = SVM_HEAP_DEFAULT_SIZE;
}

/*
----------------------------------------------------------------------
_svmf_heap_init
----------------------------------------------------------------------
*/

svm_static jint
_svmf_heap_init (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (vm->verbose_gc)
    {
      _svmf_printf (env, stderr,
		    "[verbose gc: allocating heap of %d bytes]\n",
		    vm->heap.size);
    }

  /* allocate heap */
  vm->heap.start = _svmf_malloc (vm->heap.size);

  if (vm->heap.start == NULL)
    {
      return JNI_ERR;
    }

  vm->heap.end = ((char *) vm->heap.start) + vm->heap.size;
  vm->heap.alloc = vm->heap.start;
  vm->heap.hashcode_base = 0 - (size_t) vm->heap.start;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_gc_new_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmf_gc_new_instance (_svmt_JNIEnv *env, size_t instance_size,
		       void **pinstance)
{
  _svmt_JavaVM *vm = env->vm;
  void *result = NULL;
  jint status = JNI_OK;

  _svmm_mutex_lock (vm->global_mutex);

  _svmf_halt_if_requested (env);

  if (instance_size <=
      (size_t) (((char *) vm->heap.end) - ((char *) vm->heap.alloc)))
    {
      result = vm->heap.alloc;
      vm->heap.alloc = ((char *) vm->heap.alloc) + instance_size;
    }
  else
    {
      /* no gc means we're out of memory... */
      status = JNI_ERR;
    }

  _svmm_mutex_unlock ();

  if (status != JNI_OK)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  {
    size_t i;

    for (i = 0; i < instance_size; i++)
      {
	((char *) result)[i] = 0;
      }
  }

  *pinstance = result;

  return JNI_OK;
}

#endif /* defined (_SABLEVM_NO_GC) */
