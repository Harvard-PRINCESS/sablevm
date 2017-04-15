/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_invokeMain
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    invokeMain
 * Signature: (Ljava/lang/Class;[Ljava/lang/String;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_invokeMain (JNIEnv *_env,
					  jclass _class SVM_UNUSED,
					  jclass mainClass, jobjectArray args)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, mainClass);
    _svmt_class_info *class_info;
    _svmt_method_info *method;

    if (type->is_array)
      {
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }

    class_info = _svmf_cast_class (type);

    /* link and initialize class */
    if (_svmf_link_class (env, class_info) != JNI_OK)
      {
	goto end;
      }

    if (_svmf_class_initialization (env, class_info) != JNI_OK)
      {
	goto end;
      }

    method =
      _svmf_resolve_method (class_info, "main", "([Ljava/lang/String;)V");
    if (method == NULL)
      {
	_svmf_error_NoSuchMethodError (env);
	goto end;
      }

    if (_svmm_invoke_specific_static_main
	(env, method, _svmf_cast_jobject (args)) != JNI_OK)
      {
	goto end;
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__Z
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__Z (JNIEnv *_env, jclass class SVM_UNUSED,
					jboolean value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%s", value ? "true" : "false");
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__B
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (B)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__B (JNIEnv *_env, jclass class SVM_UNUSED,
					jbyte value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__S
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (S)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__S (JNIEnv *_env, jclass class SVM_UNUSED,
					jshort value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__C
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (C)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__C (JNIEnv *_env, jclass class SVM_UNUSED,
					jchar value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    if (value > 0x7f || value < ' ')
      {
	if (value != '\n')
	  {
	    value = '?';
	  }
      }

    _svmf_printf (env, stderr, "%c", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__I
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (I)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__I (JNIEnv *_env, jclass class SVM_UNUSED,
					jint value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d", value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__J
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (J)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__J (JNIEnv *_env, jclass class SVM_UNUSED,
					jlong value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%lld", value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__F
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (F)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__F (JNIEnv *_env, jclass class SVM_UNUSED,
					jfloat value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%f", (jdouble) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__D
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (D)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__D (JNIEnv *_env, jclass class SVM_UNUSED,
					jdouble value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%f", value);
  }

  _svmm_stopping_java (env);

}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_print__Ljava_lang_String_2
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    print
 * Signature: (Ljava/lang/String;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_print__Ljava_lang_String_2 (JNIEnv *_env,
							  jclass class
							  SVM_UNUSED,
							  jstring value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  if (value != NULL)
    {
      char *str;

      if (_svmm_galloc_utf_chars (env, value, str) != JNI_OK)
	{
	  goto end;
	}

      _svmf_printf (env, stderr, "%s", str);

      _svmm_gfree_utf_chars (str);
    }
  else
    {
      _svmf_printf (env, stderr, "null");
    }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__Z
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (Z)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__Z (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jboolean value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%s\n", value ? "true" : "false");
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__B
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (B)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__B (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jbyte value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d\n", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__S
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (S)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__S (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jshort value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d\n", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__C
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (C)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__C (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jchar value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    if (value > 0x7f || value < ' ')
      {
	if (value != '\n')
	  {
	    value = '?';
	  }
      }

    _svmf_printf (env, stderr, "%c\n", (jint) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__I
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (I)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__I (JNIEnv *_env,
					  jclass class SVM_UNUSED, jint value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%d\n", value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__J
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (J)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__J (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jlong value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%lld\n", value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__F
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (F)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__F (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jfloat value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%f\n", (jdouble) value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__D
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (D)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__D (JNIEnv *_env,
					  jclass class SVM_UNUSED,
					  jdouble value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmf_printf (env, stderr, "%f\n", value);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VirtualMachine_println__Ljava_lang_String_2
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VirtualMachine
 * Method:    println
 * Signature: (Ljava/lang/String;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VirtualMachine_println__Ljava_lang_String_2 (JNIEnv *_env,
							    jclass class
							    SVM_UNUSED,
							    jstring value)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  if (value != NULL)
    {
      char *str;

      if (_svmm_galloc_utf_chars (env, value, str) != JNI_OK)
	{
	  goto end;
	}

      _svmf_printf (env, stderr, "%s\n", str);

      _svmm_gfree_utf_chars (str);
    }
  else
    {
      _svmf_printf (env, stderr, "null\n");
    }

end:
  _svmm_stopping_java (env);
}
