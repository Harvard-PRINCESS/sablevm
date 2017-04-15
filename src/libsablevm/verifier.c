/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_verify_class
----------------------------------------------------------------------
*/

svm_static jint
_svmf_verify_class (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  if (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_VERIFIED))
    {
      return JNI_OK;
    }

  if (class->verification_error != NULL)
    {
      assert (*(class->verification_error) != NULL);

      *(env->throwable) = *(class->verification_error);
      return JNI_ERR;
    }

  if (class->class_loader_info->class_loader == NULL)
    {
      /* we do not verify classes loaded by the bootstrap class loader */
      _svmm_set_flag (class->state, SVM_TYPE_STATE_VERIFIED);
      return JNI_OK;
    }

  /* This function should take care of "pass 2" of the verifier (i.e. all checks
     non-related to bytecode arrays). */

  /* Ugly hack, similar to other Free VMs... */
  _svmm_set_flag (class->state, SVM_TYPE_STATE_VERIFIED);
  return JNI_OK;
}
