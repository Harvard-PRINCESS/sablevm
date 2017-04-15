/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_NEW_INSTANCE_H
#define SVM_NEW_INSTANCE_H

/*
----------------------------------------------------------------------
_svmh_new_array_instance
----------------------------------------------------------------------
*/

#define _svmm_new_array_instance(env, array_info, size, instance) \
_svmh_new_array_instance(env, array_info, size, &instance)

svm_static jint
_svmh_new_array_instance (_svmt_JNIEnv *env, _svmt_array_info *array_info,
			  jint size, _svmt_array_instance **pinstance);

/*
----------------------------------------------------------------------
_svmh_new_object_instance
----------------------------------------------------------------------
*/

#define _svmm_new_object_instance(env, class_info, instance) \
_svmh_new_object_instance(env, class_info, &instance)

svm_static jint
_svmh_new_object_instance (_svmt_JNIEnv *env, _svmt_class_info *class_info,
			   _svmt_object_instance **pinstance);

/*
----------------------------------------------------------------------
_svmm_multianewarray
----------------------------------------------------------------------
*/

#define _svmm_multianewarray(env, array_info, dimensions, counts, instance) \
_svmh_multianewarray (env, array_info, dimensions, &counts, &instance)

svm_static jint
_svmh_multianewarray (_svmt_JNIEnv *env, _svmt_array_info *array_info,
		      jint dimensions, _svmt_stack_value counts[],
		      _svmt_array_instance **pinstance);

#endif /* NOT SVM_NEW_INSTANCE_H */
