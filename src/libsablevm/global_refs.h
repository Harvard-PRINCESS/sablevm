/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_GLOBAL_REFS_H
#define SVM_GLOBAL_REFS_H

#define _svmm_new_native_global(env,ref) \
_svmh_new_native_global (env, &ref)

#define _svmm_free_native_global(env, ref) \
_svmh_free_native_global (env, &ref)

#endif /* NOT SVM_GLOBAL_REFS_H */
