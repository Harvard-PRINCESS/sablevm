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

#ifndef SVM_METHOD_INVOKE_H
#define SVM_METHOD_INVOKE_H
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_tail:])";

#endif /* NOT SVM_METHOD_INVOKE_H */
m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_nonvirtual
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_nonvirtual)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_nonvirtual:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_nonvirtual_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * [:, ret:])[::]m4_dnl
 * ) \[::]m4_dnl
 * m4_dnl:]:]) */
#define _svmm_invoke_nonvirtual_$1(env, m4svm_arglist)

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, ret:],
 * [:, &ret:])[::]m4_dnl
 * )[::]m4_dnl
 * m4_dnl:]:]) */
_svmh_invoke_nonvirtual_$1 (env, m4svm_arglist);


/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint _svmh_invoke_nonvirtual_$1 (_svmt_JNIEnv *env,
					    jobject m4svm_arglist);

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_specific_nonvirtual
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_specific_nonvirtual)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_specific_nonvirtual:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_specific_nonvirtual_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * [:, ret:])[::]m4_dnl
 * ) \[::]m4_dnl
 * m4_dnl:]:]) */
#define _svmm_invoke_specific_nonvirtual_$1(env, method, m4svm_arglist)

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, ret:],
 * [:, &ret:])[::]m4_dnl
 * )[::]m4_dnl
 * m4_dnl:]:]) */
_svmh_invoke_specific_nonvirtual_$1 (env, method, m4svm_arglist);


/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:this[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint _svmh_invoke_specific_nonvirtual_$1
  (_svmt_JNIEnv *env, _svmt_method_info *method, jobject m4svm_arglist);

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_static
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_static)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_static:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_static_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:env[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * [:, ret:])[::]m4_dnl
 * ) \[::]m4_dnl
 * m4_dnl:]:]) */
#define _svmm_invoke_static_$1(m4svm_arglist)

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:env[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, ret:],
 * [:, &ret:])[::]m4_dnl
 * )[::]m4_dnl
 * m4_dnl:]:]) */
_svmh_invoke_static_$1 (m4svm_arglist);


/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:env[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint _svmh_invoke_static_$1 (_svmt_JNIEnv *m4svm_arglist);

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_invoke_specific_static
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_invoke_specific_static)
 */

m4svm_define_begin v = ":], [:m4svm_invoke_specific_static:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_invoke_specific_static_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:method[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * [:, ret:])[::]m4_dnl
 * ) \[::]m4_dnl
 * m4_dnl:]:]) */
#define _svmm_invoke_specific_static_$1(env, m4svm_arglist)

/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:method[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * [:, param_[::]m4_eval(arg - 2):])[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, ret:],
 * [:, &ret:])[::]m4_dnl
 * )[::]m4_dnl
 * m4_dnl:]:]) */
_svmh_invoke_specific_static_$1 (env, m4svm_arglist);


/* m4svm_comment_define([:m4svm_arglist:],
 * [:[:method[::]m4_dnl
 * m4_dnl
 * m4_dnl the arguments
 * m4_dnl
 * m4svm_for([:arg:], 3, $:][:#,
 * :]m4svm_lbkt[:, m4svm_argn(arg, $:][:@) m4_dnl
 * param_[::]m4_eval(arg - 2):]m4svm_rbkt[:)[::]m4_dnl
 * m4_dnl
 * m4_dnl the return value
 * m4_dnl
 * m4_ifelse(
 * $:][:2, void, ,
 * $:][:2, jobject, [:, jobject ret:],
 * :]m4svm_lbkt[:, $:][:2 *ret:]m4svm_rbkt[:)[::]m4_dnl
 * :]:]) */
svm_static jint _svmh_invoke_specific_static_$1
  (_svmt_JNIEnv *env, _svmt_method_info *m4svm_arglist);

m4svm_define_end v = ":])";
