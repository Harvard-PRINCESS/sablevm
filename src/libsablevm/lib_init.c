/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static pthread_once_t _svmv_init_once = { PTHREAD_ONCE_INIT };	/* internal_init should only be called once! */
static int _svmv_init_result = JNI_ERR;	/* JNI_OK when internal_init succeeds */

/*
----------------------------------------------------------------------
_svmf_internal_init
----------------------------------------------------------------------
*/

svm_static void
_svmf_internal_init (void)
{
  if (lt_dlinit () != 0)
    {
      return;
    }

  if ((_svmv_init_result = _svmf_thread_init ()) != JNI_OK)
    {
      return;
    }

  if ((_svmv_init_result = _svmf_error_init ()) != JNI_OK)
    {
      return;
    }

  _svmv_init_result = JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_init
----------------------------------------------------------------------
*/

svm_static jint
_svmf_init (void)
{
  /*  make sure internal_init is called only once */
  pthread_once (&_svmv_init_once, _svmf_internal_init);

  return _svmv_init_result;
}
