/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_instruction_head
----------------------------------------------------------------------
*/

/* m4svm_comment_define([:m4svm_instruction_head:],
 * [:m4svm_instruction_1(:]) */

/*
----------------------------------------------------------------------
m4svm_instruction_tail
----------------------------------------------------------------------
*/

/* m4svm_comment_define([:m4svm_instruction_tail:],
 * [:))m4_dnl:]) */

/*
----------------------------------------------------------------------
m4svm_instruction_1
----------------------------------------------------------------------
*/

/* m4svm_comment_define([:m4svm_instruction_1:],
 * [:m4svm_instruction_2$1:]) */

/*
----------------------------------------------------------------------
m4svm_instruction_2
----------------------------------------------------------------------
*/

/* m4svm_comment_define([:m4svm_instruction_2:],
 * [:m4svm_instruction($1, $2, $3,m4_dnl:]) */

/*
----------------------------------------------------------------------
m4svm_instruction
----------------------------------------------------------------------
*/

/* m4_define([:m4svm_instruction:],
   [:m4svm_instruction_switch_threaded([:$1:], [:$2:], [:$3:],[:$4:]):]) */

/*
----------------------------------------------------------------------
m4svm_is_two_modes_fast
----------------------------------------------------------------------
*/

/*
   m4_define(m4svm_is_two_modes_fast,
   [:m4_ifelse(m4_index(m4svm_two_modes_fast_$1(),[:m4svm:]),
   0,,m4svm_two_modes_fast_$1()):])
*/

/*
----------------------------------------------------------------------
m4svm_skip_two_modes_fast
----------------------------------------------------------------------
*/

/* m4svm_comment_define(m4svm_skip_two_modes_fast_real,
 * [:m4_ifelse(m4svm_is_two_modes_fast($1),,,
 * [:
 * 	pc++;			/[::]* skip preparation address *[::]/
 * :]):])
 */

/* m4svm_comment_define([:m4svm_skip_two_modes_fast:],
 * [:m4svm_skip_two_modes_fast_1(:])
 *
 * m4svm_comment_define([:m4svm_skip_two_modes_fast_1:],
 * [:m4svm_skip_two_modes_fast_2$1:])
 *
 * m4svm_comment_define([:m4svm_skip_two_modes_fast_2:],
 * [:m4svm_skip_two_modes_fast_3([:$1:]) m4_dnl:])
 *
 * m4svm_comment_define([:m4svm_skip_two_modes_fast_3:],
 * [:[:m4svm_skip_two_modes_fast_real($1):]:])
 * 
 * m4_define([:m4svm_end_two_modes_fast:],[:) m4_dnl:])
 */

/*
----------------------------------------------------------------------
m4svm_(dont_)expect_sigsegv
----------------------------------------------------------------------
*/

/* we don't use inlinability testing mode with switch engine */
/* m4svm_comment_define([:m4svm_expect_sigsegv:],[:m4_[::]dnl:]) */
/* m4svm_comment_define([:m4svm_dont_expect_sigsegv:],[:m4_[::]dnl:]) */

/*
----------------------------------------------------------------------
m4svm_instruction_switch_threaded
----------------------------------------------------------------------
*/

void
dummy ()
{
  switch (dummy)
    {
      m4svm_define_begin v = ":], [:m4svm_instruction_switch_threaded:])";

/*
-----------------------------------m4_dnl
-----------------------------------
$1
-----------------------------------m4_dnl
-----------------------------------
*/

    case SVM_INSTRUCTION_$1:
      {
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p $1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	/* instruction body */
	m4svm_skip_two_modes_fast ($1);
	m4svm_end_two_modes_fast ();

	$4 m4_dnl;

	/* dispatch */
	goto dispatch;
      }

      m4svm_define_end = ":])";
    }
}
