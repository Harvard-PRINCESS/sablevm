/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_reflect_Constructor */

#ifndef _Included_java_lang_reflect_Constructor
#define _Included_java_lang_reflect_Constructor
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetDeclaringClass
 * Signature: ([B)Ljava/lang/Class;
 */
  JNIEXPORT static jclass JNICALL
    Java_java_lang_reflect_Constructor_nativeGetDeclaringClass (JNIEnv *,
								jclass,
								jbyteArray);

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetModifiers
 * Signature: ([B)I
 */
  JNIEXPORT static jint JNICALL
    Java_java_lang_reflect_Constructor_nativeGetModifiers (JNIEnv *, jobject,
							   jbyteArray);

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetExceptionTypes
 * Signature: ([B)[Ljava/lang/Class;
 */
  JNIEXPORT static jobjectArray JNICALL
    Java_java_lang_reflect_Constructor_nativeGetExceptionTypes (JNIEnv *,
								jclass,
								jbyteArray);

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    constructNative
 * Signature: ([B[C[Ljava/lang/Object;)Ljava/lang/Object;
 */
  JNIEXPORT static jobject JNICALL
    Java_java_lang_reflect_Constructor_constructNative (JNIEnv *, jclass,
							jbyteArray,
							jcharArray,
							jobjectArray);

/*
 * Class:     java_lang_reflect_Constructor
 * Method:    nativeGetDescriptor
 * Signature: ([B)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL
    Java_java_lang_reflect_Constructor_nativeGetDescriptor (JNIEnv *, jclass,
							    jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
