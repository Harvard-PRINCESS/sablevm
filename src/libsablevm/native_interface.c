/* This file has been automatically generated from "native_interface.m4.c" */

/*
----------------------------------------------------------------------
NewBooleanArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbooleanArray JNICALL
NewBooleanArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.boolean_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewByteArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyteArray JNICALL
NewByteArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.byte_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewShortArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshortArray JNICALL
NewShortArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.short_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewCharArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jcharArray JNICALL
NewCharArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.char_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewIntArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jintArray JNICALL
NewIntArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.int_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewLongArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlongArray JNICALL
NewLongArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.long_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewFloatArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloatArray JNICALL
NewFloatArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.float_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
NewDoubleArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdoubleArray JNICALL
NewDoubleArray (JNIEnv *_env, jsize length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;

  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.double_array, length,
	 *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

  }

end:
  _svmm_stopping_java (env);

  return array;
}


/*
----------------------------------------------------------------------
GetBooleanField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
GetBooleanField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jboolean value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_BOOLEAN_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetByteField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
GetByteField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jbyte value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_BYTE_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetShortField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
GetShortField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jshort value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_SHORT_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetCharField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
GetCharField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jchar value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_CHAR_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetIntField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetIntField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jint value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_INT_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetLongField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
GetLongField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jlong value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_LONG_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetFloatField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
GetFloatField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jfloat value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_FLOAT_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetDoubleField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
GetDoubleField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jdouble value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    value = _svmf_get_DOUBLE_field (*obj, offset);
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
SetBooleanField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetBooleanField (JNIEnv *_env, jobject obj, jfieldID fieldID, jboolean value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_BOOLEAN_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetByteField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetByteField (JNIEnv *_env, jobject obj, jfieldID fieldID, jbyte value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_BYTE_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetShortField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetShortField (JNIEnv *_env, jobject obj, jfieldID fieldID, jshort value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_SHORT_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetCharField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetCharField (JNIEnv *_env, jobject obj, jfieldID fieldID, jchar value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_CHAR_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetIntField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetIntField (JNIEnv *_env, jobject obj, jfieldID fieldID, jint value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_INT_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetLongField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetLongField (JNIEnv *_env, jobject obj, jfieldID fieldID, jlong value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_LONG_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetFloatField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetFloatField (JNIEnv *_env, jobject obj, jfieldID fieldID, jfloat value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_FLOAT_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetDoubleField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetDoubleField (JNIEnv *_env, jobject obj, jfieldID fieldID, jdouble value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_DOUBLE_field (*obj, offset, value);
  }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetStaticBooleanField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
GetStaticBooleanField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jboolean value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.z;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticByteField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
GetStaticByteField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jbyte value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.b;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticShortField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
GetStaticShortField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jshort value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.s;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticCharField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
GetStaticCharField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jchar value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.c;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticIntField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetStaticIntField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jint value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.i;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticLongField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
GetStaticLongField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jlong value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.j;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticFloatField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
GetStaticFloatField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jfloat value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.f;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
GetStaticDoubleField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
GetStaticDoubleField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jdouble value;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  value = field->data.class_field.value.d;

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
SetStaticBooleanField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticBooleanField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jboolean value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.z = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticByteField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticByteField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jbyte value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.b = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticShortField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticShortField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jshort value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.s = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticCharField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticCharField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jchar value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.c = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticIntField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticIntField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jint value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.i = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticLongField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticLongField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jlong value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.j = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticFloatField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticFloatField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jfloat value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.f = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetStaticDoubleField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticDoubleField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		  jdouble value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field->data.class_field.value.d = value;

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualVoidMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
_svmf_internal_CallNonvirtualVoidMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  
  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
  }

end:
  ;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualVoidMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
_svmf_internal_CallNonvirtualVoidMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  
  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
  }

end:
  ;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualObjectMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
_svmf_internal_CallNonvirtualObjectMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jobject result = NULL;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualObjectMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
_svmf_internal_CallNonvirtualObjectMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jobject result = NULL;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualBooleanMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
_svmf_internal_CallNonvirtualBooleanMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jboolean result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualBooleanMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
_svmf_internal_CallNonvirtualBooleanMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jboolean result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualByteMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
_svmf_internal_CallNonvirtualByteMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jbyte result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualByteMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
_svmf_internal_CallNonvirtualByteMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jbyte result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualShortMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
_svmf_internal_CallNonvirtualShortMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jshort result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualShortMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
_svmf_internal_CallNonvirtualShortMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jshort result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualCharMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
_svmf_internal_CallNonvirtualCharMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jchar result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualCharMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
_svmf_internal_CallNonvirtualCharMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jchar result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualIntMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
_svmf_internal_CallNonvirtualIntMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jint result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualIntMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
_svmf_internal_CallNonvirtualIntMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jint result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualLongMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
_svmf_internal_CallNonvirtualLongMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jlong result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualLongMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
_svmf_internal_CallNonvirtualLongMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jlong result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualFloatMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
_svmf_internal_CallNonvirtualFloatMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jfloat result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualFloatMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
_svmf_internal_CallNonvirtualFloatMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jfloat result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualDoubleMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
_svmf_internal_CallNonvirtualDoubleMethodA (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, jvalue *args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jdouble result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    jint arg = 0;

    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      locals[i++].jint = args[arg++].z;
	    }
	    break;

	  case 'B':
	    {
	      locals[i++].jint = args[arg++].b;
	    }
	    break;

	  case 'S':
	    {
	      locals[i++].jint = args[arg++].s;
	    }
	    break;

	  case 'C':
	    {
	      locals[i++].jint = args[arg++].c;
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = args[arg++].i;
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = args[arg++].j;
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      locals[i++].jfloat = args[arg++].f;
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = args[arg++].d;
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = args[arg++].l;
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
_svmf_internal_CallNonvirtualDoubleMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
_svmf_internal_CallNonvirtualDoubleMethodV (_svmt_JNIEnv *env, jobject this,
					 jclass class SVM_UNUSED,
					 jmethodID methodID, va_list args)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *initial_frame;
  _svmt_method_info *method = methodID;
  _svmt_method_frame_info *frame_info = method->frame_info;
  jdouble result = 0;

  if (this == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  /* assert (_svmf_is_set_flag
     (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

  /* syncronized? */
  if (method->synchronized)
    {
      if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	{
	  goto end;
	}
    }

  if (_svmf_ensure_stack_capacity
      (env, frame_info->internal_invoke_frame_size) != JNI_OK)
    {
      goto end;
    }

  initial_frame = env->stack.current_frame;

  /* setup internal call frame */
  {
    size_t offset = env->stack.current_frame->end_offset;
    _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
      (((char *) env->stack.current_frame) + offset);

    frame->previous_offset = offset;
    frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
    frame->method = &vm->internal_call_method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = NULL;
    frame->pc = vm->internal_call_method.frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* push parameters */
  {
    _svmt_stack_frame *prev_frame = env->stack.current_frame;
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) prev_frame) + prev_frame->end_offset);
    jint i = 0;
    char *descriptor = DREF (method->descriptor, value);
    char c;
    jint current = 0;
    
    locals[i++].reference = *this;

    while ((c = descriptor[++current]) != ')')
      {
	switch (c)
	  {
	  case 'Z':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'B':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'S':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'C':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	    }
	    break;

	  case 'I':
	    {
	      locals[i++].jint = va_arg (args, jint);
	    }
	    break;

	  case 'J':
	    {
	      *((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
	      i += 2;
	    }
	    break;

	  case 'F':
	    {
	      /* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	    }
	    break;

	  case 'D':
	    {
	      *((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
	      i += 2;
	    }
	    break;

	  case 'L':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] != ';');
	    }
	    break;

	  case '[':
	    {
	      jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
	      assert ((obj ==
		       NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						   "SableVM") == 0));
#endif
	      locals[i++].reference = (obj == NULL) ? NULL : *obj;
	      while (descriptor[++current] == '[');
	      if (descriptor[current] == 'L')
		{
		  while (descriptor[++current] != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }
      }

    {
      jint ref_count = frame_info->non_parameter_ref_locals_count;
      jint j;

      for (j = 0; j < ref_count; j++)
	{
	  locals[i++].reference = NULL;
	}
    }
  }

  /* setup java call frame */
  {
    size_t offset =
      env->stack.current_frame->end_offset + frame_info->start_offset;
    _svmt_stack_frame *frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      offset);

    frame->previous_offset = offset;
    frame->end_offset = frame_info->end_offset;
    frame->method = method;
    frame->stack_trace_element = NULL;
    frame->lock_count = 0;
    frame->this = *this;
    frame->pc = frame_info->code;
    frame->stack_size = 0;

    env->stack.current_frame = frame;
  }

  /* interpret and pop internal call frame */
  {
    /* call the interpreter */
    jint status = _svmf_interpreter (env);

    /* retrieve stack frame */
    _svmt_stack_frame *frame = env->stack.current_frame;

    assert (frame->method == &vm->internal_call_method);

    /* pop frame */
    env->stack.current_frame = (_svmt_stack_frame *) (void *)
      (((char *) frame) - frame->previous_offset);

    /* rethrow exception */
    if (status != JNI_OK)
      {
	goto end;
      }
    
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
  }

end:
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualVoidMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallNonvirtualVoidMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    _svmf_internal_CallNonvirtualVoidMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
}


/*
----------------------------------------------------------------------
CallNonvirtualVoidMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallNonvirtualVoidMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmf_internal_CallNonvirtualVoidMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
}


/*
----------------------------------------------------------------------
CallNonvirtualVoidMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallNonvirtualVoidMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmf_internal_CallNonvirtualVoidMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
}


/*
----------------------------------------------------------------------
CallNonvirtualObjectMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallNonvirtualObjectMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualObjectMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualObjectMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallNonvirtualObjectMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualObjectMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualObjectMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallNonvirtualObjectMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualObjectMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualBooleanMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallNonvirtualBooleanMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualBooleanMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualBooleanMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallNonvirtualBooleanMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualBooleanMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualBooleanMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallNonvirtualBooleanMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualBooleanMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualByteMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallNonvirtualByteMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualByteMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualByteMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallNonvirtualByteMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualByteMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualByteMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallNonvirtualByteMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualByteMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualShortMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallNonvirtualShortMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualShortMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualShortMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallNonvirtualShortMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualShortMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualShortMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallNonvirtualShortMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualShortMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualCharMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallNonvirtualCharMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualCharMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualCharMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallNonvirtualCharMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualCharMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualCharMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallNonvirtualCharMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualCharMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualIntMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallNonvirtualIntMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualIntMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualIntMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallNonvirtualIntMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualIntMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualIntMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallNonvirtualIntMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualIntMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualLongMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallNonvirtualLongMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualLongMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualLongMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallNonvirtualLongMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualLongMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualLongMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallNonvirtualLongMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualLongMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualFloatMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallNonvirtualFloatMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualFloatMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualFloatMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallNonvirtualFloatMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualFloatMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualFloatMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallNonvirtualFloatMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualFloatMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualDoubleMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallNonvirtualDoubleMethod (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    va_list args;

    va_start (args, methodID);

    result = _svmf_internal_CallNonvirtualDoubleMethodV (env, this, class, methodID, args);
    
    va_end (args);
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualDoubleMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallNonvirtualDoubleMethodA (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualDoubleMethodA (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallNonvirtualDoubleMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallNonvirtualDoubleMethodV (JNIEnv *_env, jobject this, jclass class,
			  jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    result = _svmf_internal_CallNonvirtualDoubleMethodV (env, this, class, methodID, args);
    
  }

  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallVoidMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallVoidMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallVoidMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallVoidMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallVoidMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallVoidMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallObjectMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallObjectMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallObjectMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallObjectMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallObjectMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallObjectMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallBooleanMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallBooleanMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallBooleanMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallBooleanMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallBooleanMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallBooleanMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallByteMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallByteMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallByteMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallByteMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallByteMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallByteMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallShortMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallShortMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallShortMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallShortMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallShortMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallShortMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallCharMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallCharMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallCharMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallCharMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallCharMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallCharMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallIntMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallIntMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallIntMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallIntMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallIntMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallIntMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallLongMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallLongMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallLongMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallLongMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallLongMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallLongMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallFloatMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallFloatMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallFloatMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallFloatMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallFloatMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallFloatMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallDoubleMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallDoubleMethod (JNIEnv *_env, jobject this, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallDoubleMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallDoubleMethodA (JNIEnv *_env, jobject this, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallDoubleMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallDoubleMethodV (JNIEnv *_env, jobject this, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method;
    _svmt_method_frame_info *frame_info;
    size_t method_offset;

    if (this == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_is_set_flag
	(methodID->class_info->access_flags, SVM_ACC_INTERFACE))
      {
	/* interface */
	method_offset = -((1 + methodID->method_id) *
			  sizeof (_svmt_method_info *));
      }
    else
      {
	/* class */
	method_offset = sizeof (_svmt_vtable) +
	  (methodID->method_id * sizeof (_svmt_method_info *));
      }

    method = *((_svmt_method_info **) (void *)
	       (((char *) (*this)->vtable) + method_offset));

    frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor (env, *(this)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      locals[i++].reference = *this;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *this;
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticVoidMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallStaticVoidMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallStaticVoidMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallStaticVoidMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallStaticVoidMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
CallStaticVoidMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  
  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
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
CallStaticObjectMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallStaticObjectMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticObjectMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallStaticObjectMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticObjectMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
CallStaticObjectMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        if (ptr_ret->reference != NULL)
          {
            _svmt_object_instance *ref = ptr_ret->reference;
#if defined (MAGIC)
            assert (strcmp(ptr_ret->reference->magic, "SableVM") == 0);
#endif
            result = _svmf_get_jni_frame_native_local (env);
            *result = ref;
          }
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticBooleanMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallStaticBooleanMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticBooleanMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallStaticBooleanMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticBooleanMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
CallStaticBooleanMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticByteMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallStaticByteMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticByteMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallStaticByteMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticByteMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte JNICALL
CallStaticByteMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticShortMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallStaticShortMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticShortMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallStaticShortMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticShortMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort JNICALL
CallStaticShortMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticCharMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallStaticCharMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticCharMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallStaticCharMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticCharMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar JNICALL
CallStaticCharMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticIntMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallStaticIntMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticIntMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallStaticIntMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticIntMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
CallStaticIntMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jint;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticLongMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallStaticLongMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticLongMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallStaticLongMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticLongMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
CallStaticLongMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jlong *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticFloatMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallStaticFloatMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticFloatMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallStaticFloatMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticFloatMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat JNICALL
CallStaticFloatMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = ptr_ret->jfloat;
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticDoubleMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallStaticDoubleMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      va_list args;

      va_start (args, methodID);

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      va_end (args);

      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticDoubleMethodA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallStaticDoubleMethodA (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      jint arg = 0;

      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		locals[i++].jint = args[arg++].z;
	      }
	      break;

	    case 'B':
	      {
		locals[i++].jint = args[arg++].b;
	      }
	      break;

	    case 'S':
	      {
		locals[i++].jint = args[arg++].s;
	      }
	      break;

	    case 'C':
	      {
		locals[i++].jint = args[arg++].c;
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = args[arg++].i;
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = args[arg++].j;
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		locals[i++].jfloat = args[arg++].f;
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = args[arg++].d;
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = args[arg++].l;
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
CallStaticDoubleMethodV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble JNICALL
CallStaticDoubleMethodV (JNIEnv *_env, jclass cls SVM_UNUSED,
		      jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble result = 0;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *initial_frame;
    _svmt_method_info *method = methodID;
    _svmt_method_frame_info *frame_info = method->frame_info;

    /* assert (_svmf_is_set_flag
       (method->class_info->state, SVM_TYPE_STATE_INITIALIZED)); */

    /* syncronized? */
    if (method->synchronized)
      {
	if (_svmf_enter_object_monitor
	    (env, *(method->class_info->class_instance)) != JNI_OK)
	  {
	    goto end;
	  }
      }

    if (_svmf_ensure_stack_capacity
	(env, frame_info->internal_invoke_frame_size) != JNI_OK)
      {
	goto end;
      }

    initial_frame = env->stack.current_frame;

    /* setup internal call frame */
    {
      size_t offset = env->stack.current_frame->end_offset;
      _svmt_stack_frame *frame = (_svmt_stack_frame *) (void *)
	(((char *) env->stack.current_frame) + offset);

      frame->previous_offset = offset;
      frame->end_offset = _svmf_aligned_size_t (sizeof (_svmt_stack_frame));
      frame->method = &vm->internal_call_method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = NULL;
      frame->pc = vm->internal_call_method.frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* push parameters */
    {
      _svmt_stack_frame *prev_frame = env->stack.current_frame;
      _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
	(((char *) prev_frame) + prev_frame->end_offset);
      jint i = 0;
      char *descriptor = DREF (method->descriptor, value);
      char c;
      jint current = 0;
      
      while ((c = descriptor[++current]) != ')')
	{
	  switch (c)
	    {
	    case 'Z':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'B':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'S':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'C':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jint = va_arg (args, int);
	      }
	      break;

	    case 'I':
	      {
		locals[i++].jint = va_arg (args, jint);
	      }
	      break;

	    case 'J':
	      {
		*((jlong *) (void *) &locals[i]) = va_arg (args, jlong);
		i += 2;
	      }
	      break;

	    case 'F':
	      {
		/* Take into account ISO C's default argument promotion. */
                locals[i++].jfloat = va_arg (args, jdouble);
	      }
	      break;

	    case 'D':
	      {
		*((jdouble *) (void *) &locals[i]) = va_arg (args, jdouble);
		i += 2;
	      }
	      break;

	    case 'L':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] != ';');
	      }
	      break;

	    case '[':
	      {
		jobject obj = va_arg (args, jobject);
#if defined (MAGIC)
		assert ((obj ==
			 NULL) ? JNI_TRUE : (strcmp ((*obj)->magic,
						     "SableVM") == 0));
#endif
		locals[i++].reference = (obj == NULL) ? NULL : *obj;
		while (descriptor[++current] == '[');
		if (descriptor[current] == 'L')
		  {
		    while (descriptor[++current] != ';');
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

      
      {
	jint ref_count = frame_info->non_parameter_ref_locals_count;
	jint j;

	for (j = 0; j < ref_count; j++)
	  {
	    locals[i++].reference = NULL;
	  }
      }
    }

    /* setup java call frame */
    {
      size_t offset =
	env->stack.current_frame->end_offset + frame_info->start_offset;
      _svmt_stack_frame *frame =
	(_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
					offset);

      frame->previous_offset = offset;
      frame->end_offset = frame_info->end_offset;
      frame->method = method;
      frame->stack_trace_element = NULL;
      frame->lock_count = 0;
      frame->this = *(method->class_info->class_instance);
      frame->pc = frame_info->code;
      frame->stack_size = 0;

      env->stack.current_frame = frame;
    }

    /* interpret and pop internal call frame */
    {
      /* call the interpreter */
      jint status = _svmf_interpreter (env);

      /* retrieve stack frame */
      _svmt_stack_frame *frame = env->stack.current_frame;

      assert (frame->method == &vm->internal_call_method);

      /* pop frame */
      env->stack.current_frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);

      /* rethrow exception */
      if (status != JNI_OK)
	{
	  goto end;
	}
      
      /* set the return value */
      {
        _svmt_stack_value *ptr_ret = (_svmt_stack_value *) (void *)
          (((char *) frame) + frame->end_offset);

        result = *((jdouble *) (void *) ptr_ret);
      }
    }
  }

end:
  _svmm_stopping_java (env);
  
  return result;

}


/*
----------------------------------------------------------------------
GetByteArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetByteArrayRegion (JNIEnv *_env, jbyteArray array, jsize start, jsize len,
		  jbyte * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jbyte *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jbyte *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jbyte));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetShortArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetShortArrayRegion (JNIEnv *_env, jshortArray array, jsize start, jsize len,
		  jshort * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jshort *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jshort *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jshort));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetCharArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetCharArrayRegion (JNIEnv *_env, jcharArray array, jsize start, jsize len,
		  jchar * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jchar *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jchar *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jchar));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetIntArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetIntArrayRegion (JNIEnv *_env, jintArray array, jsize start, jsize len,
		  jint * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jint *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jint));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetLongArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetLongArrayRegion (JNIEnv *_env, jlongArray array, jsize start, jsize len,
		  jlong * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jlong *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jlong *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jlong));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetFloatArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetFloatArrayRegion (JNIEnv *_env, jfloatArray array, jsize start, jsize len,
		  jfloat * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jfloat *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jfloat *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jfloat));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetDoubleArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetDoubleArrayRegion (JNIEnv *_env, jdoubleArray array, jsize start, jsize len,
		  jdouble * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jdouble *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jdouble *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (buf, &elements[start], len * sizeof (jdouble));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetByteArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetByteArrayRegion (JNIEnv *_env, jbyteArray array, jsize start, jsize len,
		  jbyte * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jbyte *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jbyte *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jbyte));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetShortArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetShortArrayRegion (JNIEnv *_env, jshortArray array, jsize start, jsize len,
		  jshort * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jshort *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jshort *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jshort));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetCharArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetCharArrayRegion (JNIEnv *_env, jcharArray array, jsize start, jsize len,
		  jchar * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jchar *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jchar *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jchar));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetIntArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetIntArrayRegion (JNIEnv *_env, jintArray array, jsize start, jsize len,
		  jint * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jint *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jint));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetLongArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetLongArrayRegion (JNIEnv *_env, jlongArray array, jsize start, jsize len,
		  jlong * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jlong *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jlong *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jlong));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetFloatArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetFloatArrayRegion (JNIEnv *_env, jfloatArray array, jsize start, jsize len,
		  jfloat * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jfloat *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jfloat *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jfloat));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
SetDoubleArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetDoubleArrayRegion (JNIEnv *_env, jdoubleArray array, jsize start, jsize len,
		  jdouble * buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jdouble *elements;

    if (start < 0 || len < 0 || start + len > (*array)->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    elements =
      (jdouble *) (void *) (((char *) *array) +
		       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

    memcpy (&elements[start], buf, len * sizeof (jdouble));
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetByteArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jbyte * JNICALL
GetByteArrayElements (JNIEnv *_env, jbyteArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jbyte *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jbyte));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jbyte));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetShortArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jshort * JNICALL
GetShortArrayElements (JNIEnv *_env, jshortArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jshort *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jshort));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jshort));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetCharArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jchar * JNICALL
GetCharArrayElements (JNIEnv *_env, jcharArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jchar *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jchar));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jchar));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetIntArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint * JNICALL
GetIntArrayElements (JNIEnv *_env, jintArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jint *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jint));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jint));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetLongArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong * JNICALL
GetLongArrayElements (JNIEnv *_env, jlongArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jlong *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jlong));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jlong));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetFloatArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfloat * JNICALL
GetFloatArrayElements (JNIEnv *_env, jfloatArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jfloat *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jfloat));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jfloat));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
GetDoubleArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jdouble * JNICALL
GetDoubleArrayElements (JNIEnv *_env, jdoubleArray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* The JNI specification says it shouldn't be NULL if no
	   exception is thrown! Ugly.  I think the JNI spec should be
	   fixed. */
	result = (jdouble *) 1;	/* assuming NULL isn't defined as 1
				   (unlikely, but allowed by ISO C...) */
	goto end;
      }

    result = _svmf_malloc (size * sizeof (jdouble));

    if (result == NULL)
      {
	_svmf_error_OutOfMemoryError (env);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result,
	    (((char *) *array) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
	    size * sizeof (jdouble));
  }

end:
  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
ReleaseByteArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseByteArrayElements (JNIEnv *_env, jbyteArray array, jbyte * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jbyte));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jbyte));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseByteArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseShortArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseShortArrayElements (JNIEnv *_env, jshortArray array, jshort * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jshort));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jshort));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseShortArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseCharArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseCharArrayElements (JNIEnv *_env, jcharArray array, jchar * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jchar));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jchar));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseCharArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseIntArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseIntArrayElements (JNIEnv *_env, jintArray array, jint * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jint));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jint));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseIntArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseLongArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseLongArrayElements (JNIEnv *_env, jlongArray array, jlong * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jlong));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jlong));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseLongArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseFloatArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseFloatArrayElements (JNIEnv *_env, jfloatArray array, jfloat * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jfloat));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jfloat));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseFloatArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
ReleaseDoubleArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseDoubleArrayElements (JNIEnv *_env, jdoubleArray array, jdouble * elems, jint mode)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    if (size == 0)
      {
	goto end;
      }

    switch (mode)
      {
      case 0:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jdouble));
	  _svmf_free (elems);
	  goto end;
	}
	break;

      case JNI_COMMIT:
	{
	  memcpy ((((char *) *array) +
		   _svmf_aligned_size_t (sizeof (_svmt_array_instance))),
		  elems, size * sizeof (jdouble));
	  goto end;
	}
	break;

      case JNI_ABORT:
	{
	  _svmf_free (elems);
	  goto end;
	}
	break;

      default:
	{
	  _svmf_jni_fatal_error
	    ("invalid mode in ReleaseDoubleArrayElements call");
	}
	break;
      }
  }

end:
  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetObjectField (JNIEnv *_env, jobject obj, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;
    _svmt_object_instance *instance;

    instance = _svmf_get_REFERENCE_field (*obj, offset);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
SetObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetObjectField (JNIEnv *_env, jobject obj, jfieldID fieldID, jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    size_t offset = field->data.instance_field.offset;

    _svmf_put_REFERENCE_field (env, *obj, offset,
			       (value == NULL) ? NULL : *value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStaticObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetStaticObjectField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance;

    instance = *(field->data.class_field.value.l);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
SetStaticObjectField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetStaticObjectField (JNIEnv *_env, jclass cls SVM_UNUSED, jfieldID fieldID,
		      jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = fieldID;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *(field->data.class_field.value.l) = (value == NULL) ? NULL : *value;

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetFieldID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
GetFieldID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	field =
	  _svmf_resolve_field (vm->class_loading.boot_loader.classes.
			       jlobject, name, sig);
      }
    else
      {
	field = _svmf_resolve_field (_svmf_cast_class (type), name, sig);
      }

    if (field == NULL
	|| _svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field = NULL;
	_svmf_error_NoSuchFieldError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
GetStaticFieldID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
GetStaticFieldID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	field =
	  _svmf_resolve_field (vm->class_loading.boot_loader.classes.
			       jlobject, name, sig);
      }
    else
      {
	field = _svmf_resolve_field (_svmf_cast_class (type), name, sig);
      }

    if (field == NULL
	|| !_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field = NULL;
	_svmf_error_NoSuchFieldError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
DeleteLocalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteLocalRef (JNIEnv *_env, jobject localRef)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (localRef != NULL)
    {
      _svmt_stack_frame *frame = env->stack.current_frame;
      _svmt_stack_native_reference *lrefs =
	(_svmt_stack_native_reference *) (void *) (((char *) frame) +
						   frame->end_offset);
      jint lrefs_count = lrefs[-1].jint;
      size_t lrefs_size = lrefs[-2].size_t;
      jint i;

      lrefs =
	(_svmt_stack_native_reference *) (void *) (((char *) lrefs) -
						   lrefs_size);

      for (i = 0; i < lrefs_count; i++)
	{
	  if (lrefs[i].jobject == localRef)
	    {
	      *(lrefs[i].jobject) = NULL;
	      break;
	    }
	}
    }

  _svmm_stopping_java (env);
}


/*
----------------------------------------------------------------------
GetObjectClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
GetObjectClass (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    class = _svmf_get_jni_frame_native_local (env);
    *class = *((*obj)->vtable->type->class_instance);
  }

  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
ThrowNew
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
ThrowNew (JNIEnv *_env, jclass cls, const char *message)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    _svmt_method_info *method;
    jobject throwable;
    jstring msg;

    if (_svmf_link_class (env, class) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_class_initialization (env, class) != JNI_OK)
      {
	goto end;
      }

    throwable = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *throwable) != JNI_OK)
      {
	goto end;
      }

    msg = _svmf_get_jni_frame_native_local (env);
    if (_svmf_get_string (env, message, msg) != JNI_OK)
      {
	goto end;
      }

    method = _svmf_resolve_method (class, "<init>", "(Ljava/lang/String;)V");

    if (method == NULL)
      {
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }

    if (_svmm_invoke_specific_nonvirtual_throwinit
	(env, method, throwable, msg) != JNI_OK)
      {
	goto end;
      }

    *(env->throwable) = *throwable;

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewGlobalRef (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (obj == NULL || *obj == NULL)
    {
      goto end;
    }

  if (_svmm_new_native_global (env, result) != JNI_OK)
    {
      *(env->throwable) = NULL;
      goto end;
    }

  *result = *obj;

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringUTFLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetStringUTFLength (JNIEnv *_env, jstring string)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = 0;		/* init just to keep compiler happy */

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_invoke_static_stringcreator_getutflength (env, string, result);

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringUTFChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const char *JNICALL
GetStringUTFChars (JNIEnv *_env, jstring string, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  char *result = NULL;;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    char *chars;

    if (_svmm_galloc_utf_chars (env, string, chars) != JNI_OK)
      {
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    result = chars;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
ReleaseStringUTFChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringUTFChars (JNIEnv *_env, jstring string SVM_UNUSED,
		       const char *utf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    char *chars = (char *) utf;;

    _svmm_gfree_utf_chars (chars);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
ExceptionCheck
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
ExceptionCheck (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = *(env->throwable) != NULL;

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
SetObjectArrayElement
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetObjectArrayElement (JNIEnv *_env, jobjectArray array, jsize indx,
		       jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size = (*array)->size;

    /* check array bounds */
    if (((_svmt_u32) indx) >= (_svmt_u32) size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    if (_svmf_set_reference_array_element_no_exception
	(env, *array, indx, (value == NULL) ? NULL : *value) != JNI_OK)
      {
	_svmf_error_ArrayStoreException (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
NewStringUTF
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jstring JNICALL
NewStringUTF (JNIEnv *_env, const char *bytes)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  assert (*(env->throwable) == NULL);

  {
    string = _svmf_get_jni_frame_native_local (env);
    if (_svmf_get_string (env, bytes, string) != JNI_OK)
      {
	string = NULL;
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
NewObjectArray
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jarray JNICALL
NewObjectArray (JNIEnv *_env, jsize length, jclass elementClass,
		jobject initialElement)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jarray array = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, elementClass);
    _svmt_array_info *array_type;

    if (_svmm_create_array
	(env, type->class_loader_info, type->array_type_name,
	 array_type) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_link_array (env, array_type) != JNI_OK)
      {
	goto end;
      }

    array = _svmf_get_jni_frame_native_local_array (env);
    if (_svmm_new_array_instance (env, array_type, length, *array) != JNI_OK)
      {
	array = NULL;
	goto end;
      }

    if (initialElement != NULL)
      {
	_svmt_object_instance *value = *initialElement;
	_svmt_object_instance **elements;
	jint i;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	elements = (_svmt_object_instance **) *array;

#else

	elements = (_svmt_object_instance **) (void *)
	  (((char *) *array) +
	   _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

#endif

	for (i = 0; i < length; i++)
	  {
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	    elements[(-1) - i] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	    _svmf_write_barrier
	      (env, (_svmt_object_instance **) (void *) &elements[(-1) - i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
#else

	    elements[i] = value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	    _svmf_write_barrier
	      (env, (_svmt_object_instance **) &elements[i]);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
#endif
	  }
      }
  }

end:
  _svmm_stopping_java (env);

  return array;
}

/*
----------------------------------------------------------------------
GetMethodID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
GetMethodID (JNIEnv *_env, jclass cls, const char *name, const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_method_info *method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	method =
	  _svmf_resolve_method (vm->class_loading.boot_loader.classes.
				jlobject, name, sig);
      }
    else
      {
	method = _svmf_resolve_method (_svmf_cast_class (type), name, sig);
      }

    if (method == NULL
	|| _svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
      {
	method = NULL;
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
GetStaticMethodID
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
GetStaticMethodID (JNIEnv *_env, jclass cls, const char *name,
		   const char *sig)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_method_info *method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (_svmf_link_type (env, type) != JNI_OK)
      {
	goto end;
      }

    if (!type->is_array)
      {
	if (_svmf_class_initialization (env, _svmf_cast_class (type)) !=
	    JNI_OK)
	  {
	    _svmf_error_ExceptionInInitializerError (env);
	    goto end;
	  }
      }

    if (type->is_array)
      {
	method =
	  _svmf_resolve_method (vm->class_loading.boot_loader.classes.
				jlobject, name, sig);
      }
    else
      {
	method = _svmf_resolve_method (_svmf_cast_class (type), name, sig);
      }

    if (method == NULL
	|| !_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
      {
	method = NULL;
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
ExceptionDescribe
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ExceptionDescribe (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jthrowable throwable = _svmf_get_jni_frame_native_local (env);
    jstring jtext = _svmf_get_jni_frame_native_local (env);
    char *ctext = NULL;


    *throwable = *(env->throwable);
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiondescribe (env, throwable)
	== JNI_OK)
      {
	goto done;
      }

    /* There was an exception thrown while trying to print the stack
       trace using Java code. So, we now try to convert the whole
       exception & stack trace to a string, then print it here */

    /* forget the new exception */
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiondescription
	(env, throwable, jtext) != JNI_OK)
      {
	goto try_again;
      }

    if (_svmm_galloc_utf_chars (env, jtext, ctext) != JNI_OK)
      {
	goto try_again;
      }

    _svmf_printf (env, stderr, "%s\n", ctext);

    _svmm_gfree_utf_chars (ctext);

    goto done;

  try_again:
    /* There was yet again an exception trying to retrieve a full
       stack trace.  So, we try to at least provide the exception
       toString() info. */

    /* forget the new exception */
    *(env->throwable) = NULL;

    if (_svmm_invoke_static_virtualmachine_exceptiontruncateddescription
	(env, throwable, jtext) != JNI_OK)
      {
	goto try_one_last_time;
      }

    if (_svmm_galloc_utf_chars (env, jtext, ctext) != JNI_OK)
      {
	goto try_one_last_time;
      }

    _svmf_printf (env, stderr, "%s\n", ctext);

    _svmm_gfree_utf_chars (ctext);

    goto done;

  try_one_last_time:
    /* We were unable to get any info from Java. Print some minimal
       info. */

    /* forget the new exception */
    *(env->throwable) = NULL;

    /* print the old exception class name */
    _svmf_printf (env, stderr, "%s\n", (*throwable)->vtable->type->name);

  done:
    _svmm_release_jni_frame_native_local (throwable);
    _svmm_release_jni_frame_native_local (jtext);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
ExceptionOccurred
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jthrowable JNICALL
ExceptionOccurred (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jthrowable throwable = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (*(env->throwable) != NULL)
    {
      throwable = _svmf_get_jni_frame_native_local (env);
      *throwable = *(env->throwable);
    }

  _svmm_stopping_java (env);

  return throwable;
}

/*
----------------------------------------------------------------------
ExceptionClear
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ExceptionClear (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *(env->throwable) = NULL;

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetVersion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetVersion (JNIEnv *_env)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_stopping_java (env);

  return JNI_VERSION_1_4;
}

/*
----------------------------------------------------------------------
FindClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
FindClass (JNIEnv *_env, const char *name)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_stack_frame *frame = env->stack.current_frame;
    _svmt_class_loader_info *class_loader_info;


    /* get class loader */
    if (frame->method == &vm->stack_bottom_method)
      {
	jarray vmdata = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_invoke_static_virtualmachine_getsystemcl
	    (env, _svmf_cast_jobject (vmdata)) != JNI_OK)
	  {
	    goto end;
	  }
	class_loader_info = _svmf_unwrap_pointer (*vmdata);
	_svmm_release_jni_frame_native_local_array (vmdata);
      }
    else
      {
	class_loader_info = frame->method->class_info->class_loader_info;
      }

    /* load, link, and initialize type */
    {
      _svmt_type_info *type;

      if (_svmm_create_type (env, class_loader_info, name, type) != JNI_OK)
	{
	  goto end;
	}

      if (_svmf_link_type (env, type) != JNI_OK)
	{
	  goto end;
	}

      if (!(type->is_array))
	{
	  if (_svmf_class_initialization
	      (env, _svmf_cast_class (type)) != JNI_OK)
	    {
	      goto end;
	    }
	}

      class = _svmf_get_jni_frame_native_local (env);
      *class = *(type->class_instance);
    }
  }

end:
  _svmm_stopping_java (env);

  return class;
}

/*
----------------------------------------------------------------------
GetArrayLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetArrayLength (JNIEnv *_env, jarray array)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint size;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  size = (*array)->size;

  _svmm_stopping_java (env);

  return size;
}

/*
----------------------------------------------------------------------
DefineClass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
DefineClass (JNIEnv *_env, const char *name SVM_UNUSED,
	     jobject loader SVM_UNUSED, const jbyte *buf SVM_UNUSED,
	     jsize bufLen SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
GetSuperclass
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jclass JNICALL
GetSuperclass (JNIEnv *_env, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass super = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  /*
   * Note:
   * implementation very similar to Java_java_lang_VMClass_getSuperclass
   */
  {
    _svmt_JavaVM *vm = env->vm;
    /* Note: Will not work for Class of primitive types */
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, cls);

    if (type->is_array)
      {
	super = _svmf_get_jni_frame_native_local (env);
	*super =
	  *(vm->class_loading.boot_loader.classes.jlobject->class_instance);
	goto end;
      }
    if (_svmf_is_set_flag (type->access_flags, SVM_ACC_INTERFACE))
      {
	goto end;
      }

    /* has super type */
    super = _svmf_get_jni_frame_native_local (env);
    {
      _svmt_CONSTANT_Class_info *super_class;
      super_class = *(_svmf_cast_class (type)->super_class);
      if (super_class == NULL)
	{
	  super = NULL;
	  goto end;
	}
      else
	{
	  *super = *(super_class->type->class_instance);
	}
    }

  }
end:
  _svmm_stopping_java (env);

  return super;
}

/*
----------------------------------------------------------------------
IsAssignableFrom
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsAssignableFrom (JNIEnv *_env, jclass cls1, jclass cls2)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean is_assignable;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    /* Note: Will not work for Class of primitive types */
    _svmt_type_info *from = _svmf_unwrap_class_instance (env, cls1);
    _svmt_type_info *to = _svmf_unwrap_class_instance (env, cls2);

    is_assignable = _svmf_is_assignable_from (env, from, to);
  }

  _svmm_stopping_java (env);

  return is_assignable;
}

/*
----------------------------------------------------------------------
Throw
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
Throw (JNIEnv *_env, jthrowable obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    *(env->throwable) = *obj;
  }

  _svmm_stopping_java (env);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
FatalError
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
FatalError (JNIEnv *_env, const char *msg)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmm_fatal_error (msg);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
DeleteGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteGlobalRef (JNIEnv *_env, jobject globalRef)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmm_free_native_global (env, globalRef);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
IsSameObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsSameObject (JNIEnv *_env, jobject ref1, jobject ref2)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result = JNI_FALSE;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (ref1 == NULL)
      {
	if (ref2 == NULL)
	  {
	    result = JNI_TRUE;
	  }
	else
	  {
	    result = JNI_FALSE;
	  }
      }
    else
      {
	result = (*ref1 == *ref2) ? JNI_TRUE : JNI_FALSE;
      }
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
AllocObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
AllocObject (JNIEnv *_env, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObject
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObject (JNIEnv *_env, jclass cls, jmethodID methodID, ...)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    {
      va_list args;

      va_start (args, methodID);

      _svmf_internal_CallNonvirtualVoidMethodV (env, instance, cls, methodID,
						args);

      va_end (args);
    }

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObjectV
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObjectV (JNIEnv *_env, jclass cls, jmethodID methodID, va_list args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    _svmf_internal_CallNonvirtualVoidMethodV (env, instance, cls, methodID,
					      args);

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewObjectA
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewObjectA (JNIEnv *_env, jclass cls, jmethodID methodID, jvalue *args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, cls));
    jobject instance;

    /* allocate new instance */
    instance = _svmf_get_jni_frame_native_local (env);
    if (_svmm_new_object_instance (env, class, *instance) != JNI_OK)
      {
	goto end;
      }

    /* call constructor */
    _svmf_internal_CallNonvirtualVoidMethodA (env, instance, cls, methodID,
					      args);

    /* if no exception was raised, return new instance */
    if (*(env->throwable) == NULL)
      {
	result = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
IsInstanceOf
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean JNICALL
IsInstanceOf (JNIEnv *_env, jobject obj, jclass cls)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	result = JNI_TRUE;
      }
    else
      {
	/* Note: Will not work for Class of primitive types */
	_svmt_type_info *T = _svmf_unwrap_class_instance (env, cls);
	_svmt_type_info *S = (*obj)->vtable->type;

	result = _svmf_is_assignable_from (env, S, T);
      }
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewString
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jstring JNICALL
NewString (JNIEnv *_env, const jchar *unicodeChars, jsize len)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  jstring string = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jcharArray data = NULL;

    if (_svmm_new_native_local_array (env, data) != JNI_OK)
      {
	goto end;
      }

    if (_svmm_new_array_instance
	(env, vm->class_loading.boot_loader.classes.char_array, len,
	 *data) != JNI_OK)
      {
	_svmm_free_native_local_array (env, data);
	goto end;
      }

    /* put the string characters into the array */
    if (len > 0)
      {
	memcpy (((char *) *data) +
		_svmf_aligned_size_t (sizeof (_svmt_array_instance)),
		unicodeChars, len * sizeof (jchar));
      }

    string = _svmf_get_jni_frame_native_local (env);

    if (_svmm_invoke_static_stringcreator_createstringfromchars
	(env, _svmf_cast_jobject (data), string) == JNI_ERR)
      {
	_svmm_free_native_local_array (env, data);
	_svmm_release_jni_frame_native_local (string);
	goto end;
      }

    _svmm_free_native_local_array (env, data);
  }

end:
  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
GetStringLength
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jsize JNICALL
GetStringLength (JNIEnv *_env, jstring string)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result = -1;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_invoke_static_stringcreator_getlength (env, string, result) !=
      JNI_OK)
    {
      goto end;
    }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetStringChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const jchar *JNICALL
GetStringChars (JNIEnv *_env, jstring string, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jcharArray chars;
  jchar *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_new_native_local_array (env, chars) != JNI_OK)
    {
      goto end;
    }

  if (_svmm_invoke_static_stringcreator_getchars
      (env, string, _svmf_cast_jobject (chars)) != JNI_OK)
    {
      _svmm_free_native_local_array (env, chars);
      goto end;
    }

  {
    jchar *elements = (jchar *) (void *)
      (((char *) *chars) +
       _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
    jint size = (*chars)->size;

    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	result = elements;

	_svmm_free_native_local_array (env, chars);
	goto end;
      }

    if (_svmm_gmalloc_chars (env, size, result) != JNI_OK)
      {
	_svmm_free_native_local_array (env, chars);
	goto end;
      }

    if (isCopy != NULL)
      {
	*isCopy = JNI_TRUE;
      }

    memcpy (result, elements, size * sizeof (jchar));
    _svmm_free_native_local_array (env, chars);

  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
ReleaseStringChars
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringChars (JNIEnv *_env, jstring string, const jchar *_chars)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    jint size;

    if (_svmm_invoke_static_stringcreator_getlength (env, string, size) !=
	JNI_OK)
      {
	goto end;
      }

    if (size != 0)
      {
	jchar *chars = (jchar *) _chars;	/* to eliminate compile error */
	_svmm_gmfree_chars (chars);
	_chars = NULL;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetObjectArrayElement
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
GetObjectArrayElement (JNIEnv *_env, jobjectArray array, jsize indx)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint size;
  jobject value = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_object_instance *instance;

    if (array == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    size = (*array)->size;

    if (((_svmt_u32) indx) >= (_svmt_u32) size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    instance = _svmf_get_reference_array_element (*array, indx);
    if (instance != NULL)
      {
	value = _svmf_get_jni_frame_native_local (env);
	*value = instance;
      }
  }

end:
  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
GetBooleanArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jboolean *JNICALL
GetBooleanArrayElements (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
			 jboolean *isCopy SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
ReleaseBooleanArrayElements
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseBooleanArrayElements (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
			     jboolean *elems SVM_UNUSED, jint mode SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetBooleanArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetBooleanArrayRegion (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
		       jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		       jboolean *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
SetBooleanArrayRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
SetBooleanArrayRegion (JNIEnv *_env, jbooleanArray array SVM_UNUSED,
		       jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		       jboolean *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
RegisterNatives
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
RegisterNatives (JNIEnv *_env, jclass cls SVM_UNUSED,
		 const JNINativeMethod *methods SVM_UNUSED,
		 jint nMethods SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
UnregisterNatives
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
UnregisterNatives (JNIEnv *_env, jclass cls SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
MonitorEnter
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
MonitorEnter (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    if (_svmf_enter_object_monitor (env, *obj) != JNI_OK)
      {
	goto end;
      }

    /* structured locking */
    env->stack.current_frame->lock_count++;

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
MonitorExit
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
MonitorExit (JNIEnv *_env, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  jint result = JNI_ERR;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    if (obj == NULL)
      {
	_svmf_error_NullPointerException (env);
	goto end;
      }

    /* structured locking */
    if (--(env->stack.current_frame->lock_count) < 0
	&& env->vm->enforce_structured_locking)
      {
	_svmf_error_IllegalMonitorStateException (env);
	goto end;
      }

    if (_svmf_exit_object_monitor (env, *obj) != JNI_OK)
      {
	goto end;
      }

    result = JNI_OK;
  }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetJavaVM
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
GetJavaVM (JNIEnv *_env, JavaVM **vm)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  *vm = _svmf_cast_JavaVM (env->vm);

  _svmm_stopping_java (env);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
EnsureLocalCapacity
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
EnsureLocalCapacity (JNIEnv *_env, jint capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = _svmf_ensure_native_local_capacity (env, capacity);

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
PushLocalFrame
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jint JNICALL
PushLocalFrame (JNIEnv *_env, jint capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_stack_native_reference *lrefs;

  jint lrefs_count = _svmf_max_jint (capacity, SVM_FRAME_NATIVE_REFS_MIN);
  size_t lrefs_size = _svmf_aligned_size_t
    ((lrefs_count + 2) * sizeof (_svmt_stack_native_reference));
  jint i;
  jint result = JNI_OK;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmf_ensure_stack_capacity (env, lrefs_size) != JNI_OK)
    {
      result = JNI_ERR;
      goto end;
    }

  frame = env->stack.current_frame;

  frame->end_offset += lrefs_size;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame->end_offset);
  lrefs[-1].jint = lrefs_count;
  lrefs[-2].size_t = lrefs_size;

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

  /* just in case we've ran out of memory during refs creation */
  memset (lrefs, 0, lrefs_count * sizeof (_svmt_stack_native_reference));

  for (i = 0; i < lrefs_count; i++)
    {
      if (_svmm_new_native_local (env, lrefs[i].jobject) != JNI_OK)
	{
	  result = JNI_ERR;
	  goto end;
	}
    }

end:
  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
PopLocalFrame
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
PopLocalFrame (JNIEnv *_env, jobject ref)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_stack_native_reference *lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) frame) +
					       frame->end_offset);

  jint lrefs_count = lrefs[-1].jint;
  size_t lrefs_size = lrefs[-2].size_t;

  jint i;
  jobject result = NULL;
  _svmt_object_instance *saved_ref = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  /* temporarily remember the direct address of the result object, if there
     is one, just in case ref is a local ref in the top localref frame 
     (so ref will be freed below). */
  if (ref != NULL)
    {
      /* VERY IMPORTANT: As saved_ref is a direct pointer, we must make sure
         that we do not call any function that could potentially disturb the
         heap and cause GC. */
      saved_ref = *ref;
    }

  lrefs =
    (_svmt_stack_native_reference *) (void *) (((char *) lrefs) - lrefs_size);

#ifndef NDEBUG
  /* Don't allow to pop the initial native frame. 
   * Normally we don't check this as the JNI code is expected to be well-behaved, 
   * according to the specs. */

  if (!(lrefs > ((_svmt_stack_native_reference *) (void *)
		 (((char *) frame) + _svmv_stack_offset))))
    {
      _svmm_fatal_error ("Trying to pop the initial local native frame.\n"
			 "** This is a bug in the application you are trying to run.\n"
			 "** It is not allowed to call PopLocalFrame() more times than\n"
			 "** PushLocalFrame() has been called.\n");
    }

#endif

  frame->end_offset -= lrefs_size;

  for (i = 0; i < lrefs_count; i++)
    {
      if (lrefs[i].jobject !=NULL)
	{
	  /* Does not affect the heap nor cause GC.  See above
	     comment. */
	  _svmm_free_native_local (env, lrefs[i].jobject);
	}
    }

  if (ref != NULL)
    {
      /* Does not affect the heap nor cause GC (unless FatalError is
         called).  See above comment. */
      result = _svmf_get_jni_frame_native_local (env);
      *result = saved_ref;
    }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
NewLocalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewLocalRef (JNIEnv *_env, jobject ref SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
NewWeakGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jweak JNICALL
NewWeakGlobalRef (JNIEnv *_env, jobject obj SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
DeleteWeakGlobalRef
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
DeleteWeakGlobalRef (JNIEnv *_env, jweak obj SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetPrimitiveArrayCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void *JNICALL
GetPrimitiveArrayCritical (JNIEnv *_env, jarray array, jboolean *isCopy)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  void *result = NULL;

  assert (env == _svmf_get_current_env ());

  /* we only resume java if we are entering the critical section */
  if (env->critical_section_count == 0)
    {
      _svmm_resuming_java (env);
    }

  /* it must be an non-null ref to an array */
  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;
    _svmt_array_info *type = _svmf_cast_array ((*array)->vtable->type);

    assert (type->dimensions == 1);
    assert (type->base_type != SVM_TYPE_VOID);
    assert (type->base_type != SVM_TYPE_REFERENCE);

    /* if array has length 0, return some pointer != NULL */
    if (size == 0)
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	/* As the length is 0, we might as well return a direct
	   pointer to the elements.  This way, we'll be sure the
	   pointer is not NULL. */
	result = (void *) (((char *) *array) +
			   _svmf_aligned_size_t (sizeof
						 (_svmt_array_instance)));

	/* we must record the number of times JNI code reenters this
	   critical section. */
	env->critical_section_count++;
      }
    else if (type->base_type != SVM_TYPE_BOOLEAN)
      {
	/* if the array is not a boolean array, simply return a direct
	   pointer to the elements */

	if (isCopy != NULL)
	  {
	    *isCopy = JNI_FALSE;
	  }

	result = (void *) (((char *) *array) +
			   _svmf_aligned_size_t (sizeof
						 (_svmt_array_instance)));

	/* we must record the number of times JNI code reenters this
	   critical section. */
	env->critical_section_count++;
      }
    else
      {
	if (isCopy != NULL)
	  {
	    *isCopy = JNI_TRUE;
	  }

	_svmm_fatal_error ("todo");
      }
  }

  /* in a critical section, we do not call _svmm_stopping_java (env); */

  return result;
}

/*
----------------------------------------------------------------------
ReleasePrimitiveArrayCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleasePrimitiveArrayCritical (JNIEnv *_env, jarray array,
			       void *carray SVM_UNUSED, jint mode SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  /* in a critical section, we do not call _svmm_resuming_java (env); */

  /* it must be an non-null ref to an array */
  assert (array != NULL);
  assert ((*array)->vtable->type->is_array == JNI_TRUE);

  {
    jint size = (*array)->size;
    _svmt_array_info *type = _svmf_cast_array ((*array)->vtable->type);

    assert (type->base_type != SVM_TYPE_VOID);
    assert (type->base_type != SVM_TYPE_REFERENCE);

    /* if array has length 0, we have nothing to do */
    if (size == 0)
      {
      }
    else if (type->base_type != SVM_TYPE_BOOLEAN)
      {
	/* if the array is not a boolean array, we have nothing to
	   do */
      }
    else
      {
	_svmm_fatal_error ("todo");
      }
  }

  env->critical_section_count--;

  if (env->critical_section_count == 0)
    {
      /* stepping out of a critical section */
      _svmm_stopping_java (env);
    }
}

/*
----------------------------------------------------------------------
GetStringRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetStringRegion (JNIEnv *_env, jstring str SVM_UNUSED, jsize start SVM_UNUSED,
		 jsize len SVM_UNUSED, jchar *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStringUTFRegion
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
GetStringUTFRegion (JNIEnv *_env, jstring str SVM_UNUSED,
		    jsize start SVM_UNUSED, jsize len SVM_UNUSED,
		    char *buf SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
GetStringCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static const jchar *JNICALL
GetStringCritical (JNIEnv *_env, jstring string SVM_UNUSED,
		   jboolean *isCopy SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);

  return NULL;
}

/*
----------------------------------------------------------------------
ReleaseStringCritical
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void JNICALL
ReleaseStringCritical (JNIEnv *_env, jstring string SVM_UNUSED,
		       const jchar *carray SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  _svmm_fatal_error ("todo");

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
FromReflectedMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jmethodID JNICALL
FromReflectedMethod (JNIEnv *_env, jobject method)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_JavaVM *vm = env->vm;
  _svmt_method_info *method_id;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmf_cast_class ((*method)->vtable->type) ==
      vm->class_loading.boot_loader.classes.jlrmethod)
    {
      method_id = _svmf_unwrap_method_instance (env, method);
    }
  else
    {
      assert (_svmf_cast_class ((*method)->vtable->type) ==
	      vm->class_loading.boot_loader.classes.jlrconstructor);

      method_id = _svmf_unwrap_constructor_instance (env, method);
    }

  _svmm_stopping_java (env);

  return method_id;
}

/*
----------------------------------------------------------------------
FromReflectedField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jfieldID JNICALL
FromReflectedField (JNIEnv *_env, jobject field)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  _svmt_field_info *field_id;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  field_id = _svmf_unwrap_field_instance (env, field);

  _svmm_stopping_java (env);

  return field_id;
}

/*
----------------------------------------------------------------------
ToReflectedMethod
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
ToReflectedMethod (JNIEnv *_env, jclass cls SVM_UNUSED,
		   jmethodID methodID, jboolean isStatic SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject method = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    method = _svmf_get_jni_frame_native_local (env);

    if (methodID->reflection_instance == NULL)
      {
	/* create Method instance and cache it */

	jbyteArray wrapper;

	wrapper = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_local_wrap_pointer (env, methodID, wrapper) != JNI_OK)
	  {
	    goto end;
	  }

	if (DREF (methodID->name, value)[0] == '<')
	  {
	    /* Constructor */

	    if (_svmm_new_object_instance
		(env,
		 vm->class_loading.boot_loader.classes.jlrconstructor,
		 *method) != JNI_OK)
	      {
		goto end;
	      }

	    if (_svmm_invoke_nonvirtual_jlrconstructor_init
		(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
	      {
		goto end;
	      }

	  }
	else
	  {
	    /* Method */
	    if (_svmm_new_object_instance
		(env,
		 vm->class_loading.boot_loader.classes.jlrmethod,
		 *method) != JNI_OK)
	      {
		goto end;
	      }

	    if (_svmm_invoke_nonvirtual_jlrmethod_init
		(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
	      {
		goto end;
	      }
	  }


	if (_svmm_new_native_global
	    (env, methodID->reflection_instance) != JNI_OK)
	  {
	    goto end;
	  }

	*(methodID->reflection_instance) = *method;

      }
    else
      {
	*method = *(methodID->reflection_instance);
      }

  }

end:
  _svmm_stopping_java (env);

  return method;
}

/*
----------------------------------------------------------------------
ToReflectedField
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
ToReflectedField (JNIEnv *_env, jclass cls SVM_UNUSED,
		  jfieldID fieldID, jboolean isStatic SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject field = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    field = _svmf_get_jni_frame_native_local (env);

    if (fieldID->reflection_instance == NULL)
      {
	/* create Field instance and cache it */

	jbyteArray wrapper;

	wrapper = _svmf_get_jni_frame_native_local_array (env);
	if (_svmm_local_wrap_pointer (env, fieldID, wrapper) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_new_object_instance
	    (env,
	     vm->class_loading.boot_loader.classes.jlrfield,
	     *field) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_invoke_nonvirtual_jlrfield_init
	    (env, field, _svmf_cast_jobject (wrapper)) != JNI_OK)
	  {
	    goto end;
	  }

	if (_svmm_new_native_global
	    (env, fieldID->reflection_instance) != JNI_OK)
	  {
	    goto end;
	  }

	*(fieldID->reflection_instance) = *field;

      }
    else
      {
	*field = *(fieldID->reflection_instance);
      }

  }

end:
  _svmm_stopping_java (env);

  return field;
}

/*
----------------------------------------------------------------------
NewDirectByteBuffer
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jobject JNICALL
NewDirectByteBuffer (JNIEnv *_env, void *address, jlong capacity)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  result = _svmf_get_jni_frame_native_local (env);

#if SVM_WORD_BIT_COUNT == 32

  if (_svmm_invoke_static_niobytebuffervm_newbuffer32
      (env, (jint) address, capacity, result) != JNI_OK)
    {
      _svmm_release_jni_frame_native_local (result);
    }

#elif SVM_WORD_BIT_COUNT == 64

  if (_svmm_invoke_static_niobytebuffervm_newbuffer64
      (env, (jlong) address, capacity, result) != JNI_OK)
    {
      _svmm_release_jni_frame_native_local (result);
    }

#else

#error "todo: implement nio for non 32 or 64 bit platforms"

#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetDirectBufferAddress
----------------------------------------------------------------------
*/

JNIEXPORT svm_static void *JNICALL
GetDirectBufferAddress (JNIEnv *_env, jobject buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  void *result = NULL;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

#if SVM_WORD_BIT_COUNT == 32

  {
    jint value;

    if (_svmm_invoke_static_niobytebuffervm_getaddress32 (env, buf, value) ==
	JNI_OK)
      {
	result = (void *) value;
      }
  }

#elif SVM_WORD_BIT_COUNT == 64

  {
    jlong value;

    if (_svmm_invoke_static_niobytebuffervm_getaddress64 (env, buf, value) ==
	JNI_OK)
      {
	result = (void *) value;
      }
  }

#else

#error "todo: implement nio for non 32 or 64 bit platforms"

#endif

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
GetDirectBufferCapacity
----------------------------------------------------------------------
*/

JNIEXPORT svm_static jlong JNICALL
GetDirectBufferCapacity (JNIEnv *_env, jobject buf)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong result = -1;

  assert (env == _svmf_get_current_env ());

  _svmm_resuming_java (env);

  if (_svmm_invoke_static_niobytebuffervm_getcapacity (env, buf, result) !=
      JNI_OK)
    {
      result = -1;
    }

  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
_svmv_native_interface
----------------------------------------------------------------------
*/

static const JNINativeInterface _svmv_native_interface = {
  NULL,
  NULL,
  NULL,
  NULL,
  GetVersion,
  DefineClass,
  FindClass,
  FromReflectedMethod,
  FromReflectedField,
  ToReflectedMethod,
  GetSuperclass,
  IsAssignableFrom,
  ToReflectedField,
  Throw,
  ThrowNew,
  ExceptionOccurred,
  ExceptionDescribe,
  ExceptionClear,
  FatalError,
  PushLocalFrame,
  PopLocalFrame,
  NewGlobalRef,
  DeleteGlobalRef,
  DeleteLocalRef,
  IsSameObject,
  NewLocalRef,
  EnsureLocalCapacity,
  AllocObject,
  NewObject,
  NewObjectV,
  NewObjectA,
  GetObjectClass,
  IsInstanceOf,
  GetMethodID,
  CallObjectMethod,
  CallObjectMethodV,
  CallObjectMethodA,
  CallBooleanMethod,
  CallBooleanMethodV,
  CallBooleanMethodA,
  CallByteMethod,
  CallByteMethodV,
  CallByteMethodA,
  CallCharMethod,
  CallCharMethodV,
  CallCharMethodA,
  CallShortMethod,
  CallShortMethodV,
  CallShortMethodA,
  CallIntMethod,
  CallIntMethodV,
  CallIntMethodA,
  CallLongMethod,
  CallLongMethodV,
  CallLongMethodA,
  CallFloatMethod,
  CallFloatMethodV,
  CallFloatMethodA,
  CallDoubleMethod,
  CallDoubleMethodV,
  CallDoubleMethodA,
  CallVoidMethod,
  CallVoidMethodV,
  CallVoidMethodA,
  CallNonvirtualObjectMethod,
  CallNonvirtualObjectMethodV,
  CallNonvirtualObjectMethodA,
  CallNonvirtualBooleanMethod,
  CallNonvirtualBooleanMethodV,
  CallNonvirtualBooleanMethodA,
  CallNonvirtualByteMethod,
  CallNonvirtualByteMethodV,
  CallNonvirtualByteMethodA,
  CallNonvirtualCharMethod,
  CallNonvirtualCharMethodV,
  CallNonvirtualCharMethodA,
  CallNonvirtualShortMethod,
  CallNonvirtualShortMethodV,
  CallNonvirtualShortMethodA,
  CallNonvirtualIntMethod,
  CallNonvirtualIntMethodV,
  CallNonvirtualIntMethodA,
  CallNonvirtualLongMethod,
  CallNonvirtualLongMethodV,
  CallNonvirtualLongMethodA,
  CallNonvirtualFloatMethod,
  CallNonvirtualFloatMethodV,
  CallNonvirtualFloatMethodA,
  CallNonvirtualDoubleMethod,
  CallNonvirtualDoubleMethodV,
  CallNonvirtualDoubleMethodA,
  CallNonvirtualVoidMethod,
  CallNonvirtualVoidMethodV,
  CallNonvirtualVoidMethodA,
  GetFieldID,
  GetObjectField,
  GetBooleanField,
  GetByteField,
  GetCharField,
  GetShortField,
  GetIntField,
  GetLongField,
  GetFloatField,
  GetDoubleField,
  SetObjectField,
  SetBooleanField,
  SetByteField,
  SetCharField,
  SetShortField,
  SetIntField,
  SetLongField,
  SetFloatField,
  SetDoubleField,
  GetStaticMethodID,
  CallStaticObjectMethod,
  CallStaticObjectMethodV,
  CallStaticObjectMethodA,
  CallStaticBooleanMethod,
  CallStaticBooleanMethodV,
  CallStaticBooleanMethodA,
  CallStaticByteMethod,
  CallStaticByteMethodV,
  CallStaticByteMethodA,
  CallStaticCharMethod,
  CallStaticCharMethodV,
  CallStaticCharMethodA,
  CallStaticShortMethod,
  CallStaticShortMethodV,
  CallStaticShortMethodA,
  CallStaticIntMethod,
  CallStaticIntMethodV,
  CallStaticIntMethodA,
  CallStaticLongMethod,
  CallStaticLongMethodV,
  CallStaticLongMethodA,
  CallStaticFloatMethod,
  CallStaticFloatMethodV,
  CallStaticFloatMethodA,
  CallStaticDoubleMethod,
  CallStaticDoubleMethodV,
  CallStaticDoubleMethodA,
  CallStaticVoidMethod,
  CallStaticVoidMethodV,
  CallStaticVoidMethodA,
  GetStaticFieldID,
  GetStaticObjectField,
  GetStaticBooleanField,
  GetStaticByteField,
  GetStaticCharField,
  GetStaticShortField,
  GetStaticIntField,
  GetStaticLongField,
  GetStaticFloatField,
  GetStaticDoubleField,
  SetStaticObjectField,
  SetStaticBooleanField,
  SetStaticByteField,
  SetStaticCharField,
  SetStaticShortField,
  SetStaticIntField,
  SetStaticLongField,
  SetStaticFloatField,
  SetStaticDoubleField,
  NewString,
  GetStringLength,
  GetStringChars,
  ReleaseStringChars,
  NewStringUTF,
  GetStringUTFLength,
  GetStringUTFChars,
  ReleaseStringUTFChars,
  GetArrayLength,
  NewObjectArray,
  GetObjectArrayElement,
  SetObjectArrayElement,
  NewBooleanArray,
  NewByteArray,
  NewCharArray,
  NewShortArray,
  NewIntArray,
  NewLongArray,
  NewFloatArray,
  NewDoubleArray,
  GetBooleanArrayElements,
  GetByteArrayElements,
  GetCharArrayElements,
  GetShortArrayElements,
  GetIntArrayElements,
  GetLongArrayElements,
  GetFloatArrayElements,
  GetDoubleArrayElements,
  ReleaseBooleanArrayElements,
  ReleaseByteArrayElements,
  ReleaseCharArrayElements,
  ReleaseShortArrayElements,
  ReleaseIntArrayElements,
  ReleaseLongArrayElements,
  ReleaseFloatArrayElements,
  ReleaseDoubleArrayElements,
  GetBooleanArrayRegion,
  GetByteArrayRegion,
  GetCharArrayRegion,
  GetShortArrayRegion,
  GetIntArrayRegion,
  GetLongArrayRegion,
  GetFloatArrayRegion,
  GetDoubleArrayRegion,
  SetBooleanArrayRegion,
  SetByteArrayRegion,
  SetCharArrayRegion,
  SetShortArrayRegion,
  SetIntArrayRegion,
  SetLongArrayRegion,
  SetFloatArrayRegion,
  SetDoubleArrayRegion,
  RegisterNatives,
  UnregisterNatives,
  MonitorEnter,
  MonitorExit,
  GetJavaVM,
  GetStringRegion,
  GetStringUTFRegion,
  GetPrimitiveArrayCritical,
  ReleasePrimitiveArrayCritical,
  GetStringCritical,
  ReleaseStringCritical,
  NewWeakGlobalRef,
  DeleteWeakGlobalRef,
  ExceptionCheck,
  NewDirectByteBuffer,
  GetDirectBufferAddress,
  GetDirectBufferCapacity
};

/* end of file */
   
