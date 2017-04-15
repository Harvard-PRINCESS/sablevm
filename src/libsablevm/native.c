/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_encoding_length
----------------------------------------------------------------------
*/

svm_static size_t
_svmf_encoding_length (const char *name)
{
  const char *p = name;
  size_t length = 0;

  while (*p != 0)
    {
      unsigned char c = *p++;

      if ((c >= 'A' && c <= 'Z') ||
	  (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '/')
	{
	  length++;
	}
      else if (c == '_' || c == ';' || c == '[')
	{
	  length += 2;
	}
      else if (c == '(')
	{
	  /* method descriptor: skip '(' */
	}
      else if (c == ')')
	{
	  /* method descriptor: we're done */
	  break;
	}
      else if ((c & 0x80) == 0x00)
	{
	  length += 6;
	}
      else if ((c & 0xe0) == 0xc0)
	{
	  length += 6;
	  p++;
	}
      else
	{
	  assert ((c & 0xf0) == 0xe0);
	  length += 6;
	  p += 2;
	}
    }

  return length;
}

/*
----------------------------------------------------------------------
_svmf_hex_digit
----------------------------------------------------------------------
*/

inline svm_static char
_svmf_hex_digit (jint h)
{
  assert ((h & 0x0f) == h);

  if (h < 10)
    {
      return h + '0';
    }

  return h - 10 + 'a';
}

/*
----------------------------------------------------------------------
_svmf_encode_name
----------------------------------------------------------------------
*/

svm_static void
_svmf_encode_name (const char *name, char **dest)
{
  const char *p = name;

  while (*p != 0)
    {
      unsigned char c = *p++;

      if ((c >= 'A' && c <= 'Z') ||
	  (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
	{
	  *((*dest)++) = c;
	}
      else if (c == '/')
	{
	  *((*dest)++) = '_';
	}
      else if (c == '_')
	{
	  *((*dest)++) = '_';
	  *((*dest)++) = '1';
	}
      else if (c == ';')
	{
	  *((*dest)++) = '_';
	  *((*dest)++) = '2';
	}
      else if (c == '[')
	{
	  *((*dest)++) = '_';
	  *((*dest)++) = '3';
	}
      else if (c == '(')
	{
	  /* method descriptor: skip '(' */
	}
      else if (c == ')')
	{
	  /* method descriptor: we're done */
	  break;
	}
      else
	{
	  jchar jc;

	  *((*dest)++) = '_';
	  *((*dest)++) = '0';

	  if ((c & 0x80) == 0x00)
	    {
	      jc = c & 0x7f;
	    }
	  else if ((c & 0xe0) == 0xc0)
	    {
	      jc = (c & 0x1f) << 6;

	      c = *p++;
	      assert ((c & 0xc0) == 0x80);
	      jc |= c & 0x3f;
	    }
	  else
	    {
	      assert (((c >> 4) & 0x0f) == 0x0e);

	      jc = (c & 0x0f) << 12;

	      c = *p++;
	      assert ((c & 0xc0) == 0x80);
	      jc |= (c & 0x3f) << 6;

	      c = *p++;
	      assert ((c & 0xc0) == 0x80);
	      jc |= c & 0x3f;
	    }

	  *((*dest)++) = _svmf_hex_digit ((jc >> 12) & 0x0f);
	  *((*dest)++) = _svmf_hex_digit ((jc >> 8) & 0x0f);
	  *((*dest)++) = _svmf_hex_digit ((jc >> 4) & 0x0f);
	  *((*dest)++) = _svmf_hex_digit (jc & 0x0f);
	}
    }
}

/*
----------------------------------------------------------------------
_svmf_prepare_native_method_short_name
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_native_method_short_name (_svmt_JNIEnv *env,
					_svmt_method_info *method)
{
  size_t string_length =
    5 + _svmf_encoding_length (method->class_info->name) + 1 +
    _svmf_encoding_length (DREF (method->name, value)) + 1;
  char *p;

  if (_svmm_cl_malloc_chars
      (env, method->class_info->class_loader_info, string_length,
       method->data.native_method->short_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  p = method->data.native_method->short_name;

  _svmf_encode_name ("Java/", &p);	/* '/' is converted into '_' ;-) */
  _svmf_encode_name (method->class_info->name, &p);
  _svmf_encode_name ("/", &p);
  _svmf_encode_name (DREF (method->name, value), &p);
  *p = 0;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_native_method_long_name
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_native_method_long_name (_svmt_JNIEnv *env,
				       _svmt_method_info *method)
{
  size_t string_length =
    5 + _svmf_encoding_length (method->class_info->name) + 1 +
    _svmf_encoding_length (DREF (method->name, value)) + 2 +
    _svmf_encoding_length (DREF (method->descriptor, value)) + 1;
  char *p;

  if (_svmm_cl_malloc_chars
      (env, method->class_info->class_loader_info, string_length,
       method->data.native_method->long_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  p = method->data.native_method->long_name;

  _svmf_encode_name ("Java/", &p);	/* '/' is converted into '_' ;-) */
  _svmf_encode_name (method->class_info->name, &p);
  _svmf_encode_name ("/", &p);
  _svmf_encode_name (DREF (method->name, value), &p);
  _svmf_encode_name ("//", &p);
  _svmf_encode_name (DREF (method->descriptor, value), &p);
  *p = 0;

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_native_method_args_count
----------------------------------------------------------------------
*/

svm_static void
_svmf_prepare_native_method_args_count (_svmt_method_info *method)
{
  char *p = DREF (method->descriptor, value) + 1;
  size_t count = 2;		/* env and class/instance params */
  size_t refcount = 1;		/* class/instance param */

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
	case 'D':
	case 'J':
	  {
	    count++;
	  }
	  break;

	case 'L':
	  {
	    count++;
	    refcount++;

	    /* skip to next ';' */
	    while (*++p != ';');
	  }
	  break;

	case '[':
	  {
	    count++;
	    refcount++;

	    /* skip all '[' */
	    while (*++p == '[');

	    if (*p == 'L')
	      {
		/* skip to next ';' */
		while (*++p != ';');
	      }
	  }
	  break;
	}

      p++;
    }

  method->data.native_method->args_count = count;
  method->data.native_method->refargs_count = refcount;
}

/*
----------------------------------------------------------------------
_svmf_prepare_native_method_args
----------------------------------------------------------------------
*/

svm_static void
_svmf_prepare_native_method_args (_svmt_method_info *method)
{
  size_t i;
  char *p = DREF (method->descriptor, value) + 1;

  for (i = 0; i < 2; i++)
    {
      method->data.native_method->args[i] = &ffi_type_pointer;
    }

  while (*p != ')')
    {
      switch (*p)
	{
	case 'B':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_BYTE;
	    method->data.native_method->args[i] = &ffi_type_sint8;
	    i++;
	  }
	  break;

	case 'C':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_CHAR;
	    method->data.native_method->args[i] = &ffi_type_uint16;
	    i++;
	  }
	  break;

	case 'F':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_FLOAT;
	    method->data.native_method->args[i] = &ffi_type_float32;
	    i++;
	  }
	  break;

	case 'I':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_INT;
	    method->data.native_method->args[i] = &ffi_type_sint32;
	    i++;
	  }
	  break;

	case 'S':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_SHORT;
	    method->data.native_method->args[i] = &ffi_type_sint16;
	    i++;
	  }
	  break;

	case 'Z':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_BOOLEAN;
	    method->data.native_method->args[i] = &ffi_type_uint8;
	    i++;
	  }
	  break;

	case 'D':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_DOUBLE;
	    method->data.native_method->args[i] = &ffi_type_float64;
	    i++;
	  }
	  break;

	case 'J':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_LONG;
	    method->data.native_method->args[i] = &ffi_type_sint64;
	    i++;
	  }
	  break;

	case 'L':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_REFERENCE;
	    method->data.native_method->args[i] = &ffi_type_pointer;
	    i++;

	    /* skip to next ';' */
	    while (*++p != ';');
	  }
	  break;

	case '[':
	  {
	    method->data.native_method->arg_types[i] = SVM_TYPE_REFERENCE;
	    method->data.native_method->args[i] = &ffi_type_pointer;
	    i++;

	    /* skip all '[' */
	    while (*++p == '[');

	    if (*p == 'L')
	      {
		/* skip to next ';' */
		while (*++p != ';');
	      }
	  }
	  break;
	}

      p++;
    }

  switch (*++p)
    {
    case 'B':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_BYTE;
	method->data.native_method->ret = &ffi_type_sint8;
      }
      break;

    case 'C':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_CHAR;
	method->data.native_method->ret = &ffi_type_uint16;
      }
      break;

    case 'F':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_FLOAT;
	method->data.native_method->ret = &ffi_type_float32;
      }
      break;

    case 'I':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_INT;
	method->data.native_method->ret = &ffi_type_sint32;
      }
      break;

    case 'S':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_SHORT;
	method->data.native_method->ret = &ffi_type_sint16;
      }
      break;

    case 'Z':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_BOOLEAN;
	method->data.native_method->ret = &ffi_type_uint8;
      }
      break;

    case 'D':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (2, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_DOUBLE;
	method->data.native_method->ret = &ffi_type_float64;
      }
      break;

    case 'J':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (2, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_LONG;
	method->data.native_method->ret = &ffi_type_sint64;
      }
      break;

    case 'L':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_REFERENCE;
	method->data.native_method->ret = &ffi_type_pointer;
      }
      break;

    case '[':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (1, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_REFERENCE;
	method->data.native_method->ret = &ffi_type_pointer;
      }
      break;

    case 'V':
      {
	method->data.native_method->java_args_and_ret_count =
	  _svmf_max_jint (0, method->java_args_count);
	method->data.native_method->ret_type = SVM_TYPE_VOID;
	method->data.native_method->ret = &ffi_type_void;
      }
      break;
    }
}

/*
----------------------------------------------------------------------
_svmf_prepare_native_ffi_args
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_native_ffi_args (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_class_loader_info *class_loader =
    method->class_info->class_loader_info;

  _svmf_prepare_native_method_args_count (method);

  if (_svmm_cl_malloc_native_arg_types
      (env, class_loader, method->data.native_method->args_count,
       method->data.native_method->arg_types) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_cl_malloc_native_args
      (env, class_loader, method->data.native_method->args_count,
       method->data.native_method->args) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_cl_zalloc_native_cif
      (env, class_loader, method->data.native_method->cif) != JNI_OK)
    {
      return JNI_ERR;
    }

  _svmf_prepare_native_method_args (method);

  if (ffi_prep_cif
      (method->data.native_method->cif, FFI_DEFAULT_ABI,
       method->data.native_method->args_count,
       method->data.native_method->ret,
       method->data.native_method->args) != FFI_OK)
    {
      _svmf_error_InternalError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bind_native_method
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bind_native_method (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_native_library *native_library =
    method->class_info->class_loader_info->native_library_list;
  jboolean monitor_acquired = JNI_FALSE;

  if (_svmf_enter_object_monitor (env, *(method->class_info->class_instance))
      != JNI_OK)
    {
      goto error;
    }

  monitor_acquired = JNI_TRUE;

  /* process native libraries in loading order */
  while (native_library != NULL)
    {
      if (native_library->handle != NULL)
	{
	  /* try short name */
	  method->data.native_method->code = SVM_CAST_EXTENSION
	    (void (*)(void)) lt_dlsym (native_library->handle,
				       method->data.native_method->
				       short_name);

	  if (method->data.native_method->code != NULL)
	    {
	      break;
	    }

	  /* try long name */
	  method->data.native_method->code = SVM_CAST_EXTENSION
	    (void (*)(void)) lt_dlsym (native_library->handle,
				       method->data.native_method->long_name);

	  if (method->data.native_method->code != NULL)
	    {
	      break;
	    }
	}
      else
	{
	  _svmt_internal_method_node *internal_method_node;
	  _svmt_internal_method_node tmp_node =
	    { NULL, NULL, NULL, NULL, NULL };

	  /*try short name */
	  tmp_node.name = method->data.native_method->short_name;

	  internal_method_node =
	    _svmm_tree_find_internal_method (vm->class_loading.boot_loader.
					     internal_method_tree, &tmp_node);

	  if (internal_method_node != NULL)
	    {
	      assert (internal_method_node->code != NULL);

	      method->data.native_method->code = internal_method_node->code;
	      break;
	    }

	  /*try long name */
	  tmp_node.name = method->data.native_method->long_name;

	  internal_method_node =
	    _svmm_tree_find_internal_method (vm->class_loading.boot_loader.
					     internal_method_tree, &tmp_node);

	  if (internal_method_node != NULL)
	    {
	      assert (internal_method_node->code != NULL);

	      method->data.native_method->code = internal_method_node->code;
	      break;
	    }

	  method->data.native_method->code = NULL;
	}

      native_library = native_library->next;
    }

  if (method->data.native_method->code == NULL)
    {
      /* method not found */

      jstring function_name;

      if (_svmm_new_native_local (env, function_name) != JNI_OK)
	{
	  goto error;
	}

      if (_svmf_get_string
	  (env, method->data.native_method->long_name,
	   function_name) != JNI_OK)
	{
	  _svmm_free_native_local (env, function_name);
	  goto error;
	}

      /* Highly useful, when all you see is java/lang/UnsatisfiedLinkError. */
      if (vm->verbose_jni)
	{
	  _svmf_printf (env, stderr,
			"[verbose jni: Unable to link native method %s]\n",
			method->data.native_method->short_name);
	}

      _svmf_error_UnsatisfiedLinkError_msg (env, function_name);

      _svmm_free_native_local (env, function_name);

      {
	/* pop frame */
	_svmt_stack_frame *frame = env->stack.current_frame;

	env->stack.current_frame =
	  (_svmt_stack_frame *) (void *) (((char *) frame) -
					  frame->previous_offset);
      }

      goto error;
    }

  if (_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
    {
      method->frame_info->code =
	&vm->instructions[SVM_INSTRUCTION_NATIVE_STATIC_METHOD].code;
    }
  else
    {
      method->frame_info->code =
	&vm->instructions[SVM_INSTRUCTION_NATIVE_NONSTATIC_METHOD].code;
    }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env, *(method->class_info->class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_invoke_native_static
----------------------------------------------------------------------
*/

svm_static jint
_svmf_invoke_native_static (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  _svmt_JavaVM *vm = env->vm;
#endif

  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_method_info *method = frame->method;
  _svmt_method_frame_info *frame_info = method->frame_info;
  _svmt_stack_value *params =
    (_svmt_stack_value *) (void *) (((char *) frame) -
				    frame_info->start_offset);
  void **ptrs =
    (void **) &params[method->data.native_method->java_args_and_ret_count];
  jint param = 0;
  jint args_count = method->data.native_method->args_count;
  jint *args = method->data.native_method->arg_types;
  void *nullvar = NULL;

  jint i;
  _svmt_stack_native_reference *lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame_info->end_offset);
  jint ref = 0;

  {
    jint lrefs_count =
      method->data.native_method->refargs_count + SVM_FRAME_NATIVE_REFS_MIN;
    size_t lrefs_size =
      _svmf_aligned_size_t ((lrefs_count +
			     2) * sizeof (_svmt_stack_native_reference));

    lrefs[-1].jint = lrefs_count;
    lrefs[-2].size_t = lrefs_size;

    lrefs =
      (_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						 lrefs_size);

    for (i = 0; i < lrefs_count; i++)
      {
	if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	  {
	    goto end;
	  }
      }
  }


#ifndef NDEBUG

  {
    /* check argument types */

    jint arg_count = method->java_args_count;
    const char *pdesc = DREF (method->descriptor, value) + 1;
    jint arg = 0;

    while (arg < arg_count)
      {
	jint old_arg = arg;

	if (params[old_arg].reference != NULL)
	  {
	    _svmt_type_info *t =
	      _svmm_get_type_from_within_descriptor (env, method, pdesc, arg);

	    if (t != NULL)
	      {
		if (!_svmf_is_assignable_from
		    (env, params[old_arg].reference->vtable->type, t))
		  {
		    _svmf_dump_stack_trace (env);
		    _svmm_fatal_error ("argument type bug detected");
		  }
	      }
	  }
	else
	  {
	    _svmm_skip_type_within_descriptor (pdesc, arg);
	  }
      }
  }

#endif


  /* time to initialize ptrs array */
  assert (ref == 0);
  assert (param == 0);

  /* env */
  ptrs[0] = &env;

  /* class */
  *(lrefs[ref].jobject) = *(method->class_info->class_instance);
  ptrs[1] = &lrefs[ref++];

  for (i = 2; i < args_count; i++)
    {
      switch (args[i])
	{
	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;

	case SVM_TYPE_BOOLEAN:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jboolean *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_BYTE:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jbyte *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_SHORT:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jshort *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_CHAR:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jchar *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_INT:
	case SVM_TYPE_FLOAT:
	  {
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_REFERENCE:
	  {
	    *(lrefs[ref].jobject) = params[param++].reference;

	    if (*(lrefs[ref].jobject) !=NULL)
	      {
		ptrs[i] = &lrefs[ref++];
	      }
	    else
	      {
		/* JNI function should receive NULL instead of a
		   pointer to NULL */
		ptrs[i] = &nullvar;
	      }
	  }
	  break;

	case SVM_TYPE_LONG:
	case SVM_TYPE_DOUBLE:
	  {
	    ptrs[i] = &params[param];
	    param += 2;
	  }
	  break;
	}
    }

  /* going native */
  _svmm_stopping_java (env);

  {
    _svmt_stack_value result[2];

    /* do the call */
    ffi_call (method->data.native_method->cif,
	      method->data.native_method->code, &result, ptrs);

    /* coming back */
    _svmm_resuming_java (env);

    /* retrieve current frame */
    frame = env->stack.current_frame;

    assert (frame->method == method);

#if !defined(NDEBUG)

    if (env->vm->verbose_methods)
      {
	_svmf_printf (env, stderr,
		      "[verbose methods: exiting  method %s.%s%s]\n",
		      method->class_info->name, DREF (method->name, value),
		      DREF (method->descriptor, value));

	{
	  _svmt_method_info *caller_method;
	  _svmt_stack_frame *caller_frame = env->stack.current_frame;
	  caller_frame = (_svmt_stack_frame *) (void *)
	    (((char *) caller_frame) - caller_frame->previous_offset);
	  caller_method = caller_frame->method;

	  while (_svmf_is_set_flag
		 (caller_method->access_flags, SVM_ACC_INTERNAL)
		 && caller_method != &vm->stack_bottom_method)
	    {
	      caller_frame = (_svmt_stack_frame *) (void *)
		(((char *) caller_frame) - caller_frame->previous_offset);
	      caller_method = caller_frame->method;
	    }

	  if (!_svmf_is_set_flag
	      (caller_method->access_flags, SVM_ACC_INTERNAL))
	    {
	      _svmf_printf (env, stderr,
			    "[                   returning to %s.%s%s]\n",
			    caller_method->class_info->name,
			    DREF (caller_method->name, value),
			    DREF (caller_method->descriptor, value));
	    }
	}
      }

#endif

    /* if no exception was thrown */
    if (*(env->throwable) == NULL)
      {
	/* retrieve and store return value */
	params =
	  (_svmt_stack_value *) (void *) (((char *) frame) -
					  frame_info->start_offset);

	/* point "frame" at caller frame */
	frame =
	  (_svmt_stack_frame *) (void *) (((char *) frame) -
					  frame->previous_offset);

	switch (method->data.native_method->ret_type)
	  {
	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;

	  case SVM_TYPE_VOID:
	    {
	    }
	    break;

	  case SVM_TYPE_BOOLEAN:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jboolean) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jboolean *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_BYTE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jbyte) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jbyte *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_SHORT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jshort) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jshort *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_CHAR:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jchar) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jchar *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_INT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jint) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = result[0].jint;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_FLOAT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jfloat) < sizeof (_svmt_float_word))
		{
		  params[0].jfloat =
		    (jfloat) *((_svmt_float_word *) &result[0]);
		}
	      else
		{
		  params[0].jfloat = result[0].jfloat;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_REFERENCE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      jobject obj;

	      if (sizeof (jobject) < sizeof (_svmt_word))
		{
		  obj = (jobject) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  obj = *((jobject *) &result[0]);
		}


#ifndef NDEBUG

	      if (obj != NULL)
		{
		  /* check return value type */

		  const char *pdesc = DREF (method->descriptor, value) + 1;
		  jint arg = 0;
		  _svmt_type_info *t;

		  while (*pdesc++ != ')');

		  t =
		    _svmm_get_type_from_within_descriptor (env, method, pdesc,
							   arg);

		  assert (t != NULL);

		  if (*obj == NULL || !_svmf_is_assignable_from
		      (env, (*obj)->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}

#endif

	      if (obj != NULL)
		{
		  params[0].reference = *obj;
		}
	      else
		{
		  params[0].reference = NULL;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_LONG:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      /* Of course, this test is only useful for a 128bit platform ;-) */
	      if (sizeof (jlong) < sizeof (_svmt_word))
		{
		  *((jlong *) (void *) &params[0]) =
		    (jlong) *((_svmt_word *) (void *) &result[0]);
		}
	      else
		{
		  *((jlong *) (void *) &params[0]) =
		    *((jlong *) (void *) &result[0]);
		}

	      frame->stack_size += 2;
	    }
	    break;

	  case SVM_TYPE_DOUBLE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      /* Of course, this test is only useful for a 128bit platform ;-) */
	      if (sizeof (jdouble) < sizeof (_svmt_float_word))
		{
		  *((jdouble *) (void *) &params[0]) =
		    (jdouble) *((_svmt_float_word *) (void *) &result[0]);
		}
	      else
		{
		  *((jdouble *) (void *) &params[0]) =
		    *((jdouble *) (void *) &result[0]);
		}

	      frame->stack_size += 2;
	    }
	    break;
	  }
      }
  }

end:
  /* point "frame" at current frame */
  frame = env->stack.current_frame;

  /* free native local frames */
  lrefs = (_svmt_stack_native_reference *) (void *)
    (((char *) frame) + frame->end_offset);

  while (lrefs > ((_svmt_stack_native_reference *) (void *)
		  (((char *) frame) + _svmv_stack_offset)))
    {
      jint lrefs_count = lrefs[-1].jint;
      size_t lrefs_size = lrefs[-2].size_t;

      lrefs = (_svmt_stack_native_reference *) (void *)
	(((char *) lrefs) - lrefs_size);

      for (i = 0; i < lrefs_count; i++)
	{
	  if (lrefs[i].jobject !=NULL)
	    {
	      _svmm_free_native_local (env, lrefs[i].jobject);
	    }
	}
    }

  /* pop frame */
  env->stack.current_frame =
    (_svmt_stack_frame *) (void *) (((char *) frame) -
				    frame->previous_offset);

  /* is method synchronized? */
  if (method->synchronized)
    {
      /* release monitor */
      if (_svmf_exit_object_monitor (env, frame->this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_invoke_native_nonstatic
----------------------------------------------------------------------
*/

svm_static jint
_svmf_invoke_native_nonstatic (_svmt_JNIEnv *env)
{
#ifndef NDEBUG
  _svmt_JavaVM *vm = env->vm;

#endif
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_method_info *method = frame->method;
  _svmt_method_frame_info *frame_info = method->frame_info;
  _svmt_stack_value *params =
    (_svmt_stack_value *) (void *) (((char *) frame) -
				    frame_info->start_offset);
  void **ptrs =
    (void **) &params[method->data.native_method->java_args_and_ret_count];
  jint param = 0;
  jint args_count = method->data.native_method->args_count;
  jint *args = method->data.native_method->arg_types;
  void *nullvar = NULL;

  jint i;
  _svmt_stack_native_reference *lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame_info->end_offset);
  jint ref = 0;

  {
    jint lrefs_count =
      method->data.native_method->refargs_count + SVM_FRAME_NATIVE_REFS_MIN;
    size_t lrefs_size =
      _svmf_aligned_size_t ((lrefs_count +
			     2) * sizeof (_svmt_stack_native_reference));

    lrefs[-1].jint = lrefs_count;
    lrefs[-2].size_t = lrefs_size;

    lrefs =
      (_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						 lrefs_size);

    for (i = 0; i < lrefs_count; i++)
      {
	if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	  {
	    goto end;
	  }
      }
  }

#ifndef NDEBUG

  {
    /* check argument types */

    jint arg_count = method->java_args_count;
    const char *pdesc = DREF (method->descriptor, value) + 1;
    jint arg = 0;

    while (arg < arg_count)
      {
	jint old_arg = arg;

	if (params[old_arg].reference != NULL)
	  {
	    _svmt_type_info *t;

	    if (old_arg == 0)
	      {
		t = _svmf_cast_type_class (method->class_info);
		arg++;
	      }
	    else
	      {
		t =
		  _svmm_get_type_from_within_descriptor (env, method, pdesc,
							 arg);
	      }

	    if (t != NULL)
	      {
		if (!_svmf_is_assignable_from
		    (env, params[old_arg].reference->vtable->type, t))
		  {
		    _svmf_dump_stack_trace (env);
		    _svmm_fatal_error ("argument type bug detected");
		  }
	      }
	  }
	else
	  {
	    assert (old_arg != 0);

	    _svmm_skip_type_within_descriptor (pdesc, arg);
	  }
      }
  }

#endif

  /* time to initialize ptrs array */
  assert (ref == 0);
  assert (param == 0);

  /* env */
  ptrs[0] = &env;

  /* this */
  assert (params[0].reference != NULL);
  *(lrefs[ref].jobject) = params[param++].reference;
  ptrs[1] = &lrefs[ref++];

  for (i = 2; i < args_count; i++)
    {
      switch (args[i])
	{
	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;

	case SVM_TYPE_BOOLEAN:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jboolean *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_BYTE:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jbyte *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_SHORT:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jshort *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_CHAR:
	  {
	    /* don't forget about little/big endian alignment */
	    *((jchar *) &params[param]) = params[param].jint;
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_INT:
	case SVM_TYPE_FLOAT:
	  {
	    ptrs[i] = &params[param++];
	  }
	  break;

	case SVM_TYPE_REFERENCE:
	  {
	    *(lrefs[ref].jobject) = params[param++].reference;

	    if (*(lrefs[ref].jobject) !=NULL)
	      {
		ptrs[i] = &lrefs[ref++];
	      }
	    else
	      {
		/* JNI function should receive NULL instead of a
		   pointer to NULL */
		ptrs[i] = &nullvar;
	      }
	  }
	  break;

	case SVM_TYPE_LONG:
	case SVM_TYPE_DOUBLE:
	  {
	    ptrs[i] = &params[param];
	    param += 2;
	  }
	  break;
	}
    }


  /* going native */
  _svmm_stopping_java (env);

  {
    _svmt_stack_value result[2];

    /* do the call */
    ffi_call (method->data.native_method->cif,
	      method->data.native_method->code, &result, ptrs);

    /* coming back */
    _svmm_resuming_java (env);

    /* retrieve current frame */
    frame = env->stack.current_frame;

    assert (frame->method == method);

#if !defined(NDEBUG)

    if (env->vm->verbose_methods)
      {
	_svmf_printf (env, stderr,
		      "[verbose methods: exiting  method %s.%s%s]\n",
		      method->class_info->name, DREF (method->name, value),
		      DREF (method->descriptor, value));

	{
	  _svmt_method_info *caller_method;
	  _svmt_stack_frame *caller_frame = env->stack.current_frame;
	  caller_frame = (_svmt_stack_frame *) (void *)
	    (((char *) caller_frame) - caller_frame->previous_offset);
	  caller_method = caller_frame->method;

	  while (_svmf_is_set_flag
		 (caller_method->access_flags, SVM_ACC_INTERNAL)
		 && caller_method != &vm->stack_bottom_method)
	    {
	      caller_frame = (_svmt_stack_frame *) (void *)
		(((char *) caller_frame) - caller_frame->previous_offset);
	      caller_method = caller_frame->method;
	    }

	  if (!_svmf_is_set_flag
	      (caller_method->access_flags, SVM_ACC_INTERNAL))
	    {
	      _svmf_printf (env, stderr,
			    "[                   returning to %s.%s%s]\n",
			    caller_method->class_info->name,
			    DREF (caller_method->name, value),
			    DREF (caller_method->descriptor, value));
	    }
	}
      }

#endif

    /* if no exception was thrown */
    if (*(env->throwable) == NULL)
      {
	/* retrieve and store return value */
	params =
	  (_svmt_stack_value *) (void *) (((char *) frame) -
					  frame_info->start_offset);

	/* point "frame" at caller frame */
	frame =
	  (_svmt_stack_frame *) (void *) (((char *) frame) -
					  frame->previous_offset);

	switch (method->data.native_method->ret_type)
	  {
	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;

	  case SVM_TYPE_VOID:
	    {
	    }
	    break;

	  case SVM_TYPE_BOOLEAN:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jboolean) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jboolean *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_BYTE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jbyte) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jbyte *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_SHORT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jshort) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jshort *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_CHAR:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jchar) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = *((jchar *) &result[0]);
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_INT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jint) < sizeof (_svmt_word))
		{
		  params[0].jint = (jint) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  params[0].jint = result[0].jint;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_FLOAT:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      if (sizeof (jfloat) < sizeof (_svmt_float_word))
		{
		  params[0].jfloat =
		    (jfloat) *((_svmt_float_word *) &result[0]);
		}
	      else
		{
		  params[0].jfloat = result[0].jfloat;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_REFERENCE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      jobject obj;

	      if (sizeof (jobject) < sizeof (_svmt_word))
		{
		  obj = (jobject) *((_svmt_word *) &result[0]);
		}
	      else
		{
		  obj = *((jobject *) &result[0]);
		}

#ifndef NDEBUG

	      if (obj != NULL)
		{
		  /* check return value type */

		  const char *pdesc = DREF (method->descriptor, value) + 1;
		  jint arg = 0;
		  _svmt_type_info *t;

		  while (*pdesc++ != ')');

		  t =
		    _svmm_get_type_from_within_descriptor (env, method, pdesc,
							   arg);

		  assert (t != NULL);

		  if (*obj == NULL || !_svmf_is_assignable_from
		      (env, (*obj)->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
#endif

	      if (obj != NULL)
		{
		  params[0].reference = *obj;
		}
	      else
		{
		  params[0].reference = NULL;
		}

	      frame->stack_size++;
	    }
	    break;

	  case SVM_TYPE_LONG:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      /* Of course, this test is only useful for a 128bit platform ;-) */
	      if (sizeof (jlong) < sizeof (_svmt_word))
		{
		  *((jlong *) (void *) &params[0]) =
		    (jlong) *((_svmt_word *) (void *) &result[0]);
		}
	      else
		{
		  *((jlong *) (void *) &params[0]) =
		    *((jlong *) (void *) &result[0]);
		}

	      frame->stack_size += 2;
	    }
	    break;

	  case SVM_TYPE_DOUBLE:
	    {
	      /* a) don't forget about little/big endian alignment */
	      /* b) smallest return value = word */

	      /* Hopefully, this conditional will be removed by the
	         optimizing compiler */

	      /* Of course, this test is only useful for a 128bit platform ;-) */
	      if (sizeof (jdouble) < sizeof (_svmt_float_word))
		{
		  *((jdouble *) (void *) &params[0]) =
		    (jdouble) *((_svmt_float_word *) (void *) &result[0]);
		}
	      else
		{
		  *((jdouble *) (void *) &params[0]) =
		    *((jdouble *) (void *) &result[0]);
		}

	      frame->stack_size += 2;
	    }
	    break;
	  }
      }
  }

end:
  /* point "frame" at current frame */
  frame = env->stack.current_frame;

  /* free native local frames */
  lrefs = (_svmt_stack_native_reference *) (void *)
    (((char *) frame) + frame->end_offset);

  while (lrefs > ((_svmt_stack_native_reference *) (void *)
		  (((char *) frame) + _svmv_stack_offset)))
    {
      jint lrefs_count = lrefs[-1].jint;
      size_t lrefs_size = lrefs[-2].size_t;

      lrefs = (_svmt_stack_native_reference *) (void *)
	(((char *) lrefs) - lrefs_size);

      for (i = 0; i < lrefs_count; i++)
	{
	  if (lrefs[i].jobject !=NULL)
	    {
	      _svmm_free_native_local (env, lrefs[i].jobject);
	    }
	}
    }

  /* pop frame */
  env->stack.current_frame =
    (_svmt_stack_frame *) (void *) (((char *) frame) -
				    frame->previous_offset);

  /* is method synchronized? */
  if (method->synchronized)
    {
      /* release monitor */
      if (_svmf_exit_object_monitor (env, frame->this) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;
}
