/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_CLASS_LOADER_MEMORY_MANAGER_H
#define SVM_CLASS_LOADER_MEMORY_MANAGER_H

/*
----------------------------------------------------------------------
_svmm_cl_zalloc_vtable
----------------------------------------------------------------------
*/

#define _svmm_cl_zalloc_vtable(env,cli,cls,ptr) \
_svmh_cl_zalloc_vtable (env,cli,cls,&ptr)

#endif /* not SVM_CLASS_LOADER_MEMORY_MANAGER_H */
