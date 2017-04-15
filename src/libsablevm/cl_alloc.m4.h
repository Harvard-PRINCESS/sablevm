/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";

#ifndef SVM_CL_ALLOC_H
#define SVM_CL_ALLOC_H
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";

#endif /* NOT SVM_CL_ALLOC_H */
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_cl_zalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_zalloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_zalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_zalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_zalloc_$1(env, cli, ptr) \
_svmh_cl_zalloc_$1 (env, cli, &ptr)

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_zfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_zfree_$1(cli, ptr) \
_svmh_cl_zfree_$1 (cli, &ptr)

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_cl_malloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_malloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_malloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_malloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_malloc_$1(env, cli, n, ptr) \
_svmh_cl_malloc_$1 (env, cli, n, &ptr)

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_mfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_mfree_$1(cli, n, ptr) \
_svmh_cl_mfree_$1 (cli, n, &ptr)

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_cl_zmalloc
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cl_zmalloc)
 */

m4svm_define_begin v = ":], [:m4svm_cl_zmalloc:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_zmalloc_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_zmalloc_$1(env, cli, n, ptr) \
_svmh_cl_zmalloc_$1 (env, cli, n, &ptr)

/*
-----------------------------------m4_dnl
-----------------------------------
_svmm_cl_zmfree_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_cl_zmfree_$1(cli, n, ptr) \
_svmh_cl_zmfree_$1 (cli, n, &ptr)

m4svm_define_end v = ":])";
