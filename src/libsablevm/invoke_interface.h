/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_INVOKE_INTERFACE_H
#define SVM_INVOKE_INTERFACE_H

static JNIEXPORT jint JNICALL DestroyJavaVM (JavaVM *vm);
static JNIEXPORT jint JNICALL AttachCurrentThread
  (JavaVM *vm, void **penv, void *args);
static JNIEXPORT jint JNICALL DetachCurrentThread (JavaVM *vm);
static JNIEXPORT jint JNICALL GetEnv
  (JavaVM *vm, void **penv, jint interface_id);

#endif /* NOT SVM_INVOKE_INTERFACE_H */
