/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

----------------------------------------------------------------------
m4svm_arches
----------------------------------------------------------------------

m4_define(m4svm_arches,
[:m4_define(m4svm_archno,
m4svm_for(arg,1,$#,
[:m4_ifelse(m4svm_argn(arg,$@),m4svm_archname,arg):])m4_dnl
)
m4_ifelse(m4svm_archno,,
[:m4_errprint(m4: m4___file__: fatal error m4_dnl
- unknown architecture m4svm_archname
)[::]m4_dnl
m4_m4exit(1)m4_dnl
:],
[:m4_define([:m4svm_archno:], m4_incr(m4svm_archno)):])
:])


----------------------------------------------------------------------
m4svm_get_arch_inlineability
----------------------------------------------------------------------

m4_define(m4svm_get_arch_inlineability,
[:m4_ifelse(m4svm_argn(m4svm_archno,$@),,INL,m4svm_argn(m4svm_archno,$@)):])


----------------------------------------------------------------------
m4svm_arches_inlineability
----------------------------------------------------------------------

m4svm_multicall(m4svm_arches_inlineability)

m4_define(m4svm_arches_inlineability,
[:m4svm_on(1)#m4_dnl
define SVM_INLINEABLE_$1         SVM_INTRP_FLAG_[::]m4_dnl
m4_define(m4svm_arch_inlineability, m4svm_get_arch_inlineability($@))m4_dnl
m4_ifelse(
m4svm_arch_inlineability, INL, INLINEABLE,
m4svm_arch_inlineability, NOT, CONTAINS_BRANCH_OR_CALL,
m4svm_arch_inlineability, SIG, INLINEABLE_IF_SIGNALS,
[:m4_errprint(m4: m4___file__: fatal error m4_dnl
- unknown inlineability information on architecture m4svm_archno for instruction $1
)[::]m4_dnl
m4_m4exit(1)m4_dnl
:])
m4_undefine([:m4svm_arch_inlineability:])m4_dnl
m4svm_off():])

----------------------------------------------------------------------
m4svm_never_inlineable
----------------------------------------------------------------------

m4svm_multicall(m4svm_never_inlineable)

m4_define(m4svm_never_inlineable,
[:m4svm_on(1)#m4_dnl
define SVM_INLINEABLE_$1 SVM_INTRP_FLAG_[::]m4_dnl
m4_ifelse(
$2, NOT, CONTAINS_BRANCH_OR_CALL,
$2, SIG, INLINEABLE_IF_SIGNALS,
$2, SPC, SPECIAL,
$2, NSD, UNUSED,
[:m4_errprint(m4: m4___file__: fatal error m4_dnl
- unknown inlineability information on architecture m4svm_archno for instruction $1
)[::]m4_dnl
m4_m4exit(1)m4_dnl
:])
m4svm_off():])


----------------------------------------------------------------------
m4svm_inlinability_data_name
----------------------------------------------------------------------

m4_define(m4svm_inlinability_data_name,
[:m4svm_on(1)
#m4_dnl
define SVM_INLINABILITY_DATA_NAME "m4svm_archname"
m4svm_off():])
