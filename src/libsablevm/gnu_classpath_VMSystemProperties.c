/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getSableVMVersion
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getSableVMVersion
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getSableVMVersion (JNIEnv *_env,
							 jclass class
							 SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, _SABLEVM_PACKAGE_VERSION, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getOSName
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSName
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getOSName (JNIEnv *_env,
						 jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    struct utsname uname_info;
    const char *value;

    if (uname (&uname_info) == -1)
      {
	value = "?";
      }
    else
      {
	value = uname_info.sysname;
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getOSArch
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSArch
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getOSArch (JNIEnv *_env,
						 jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    struct utsname uname_info;
    const char *value;

    if (uname (&uname_info) == -1)
      {
	value = "?";
      }
    else
      {
	value = uname_info.machine;
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getOSVersion
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSVersion
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getOSVersion (JNIEnv *_env,
						    jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    struct utsname uname_info;
    const char *value;

    if (uname (&uname_info) == -1)
      {
	value = "?";
      }
    else
      {
	value = uname_info.release;
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getFileSeparator
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getFileSeparator
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getFileSeparator (JNIEnv *_env,
							jclass class
							SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, "/", string);
  }

  _svmm_stopping_java (env);

  return string;
}


/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getPathSeparator
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getPathSeparator
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getPathSeparator (JNIEnv *_env,
							jclass class
							SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, ":", string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getLineSeparator
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getLineSeparator
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getLineSeparator (JNIEnv *_env,
							jclass class
							SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, "\n", string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getUserName
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getUserName
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getUserName (JNIEnv *_env,
						   jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    const char *value = getenv ("USER");

    if (value == NULL)
      {
	value = "";
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getUserHome
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getUserHome
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getUserHome (JNIEnv *_env,
						   jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    const char *value = getenv ("HOME");

    if (value == NULL)
      {
	value = "";
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getWorkDir
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getWorkDir
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getWorkDir (JNIEnv *_env,
						  jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    const char *value = vm->boot_working_directory;

    if (value == NULL)
      {
	value = "";
      }

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_isBigEndian
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    isBigEndian
 * Signature: ()Z
 */
JNIEXPORT static jboolean JNICALL
Java_gnu_classpath_VMSystemProperties_isBigEndian (JNIEnv *_env,
						   jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  {
    jint n = 0x01000000;

    result = *((jbyte *) &n) == 1 ? JNI_TRUE : JNI_FALSE;
  }

  _svmm_stopping_java (env);

  return result;

}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getBootstrapLibraryPath
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath (JNIEnv *_env,
							       jclass class
							       SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    const char *value = vm->class_loading.boot_loader.boot_library_path;

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getBootstrapClassPath
 * Signature: ()Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath (JNIEnv *_env,
							     jclass class
							     SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    const char *value = vm->class_loading.boot_loader.boot_class_path;

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, value, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getJavaHome
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getJavaHome
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getJavaHome (JNIEnv *_env,
						   jclass class SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, JAVA_HOME_PATH, string);
  }

  _svmm_stopping_java (env);

  return string;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getPropertyCount
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getPropertyCount
 * Signature: ()I
 */

JNIEXPORT static jint JNICALL
Java_gnu_classpath_VMSystemProperties_getPropertyCount (JNIEnv *_env,
							jclass class
							SVM_UNUSED)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint count;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    count = vm->class_loading.boot_loader.system_properties.count;
  }

  _svmm_stopping_java (env);

  return count;
}

/*
----------------------------------------------------------------------
Java_gnu_classpath_VMSystemProperties_getProperty
----------------------------------------------------------------------
*/

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getProperty
 * Signature: (I)Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_gnu_classpath_VMSystemProperties_getProperty (JNIEnv *_env,
						   jclass class SVM_UNUSED,
						   jint index)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring string;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    /* as we do nothing else after, we can safely ignore the return
       value (any exception being also set in the environment) */
    string = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env,
		      vm->class_loading.boot_loader.system_properties.
		      properties[index], string);
  }

  _svmm_stopping_java (env);

  return string;
}
