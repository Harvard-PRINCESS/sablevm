/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* THIS CODE IS USED **ONLY** IN INLINABILITY TESTING MODE !!! */

/* IDEA: from the method name we should be able to deduce what's the
     name of the *only one* instruction that we want to have inlined
     for this sequence. Compare([instr].name, method->name)
   PROBLEM: names of the tests are not necessarily the same as the
     names of internal SableVM instructions.
   SOLUTION: based on some switch - execute once only inlining these
     bytecodes that can be recognized as the ones we want to inline
     based on the name of the method, then execute tests second
     time, for all instructions.
     In fact it may make sense to first compile version with in the
     first way - then use gained informations about inlinability and
     compile the second version for fine-tuning */


/*
----------------------------------------------------------------------
_svmf_get_bytecode_by_method_name
----------------------------------------------------------------------
*/

svm_static jint
_svmf_get_bytecode_by_method_name (_svmt_JNIEnv *env, char *method_name)
{
/* Ex: method "svmTestBytecode_aload_0" matches bytecode "ALOAD_0" */
  int i;
  /* EG: constant-size arrays are critical bugs. */
  /* Gadek: I had a version that did the "proper" dynamic allocation,
   * but even though it seemed small change and I took care to make the
   * additional memory allocation calls via "function pointer" trick -
   * this change broke inlined completly and has therefore been never
   * merged into the mainline. */
  char name[_SABLEVM_BYTECODE_NAME_MAX_LENGTH], *underscore, *suffix;

  underscore = strchr (method_name, '_');
  if (underscore == NULL)
    goto nomatch;
  if (strlen (underscore) < 2)
    goto nomatch;

  /* ignore _wide_ prefix */
  if (strncmp (underscore, "_wide_", 6) == 0)
    strcpy (name, &underscore[6]);
  else
    strcpy (name, &underscore[1]);

  /* ignore __* suffixes */
  suffix = strstr (name, "__");
  if (suffix != NULL)
    suffix[0] = 0;

  /* know about some specials and convert names accordingly */
  if (strncmp (name, "baload", strlen ("baload")) == 0)
    name[strlen ("baload")] = 0;
  if (strncmp (name, "bastore", strlen ("bastore")) == 0)
    name[strlen ("bastore")] = 0;
  if (strncmp (name, "multianewarray", strlen ("multianewarray")) == 0)
    name[strlen ("multianewarray")] = 0;
  if (strncmp (name, "getfield_array", strlen ("getfield_array")) == 0)
    strcpy (name, "getfield_reference");
  if (strncmp (name, "getstatic_array", strlen ("getstatic_array")) == 0)
    strcpy (name, "getstatic_reference");
  if (strncmp (name, "putfield_array", strlen ("putfield_array")) == 0)
    strcpy (name, "putfield_reference");
  if (strncmp (name, "putstatic_array", strlen ("putstatic_array")) == 0)
    strcpy (name, "putstatic_reference");
  if (strncmp (name, "ldc_w_int", strlen ("ldc_w_int")) == 0)
    strcpy (name, "ldc_integer");
  if (strncmp (name, "ldc_w_", strlen ("ldc_w_")) == 0)	/* remove "_w_" */
    memmove (&name[strlen ("ldc")], &name[strlen ("ldc_w")],
	     strlen (name) - strlen ("ldc") + 1);

  for (i = 0; i < strlen (name); i++)
    name[i] = toupper (name[i]);

  for (i = 0; i < SVM_INSTRUCTION_COUNT; i++)
    if (strcmp (name, env->vm->instructions[i].name) == 0)
      return i;

nomatch:
  _svmf_printf (env, stderr, "UNABLE_TO_MATCH: %s\n", method_name);
  return -1;
}

/*
----------------------------------------------------------------------
_svmf_inlined_testing_initialize
----------------------------------------------------------------------
*/

svm_static void
_svmf_inlined_testing_initialize (_svmt_JNIEnv *env)
{
  env->inlinability_testing.ever_used = JNI_FALSE;
  memset (env->inlinability_testing.bytecode_inlinability,
	  SVM_BCI_UNTESTED, SVM_INSTRUCTION_COUNT * sizeof (jbyte));
  memset (env->inlinability_testing.bytecode_recognizability,
	  JNI_FALSE, SVM_INSTRUCTION_COUNT * sizeof (jbyte));
}

/*
----------------------------------------------------------------------
_svmf_print_inlined_testing_results
----------------------------------------------------------------------
*/

svm_static void
_svmf_print_inlined_testing_results (_svmt_JNIEnv *env)
{
  char result[_SABLEVM_BYTECODE_NAME_MAX_LENGTH];
  const char *is_recognizable;
  const char filling[] = "-----------------------------";
  const char recognizable_desc[] = "RECognizable";
  const char not_recognizable_desc[] = "NOT recognizable";
  jint i;
  jint noninlinable = 0;
  jint untested = 0;
  jint failing = 0;
  jint inlined = 0;
  jint unknown = 0;
  jint recogn = 0;
  jint nonrecogn = 0;

  if (env->inlinability_testing.ever_used == JNI_FALSE)
    return;

  _svmf_printf (env, stderr,
		"\n\n\nAUTOMATICALLY GATHERED INSTRUCTION INLINABILITY TEST RESULTS\n\n");

  for (i = 0; i < SVM_INSTRUCTION_COUNT; i++)
    {
      if (i == SVM_INSTRUCTION_UNDEFINED_186)
	continue;

      switch (env->inlinability_testing.bytecode_inlinability[i])
	{
	case SVM_BCI_UNTESTED:
	  if (env->vm->instructions[i].flag != SVM_INTRP_FLAG_INLINEABLE)
	    {
	      strcpy (result, "UNTESTED - NONINLINABLE");
	      noninlinable++;
	    }
	  else
	    {
	      strcpy (result, "UNTESTED");
	      untested++;
	    }
	  break;
	case SVM_BCI_INLINED | SVM_BCI_FAILING:
	  strcpy (result, "FAILING");
	  failing++;
	  break;
	case SVM_BCI_INLINED:
	  strcpy (result, "INLINED and WORKING");
	  inlined++;
	  break;
	default:
	  sprintf (result, "UNDETERMINED (%i)",
		   env->inlinability_testing.bytecode_inlinability[i]);
	  unknown++;
	}

      if (env->inlinability_testing.bytecode_recognizability[i] != JNI_FALSE)
	{
	  is_recognizable = recognizable_desc;
	  recogn++;
	}
      else
	{
	  is_recognizable = not_recognizable_desc;
	  nonrecogn++;
	}

      _svmf_printf (env, stderr, "%s %s=> %s (%s)\n",
		    env->vm->instructions[i].name,
		    &filling[strlen (env->vm->instructions[i].name)],
		    result, is_recognizable);
    }

  _svmf_printf (env, stderr, "\nINLINABILITY TESTING STATISTICS:\n");
  _svmf_printf (env, stderr, "\tUNTESTED - NONINLINABLE           = %i\n",
		noninlinable);
  _svmf_printf (env, stderr, "\tUNTESTED                          = %i\n",
		untested);
  _svmf_printf (env, stderr, "\tFAILING                           = %i\n",
		failing);
  _svmf_printf (env, stderr, "\tINLINED and WORKING (NOT FAILING) = %i\n",
		inlined);
  _svmf_printf (env, stderr, "\tUNDETERMINED                      = %i\n",
		unknown);
  _svmf_printf (env, stderr, "\tTOTAL INLNED   (FAILING OR NOT)   = %i\n",
		failing + inlined);
  _svmf_printf (env, stderr, "\tRECOGNIZABLE   METHOD/BCODE NAME  = %i\n",
		recogn);
  _svmf_printf (env, stderr, "\tNON-RECOGN. BY METHOD/BCODE NAME  = %i\n",
		nonrecogn);
}

/*
----------------------------------------------------------------------
_svmf_no_inlining
----------------------------------------------------------------------
*/

svm_static jboolean
_svmf_no_inlining (_svmt_JNIEnv *env, _svmt_word instr, jint mode)
{
  static _svmt_word last_codes[SVM_IS_INLINED_HISTORY_SIZE] = { -1 };
  static jint last_results[SVM_IS_INLINED_HISTORY_SIZE];
  static jint last_who[SVM_IS_INLINED_HISTORY_SIZE];
  _svmt_method_info *method;
  static char who_sighnd[] = "SIGHND";
  static char who_isbcod[] = "ISBCOD";
  static char who_ismeth[] = "ISMETH";
  static char who_unknwn[] = "???";
  char *who;
  jint result;
  int i, byname = -1;

  if (mode == SVM_IS_INLINED_GET_BACKTRACE)
    {
      _svmf_printf (env, stderr, "Last signal no.: %i\n",
		    env->inlinability_testing.last_signal);

      for (i = 0; i < SVM_IS_INLINED_HISTORY_SIZE; i++)
	{
	  /* skip ISMETH at the beginning, stop at code == -1 or another ISMET */
	  if ((last_who[i] == SVM_IS_INLINED_METHOD) && (i == 0))
	    continue;
	  if ((last_codes[i] == -1) || (last_who[i] == SVM_IS_INLINED_METHOD))
	    break;

	  switch (last_who[i])
	    {
	    case SVM_IS_INLINED_FROM_SIGHANDLER:
	      who = who_sighnd;
	      break;
	    case SVM_IS_INLINED_BYTECODE:
	      who = who_isbcod;
	      break;
	    case SVM_IS_INLINED_METHOD:
	      who = who_ismeth;
	      break;
	    default:
	      who = who_unknwn;
	      break;
	    }
	  _svmf_printf (env, stderr, "Q#%i by %s: %s\t(%i)\n", i, who,
			env->vm->instructions[last_codes[i]].name,
			last_results[i]);
	}

      return JNI_FALSE;
    }

  if (env->stack.current_frame == NULL)
    return JNI_TRUE;

  method = env->stack.current_frame->method;

  if (strstr (DREF (method->name, value), "svmTest"))
    if (strstr (method->class_info->name, "SVMTest"))
      {
	if (mode == SVM_IS_INLINED_FROM_SIGHANDLER)
	  {
	    /* we're inside *generally* inlinable code
	       (info for sighandler w/o any output/printing) */
	    env->inlinability_testing.last_signal = instr;
	    return JNI_FALSE;
	  }

	if (mode == SVM_IS_INLINED_BYTECODE)
	  {

	    who = who_isbcod;
	    byname =
	      _svmf_get_bytecode_by_method_name (env,
						 DREF (method->name, value));

	    if (byname == instr)
	      {
		env->inlinability_testing.bytecode_recognizability[instr] = 1;
		/* we're eventually inlining only those bytecodes
		   whose names match current method name! */
		result =
		  (env->vm->instructions[instr].flag !=
		   SVM_INTRP_FLAG_INLINEABLE);
	      }
	    else
	      {
		result = JNI_TRUE;
	      }

	  }
	else
	  {			/* mode == SVM_IS_INLINED_METHOD */
	    who = who_ismeth;
	    result = JNI_FALSE;	/* generally inlinable code */
	  }

	_svmf_printf (env, stderr,
		      "INLQ: %s, ALLOW: %i, INSTR: %s, METHOD: %s, CLASS: %s\n",
		      who, (result ? 0 : 1),
		      env->vm->instructions[instr].name, DREF (method->name,
							       value),
		      method->class_info->name);

	/* save to be able to do backtrace when needed */
	memmove (&last_codes[1], &last_codes[0],
		 (SVM_IS_INLINED_HISTORY_SIZE - 1) * sizeof (_svmt_word));
	memmove (&last_results[1], &last_results[0],
		 (SVM_IS_INLINED_HISTORY_SIZE - 1) * sizeof (jint));
	memmove (&last_who[1], &last_who[0],
		 (SVM_IS_INLINED_HISTORY_SIZE - 1) * sizeof (int));

	last_codes[0] = instr;
	last_results[0] = (result ? 0 : 1);
	last_who[0] = mode;

	/* note, that we have inlined this bytecode at least once */
	if (result == JNI_FALSE)
	  {
	    env->inlinability_testing.bytecode_inlinability[instr]
	      |= SVM_BCI_INLINED;
	    env->inlinability_testing.ever_used = JNI_TRUE;
	  }

	return result;
      }

  return JNI_TRUE;
}

/*
----------------------------------------------------------------------
_svmf_no_inlining_increment_pc
----------------------------------------------------------------------
*/

svm_static _svmt_code *
_svmf_no_inlining_increment_pc (_svmt_JNIEnv *env,
				_svmt_word instr, _svmt_code *pc)
{
  if (_svmf_no_inlining (env, instr, SVM_IS_INLINED_BYTECODE))
    pc++;
  return pc;
}
