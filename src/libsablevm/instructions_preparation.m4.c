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
 * [:m4svm_instruction($1, $2, m4_dnl:]) */

/*
----------------------------------------------------------------------
m4svm_instruction
----------------------------------------------------------------------
*/

/* m4_ifdef([:m4svm_inlined_threaded:],
   [:m4_define([:m4svm_instruction:],
   [:m4svm_instruction_inlined_threaded([:$1:], [:$2:],[:$3:]):]):])
   m4_ifdef([:m4svm_direct_threaded:],
   [:m4_define([:m4svm_instruction:],
   [:m4svm_instruction_direct_threaded([:$1:], [:$2:], [:$3:]):]):])
   m4_ifdef([:m4svm_switch_threaded:],
   [:m4_define([:m4svm_instruction:],
   [:m4svm_instruction_switch_threaded([:$1:], [:$2:], [:$3:]):]):]) */

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
m4svm_mark_start_and_skip
----------------------------------------------------------------------
*/

/*
NOTE: We expect the compiler to be:
      * EITHER that smart to check comparison of two CONSTANT values at
        compile time and generate code accordingly
      * OR that dumb so that it didn't overoptimize this conditional
        making whole thing non-inlinable
*/

/* m4svm_comment_define([:m4svm_mark_start_and_skip_normal:],
 * [:m4_ifdef([:m4svm_inlined_threaded:],
 * [:m4_ifelse(m4svm_is_two_modes_fast($1),,,
 * [:
 * 	{	/[::]* skip preparation address A *[::]/
 * 	  if (SVM_INLINEABLE_$1 != SVM_INTRP_FLAG_INLINEABLE) pc++;
 * 	}
 * :]):],
 * [:m4_ifelse(m4svm_is_two_modes_fast($1),,,
 * [:
 * 	pc++;	/[::]* skip preparation address B *[::]/
 * :]):]):])
 */

/*
NOTE: Version below is for compilation in special mode to allow
      testing of inlinablility of bytecodes and is only applicable
      when you configure for inlined engine. Define
      m4svm_inlinability_testing_mode to turn it on.
*/

/* m4svm_comment_define([:m4svm_mark_start_and_skip_testing:],
 * [:m4_ifdef([:m4svm_inlined_threaded:],
 * [:m4_ifelse(m4svm_is_two_modes_fast($1),,,
 * [:
 * 	/[::]* extra skip if we're currently in inlinable but not inlined code *[::]/
 * 	{ pc = no_inlining_increment_pc(env, SVM_INSTRUCTION_$1, pc); }
 * :]):],
 * [:
 * 	pc++;	/[::]* skip preparation address C *[::]/
 * :]):])
 */

/* m4svm_comment_define([:m4svm_mark_start_and_skip:],
 * [:m4svm_mark_start_and_skip_1(:]) */

/* m4svm_comment_define([:m4svm_mark_start_and_skip_1:],
 * [:m4svm_mark_start_and_skip_2$1:]) */

/* m4svm_comment_define([:m4svm_mark_start_and_skip_2:],
 * [:m4svm_mark_start_and_skip_3([:$1:]) m4_dnl:]) */

/*
   m4_ifdef([:m4svm_inlinability_testing_mode:],
   [:m4_define([:m4svm_mark_start_and_skip_3:],
     [:[:m4svm_mark_start_and_skip_testing($1):]:]):],
   [:m4_define([:m4svm_mark_start_and_skip_3:],
     [:[:m4svm_mark_start_and_skip_normal($1):]:]):])

   m4_define([:m4svm_end_start_and_skip:],[:) m4_dnl:])
*/

/*
----------------------------------------------------------------------
m4svm_(dont_)expect_sigsegv
----------------------------------------------------------------------
*/

/* m4svm_comment_define([:m4svm_expect_sigsegv:],[:m4_[::]dnl:]) */
/* m4svm_comment_define([:m4svm_dont_expect_sigsegv:],[:m4_[::]dnl:]) */

/* m4_ifdef([:m4svm_inlinability_testing_mode:],[:
 * m4svm_comment_define([:m4svm_expect_sigsegv:],
 * [:[:{ env->inlinability_testing.sigsegv_expected = JNI_TRUE; } {
 * :] m4_[::]dnl:]):]) */

/* m4_ifdef([:m4svm_inlinability_testing_mode:],[:
 * m4svm_comment_define([:m4svm_dont_expect_sigsegv:],
 * [:[:} { env->inlinability_testing.sigsegv_expected = JNI_FALSE; }
 * :] m4_[::]dnl:]):]) */

/*
----------------------------------------------------------------------
m4svm_instruction_inlined_threaded
----------------------------------------------------------------------
*/

void
dummy ()
{
  switch (dummy)
    {
      m4svm_define_begin v = ":], [:m4svm_instruction_inlined_threaded:])";

/*
-----------------------------------m4_dnl
-----------------------------------
$1
-----------------------------------m4_dnl
-----------------------------------
*/

    case SVM_INSTRUCTION_$1:
      {
	env->vm->instructions[instr].param_count = $2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_$1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_$1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_$1) - ((char *) &&INLINED_START_$1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_$1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "$1");
#endif
	break;

      START_$1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p $1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_$1:
	m4svm_mark_start_and_skip ($1);
	m4svm_end_start_and_skip ();

	{

	  _svmm_verbose_instructions_inlined (env, pc, "$1");

	  /* instruction body */
	  $3 m4_dnl;

	}

      END_$1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }
      m4svm_define_end = ":])";
    }
}

/*
----------------------------------------------------------------------
m4svm_instruction_direct_threaded
----------------------------------------------------------------------
*/

void
dummy ()
{
  switch (dummy)
    {
      m4svm_define_begin v = ":], [:m4svm_instruction_direct_threaded:])";

/*
-----------------------------------m4_dnl
-----------------------------------
$1
-----------------------------------m4_dnl
-----------------------------------
*/

    case SVM_INSTRUCTION_$1:
      {
	env->vm->instructions[instr].param_count = $2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_$1;

#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "$1");
#endif
	break;

      START_$1:
#ifndef	NDEBUG

	if (env->vm->verbose_instructions == JNI_TRUE)
	  {
	    _svmf_printf (env, stderr,
			  "T%d: [verbose instructions: executing @%p $1]\n",
			  env->thread.id, (void *) (pc - 1));
	  }

#endif

	m4svm_mark_start_and_skip ($1);
	m4svm_end_start_and_skip ();

	/* instruction body */
	$3 m4_dnl;

	/* dispatch */
	goto *((pc++)->implementation);
      }
      m4svm_define_end = ":])";
    }
}

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
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = $2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "$1");
#endif
	break;
      }
      m4svm_define_end = ":])";
    }
}
