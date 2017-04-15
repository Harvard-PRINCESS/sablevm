/* This file has been automatically generated from "global_alloc.list" */

/*
----------------------------------------------------------------------
_svmh_gzalloc_env_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_env_no_exception (_svmt_JNIEnv ** ptr)
{
  _svmt_JNIEnv *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_JNIEnv));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_env_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_env_no_exception (_svmt_JNIEnv ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_fat_lock_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_fat_lock_no_exception (_svmt_fat_lock ** ptr)
{
  _svmt_fat_lock *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_fat_lock));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_fat_lock_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_fat_lock_no_exception (_svmt_fat_lock ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_initialization_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_initialization_no_exception (_svmt_initialization ** ptr)
{
  _svmt_initialization *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_initialization));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_initialization_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_initialization_no_exception (_svmt_initialization ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_native_ref_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_native_ref_no_exception (_svmt_native_ref ** ptr)
{
  _svmt_native_ref *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_native_ref));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_native_ref_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_native_ref_no_exception (_svmt_native_ref ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_vm_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_vm_no_exception (_svmt_JavaVM ** ptr)
{
  _svmt_JavaVM *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_JavaVM));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_vm_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_vm_no_exception (_svmt_JavaVM ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_cchars_no_exception
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_cchars_no_exception (size_t nmemb, char ** ptr)
{
  char *tmp;
  size_t size = nmemb * sizeof (char);

  if (size < nmemb)
    return JNI_ERR;

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_cchars_no_exception
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_cchars_no_exception (char ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_class_loader_info
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_class_loader_info (_svmt_JNIEnv *env, _svmt_class_loader_info ** ptr)
{
  _svmt_class_loader_info *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_class_loader_info));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_class_loader_info
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_class_loader_info (_svmt_class_loader_info ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_gc_map_node
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_gc_map_node (_svmt_JNIEnv *env, _svmt_gc_map_node ** ptr)
{
  _svmt_gc_map_node *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_gc_map_node));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_gc_map_node
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_gc_map_node (_svmt_gc_map_node ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_imethod_signature_node
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_imethod_signature_node (_svmt_JNIEnv *env, _svmt_imethod_signature_node ** ptr)
{
  _svmt_imethod_signature_node *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_imethod_signature_node));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_imethod_signature_node
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_imethod_signature_node (_svmt_imethod_signature_node ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_memory_block
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_memory_block (_svmt_JNIEnv *env, _svmt_memory_block ** ptr)
{
  _svmt_memory_block *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_memory_block));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_memory_block
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_memory_block (_svmt_memory_block ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_type_node
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_type_node (_svmt_JNIEnv *env, _svmt_type_node ** ptr)
{
  _svmt_type_node *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_type_node));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_type_node
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_type_node (_svmt_type_node ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_internal_method_node
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_internal_method_node (_svmt_JNIEnv *env, _svmt_internal_method_node ** ptr)
{
  _svmt_internal_method_node *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_internal_method_node));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_internal_method_node
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_internal_method_node (_svmt_internal_method_node ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzalloc_zip_file
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_zip_file (_svmt_JNIEnv *env, _svmt_zip_file ** ptr)
{
  _svmt_zip_file *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_zip_file));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_zip_file
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_zip_file (_svmt_zip_file ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmh_gzalloc_sequence_node
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzalloc_sequence_node (_svmt_JNIEnv *env, _svmt_sequence_node ** ptr)
{
  _svmt_sequence_node *tmp;

  tmp = _svmf_calloc (1, sizeof (_svmt_sequence_node));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_sequence_node
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_sequence_node (_svmt_sequence_node ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
----------------------------------------------------------------------
_svmh_gmalloc_cchars
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gmalloc_cchars (_svmt_JNIEnv *env, size_t nmemb, char ** ptr)
{
  char *tmp;
  size_t size = nmemb * sizeof (char);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_malloc (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gmfree_cchars
----------------------------------------------------------------------
*/

svm_static void
_svmh_gmfree_cchars (char ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gmalloc_ints
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gmalloc_ints (_svmt_JNIEnv *env, size_t nmemb, jint ** ptr)
{
  jint *tmp;
  size_t size = nmemb * sizeof (jint);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_malloc (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gmfree_ints
----------------------------------------------------------------------
*/

svm_static void
_svmh_gmfree_ints (jint ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gmalloc_ubytes
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gmalloc_ubytes (_svmt_JNIEnv *env, size_t nmemb, _svmt_u8 ** ptr)
{
  _svmt_u8 *tmp;
  size_t size = nmemb * sizeof (_svmt_u8);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_malloc (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gmfree_ubytes
----------------------------------------------------------------------
*/

svm_static void
_svmh_gmfree_ubytes (_svmt_u8 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gmalloc_chars
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gmalloc_chars (_svmt_JNIEnv *env, size_t nmemb, jchar ** ptr)
{
  jchar *tmp;
  size_t size = nmemb * sizeof (jchar);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_malloc (size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gmfree_chars
----------------------------------------------------------------------
*/

svm_static void
_svmh_gmfree_chars (jchar ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_env_array
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_env_array (_svmt_JNIEnv *env, size_t nmemb, _svmt_JNIEnv * ** ptr)
{
  _svmt_JNIEnv * *tmp;
  size_t size = nmemb * sizeof (_svmt_JNIEnv *);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_env_array
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_env_array (_svmt_JNIEnv * ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_fat_lock_array
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_fat_lock_array (_svmt_JNIEnv *env, size_t nmemb, _svmt_fat_lock * ** ptr)
{
  _svmt_fat_lock * *tmp;
  size_t size = nmemb * sizeof (_svmt_fat_lock *);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_fat_lock_array
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_fat_lock_array (_svmt_fat_lock * ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_instruction_info
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_instruction_info (_svmt_JNIEnv *env, size_t nmemb, _svmt_instruction_info ** ptr)
{
  _svmt_instruction_info *tmp;
  size_t size = nmemb * sizeof (_svmt_instruction_info);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_instruction_info
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_instruction_info (_svmt_instruction_info ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_instruction_preparation
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_instruction_preparation (_svmt_JNIEnv *env, size_t nmemb, _svmt_instruction_preparation ** ptr)
{
  _svmt_instruction_preparation *tmp;
  size_t size = nmemb * sizeof (_svmt_instruction_preparation);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_instruction_preparation
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_instruction_preparation (_svmt_instruction_preparation ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_local_preparation
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_local_preparation (_svmt_JNIEnv *env, size_t nmemb, _svmt_local_preparation ** ptr)
{
  _svmt_local_preparation *tmp;
  size_t size = nmemb * sizeof (_svmt_local_preparation);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_local_preparation
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_local_preparation (_svmt_local_preparation ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_ubytes
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_ubytes (_svmt_JNIEnv *env, size_t nmemb, _svmt_u8 ** ptr)
{
  _svmt_u8 *tmp;
  size_t size = nmemb * sizeof (_svmt_u8);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_ubytes
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_ubytes (_svmt_u8 ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_boot_class_path_entry
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_boot_class_path_entry (_svmt_JNIEnv *env, size_t nmemb, _svmt_boot_class_path_entry ** ptr)
{
  _svmt_boot_class_path_entry *tmp;
  size_t size = nmemb * sizeof (_svmt_boot_class_path_entry);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_boot_class_path_entry
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_boot_class_path_entry (_svmt_boot_class_path_entry ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}


/*
----------------------------------------------------------------------
_svmh_gzmalloc_zip_file_entry
----------------------------------------------------------------------
*/

svm_static jint
_svmh_gzmalloc_zip_file_entry (_svmt_JNIEnv *env, size_t nmemb, _svmt_zip_file_entry ** ptr)
{
  _svmt_zip_file_entry *tmp;
  size_t size = nmemb * sizeof (_svmt_zip_file_entry);

  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp = _svmf_calloc (1, size);

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzmfree_zip_file_entry
----------------------------------------------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_zip_file_entry (_svmt_zip_file_entry ** ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}

