/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class gnu_classpath_VMSystemProperties */

#ifndef _Included_gnu_classpath_VMSystemProperties
#define _Included_gnu_classpath_VMSystemProperties
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getSableVMVersion
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getSableVMVersion (JNIEnv *,
							     jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSName
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getOSName (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSArch
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getOSArch (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getOSVersion
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getOSVersion (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getFileSeparator
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getFileSeparator (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getPathSeparator
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getPathSeparator (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getLineSeparator
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getLineSeparator (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getUserName
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getUserName (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getUserHome
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getUserHome (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getWorkDir
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getWorkDir (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    isBigEndian
 * Signature: ()Z
 */
  JNIEXPORT static jboolean JNICALL
    Java_gnu_classpath_VMSystemProperties_isBigEndian (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getBootstrapLibraryPath
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath (JNIEnv *,
								   jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getBootstrapClassPath
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath (JNIEnv *,
								 jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getJavaHome
 * Signature: ()Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getJavaHome (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getPropertyCount
 * Signature: ()I
 */
  JNIEXPORT static jint JNICALL
    Java_gnu_classpath_VMSystemProperties_getPropertyCount (JNIEnv *, jclass);

/*
 * Class:     gnu_classpath_VMSystemProperties
 * Method:    getProperty
 * Signature: (I)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_gnu_classpath_VMSystemProperties_getProperty (JNIEnv *, jclass,
						       jint);

#ifdef __cplusplus
}
#endif
#endif
