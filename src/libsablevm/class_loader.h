/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_CLASS_LOADER_H
#define SVM_CLASS_LOADER_H

#define _svmm_create_type(env,cl,name,type) \
_svmh_create_type (env, cl, name, &type)

#define _svmm_create_class(env,cl,name,class) \
_svmh_create_class (env, cl, name, &class)

#define _svmm_create_array(env,cl,name,array) \
_svmh_create_array (env, cl, name, &array)

#define _svmm_bootcl_internal_load_class_file(env,name,cf) \
_svmh_bootcl_internal_load_class_file (env, name, &cf)

svm_static jint _svmh_create_type (_svmt_JNIEnv *env,
				   _svmt_class_loader_info *class_loader_info,
				   const char *type_name,
				   _svmt_type_info **ptype);

svm_static jint _svmh_create_array (_svmt_JNIEnv *env,
				    _svmt_class_loader_info
				    *class_loader_info,
				    const char *array_name,
				    _svmt_array_info **parray);

#endif /* SVM_CLASS_LOADER_H */
