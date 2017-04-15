/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmh_new_array_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmh_new_array_instance (_svmt_JNIEnv *env, _svmt_array_info *array_info,
			  jint size, _svmt_array_instance **pinstance)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_instance *result;
  size_t instance_size = _svmf_aligned_size_t (sizeof (_svmt_array_instance));

  assert (array_info->is_array);

  assert (size >= 0);

  if (array_info->dimensions == 1)
    {
      switch (array_info->base_type)
	{
	case SVM_TYPE_BOOLEAN:
	  {
	    instance_size += (((size_t) size) + 7) / 8;
	  }
	  break;

	case SVM_TYPE_BYTE:
	  {
	    instance_size += ((size_t) size);
	  }
	  break;

	case SVM_TYPE_SHORT:
	case SVM_TYPE_CHAR:
	  {
	    if ((size_t) size > (SIZE_T_MAX - instance_size) / 2)
	      {
		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }
	    instance_size += ((size_t) size) * 2;
	  }
	  break;

	case SVM_TYPE_INT:
	case SVM_TYPE_FLOAT:
	  {
	    if ((size_t) size > (SIZE_T_MAX - instance_size) / 4)
	      {
		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }
	    instance_size += ((size_t) size) * 4;
	  }
	  break;

	case SVM_TYPE_LONG:
	case SVM_TYPE_DOUBLE:
	  {
	    if ((size_t) size > (SIZE_T_MAX - instance_size) / 8)
	      {
		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }
	    instance_size += ((size_t) size) * 8;
	  }
	  break;

	case SVM_TYPE_REFERENCE:
	  {
	    if ((size_t) size >
		(SIZE_T_MAX - instance_size) / sizeof (void *))
	      {
		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }
	    instance_size += ((size_t) size) * sizeof (void *);
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}
    }
  else
    {
      instance_size += ((size_t) size) * sizeof (void *);
    }

  instance_size = _svmf_aligned_size_t (instance_size);

  if (_svmf_gc_new_instance (env, instance_size, (void **) &result) != JNI_OK)
    {
      return JNI_ERR;
    }

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  /* do nothing */

#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  /* if elements preceed object header, adjust head pointer
   * accordignly */
  if (array_info->dimensions > 1
      || array_info->base_type == SVM_TYPE_REFERENCE)
    {
      size_t offset =
	_svmf_aligned_size_t (((size_t) size) * sizeof (void *));

      result = (_svmt_array_instance *) (void *) (((char *) result) + offset);
    }
  else
    {
      /* do nothing */
    }

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  /* initialize header fields */
  result->lockword = array_info->initial_lockword;
  result->vtable = array_info->vtable;
  result->size = size;

#if defined (_SABLEVM_NO_GC)  || defined (_SABLEVM_COPY_GC)

  result->hashcode = vm->heap.hashcode_base + (size_t) result;

#elif defined (_SABLEVM_GENCOPY_GC)

  if (_svmf_in_nursery (env, (void *) result))
    result->hashcode = vm->heap.hashcode_base_nursery + (size_t) result;
  else
    result->hashcode = vm->heap.hashcode_base - (size_t) result;

#else
#error todo
#endif

#ifdef MAGIC
  strcpy (result->magic, "SableVM");
#endif

  *pinstance = result;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_clone_array_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmf_clone_array_instance (_svmt_JNIEnv *env, jarray orig, jarray clone)
{
  _svmt_JavaVM *vm = env->vm;
  jint size = (*orig)->size;
  size_t instance_size = _svmf_aligned_size_t (sizeof (_svmt_array_instance));
  _svmt_word array_type = _svmf_lockword_get_array_type ((*orig)->lockword);
  _svmt_array_info *array_info = _svmf_cast_array ((*orig)->vtable->type);

  assert (array_info->is_array);
  assert (size >= 0);

  switch (array_type)
    {
    case SVM_TYPE_BOOLEAN:
      {
	instance_size += (((size_t) size) + 7) / 8;
      }
      break;

    case SVM_TYPE_BYTE:
      {
	instance_size += ((size_t) size);
      }
      break;

    case SVM_TYPE_SHORT:
      {
	instance_size += ((size_t) size) * 2;
      }
      break;

    case SVM_TYPE_CHAR:
      {
	instance_size += ((size_t) size) * 2;
      }
      break;

    case SVM_TYPE_INT:
      {
	instance_size += ((size_t) size) * 4;
      }
      break;

    case SVM_TYPE_LONG:
      {
	instance_size += ((size_t) size) * 8;
      }
      break;

    case SVM_TYPE_FLOAT:
      {
	instance_size += ((size_t) size) * 4;
      }
      break;

    case SVM_TYPE_DOUBLE:
      {
	instance_size += ((size_t) size) * 8;
      }
      break;

    case SVM_TYPE_REFERENCE:
      {
	instance_size += ((size_t) size) * sizeof (void *);
      }
      break;

    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
      break;
    }

  instance_size = _svmf_aligned_size_t (instance_size);

  if (_svmf_gc_new_instance (env, instance_size, (void **) clone) != JNI_OK)
    {
      return JNI_ERR;
    }

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  memcpy (*clone, *orig, instance_size);

#if defined (_SABLEVM_GC_WRITE_BARRIER)
  if (array_type == SVM_TYPE_REFERENCE)
    {
      void *ref, *ref2;
      ref2 = clone + instance_size;
      for (ref = clone + (3 * sizeof (void *));
	   ref < ref2; ref = (char *) ref + sizeof (void *))
	{
	  _svmf_write_barrier (env, (_svmt_object_instance **) ref);
	}
    }
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  /* if elements preceed object header, adjust head pointer
   * accordignly */
  if (array_type == SVM_TYPE_REFERENCE)
    {
      size_t offset =
	_svmf_aligned_size_t (((size_t) size) * sizeof (void *));

      memcpy (*clone, ((char *) (*orig)) - offset, instance_size);

#if defined (_SABLEVM_GC_WRITE_BARRIER)
      if (array_type == SVM_TYPE_REFERENCE)
	{
	  void *ref, *ref2;
	  ref2 = clone + instance_size - (3 * sizeof (void *));
	  for (ref = clone; ref < ref2; ref = (char *) ref + sizeof (void *))
	    {
	      _svmf_write_barrier (env, (_svmt_object_instance **) ref);
	    }
	}
#endif /* _SABLEVM_GC_WRITE_BARRIER */

      *clone =
	(_svmt_array_instance *) (void *) (((char *) (*clone)) + offset);
    }
  else
    {
      memcpy (*clone, *orig, instance_size);
    }

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  /* initialize header fields */
  (*clone)->lockword = array_info->initial_lockword;
  (*clone)->vtable = array_info->vtable;
  (*clone)->size = size;

#if defined (_SABLEVM_NO_GC)  || defined (_SABLEVM_COPY_GC)

  (*clone)->hashcode = vm->heap.hashcode_base + (size_t) *clone;

#elif defined (_SABLEVM_GENCOPY_GC)

  if (_svmf_in_nursery (env, (void *) *clone))
    (*clone)->hashcode = vm->heap.hashcode_base_nursery + (size_t) *clone;
  else
    (*clone)->hashcode = vm->heap.hashcode_base - (size_t) *clone;

#else
#error todo
#endif

#ifdef MAGIC
  strcpy ((*clone)->magic, "SableVM");
#endif

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_new_object_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmh_new_object_instance (_svmt_JNIEnv *env, _svmt_class_info *class_info,
			   _svmt_object_instance **pinstance)
{
  _svmt_object_instance *result;
  size_t instance_size;

  assert (!(class_info->is_array));

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  instance_size = class_info->data.noninterface.next_offset_no_hashcode;

#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  instance_size =
    class_info->data.noninterface.start_offset +
    class_info->data.noninterface.next_offset_no_hashcode;

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  if (_svmf_gc_new_instance (env, instance_size, (void **) &result) != JNI_OK)
    {
      return JNI_ERR;
    }

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  /* do nothing */

#elif defined(_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  /* adjust pointer to object header */
  result = (_svmt_object_instance *) (void *)
    (((char *) result) + class_info->data.noninterface.start_offset);

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  /* initialize header fields */
  result->lockword = class_info->data.noninterface.initial_lockword;
  result->vtable = class_info->data.noninterface.vtable;

#ifdef MAGIC
  strcpy (result->magic, "SableVM");
#endif

  *pinstance = result;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_clone_object_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmf_clone_object_instance (_svmt_JNIEnv *env, jobject orig, jobject clone)
{
  _svmt_class_info *class_info = _svmf_cast_class ((*orig)->vtable->type);
  size_t instance_size;

  assert (!(class_info->is_array));

#if defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  instance_size = class_info->data.noninterface.next_offset_no_hashcode;

#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  instance_size =
    class_info->data.noninterface.start_offset +
    class_info->data.noninterface.next_offset_no_hashcode;

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  if (_svmf_gc_new_instance (env, instance_size, (void **) clone) != JNI_OK)
    {
      return JNI_ERR;
    }

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  memcpy (*clone, *orig, instance_size);

#elif defined(_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  memcpy (*clone,
	  ((char *) (*orig)) - class_info->data.noninterface.start_offset,
	  instance_size);

  /* adjust pointer to object header */
  *clone = (_svmt_object_instance *) (void *)
    (((char *) (*clone)) + class_info->data.noninterface.start_offset);

#endif /* defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT) */

  /* initialize header fields */
  (*clone)->lockword = class_info->data.noninterface.initial_lockword;
  (*clone)->vtable = class_info->data.noninterface.vtable;

#ifdef MAGIC
  strcpy ((*clone)->magic, "SableVM");
#endif

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_clone_instance
----------------------------------------------------------------------
*/

svm_static jint
_svmf_clone_instance (_svmt_JNIEnv *env, jobject orig, jobject clone)
{
  if ((*orig)->vtable->type->is_array)
    {
      return _svmf_clone_array_instance (env, _svmf_cast_jarray (orig),
					 _svmf_cast_jarray (clone));
    }

  return _svmf_clone_object_instance (env, orig, clone);
}

/*
----------------------------------------------------------------------
_svmm_multianewarray
----------------------------------------------------------------------
*/

svm_static jint
_svmh_multianewarray (_svmt_JNIEnv *env, _svmt_array_info *array_info,
		      jint dimensions, _svmt_stack_value counts[],
		      _svmt_array_instance **pinstance)
{
  jint count = counts[0].jint;
  jarray array;

  if (count < 0)
    {
      _svmf_error_NegativeArraySizeException (env);
      return JNI_ERR;
    }

  if (_svmm_new_native_local_array (env, array) != JNI_OK)
    {
      return JNI_ERR;
    }


  if (_svmm_new_array_instance (env, array_info, count, *array) != JNI_OK)
    {
      _svmm_free_native_local_array (env, array);
      return JNI_ERR;
    }

  if (count > 0 && dimensions > 1)
    {
      jint i;

      for (i = 0; i < count; i++)
	{
	  _svmt_array_instance *instance;
	  _svmt_array_instance **elements;

	  if (_svmm_multianewarray
	      (env, array_info->array_element, dimensions - 1, counts[1],
	       instance) != JNI_OK)
	    {
	      _svmm_free_native_local_array (env, array);
	      return JNI_ERR;
	    }

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	  elements = (_svmt_array_instance **) (*array);
	  elements[(-1) - i] = instance;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier
	    (env, (_svmt_object_instance **) &elements[(-1) - i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#else

	  elements = (_svmt_array_instance **)
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  elements[i] = instance;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier (env, (_svmt_object_instance **) &elements[i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#endif
	}
    }

  *pinstance = *array;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  assert (*array == NULL || strcmp ((*array)->magic, "SableVM") == 0);
#endif

  _svmm_free_native_local_array (env, array);
  return JNI_OK;
}
