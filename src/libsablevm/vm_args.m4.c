/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */

/*
----------------------------------------------------------------------
m4svm_property_string
----------------------------------------------------------------------
*/

void
dummy ()
{
  if (dummy)

    m4svm_define_begin v = ":], [:m4svm_property_string:])";

  /* m4svm_comment_define([:m4svm_prefix_length:],
   * [:[:m4_len(:]m4svm_lbkt[:-D$:][:1=:]m4svm_rbkt[:):]:]) */
  else if (strncmp ("-D$1=", optstr, m4svm_prefix_length) == 0)
    {
      if ($2 != NULL)
	{
	  _svmm_gfree_str_no_exception ($2);
	}

      if (_svmm_galloc_copy_str_no_exception
	  ($2, &optstr[m4svm_prefix_length]) != JNI_OK)
	{
	  goto error;
	}
    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_property_integer
----------------------------------------------------------------------
*/

void
dummy ()
{
  if (dummy)

    m4svm_define_begin v = ":], [:m4svm_property_integer:])";

  /* m4svm_comment_define([:m4svm_prefix_length:],
   * [:[:m4_len(:]m4svm_lbkt[:-D$:][:1=:]m4svm_rbkt[:):]:]) */
  else if (strncmp ("-D$1=", optstr, m4svm_prefix_length) == 0)
    {
      if (_svmf_parse_size_t (&$2, &optstr[m4svm_prefix_length]) != JNI_OK)
	{
	  goto error;
	}
    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
m4svm_property_boolean
----------------------------------------------------------------------
*/

void
dummy ()
{
  if (dummy)

    m4svm_define_begin v = ":], [:m4svm_property_boolean:])";

  /* m4svm_comment_define([:m4svm_prefix_length:],
   * [:[:m4_len(:]m4svm_lbkt[:-D$:][:1=:]m4svm_rbkt[:):]:]) */
  else if (strncmp ("-D$1=", optstr, m4svm_prefix_length) == 0)
    {
      const char *value = &optstr[m4svm_prefix_length];

      if (strcmp (value, "on") == 0 || strcmp (value, "true") == 0)
	{
	  $2 = JNI_TRUE;
	}
      else if (strcmp (value, "off") == 0 || strcmp (value, "false") == 0)
	{
	  $2 = JNI_FALSE;
	}
      else
	{
	  goto error;
	}
    }
  m4svm_define_end = ":])";
}

/*
----------------------------------------------------------------------
vm_args
----------------------------------------------------------------------
*/

void
dummy ()
{
  /* m4svm_on(0)m4_dnl */

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

  /* boot paths *[::]/
     m4svm_off()

     m4svm_property_string(sablevm.boot.class.path, vm->class_loading.boot_loader.boot_class_path)
     m4svm_property_string(sablevm.boot.class.path.prepend, vm->class_loading.boot_loader.boot_class_path_prepend)
     m4svm_property_string(sablevm.boot.class.path.append, vm->class_loading.boot_loader.boot_class_path_append)
     m4svm_property_string(sablevm.boot.library.path, vm->class_loading.boot_loader.boot_library_path)

     m4svm_on(0)m4_dnl */

  /* structured locking *[::]/
     m4svm_off()

     m4svm_property_boolean(sablevm.structured.locking, vm->enforce_structured_locking)

     m4svm_on(0)m4_dnl */

#if defined (_SABLEVM_NO_GC)

  /* copying heap parameters *[::]/
     m4svm_off()

     m4svm_property_integer(sablevm.heap.size, vm->heap.size)

     m4svm_on(0)m4_dnl */

#elif defined (_SABLEVM_COPY_GC) || defined (_SABLEVM_GENCOPY_GC)

  /* copying heap parameters *[::]/
     m4svm_off()

     m4svm_property_integer(sablevm.heap.size.min, vm->heap.min_size)
     m4svm_property_integer(sablevm.heap.size.max, vm->heap.max_size)
     m4svm_property_integer(sablevm.heap.size.increment, vm->heap.allocation_increment)

     m4svm_on(0)m4_dnl */

#if defined (_SABLEVM_GENCOPY_GC)

  /* genrational copying heap parameters *[::]/
     m4svm_off()

     m4svm_property_integer(sablevm.heap.size.nursery, vm->heap.nursery_size)

     m4svm_on(0)m4_dnl */

#endif /* defined (_SABLEVM_GENCOPY_GC) */
#endif /* defined (_SABLEVM_NO_GC) */

  /* stack and class loader heap parameters *[::]/
     m4svm_off()

     m4svm_property_integer(sablevm.stack.size.min, vm->stack_min_size)
     m4svm_property_integer(sablevm.stack.size.max, vm->stack_max_size)
     m4svm_property_integer(sablevm.stack.size.increment, vm->stack_allocation_increment)
     m4svm_property_integer(sablevm.classloader.heap.size.min, vm->class_loader_min_size)
     m4svm_property_integer(sablevm.classloader.heap.size.max, vm->class_loader_max_size)
     m4svm_property_integer(sablevm.classloader.heap.size.increment, vm->class_loader_allocation_increment)

     m4svm_on(0)m4_dnl */

#if !defined(NDEBUG)

  /* additional verbose options *[::]/
     m4svm_off()

     m4svm_property_boolean(sablevm.verbose.exceptions, vm->verbose_exceptions)
     m4svm_property_boolean(sablevm.verbose.exit, vm->exit_stack_trace)

     m4svm_on(0)m4_dnl */

#endif

#if !defined(NDEBUG) || defined(_SABLEVM_VERBOSE_INSTRUCTIONS_INLINED)

  /* additional verbose options *[::]/
     m4svm_off()

     m4svm_property_boolean(sablevm.verbose.methods, vm->verbose_methods)
     m4svm_property_boolean(sablevm.verbose.instructions, vm->verbose_instructions)
     m4svm_property_boolean(sablevm.verbose.synchronization, vm->verbose_synchronization)

     m4svm_on(0)m4_dnl */

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

  /* end of arguments *[::]/
     m4svm_off() */
}

/* m4svm_on(0)m4_dnl 

m4svm_off() */
