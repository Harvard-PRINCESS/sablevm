/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_prepare_interface_instanceof
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_interface_instanceof (_svmt_JNIEnv *env,
				    _svmt_class_info *interface)
{
  _svmt_JavaVM *vm = env->vm;
  jint i;

  interface->data.interface.interface_id =
    vm->class_loading.next_interface_id++;

  if (vm->class_loading.next_interface_id < 0)
    {
      /* we have exhausted the number of interfaces!!!  Quite unlikely to
         happen as OutOfMemory error is more likely to happen before this. */
      _svmf_error_InternalError (env);
      return JNI_ERR;
    }

  if (_svmm_cl_zmalloc_super_interfaces
      (env, interface->class_loader_info,
       (interface->data.interface.interface_id / 8) + 1,
       interface->data.interface.super_interfaces) != JNI_OK)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  /* interfaces have no super class other than java.lang.Object which
     implements no interface. */

  for (i = 0; i < interface->interfaces_count; i++)
    {
      _svmt_class_info *super_interface =
	_svmf_cast_class (DREF (interface->interfaces[i], type));
      jint bytes = (super_interface->data.interface.interface_id / 8) + 1;
      jint j;

      for (j = 0; j < bytes; j++)
	{
	  interface->data.interface.super_interfaces[j] |=
	    super_interface->data.interface.super_interfaces[j];
	}
    }

  _svmf_set_bit (interface->data.interface.super_interfaces,
		 interface->data.interface.interface_id);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_noninterface_instanceof
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_noninterface_instanceof (_svmt_JNIEnv *env,
				       _svmt_class_info *class)
{
  if (CAN_DREF (class->super_class))
    {
      jint i;
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));

      class->data.noninterface.super_classes_size =
	super_class->data.noninterface.super_classes_size + 1;

      if (class->data.noninterface.super_classes_size < 0)
	{
	  _svmf_error_InternalError (env);
	  return JNI_ERR;
	}

      if (_svmm_cl_malloc_super_classes
	  (env, class->class_loader_info,
	   class->data.noninterface.super_classes_size,
	   class->data.noninterface.super_classes) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < super_class->data.noninterface.super_classes_size; i++)
	{
	  class->data.noninterface.super_classes[i] =
	    super_class->data.noninterface.super_classes[i];
	}

      class->data.noninterface.super_classes[i] = class;

      class->data.noninterface.max_interface_id =
	super_class->data.noninterface.max_interface_id;
    }
  else
    {
      class->data.noninterface.super_classes_size = 1;

      if (_svmm_cl_malloc_super_classes
	  (env, class->class_loader_info,
	   class->data.noninterface.super_classes_size,
	   class->data.noninterface.super_classes) != JNI_OK)
	{
	  return JNI_ERR;
	}

      class->data.noninterface.super_classes[0] = class;

      class->data.noninterface.max_interface_id = -1;
    }

  {
    jint i;

    for (i = 0; i < class->interfaces_count; i++)
      {
	_svmt_class_info *super_interface =
	  _svmf_cast_class (DREF (class->interfaces[i], type));

	class->data.noninterface.max_interface_id =
	  _svmf_max_jint
	  (class->data.noninterface.max_interface_id,
	   super_interface->data.interface.interface_id);
      }

    if (class->data.noninterface.max_interface_id >= 0)
      {
	if (_svmm_cl_zmalloc_super_interfaces
	    (env, class->class_loader_info,
	     (class->data.noninterface.max_interface_id / 8) + 1,
	     class->data.noninterface.super_interfaces) != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	if (CAN_DREF (class->super_class))
	  {
	    _svmt_class_info *super_class =
	      _svmf_cast_class (DREF (class->super_class, type));

	    if (super_class->data.noninterface.max_interface_id >= 0)
	      {
		jint bytes =
		  (super_class->data.noninterface.max_interface_id / 8) + 1;
		jint j;

		for (j = 0; j < bytes; j++)
		  {
		    class->data.noninterface.super_interfaces[j] |=
		      super_class->data.noninterface.super_interfaces[j];
		  }
	      }
	  }

	for (i = 0; i < class->interfaces_count; i++)
	  {
	    _svmt_class_info *super_interface =
	      _svmf_cast_class (DREF (class->interfaces[i], type));
	    jint bytes =
	      (super_interface->data.interface.interface_id / 8) + 1;
	    jint j;

	    for (j = 0; j < bytes; j++)
	      {
		class->data.noninterface.super_interfaces[j] |=
		  super_interface->data.interface.super_interfaces[j];
	      }
	  }
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_interface_fields
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_interface_fields (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  jint i;
  jint size = class->fields_count;

  for (i = 0; i < size; i++)
    {
      jchar c = DREF (class->fields[i].descriptor, value)[0];

      assert (_svmf_is_set_flag
	      (class->fields[i].access_flags, SVM_ACC_STATIC));

      class->fields[i].class_info = class;

      switch (c)
	{
	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;

	case (_svmt_u8) 'Z':
	  {
	    class->fields[i].type = SVM_TYPE_BOOLEAN;
	  }
	  break;

	case (_svmt_u8) 'B':
	  {
	    class->fields[i].type = SVM_TYPE_BYTE;
	  }
	  break;

	case (_svmt_u8) 'S':
	  {
	    class->fields[i].type = SVM_TYPE_SHORT;
	  }
	  break;

	case (_svmt_u8) 'C':
	  {
	    class->fields[i].type = SVM_TYPE_CHAR;
	  }
	  break;

	case (_svmt_u8) 'I':
	  {
	    class->fields[i].type = SVM_TYPE_INT;
	  }
	  break;

	case (_svmt_u8) 'J':
	  {
	    class->fields[i].type = SVM_TYPE_LONG;
	  }
	  break;

	case (_svmt_u8) 'F':
	  {
	    class->fields[i].type = SVM_TYPE_FLOAT;
	  }
	  break;

	case (_svmt_u8) 'D':
	  {
	    class->fields[i].type = SVM_TYPE_DOUBLE;
	  }
	  break;

	case (_svmt_u8) 'L':
	case (_svmt_u8) '[':
	  {
	    class->fields[i].type = SVM_TYPE_REFERENCE;
	  }
	  break;
	}

      /* if reference, allocate native global */
      if (class->fields[i].type == SVM_TYPE_REFERENCE)
	{
	  if (_svmm_new_native_global
	      (env, class->fields[i].data.class_field.value.l) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_save_instance_free_space
----------------------------------------------------------------------
*/

svm_static void
_svmf_save_instance_free_space (_svmt_class_info *class, size_t size,
				size_t offset)
{
  jint i;
  size_t power;

  for (i = 0, power = 2; i < SVM_ALIGNMENT_POWER; i++, power *= 2)
    {
      if (size % power != 0)
	{
	  assert (class->data.noninterface.free_space_offset[i] == 0);

	  class->data.noninterface.free_space_offset[i] = offset;
	  offset += power / 2;
	  size -= power / 2;
	}
    }
}

/*
----------------------------------------------------------------------
_svmf_get_instance_free_space
----------------------------------------------------------------------
*/

svm_static size_t
_svmf_get_instance_free_space (_svmt_class_info *class, size_t size)
{
  jint i;
  size_t power;
  size_t offset;

  if (size >= SVM_ALIGNMENT)
    {
      assert (size % SVM_ALIGNMENT == 0);

      offset = class->data.noninterface.next_offset_no_hashcode;
      class->data.noninterface.next_offset_no_hashcode += size;
      return offset;
    }

  for (i = 0, power = 1; i < SVM_ALIGNMENT_POWER; i++, power *= 2)
    {
      if (size == power)
	{
	  break;
	}
    }

  assert (i < SVM_ALIGNMENT_POWER);

  for (; i < SVM_ALIGNMENT_POWER; i++, power *= 2)
    {
      offset = class->data.noninterface.free_space_offset[i];

      if (offset != 0)
	{
	  class->data.noninterface.free_space_offset[i] = 0;
	  _svmf_save_instance_free_space (class, power - size, offset + size);
	  return offset;
	}
    }

  offset = class->data.noninterface.next_offset_no_hashcode;
  class->data.noninterface.next_offset_no_hashcode += SVM_ALIGNMENT;
  _svmf_save_instance_free_space (class, SVM_ALIGNMENT - size, offset + size);
  return offset;
}

/*
----------------------------------------------------------------------
_svmf_prepare_noninterface_fields
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_noninterface_fields (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));
      jint i;

      class->data.noninterface.next_offset_no_hashcode =
	super_class->data.noninterface.next_offset_no_hashcode;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

      class->data.noninterface.start_offset =
	super_class->data.noninterface.start_offset;
      class->data.noninterface.ref_field_count =
	super_class->data.noninterface.ref_field_count;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

      class->data.noninterface.ref_field_count =
	super_class->data.noninterface.ref_field_count;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

      class->data.noninterface.free_bits_count =
	super_class->data.noninterface.free_bits_count;
      class->data.noninterface.free_bits_offset =
	super_class->data.noninterface.free_bits_offset;

      for (i = 0; i < SVM_ALIGNMENT_POWER; i++)
	{
	  class->data.noninterface.free_space_offset[i] =
	    super_class->data.noninterface.free_space_offset[i];
	}
    }
  else
    {
      class->data.noninterface.next_offset_no_hashcode =
	_svmf_aligned_size_t (sizeof (_svmt_object_instance));
    }

  {
    jint i;
    jint size = class->fields_count;

    for (i = 0; i < size; i++)
      {
	jchar c = DREF (class->fields[i].descriptor, value)[0];

	class->fields[i].class_info = class;

	switch (c)
	  {
	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;

	  case (_svmt_u8) 'Z':
	    {
	      class->fields[i].type = SVM_TYPE_BOOLEAN;
	    }
	    break;

	  case (_svmt_u8) 'B':
	    {
	      class->fields[i].type = SVM_TYPE_BYTE;
	    }
	    break;

	  case (_svmt_u8) 'S':
	    {
	      class->fields[i].type = SVM_TYPE_SHORT;
	    }
	    break;

	  case (_svmt_u8) 'C':
	    {
	      class->fields[i].type = SVM_TYPE_CHAR;
	    }
	    break;

	  case (_svmt_u8) 'I':
	    {
	      class->fields[i].type = SVM_TYPE_INT;
	    }
	    break;

	  case (_svmt_u8) 'J':
	    {
	      class->fields[i].type = SVM_TYPE_LONG;
	    }
	    break;

	  case (_svmt_u8) 'F':
	    {
	      class->fields[i].type = SVM_TYPE_FLOAT;
	    }
	    break;

	  case (_svmt_u8) 'D':
	    {
	      class->fields[i].type = SVM_TYPE_DOUBLE;
	    }
	    break;

	  case (_svmt_u8) 'L':
	  case (_svmt_u8) '[':
	    {
	      class->fields[i].type = SVM_TYPE_REFERENCE;
	    }
	    break;
	  }

	if (_svmf_is_set_flag (class->fields[i].access_flags, SVM_ACC_STATIC))
	  {
	    /* if reference, allocate native global */
	    if (class->fields[i].type == SVM_TYPE_REFERENCE)
	      {
		if (_svmm_new_native_global
		    (env,
		     class->fields[i].data.class_field.value.l) != JNI_OK)
		  {
		    return JNI_ERR;
		  }
	      }
	  }
	else
	  {
	    switch (class->fields[i].type)
	      {
	      case SVM_TYPE_BOOLEAN:
		{
		  if (class->data.noninterface.free_bits_count == 0)
		    {
		      class->data.noninterface.free_bits_count = 8;
		      class->data.noninterface.free_bits_offset =
			_svmf_get_instance_free_space (class, 1);
		    }

		  /* offset of boolean fields calculated in bits */
		  class->fields[i].data.instance_field.offset =
		    --(class->data.noninterface.free_bits_count);
		  class->fields[i].data.instance_field.offset +=
		    8 * class->data.noninterface.free_bits_offset;
		}
		break;
	      case SVM_TYPE_BYTE:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 1);
		}
		break;
	      case SVM_TYPE_SHORT:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 2);
		}
		break;
	      case SVM_TYPE_CHAR:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 2);
		}
		break;
	      case SVM_TYPE_INT:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 4);
		}
		break;
	      case SVM_TYPE_LONG:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 8);
		}
		break;
	      case SVM_TYPE_FLOAT:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 4);
		}
		break;
	      case SVM_TYPE_DOUBLE:
		{
		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, 8);
		}
		break;
	      case SVM_TYPE_REFERENCE:
		{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

		  class->fields[i].data.instance_field.offset = 0 -
		    ((++(class->data.noninterface.ref_field_count)) *
		     sizeof (void *));

		  if (class->data.noninterface.ref_field_count < 0)
		    {
		      _svmf_error_InternalError (env);
		      return JNI_ERR;
		    }

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

		  class->fields[i].data.instance_field.offset =
		    _svmf_get_instance_free_space (class, sizeof (void *));
		  class->data.noninterface.ref_field_count++;

		  if (class->data.noninterface.ref_field_count < 0)
		    {
		      _svmf_error_InternalError (env);
		      return JNI_ERR;
		    }

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */
		}
		break;
	      }
	  }
      }
  }

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  class->data.noninterface.start_offset =
    _svmf_aligned_size_t (class->data.noninterface.ref_field_count *
			  sizeof (void *));

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  if (_svmm_cl_malloc_size_t
      (env, class->class_loader_info,
       class->data.noninterface.ref_field_count,
       class->data.noninterface.ref_field_offsets) != JNI_OK)
    {
      return JNI_ERR;
    }

  {
    jint i = 0;
    jint j;
    jint size = class->fields_count;

    if (CAN_DREF (class->super_class))
      {
	_svmt_class_info *super_class =
	  _svmf_cast_class (DREF (class->super_class, type));

	for (; i < super_class->data.noninterface.ref_field_count; i++)
	  {
	    class->data.noninterface.ref_field_offsets[i] =
	      super_class->data.noninterface.ref_field_offsets[i];
	  }
      }

    for (j = 0; j < size; j++)
      {
	if (class->fields[j].type == SVM_TYPE_REFERENCE &&
	    (!_svmf_is_set_flag (class->fields[j].access_flags,
				 SVM_ACC_STATIC)))
	  {
	    class->data.noninterface.ref_field_offsets[i++] =
	      class->fields[j].data.instance_field.offset;
	  }
      }

    assert (i == class->data.noninterface.ref_field_count);
  }

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  class->data.noninterface.next_offset_with_hashcode =
    class->data.noninterface.next_offset_no_hashcode +
    _svmf_aligned_size_t (sizeof (jint));

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_method_args_count
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_method_args_count (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  /* skip '(' */
  char *p = &DREF (method->descriptor, value)[1];
  jint count = 0;
  jint map_size = 0;

  if (DREF (method->name, value)[0] == '<')
    {
      if (strcmp (DREF (method->name, value), "<init>") == 0)
	{
	  count++;		/* implicit "this" parameter */
	  map_size = count;
	}
      else
	{
	  /* just making sure the verifier works... */
	  assert (strcmp (DREF (method->name, value), "<clinit>") == 0);
	}
    }
  else
    {
      if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
	{
	  count++;		/* implicit "this" parameter */
	  map_size = count;
	}
    }

  while (*p != ')')
    {
      switch (*p)
	{
	case 'B':
	case 'C':
	case 'F':
	case 'I':
	case 'S':
	case 'Z':
	  {
	    count++;
	  }
	  break;

	case 'D':
	case 'J':
	  {
	    count += 2;
	  }
	  break;

	case 'L':
	  {
	    count++;
	    map_size = count;

	    /* skip to next ';' */
	    while (*++p != ';');
	  }
	  break;

	case '[':
	  {
	    count++;
	    map_size = count;

	    /* skip all '[' */
	    while (*++p == '[');

	    if (*p == 'L')
	      {
		/* skip to next ';' */
		while (*++p != ';');
	      }
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}

      ++p;
    }

  method->java_args_count = count;

  if (_svmm_gzalloc_gc_map_node (env, method->parameters_gc_map) != JNI_OK)
    {
      return JNI_ERR;
    }

  method->parameters_gc_map->size = map_size;

  if (map_size > 0)
    {
      p = &DREF (method->descriptor, value)[1];
      count = 0;

      if (_svmm_gzmalloc_ubytes
	  (env, (map_size + 7) / 8,
	   method->parameters_gc_map->bits) != JNI_OK)
	{
	  return JNI_ERR;
	}

      if (DREF (method->name, value)[0] == '<')
	{
	  if (strcmp (DREF (method->name, value), "<init>") == 0)
	    {
	      _svmf_set_bit (method->parameters_gc_map->bits, count++);
	    }
	  else
	    {
	      /* just making sure the verifier works... */
	      assert (strcmp (DREF (method->name, value), "<clinit>") == 0);
	    }
	}
      else
	{
	  if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
	    {
	      _svmf_set_bit (method->parameters_gc_map->bits, count++);
	    }
	}

      while (*p != ')')
	{
	  switch (*p)
	    {
	    case 'B':
	    case 'C':
	    case 'F':
	    case 'I':
	    case 'S':
	    case 'Z':
	      {
		count++;
	      }
	      break;

	    case 'D':
	    case 'J':
	      {
		count += 2;
	      }
	      break;

	    case 'L':
	      {
		_svmf_set_bit (method->parameters_gc_map->bits, count++);

		/* skip to next ';' */
		while (*++p != ';');
	      }
	      break;

	    case '[':
	      {
		_svmf_set_bit (method->parameters_gc_map->bits, count++);

		/* skip all '[' */
		while (*++p == '[');

		if (*p == 'L')
		  {
		    /* skip to next ';' */
		    while (*++p != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }

	  ++p;
	}
    }

  /* reuse identical map, if it exists */
  {
    _svmt_gc_map_node *map =
      _svmm_tree_find_gc_map (vm->class_loading.gc_map_tree,
			      method->parameters_gc_map);

    if (map == NULL)
      {
#ifdef STATISTICS

	vm->total_gc_maps_count++;
	vm->total_gc_maps_size +=
	  _svmf_aligned_size_t (sizeof (_svmt_gc_map_node)) +
	  _svmf_aligned_size_t ((method->parameters_gc_map->size + 7) / 8);

#endif

	_svmm_tree_insert_gc_map (vm->class_loading.gc_map_tree,
				  method->parameters_gc_map);
      }
    else
      {
	if (method->parameters_gc_map->size > 0)
	  {
	    _svmm_gzmfree_ubytes (method->parameters_gc_map->bits);
	  }

	_svmm_gzfree_gc_map_node (method->parameters_gc_map);

	method->parameters_gc_map = map;
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_get_interface_method_id
----------------------------------------------------------------------
*/

svm_static jint
_svmh_get_interface_method_id (_svmt_JNIEnv *env, const char *name,
			       const char *descriptor, jint *pmethod_id)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_imethod_signature_node sig = { NULL, NULL, 0, NULL, NULL, NULL };
  _svmt_imethod_signature_node *node;

  sig.name = name;
  sig.descriptor = descriptor;

  node =
    _svmm_tree_find_imethod_signature (vm->class_loading.
				       interface_method_signature_tree, &sig);

  if (node != NULL)
    {
      *pmethod_id = node->interface_method_id;
      return JNI_OK;
    }

  if (vm->class_loading.next_interface_method_id < 0)
    {
      /* exceeded internal limits */
      _svmf_error_InternalError (env);
      return JNI_ERR;
    }

  if (_svmm_gzalloc_imethod_signature_node (env, node) != JNI_OK)
    {
      return JNI_ERR;
    }

  node->name = name;
  node->descriptor = descriptor;
  node->interface_method_id = vm->class_loading.next_interface_method_id++;

  _svmm_tree_insert_imethod_signature (vm->class_loading.
				       interface_method_signature_tree, node);

  *pmethod_id = node->interface_method_id;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_interface_methods
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_interface_methods (_svmt_JNIEnv *env,
				 _svmt_class_info *interface)
{
  jint i;
  _svmt_JavaVM *vm = env->vm;

  /* initialize max_interface_method_id (and interface_method_id's) */
  interface->data.interface.max_interface_method_id = -1;

  for (i = 0; i < interface->interfaces_count; i++)
    {
      _svmt_class_info *super_interface =
	_svmf_cast_class (DREF (interface->interfaces[i], type));

      interface->data.interface.max_interface_method_id = _svmf_max_jint
	(interface->data.interface.max_interface_method_id,
	 super_interface->data.interface.max_interface_method_id);
    }

  for (i = 0; i < interface->methods_count; i++)
    {
      /* skip initializer */
      if (DREF (interface->methods[i].name, value)[0] == '<')
	{
	  continue;
	}

      if (_svmm_get_interface_method_id
	  (env, DREF (interface->methods[i].name, value),
	   DREF (interface->methods[i].descriptor, value),
	   interface->methods[i].method_id) != JNI_OK)
	{
	  return JNI_ERR;
	}

      interface->data.interface.max_interface_method_id =
	_svmf_max_jint (interface->data.interface.max_interface_method_id,
			interface->methods[i].method_id);
    }

  /* prepare various method_info fields */
  for (i = 0; i < interface->methods_count; i++)
    {
      _svmt_method_info *method = &interface->methods[i];
      _svmt_method_frame_info *frame_info;

      method->class_info = interface;

      method->synchronized =
	_svmf_is_set_flag (method->access_flags, SVM_ACC_SYNCHRONIZED);

      if (_svmf_prepare_method_args_count (env, method) != JNI_OK)
	{
	  return JNI_ERR;
	}

      if (DREF (method->name, value)[0] == '<')
	{
	  int j;

	  assert (strcmp (DREF (method->name, value), "<clinit>") == 0);

	  frame_info = &method->non_prepared_info;
	  method->frame_info = frame_info;

	  for (j = 0; j < method->attributes_count; j++)
	    {
	      if (strcmp (DREF (method->attributes[j]->name, value),
			  "Code") == 0)
		{
		  method->data.code_attribute =
		    _svmf_cast_code_attribute (method->attributes[j]);
		  break;
		}
	    }

	  assert (method->data.code_attribute != NULL);
	  assert (method->data.code_attribute->max_locals >=
		  method->java_args_count);

	  frame_info->code =
	    &vm->instructions[SVM_INSTRUCTION_PREPARE_METHOD].code;

	  frame_info->start_offset =
	    method->java_args_count * sizeof (_svmt_stack_value);

	  frame_info->end_offset = _svmv_stack_offset +
	    method->data.code_attribute->max_stack *
	    sizeof (_svmt_stack_value);
	  frame_info->java_invoke_frame_size =
	    frame_info->start_offset + frame_info->end_offset;
	  frame_info->internal_invoke_frame_size =
	    _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
	    frame_info->java_invoke_frame_size;

#ifdef STATISTICS

	  frame_info->local_count = method->java_args_count;
	  frame_info->local_split_count = 0;

#endif
	}
      else
	{
	  assert (_svmf_is_set_flag (method->access_flags, SVM_ACC_ABSTRACT));

	  frame_info = &method->prepared_info;
	  method->frame_info = frame_info;

	  frame_info->code =
	    &vm->instructions[SVM_INSTRUCTION_ABSTRACT_METHOD].code;

	  frame_info->start_offset =
	    method->java_args_count * sizeof (_svmt_stack_value);

	  frame_info->end_offset = _svmv_stack_offset;
	  frame_info->java_invoke_frame_size =
	    frame_info->start_offset + frame_info->end_offset;
	  frame_info->internal_invoke_frame_size =
	    _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
	    frame_info->java_invoke_frame_size;

#ifdef STATISTICS

	  frame_info->local_count = method->java_args_count;
	  frame_info->local_split_count = 0;

#endif
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_noninterface_methods
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_noninterface_methods (_svmt_JNIEnv *env,
				    _svmt_class_info *class)
{
  jint i;
  _svmt_JavaVM *vm = env->vm;

  /* initialize max_interface_method_id and max_virtual_method_id */
  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));

      class->data.noninterface.max_virtual_method_id =
	super_class->data.noninterface.max_virtual_method_id;
      class->data.noninterface.max_interface_method_id =
	super_class->data.noninterface.max_interface_method_id;
    }
  else
    {
      class->data.noninterface.max_virtual_method_id = -1;
      class->data.noninterface.max_interface_method_id = -1;
    }

  for (i = 0; i < class->interfaces_count; i++)
    {
      _svmt_class_info *super_interface =
	_svmf_cast_class (DREF (class->interfaces[i], type));

      class->data.noninterface.max_interface_method_id =
	_svmf_max_jint (class->data.noninterface.max_interface_method_id,
			super_interface->data.interface.
			max_interface_method_id);
    }

  for (i = 0; i < class->methods_count; i++)
    {
      _svmt_method_info *method = &class->methods[i];

      /* skip <init>,<clinit>, and svm_static methods */
      if (DREF (method->name, value)[0] == '<' ||
	  _svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
	{
	  continue;
	}

      method->method_id = -1;

      if (CAN_DREF (class->super_class))
	{
	  _svmt_class_info *super_class =
	    _svmf_cast_class (DREF (class->super_class, type));
	  jint j;
	  _svmt_method_info **methods =
	    (_svmt_method_info **) (super_class->data.noninterface.vtable +
				    1);
	  jint size =
	    super_class->data.noninterface.max_virtual_method_id + 1;

	  for (j = 0; j < size; j++)
	    {
	      if (strcmp
		  (DREF (method->name, value),
		   DREF (methods[j]->name, value)) == 0
		  && strcmp (DREF (method->descriptor, value),
			     DREF (methods[j]->descriptor, value)) == 0)
		{
		  method->method_id = methods[j]->method_id;
		  assert (method->method_id == j);
		  break;
		}
	    }
	}

      if (method->method_id == -1)
	{
	  method->method_id =
	    ++(class->data.noninterface.max_virtual_method_id);
	}
    }

  /* prepare various method_info fields */
  for (i = 0; i < class->methods_count; i++)
    {
      _svmt_method_info *method = &class->methods[i];
      _svmt_method_frame_info *frame_info;

      method->class_info = class;

      method->synchronized =
	_svmf_is_set_flag (method->access_flags, SVM_ACC_SYNCHRONIZED);

      if (_svmf_prepare_method_args_count (env, method) != JNI_OK)
	{
	  return JNI_ERR;
	}

      if (DREF (method->name, value)[0] != '<' &&
	  _svmf_is_set_flag (method->access_flags, SVM_ACC_ABSTRACT))
	{
	  frame_info = &method->prepared_info;
	  method->frame_info = frame_info;

	  frame_info->code =
	    &vm->instructions[SVM_INSTRUCTION_ABSTRACT_METHOD].code;

	  frame_info->start_offset =
	    method->java_args_count * sizeof (_svmt_stack_value);

	  frame_info->end_offset = _svmv_stack_offset;
	  frame_info->java_invoke_frame_size =
	    frame_info->start_offset + frame_info->end_offset;
	  frame_info->internal_invoke_frame_size =
	    _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
	    frame_info->java_invoke_frame_size;

#ifdef STATISTICS

	  frame_info->local_count = method->java_args_count;
	  frame_info->local_split_count = 0;

#endif
	}
      else if (DREF (method->name, value)[0] != '<' &&
	       _svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE))
	{
	  if (_svmm_cl_zalloc_native_method_data
	      (env, class->class_loader_info,
	       method->data.native_method) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmf_prepare_native_method_short_name (env, method) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmf_prepare_native_method_long_name (env, method) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  if (_svmf_prepare_native_ffi_args (env, method) != JNI_OK)
	    {
	      return JNI_ERR;
	    }

	  frame_info = &method->prepared_info;
	  method->frame_info = frame_info;

	  frame_info->code =
	    &vm->instructions[SVM_INSTRUCTION_LINK_NATIVE_METHOD].code;

	  frame_info->start_offset =
	    method->data.native_method->java_args_and_ret_count *
	    sizeof (_svmt_stack_value) +
	    _svmf_aligned_size_t (method->data.native_method->args_count *
				  sizeof (void *));

	  frame_info->end_offset =
	    _svmv_stack_offset + _svmf_aligned_size_t
	    (((SVM_FRAME_NATIVE_REFS_MIN + 2) +
	      method->data.native_method->refargs_count) *
	     sizeof (_svmt_stack_native_reference));
	  frame_info->java_invoke_frame_size =
	    frame_info->start_offset + frame_info->end_offset;
	  frame_info->internal_invoke_frame_size =
	    _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
	    frame_info->java_invoke_frame_size;

#ifdef STATISTICS

	  frame_info->local_count = method->java_args_count;
	  frame_info->local_split_count = 0;

#endif
	}
      else
	{
	  int j;

	  frame_info = &method->non_prepared_info;
	  method->frame_info = frame_info;

	  for (j = 0; j < method->attributes_count; j++)
	    {
	      if (strcmp (DREF (method->attributes[j]->name, value), "Code")
		  == 0)
		{
		  method->data.code_attribute =
		    _svmf_cast_code_attribute (method->attributes[j]);
		  break;
		}
	    }

	  assert (method->data.code_attribute != NULL);
	  assert (method->data.code_attribute->max_locals >=
		  method->java_args_count);

	  frame_info->code =
	    &vm->instructions[SVM_INSTRUCTION_PREPARE_METHOD].code;

	  frame_info->start_offset =
	    method->java_args_count * sizeof (_svmt_stack_value);

	  frame_info->end_offset = _svmv_stack_offset +
	    method->data.code_attribute->max_stack *
	    sizeof (_svmt_stack_value);
	  frame_info->java_invoke_frame_size =
	    frame_info->start_offset + frame_info->end_offset;
	  frame_info->internal_invoke_frame_size =
	    _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
	    frame_info->java_invoke_frame_size;

#ifdef STATISTICS

	  frame_info->local_count = method->java_args_count;
	  frame_info->local_split_count = 0;

#endif
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_interface
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_interface (_svmt_JNIEnv *env, _svmt_class_info *interface)
{
  if (_svmf_prepare_interface_instanceof (env, interface) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_prepare_interface_fields (env, interface) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_prepare_interface_methods (env, interface) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmf_fill_interface_table_with_interface
----------------------------------------------------------------------
*/

svm_static void
_svmf_fill_interface_table_with_interface (_svmt_class_info *interface,
					   _svmt_method_info **imethods,
					   _svmt_method_info **vmethods,
					   jint vmethods_count,
					   _svmt_u8 *visited)
{
  jint size = interface->methods_count;
  jint i;

  if (_svmf_get_bit (visited, interface->data.interface.interface_id) == 1)
    {
      return;
    }

  _svmf_set_bit (visited, interface->data.interface.interface_id);

  /* fill the entry related to every method of this interface */
  for (i = 0; i < size; i++)
    {
      _svmt_method_info *method = &interface->methods[i];
      jint j;

      /* skip initializer */
      if (DREF (method->name, value)[0] == '<')
	{
	  continue;
	}

      imethods[-1 - method->method_id] = method;

      for (j = 0; j < vmethods_count; j++)
	{
	  if (strcmp
	      (DREF (method->name, value),
	       DREF (vmethods[j]->name, value)) == 0
	      && strcmp (DREF (method->descriptor, value),
			 DREF (vmethods[j]->descriptor, value)) == 0)
	    {
	      imethods[-1 - method->method_id] = vmethods[j];
	      break;
	    }
	}
    }

  /* recursively visit all super interfaces */
  size = interface->interfaces_count;
  for (i = 0; i < size; i++)
    {
      _svmf_fill_interface_table_with_interface (_svmf_cast_class
						 (DREF
						  (interface->interfaces[i],
						   type)), imethods, vmethods,
						 vmethods_count, visited);
    }
}

/*
----------------------------------------------------------------------
_svmf_fill_interface_table
----------------------------------------------------------------------
*/

svm_static jint
_svmf_fill_interface_table (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  _svmt_u8 *visited;
  _svmt_method_info **imethods =
    (_svmt_method_info **) class->data.noninterface.vtable;
  _svmt_method_info **vmethods =
    (_svmt_method_info **) (class->data.noninterface.vtable + 1);
  jint vmethods_count = class->data.noninterface.max_virtual_method_id + 1;

  assert (!_svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE));

  if (_svmm_gzmalloc_ubytes
      (env, class->data.noninterface.max_interface_id / 8 + 1,
       visited) != JNI_OK)
    {
      return JNI_ERR;
    }

  while (class != NULL)
    {
      jint size = class->interfaces_count;
      jint i;

      for (i = 0; i < size; i++)
	{
	  _svmf_fill_interface_table_with_interface (_svmf_cast_class
						     (DREF
						      (class->interfaces[i],
						       type)), imethods,
						     vmethods, vmethods_count,
						     visited);
	}

      if (CAN_DREF (class->super_class))
	{
	  class = _svmf_cast_class (DREF (class->super_class, type));
	}
      else
	{
	  class = NULL;
	}
    }


  _svmm_gzmfree_ubytes (visited);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_noninterface_vtable
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_noninterface_vtable (_svmt_JNIEnv *env, _svmt_class_info *class)
{
#ifdef STATISTICS
  _svmt_JavaVM *vm = env->vm;
#endif
  jboolean is_abstract =
    _svmf_is_set_flag (class->access_flags, SVM_ACC_ABSTRACT);

  if (_svmm_cl_zalloc_vtable
      (env, class->class_loader_info, class,
       class->data.noninterface.vtable) != JNI_OK)
    {
      return JNI_ERR;
    }

  class->data.noninterface.vtable->type = _svmf_cast_type_class (class);

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  assert (class->data.noninterface.next_offset_with_hashcode ==
	  (class->data.noninterface.next_offset_no_hashcode +
	   _svmf_aligned_size_t (sizeof (jint))));

  class->data.noninterface.vtable->hashcode_offset =
    class->data.noninterface.next_offset_no_hashcode;
  class->data.noninterface.vtable->next_offset_no_hashcode =
    class->data.noninterface.next_offset_no_hashcode;
  class->data.noninterface.vtable->next_offset_with_hashcode =
    class->data.noninterface.next_offset_with_hashcode;
  class->data.noninterface.vtable->start_offset =
    class->data.noninterface.start_offset;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  assert (class->data.noninterface.next_offset_with_hashcode ==
	  (class->data.noninterface.next_offset_no_hashcode +
	   _svmf_aligned_size_t (sizeof (jint))));

  class->data.noninterface.vtable->hashcode_offset =
    class->data.noninterface.next_offset_no_hashcode;
  class->data.noninterface.vtable->next_offset_no_hashcode =
    class->data.noninterface.next_offset_no_hashcode;
  class->data.noninterface.vtable->next_offset_with_hashcode =
    class->data.noninterface.next_offset_with_hashcode;
  class->data.noninterface.vtable->ref_field_count =
    class->data.noninterface.ref_field_count;
  class->data.noninterface.vtable->ref_field_offsets =
    class->data.noninterface.ref_field_offsets;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  /* initialize normal virtual method table from super class */
  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));
      _svmt_method_info **this_methods =
	(_svmt_method_info **) (class->data.noninterface.vtable + 1);
      _svmt_method_info **super_methods =
	(_svmt_method_info **) (super_class->data.noninterface.vtable + 1);
      jint i;
      jint size = super_class->data.noninterface.max_virtual_method_id + 1;

      assert (class->data.noninterface.max_virtual_method_id >=
	      super_class->data.noninterface.max_virtual_method_id);

      for (i = 0; i < size; i++)
	{
	  this_methods[i] = super_methods[i];
	}
    }

  /* fill vtable with methods of this class */
  {
    jint i;
    jint size = class->methods_count;
    _svmt_method_info **methods =
      (_svmt_method_info **) (class->data.noninterface.vtable + 1);

    for (i = 0; i < size; i++)
      {
	/* skip <init>, <clinit>, and svm_static methods */
	if (DREF (class->methods[i].name, value)[0] == '<' ||
	    _svmf_is_set_flag (class->methods[i].access_flags,
			       SVM_ACC_STATIC))
	  {
	    continue;
	  }

	assert (class->methods[i].method_id >= 0);
	assert (class->methods[i].method_id <=
		class->data.noninterface.max_virtual_method_id);

	methods[class->methods[i].method_id] = &class->methods[i];
      }
  }

  if (class->data.noninterface.max_interface_method_id >= 0 && !is_abstract)
    {
      _svmt_method_info **imethods =
	(_svmt_method_info **) class->data.noninterface.vtable;
      jint size = class->data.noninterface.max_interface_method_id + 1;
      jint i;
      size_t hole_size = 0;
      _svmt_method_info **hole = NULL;

      /* fill interface table */
      if (_svmf_fill_interface_table (env, class) != JNI_OK)
	{
	  return JNI_ERR;
	}

      /* check that the latest entry is actually used */
      assert (imethods[-1 - class->data.noninterface.max_interface_method_id]
	      != NULL);

      /* free holes in the interface table */
      for (i = 0; i < size; i++)
	{
	  if (imethods[-1 - i] == NULL)
	    {
	      hole_size += sizeof (void *);
	      hole = &imethods[-1 - i];
	    }
	  else if (hole_size > 0)
	    {
#ifdef STATISTICS
	      vm->total_holes += hole_size;
#endif

	      _svmf_cl_free (env, class->class_loader_info, hole_size,
			     (void **) &hole);

	      hole_size = 0;
	      assert (hole == NULL);
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_noninterface
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_noninterface (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  if (_svmf_prepare_noninterface_instanceof (env, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_prepare_noninterface_fields (env, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_prepare_noninterface_methods (env, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_prepare_noninterface_vtable (env, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  _svmf_prepare_class_lockword (class);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_class (_svmt_JNIEnv *env, _svmt_class_info *class)
{
#ifdef STATISTICS
  _svmt_JavaVM *vm = env->vm;
#endif

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_VERIFIED));

  if (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED))
    {
      return JNI_OK;
    }

  if (class->preparation_error != NULL)
    {
      assert (*(class->preparation_error) != NULL);

      *(env->throwable) = *(class->preparation_error);
      return JNI_ERR;
    }

  if (_svmm_new_native_global (env, class->preparation_error) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (CAN_DREF (class->super_class))
    {
      if (_svmf_link_class
	  (env, _svmf_cast_class (DREF (class->super_class, type))) != JNI_OK)
	{
	  *(class->preparation_error) = *(env->throwable);
	  return JNI_ERR;
	}
    }

  {
    jint i;

    for (i = 0; i < class->interfaces_count; i++)
      {
	if (_svmf_link_class
	    (env,
	     _svmf_cast_class (DREF (class->interfaces[i], type))) != JNI_OK)
	  {
	    *(class->preparation_error) = *(env->throwable);
	    return JNI_ERR;
	  }
      }
  }

  /* resolve file name */
  {
    jint i;
    jint attributes_count = class->attributes_count;
    ;
    for (i = 0; i < attributes_count; i++)
      {
	if (strcmp (DREF (class->attributes[i]->name, value), "SourceFile") ==
	    0)
	  {
	    _svmt_SourceFile_attribute *sourceFile =
	      _svmf_cast_SourceFile_attribute (class->attributes[i]);
	    class->file_name = DREF (sourceFile->sourcefile, value);
	    break;
	  }
      }
  }

  if (_svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE))
    {
      if (_svmf_prepare_interface (env, class) != JNI_OK)
	{
	  *(class->preparation_error) = *(env->throwable);
	  return JNI_ERR;
	}

#ifdef STATISTICS
      vm->interface_count++;
#endif
    }
  else
    {
      if (_svmf_prepare_noninterface (env, class) != JNI_OK)
	{
	  *(class->preparation_error) = *(env->throwable);
	  return JNI_ERR;
	}

#ifdef STATISTICS
      vm->class_count++;
#endif
    }

  _svmm_set_flag (class->state, SVM_TYPE_STATE_PREPARED);
  _svmm_free_native_global (env, class->preparation_error);
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_array_vtable
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_array_vtable (_svmt_JNIEnv *env, _svmt_array_info *array)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_class_info *jlobject = vm->class_loading.boot_loader.classes.jlobject;

  if (_svmm_cl_zalloc_vtable
      (env, array->class_loader_info, jlobject, array->vtable) != JNI_OK)
    {
      return JNI_ERR;
    }

  array->vtable->type = _svmf_cast_type_array (array);

  /* fill vtable with methods of java/lang/Object */
  {
    jint size = jlobject->data.noninterface.max_virtual_method_id + 1;
    _svmt_method_info **jlobject_methods =
      (_svmt_method_info **) (jlobject->data.noninterface.vtable + 1);
    _svmt_method_info **array_methods =
      (_svmt_method_info **) (array->vtable + 1);

    memcpy (array_methods, jlobject_methods, size * sizeof (void *));
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_array
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_array (_svmt_JNIEnv *env, _svmt_array_info *array)
{
#ifdef STATISTICS
  _svmt_JavaVM *vm = env->vm;
#endif

  if (_svmf_is_set_flag (array->state, SVM_TYPE_STATE_PREPARED))
    {
      return JNI_OK;
    }

  if (array->preparation_error != NULL)
    {
      assert (*(array->preparation_error) != NULL);

      *(env->throwable) = *(array->preparation_error);
      return JNI_ERR;
    }

  if (_svmm_new_native_global (env, array->preparation_error) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (array->dimensions > 1)
    {
      if (_svmf_link_array (env, array->array_element) != JNI_OK)
	{
	  *(array->preparation_error) = *(env->throwable);
	  return JNI_ERR;
	}

      /* recursion should have taken care of linking the base class */
      assert (array->base_type != SVM_TYPE_REFERENCE ||
	      _svmf_is_set_flag (array->base_class->state,
				 SVM_TYPE_STATE_PREPARED));
    }
  else if (array->base_type == SVM_TYPE_REFERENCE)
    {
      if (_svmf_link_class (env, array->base_class) != JNI_OK)
	{
	  *(array->preparation_error) = *(env->throwable);
	  return JNI_ERR;
	}
    }

  if (_svmf_prepare_array_vtable (env, array) != JNI_OK)
    {
      *(array->preparation_error) = *(env->throwable);
      return JNI_ERR;
    }

  _svmf_prepare_array_lockword (array);

#ifdef STATISTICS
  vm->array_count++;
#endif

  _svmm_set_flag (array->state, SVM_TYPE_STATE_PREPARED);
  _svmm_free_native_global (env, array->preparation_error);
  return JNI_OK;
}
