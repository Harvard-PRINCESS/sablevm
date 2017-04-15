/* This file has been automatically generated from "vm_args.m4.c" */

  if (strcmp ("vfprintf", optstr) == 0)
    {
      vm->vfprintf = SVM_CAST_EXTENSION
	(int (*)(FILE *, const char *, va_list)) vm_args->options[i].
	extraInfo;
      if (vm->vfprintf == NULL)
	{
	  goto error;
	}
    }

  else if (strcmp ("exit", optstr) == 0)
    {
      vm->exit =
	SVM_CAST_EXTENSION (void (*)(int)) vm_args->options[i].extraInfo;
      if (vm->exit == NULL)
	{
	  goto error;
	}
    }

  else if (strcmp ("abort", optstr) == 0)
    {
      vm->abort =
	SVM_CAST_EXTENSION (void (*)(void)) vm_args->options[i].extraInfo;
      if (vm->abort == NULL)
	{
	  goto error;
	}
    }

  /* boot paths */
     
  else if (strncmp ("-Dsablevm.boot.class.path=", optstr, 26) == 0)
    {
      if (vm->class_loading.boot_loader.boot_class_path != NULL)
	{
	  _svmm_gfree_str_no_exception (vm->class_loading.boot_loader.boot_class_path);
	}

      if (_svmm_galloc_copy_str_no_exception
	  (vm->class_loading.boot_loader.boot_class_path, &optstr[26]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.boot.class.path.prepend=", optstr, 34) == 0)
    {
      if (vm->class_loading.boot_loader.boot_class_path_prepend != NULL)
	{
	  _svmm_gfree_str_no_exception (vm->class_loading.boot_loader.boot_class_path_prepend);
	}

      if (_svmm_galloc_copy_str_no_exception
	  (vm->class_loading.boot_loader.boot_class_path_prepend, &optstr[34]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.boot.class.path.append=", optstr, 33) == 0)
    {
      if (vm->class_loading.boot_loader.boot_class_path_append != NULL)
	{
	  _svmm_gfree_str_no_exception (vm->class_loading.boot_loader.boot_class_path_append);
	}

      if (_svmm_galloc_copy_str_no_exception
	  (vm->class_loading.boot_loader.boot_class_path_append, &optstr[33]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.boot.library.path=", optstr, 28) == 0)
    {
      if (vm->class_loading.boot_loader.boot_library_path != NULL)
	{
	  _svmm_gfree_str_no_exception (vm->class_loading.boot_loader.boot_library_path);
	}

      if (_svmm_galloc_copy_str_no_exception
	  (vm->class_loading.boot_loader.boot_library_path, &optstr[28]) != JNI_OK)
	{
	  goto error;
	}
    }

  /* structured locking */
     
  else if (strncmp ("-Dsablevm.structured.locking=", optstr, 29) == 0)
    {
      const char *value = &optstr[29];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->enforce_structured_locking = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->enforce_structured_locking = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

#if defined (_SABLEVM_NO_GC)

  /* copying heap parameters */
     
  else if (strncmp ("-Dsablevm.heap.size=", optstr, 20) == 0)
    {
      if (_svmf_parse_size_t (&vm->heap.size, &optstr[20]) != JNI_OK)
	{
	  goto error;
	}
    }

#elif defined (_SABLEVM_COPY_GC) || defined (_SABLEVM_GENCOPY_GC)

  /* copying heap parameters */
     
  else if (strncmp ("-Dsablevm.heap.size.min=", optstr, 24) == 0)
    {
      if (_svmf_parse_size_t (&vm->heap.min_size, &optstr[24]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.heap.size.max=", optstr, 24) == 0)
    {
      if (_svmf_parse_size_t (&vm->heap.max_size, &optstr[24]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.heap.size.increment=", optstr, 30) == 0)
    {
      if (_svmf_parse_size_t (&vm->heap.allocation_increment, &optstr[30]) != JNI_OK)
	{
	  goto error;
	}
    }

#if defined (_SABLEVM_GENCOPY_GC)

  /* genrational copying heap parameters */
     
  else if (strncmp ("-Dsablevm.heap.size.nursery=", optstr, 28) == 0)
    {
      if (_svmf_parse_size_t (&vm->heap.nursery_size, &optstr[28]) != JNI_OK)
	{
	  goto error;
	}
    }

#endif /* defined (_SABLEVM_GENCOPY_GC) */
#endif /* defined (_SABLEVM_NO_GC) */

  /* stack and class loader heap parameters */
     
  else if (strncmp ("-Dsablevm.stack.size.min=", optstr, 25) == 0)
    {
      if (_svmf_parse_size_t (&vm->stack_min_size, &optstr[25]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.stack.size.max=", optstr, 25) == 0)
    {
      if (_svmf_parse_size_t (&vm->stack_max_size, &optstr[25]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.stack.size.increment=", optstr, 31) == 0)
    {
      if (_svmf_parse_size_t (&vm->stack_allocation_increment, &optstr[31]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.classloader.heap.size.min=", optstr, 36) == 0)
    {
      if (_svmf_parse_size_t (&vm->class_loader_min_size, &optstr[36]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.classloader.heap.size.max=", optstr, 36) == 0)
    {
      if (_svmf_parse_size_t (&vm->class_loader_max_size, &optstr[36]) != JNI_OK)
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.classloader.heap.size.increment=", optstr, 42) == 0)
    {
      if (_svmf_parse_size_t (&vm->class_loader_allocation_increment, &optstr[42]) != JNI_OK)
	{
	  goto error;
	}
    }

#if !defined(NDEBUG)

  /* additional verbose options */
     
  else if (strncmp ("-Dsablevm.verbose.exceptions=", optstr, 29) == 0)
    {
      const char *value = &optstr[29];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->verbose_exceptions = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->verbose_exceptions = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.verbose.exit=", optstr, 23) == 0)
    {
      const char *value = &optstr[23];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->exit_stack_trace = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->exit_stack_trace = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

#endif

#if !defined(NDEBUG) || defined(_SABLEVM_VERBOSE_INSTRUCTIONS_INLINED)

  /* additional verbose options */
     
  else if (strncmp ("-Dsablevm.verbose.methods=", optstr, 26) == 0)
    {
      const char *value = &optstr[26];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->verbose_methods = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->verbose_methods = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.verbose.instructions=", optstr, 31) == 0)
    {
      const char *value = &optstr[31];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->verbose_instructions = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->verbose_instructions = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

  else if (strncmp ("-Dsablevm.verbose.synchronization=", optstr, 34) == 0)
    {
      const char *value = &optstr[34];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  vm->verbose_synchronization = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  vm->verbose_synchronization = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }

#endif

  /* generic property */
  else if (strncmp ("-D", optstr, 2) == 0)
    {
      /* check that properties are properly declared */

      const char *first_equal;

      if (strlen (optstr) < 4 || optstr[2] == '=')
	{
	  goto error;
	}

      first_equal = strchr (&optstr[3], '=');

      if (first_equal == NULL)
	{
	  goto error;
	}
    }

  /* verbose */

  else if (strncmp ("-verbose", optstr, 8) == 0)
    {
      const char *start = &optstr[8];
      if (*start == 0)
	{
	  vm->verbose_class = JNI_TRUE;
	  vm->verbose_gc = JNI_TRUE;
	  vm->verbose_jni = JNI_TRUE;
	  start = NULL;
	}
      else if (*(start++) != ':')
	{
	  goto error;
	}

      while (start != NULL)
	{
	  const char *stop = strchr (start, ',');
	  size_t len;

	  if (stop != NULL)
	    {
	      len = stop - start;
	    }
	  else
	    {
	      len = strlen (start);
	    }

	  if (len == 0)
	    {
	      goto error;
	    }

	  if (len == 5 && strncmp (start, "class", len) == 0)
	    {
	      vm->verbose_class = JNI_TRUE;
	    }
	  else if (len == 2 && strncmp (start, "gc", len) == 0)
	    {
	      vm->verbose_gc = JNI_TRUE;
	    }
	  else if (len == 3 && strncmp (start, "jni", len) == 0)
	    {
	      vm->verbose_jni = JNI_TRUE;
	    }
	  else if (!vm_args->ignoreUnrecognized)
	    {
	      goto error;
	    }

	  start = (stop == NULL) ? NULL : (stop + 1);
	}
    }

  else if (!vm_args->ignoreUnrecognized)
    {
      goto error;
    }

  /* save properties */
  if (strncmp ("-D", optstr, 2) == 0)
    {
      if (_svmm_galloc_copy_str_no_exception
	  (vm->class_loading.boot_loader.system_properties.properties
	   [vm->class_loading.boot_loader.system_properties.count],
	   &optstr[2]) != JNI_OK)
	{
	  goto error;
	}

      vm->class_loading.boot_loader.system_properties.count++;
    }

  /* end of arguments */
     
