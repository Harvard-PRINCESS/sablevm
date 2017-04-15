/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmm_identity_hashcode
----------------------------------------------------------------------
*/

#define _svmm_identity_hashcode(env, obj, hashcode) \
_svmh_identity_hashcode (env, obj, &hashcode)

svm_static jint
_svmh_identity_hashcode (_svmt_JNIEnv *env, jobject obj, jint *phashcode)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;
  _svmt_JNIEnv *owner = NULL;

  /* is it an array? */
  if (_svmf_lockword_is_array ((*obj)->lockword))
    {
      assert (!monitor_acquired);

      *phashcode = (*(_svmf_cast_jarray (obj)))->hashcode;
      return JNI_OK;
    }

retry:
  {
    _svmt_object_instance *instance = *obj;
    _svmt_word state = _svmf_lockword_get_hashstate (instance->lockword);

    switch (state)
      {
      case SVM_HASH_NONE:
	{
	  /* The untold story in the 2 bits hashcode within a thin
	     lock is that it cannot be modified unless a) the current
	     thread owns the lock, or b) the owning thread is
	     suspended.
	   */

	  if (!monitor_acquired)
	    {
	      jboolean succeeded = JNI_FALSE;	/* init just to keep compiler happy */

	      if (_svmm_enter_object_monitor_non_blocking
		  (env, instance, succeeded))
		{
		  return JNI_ERR;
		}

	      if (succeeded)
		{
		  monitor_acquired = JNI_TRUE;
		  goto retry;
		}

	      /* refresh values, in case GC happened in enter_monitor call */
	      instance = *obj;

	      /* contention: another thread owns the lock.  Suspend it. */
	      {
		_svmt_word lockword = instance->lockword;

		if (_svmf_lockword_is_thin (lockword))
		  {
		    jint owner_id = _svmf_lockword_get_thread_id (lockword);

		    assert (owner_id != env->thread.id);

		    owner = vm->threads.array[owner_id];

		    /* If the lock has been released, retry. */
		    if (owner == NULL)
		      {
			goto retry;
		      }

		    _svmm_mutex_lock (vm->global_mutex);

		    assert (env != owner);

		    /* suspend owner thread */
		    _svmf_suspend_thread (env, owner);

		    _svmm_mutex_unlock ();

		    /* refresh values */
		    instance = *obj;
		    lockword = instance->lockword;

		    if (_svmf_lockword_is_thin (lockword))
		      {
			owner_id = _svmf_lockword_get_thread_id (lockword);
		      }
		    else
		      {
			owner_id = 0;	/* so that we retry */
		      }

		    /* make sure it is still owner */
		    if (owner != vm->threads.array[owner_id])
		      {
			_svmm_mutex_lock (vm->global_mutex);

			/* resume owner thread */
			_svmf_resume_thread (env, owner);

			_svmm_mutex_unlock ();

			owner = NULL;
			goto retry;
		      }
		  }
		else
		  {
		    /* it is a fat lock */

		    _svmt_word fat_index =
		      _svmf_lockword_get_fatlock_index (lockword);
		    _svmt_fat_lock *fat_lock = vm->fat_locks.array[fat_index];

		    _svmm_mutex_lock (fat_lock->mutex);

		    if (fat_lock->recursive_count != 0)
		      {
			owner = fat_lock->owner;
		      }

		    _svmm_mutex_unlock ();

		    /* If the lock has been released, retry. */
		    if (owner == NULL)
		      {
			goto retry;
		      }

		    _svmm_mutex_lock (vm->global_mutex);

		    assert (env != owner);

		    /* suspend owner thread */
		    _svmf_suspend_thread (env, owner);

		    _svmm_mutex_unlock ();

		    /* refresh values */
		    instance = *obj;
		    lockword = instance->lockword;

		    {
		      jboolean changed = JNI_FALSE;

		      if (!_svmf_lockword_is_thin (lockword))
			{
			  fat_index =
			    _svmf_lockword_get_fatlock_index (lockword);
			  fat_lock = vm->fat_locks.array[fat_index];

			  _svmm_mutex_lock (fat_lock->mutex);

			  if (fat_lock->recursive_count == 0
			      || owner != fat_lock->owner)
			    {
			      changed = JNI_TRUE;
			    }

			  _svmm_mutex_unlock ();
			}
		      else
			{
			  changed = JNI_TRUE;
			}

		      /* make sure it is still owner */
		      if (changed)
			{
			  _svmm_mutex_lock (vm->global_mutex);

			  /* resume owner thread */
			  _svmf_resume_thread (env, owner);

			  _svmm_mutex_unlock ();

			  owner = NULL;
			  goto retry;
			}
		    }
		  }
	      }
	    }

#if defined (_SABLEVM_COPY_GC) || defined (_SABLEVM_GENCOPY_GC)

	  /* we must make sure there will be enough space to store the hashcode at gc time */
	  {
	    jint end_of_heap, status = JNI_OK;

	    _svmm_mutex_lock (vm->global_mutex);

	    /* remember that allocation is made in multiples of SVM_ALIGNMENT */
	    if (vm->heap.alloc == vm->heap.end)
	      end_of_heap = JNI_TRUE;
	    else
	      end_of_heap = JNI_FALSE;

	    if (end_of_heap == JNI_TRUE)
	      {
#if defined (_SABLEVM_COPY_GC)
		status = _svmf_copy_gc_no_exception (env, SVM_ALIGNMENT);
#elif defined (_SABLEVM_GENCOPY_GC)
		status = _svmf_gencopy_gc_no_exception (env, SVM_ALIGNMENT);
#endif
	      }

	    if ((end_of_heap == JNI_FALSE) || (status == JNI_OK))
	      {
#if defined (_SABLEVM_GENCOPY_GC)
		if (_svmf_in_nursery (env, *obj))
		  vm->heap.hashed_notmoved_nursery++;
#endif
		vm->heap.hashed_notmoved++;
		vm->heap.end = ((char *) vm->heap.end) - SVM_ALIGNMENT;
	      }

	    _svmm_mutex_unlock ();

	    if (status != JNI_OK)
	      {
		if (monitor_acquired)
		  {
		    assert (owner == NULL);

		    if (_svmf_exit_object_monitor (env, *obj) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		  }
		else
		  {
		    assert (owner != NULL);

		    _svmm_mutex_lock (vm->global_mutex);

		    /* resume owner thread */
		    _svmf_resume_thread (env, owner);

		    _svmm_mutex_unlock ();
		  }

		_svmf_error_OutOfMemoryError (env);
		return JNI_ERR;
	      }

	    /* in case gc moved things around */
	    instance = *obj;
	  }
#endif

	  _svmm_lockword_set_hashstate (instance->lockword,
					SVM_HASH_NOT_MOVED);

#if defined (_SABLEVM_NO_GC) || defined (_SABLEVM_COPY_GC)

	  *phashcode = vm->heap.hashcode_base + (size_t) instance;

#elif defined (_SABLEVM_GENCOPY_GC)

	  if (_svmf_in_nursery (env, instance))
	    *phashcode = vm->heap.hashcode_base_nursery + (size_t) instance;
	  else
	    *phashcode = vm->heap.hashcode_base - (size_t) instance;

#else
#error todo
#endif
	}
	break;

      case SVM_HASH_NOT_MOVED:
	{
#if defined (_SABLEVM_NO_GC)  || defined (_SABLEVM_COPY_GC)

	  *phashcode = vm->heap.hashcode_base + (size_t) instance;

#elif defined (_SABLEVM_GENCOPY_GC)

	  if (_svmf_in_nursery (env, instance))
	    *phashcode = vm->heap.hashcode_base_nursery + (size_t) instance;
	  else
	    *phashcode = vm->heap.hashcode_base - (size_t) instance;

#else
#error todo
#endif
	}
	break;

      case SVM_HASH_MOVED:
	{
	  *phashcode =
	    _svmf_get_INT_field (instance, instance->vtable->hashcode_offset);
	}
	break;

      default:
	{
	  _svmm_fatal_error ("impossible control flow");
	}
	break;
      }
  }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor (env, *obj) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }
  else if (owner != NULL)
    {
      _svmm_mutex_lock (vm->global_mutex);

      /* resume owner thread */
      _svmf_resume_thread (env, owner);

      _svmm_mutex_unlock ();
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_is_assignable_from
----------------------------------------------------------------------
*/

inline svm_static jboolean
_svmf_is_assignable_from (_svmt_JNIEnv *env, _svmt_type_info *from,
			  _svmt_type_info *to)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_type_info *S = from;
  _svmt_type_info *T = to;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (S != NULL);
  assert (T != NULL);
#endif

loop:
  if (!(S->is_array))
    {
      _svmt_class_info *cS = _svmf_cast_class (S);

      if (!_svmf_is_set_flag (cS->access_flags, SVM_ACC_INTERFACE))
	{
	  /* S is a class */
	  if (!(T->is_array))
	    {
	      _svmt_class_info *cT = _svmf_cast_class (T);

	      if (!_svmf_is_set_flag (cT->access_flags, SVM_ACC_INTERFACE))
		{
		  /* T is a class */
		  jint s = cS->data.noninterface.super_classes_size;
		  jint t = cT->data.noninterface.super_classes_size;

		  if ((s < t)
		      || (cS->data.noninterface.super_classes[t - 1] != cT))
		    {
		      return JNI_FALSE;
		    }
		  else
		    {
		      return JNI_TRUE;
		    }
		}
	      else
		{
		  /* T is an interface */
		  jint s = cS->data.noninterface.max_interface_id;
		  jint t = cT->data.interface.interface_id;

		  if ((s < t) ||
		      (_svmf_get_bit
		       (cS->data.noninterface.super_interfaces, t) == 0))
		    {
		      return JNI_FALSE;
		    }
		  else
		    {
		      return JNI_TRUE;
		    }
		}
	    }
	  else
	    {
	      /* T is an array */
	      return JNI_FALSE;
	    }
	}
      else
	{
	  /* S is an interface */
	  if (!(T->is_array))
	    {
	      _svmt_class_info *cT = _svmf_cast_class (T);

	      if (!_svmf_is_set_flag (cT->access_flags, SVM_ACC_INTERFACE))
		{
		  /* T is a class */
		  if (cT == vm->class_loading.boot_loader.classes.jlobject)
		    {
		      return JNI_TRUE;
		    }
		  else
		    {
		      return JNI_FALSE;
		    }
		}
	      else
		{
		  /* T is an interface */
		  jint s = cS->data.interface.interface_id;
		  jint t = cT->data.interface.interface_id;

		  if ((s < t) ||
		      (_svmf_get_bit (cS->data.interface.super_interfaces, t)
		       == 0))
		    {
		      return JNI_FALSE;
		    }
		  else
		    {
		      return JNI_TRUE;
		    }
		}
	    }
	  else
	    {
	      /* T is an array */
	      return JNI_FALSE;
	    }
	}
    }
  else
    {
      /* S is an array */
      _svmt_array_info *aS = _svmf_cast_array (S);

      if (!(T->is_array))
	{
	  _svmt_class_info *cT = _svmf_cast_class (T);

	  if (!_svmf_is_set_flag (cT->access_flags, SVM_ACC_INTERFACE))
	    {
	      /* T is a class */
	      if (cT == vm->class_loading.boot_loader.classes.jlobject)
		{
		  return JNI_TRUE;
		}
	      else
		{
		  return JNI_FALSE;
		}
	    }
	  else
	    {
	      /* T is an interface */
	      if ((cT == vm->class_loading.boot_loader.classes.jlcloneable) ||
		  (cT ==
		   vm->class_loading.boot_loader.classes.jiserializable))
		{
		  return JNI_TRUE;
		}
	      else
		{
		  return JNI_FALSE;
		}
	    }
	}
      else
	{
	  /* T is an array */
	  _svmt_array_info *aT = _svmf_cast_array (T);

	  if ((aS->dimensions == 1 && aS->base_type != SVM_TYPE_REFERENCE) ||
	      (aT->dimensions == 1 && aT->base_type != SVM_TYPE_REFERENCE))
	    {
	      /* S or T is an array of primitive type */
	      if (aS->dimensions == aT->dimensions &&
		  aS->base_type == aT->base_type)
		{
		  return JNI_TRUE;
		}
	      else
		{
		  return JNI_FALSE;
		}
	    }

	  /* redo with element types */

	  if (aS->dimensions == 1)
	    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	      assert (aS->base_type == SVM_TYPE_REFERENCE);
	      assert (aS->base_class != NULL);
#endif

	      S = _svmf_cast_type_class (aS->base_class);
	    }
	  else
	    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	      assert (aS->array_element != NULL);
#endif

	      S = _svmf_cast_type_array (aS->array_element);
	    }

	  if (aT->dimensions == 1)
	    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	      assert (aT->base_type == SVM_TYPE_REFERENCE);
	      assert (aT->base_class != NULL);
#endif

	      T = _svmf_cast_type_class (aT->base_class);
	    }
	  else
	    {
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	      assert (aT->array_element != NULL);
#endif

	      T = _svmf_cast_type_array (aT->array_element);
	    }

	  goto loop;
	}
    }

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  _svmm_fatal_error ("impossible control flow");
#endif
}

/*
----------------------------------------------------------------------
_svmf_set_reference_array_element_no_exception
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_set_reference_array_element_no_exception (_svmt_JNIEnv *env,
						_svmt_array_instance *array,
						jint indx,
						_svmt_object_instance *value)
{
  _svmt_object_instance **elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
  assert (array->vtable->type->is_array == JNI_TRUE);
#endif

  /* check that value is of appropriate type */
  if (value != NULL)
    {
      _svmt_array_info *array_type = _svmf_cast_array (array->vtable->type);
      _svmt_type_info *element_type;

      if (array_type->dimensions > 1)
	{
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (array_type->array_element != NULL);
#endif

	  element_type = _svmf_cast_type_array (array_type->array_element);
	}
      else
	{
#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
	  assert (array_type->dimensions == 1);
	  assert (array_type->base_type == SVM_TYPE_REFERENCE);
	  assert (array_type->base_class != NULL);
#endif

	  element_type = _svmf_cast_type_class (array_type->base_class);
	}

      if (!_svmf_is_assignable_from (env, value->vtable->type, element_type))
	{
	  return JNI_ERR;
	}
    }

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  elements = (_svmt_object_instance **) array;
  elements[(-1) - indx] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
  _svmf_write_barrier
    (env, (_svmt_object_instance **) &elements[(-1) - indx]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#else

  elements = (_svmt_object_instance **)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
  _svmf_write_barrier (env, (_svmt_object_instance **) &elements[indx]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#endif

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_tree_compare_type
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_tree_compare_type (_svmt_type_node *value1, _svmt_type_node *value2)
{
  assert (value1 != NULL);
  assert (value2 != NULL);

  return strcmp (value1->name, value2->name);
}

/*
----------------------------------------------------------------------
_svmf_tree_compare_interface_method_signature
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_tree_compare_imethod_signature (_svmt_imethod_signature_node *value1,
				      _svmt_imethod_signature_node *value2)
{
  jint diff = strcmp (value1->name, value2->name);

  if (diff == 0)
    {
      diff = strcmp (value1->descriptor, value2->descriptor);
    }

  return diff;
}

/*
----------------------------------------------------------------------
_svmf_tree_compare_gc_map
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_tree_compare_gc_map (_svmt_gc_map_node *value1,
			   _svmt_gc_map_node *value2)
{
  jint diff;
  jint i;
  jint size;

  assert (value1 != NULL);
  assert (value2 != NULL);

  diff = value1->size - value2->size;
  i = 0;
  size = value1->size;

  while (diff == 0 && i < size)
    {
      diff =
	_svmf_get_bit (value1->bits, i) - _svmf_get_bit (value2->bits, i);
      i++;
    }

  return diff;
}

/*
----------------------------------------------------------------------
_svmf_tree_compare_sequence
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_tree_compare_sequence (_svmt_sequence_node *value1,
			     _svmt_sequence_node *value2)
{
  jint diff;
  jint i;
  jint size;

  assert (value1 != NULL);
  assert (value2 != NULL);

  diff = value1->instructions_length - value2->instructions_length;
  i = 0;
  size = value1->instructions_length;

  while (diff == 0 && i < size)
    {
      diff = value1->instructions[i] - value2->instructions[i];
      i++;
    }

  return diff;
}

/*
----------------------------------------------------------------------
_svmf_tree_compare_internal_method
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_tree_compare_internal_method (_svmt_internal_method_node *value1,
				    _svmt_internal_method_node *value2)
{
  assert (value1 != NULL);
  assert (value2 != NULL);

  return strcmp (value1->name, value2->name);
}

/*
----------------------------------------------------------------------
_svmh_global_copy_jobject
----------------------------------------------------------------------
*/

inline svm_static jint
_svmh_global_copy_jobject (_svmt_JNIEnv *env, jobject src, jobject *dest)
{
  assert (src != NULL);

  if (_svmm_new_native_global (env, *dest) != JNI_OK)
    {
      return JNI_ERR;
    }

  **dest = *src;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_galloc_copy_str_no_exception
----------------------------------------------------------------------
*/

#define _svmm_galloc_copy_str_no_exception(dst, src) \
_svmh_galloc_copy_str_no_exception (&dst, src)

svm_static jint
_svmh_galloc_copy_str_no_exception (char **dest, const char *src)
{
  char *tmp;

  assert (src != NULL);

  tmp = _svmf_malloc (strlen (src) + 1);

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  strcpy (tmp, src);

  *dest = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gfree_str_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gfree_str_no_exception(str) \
_svmh_gfree_str_no_exception (&str)

svm_static void
_svmh_gfree_str_no_exception (char **str)
{
  assert (*str != NULL);

  _svmf_free (*str);
  *str = NULL;
}

/*
----------------------------------------------------------------------
_svmh_galloc_copy_str
----------------------------------------------------------------------
*/

#define _svmm_galloc_copy_str(env, dst, src) \
_svmh_galloc_copy_str (env, &dst, src)

svm_static jint
_svmh_galloc_copy_str (_svmt_JNIEnv *env, char **dest, const char *src)
{
  char *tmp;

  assert (src != NULL);

  tmp = _svmf_malloc (strlen (src) + 1);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  strcpy (tmp, src);

  *dest = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gfree_str
----------------------------------------------------------------------
*/

#define _svmm_gfree_str(str) \
_svmh_gfree_str (&str)

svm_static void
_svmh_gfree_str (char **str)
{
  assert (*str != NULL);

  _svmf_free (*str);
  *str = NULL;
}

/*
----------------------------------------------------------------------
_svmh_new_native_global_array
----------------------------------------------------------------------
*/

#ifdef COMMENT

static jint
_svmh_new_native_global_array (_svmt_JNIEnv *env, jarray *array)
{
  return _svmh_new_native_global (env, (jobject *) array);
}

#endif /* COMMENT */

/*
----------------------------------------------------------------------
_svmh_free_native_global_array
----------------------------------------------------------------------
*/

#ifdef COMMENT

static void
_svmh_free_native_global_array (_svmt_JNIEnv *env, jarray *pglobal_arrayref)
{
  _svmh_free_native_global (env, (jobject *) pglobal_arrayref);
}

#endif /* COMMENT */

/*
----------------------------------------------------------------------
_svmh_new_native_local_array
----------------------------------------------------------------------
*/

static jint
_svmh_new_native_local_array (_svmt_JNIEnv *env, jarray *array)
{
  return _svmh_new_native_local (env, (jobject *) array);
}

/*
----------------------------------------------------------------------
_svmh_free_native_local_array
----------------------------------------------------------------------
*/

static void
_svmh_free_native_local_array (_svmt_JNIEnv *env, jarray *pglobal_arrayref)
{
  _svmh_free_native_local (env, (jobject *) pglobal_arrayref);
}

/*
----------------------------------------------------------------------
_svmh_local_wrap_pointer
----------------------------------------------------------------------
*/

svm_static jint
_svmh_local_wrap_pointer (_svmt_JNIEnv *env, void *pointer,
			  jbyteArray *pwrapper)
{
  _svmt_JavaVM *vm = env->vm;
  jbyteArray wrapper = NULL;

  if (_svmm_new_native_local_array (env, wrapper) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_array_instance
      (env, vm->class_loading.boot_loader.classes.byte_array, sizeof (void *),
       *wrapper) != JNI_OK)
    {
      _svmm_free_native_local_array (env, wrapper);
      return JNI_ERR;
    }

  /* put "pointer" into the "wrapper" array */
  *((void **) (void *)
    (((char *) *wrapper) + _svmf_aligned_size_t
     (sizeof (_svmt_array_instance)))) = pointer;

  *pwrapper = wrapper;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_wrap_pointer
----------------------------------------------------------------------
*/

svm_static jint
_svmf_wrap_pointer (_svmt_JNIEnv *env, void *pointer, jbyteArray wrapper)
{
  _svmt_JavaVM *vm = env->vm;

  if (_svmm_new_array_instance
      (env, vm->class_loading.boot_loader.classes.byte_array, sizeof (void *),
       *wrapper) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* put "pointer" into the "wrapper" array */
  *((void **) (void *)
    (((char *) *wrapper) + _svmf_aligned_size_t
     (sizeof (_svmt_array_instance)))) = pointer;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_unwrap_pointer
----------------------------------------------------------------------
*/

static void *
_svmf_unwrap_pointer (_svmt_array_instance *wrapper)
{
  return *((void **) (void *)
	   (((char *) wrapper) +
	    _svmf_aligned_size_t (sizeof (_svmt_array_instance))));
}

/*
----------------------------------------------------------------------
_svmf_unwrap_class_instance
----------------------------------------------------------------------
*/

svm_static _svmt_type_info *
_svmf_unwrap_class_instance (_svmt_JNIEnv *env, jclass class)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_instance *vmdata;

  vmdata = _svmf_cast_array_instance
    (_svmf_get_REFERENCE_field (*class,
				vm->class_loading.boot_loader.fields.
				jlclass_vmdata->data.instance_field.offset));

  return (_svmt_type_info *) _svmf_unwrap_pointer (vmdata);
}

/*
----------------------------------------------------------------------
_svmf_unwrap_field_instance
----------------------------------------------------------------------
*/

svm_static _svmt_field_info *
_svmf_unwrap_field_instance (_svmt_JNIEnv *env, jobject obj)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_instance *vmdata;

  vmdata = _svmf_cast_array_instance
    (_svmf_get_REFERENCE_field (*obj,
				vm->class_loading.boot_loader.fields.
				jlrfield_vmdata->data.instance_field.offset));

  return (_svmt_field_info *) _svmf_unwrap_pointer (vmdata);
}

/*
----------------------------------------------------------------------
_svmf_unwrap_method_instance
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_unwrap_method_instance (_svmt_JNIEnv *env, jobject obj)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_instance *vmdata;

  vmdata = _svmf_cast_array_instance
    (_svmf_get_REFERENCE_field (*obj,
				vm->class_loading.boot_loader.fields.
				jlrmethod_vmdata->data.instance_field.
				offset));

  return (_svmt_method_info *) _svmf_unwrap_pointer (vmdata);
}

/*
----------------------------------------------------------------------
_svmf_unwrap_constructor_instance
----------------------------------------------------------------------
*/

svm_static _svmt_method_info *
_svmf_unwrap_constructor_instance (_svmt_JNIEnv *env, jobject obj)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_instance *vmdata;

  vmdata = _svmf_cast_array_instance
    (_svmf_get_REFERENCE_field (*obj,
				vm->class_loading.boot_loader.fields.
				jlrconstructor_vmdata->data.instance_field.
				offset));

  return (_svmt_method_info *) _svmf_unwrap_pointer (vmdata);
}

/*
----------------------------------------------------------------------
_svmf_new_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_new_class_pd (_svmt_JNIEnv *env, _svmt_type_info *type,
		    jobject protection_domain)
{
  _svmt_JavaVM *vm = env->vm;
  jbyteArray data = NULL;
  jclass class_instance = NULL;

  if (_svmm_local_wrap_pointer (env, type, data) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_native_global (env, class_instance) != JNI_OK)
    {
      _svmm_free_native_local_array (env, data);
      return JNI_ERR;
    }

  if (_svmm_new_object_instance
      (env, vm->class_loading.boot_loader.classes.jlclass,
       *class_instance) != JNI_OK)
    {
      _svmm_free_native_local_array (env, data);
      _svmm_free_native_global (env, class_instance);
      return JNI_ERR;
    }

  if (_svmm_invoke_nonvirtual_jlclass_init
      (env, class_instance, _svmf_cast_jobject (data),
       protection_domain) != JNI_OK)
    {
      _svmm_free_native_local_array (env, data);
      _svmm_free_native_global (env, class_instance);
      return JNI_ERR;
    }

  _svmm_free_native_local_array (env, data);

  type->class_instance = class_instance;

  return JNI_OK;
}

svm_static jint
_svmf_new_class (_svmt_JNIEnv *env, _svmt_type_info *type)
{
  return _svmf_new_class_pd (env, type, (jobject) (NULL));
}

/*
----------------------------------------------------------------------
_svmf_find_method_in_class
----------------------------------------------------------------------
*/

/*
inline static _svmt_method_info *
_svmf_find_method_in_class (_svmt_class_info *class, const char *name,
			    const char *descriptor)
{
  jint methods_count = class->methods_count;
  _svmt_method_info *methods = class->methods;
  jint i;

  for (i = 0; i < methods_count; i++)
    {
      _svmt_method_info *method = &methods[i];

      if (strcmp (name, DREF (method->name, value)) == 0 &&
	  strcmp (descriptor, DREF (method->descriptor, value)) == 0)
	{
	  return method;
	}
    }

  return NULL;
}
*/

/*
----------------------------------------------------------------------
_svmf_get_string
----------------------------------------------------------------------
*/

svm_static jint
_svmf_get_string (_svmt_JNIEnv *env, const char *value, jstring str)
{
  _svmt_JavaVM *vm = env->vm;
  jbyteArray data = NULL;
  jint length = strlen (value);
  jint status;

  if (_svmm_new_native_local_array (env, data) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_array_instance
      (env, vm->class_loading.boot_loader.classes.byte_array, length,
       *data) != JNI_OK)
    {
      _svmm_free_native_local_array (env, data);
      return JNI_ERR;
    }

  /* put the string characters into the "wrapper" array without
     including the end-of-string '\0' marker */
  strncpy (((char *) *data) +
	   _svmf_aligned_size_t (sizeof (_svmt_array_instance)), value,
	   length);

  status =
    _svmm_invoke_static_stringcreator_createstring
    (env, _svmf_cast_jobject (data), str);

  _svmm_free_native_local_array (env, data);

  return status;
}

/*
----------------------------------------------------------------------
_svmf_get_interned_string
----------------------------------------------------------------------
*/

svm_static jint
_svmf_get_interned_string (_svmt_JNIEnv *env, const char *value, jstring str)
{
  _svmt_JavaVM *vm = env->vm;
  jbyteArray data = NULL;
  jint length = strlen (value);
  jint status;

  if (_svmm_new_native_local_array (env, data) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_array_instance
      (env, vm->class_loading.boot_loader.classes.byte_array, length,
       *data) != JNI_OK)
    {
      _svmm_free_native_local_array (env, data);
      return JNI_ERR;
    }

  /* put the string characters into the "wrapper" array without
     including the end-of-string '\0' marker */
  strncpy (((char *) *data) +
	   _svmf_aligned_size_t (sizeof (_svmt_array_instance)), value,
	   length);

  status =
    _svmm_invoke_static_stringcreator_createinternedstring
    (env, _svmf_cast_jobject (data), str);

  _svmm_free_native_local_array (env, data);

  return status;
}

/*
----------------------------------------------------------------------
_svmf_get_current_working_directory
----------------------------------------------------------------------
*/

svm_static const char *
_svmf_get_current_working_directory (void)
{
  size_t size = 1024;
  char *buffer = _svmf_malloc (size);

  while (buffer != NULL)
    {
      if (getcwd (buffer, size) != NULL)
	{
	  return buffer;
	}

      _svmf_free (buffer);

      {
	size_t old_size = size;

	size *= 2;

	if (size <= old_size)
	  {
	    return NULL;
	  }
      }

      buffer = _svmf_malloc (size);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmm_galloc_utf_chars
----------------------------------------------------------------------
*/

#define _svmm_galloc_utf_chars(env, src, dst) \
_svmh_galloc_utf_chars (env, src, &dst)

#define _svmm_gfree_utf_chars(str) \
_svmm_gfree_str(str)

svm_static jint
_svmh_galloc_utf_chars (_svmt_JNIEnv *env, jstring src, char **pdst)
{
  jbyteArray bytes;
  char *result;

  if (_svmm_new_native_local_array (env, bytes) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_invoke_static_stringcreator_getutfchars
      (env, src, _svmf_cast_jobject (bytes)) != JNI_OK)
    {
      _svmm_free_native_local_array (env, bytes);
      return JNI_ERR;
    }

  {
    char *str =
      ((char *) *bytes) +
      _svmf_aligned_size_t (sizeof (_svmt_array_instance));

    if (_svmm_galloc_copy_str (env, result, str) != JNI_OK)
      {
	_svmm_free_native_local_array (env, bytes);
	return JNI_ERR;
      }

    _svmm_free_native_local_array (env, bytes);
    *pdst = result;
    return JNI_OK;
  }
}

/*
----------------------------------------------------------------------
_svmf_is_super_class
----------------------------------------------------------------------
*/

svm_static jboolean
_svmf_is_super_class (_svmt_class_info *class1, _svmt_class_info *class2)
{
  _svmt_class_info *current;

  if (CAN_DREF (class2->super_class))
    {
      current = _svmf_cast_class (DREF (class2->super_class, type));
    }
  else
    {
      current = NULL;
    }

  while (current != NULL)
    {
      if (current == class1)
	{
	  return JNI_TRUE;
	}

      if (CAN_DREF (current->super_class))
	{
	  current = _svmf_cast_class (DREF (current->super_class, type));
	}
      else
	{
	  current = NULL;
	}
    }

  return JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_get_current_class_loader
----------------------------------------------------------------------
*/

svm_static _svmt_class_loader_info *
_svmf_get_current_class_loader (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_method_info *method = frame->method;

  while (method != &vm->stack_bottom_method &&
	 method != &vm->vm_initiated_call_method)
    {
      if ((!_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL)) &&
	  method->class_info->class_loader_info->class_loader != NULL)
	{
	  return method->class_info->class_loader_info;
	}

      frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);
      method = frame->method;
    }

  return vm->class_loading.boot_loader.class_loader_info;
}

/*
----------------------------------------------------------------------
_svmf_enter_class_loader_monitor
----------------------------------------------------------------------
*/

svm_static jint
_svmf_enter_class_loader_monitor (_svmt_JNIEnv *env,
				  _svmt_class_loader_info *class_loader_info)
{
  if (class_loader_info->class_loader == NULL)
    {
      _svmt_JavaVM *vm = env->vm;
      assert (class_loader_info ==
	      vm->class_loading.boot_loader.class_loader_info);

      if (_svmf_enter_object_monitor
	  (env,
	   *(vm->class_loading.boot_loader.classes.virtualmachine->
	     class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }
  else
    {
      if (_svmf_enter_object_monitor (env, *(class_loader_info->class_loader))
	  != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_exit_class_loader_monitor
----------------------------------------------------------------------
*/

svm_static jint
_svmf_exit_class_loader_monitor (_svmt_JNIEnv *env,
				 _svmt_class_loader_info *class_loader_info)
{
  if (class_loader_info->class_loader == NULL)
    {
      _svmt_JavaVM *vm = env->vm;
      assert (class_loader_info ==
	      vm->class_loading.boot_loader.class_loader_info);

      if (_svmf_exit_object_monitor
	  (env,
	   *(vm->class_loading.boot_loader.classes.virtualmachine->
	     class_instance)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }
  else
    {
      if (_svmf_exit_object_monitor (env, *(class_loader_info->class_loader))
	  != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_wrap_exception_in_invocationte
----------------------------------------------------------------------
*/

/* This function wraps the "current_exception" parameter into a new
   InvocationTargetException instance, then throws it. */

svm_static int
_svmf_wrap_exception_in_invocationte (_svmt_JNIEnv *env,
				      jobject current_exception)
{
  _svmt_JavaVM *vm = env->vm;
  jobject invocationte = NULL;
  jint status;

  if (_svmm_new_native_local (env, invocationte) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_object_instance
      (env,
       vm->class_loading.boot_loader.classes.jlrinvocationtargetexception,
       *invocationte) != JNI_OK)
    {
      _svmm_free_native_local (env, invocationte);
      return JNI_ERR;
    }

  status =
    _svmm_invoke_nonvirtual_jlrinvocationtargetexception_init (env,
							       invocationte,
							       current_exception);

  /* if no exception was raised, throw InvocationTargetException
     instance */
  if (status == JNI_OK)
    {
      *(env->throwable) = *invocationte;
    }

  _svmm_free_native_local (env, invocationte);

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_verbose_methods_enter
----------------------------------------------------------------------
*/

#ifndef NDEBUG

inline svm_static void
_svmf_verbose_methods_enter (_svmt_JNIEnv *env)
{
  if (env->vm->verbose_methods == JNI_TRUE)
    {
      _svmt_method_info *method = env->stack.current_frame->method;

      _svmf_printf (env, stderr,
		    "T%d: [verbose methods: entering method %s.%s%s]\n",
		    env->thread.id,
		    method->class_info->name,
		    DREF (method->name, value),
		    DREF (method->descriptor, value));
    }
}

#endif /* !NDEBUG */

/*
----------------------------------------------------------------------
_svmf_verbose_methods_exit
----------------------------------------------------------------------
*/

#ifndef NDEBUG

inline svm_static void
_svmf_verbose_methods_exit (_svmt_JNIEnv *env)
{
  if (env->vm->verbose_methods == JNI_TRUE)
    {
      _svmt_method_info *method = env->stack.current_frame->method;

      _svmf_printf (env, stderr,
		    "T%d: [verbose methods: exiting  method %s.%s%s]\n",
		    env->thread.id,
		    method->class_info->name,
		    DREF (method->name, value),
		    DREF (method->descriptor, value));

      {
	_svmt_method_info *caller_method;
	_svmt_stack_frame *caller_frame = env->stack.current_frame;
	caller_frame = (_svmt_stack_frame *) (void *)
	  (((char *) caller_frame) - caller_frame->previous_offset);
	caller_method = caller_frame->method;

	while (_svmf_is_set_flag
	       (caller_method->access_flags, SVM_ACC_INTERNAL)
	       && caller_method != &env->vm->stack_bottom_method)
	  {
	    caller_frame = (_svmt_stack_frame *) (void *)
	      (((char *) caller_frame) - caller_frame->previous_offset);
	    caller_method = caller_frame->method;
	  }

	if (!_svmf_is_set_flag
	    (caller_method->access_flags, SVM_ACC_INTERNAL))
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [                   returning to %s.%s%s]\n",
			  env->thread.id,
			  caller_method->class_info->name,
			  DREF (caller_method->name, value),
			  DREF (caller_method->descriptor, value));
	  }
      }
    }
}

#endif /* !NDEBUG */

/*
----------------------------------------------------------------------
_svmm_get_type_from_within_descriptor
----------------------------------------------------------------------
*/

#ifndef NDEBUG

#define _svmm_get_type_from_within_descriptor(env, method_info, current, index) \
_svmh_get_type_from_within_descriptor (env, method_info, &current, &index)

svm_static _svmt_type_info *
_svmh_get_type_from_within_descriptor (_svmt_JNIEnv *env,
				       _svmt_method_info *method_info,
				       const char **pcurrent, jint *pindex)
{
  const char *current = *pcurrent;
  _svmt_type_info *result = NULL;

  switch (*current)
    {
    case 'B':
    case 'C':
    case 'F':
    case 'I':
    case 'S':
    case 'Z':
    case 'V':
      {
	current++;
	(*pindex)++;
      }
      break;

    case 'D':
    case 'J':
      {
	current++;
	(*pindex) += 2;
      }
      break;

    case 'L':
      {
	jint length = 0;
	char *p = (char *) current;
	_svmt_u8 *name;

	while (*++p != ';')
	  {
	    length++;
	  }

	if (_svmm_gzmalloc_ubytes (env, length + 1, name) != JNI_OK)
	  {
	    _svmm_fatal_error ("unsupported failure while debugging");
	  }

	p = (char *) name;
	while (*++current != ';')
	  {
	    *(p++) = *current;
	  }

	current++;
	(*pindex)++;

	if (_svmm_create_type
	    (env, method_info->class_info->class_loader_info,
	     (const char *) name, result) != JNI_OK)
	  {
	    _svmm_fatal_error ("unsupported failure while debugging");
	  }

	_svmm_gzmfree_ubytes (name);
      }
      break;

    case '[':
      {
	jint length = 0;
	char *p = (char *) current;
	_svmt_u8 *name;

	while (*p == '[')
	  {
	    p++;
	    length++;
	  }

	if (*p == 'L')
	  {
	    while (*p != ';')
	      {
		p++;
		length++;
	      }
	    length++;
	  }
	else
	  {
	    length++;
	  }

	if (_svmm_gzmalloc_ubytes (env, length + 1, name) != JNI_OK)
	  {
	    _svmm_fatal_error ("unsupported failure while debugging");
	  }

	p = (char *) name;
	while (*current == '[')
	  {
	    *(p++) = *current++;
	  }

	if (*current == 'L')
	  {
	    while (*current != ';')
	      {
		*(p++) = *current++;
	      }
	    *(p++) = *current++;
	  }
	else
	  {
	    *(p++) = *current++;
	  }

	(*pindex)++;

	if (_svmm_create_type
	    (env, method_info->class_info->class_loader_info,
	     (const char *) name, result) != JNI_OK)
	  {
	    _svmm_fatal_error ("unsupported failure while debugging");
	  }

	if (_svmf_link_type (env, result) != JNI_OK)
	  {
	    _svmm_fatal_error ("unsupported failure while debugging");
	  }

	_svmm_gzmfree_ubytes (name);
      }
      break;

    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
    }

  *pcurrent = current;
  return result;
}

#endif /* !NDEBUG */

/*
----------------------------------------------------------------------
_svmm_skip_type_within_descriptor
----------------------------------------------------------------------
*/

#ifndef NDEBUG

#define _svmm_skip_type_within_descriptor(current, index) \
_svmh_skip_type_within_descriptor (&current, &index)

svm_static void
_svmh_skip_type_within_descriptor (const char **pcurrent, jint *pindex)
{
  const char *current = *pcurrent;

  switch (*current++)
    {
    case 'B':
    case 'C':
    case 'F':
    case 'I':
    case 'S':
    case 'Z':
    case 'V':
      {
	(*pindex)++;
      }
      break;

    case 'D':
    case 'J':
      {
	(*pindex) += 2;
      }
      break;

    case 'L':
      {
	while (*current++ != ';');

	(*pindex)++;
      }
      break;

    case '[':
      {
	while (*current == '[')
	  {
	    current++;
	  }

	if (*current++ == 'L')
	  {
	    while (*current++ != ';');
	  }

	(*pindex)++;
      }
      break;

    default:
      {
	_svmm_fatal_error ("impossible control flow");
      }
    }

  *pcurrent = current;
}

#endif /* !NDEBUG */

/*
----------------------------------------------------------------------
_svmf_print_statistics
----------------------------------------------------------------------
*/
#ifdef STATISTICS
svm_static void
_svmf_print_statistics (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  _svmf_printf (env, stderr, "\nSTATS: Number of prepared classes: %d\n",
		vm->class_count);
  _svmf_printf (env, stderr, "STATS: Number of prepared interfaces: %d\n",
		vm->interface_count);
  _svmf_printf (env, stderr, "STATS: Number of prepared arrays: %d\n",
		vm->array_count);
  _svmf_printf (env, stderr, "STATS: Number of prepared methods: %d\n",
		vm->method_count);
  _svmf_printf (env, stderr,
		"STATS: Number of prepared bytecode instructions: %d\n",
		vm->bytecode_instruction_count);
  _svmf_printf (env, stderr,
		"STATS: Number of prepared bytecodes: %d\n",
		vm->bytecode_count);
  _svmf_printf (env, stderr, "STATS: Code array size: %d\n\n", vm->code_size);

  _svmf_printf (env, stderr,
		"STATS: Maximum stack size: %d\n", vm->max_stack_size);
  _svmf_printf (env, stderr,
		"STATS: Number of locals on stack: %d\n",
		vm->stack_local_count);
  _svmf_printf (env, stderr,
		"STATS: Number of split locals on stack: %d\n\n",
		vm->stack_local_split_count);

  _svmf_printf (env, stderr,
		"STATS: Total sparse interface virtual tables size: %d\n",
		vm->total_ivtables);
  _svmf_printf (env, stderr,
		"STATS: Total interface virtual table holes size: %d\n",
		vm->total_holes);
  _svmf_printf (env, stderr, "STATS: Total wasted holes size: %d\n\n",
		vm->total_lost_holes);

  _svmf_printf (env, stderr, "STATS: Total GC maps size: %d\n",
		vm->total_gc_maps_size);
  _svmf_printf (env, stderr, "STATS: GC maps count: %d\n",
		vm->total_gc_maps_count);
  _svmf_printf (env, stderr, "STATS: GC points count: %d\n\n",
		vm->check_points_count);

  _svmf_printf (env, stderr, "STATS: Original locals count: %d\n",
		vm->total_orig_locals_count);
  _svmf_printf (env, stderr, "STATS: Unused locals count: %d\n",
		vm->total_unused_locals_count);
  _svmf_printf (env, stderr, "STATS: Added locals count: %d\n\n",
		vm->total_added_locals_count);

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

  _svmf_printf (env, stderr,
		"STATS: Number of distinct (inlined) threads:: %d\n",
		vm->distinct_inlined_threads_count);
  _svmf_printf (env, stderr,
		"STATS: Total bytecode count of distinct threads: %d\n",
		vm->total_distinct_thread_bc_length);
  _svmf_printf (env, stderr,
		"STATS: Total inlined size of distinct threads: %d\n\n",
		vm->total_distinct_thread_inlined_length);

  _svmf_printf (env, stderr, "STATS: Number of (inlined) threads:: %d\n",
		vm->inlined_threads_count);
  _svmf_printf (env, stderr, "STATS: Total bytecode count of threads: %d\n",
		vm->total_thread_bc_length);
  _svmf_printf (env, stderr, "STATS: Total inlined size of threads: %d\n\n",
		vm->total_thread_inlined_length);

  _svmf_printf (env, stderr, "STATS: Maximum thread bytecode count: %d\n",
		vm->max_thread_bc_length);
  _svmf_printf (env, stderr, "STATS: Maximum thread inlined size: %d\n\n",
		vm->max_thread_inlined_length);

#endif

}
#endif /* STATISTICS */
