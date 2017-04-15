/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



/*
 * Class:     java_lang_reflect_Array
 * Method:    createObjectArray
 * Signature: (Ljava/lang/Class;I)Ljava/lang/Object;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_reflect_Array_createObjectArray (JNIEnv *_env,
						jclass jlrarrayClass
						SVM_UNUSED, jclass _class,
						jint dim)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobjectArray instance = NULL;
  _svmt_array_info *array_info;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, _class);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (_svmm_create_array
	(env,
	 type->class_loader_info,
	 type->array_type_name, array_info) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_link_array (env, array_info) != JNI_OK)
      {
	goto end;
      }

    if (dim < 0)
      {
	_svmf_error_NegativeArraySizeException (env);
	goto end;
      }

    instance = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance (env, array_info, dim, *instance) != JNI_OK)
      {
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return _svmf_cast_jobject (instance);

}
