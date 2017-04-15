/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_cast
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_cast)
 */

m4svm_define_begin v = ":], [:m4svm_cast:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_cast_$1
-----------------------------------m4_dnl
-----------------------------------
*/

inline static $2
_svmf_cast_$1 ($3 expr)
{
  return ($2) (void *) expr;
}

m4svm_define_end v = ":])";
