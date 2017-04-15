/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_LINK_H
#define SVM_LINK_H

static jint _svmf_link_array (_svmt_JNIEnv *env, _svmt_array_info *array);
static jint _svmf_link_class (_svmt_JNIEnv *env, _svmt_class_info *class);
static jint _svmf_link_type (_svmt_JNIEnv *env, _svmt_type_info *type);

#endif /* not SVM_LINK_H */
