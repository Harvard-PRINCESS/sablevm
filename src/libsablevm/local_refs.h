/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_LOCAL_REFS_H
#define SVM_LOCAL_REFS_H

#define _svmm_new_native_local(env,ref) \
_svmh_new_native_local (env, &ref)

static jint _svmh_new_native_local (_svmt_JNIEnv *env, jobject *pobj);

#define _svmm_free_native_local(env,ref) \
_svmh_free_native_local (env, &ref)

static void _svmh_free_native_local (_svmt_JNIEnv *env, jobject *pobj);

#endif /* NOT SVM_LOCAL_REFS_H */
