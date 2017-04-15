/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_nativeGetResource
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeGetResource
 * Signature: (Ljava/lang/String)Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_java_lang_VMClassLoader_nativeGetResource (JNIEnv *_env,
						jclass _class SVM_UNUSED,
						jstring _name)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring result = NULL;
  char *res_url, *name;

  _svmm_resuming_java (env);

  {
    if (_svmm_galloc_utf_chars (env, _name, name) != JNI_OK)
      {
	goto end;
      }

    res_url = _svmf_bootcl_get_resource_url (env, name);

    if (res_url != NULL)
      {
	result = _svmf_get_jni_frame_native_local (env);
	_svmf_get_string (env, res_url, result);
	_svmf_free (res_url);
      }

    _svmf_free (name);
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_newClassLoaderVmData
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    newClassLoaderVmData
 * Signature: (Ljava/lang/ClassLoader;)[B
 */

JNIEXPORT static jbyteArray JNICALL
Java_java_lang_VMClassLoader_newClassLoaderVmData (JNIEnv *_env,
						   jclass _class SVM_UNUSED,
						   jobject cl)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyteArray vmData = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_class_loader_info *class_loader_info;

    if (_svmm_gzalloc_class_loader_info (env, class_loader_info) != JNI_OK)
      {
	goto end;
      }

    if (_svmm_new_native_global (env, class_loader_info->class_loader) !=
	JNI_OK)
      {
	_svmm_gzfree_class_loader_info (class_loader_info);
	goto end;
      }

    *(class_loader_info->class_loader) = *cl;

    /* initialize class loader memory manager */
    if (_svmf_init_cl_alloc (env, class_loader_info) != JNI_OK)
      {
	_svmm_free_native_global (env, class_loader_info->class_loader);
	_svmm_gzfree_class_loader_info (class_loader_info);
	goto end;
      }

    /* initialize native library list tail pointer */
    class_loader_info->native_library_list_tail =
      &class_loader_info->native_library_list;

    vmData = _svmf_get_jni_frame_native_local_array (env);
    if (_svmf_wrap_pointer (env, class_loader_info, vmData) != JNI_OK)
      {
	_svmm_free_native_global (env, class_loader_info->class_loader);
	_svmm_gzfree_class_loader_info (class_loader_info);
	goto end;
      }

    /* manage class loader linked list */
    class_loader_info->next = vm->class_loading.class_loader_list;
    if (vm->class_loading.class_loader_list != NULL)
      {
	assert (vm->class_loading.class_loader_list->previous == NULL);

	vm->class_loading.class_loader_list->previous = class_loader_info;
      }
    vm->class_loading.class_loader_list = class_loader_info;

  }

end:
  _svmm_stopping_java (env);

  return vmData;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_getPrimitiveArray
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getPrimitiveArray
 * Signature: (C)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_getPrimitiveArray (JNIEnv *_env,
						jclass _class SVM_UNUSED,
						jchar element)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass array_instance = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_array_info *array_type;

    switch (element)
      {
      case 'Z':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[Z", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'B':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[B", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'S':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[S", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'C':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[C", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'I':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[I", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'J':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[J", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'F':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[F", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      case 'D':
	{
	  if (_svmm_create_array
	      (env, vm->class_loading.boot_loader.class_loader_info,
	       "[D", array_type) != JNI_OK)
	    {
	      goto end;
	    }
	}
	break;

      default:
	{
	  _svmm_fatal_error ("impossible control flow");
	}
	break;
      }

    array_instance = _svmf_get_jni_frame_native_local (env);
    *array_instance = *(array_type->class_instance);
  }

end:
  _svmm_stopping_java (env);

  return array_instance;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_getArray
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getArray
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_getArray (JNIEnv *_env, jclass _class SVM_UNUSED,
				       jclass _element)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass array_instance = NULL;

  _svmm_resuming_java (env);

  {
#ifndef NDEBUG
    _svmt_JavaVM *vm = env->vm;
#endif

    _svmt_type_info *element = _svmf_unwrap_class_instance (env, _element);
    _svmt_array_info *array_type;

    assert (element->class_loader_info ==
	    vm->class_loading.boot_loader.class_loader_info);

    if (_svmm_create_array
	(env, element->class_loader_info, element->array_type_name,
	 array_type) != JNI_OK)
      {
	goto end;
      }

    array_instance = _svmf_get_jni_frame_native_local (env);
    *array_instance = *(array_type->class_instance);
  }

end:
  _svmm_stopping_java (env);

  return array_instance;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_nativeDefineArray
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeDefineArray
 * Signature: ([BLjava/lang/String;Ljava/lang/Class;)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_nativeDefineArray (JNIEnv *_env,
						jclass _class SVM_UNUSED,
						jbyteArray cl, jstring name,
						jclass _element)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass array_instance = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_class_loader_info *class_loader_info = _svmf_unwrap_pointer (*cl);
    _svmt_type_info *element = _svmf_unwrap_class_instance (env, _element);
    _svmt_array_info *array;

    assert (class_loader_info == element->class_loader_info);

    if (name == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmm_cl_zalloc_array_info (env, class_loader_info, array) != JNI_OK)
      {
	goto end;
      }

    array->is_array = JNI_TRUE;
    array->class_loader_info = class_loader_info;
    array->access_flags = element->access_flags;
    array->base_type = SVM_TYPE_REFERENCE;

    if (element->is_array)
      {
	if (_svmm_cl_malloc_chars
	    (env, class_loader_info,
	     strlen (element->name) + 3, array->array_type_name) != JNI_OK)
	  {
	    goto end;
	  }

	array->array_type_name[0] = '[';
	array->array_type_name[1] = '[';
	array->array_type_name[2] = 0;
	strcat (array->array_type_name, element->name);
	array->name = &array->array_type_name[1];

	array->array_element = _svmf_cast_array (element);

	assert (array->array_element->base_class != NULL);
	array->base_class = array->array_element->base_class;

	array->dimensions = array->array_element->dimensions + 1;

	if (array->dimensions > 255)
	  {
	    _svmf_error_VerifyError (env);
	    goto end;
	  }
      }
    else
      {
	if (_svmm_cl_malloc_chars
	    (env, class_loader_info,
	     strlen (element->name) + 5, array->array_type_name) != JNI_OK)
	  {
	    goto end;
	  }

	array->array_type_name[0] = '[';
	array->array_type_name[1] = '[';
	array->array_type_name[2] = 'L';
	array->array_type_name[3] = 0;
	strcat (array->array_type_name, element->name);
	strcat (array->array_type_name, ";");
	array->name = &array->array_type_name[1];

	array->base_class = _svmf_cast_class (element);
	array->dimensions = 1;
      }

    if (_svmf_new_class (env, _svmf_cast_type_array (array)) != JNI_OK)
      {
	goto end;
      }

    {
      char *name_utf;

      if (_svmm_galloc_utf_chars (env, name, name_utf) != JNI_OK)
	{
	  goto end;
	}

      if (strcmp (name_utf, array->name) != 0)
	{
	  _svmm_gfree_utf_chars (name_utf);
	  _svmf_error_NoClassDefFoundError (env);
	  goto end;
	}

      _svmm_gfree_utf_chars (name_utf);
    }

    array_instance = _svmf_get_jni_frame_native_local (env);
    *array_instance = *(array->class_instance);
  }

end:
  _svmm_stopping_java (env);

  return array_instance;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_nativeDefineClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeDefineClass
 * Signature: ([BLjava/lang/String;[BII)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_nativeDefineClass (JNIEnv *_env,
						jclass _class SVM_UNUSED,
						jbyteArray cl, jstring name,
						jbyteArray data, jint offset,
						jint len,
						jobject protection_domain)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class_instance = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_class_loader_info *class_loader_info = _svmf_unwrap_pointer (*cl);
    _svmt_class_info *class;

    if (name == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    {
      _svmt_u8 *bytes = (_svmt_u8 *)
	(((char *) *data) +
	 _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

      /* parse the bytes */
      if (_svmm_parse_class_file
	  (env, class_loader_info, len, &bytes[offset], class) != JNI_OK)
	{
	  goto end;
	}
    }

    /* check version and name */
    if (!(class->major_version >= 45 && class->major_version <= 48))
      {
	_svmf_error_UnsupportedClassVersionError (env);
	goto end;
      }

    {
      char *name_utf;

      if (_svmm_galloc_utf_chars (env, name, name_utf) != JNI_OK)
	{
	  goto end;
	}

      if (strcmp (name_utf, class->name) != 0)
	{
	  _svmm_gfree_utf_chars (name_utf);
	  _svmf_error_NoClassDefFoundError (env);
	  goto end;
	}

      _svmm_gfree_utf_chars (name_utf);
    }

    class->protection_domain = protection_domain;

    if (_svmf_resolve_super_class (env, class) != JNI_OK ||
	_svmf_resolve_super_interfaces (env, class) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_link_class (env, class) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_new_class_pd
	(env, _svmf_cast_type_class (class),
	 class->protection_domain) != JNI_OK)
      {
	goto end;
      }

    class_instance = _svmf_get_jni_frame_native_local (env);
    *class_instance = *(class->class_instance);
  }

end:
  _svmm_stopping_java (env);

  return class_instance;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_linkClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    linkClass
 * Signature: (Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMClassLoader_linkClass (JNIEnv *_env,
					jclass _class SVM_UNUSED,
					jclass class)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, class);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_initializeClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    initializeClass
 * Signature: (Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMClassLoader_initializeClass (JNIEnv *_env,
					      jclass _class SVM_UNUSED,
					      jclass class)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, class);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!(type->is_array))
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    goto end;
	  }

      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_nativeLoadClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeLoadClass
 * Signature: (Ljava/lang/String;Z)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_nativeLoadClass (JNIEnv *_env,
					      jclass _class SVM_UNUSED,
					      jstring _name,
					      jboolean resolve SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_class_loader_info *class_loader_info =
      vm->class_loading.boot_loader.class_loader_info;
    char *name;

    if (_svmm_galloc_utf_chars (env, _name, name) != JNI_OK)
      {
	goto end;
      }

    /* load class */
    {
      _svmt_class_info *class_info;

      if (_svmm_create_class (env, class_loader_info, name, class_info) !=
	  JNI_OK)
	{
	  _svmm_gfree_utf_chars (name);
	  goto end;
	}

      _svmm_gfree_utf_chars (name);


      /* We link the class now, as we don't want a class reference
         to escape to Java code before that class is prepared.  This
         is important for correct behavior of preparation-dependent
         operations such as "instanceof". */
      if (_svmf_link_class (env, class_info) != JNI_OK)
	{
	  goto end;
	}

      assert (_svmf_is_set_flag (class_info->state, SVM_TYPE_STATE_PREPARED));

      class = _svmf_get_jni_frame_native_local (env);
      *class = *(class_info->class_instance);
    }
  }

end:
  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_nativeCreateArray
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    nativeCreateArray
 * Signature: (Ljava/lang/String;Z)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_nativeCreateArray (JNIEnv *_env,
						jclass _class SVM_UNUSED,
						jstring _name,
						jboolean resolve)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_class_loader_info *class_loader_info =
      vm->class_loading.boot_loader.class_loader_info;
    char *name;

    if (_svmm_galloc_utf_chars (env, _name, name) != JNI_OK)
      {
	goto end;
      }

    /* create array */
    {
      _svmt_array_info *array_info;

      if (_svmm_create_array (env, class_loader_info, name, array_info) !=
	  JNI_OK)
	{
	  _svmm_gfree_utf_chars (name);
	  goto end;
	}

      _svmm_gfree_utf_chars (name);

      if (resolve)
	{
	  if (_svmf_link_array (env, array_info) != JNI_OK)
	    {
	      goto end;
	    }
	}

      class = _svmf_get_jni_frame_native_local (env);
      *class = *(array_info->class_instance);
    }
  }

end:
  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClassLoader_getPrimitiveClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClassLoader
 * Method:    getPrimitiveClass
 * Signature: (C)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClassLoader_getPrimitiveClass (JNIEnv *_env,
						jclass class SVM_UNUSED,
						jchar t)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass type = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    type = _svmf_get_jni_frame_native_local (env);
    switch (t)
      {
      case 'Z':
	{
	  *type = *(vm->class_loading.boot_loader.instances.boolean_type);
	}
	break;

      case 'B':
	{
	  *type = *(vm->class_loading.boot_loader.instances.byte_type);
	}
	break;

      case 'C':
	{
	  *type = *(vm->class_loading.boot_loader.instances.char_type);
	}
	break;

      case 'D':
	{
	  *type = *(vm->class_loading.boot_loader.instances.double_type);
	}
	break;

      case 'F':
	{
	  *type = *(vm->class_loading.boot_loader.instances.float_type);
	}
	break;

      case 'I':
	{
	  *type = *(vm->class_loading.boot_loader.instances.int_type);
	}
	break;

      case 'J':
	{
	  *type = *(vm->class_loading.boot_loader.instances.long_type);
	}
	break;

      case 'S':
	{
	  *type = *(vm->class_loading.boot_loader.instances.short_type);
	}
	break;

      case 'V':
	{
	  *type = *(vm->class_loading.boot_loader.instances.void_type);
	}
	break;


      default:
	{
	  _svmf_error_InternalError (env);
	  goto end;
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);

  return type;
}
