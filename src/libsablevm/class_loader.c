/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_resolve_super_interfaces
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_super_interfaces (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  jint i;

  assert (class->class_loader_info->class_loader != NULL);

  for (i = 0; i < class->interfaces_count; i++)
    {
      _svmt_CONSTANT_Class_info **cp_super_interface = class->interfaces[i];

      if (CANNOT_DREF (cp_super_interface) ||
	  DREF (cp_super_interface, tag) != SVM_CONSTANT_Class ||
	  CANNOT_DREF (DREF (cp_super_interface, name)) ||
	  DREF (DREF (cp_super_interface, name), tag) != SVM_CONSTANT_Utf8 ||
	  DREF (DREF (cp_super_interface, name), value)[0] == '[')
	{
	  _svmf_error_ClassFormatError (env);
	  return JNI_ERR;
	}

      if (_svmf_resolve_CONSTANT_Class (env, class, *cp_super_interface) !=
	  JNI_OK)
	{
	  return JNI_ERR;
	}

      assert (!(DREF (cp_super_interface, type)->is_array));

      if (!_svmf_is_interface
	  (_svmf_cast_class (DREF (cp_super_interface, type))))
	{
	  _svmf_error_IncompatibleClassChangeError (env);
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_resolve_super_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_resolve_super_class (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_CONSTANT_Class_info **cp_super_class = class->super_class;

  assert (class->class_loader_info->class_loader != NULL);

  /* must have a super class */
  if (CANNOT_DREF (cp_super_class))
    {
      _svmf_error_VerifyError (env);
      return JNI_ERR;
    }

  if (DREF (cp_super_class, tag) != SVM_CONSTANT_Class ||
      CANNOT_DREF (DREF (cp_super_class, name)) ||
      DREF (DREF (cp_super_class, name), tag) != SVM_CONSTANT_Utf8 ||
      DREF (DREF (cp_super_class, name), value)[0] == '[')
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  if (_svmf_resolve_CONSTANT_Class (env, class, *cp_super_class) != JNI_OK)
    {
      return JNI_ERR;
    }

  assert (!(DREF (cp_super_class, type)->is_array));

  if (_svmf_is_interface (class) &&
      DREF (cp_super_class, type) !=
      _svmf_cast_type_class (vm->class_loading.boot_loader.classes.jlobject))
    {
      _svmf_error_IncompatibleClassChangeError (env);
      return JNI_ERR;
    }

  if (_svmf_is_interface (_svmf_cast_class (DREF (cp_super_class, type))))
    {
      _svmf_error_IncompatibleClassChangeError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_resolve_super_interfaces
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_resolve_super_interfaces (_svmt_JNIEnv *env,
				       _svmt_class_info *class)
{
  _svmt_JavaVM *vm = env->vm;
  jint i;

  assert (class->class_loader_info->class_loader == NULL);

  for (i = 0; i < class->interfaces_count; i++)
    {
      _svmt_CONSTANT_Class_info **cp_super_interface = class->interfaces[i];

      if (CANNOT_DREF (cp_super_interface) ||
	  DREF (cp_super_interface, tag) != SVM_CONSTANT_Class ||
	  CANNOT_DREF (DREF (cp_super_interface, name)) ||
	  DREF (DREF (cp_super_interface, name), tag) != SVM_CONSTANT_Utf8 ||
	  DREF (DREF (cp_super_interface, name), value)[0] == '[')
	{
	  _svmf_error_ClassFormatError (env);
	  return JNI_ERR;
	}

      {
	_svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };

	type.name = DREF (DREF (cp_super_interface, name), value);

	if (_svmm_tree_find_type
	    (vm->class_loading.boot_loader.partially_derived_type_tree,
	     &type) != NULL)
	  {
	    _svmf_error_ClassCircularityError (env);
	    return JNI_ERR;
	  }
      }

      if (_svmf_resolve_CONSTANT_Class (env, class, *cp_super_interface) !=
	  JNI_OK)
	{
	  return JNI_ERR;
	}

      assert (!(DREF (cp_super_interface, type)->is_array));

      if (!_svmf_is_interface
	  (_svmf_cast_class (DREF (cp_super_interface, type))))
	{
	  _svmf_error_IncompatibleClassChangeError (env);
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_resolve_super_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_resolve_super_class (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_CONSTANT_Class_info **cp_super_class = class->super_class;

  assert (class->class_loader_info->class_loader == NULL);

  /* no super class -> we're done */
  if (CANNOT_DREF (cp_super_class))
    {
      /* this must be "java/lang/Object" */
      /* and it must be a public non-abstract non-final class */
      if (strcmp (class->name, "java/lang/Object") != 0 ||
	  class->class_loader_info->class_loader != NULL ||
	  (!_svmf_is_set_flag (class->access_flags, SVM_ACC_PUBLIC)) ||
	  _svmf_is_set_flag (class->access_flags, SVM_ACC_FINAL) ||
	  _svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE) ||
	  _svmf_is_set_flag (class->access_flags, SVM_ACC_ABSTRACT))
	{
	  _svmf_error_VerifyError (env);
	  return JNI_ERR;
	}

      return JNI_OK;
    }

  if (DREF (cp_super_class, tag) != SVM_CONSTANT_Class ||
      CANNOT_DREF (DREF (cp_super_class, name)) ||
      DREF (DREF (cp_super_class, name), tag) != SVM_CONSTANT_Utf8 ||
      DREF (DREF (cp_super_class, name), value)[0] == '[')
    {
      _svmf_error_ClassFormatError (env);
      return JNI_ERR;
    }

  {
    _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };

    type.name = DREF (DREF (cp_super_class, name), value);

    if (_svmm_tree_find_type
	(vm->class_loading.boot_loader.partially_derived_type_tree,
	 &type) != NULL)
      {
	_svmf_error_ClassCircularityError (env);
	return JNI_ERR;
      }
  }

  if (_svmf_resolve_CONSTANT_Class (env, class, *cp_super_class) != JNI_OK)
    {
      return JNI_ERR;
    }

  assert (!(DREF (cp_super_class, type)->is_array));

  if (_svmf_is_interface (class) &&
      DREF (cp_super_class, type) !=
      _svmf_cast_type_class (vm->class_loading.boot_loader.classes.jlobject))
    {
      _svmf_error_IncompatibleClassChangeError (env);
      return JNI_ERR;
    }

  if (_svmf_is_interface (_svmf_cast_class (DREF (cp_super_class, type))))
    {
      _svmf_error_IncompatibleClassChangeError (env);
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_derive_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_derive_class (_svmt_JNIEnv *env,
			   const char *class_name,
			   _svmt_class_file *class_file,
			   _svmt_class_info **pclass, jboolean free_bytes)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_class_info *class;

  /* has the boot loader been recorded as an initiating loader of "name"? */
  {
    _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };

    type.name = class_name;

    if (_svmm_tree_find_type
	(vm->class_loading.boot_loader.initiated_type_tree, &type) != NULL)
      {
	/* yes it has! */
	_svmf_error_LinkageError (env);
	return JNI_ERR;
      }
  }

  /* parse the bytes */
  if (_svmm_parse_class_file
      (env, vm->class_loading.boot_loader.class_loader_info,
       class_file->length, class_file->bytes, class) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* were're done with the bytes, so free them to allow recursive calls */
  if (free_bytes && (class_file->free_bytes_after_use == JNI_TRUE))
    {
      _svmm_gmfree_ubytes (class_file->bytes);
      class_file->length = 0;
    }
  else
    {
      class_file->bytes = NULL;
      class_file->length = 0;
    }

  /* check version and name */
  if (!(class->major_version >= 45 && class->major_version <= 48))
    {
      _svmf_error_UnsupportedClassVersionError (env);
      return JNI_ERR;
    }

  if (strcmp (class_name, class->name) != 0)
    {
      _svmf_error_NoClassDefFoundError (env);
      return JNI_ERR;
    }

  {
    _svmt_type_node *partially_derived_type;

    if (_svmm_gzalloc_type_node (env, partially_derived_type) != JNI_OK)
      {
	return JNI_ERR;
      }

    partially_derived_type->name = class->name;
    partially_derived_type->type = _svmf_cast_type_class (class);

    _svmm_tree_insert_type (vm->class_loading.boot_loader.
			    partially_derived_type_tree,
			    partially_derived_type);
  }

  if (_svmf_bootcl_resolve_super_class (env, class)
      != JNI_OK ||
      _svmf_bootcl_resolve_super_interfaces (env, class) != JNI_OK)
    {
      _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };
      _svmt_type_node *partially_derived_type;

      type.name = class->name;

      partially_derived_type =
	_svmm_tree_find_type (vm->class_loading.boot_loader.
			      partially_derived_type_tree, &type);
      _svmm_tree_remove_type (vm->class_loading.boot_loader.
			      partially_derived_type_tree,
			      partially_derived_type);

      assert (partially_derived_type->type == _svmf_cast_type_class (class));

      _svmm_gzfree_type_node (partially_derived_type);

      return JNI_ERR;
    }

  if (vm->class_loading.boot_loader.classes.jlclass != NULL)
    {
      if (_svmf_new_class_pd
	  (env, _svmf_cast_type_class (class),
	   class->protection_domain) != JNI_OK)
	{
	  _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };
	  _svmt_type_node *partially_derived_type;

	  type.name = class->name;

	  partially_derived_type =
	    _svmm_tree_find_type (vm->class_loading.boot_loader.
				  partially_derived_type_tree, &type);
	  _svmm_tree_remove_type (vm->class_loading.boot_loader.
				  partially_derived_type_tree,
				  partially_derived_type);

	  assert (partially_derived_type->type ==
		  _svmf_cast_type_class (class));

	  _svmm_gzfree_type_node (partially_derived_type);

	  return JNI_ERR;
	}
    }

  {
    _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };
    _svmt_type_node *derived_type;

    type.name = class->name;

    derived_type =
      _svmm_tree_find_type (vm->class_loading.boot_loader.
			    partially_derived_type_tree, &type);
    _svmm_tree_remove_type (vm->class_loading.boot_loader.
			    partially_derived_type_tree, derived_type);

    assert (derived_type->type == _svmf_cast_type_class (class));

    _svmm_tree_insert_type (vm->class_loading.boot_loader.initiated_type_tree,
			    derived_type);
  }

  *pclass = class;
  return JNI_OK;
}


/*
----------------------------------------------------------------------
_svmf_bootcl_internal_load_zipped_class_file
----------------------------------------------------------------------
*/

svm_static jint
  _svmf_bootcl_internal_load_zipped_class_file
  (_svmt_JNIEnv *env, _svmt_zip_file ** zip_file, const char *class_path,
   const char *class_name, _svmt_class_file *class_file,
   jboolean *free_after_use)
{
  jint result;
  size_t class_file_name_length;
  char *class_file_name;


  assert (zip_file != NULL);

  if (*zip_file == NULL)
    {
      *zip_file = _svmf_zip_file_open (env, class_path);
      if (*zip_file == NULL)
	return JNI_ERR;
    }

  class_file_name_length = strlen (class_name) + sizeof (".class");

  if (_svmm_gmalloc_cchars (env, strlen (class_name) + sizeof (".class"),
			    class_file_name) != JNI_OK)
    return JNI_ERR;

  strcpy (class_file_name, class_name);
  strcat (class_file_name, ".class");

  result = _svmf_zip_get_file_content
    (env, &(class_file->bytes), &(class_file->length), *zip_file,
     class_file_name, free_after_use);

  if (result == ZIP_FILE_FOUND)
    return JNI_OK;

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_internal_load_ondisk_class_file
----------------------------------------------------------------------
*/

svm_static jint
  _svmf_bootcl_internal_load_ondisk_class_file
  (_svmt_JNIEnv *env, const char *class_path,
   const char *class_name, _svmt_class_file *class_file)
{
  int fd;
  struct stat stats;
  void *content;

  {
    size_t path_length =
      strlen (class_path) + sizeof ('/') + strlen (class_name) +
      strlen (".class");
    char *path;

    path = _svmf_malloc (path_length);

    if (path == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	return JNI_ERR;
      }

    strcpy (path, class_path);

    if (path[strlen (path) - 1] != '/')
      {
	strcat (path, "/");
      }

    strcat (path, class_name);
    strcat (path, ".class");

    if ((fd = open (path, O_RDONLY)) == -1)
      {
	_svmf_free (path);
	return JNI_ERR;
      }

    _svmf_free (path);
    path = NULL;
  }

  if (fstat (fd, &stats) == -1)
    {
      close (fd);
      return JNI_ERR;
    }

  class_file->length = stats.st_size;

  /* make sure length > 0 and fits into a "jint" */
  if ((class_file->length <= 0) || (class_file->length != stats.st_size))
    {
      class_file->length = 0;
      close (fd);
      _svmf_error_ClassFormatError (env);

      return JNI_ERR;
    }

  content = mmap (NULL, class_file->length, PROT_READ, MAP_PRIVATE, fd, 0);

  if (content == MAP_FAILED)
    {
      class_file->length = 0;
      close (fd);
      _svmf_error_OutOfMemoryError (env);

      return JNI_ERR;
    }

  if (_svmm_gmalloc_ubytes (env, class_file->length, class_file->bytes) !=
      JNI_OK)
    {
      munmap (content, class_file->length);
      class_file->length = 0;
      close (fd);

      return JNI_ERR;
    }

  memcpy (class_file->bytes, content, class_file->length);

  munmap (content, class_file->length);
  close (fd);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_internal_split_bootcl
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_internal_split_bootcl (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  /*
   * boot.class.path = boot.class.path.prepend + ':'
   *  + boot.class.path + ':' + boot.class.path.append
   */

  {
    jint bootcp_length = 0;

    if (vm->class_loading.boot_loader.boot_class_path_prepend != NULL)
      bootcp_length += strlen
	(vm->class_loading.boot_loader.boot_class_path_prepend);

    if (vm->class_loading.boot_loader.boot_class_path_append != NULL)
      bootcp_length += strlen
	(vm->class_loading.boot_loader.boot_class_path_append);

    if (bootcp_length > 0)
      {

	char *new_boot_class_path = NULL;

	if (vm->class_loading.boot_loader.boot_class_path != NULL)
	  bootcp_length += strlen
	    (vm->class_loading.boot_loader.boot_class_path) + 1;

	bootcp_length += 3;

	if (_svmm_gzmalloc_cchars_no_exception
	    (bootcp_length, new_boot_class_path) != JNI_OK)
	  return JNI_ERR;

	if (vm->class_loading.boot_loader.boot_class_path_prepend != NULL)
	  {
	    strcat (new_boot_class_path,
		    vm->class_loading.boot_loader.boot_class_path_prepend);
	    strcat (new_boot_class_path, ":");
	  }

	if (vm->class_loading.boot_loader.boot_class_path != NULL)
	  strcat (new_boot_class_path,
		  vm->class_loading.boot_loader.boot_class_path);

	if (vm->class_loading.boot_loader.boot_class_path_append != NULL)
	  {
	    strcat (new_boot_class_path, ":");
	    strcat (new_boot_class_path,
		    vm->class_loading.boot_loader.boot_class_path_append);
	  }

	_svmm_gzmfree_cchars_no_exception
	  (vm->class_loading.boot_loader.boot_class_path);
	vm->class_loading.boot_loader.boot_class_path = new_boot_class_path;
      }

    if (vm->class_loading.boot_loader.boot_class_path_prepend != NULL)
      _svmm_gzmfree_cchars_no_exception
	(vm->class_loading.boot_loader.boot_class_path_prepend);

    if (vm->class_loading.boot_loader.boot_class_path_append != NULL)
      _svmm_gzmfree_cchars_no_exception
	(vm->class_loading.boot_loader.boot_class_path_append);
  }

  /* Actually split full boot class path. */
  {
    jint entries_no = 0;
    char *colon_pos, *position;

    position = vm->class_loading.boot_loader.boot_class_path;

    /* count the entries */
    while (*position != 0)
      {
	entries_no++;
	/* Skip multiple ":" */
	while (*position == ':')
	  position++;

	colon_pos = strchr (position, ':');

	if (colon_pos == NULL)
	  break;

	position = ++colon_pos;
      }

    /* allocate needed amount of entries */
    if (JNI_OK != _svmm_gzmalloc_boot_class_path_entry
	(env, entries_no,
	 vm->class_loading.boot_loader.boot_class_path_entries))
      return JNI_ERR;

    /* fill in entries' data */
    {
      _svmt_boot_class_path_entry *entries =
	vm->class_loading.boot_loader.boot_class_path_entries;

      entries_no = 0;
      position = vm->class_loading.boot_loader.boot_class_path;

      while (*position != 0)
	{
	  jint len;
	  struct stat file_stat;

	  entries_no++;

	  /* Skip multiple ":" */
	  while (*position == ':')
	    position++;

	  colon_pos = strchr (position, ':');

	  if (colon_pos == NULL)
	    len = strlen (position);
	  else
	    len = (jint) (colon_pos - position);

	  if (JNI_OK != _svmm_gmalloc_cchars
	      (env, len + 1, entries[entries_no - 1].class_path))
	    {
	      _svmf_error_OutOfMemoryError (env);
	      return JNI_ERR;
	    }

	  memcpy (entries[entries_no - 1].class_path, position, len);

	  entries[entries_no - 1].class_path[len] = 0;

	  /* record whether it is a file or directory */
	  if (stat (entries[entries_no - 1].class_path, &file_stat) != 0)
	    {
	      entries[entries_no - 1].is_valid = JNI_FALSE;
	    }
	  else
	    {
	      entries[entries_no - 1].is_valid = JNI_TRUE;
	      if (S_ISDIR (file_stat.st_mode))
		entries[entries_no - 1].is_file = JNI_FALSE;
	      else
		entries[entries_no - 1].is_file = JNI_TRUE;
	    }

	  entries[entries_no - 1].zip_file = NULL;

	  vm->class_loading.boot_loader.boot_class_path_entries_no =
	    entries_no;

	  if (colon_pos == NULL)
	    break;

	  position = ++colon_pos;
	}
    }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_bootcl_internal_load_class_file
----------------------------------------------------------------------
*/

svm_static jint
_svmh_bootcl_internal_load_class_file (_svmt_JNIEnv *env,
				       const char *class_name,
				       _svmt_class_file *class_file)
{
  _svmt_JavaVM *vm = env->vm;

  /*
   * Traverse boot_class_path_elements try to load the class data.
   *
   * If JNI_ERR was returned then:
   * - *(env->throwable) == NULL means ClassNotFound,
   * - *(env->throwable) != NULL means a serious error had place (like
   *   memory allocation error).
   */
  {
    jint entry_no;
    for (entry_no = 0;
	 entry_no < vm->class_loading.boot_loader.boot_class_path_entries_no;
	 entry_no++)
      {
	_svmt_boot_class_path_entry *entry =
	  &vm->class_loading.boot_loader.boot_class_path_entries[entry_no];

	if (entry->is_valid == JNI_FALSE)
	  continue;

	if (entry->is_file == JNI_FALSE)
	  {			/* directory - look for an uncompressed .class file */
	    if (JNI_OK == _svmf_bootcl_internal_load_ondisk_class_file
		(env, entry->class_path, class_name, class_file))
	      {
		class_file->free_bytes_after_use = JNI_TRUE;
		break;		/* class found! */
	      }
	  }
	else
	  {			/* file - means .jar or .zip usually */
	    if (JNI_OK == _svmf_bootcl_internal_load_zipped_class_file
		(env, &(entry->zip_file), entry->class_path, class_name,
		 class_file, &(class_file->free_bytes_after_use)))
	      break;		/* class found! */
	  }
      }

    if (*(env->throwable) != NULL)
      return JNI_ERR;

    if (entry_no == vm->class_loading.boot_loader.boot_class_path_entries_no)
      {
	/* At bootstrap time  _svmf_error_NoClassDefFoundError never returns.
	   Detect it and try to provide some meaningful message to user. */
	if (vm->initialization != NULL)
	  {
	    _svmf_printf (env, stderr,
			  "*** Fatal error: Unable to load essential class %s.\n",
			  class_name);
	    _svmf_printf (env, stderr,
			  "*** Most probably it was not found on boot classpath:\n");
	    _svmf_printf (env, stderr, "*** %s\n",
			  vm->class_loading.boot_loader.boot_class_path);
	  }

	_svmf_error_NoClassDefFoundError (env);

	return JNI_ERR;
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_get_resource_url
----------------------------------------------------------------------
*/

svm_static char *
_svmf_bootcl_get_resource_url (_svmt_JNIEnv *env, const char *res_name)
{
  _svmt_JavaVM *vm = env->vm;

  {
    jint entry_no;

    if (res_name[0] == '/')
      res_name++;

    for (entry_no = 0;
	 entry_no < vm->class_loading.boot_loader.boot_class_path_entries_no;
	 entry_no++)
      {
	_svmt_boot_class_path_entry *entry =
	  &vm->class_loading.boot_loader.boot_class_path_entries[entry_no];

	if (entry->is_valid == JNI_FALSE)
	  continue;

	if (entry->is_file == JNI_FALSE)
	  {			/* directory - look for an uncompressed .class file */

	    struct stat stats;
	    size_t path_length = sizeof ("file://") +
	      strlen (entry->class_path) + sizeof ('/') + strlen (res_name);
	    char *path;

	    path = _svmf_malloc (path_length);

	    if (path == NULL)
	      {
		_svmf_error_OutOfMemoryError (env);
		return NULL;
	      }

	    strcpy (path, "file://");
	    strcat (path, entry->class_path);

	    if (path[strlen (path) - 1] != '/')
	      {
		strcat (path, "/");
	      }

	    strcat (path, res_name);

	    if (stat (path + sizeof ("file://") - 1, &stats) == 0)
	      {			/* we found the file! */
		return path;
	      }
	  }
	else
	  {			/* file - means .jar or .zip usually */
	    if (entry->zip_file == NULL)
	      {
		entry->zip_file =
		  _svmf_zip_file_open (env, entry->class_path);
		if (entry->zip_file == NULL)
		  continue;
	      }

	    if (_svmf_zip_file_exists (env, entry->zip_file, res_name) ==
		JNI_TRUE)
	      {

		size_t path_length = sizeof ("jar:file://") +
		  strlen (entry->class_path) + sizeof ("!/") +
		  strlen (res_name);
		char *path;

		path = _svmf_malloc (path_length);

		if (path == NULL)
		  {
		    _svmf_error_OutOfMemoryError (env);
		    return NULL;
		  }

		strcpy (path, "jar:file://");
		strcat (path, entry->class_path);
		strcat (path, "!/");
		strcat (path, res_name);

		return path;

	      }
	  }

      }
  }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_create_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_create_class (_svmt_JNIEnv *env,
			   const char *class_name, _svmt_class_info **pclass)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_class_file current_class_file;

  _svmm_zero_memory (current_class_file);

  /* has the boot loader been recorded as an initiating loader of "name"? */
  {
    _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };
    _svmt_type_node *result;

    type.name = class_name;

    if ((result =
	 _svmm_tree_find_type (vm->class_loading.boot_loader.
			       initiated_type_tree, &type)) != NULL)
      {
	/* yes it has! */
	*pclass = _svmf_cast_class (result->type);
	return JNI_OK;
      }
  }

  if (vm->verbose_class)
    {
      _svmf_printf (env, stderr, "[verbose class: loading \"%s\"]\n",
		    class_name);
    }

  assert (current_class_file.bytes == NULL);

  if (_svmm_bootcl_internal_load_class_file
      (env, class_name, current_class_file) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_bootcl_derive_class
      (env, class_name, &current_class_file, pclass, JNI_TRUE) != JNI_OK)
    {
      if ((current_class_file.bytes != NULL) &&
	  (current_class_file.free_bytes_after_use == JNI_TRUE))
	{
	  _svmm_gmfree_ubytes (current_class_file.bytes);
	  current_class_file.length = 0;
	}

      return JNI_ERR;
    }

  if ((current_class_file.bytes != NULL) &&
      (current_class_file.free_bytes_after_use == JNI_TRUE))
    {
      _svmm_gmfree_ubytes (current_class_file.bytes);
      current_class_file.length = 0;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_usercl_create_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_usercl_create_class (_svmt_JNIEnv *env,
			   _svmt_class_loader_info *class_loader_info,
			   const char *class_name, _svmt_class_info **pclass)
{
  jobject class_instance;
  jobject name;

  if (_svmm_new_native_local (env, class_instance) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_native_local (env, name) != JNI_OK)
    {
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  if (_svmf_get_string (env, class_name, name) != JNI_OK)
    {
      _svmm_free_native_local (env, name);
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  if (_svmm_invoke_static_virtualmachine_createclass
      (env, class_loader_info->class_loader, name, class_instance) != JNI_OK)
    {
      _svmm_free_native_local (env, name);
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  *pclass =
    _svmf_cast_class (_svmf_unwrap_class_instance (env, class_instance));

  assert (!((*pclass)->is_array));

  _svmm_free_native_local (env, name);
  _svmm_free_native_local (env, class_instance);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_create_class
----------------------------------------------------------------------
*/

svm_static jint
_svmh_create_class (_svmt_JNIEnv *env,
		    _svmt_class_loader_info *class_loader_info,
		    const char *class_name, _svmt_class_info **pclass)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  assert (class_name[0] != '[');

  if (class_loader_info->class_loader != NULL)
    {
      /* user-defined class loader */
      if (_svmf_usercl_create_class (env, class_loader_info, class_name,
				     pclass) != JNI_OK)
	{
	  goto error;
	}
    }
  else
    {
      assert (class_loader_info ==
	      vm->class_loading.boot_loader.class_loader_info);

      /* bootstrap class loader */
      if (_svmf_bootcl_create_class (env, class_name, pclass) != JNI_OK)
	{
	  goto error;
	}
    }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_bootcl_create_array
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootcl_create_array (_svmt_JNIEnv *env,
			   const char *array_name, _svmt_array_info **parray)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_array_info *array;

  /* has the boot loader been recorded as an initiating loader of "name"? */
  {
    _svmt_type_node type = { NULL, NULL, NULL, NULL, NULL };
    _svmt_type_node *result;

    type.name = array_name;

    if ((result =
	 _svmm_tree_find_type (vm->class_loading.boot_loader.
			       initiated_type_tree, &type)) != NULL)
      {
	/* yes it has! */
	*parray = _svmf_cast_array (result->type);
	return JNI_OK;
      }
  }

  if (vm->verbose_class)
    {
      _svmf_printf (env, stderr, "[verbose class: creating \"%s\"]\n",
		    array_name);
    }

  if (_svmm_cl_zalloc_array_info
      (env, vm->class_loading.boot_loader.class_loader_info, array) != JNI_OK)
    {
      return JNI_ERR;
    }

  array->is_array = JNI_TRUE;

  if (_svmm_cl_malloc_chars
      (env, vm->class_loading.boot_loader.class_loader_info,
       strlen (array_name) + 2, array->array_type_name) != JNI_OK)
    {
      return JNI_ERR;
    }

  array->array_type_name[0] = '[';
  array->array_type_name[1] = 0;
  strcat (array->array_type_name, array_name);
  array->name = &array->array_type_name[1];

  {
    char *base_name = array->name;
    jint dimensions = 0;
    size_t length;

    while (*base_name == '[')
      {
	dimensions++;
	base_name++;

	if (dimensions > 255)
	  {
	    _svmf_error_VerifyError (env);
	    return JNI_ERR;
	  }
      }

    assert (dimensions != 0);

    array->dimensions = dimensions;

    if (dimensions > 1)
      {
	if (_svmm_create_array
	    (env, vm->class_loading.boot_loader.class_loader_info,
	     &array->name[1], array->array_element) != JNI_OK)
	  {
	    return JNI_ERR;
	  }
      }

    length = strlen (base_name);

    if (length == 1)
      {
	array->class_loader_info =
	  vm->class_loading.boot_loader.class_loader_info;
	array->access_flags = SVM_ACC_PUBLIC;

	switch (*base_name)
	  {
	  case 'B':
	    {
	      array->base_type = SVM_TYPE_BYTE;
	    }
	    break;

	  case 'C':
	    {
	      array->base_type = SVM_TYPE_CHAR;
	    }
	    break;

	  case 'D':
	    {
	      array->base_type = SVM_TYPE_DOUBLE;
	    }
	    break;

	  case 'F':
	    {
	      array->base_type = SVM_TYPE_FLOAT;
	    }
	    break;

	  case 'I':
	    {
	      array->base_type = SVM_TYPE_INT;
	    }
	    break;

	  case 'J':
	    {
	      array->base_type = SVM_TYPE_LONG;
	    }
	    break;

	  case 'S':
	    {
	      array->base_type = SVM_TYPE_SHORT;
	    }
	    break;

	  case 'Z':
	    {
	      array->base_type = SVM_TYPE_BOOLEAN;
	    }
	    break;

	  default:
	    {
	      _svmf_error_VerifyError (env);
	      return JNI_ERR;
	    }
	    break;
	  }
      }
    else
      {
	if (length < 3 || base_name[0] != 'L' || base_name[length - 1] != ';')
	  {
	    _svmf_error_VerifyError (env);
	    return JNI_ERR;
	  }

	base_name++[length-- - 1] = 0;
	array->base_type = SVM_TYPE_REFERENCE;

	if (_svmm_create_class
	    (env, vm->class_loading.boot_loader.class_loader_info, base_name,
	     array->base_class) != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	if (_svmf_link_class (env, array->base_class) != JNI_OK)
	  {
	    return JNI_ERR;
	  }

	base_name[length - 1] = ';';
	array->class_loader_info = array->base_class->class_loader_info;
	array->access_flags = array->base_class->access_flags;
      }
  }

  if (vm->class_loading.boot_loader.classes.jlclass != NULL)
    {
      if (_svmf_new_class (env, _svmf_cast_type_array (array)) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  {
    _svmt_type_node *derived_type;

    if (_svmm_gzalloc_type_node (env, derived_type) != JNI_OK)
      {
	return JNI_ERR;
      }

    derived_type->name = array->name;
    derived_type->type = _svmf_cast_type_array (array);

    _svmm_tree_insert_type (vm->class_loading.boot_loader.initiated_type_tree,
			    derived_type);
  }

  *parray = array;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_usercl_create_array
----------------------------------------------------------------------
*/

svm_static jint
_svmf_usercl_create_array (_svmt_JNIEnv *env,
			   _svmt_class_loader_info *class_loader_info,
			   const char *array_name, _svmt_array_info **parray)
{
  jobject class_instance;
  jobject name;

  if (_svmm_new_native_local (env, class_instance) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_new_native_local (env, name) != JNI_OK)
    {
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  if (_svmf_get_string (env, array_name, name) != JNI_OK)
    {
      _svmm_free_native_local (env, name);
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  if (_svmm_invoke_static_virtualmachine_createarray
      (env, class_loader_info->class_loader, name, class_instance) != JNI_OK)
    {
      _svmm_free_native_local (env, name);
      _svmm_free_native_local (env, class_instance);
      return JNI_ERR;
    }

  *parray =
    _svmf_cast_array (_svmf_unwrap_class_instance (env, class_instance));

  assert ((*parray)->is_array);

  _svmm_free_native_local (env, name);
  _svmm_free_native_local (env, class_instance);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_create_array
----------------------------------------------------------------------
*/

svm_static jint
_svmh_create_array (_svmt_JNIEnv *env,
		    _svmt_class_loader_info *class_loader_info,
		    const char *array_name, _svmt_array_info **parray)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  if (vm->initialization == NULL)
    {
      if (_svmf_enter_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  assert (array_name[0] == '[');

  if (class_loader_info->class_loader != NULL)
    {
      /* user-defined class loader */
      if (_svmf_usercl_create_array (env, class_loader_info, array_name,
				     parray) != JNI_OK)
	{
	  goto error;
	}
    }
  else
    {
      assert (class_loader_info ==
	      vm->class_loading.boot_loader.class_loader_info);

      /* bootstrap class loader */
      if (_svmf_bootcl_create_array (env, array_name, parray) != JNI_OK)
	{
	  goto error;
	}
    }

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_class_loader_monitor (env, class_loader_info) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmh_create_type
----------------------------------------------------------------------
*/

svm_static jint
_svmh_create_type (_svmt_JNIEnv *env,
		   _svmt_class_loader_info *class_loader_info,
		   const char *type_name, _svmt_type_info **ptype)
{
  if (type_name[0] == '[')
    {
      /* array */
      return _svmm_create_array (env, class_loader_info, type_name,
				 *_svmf_cast_parray (ptype));
    }
  else
    {
      /* nonarray class or interface */
      return _svmm_create_class (env, class_loader_info, type_name,
				 *_svmf_cast_pclass (ptype));
    }
}
