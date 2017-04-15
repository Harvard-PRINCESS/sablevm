/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_gzalloc_$1_no_exception ($2 ** ptr)
{
  $2 *tmp;

  tmp = _svmf_calloc (1, sizeof ($2));

  if (tmp == NULL)
    {
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_$1_no_exception ($2 ** ptr)
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

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zmalloc_no_exception
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc_no_exception)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc_no_exception:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmalloc_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_gzmalloc_$1_no_exception (size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

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
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmfree_$1_no_exception
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_$1_no_exception ($2 ** ptr)
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

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_gzalloc_$1 (_svmt_JNIEnv *env, $2 ** ptr)
{
  $2 *tmp;

  tmp = _svmf_calloc (1, sizeof ($2));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzfree_$1 ($2 ** ptr)
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

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_malloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_malloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_malloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_gmalloc_$1 (_svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

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
-----------------------------------m4_dnl
-----------------------------------
_svmh_gmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void
_svmh_gmfree_$1 ($2 ** ptr)
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

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_global_zmalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_global_zmalloc)
 */

m4svm_define_begin v = ":], [:m4svm_global_zmalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_gzmalloc_$1 (_svmt_JNIEnv *env, size_t nmemb, $2 ** ptr)
{
  $2 *tmp;
  size_t size = nmemb * sizeof ($2);

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
-----------------------------------m4_dnl
-----------------------------------
_svmh_gzmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_gzmfree_$1 ($2 ** ptr)
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

m4svm_define_end v = ":])";
