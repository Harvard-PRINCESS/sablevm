/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class java_lang_VMRuntime */

#ifndef _Included_java_lang_VMRuntime
#define _Included_java_lang_VMRuntime
#ifdef __cplusplus
extern "C"
{
#endif
/*
 * Class:     java_lang_VMRuntime
 * Method:    availableProcessors
 * Signature: ()I
 */
  JNIEXPORT static jint JNICALL Java_java_lang_VMRuntime_availableProcessors
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    freeMemory
 * Signature: ()J
 */
  JNIEXPORT static jlong JNICALL Java_java_lang_VMRuntime_freeMemory
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    totalMemory
 * Signature: ()J
 */
  JNIEXPORT static jlong JNICALL Java_java_lang_VMRuntime_totalMemory
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    maxMemory
 * Signature: ()J
 */
  JNIEXPORT static jlong JNICALL Java_java_lang_VMRuntime_maxMemory
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    gc
 * Signature: ()V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_gc
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalization
 * Signature: ()V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_runFinalization
    (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalizationForExit
 * Signature: ()V
 */
  JNIEXPORT static void JNICALL
    Java_java_lang_VMRuntime_runFinalizationForExit (JNIEnv *, jclass);

/*
 * Class:     java_lang_VMRuntime
 * Method:    traceInstructions
 * Signature: (Z)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_traceInstructions
    (JNIEnv *, jclass, jboolean);

/*
 * Class:     java_lang_VMRuntime
 * Method:    traceMethodCalls
 * Signature: (Z)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_traceMethodCalls
    (JNIEnv *, jclass, jboolean);

/*
 * Class:     java_lang_VMRuntime
 * Method:    runFinalizersOnExit
 * Signature: (Z)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_runFinalizersOnExit
    (JNIEnv *, jclass, jboolean);

/*
 * Class:     java_lang_VMRuntime
 * Method:    exit
 * Signature: (I)V
 */
  JNIEXPORT static void JNICALL Java_java_lang_VMRuntime_exit
    (JNIEnv *, jclass, jint);

/*
 * Class:     java_lang_VMRuntime
 * Method:    nativeLoad
 * Signature: (Ljava/lang/String;[B)I
 */
  JNIEXPORT static jint JNICALL Java_java_lang_VMRuntime_nativeLoad
    (JNIEnv *, jclass, jstring, jbyteArray);

/*
 * Class:     java_lang_VMRuntime
 * Method:    mapLibraryName
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
  JNIEXPORT static jstring JNICALL Java_java_lang_VMRuntime_mapLibraryName
    (JNIEnv *, jclass, jstring);

#ifdef __cplusplus
}
#endif
#endif
