/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_io_VMObjectStreamClass_hasClassInitializer
----------------------------------------------------------------------
*/

/*
 * Class:     java_io_VMObjectStreamClass
 * Method:    hasClassInitializer
 * Signature: (Ljava/lang/Class;)Z
 */
JNIEXPORT svm_static jboolean JNICALL
Java_java_io_VMObjectStreamClass_hasClassInitializer (JNIEnv *_env,
						      jclass class SVM_UNUSED,
						      jclass clazz)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, clazz);

    if (type->is_array)
      {
	result = JNI_FALSE;
      }
    else
      {
	_svmt_class_info *class_info;
	_svmt_method_info *methods;
	jint i;

	result = JNI_FALSE;	/* assume false */
	class_info = _svmf_cast_class (type);
	methods = class_info->methods;
	for (i = 0; i < class_info->methods_count; i++)
	  {
	    if (strcmp (DREF (methods[i].name, value), "<clinit>") == 0)
	      {
		result = JNI_TRUE;
		break;
	      }
	  }
      }
  }

  _svmm_stopping_java (env);

  return result;
}
