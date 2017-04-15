/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_PREPARE_H
#define SVM_PREPARE_H

#define _svmm_get_interface_method_id(env, name, descriptor, mid) \
_svmh_get_interface_method_id (env, name, descriptor, &mid)

#endif /* NOT SVM_PREPARE_H */
