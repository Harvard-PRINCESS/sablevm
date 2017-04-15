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
m4svm_cl_zalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_zalloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_zalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_zalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_cl_zalloc_$1 (_svmt_JNIEnv *env,
		    _svmt_class_loader_info *class_loader_info, $2 ** ptr)
{
  return _svmf_cl_zalloc (env, class_loader_info, sizeof ($2), (void **) ptr);
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_zfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_cl_zfree_$1 (_svmt_JNIEnv *env,
		   _svmt_class_loader_info *class_loader_info, $2 ** ptr)
{
  _svmf_cl_free (env, class_loader_info, sizeof ($2), (void **) ptr);
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_cl_malloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_malloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_malloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_malloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_cl_malloc_$1 (_svmt_JNIEnv *env,
		    _svmt_class_loader_info *class_loader_info,
		    size_t nmemb, $2 ** ptr)
{
  size_t size = nmemb * sizeof ($2);

  /* check for overflow */
  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  return _svmf_cl_alloc (env, class_loader_info, size, (void **) ptr);
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_mfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_cl_mfree_$1 (_svmt_JNIEnv *env,
		   _svmt_class_loader_info *class_loader_info, size_t nmemb,
		   $2 ** ptr)
{
  size_t size = nmemb * sizeof ($2);

  _svmf_cl_free (env, class_loader_info, size, (void **) ptr);
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_cl_zmalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_zmalloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_zmalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_zmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmh_cl_zmalloc_$1 (_svmt_JNIEnv *env,
		     _svmt_class_loader_info *class_loader_info, size_t nmemb,
		     $2 ** ptr)
{
  size_t size = nmemb * sizeof ($2);

  /* check for overflow */
  if (size < nmemb)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  return _svmf_cl_zalloc (env, class_loader_info, size, (void **) ptr);
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_cl_zmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static void SVM_UNUSED
_svmh_cl_zmfree_$1 (_svmt_JNIEnv *env,
		    _svmt_class_loader_info *class_loader_info, size_t nmemb,
		    $2 ** ptr)
{
  size_t size = nmemb * sizeof ($2);

  _svmf_cl_free (env, class_loader_info, size, (void **) ptr);
}

m4svm_define_end v = ":])";
