/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*
 * Note: For all getTYPE() and setTYPE(), all checks (security, correct
 *       field type, null pointer, etc.) should be done on the Java
 *       side.  The nativeGetTYPE() and nativeSetTYPE() handles only
 *       the non-exceptional cases.
 *
 */


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetDeclaringClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetDeclaringClass
 * Signature: ([B)Ljava/lang/Class;
 */
JNIEXPORT static jclass JNICALL
Java_java_lang_reflect_Field_nativeGetDeclaringClass (JNIEnv *_env,
						      jclass _class
						      SVM_UNUSED,
						      jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass dclass;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    dclass = _svmf_get_jni_frame_native_local (env);
    *dclass = *(field->class_info->class_instance);
  }

  _svmm_stopping_java (env);

  return dclass;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetModifiers
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetModifiers
 * Signature: ([B)I
 */
JNIEXPORT static jint JNICALL
Java_java_lang_reflect_Field_nativeGetModifiers (JNIEnv *_env,
						 jobject _class SVM_UNUSED,
						 jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint modifiers;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    /* make sure not to return any internal flags */
    modifiers = field->access_flags &
      (SVM_ACC_PUBLIC |
       SVM_ACC_PRIVATE |
       SVM_ACC_PROTECTED |
       SVM_ACC_STATIC | SVM_ACC_FINAL | SVM_ACC_TRANSIENT | SVM_ACC_VOLATILE);
  }

  _svmm_stopping_java (env);

  return modifiers;

}



/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetType
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetType
 * Signature: ([B)Ljava/lang/Class;
 */
JNIEXPORT static jclass JNICALL
Java_java_lang_reflect_Field_nativeGetType (JNIEnv *_env,
					    jclass _class SVM_UNUSED,
					    jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    switch (field->type)
      {
      case SVM_TYPE_BOOLEAN:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.boolean_type);
	break;
      case SVM_TYPE_BYTE:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.byte_type);
	break;
      case SVM_TYPE_SHORT:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.short_type);
	break;
      case SVM_TYPE_CHAR:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.char_type);
	break;
      case SVM_TYPE_INT:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.int_type);
	break;
      case SVM_TYPE_LONG:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.long_type);
	break;
      case SVM_TYPE_FLOAT:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.float_type);
	break;
      case SVM_TYPE_DOUBLE:
	class = _svmf_get_jni_frame_native_local (env);
	*class = *(vm->class_loading.boot_loader.instances.double_type);
	break;
      case SVM_TYPE_REFERENCE:
	{
	  /* Based on JNI FindClass */
	  char *descriptor;
	  char *name = NULL;
	  jboolean free_name;
	  _svmt_class_loader_info *class_loader_info;

	  descriptor = DREF (field->descriptor, value);

	  assert (descriptor != NULL);
	  assert (descriptor[0] == 'L' || descriptor[0] == '[');

	  if (descriptor[0] == 'L')
	    {
	      /*
	       * Convert name for non-array types.
	       *
	       * Ljava/lang/String; -> java/lang/String
	       *
	       */
	      size_t len;
	      len = strlen (descriptor) - 2;
	      name = _svmf_malloc (len + 1);
	      if (name == NULL)
		{
		  _svmf_error_OutOfMemoryError (env);
		  goto end;
		}
	      strncpy (name, descriptor + 1, len);
	      name[len] = '\0';
	      free_name = JNI_TRUE;
	    }
	  else
	    {
	      name = descriptor;
	      free_name = JNI_FALSE;
	    }

	  class_loader_info = field->class_info->class_loader_info;


	  /* load, link, and initialize type */
	  {
	    _svmt_type_info *type;

	    if (_svmm_create_type (env, class_loader_info, name, type) !=
		JNI_OK)
	      {
		if (free_name)
		  {
		    _svmf_free (name);
		  }

		goto end;
	      }

	    if (free_name)
	      {
		_svmf_free (name);
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
	break;

      default:
	_svmm_fatal_error ("impossible control flow");
	break;
      }
  }

end:
  _svmm_stopping_java (env);

  return class;

}



/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetName
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetName
 * Signature: ([B)Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_java_lang_reflect_Field_nativeGetName (JNIEnv *_env,
					    jclass _class SVM_UNUSED,
					    jbyteArray vmData)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring name;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    name = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, DREF (field->name, value), name);
  }

  _svmm_stopping_java (env);

  return name;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetReference
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetReference
 * Signature: ([BLjava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT static jobject JNICALL
Java_java_lang_reflect_Field_nativeGetReference (JNIEnv *_env,
						 jobject this SVM_UNUSED,
						 jbyteArray vmData,
						 jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject value = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_REFERENCE);

    value = _svmf_get_jni_frame_native_local (env);
    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	*value = *(field->data.class_field.value.l);
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	*value = _svmf_get_REFERENCE_field (*instance, offset);
      }
  }

  _svmm_stopping_java (env);

  return value;
}



/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetBoolean
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetBoolean
 * Signature: ([BLjava/lang/Object;)Z
 */
JNIEXPORT static jboolean JNICALL
Java_java_lang_reflect_Field_nativeGetBoolean (JNIEnv *_env,
					       jobject this SVM_UNUSED,
					       jbyteArray vmData,
					       jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean value;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_BOOLEAN);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	value = field->data.class_field.value.z;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	value = _svmf_get_BOOLEAN_field (*instance, offset);
      }
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetByte
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetByte
 * Signature: ([BLjava/lang/Object;)B
 */
JNIEXPORT static jbyte JNICALL
Java_java_lang_reflect_Field_nativeGetByte (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jbyte value;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_BYTE);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	value = field->data.class_field.value.b;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	value = _svmf_get_BYTE_field (*instance, offset);
      }
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetChar
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetChar
 * Signature: ([BLjava/lang/Object;)C
 */
JNIEXPORT static jchar JNICALL
Java_java_lang_reflect_Field_nativeGetChar (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jchar value;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_CHAR);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	value = field->data.class_field.value.c;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	value = _svmf_get_CHAR_field (*instance, offset);
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetShort
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetShort
 * Signature: ([BLjava/lang/Object;)S
 */
JNIEXPORT static jshort JNICALL
Java_java_lang_reflect_Field_nativeGetShort (JNIEnv *_env,
					     jobject this SVM_UNUSED,
					     jbyteArray vmData,
					     jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jshort value;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert ((field->type == SVM_TYPE_BYTE) ||
	    (field->type == SVM_TYPE_SHORT));


    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	if (field->type == SVM_TYPE_BYTE)
	  {
	    value = field->data.class_field.value.b;
	  }
	else
	  {
	    value = field->data.class_field.value.s;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	if (field->type == SVM_TYPE_BYTE)
	  {
	    value = _svmf_get_BYTE_field (*instance, offset);
	  }
	else
	  {
	    value = _svmf_get_SHORT_field (*instance, offset);
	  }
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetInt
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetInt
 * Signature: ([BLjava/lang/Object;)I
 */
JNIEXPORT static jint JNICALL
Java_java_lang_reflect_Field_nativeGetInt (JNIEnv *_env,
					   jobject this SVM_UNUSED,
					   jbyteArray vmData,
					   jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint value = 0;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert ((field->type == SVM_TYPE_BYTE) ||
	    (field->type == SVM_TYPE_SHORT) ||
	    (field->type == SVM_TYPE_CHAR) || (field->type == SVM_TYPE_INT));


    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = field->data.class_field.value.b;
	    break;
	  case SVM_TYPE_SHORT:
	    value = field->data.class_field.value.s;
	    break;
	  case SVM_TYPE_CHAR:
	    value = field->data.class_field.value.c;
	    break;
	  case SVM_TYPE_INT:
	    value = field->data.class_field.value.i;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = _svmf_get_BYTE_field (*instance, offset);
	    break;
	  case SVM_TYPE_SHORT:
	    value = _svmf_get_SHORT_field (*instance, offset);
	    break;
	  case SVM_TYPE_CHAR:
	    value = _svmf_get_CHAR_field (*instance, offset);
	    break;
	  case SVM_TYPE_INT:
	    value = _svmf_get_INT_field (*instance, offset);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetLong
----------------------------------------------------------------------
*/



/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetLong
 * Signature: ([BLjava/lang/Object;)J
 */
JNIEXPORT static jlong JNICALL
Java_java_lang_reflect_Field_nativeGetLong (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jlong value = 0;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert ((field->type == SVM_TYPE_BYTE) ||
	    (field->type == SVM_TYPE_SHORT) ||
	    (field->type == SVM_TYPE_CHAR) ||
	    (field->type == SVM_TYPE_INT) || (field->type == SVM_TYPE_LONG));


    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = field->data.class_field.value.b;
	    break;
	  case SVM_TYPE_SHORT:
	    value = field->data.class_field.value.s;
	    break;
	  case SVM_TYPE_CHAR:
	    value = field->data.class_field.value.c;
	    break;
	  case SVM_TYPE_INT:
	    value = field->data.class_field.value.i;
	    break;
	  case SVM_TYPE_LONG:
	    value = field->data.class_field.value.j;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = _svmf_get_BYTE_field (*instance, offset);
	    break;
	  case SVM_TYPE_SHORT:
	    value = _svmf_get_SHORT_field (*instance, offset);
	    break;
	  case SVM_TYPE_CHAR:
	    value = _svmf_get_CHAR_field (*instance, offset);
	    break;
	  case SVM_TYPE_INT:
	    value = _svmf_get_INT_field (*instance, offset);
	    break;
	  case SVM_TYPE_LONG:
	    value = _svmf_get_LONG_field (*instance, offset);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
  }

  _svmm_stopping_java (env);

  return value;
}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetFloat
----------------------------------------------------------------------
*/



/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetFloat
 * Signature: ([BLjava/lang/Object;)F
 */
JNIEXPORT static jfloat JNICALL
Java_java_lang_reflect_Field_nativeGetFloat (JNIEnv *_env,
					     jobject this SVM_UNUSED,
					     jbyteArray vmData,
					     jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jfloat value = 0.0;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert ((field->type == SVM_TYPE_BYTE) ||
	    (field->type == SVM_TYPE_SHORT) ||
	    (field->type == SVM_TYPE_CHAR) ||
	    (field->type == SVM_TYPE_INT) ||
	    (field->type == SVM_TYPE_LONG) ||
	    (field->type == SVM_TYPE_FLOAT));



    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = field->data.class_field.value.b;
	    break;
	  case SVM_TYPE_SHORT:
	    value = field->data.class_field.value.s;
	    break;
	  case SVM_TYPE_CHAR:
	    value = field->data.class_field.value.c;
	    break;
	  case SVM_TYPE_INT:
	    value = field->data.class_field.value.i;
	    break;
	  case SVM_TYPE_LONG:
	    value = field->data.class_field.value.j;
	    break;
	  case SVM_TYPE_FLOAT:
	    value = field->data.class_field.value.f;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = _svmf_get_BYTE_field (*instance, offset);
	    break;
	  case SVM_TYPE_SHORT:
	    value = _svmf_get_SHORT_field (*instance, offset);
	    break;
	  case SVM_TYPE_CHAR:
	    value = _svmf_get_CHAR_field (*instance, offset);
	    break;
	  case SVM_TYPE_INT:
	    value = _svmf_get_INT_field (*instance, offset);
	    break;
	  case SVM_TYPE_LONG:
	    value = _svmf_get_LONG_field (*instance, offset);
	    break;
	  case SVM_TYPE_FLOAT:
	    value = _svmf_get_FLOAT_field (*instance, offset);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeGetDouble
----------------------------------------------------------------------
*/



/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeGetDouble
 * Signature: ([BLjava/lang/Object;)D
 */
JNIEXPORT static jdouble JNICALL
Java_java_lang_reflect_Field_nativeGetDouble (JNIEnv *_env,
					      jobject this SVM_UNUSED,
					      jbyteArray vmData,
					      jobject instance)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jdouble value = 0.0;

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert ((field->type == SVM_TYPE_BYTE) ||
	    (field->type == SVM_TYPE_SHORT) ||
	    (field->type == SVM_TYPE_CHAR) ||
	    (field->type == SVM_TYPE_INT) ||
	    (field->type == SVM_TYPE_LONG) ||
	    (field->type == SVM_TYPE_FLOAT) ||
	    (field->type == SVM_TYPE_DOUBLE));


    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = field->data.class_field.value.b;
	    break;
	  case SVM_TYPE_SHORT:
	    value = field->data.class_field.value.s;
	    break;
	  case SVM_TYPE_CHAR:
	    value = field->data.class_field.value.c;
	    break;
	  case SVM_TYPE_INT:
	    value = field->data.class_field.value.i;
	    break;
	  case SVM_TYPE_LONG:
	    value = field->data.class_field.value.j;
	    break;
	  case SVM_TYPE_FLOAT:
	    value = field->data.class_field.value.f;
	    break;
	  case SVM_TYPE_DOUBLE:
	    value = field->data.class_field.value.d;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    value = _svmf_get_BYTE_field (*instance, offset);
	    break;
	  case SVM_TYPE_SHORT:
	    value = _svmf_get_SHORT_field (*instance, offset);
	    break;
	  case SVM_TYPE_CHAR:
	    value = _svmf_get_CHAR_field (*instance, offset);
	    break;
	  case SVM_TYPE_INT:
	    value = _svmf_get_INT_field (*instance, offset);
	    break;
	  case SVM_TYPE_LONG:
	    value = _svmf_get_LONG_field (*instance, offset);
	    break;
	  case SVM_TYPE_FLOAT:
	    value = _svmf_get_FLOAT_field (*instance, offset);
	    break;
	  case SVM_TYPE_DOUBLE:
	    value = _svmf_get_DOUBLE_field (*instance, offset);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	  }
      }
  }

  _svmm_stopping_java (env);

  return value;
}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetReference
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetReference
 * Signature: ([BLjava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;
 */
JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetReference (JNIEnv *_env,
						 jobject this SVM_UNUSED,
						 jbyteArray vmData,
						 jobject instance,
						 jobject value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_REFERENCE);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	*(field->data.class_field.value.l) = *value;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	_svmf_put_REFERENCE_field (env, *instance, offset, *value);
      }
  }

  _svmm_stopping_java (env);

}



/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetBoolean
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetBoolean
 * Signature: ([BLjava/lang/Object;Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetBoolean (JNIEnv *_env,
					       jobject this SVM_UNUSED,
					       jbyteArray vmData,
					       jobject instance,
					       jboolean value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_BOOLEAN);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field->data.class_field.value.z = value;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	_svmf_put_BOOLEAN_field (*instance, offset, value);
      }
  }

  _svmm_stopping_java (env);

}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetByte
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetByte
 * Signature: ([BLjava/lang/Object;B)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetByte (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance, jbyte value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    field->data.class_field.value.b = value;
	    break;
	  case SVM_TYPE_SHORT:
	    field->data.class_field.value.s = value;
	    break;
	  case SVM_TYPE_INT:
	    field->data.class_field.value.i = value;
	    break;
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	  case SVM_TYPE_DOUBLE:
	    field->data.class_field.value.d = value;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_BYTE:
	    _svmf_put_BYTE_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_SHORT:
	    _svmf_put_SHORT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_INT:
	    _svmf_put_INT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_DOUBLE:
	    _svmf_put_DOUBLE_field (*instance, offset, value);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
  }

  _svmm_stopping_java (env);

}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetChar
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetChar
 * Signature: ([BLjava/lang/Object;C)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetChar (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance, jchar value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_CHAR:
	    field->data.class_field.value.c = value;
	    break;
	  case SVM_TYPE_INT:
	    field->data.class_field.value.i = value;
	    break;
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	  case SVM_TYPE_DOUBLE:
	    field->data.class_field.value.d = value;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_CHAR:
	    _svmf_put_CHAR_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_INT:
	    _svmf_put_INT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_DOUBLE:
	    _svmf_put_DOUBLE_field (*instance, offset, value);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
  }

  _svmm_stopping_java (env);

}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetShort
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetShort
 * Signature: ([BLjava/lang/Object;S)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetShort (JNIEnv *_env,
					     jobject this SVM_UNUSED,
					     jbyteArray vmData,
					     jobject instance, jshort value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {

    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_SHORT:
	    field->data.class_field.value.s = value;
	    break;
	  case SVM_TYPE_INT:
	    field->data.class_field.value.i = value;
	    break;
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	  case SVM_TYPE_DOUBLE:
	    field->data.class_field.value.d = value;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_SHORT:
	    _svmf_put_SHORT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_INT:
	    _svmf_put_INT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_DOUBLE:
	    _svmf_put_DOUBLE_field (*instance, offset, value);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }

  }

  _svmm_stopping_java (env);


}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetInt
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetInt
 * Signature: ([BLjava/lang/Object;I)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetInt (JNIEnv *_env,
					   jobject this SVM_UNUSED,
					   jbyteArray vmData,
					   jobject instance, jint value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_INT:
	    field->data.class_field.value.i = value;
	    break;
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	  case SVM_TYPE_DOUBLE:
	    field->data.class_field.value.d = value;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_INT:
	    _svmf_put_INT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_DOUBLE:
	    _svmf_put_DOUBLE_field (*instance, offset, value);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }


  }

  _svmm_stopping_java (env);

}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetLong
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetLong
 * Signature: ([BLjava/lang/Object;J)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetLong (JNIEnv *_env,
					    jobject this SVM_UNUSED,
					    jbyteArray vmData,
					    jobject instance, jlong value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {

    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	  case SVM_TYPE_DOUBLE:
	    field->data.class_field.value.d = value;
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_DOUBLE:
	    _svmf_put_DOUBLE_field (*instance, offset, value);
	    break;
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }


  }

  _svmm_stopping_java (env);

}

/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetFloat
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetFloat
 * Signature: ([BLjava/lang/Object;F)V
 */


JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetFloat (JNIEnv *_env,
					     jobject this SVM_UNUSED,
					     jbyteArray vmData,
					     jobject instance, jfloat value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {

    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	switch (field->type)
	  {
	  case SVM_TYPE_LONG:
	    field->data.class_field.value.j = value;
	    break;
	  case SVM_TYPE_FLOAT:
	    field->data.class_field.value.f = value;
	    break;
	    /* Note: Classpath javadoc exclude double, a bug? */
	    /*
	       case SVM_TYPE_DOUBLE:
	       field->data.class_field.value.d = value;
	       break;
	     */
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	switch (field->type)
	  {
	  case SVM_TYPE_LONG:
	    _svmf_put_LONG_field (*instance, offset, value);
	    break;
	  case SVM_TYPE_FLOAT:
	    _svmf_put_FLOAT_field (*instance, offset, value);
	    break;
	    /* see comment above */
	    /*
	       case SVM_TYPE_DOUBLE:
	       _svmf_put_DOUBLE_field(*instance, offset, value);
	       break;
	     */
	  default:
	    _svmm_fatal_error ("impossible control flow");
	    break;
	  }
      }

  }

  _svmm_stopping_java (env);

}


/*
----------------------------------------------------------------------
Java_java_lang_reflect_Field_nativeSetDouble
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_reflect_Field
 * Method:    nativeSetDouble
 * Signature: ([BLjava/lang/Object;D)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_reflect_Field_nativeSetDouble (JNIEnv *_env,
					      jobject this SVM_UNUSED,
					      jbyteArray vmData,
					      jobject instance, jdouble value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {

    _svmt_field_info *field = _svmf_unwrap_pointer (*vmData);

    assert (field->type == SVM_TYPE_DOUBLE);

    if (_svmf_is_set_flag (field->access_flags, SVM_ACC_STATIC))
      {
	field->data.class_field.value.d = value;
      }
    else
      {
	size_t offset;
	assert (instance != NULL);
	offset = field->data.instance_field.offset;
	_svmf_put_DOUBLE_field (*instance, offset, value);
      }
  }

  _svmm_stopping_java (env);

}
