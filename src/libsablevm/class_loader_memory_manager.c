/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_class_loader_init_defaults
----------------------------------------------------------------------
*/

svm_static void
_svmf_class_loader_init_defaults (_svmt_JavaVM *vm)
{
  vm->class_loader_min_size = SVM_CLASS_LOADER_DEFAULT_MIN_SIZE;
  vm->class_loader_max_size = SVM_CLASS_LOADER_DEFAULT_MAX_SIZE;
  vm->class_loader_allocation_increment =
    SVM_CLASS_LOADER_DEFAULT_ALLOCATION_INCREMENT;
}

/*
----------------------------------------------------------------------
_svmf_init_cl_alloc
----------------------------------------------------------------------
*/

svm_static jint
_svmf_init_cl_alloc (_svmt_JNIEnv *env,
		     _svmt_class_loader_info *class_loader_info)
{
  _svmt_JavaVM *vm = env->vm;

  assert (class_loader_info->total_allocation_size == 0);

  if (_svmm_gzalloc_memory_block
      (env, class_loader_info->memory_block_list) != JNI_OK)
    {
      return JNI_ERR;
    }

  class_loader_info->memory_block_list->block =
    _svmf_malloc (vm->class_loader_min_size);
  if (class_loader_info->memory_block_list->block == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  class_loader_info->memory_block_list->size = vm->class_loader_min_size;

  class_loader_info->total_allocation_size =
    class_loader_info->memory_block_list->size;
  class_loader_info->free_blocks[0].size =
    class_loader_info->memory_block_list->size;
  class_loader_info->free_blocks[0].block =
    class_loader_info->memory_block_list->block;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_cl_alloc
----------------------------------------------------------------------
*/

svm_static jint
_svmf_cl_alloc (_svmt_JNIEnv *env, _svmt_class_loader_info *class_loader_info,
		size_t size, void **ptr)
{
  _svmt_JavaVM *vm = env->vm;
  jint i;
  jint free_block_index = -1;

  size = _svmf_aligned_size_t (size);

  for (i = 0; i < SVM_CLASS_LOADER_FREE_ARRAY_SIZE; i++)
    {
      if (class_loader_info->free_blocks[i].size >= size)
	{
	  free_block_index = i;
	}
      else
	{
	  break;
	}
    }

  if (free_block_index == -1 && vm->class_loader_allocation_increment == 0)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  if (free_block_index == -1)
    {
      size_t alloc_size = _svmf_aligned_to_increment
	(size, vm->class_loader_allocation_increment);
      _svmt_memory_block *memory_block;
      void *block;

      if (vm->class_loader_max_size != 0 &&
	  (size > vm->class_loader_max_size -
	   class_loader_info->total_allocation_size))
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}

      block = _svmf_malloc (alloc_size);
      if (block == NULL)
	{
	  _svmf_error_OutOfMemoryError (env);
	  return JNI_ERR;
	}

      if (_svmm_gzalloc_memory_block (env, memory_block) != JNI_OK)
	{
	  return JNI_ERR;
	}
      memory_block->block = block;
      memory_block->size = alloc_size;

      memory_block->next = class_loader_info->memory_block_list;
      class_loader_info->memory_block_list = memory_block;

#ifdef STATISTICS
      vm->total_lost_holes +=
	class_loader_info->free_blocks[SVM_CLASS_LOADER_FREE_ARRAY_SIZE -
				       1].size;
#endif

      for (i = SVM_CLASS_LOADER_FREE_ARRAY_SIZE - 1; i > 0; i--)
	{
	  class_loader_info->free_blocks[i] =
	    class_loader_info->free_blocks[i - 1];
	}

      class_loader_info->free_blocks[0].size = alloc_size;
      class_loader_info->free_blocks[0].block = block;

      free_block_index = 0;
    }

  assert (class_loader_info->free_blocks[free_block_index].size >= size);

  {
    void *block = class_loader_info->free_blocks[free_block_index].block;

    *ptr = block;

    /* from now on, use "size" and "block" for the
       remaining part of the free block */
    block = ((char *) block) + size;
    size = class_loader_info->free_blocks[free_block_index].size - size;
    if (size == 0)
      {
	block = NULL;
      }

    for (i = free_block_index + 1; i < SVM_CLASS_LOADER_FREE_ARRAY_SIZE; i++)
      {
	if (class_loader_info->free_blocks[i].size > size)
	  {
	    class_loader_info->free_blocks[i - 1] =
	      class_loader_info->free_blocks[i];
	  }
	else
	  {
	    break;
	  }
      }

    class_loader_info->free_blocks[i - 1].size = size;
    class_loader_info->free_blocks[i - 1].block = block;
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_cl_zalloc
----------------------------------------------------------------------
*/

svm_static jint
_svmf_cl_zalloc (_svmt_JNIEnv *env,
		 _svmt_class_loader_info *class_loader_info, size_t size,
		 void **ptr)
{
  if (_svmf_cl_alloc (env, class_loader_info, size, ptr) != JNI_OK)
    {
      return JNI_ERR;
    }

  {
    size_t i;
    char *mem = *ptr;

    for (i = 0; i < size; i++)
      {
	mem[i] = 0;
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_cl_free
----------------------------------------------------------------------
*/

svm_static void
_svmf_cl_free (_svmt_JNIEnv *env SVM_UNUSED,
	       _svmt_class_loader_info *class_loader_info, size_t size,
	       void **ptr)
{
#ifdef STATISTICS
  _svmt_JavaVM *vm = env->vm;
#endif
  jint i;
  jint insertion_index = -1;

  assert (size > 0);

  /* We want blocks to be aligned in memory, so we must make sure *ptr
     is aligned.  Same applies to size, of course. */

  {
    size_t old_size = size;
    void *old_ptr = *ptr;
    size_t new_size;
    void *new_ptr;
    size_t temp;
    size_t diff;

    temp = _svmf_aligned_size_t ((size_t) old_ptr);
    new_ptr = (void *) temp;

    diff = ((char *) new_ptr) - ((char *) old_ptr);

    if (diff > 0)
      {
	if (diff >= old_size)
	  {
#ifdef STATISTICS
	    vm->total_lost_holes += old_size;
#endif
	    *ptr = NULL;
	    return;
	  }

#ifdef STATISTICS
	vm->total_lost_holes += diff;
#endif
	old_size -= diff;
      }

    assert (old_size > 0);

    new_size = _svmf_aligned_size_t (old_size);

    if (new_size > old_size)
      {
	new_size -= SVM_ALIGNMENT;

	assert (old_size > new_size);

	diff = old_size - new_size;

#ifdef STATISTICS
	vm->total_lost_holes += diff;
#endif

	if (new_size == 0)
	  {
	    *ptr = NULL;
	    return;
	  }
      }

    size = new_size;
    *ptr = new_ptr;
  }

  for (i = SVM_CLASS_LOADER_FREE_ARRAY_SIZE - 1; i >= 0; i--)
    {
      if (size > class_loader_info->free_blocks[i].size)
	{
	  insertion_index = i;
	}
      else
	{
	  break;
	}
    }

  if (insertion_index == -1)
    {
#ifdef STATISTICS
      vm->total_lost_holes += size;
#endif

      *ptr = NULL;
      return;
    }

#ifdef STATISTICS
  vm->total_lost_holes +=
    class_loader_info->free_blocks[SVM_CLASS_LOADER_FREE_ARRAY_SIZE - 1].size;
#endif

  for (i = SVM_CLASS_LOADER_FREE_ARRAY_SIZE - 1; i > insertion_index; i--)
    {
      class_loader_info->free_blocks[i] =
	class_loader_info->free_blocks[i - 1];
    }

  class_loader_info->free_blocks[insertion_index].size = size;
  class_loader_info->free_blocks[insertion_index].block = *ptr;

  *ptr = NULL;
}

/*
----------------------------------------------------------------------
_svmh_cl_zalloc_vtable
----------------------------------------------------------------------
*/

svm_static jint
_svmh_cl_zalloc_vtable (_svmt_JNIEnv *env,
			_svmt_class_loader_info *class_loader_info,
			_svmt_class_info *class, _svmt_vtable **ptr)
{
#ifdef STATISTICS
  _svmt_JavaVM *vm = env->vm;
#endif
  size_t vmethod_size =
    (class->data.noninterface.max_virtual_method_id + 1) * sizeof (void *);
  size_t imethod_size;
  size_t alloc_size;

  if (_svmf_is_set_flag (class->access_flags, SVM_ACC_ABSTRACT))
    {
      imethod_size = 0;
    }
  else
    {
      imethod_size =
	(class->data.noninterface.max_interface_method_id +
	 1) * sizeof (void *);

#ifdef STATISTICS
      vm->total_ivtables += imethod_size;
#endif
    }

  alloc_size = imethod_size + sizeof (_svmt_vtable) + vmethod_size;

  if (_svmf_cl_zalloc (env, class_loader_info, alloc_size, (void **) ptr) !=
      JNI_OK)
    {
      return JNI_ERR;
    }

  *ptr = (_svmt_vtable *) (void *) (((char *) *ptr) + imethod_size);

  return JNI_OK;
}
