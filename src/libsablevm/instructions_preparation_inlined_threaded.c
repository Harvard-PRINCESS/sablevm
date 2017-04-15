/* This file has been automatically generated from "instructions.m4.c" */

/*
----------------------------------------------------------------------
BIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BIPUSH:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_BIPUSH;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_BIPUSH;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_BIPUSH) - ((char *) &&INLINED_START_BIPUSH);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_BIPUSH;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "BIPUSH");
#endif
	break;

      START_BIPUSH:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p BIPUSH]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_BIPUSH:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "BIPUSH");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_BIPUSH:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
SIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SIPUSH:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_SIPUSH;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_SIPUSH;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_SIPUSH) - ((char *) &&INLINED_START_SIPUSH);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_SIPUSH;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "SIPUSH");
#endif
	break;

      START_SIPUSH:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p SIPUSH]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_SIPUSH:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "SIPUSH");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_SIPUSH:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC) - ((char *) &&INLINED_START_LDC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC");
#endif
	break;

      START_LDC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_LDC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_W:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_W;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_W;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_W) - ((char *) &&INLINED_START_LDC_W);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_W;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_W");
#endif
	break;

      START_LDC_W:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_W]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_W:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_W");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_LDC_W:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC2_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC2_W:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC2_W;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC2_W;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC2_W) - ((char *) &&INLINED_START_LDC2_W);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC2_W;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC2_W");
#endif
	break;

      START_LDC2_W:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC2_W]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC2_W:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC2_W");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_LDC2_W:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC) - ((char *) &&INLINED_START_GETSTATIC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC");
#endif
	break;

      START_GETSTATIC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_GETSTATIC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC) - ((char *) &&INLINED_START_PUTSTATIC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC");
#endif
	break;

      START_PUTSTATIC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_PUTSTATIC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD) - ((char *) &&INLINED_START_GETFIELD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD");
#endif
	break;

      START_GETFIELD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_GETFIELD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD) - ((char *) &&INLINED_START_PUTFIELD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD");
#endif
	break;

      START_PUTFIELD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_PUTFIELD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY) - ((char *) &&INLINED_START_NEWARRAY);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY");
#endif
	break;

      START_NEWARRAY:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_NEWARRAY:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
WIDE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_WIDE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_WIDE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_WIDE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_WIDE) - ((char *) &&INLINED_START_WIDE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_WIDE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "WIDE");
#endif
	break;

      START_WIDE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p WIDE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_WIDE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "WIDE");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_WIDE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GOTO_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_W:
      {
	env->vm->instructions[instr].param_count = 4;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GOTO_W;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GOTO_W;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GOTO_W) - ((char *) &&INLINED_START_GOTO_W);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GOTO_W;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GOTO_W");
#endif
	break;

      START_GOTO_W:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GOTO_W]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GOTO_W:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GOTO_W");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_GOTO_W:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
JSR_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_W:
      {
	env->vm->instructions[instr].param_count = 4;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_JSR_W;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_JSR_W;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_JSR_W) - ((char *) &&INLINED_START_JSR_W);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_JSR_W;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "JSR_W");
#endif
	break;

      START_JSR_W:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p JSR_W]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_JSR_W:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "JSR_W");

	  /* instruction body */
	  
	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	 
	}

      END_JSR_W:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NOP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NOP:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NOP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NOP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NOP) - ((char *) &&INLINED_START_NOP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NOP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NOP");
#endif
	break;

      START_NOP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NOP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NOP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NOP");

	  /* instruction body */
	  
	 
	}

      END_NOP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ACONST_NULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ACONST_NULL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ACONST_NULL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ACONST_NULL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ACONST_NULL) - ((char *) &&INLINED_START_ACONST_NULL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ACONST_NULL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ACONST_NULL");
#endif
	break;

      START_ACONST_NULL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ACONST_NULL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ACONST_NULL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ACONST_NULL");

	  /* instruction body */
	  
	stack[stack_size++].reference = NULL;

	 
	}

      END_ACONST_NULL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_M1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_M1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_M1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_M1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_M1) - ((char *) &&INLINED_START_ICONST_M1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_M1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_M1");
#endif
	break;

      START_ICONST_M1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_M1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_M1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_M1");

	  /* instruction body */
	  
	stack[stack_size++].jint = -1;

	 
	}

      END_ICONST_M1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_0) - ((char *) &&INLINED_START_ICONST_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_0");
#endif
	break;

      START_ICONST_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_0");

	  /* instruction body */
	  
	stack[stack_size++].jint = 0;

	 
	}

      END_ICONST_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_1) - ((char *) &&INLINED_START_ICONST_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_1");
#endif
	break;

      START_ICONST_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_1");

	  /* instruction body */
	  
	stack[stack_size++].jint = 1;

	 
	}

      END_ICONST_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_2) - ((char *) &&INLINED_START_ICONST_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_2");
#endif
	break;

      START_ICONST_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_2");

	  /* instruction body */
	  
	stack[stack_size++].jint = 2;

	 
	}

      END_ICONST_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_3) - ((char *) &&INLINED_START_ICONST_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_3");
#endif
	break;

      START_ICONST_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_3");

	  /* instruction body */
	  
	stack[stack_size++].jint = 3;

	 
	}

      END_ICONST_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_4
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_4:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_4;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_4;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_4) - ((char *) &&INLINED_START_ICONST_4);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_4;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_4");
#endif
	break;

      START_ICONST_4:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_4]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_4:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_4");

	  /* instruction body */
	  
	stack[stack_size++].jint = 4;

	 
	}

      END_ICONST_4:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ICONST_5
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_5:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ICONST_5;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ICONST_5;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ICONST_5) - ((char *) &&INLINED_START_ICONST_5);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ICONST_5;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ICONST_5");
#endif
	break;

      START_ICONST_5:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ICONST_5]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ICONST_5:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ICONST_5");

	  /* instruction body */
	  
	stack[stack_size++].jint = 5;

	 
	}

      END_ICONST_5:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LCONST_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LCONST_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LCONST_0) - ((char *) &&INLINED_START_LCONST_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LCONST_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LCONST_0");
#endif
	break;

      START_LCONST_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LCONST_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LCONST_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LCONST_0");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) = 0;
	stack_size += 2;

	 
	}

      END_LCONST_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LCONST_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LCONST_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LCONST_1) - ((char *) &&INLINED_START_LCONST_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LCONST_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LCONST_1");
#endif
	break;

      START_LCONST_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LCONST_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LCONST_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LCONST_1");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) = 1;
	stack_size += 2;

	 
	}

      END_LCONST_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FCONST_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FCONST_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FCONST_0) - ((char *) &&INLINED_START_FCONST_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FCONST_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FCONST_0");
#endif
	break;

      START_FCONST_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FCONST_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FCONST_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FCONST_0");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = 0;

	 
	}

      END_FCONST_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FCONST_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FCONST_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FCONST_1) - ((char *) &&INLINED_START_FCONST_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FCONST_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FCONST_1");
#endif
	break;

      START_FCONST_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FCONST_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FCONST_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FCONST_1");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = 1;

	 
	}

      END_FCONST_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FCONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FCONST_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FCONST_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FCONST_2) - ((char *) &&INLINED_START_FCONST_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FCONST_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FCONST_2");
#endif
	break;

      START_FCONST_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FCONST_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FCONST_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FCONST_2");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = 2;

	 
	}

      END_FCONST_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DCONST_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DCONST_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DCONST_0) - ((char *) &&INLINED_START_DCONST_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DCONST_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DCONST_0");
#endif
	break;

      START_DCONST_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DCONST_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DCONST_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DCONST_0");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) = 0;
	stack_size += 2;

	 
	}

      END_DCONST_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DCONST_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DCONST_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DCONST_1) - ((char *) &&INLINED_START_DCONST_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DCONST_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DCONST_1");
#endif
	break;

      START_DCONST_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DCONST_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DCONST_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DCONST_1");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) = 1;
	stack_size += 2;

	 
	}

      END_DCONST_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_INTEGER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_INTEGER:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_INTEGER;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_INTEGER;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_INTEGER) - ((char *) &&INLINED_START_LDC_INTEGER);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_INTEGER;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_INTEGER");
#endif
	break;

      START_LDC_INTEGER:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_INTEGER]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_INTEGER:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_INTEGER");

	  /* instruction body */
	  
	stack[stack_size++].jint = (pc++)->jint;

	 
	}

      END_LDC_INTEGER:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_FLOAT) - ((char *) &&INLINED_START_LDC_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_FLOAT");
#endif
	break;

      START_LDC_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_FLOAT");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = (pc++)->jfloat;

	 
	}

      END_LDC_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_STRING:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_STRING;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_STRING;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_STRING) - ((char *) &&INLINED_START_LDC_STRING);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_STRING;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_STRING");
#endif
	break;

      START_LDC_STRING:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_STRING]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_STRING:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_LDC_STRING != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_STRING");

	  /* instruction body */
	  
	stack[stack_size++].reference = *((pc++)->jobject);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	 
	}

      END_LDC_STRING:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_LONG) - ((char *) &&INLINED_START_LDC_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_LONG");
#endif
	break;

      START_LDC_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_LONG");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) = *((pc++)->pjlong);
	stack_size += 2;

	 
	}

      END_LDC_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDC_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDC_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDC_DOUBLE) - ((char *) &&INLINED_START_LDC_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDC_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDC_DOUBLE");
#endif
	break;

      START_LDC_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDC_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDC_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDC_DOUBLE");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) = *((pc++)->pjdouble);
	stack_size += 2;

	 
	}

      END_LDC_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ILOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ILOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ILOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ILOAD) - ((char *) &&INLINED_START_ILOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ILOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ILOAD");
#endif
	break;

      START_ILOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ILOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ILOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ILOAD");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].jint = locals[indx].jint;
	}

	 
	}

      END_ILOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LLOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LLOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LLOAD) - ((char *) &&INLINED_START_LLOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LLOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LLOAD");
#endif
	break;

      START_LLOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LLOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LLOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LLOAD");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  *((jlong *) (void *) &stack[stack_size]) =
	    *((jlong *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	 
	}

      END_LLOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FLOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FLOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FLOAD) - ((char *) &&INLINED_START_FLOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FLOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FLOAD");
#endif
	break;

      START_FLOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FLOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FLOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FLOAD");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].jfloat = locals[indx].jfloat;
	}

	 
	}

      END_FLOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DLOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DLOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DLOAD) - ((char *) &&INLINED_START_DLOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DLOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DLOAD");
#endif
	break;

      START_DLOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DLOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DLOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DLOAD");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  *((jdouble *) (void *) &stack[stack_size]) =
	    *((jdouble *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	 
	}

      END_DLOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ILOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ILOAD_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ILOAD_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ILOAD_0) - ((char *) &&INLINED_START_ILOAD_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ILOAD_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ILOAD_0");
#endif
	break;

      START_ILOAD_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ILOAD_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ILOAD_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ILOAD_0");

	  /* instruction body */
	  
	stack[stack_size++].jint = locals[0].jint;

	 
	}

      END_ILOAD_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ILOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ILOAD_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ILOAD_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ILOAD_1) - ((char *) &&INLINED_START_ILOAD_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ILOAD_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ILOAD_1");
#endif
	break;

      START_ILOAD_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ILOAD_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ILOAD_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ILOAD_1");

	  /* instruction body */
	  
	stack[stack_size++].jint = locals[1].jint;

	 
	}

      END_ILOAD_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ILOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ILOAD_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ILOAD_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ILOAD_2) - ((char *) &&INLINED_START_ILOAD_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ILOAD_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ILOAD_2");
#endif
	break;

      START_ILOAD_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ILOAD_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ILOAD_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ILOAD_2");

	  /* instruction body */
	  
	stack[stack_size++].jint = locals[2].jint;

	 
	}

      END_ILOAD_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ILOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ILOAD_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ILOAD_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ILOAD_3) - ((char *) &&INLINED_START_ILOAD_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ILOAD_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ILOAD_3");
#endif
	break;

      START_ILOAD_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ILOAD_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ILOAD_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ILOAD_3");

	  /* instruction body */
	  
	stack[stack_size++].jint = locals[3].jint;

	 
	}

      END_ILOAD_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LLOAD_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LLOAD_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LLOAD_0) - ((char *) &&INLINED_START_LLOAD_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LLOAD_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LLOAD_0");
#endif
	break;

      START_LLOAD_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LLOAD_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LLOAD_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LLOAD_0");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[0]);
	stack_size += 2;

	 
	}

      END_LLOAD_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LLOAD_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LLOAD_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LLOAD_1) - ((char *) &&INLINED_START_LLOAD_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LLOAD_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LLOAD_1");
#endif
	break;

      START_LLOAD_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LLOAD_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LLOAD_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LLOAD_1");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[1]);
	stack_size += 2;

	 
	}

      END_LLOAD_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LLOAD_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LLOAD_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LLOAD_2) - ((char *) &&INLINED_START_LLOAD_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LLOAD_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LLOAD_2");
#endif
	break;

      START_LLOAD_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LLOAD_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LLOAD_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LLOAD_2");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[2]);
	stack_size += 2;

	 
	}

      END_LLOAD_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LLOAD_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LLOAD_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LLOAD_3) - ((char *) &&INLINED_START_LLOAD_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LLOAD_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LLOAD_3");
#endif
	break;

      START_LLOAD_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LLOAD_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LLOAD_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LLOAD_3");

	  /* instruction body */
	  
	*((jlong *) (void *) &stack[stack_size]) =
	  *((jlong *) (void *) &locals[3]);
	stack_size += 2;

	 
	}

      END_LLOAD_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FLOAD_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FLOAD_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FLOAD_0) - ((char *) &&INLINED_START_FLOAD_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FLOAD_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FLOAD_0");
#endif
	break;

      START_FLOAD_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FLOAD_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FLOAD_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FLOAD_0");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = locals[0].jfloat;

	 
	}

      END_FLOAD_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FLOAD_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FLOAD_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FLOAD_1) - ((char *) &&INLINED_START_FLOAD_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FLOAD_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FLOAD_1");
#endif
	break;

      START_FLOAD_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FLOAD_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FLOAD_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FLOAD_1");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = locals[1].jfloat;

	 
	}

      END_FLOAD_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FLOAD_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FLOAD_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FLOAD_2) - ((char *) &&INLINED_START_FLOAD_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FLOAD_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FLOAD_2");
#endif
	break;

      START_FLOAD_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FLOAD_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FLOAD_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FLOAD_2");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = locals[2].jfloat;

	 
	}

      END_FLOAD_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FLOAD_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FLOAD_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FLOAD_3) - ((char *) &&INLINED_START_FLOAD_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FLOAD_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FLOAD_3");
#endif
	break;

      START_FLOAD_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FLOAD_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FLOAD_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FLOAD_3");

	  /* instruction body */
	  
	stack[stack_size++].jfloat = locals[3].jfloat;

	 
	}

      END_FLOAD_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DLOAD_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DLOAD_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DLOAD_0) - ((char *) &&INLINED_START_DLOAD_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DLOAD_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DLOAD_0");
#endif
	break;

      START_DLOAD_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DLOAD_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DLOAD_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DLOAD_0");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[0]);
	stack_size += 2;

	 
	}

      END_DLOAD_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DLOAD_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DLOAD_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DLOAD_1) - ((char *) &&INLINED_START_DLOAD_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DLOAD_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DLOAD_1");
#endif
	break;

      START_DLOAD_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DLOAD_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DLOAD_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DLOAD_1");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[1]);
	stack_size += 2;

	 
	}

      END_DLOAD_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DLOAD_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DLOAD_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DLOAD_2) - ((char *) &&INLINED_START_DLOAD_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DLOAD_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DLOAD_2");
#endif
	break;

      START_DLOAD_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DLOAD_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DLOAD_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DLOAD_2");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[2]);
	stack_size += 2;

	 
	}

      END_DLOAD_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DLOAD_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DLOAD_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DLOAD_3) - ((char *) &&INLINED_START_DLOAD_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DLOAD_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DLOAD_3");
#endif
	break;

      START_DLOAD_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DLOAD_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DLOAD_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DLOAD_3");

	  /* instruction body */
	  
	*((jdouble *) (void *) &stack[stack_size]) =
	  *((jdouble *) (void *) &locals[3]);
	stack_size += 2;

	 
	}

      END_DLOAD_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IALOAD) - ((char *) &&INLINED_START_IALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IALOAD");
#endif
	break;

      START_IALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_int_array_element (array, indx);
	}

	 
	}

      END_IALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LALOAD) - ((char *) &&INLINED_START_LALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LALOAD");
#endif
	break;

      START_LALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[stack_size - 1].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_size - 2].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_long_array_element (array, indx);
	}

	 
	}

      END_LALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FALOAD) - ((char *) &&INLINED_START_FALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FALOAD");
#endif
	break;

      START_FALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jfloat = _svmf_get_float_array_element (array, indx);
	}

	 
	}

      END_FALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DALOAD) - ((char *) &&INLINED_START_DALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DALOAD");
#endif
	break;

      START_DALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[stack_size - 1].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_size - 2].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_double_array_element (array, indx);
	}

	 
	}

      END_DALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
CALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_CALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_CALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_CALOAD) - ((char *) &&INLINED_START_CALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_CALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "CALOAD");
#endif
	break;

      START_CALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p CALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_CALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "CALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_char_array_element (array, indx);
	}

	 
	}

      END_CALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
SALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_SALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_SALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_SALOAD) - ((char *) &&INLINED_START_SALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_SALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "SALOAD");
#endif
	break;

      START_SALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p SALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_SALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "SALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].jint = _svmf_get_short_array_element (array, indx);
	}

	 
	}

      END_SALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ALOAD) - ((char *) &&INLINED_START_ALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ALOAD");
#endif
	break;

      START_ALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ALOAD");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].reference = locals[indx].reference;
	}

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
	}

      END_ALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ALOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ALOAD_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ALOAD_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ALOAD_0) - ((char *) &&INLINED_START_ALOAD_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ALOAD_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ALOAD_0");
#endif
	break;

      START_ALOAD_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ALOAD_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ALOAD_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ALOAD_0");

	  /* instruction body */
	  
	stack[stack_size++].reference = locals[0].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
	}

      END_ALOAD_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ALOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ALOAD_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ALOAD_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ALOAD_1) - ((char *) &&INLINED_START_ALOAD_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ALOAD_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ALOAD_1");
#endif
	break;

      START_ALOAD_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ALOAD_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ALOAD_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ALOAD_1");

	  /* instruction body */
	  
	stack[stack_size++].reference = locals[1].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
	}

      END_ALOAD_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ALOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ALOAD_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ALOAD_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ALOAD_2) - ((char *) &&INLINED_START_ALOAD_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ALOAD_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ALOAD_2");
#endif
	break;

      START_ALOAD_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ALOAD_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ALOAD_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ALOAD_2");

	  /* instruction body */
	  
	stack[stack_size++].reference = locals[2].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
	}

      END_ALOAD_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ALOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ALOAD_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ALOAD_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ALOAD_3) - ((char *) &&INLINED_START_ALOAD_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ALOAD_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ALOAD_3");
#endif
	break;

      START_ALOAD_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ALOAD_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ALOAD_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ALOAD_3");

	  /* instruction body */
	  
	stack[stack_size++].reference = locals[3].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	 
	}

      END_ALOAD_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
AALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_AALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_AALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_AALOAD) - ((char *) &&INLINED_START_AALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_AALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "AALOAD");
#endif
	break;

      START_AALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p AALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_AALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "AALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].reference =
	    _svmf_get_reference_array_element (array, indx);
	}

#if defined (MAGIC)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	 
	}

      END_AALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
BALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BALOAD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_BALOAD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_BALOAD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_BALOAD) - ((char *) &&INLINED_START_BALOAD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_BALOAD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "BALOAD");
#endif
	break;

      START_BALOAD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p BALOAD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_BALOAD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "BALOAD");

	  /* instruction body */
	  
	{
	  jint indx = stack[--stack_size].jint;
	  size_t stack_top = stack_size - 1;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[stack_top].reference;
	  jint base_type;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  base_type = _svmf_cast_array (array->vtable->type)->base_type;

	  switch (base_type)
	    {
	    case SVM_TYPE_BYTE:
	      {
		stack[stack_top].jint =
		  _svmf_get_byte_array_element (array, indx);
	      }
	      break;

	    case SVM_TYPE_BOOLEAN:
	      {
		stack[stack_top].jint =
		  _svmf_get_boolean_array_element (array, indx);
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

	 
	}

      END_BALOAD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISTORE) - ((char *) &&INLINED_START_ISTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISTORE");
#endif
	break;

      START_ISTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISTORE");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  locals[indx].jint = stack[--stack_size].jint;
	}

	 
	}

      END_ISTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSTORE) - ((char *) &&INLINED_START_LSTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSTORE");
#endif
	break;

      START_LSTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSTORE");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *((jlong *) (void *) &locals[indx]) =
	    *((jlong *) (void *) &stack[stack_size]);
	}

	 
	}

      END_LSTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSTORE) - ((char *) &&INLINED_START_FSTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSTORE");
#endif
	break;

      START_FSTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSTORE");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  locals[indx].jfloat = stack[--stack_size].jfloat;
	}

	 
	}

      END_FSTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSTORE) - ((char *) &&INLINED_START_DSTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSTORE");
#endif
	break;

      START_DSTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSTORE");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *((jdouble *) (void *) &locals[indx]) =
	    *((jdouble *) (void *) &stack[stack_size]);
	}

	 
	}

      END_DSTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE) - ((char *) &&INLINED_START_ASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE");
#endif
	break;

      START_ASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  locals[indx].reference = stack[--stack_size].reference;
	}

	 
	}

      END_ASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISTORE_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISTORE_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISTORE_0) - ((char *) &&INLINED_START_ISTORE_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISTORE_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISTORE_0");
#endif
	break;

      START_ISTORE_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISTORE_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISTORE_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISTORE_0");

	  /* instruction body */
	  
	locals[0].jint = stack[--stack_size].jint;

	 
	}

      END_ISTORE_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISTORE_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISTORE_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISTORE_1) - ((char *) &&INLINED_START_ISTORE_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISTORE_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISTORE_1");
#endif
	break;

      START_ISTORE_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISTORE_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISTORE_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISTORE_1");

	  /* instruction body */
	  
	locals[1].jint = stack[--stack_size].jint;

	 
	}

      END_ISTORE_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISTORE_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISTORE_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISTORE_2) - ((char *) &&INLINED_START_ISTORE_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISTORE_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISTORE_2");
#endif
	break;

      START_ISTORE_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISTORE_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISTORE_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISTORE_2");

	  /* instruction body */
	  
	locals[2].jint = stack[--stack_size].jint;

	 
	}

      END_ISTORE_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISTORE_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISTORE_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISTORE_3) - ((char *) &&INLINED_START_ISTORE_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISTORE_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISTORE_3");
#endif
	break;

      START_ISTORE_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISTORE_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISTORE_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISTORE_3");

	  /* instruction body */
	  
	locals[3].jint = stack[--stack_size].jint;

	 
	}

      END_ISTORE_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSTORE_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSTORE_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSTORE_0) - ((char *) &&INLINED_START_LSTORE_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSTORE_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSTORE_0");
#endif
	break;

      START_LSTORE_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSTORE_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSTORE_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSTORE_0");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jlong *) (void *) &locals[0]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
	}

      END_LSTORE_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSTORE_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSTORE_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSTORE_1) - ((char *) &&INLINED_START_LSTORE_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSTORE_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSTORE_1");
#endif
	break;

      START_LSTORE_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSTORE_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSTORE_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSTORE_1");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jlong *) (void *) &locals[1]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
	}

      END_LSTORE_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSTORE_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSTORE_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSTORE_2) - ((char *) &&INLINED_START_LSTORE_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSTORE_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSTORE_2");
#endif
	break;

      START_LSTORE_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSTORE_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSTORE_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSTORE_2");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jlong *) (void *) &locals[2]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
	}

      END_LSTORE_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSTORE_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSTORE_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSTORE_3) - ((char *) &&INLINED_START_LSTORE_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSTORE_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSTORE_3");
#endif
	break;

      START_LSTORE_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSTORE_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSTORE_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSTORE_3");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jlong *) (void *) &locals[3]) =
	  *((jlong *) (void *) &stack[stack_size]);

	 
	}

      END_LSTORE_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSTORE_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSTORE_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSTORE_0) - ((char *) &&INLINED_START_FSTORE_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSTORE_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSTORE_0");
#endif
	break;

      START_FSTORE_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSTORE_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSTORE_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSTORE_0");

	  /* instruction body */
	  
	locals[0].jfloat = stack[--stack_size].jfloat;

	 
	}

      END_FSTORE_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSTORE_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSTORE_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSTORE_1) - ((char *) &&INLINED_START_FSTORE_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSTORE_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSTORE_1");
#endif
	break;

      START_FSTORE_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSTORE_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSTORE_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSTORE_1");

	  /* instruction body */
	  
	locals[1].jfloat = stack[--stack_size].jfloat;

	 
	}

      END_FSTORE_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSTORE_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSTORE_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSTORE_2) - ((char *) &&INLINED_START_FSTORE_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSTORE_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSTORE_2");
#endif
	break;

      START_FSTORE_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSTORE_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSTORE_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSTORE_2");

	  /* instruction body */
	  
	locals[2].jfloat = stack[--stack_size].jfloat;

	 
	}

      END_FSTORE_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSTORE_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSTORE_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSTORE_3) - ((char *) &&INLINED_START_FSTORE_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSTORE_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSTORE_3");
#endif
	break;

      START_FSTORE_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSTORE_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSTORE_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSTORE_3");

	  /* instruction body */
	  
	locals[3].jfloat = stack[--stack_size].jfloat;

	 
	}

      END_FSTORE_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSTORE_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSTORE_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSTORE_0) - ((char *) &&INLINED_START_DSTORE_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSTORE_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSTORE_0");
#endif
	break;

      START_DSTORE_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSTORE_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSTORE_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSTORE_0");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jdouble *) (void *) &locals[0]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
	}

      END_DSTORE_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSTORE_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSTORE_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSTORE_1) - ((char *) &&INLINED_START_DSTORE_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSTORE_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSTORE_1");
#endif
	break;

      START_DSTORE_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSTORE_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSTORE_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSTORE_1");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jdouble *) (void *) &locals[1]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
	}

      END_DSTORE_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSTORE_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSTORE_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSTORE_2) - ((char *) &&INLINED_START_DSTORE_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSTORE_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSTORE_2");
#endif
	break;

      START_DSTORE_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSTORE_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSTORE_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSTORE_2");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jdouble *) (void *) &locals[2]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
	}

      END_DSTORE_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSTORE_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSTORE_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSTORE_3) - ((char *) &&INLINED_START_DSTORE_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSTORE_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSTORE_3");
#endif
	break;

      START_DSTORE_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSTORE_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSTORE_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSTORE_3");

	  /* instruction body */
	  
	stack_size -= 2;
	*((jdouble *) (void *) &locals[3]) =
	  *((jdouble *) (void *) &stack[stack_size]);

	 
	}

      END_DSTORE_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_0:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_0) - ((char *) &&INLINED_START_ASTORE_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_0");
#endif
	break;

      START_ASTORE_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_0");

	  /* instruction body */
	  
	locals[0].reference = stack[--stack_size].reference;

	 
	}

      END_ASTORE_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_1) - ((char *) &&INLINED_START_ASTORE_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_1");
#endif
	break;

      START_ASTORE_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_1");

	  /* instruction body */
	  
	locals[1].reference = stack[--stack_size].reference;

	 
	}

      END_ASTORE_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_2) - ((char *) &&INLINED_START_ASTORE_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_2");
#endif
	break;

      START_ASTORE_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_2");

	  /* instruction body */
	  
	locals[2].reference = stack[--stack_size].reference;

	 
	}

      END_ASTORE_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_3:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_3) - ((char *) &&INLINED_START_ASTORE_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_3");
#endif
	break;

      START_ASTORE_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_3");

	  /* instruction body */
	  
	locals[3].reference = stack[--stack_size].reference;

	 
	}

      END_ASTORE_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IASTORE) - ((char *) &&INLINED_START_IASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IASTORE");
#endif
	break;

      START_IASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IASTORE");

	  /* instruction body */
	  
	{
	  jint value = stack[--stack_size].jint;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_int_array_element (array, indx, value);
	}

	 
	}

      END_IASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LASTORE) - ((char *) &&INLINED_START_LASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LASTORE");
#endif
	break;

      START_LASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LASTORE");

	  /* instruction body */
	  
	{
	  jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_long_array_element (array, indx, value);
	}

	 
	}

      END_LASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FASTORE) - ((char *) &&INLINED_START_FASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FASTORE");
#endif
	break;

      START_FASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FASTORE");

	  /* instruction body */
	  
	{
	  jfloat value = stack[--stack_size].jfloat;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_float_array_element (array, indx, value);
	}

	 
	}

      END_FASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DASTORE) - ((char *) &&INLINED_START_DASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DASTORE");
#endif
	break;

      START_DASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DASTORE");

	  /* instruction body */
	  
	{
	  jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_double_array_element (array, indx, value);
	}

	 
	}

      END_DASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
CASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_CASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_CASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_CASTORE) - ((char *) &&INLINED_START_CASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_CASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "CASTORE");
#endif
	break;

      START_CASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p CASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_CASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "CASTORE");

	  /* instruction body */
	  
	{
	  jchar value = stack[--stack_size].jint;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_char_array_element (array, indx, value);
	}

	 
	}

      END_CASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
SASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_SASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_SASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_SASTORE) - ((char *) &&INLINED_START_SASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_SASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "SASTORE");
#endif
	break;

      START_SASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p SASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_SASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "SASTORE");

	  /* instruction body */
	  
	{
	  jshort value = stack[--stack_size].jint;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_short_array_element (array, indx, value);
	}

	 
	}

      END_SASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
BASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_BASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_BASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_BASTORE) - ((char *) &&INLINED_START_BASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_BASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "BASTORE");
#endif
	break;

      START_BASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p BASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_BASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "BASTORE");

	  /* instruction body */
	  
	{
	  jint value = stack[--stack_size].jint;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint base_type;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  base_type = _svmf_cast_array (array->vtable->type)->base_type;

	  switch (base_type)
	    {
	    case SVM_TYPE_BYTE:
	      {
		_svmf_set_byte_array_element (array, indx, value);
	      }
	      break;

	    case SVM_TYPE_BOOLEAN:
	      {
		_svmf_set_boolean_array_element (array, indx, value);
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}

	 
	}

      END_BASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
AASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AASTORE:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_AASTORE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_AASTORE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_AASTORE) - ((char *) &&INLINED_START_AASTORE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_AASTORE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "AASTORE");
#endif
	break;

      START_AASTORE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p AASTORE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_AASTORE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "AASTORE");

	  /* instruction body */
	  
	{
	  _svmt_object_instance *value = stack[--stack_size].reference;
	  jint indx = stack[--stack_size].jint;
	  _svmt_array_instance *array =
	    (_svmt_array_instance *) stack[--stack_size].reference;
	  jint size;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  
	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  if (_svmf_set_reference_array_element_no_exception
	      (env, array, indx, value) != JNI_OK)
	    {			/* TODO: how to get into here using BTF ?! */
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arraystoreexception_handler);
	    }
	}

	 
	}

      END_AASTORE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
POP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_POP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_POP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_POP) - ((char *) &&INLINED_START_POP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_POP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "POP");
#endif
	break;

      START_POP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p POP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_POP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "POP");

	  /* instruction body */
	  
	stack_size--;

	 
	}

      END_POP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
POP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_POP2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_POP2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_POP2) - ((char *) &&INLINED_START_POP2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_POP2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "POP2");
#endif
	break;

      START_POP2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p POP2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_POP2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "POP2");

	  /* instruction body */
	  
	stack_size -= 2;

	 
	}

      END_POP2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP) - ((char *) &&INLINED_START_DUP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP");
#endif
	break;

      START_DUP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP");

	  /* instruction body */
	  
	stack[stack_size] = stack[stack_size - 1];
	stack_size++;

	 
	}

      END_DUP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP_X1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP_X1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP_X1) - ((char *) &&INLINED_START_DUP_X1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP_X1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP_X1");
#endif
	break;

      START_DUP_X1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP_X1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP_X1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP_X1");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	 
	}

      END_DUP_X1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP_X2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP_X2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP_X2) - ((char *) &&INLINED_START_DUP_X2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP_X2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP_X2");
#endif
	break;

      START_DUP_X2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP_X2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP_X2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP_X2");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 3] = value1;
	  stack[stack_size - 2] = value3;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	 
	}

      END_DUP_X2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP2) - ((char *) &&INLINED_START_DUP2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP2");
#endif
	break;

      START_DUP2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP2");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	 
	}

      END_DUP2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP2_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X1:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP2_X1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP2_X1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP2_X1) - ((char *) &&INLINED_START_DUP2_X1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP2_X1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP2_X1");
#endif
	break;

      START_DUP2_X1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP2_X1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP2_X1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP2_X1");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 3] = value2;
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value3;
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	 
	}

      END_DUP2_X1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DUP2_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X2:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DUP2_X2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DUP2_X2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DUP2_X2) - ((char *) &&INLINED_START_DUP2_X2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DUP2_X2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DUP2_X2");
#endif
	break;

      START_DUP2_X2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DUP2_X2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DUP2_X2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DUP2_X2");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value4 = stack[stack_size - 4];
	  _svmt_stack_value value3 = stack[stack_size - 3];
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 4] = value2;
	  stack[stack_size - 3] = value1;
	  stack[stack_size - 2] = value4;
	  stack[stack_size - 1] = value3;
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	 
	}

      END_DUP2_X2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
SWAP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SWAP:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_SWAP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_SWAP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_SWAP) - ((char *) &&INLINED_START_SWAP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_SWAP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "SWAP");
#endif
	break;

      START_SWAP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p SWAP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_SWAP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "SWAP");

	  /* instruction body */
	  
	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	}

	 
	}

      END_SWAP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IADD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IADD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IADD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IADD) - ((char *) &&INLINED_START_IADD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IADD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IADD");
#endif
	break;

      START_IADD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IADD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IADD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IADD");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 + value2;
	}

	 
	}

      END_IADD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LADD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LADD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LADD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LADD) - ((char *) &&INLINED_START_LADD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LADD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LADD");
#endif
	break;

      START_LADD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LADD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LADD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LADD");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 + value2;
	}

	 
	}

      END_LADD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FADD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FADD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FADD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FADD) - ((char *) &&INLINED_START_FADD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FADD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FADD");
#endif
	break;

      START_FADD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FADD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FADD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FADD");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 + value2;
	}

	 
	}

      END_FADD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DADD:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DADD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DADD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DADD) - ((char *) &&INLINED_START_DADD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DADD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DADD");
#endif
	break;

      START_DADD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DADD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DADD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DADD");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 + value2;
	}

	 
	}

      END_DADD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISUB:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISUB;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISUB;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISUB) - ((char *) &&INLINED_START_ISUB);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISUB;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISUB");
#endif
	break;

      START_ISUB:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISUB]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISUB:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISUB");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 - value2;
	}

	 
	}

      END_ISUB:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSUB:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSUB;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSUB;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSUB) - ((char *) &&INLINED_START_LSUB);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSUB;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSUB");
#endif
	break;

      START_LSUB:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSUB]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSUB:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSUB");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 - value2;
	}

	 
	}

      END_LSUB:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSUB:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FSUB;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FSUB;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FSUB) - ((char *) &&INLINED_START_FSUB);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FSUB;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FSUB");
#endif
	break;

      START_FSUB:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FSUB]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FSUB:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FSUB");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 - value2;
	}

	 
	}

      END_FSUB:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSUB:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DSUB;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DSUB;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DSUB) - ((char *) &&INLINED_START_DSUB);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DSUB;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DSUB");
#endif
	break;

      START_DSUB:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DSUB]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DSUB:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DSUB");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 - value2;
	}

	 
	}

      END_DSUB:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IMUL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IMUL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IMUL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IMUL) - ((char *) &&INLINED_START_IMUL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IMUL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IMUL");
#endif
	break;

      START_IMUL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IMUL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IMUL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IMUL");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 * value2;
	}

	 
	}

      END_IMUL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LMUL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LMUL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LMUL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LMUL) - ((char *) &&INLINED_START_LMUL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LMUL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LMUL");
#endif
	break;

      START_LMUL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LMUL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LMUL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LMUL");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 * value2;
	}

	 
	}

      END_LMUL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FMUL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FMUL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FMUL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FMUL) - ((char *) &&INLINED_START_FMUL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FMUL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FMUL");
#endif
	break;

      START_FMUL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FMUL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FMUL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FMUL");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 * value2;
	}

	 
	}

      END_FMUL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DMUL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DMUL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DMUL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DMUL) - ((char *) &&INLINED_START_DMUL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DMUL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DMUL");
#endif
	break;

      START_DMUL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DMUL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DMUL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DMUL");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 * value2;
	}

	 
	}

      END_DMUL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FDIV:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FDIV;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FDIV;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FDIV) - ((char *) &&INLINED_START_FDIV);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FDIV;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FDIV");
#endif
	break;

      START_FDIV:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FDIV]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FDIV:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FDIV");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = value1 / value2;
	}

	 
	}

      END_FDIV:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DDIV:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DDIV;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DDIV;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DDIV) - ((char *) &&INLINED_START_DDIV);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DDIV;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DDIV");
#endif
	break;

      START_DDIV:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DDIV]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DDIV:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DDIV");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) = value1 / value2;
	}

	 
	}

      END_DDIV:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INEG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INEG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INEG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INEG) - ((char *) &&INLINED_START_INEG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INEG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INEG");
#endif
	break;

      START_INEG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INEG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INEG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INEG");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = - value;
	    }
	}

	 
	}

      END_INEG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LNEG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LNEG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LNEG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LNEG) - ((char *) &&INLINED_START_LNEG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LNEG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LNEG");
#endif
	break;

      START_LNEG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LNEG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LNEG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LNEG");

	  /* instruction body */
	  
	{
	  jlong value = *((jlong *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = - value;
	    }
	}

	 
	}

      END_LNEG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FNEG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FNEG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FNEG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FNEG) - ((char *) &&INLINED_START_FNEG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FNEG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FNEG");
#endif
	break;

      START_FNEG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FNEG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FNEG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FNEG");

	  /* instruction body */
	  
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat = - value;
	    }
	}

	 
	}

      END_FNEG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DNEG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DNEG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DNEG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DNEG) - ((char *) &&INLINED_START_DNEG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DNEG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DNEG");
#endif
	break;

      START_DNEG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DNEG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DNEG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DNEG");

	  /* instruction body */
	  
	{
	  jdouble value = *((jdouble *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = - value;
	    }
	}

	 
	}

      END_DNEG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IAND:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IAND;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IAND;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IAND) - ((char *) &&INLINED_START_IAND);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IAND;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IAND");
#endif
	break;

      START_IAND:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IAND]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IAND:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IAND");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 & value2;
	}

	 
	}

      END_IAND:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LAND:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LAND;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LAND;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LAND) - ((char *) &&INLINED_START_LAND);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LAND;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LAND");
#endif
	break;

      START_LAND:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LAND]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LAND:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LAND");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 & value2;
	}

	 
	}

      END_LAND:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IOR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IOR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IOR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IOR) - ((char *) &&INLINED_START_IOR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IOR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IOR");
#endif
	break;

      START_IOR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IOR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IOR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IOR");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 | value2;
	}

	 
	}

      END_IOR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LOR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LOR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LOR) - ((char *) &&INLINED_START_LOR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LOR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LOR");
#endif
	break;

      START_LOR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LOR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LOR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LOR");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 | value2;
	}

	 
	}

      END_LOR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IXOR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IXOR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IXOR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IXOR) - ((char *) &&INLINED_START_IXOR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IXOR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IXOR");
#endif
	break;

      START_IXOR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IXOR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IXOR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IXOR");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 ^ value2;
	}

	 
	}

      END_IXOR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LXOR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LXOR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LXOR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LXOR) - ((char *) &&INLINED_START_LXOR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LXOR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LXOR");
#endif
	break;

      START_LXOR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LXOR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LXOR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LXOR");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 ^ value2;
	}

	 
	}

      END_LXOR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2L:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2L;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2L;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2L) - ((char *) &&INLINED_START_I2L);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2L;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2L");
#endif
	break;

      START_I2L:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2L]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2L:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2L");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
	}

      END_I2L:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2F:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2F;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2F;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2F) - ((char *) &&INLINED_START_I2F);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2F;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2F");
#endif
	break;

      START_I2F:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2F]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2F:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2F");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
	}

      END_I2F:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2D:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2D;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2D;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2D) - ((char *) &&INLINED_START_I2D);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2D;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2D");
#endif
	break;

      START_I2D:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2D]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2D:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2D");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
	}

      END_I2D:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
L2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2I:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_L2I;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_L2I;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_L2I) - ((char *) &&INLINED_START_L2I);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_L2I;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "L2I");
#endif
	break;

      START_L2I:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p L2I]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_L2I:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "L2I");

	  /* instruction body */
	  
	{
	  jlong value = *((jlong *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
	}

      END_L2I:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
L2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2F:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_L2F;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_L2F;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_L2F) - ((char *) &&INLINED_START_L2F);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_L2F;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "L2F");
#endif
	break;

      START_L2F:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p L2F]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_L2F:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "L2F");

	  /* instruction body */
	  
	{
	  jlong value = *((jlong *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
	}

      END_L2F:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
L2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2D:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_L2D;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_L2D;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_L2D) - ((char *) &&INLINED_START_L2D);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_L2D;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "L2D");
#endif
	break;

      START_L2D:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p L2D]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_L2D:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "L2D");

	  /* instruction body */
	  
	{
	  jlong value = *((jlong *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size - 2]) =  value;
	    }
	}

	 
	}

      END_L2D:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
F2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2I:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_F2I;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_F2I;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_F2I) - ((char *) &&INLINED_START_F2I);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_F2I;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "F2I");
#endif
	break;

      START_F2I:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p F2I]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_F2I:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "F2I");

	  /* instruction body */
	  
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM_JINT_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM_JINT_MAX)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MAX;
	    }
	  else if (value <= SVM_JINT_MIN)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
	}

      END_F2I:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
F2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2L:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_F2L;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_F2L;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_F2L) - ((char *) &&INLINED_START_F2L);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_F2L;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "F2L");
#endif
	break;

      START_F2L:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p F2L]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_F2L:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "F2L");

	  /* instruction body */
	  
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM_JLONG_MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM_JLONG_MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM_JLONG_MAX;
	    }
	  else if (value <= SVM_JLONG_MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) = SVM_JLONG_MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
	}

      END_F2L:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
F2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2D:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_F2D;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_F2D;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_F2D) - ((char *) &&INLINED_START_F2D);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_F2D;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "F2D");
#endif
	break;

      START_F2D:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p F2D]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_F2D:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "F2D");

	  /* instruction body */
	  
	{
	  jfloat value = stack[stack_size - 1].jfloat;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) = SVM__MIN;
	    }
	  else
#endif
	    {
	      *((jdouble *) (void *) &stack[stack_size++ - 1]) =  value;
	    }
	}

	 
	}

      END_F2D:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
D2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2I:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_D2I;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_D2I;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_D2I) - ((char *) &&INLINED_START_D2I);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_D2I;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "D2I");
#endif
	break;

      START_D2I:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p D2I]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_D2I:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "D2I");

	  /* instruction body */
	  
	{
	  jdouble value = *((jdouble *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM_JINT_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM_JINT_MAX)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MAX;
	    }
	  else if (value <= SVM_JINT_MIN)
	    {
	      stack[stack_size - 1].jint = SVM_JINT_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint =  value;
	    }
	}

	 
	}

      END_D2I:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
D2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2L:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_D2L;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_D2L;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_D2L) - ((char *) &&INLINED_START_D2L);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_D2L;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "D2L");
#endif
	break;

      START_D2L:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p D2L]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_D2L:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "D2L");

	  /* instruction body */
	  
	{
	  jdouble value = *((jdouble *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM_JLONG_MAX
	  if (value != value)
	    {			/* NaN */
	      *((jlong *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM_JLONG_MAX)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM_JLONG_MAX;
	    }
	  else if (value <= SVM_JLONG_MIN)
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) = SVM_JLONG_MIN;
	    }
	  else
#endif
	    {
	      *((jlong *) (void *) &stack[stack_size - 2]) =  value;
	    }
	}

	 
	}

      END_D2L:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
D2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2F:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_D2F;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_D2F;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_D2F) - ((char *) &&INLINED_START_D2F);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_D2F;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "D2F");
#endif
	break;

      START_D2F:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p D2F]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_D2F:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "D2F");

	  /* instruction body */
	  
	{
	  jdouble value = *((jdouble *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jfloat = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jfloat = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jfloat = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jfloat =  value;
	    }
	}

	 
	}

      END_D2F:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2B
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2B:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2B;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2B;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2B) - ((char *) &&INLINED_START_I2B);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2B;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2B");
#endif
	break;

      START_I2B:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2B]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2B:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2B");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jbyte) value;
	    }
	}

	 
	}

      END_I2B:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2C
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2C:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2C;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2C;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2C) - ((char *) &&INLINED_START_I2C);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2C;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2C");
#endif
	break;

      START_I2C:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2C]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2C:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2C");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jchar) value;
	    }
	}

	 
	}

      END_I2C:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
I2S
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2S:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_I2S;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_I2S;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_I2S) - ((char *) &&INLINED_START_I2S);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_I2S;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "I2S");
#endif
	break;

      START_I2S:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p I2S]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_I2S:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "I2S");

	  /* instruction body */
	  
	{
	  jint value = stack[stack_size - 1].jint;
/* SVM__MAX is never defined. */
#ifdef SVM__MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].jint = 0;
	    }
	  else if (value >= SVM__MAX)
	    {
	      stack[stack_size - 1].jint = SVM__MAX;
	    }
	  else if (value <= SVM__MIN)
	    {
	      stack[stack_size - 1].jint = SVM__MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = (jshort) value;
	    }
	}

	 
	}

      END_I2S:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IDIV:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IDIV;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IDIV;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IDIV) - ((char *) &&INLINED_START_IDIV);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IDIV;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IDIV");
#endif
	break;

      START_IDIV:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IDIV]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IDIV:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IDIV");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;


#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__))

#ifndef NDEBUG

	  if (value2 == 0)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }
#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */


#if defined(__i386__) || defined(__powerpc__) || defined(__s390__)
	  /*
	   * i386 arch is broken and will cause a *FLOAT* point error signal on
	   * division of MIN_INT / -1 - so we have to fix it by hand
	   * 
	   * On s390 this also seem to cause an unexpected signal.
	   * 
	   * On PowerPC no exception is raised but the result is undefined.
	   *
	   */
	  if ((value1 == (jint) 0x80000000) && (value2 == -1))
	    {
	      stack[stack_size - 1].jint = value1;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = value1 / value2;
	    }
	}

	 
	}

      END_IDIV:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDIV:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LDIV;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LDIV;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LDIV) - ((char *) &&INLINED_START_LDIV);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LDIV;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LDIV");
#endif
	break;

      START_LDIV:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LDIV]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LDIV:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LDIV");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__) || defined(__s390__))

#ifndef NDEBUG

	  if (value2 == 0L)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0L)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 / value2;
	}

	 
	}

      END_LDIV:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IREM:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IREM;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IREM;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IREM) - ((char *) &&INLINED_START_IREM);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IREM;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IREM");
#endif
	break;

      START_IREM:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IREM]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IREM:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IREM");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;


#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__))

#ifndef NDEBUG

	  if (value2 == 0)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

#if defined(__i386__) || defined(__powerpc__) || defined(__s390__)
	  /*
	   * i386 arch is broken and will cause a *FLOAT* point error signal on
	   * modulo of MIN_INT / -1 - so we have to fix it by hand
	   * 
	   * We assumed problem exists on s390 and PowerPC just as for IDIV
	   * 
	   */
	  if ((value1 == (jint) 0x80000000) && (value2 == -1))
	    {
	      stack[stack_size - 1].jint = 0;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].jint = value1 % value2;
	    }
	}

	 
	}

      END_IREM:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LREM:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LREM;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LREM;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LREM) - ((char *) &&INLINED_START_LREM);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LREM;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LREM");
#endif
	break;

      START_LREM:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LREM]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LREM:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LREM");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[(stack_size -= 2)]);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && \
  !(defined(__hppa__) || defined(__ia64__) || defined(__powerpc__) || defined(__s390__))

#ifndef NDEBUG

	  if (value2 == 0L)
	    {
	      env->sigfpe_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (value2 == 0L)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arithmeticexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  *((jlong *) (void *) &stack[stack_size - 2]) = value1 % value2;
	}

	 
	}

      END_LREM:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FREM:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FREM;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FREM;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FREM) - ((char *) &&INLINED_START_FREM);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FREM;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FREM");
#endif
	break;

      START_FREM:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FREM]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FREM:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FREM");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = _svmm_fmod (value1, value2);
	}

	 
	}

      END_FREM:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DREM:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DREM;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DREM;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DREM) - ((char *) &&INLINED_START_DREM);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DREM;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DREM");
#endif
	break;

      START_DREM:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DREM]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DREM:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DREM");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmm_fmod (value1, value2);
	}

	 
	}

      END_DREM:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISHL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISHL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISHL) - ((char *) &&INLINED_START_ISHL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISHL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISHL");
#endif
	break;

      START_ISHL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISHL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISHL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISHL");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 << (value2 & 0x1f);
	}

	 
	}

      END_ISHL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSHL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSHL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSHL) - ((char *) &&INLINED_START_LSHL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSHL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSHL");
#endif
	break;

      START_LSHL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSHL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSHL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSHL");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 << (value2 & 0x3f);
	}

	 
	}

      END_LSHL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ISHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ISHR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ISHR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ISHR) - ((char *) &&INLINED_START_ISHR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ISHR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ISHR");
#endif
	break;

      START_ISHR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ISHR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ISHR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ISHR");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
#if defined(SVM_SIGNED_SHR)
	  stack[stack_size - 1].jint = value1 >> (value2 & 0x1f);
#elif defined(SVM_UNSIGNED_SHR)
	  jint sign = value1 >> 31;
	  /* unsigned shift */
	  jint result = value1 >> (value2 & 0x1f);
	  /* add leading 1s if necessary */
	  result |= (-1 * sign) << (0x20 - (value2 & 0x1f));
	  stack[stack_size - 1].jint = result;
#endif
	}

	 
	}

      END_ISHR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LSHR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LSHR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LSHR) - ((char *) &&INLINED_START_LSHR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LSHR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LSHR");
#endif
	break;

      START_LSHR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LSHR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LSHR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LSHR");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;

#if defined(SVM_SIGNED_SHR)
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 >> (value2 & 0x3f);
#elif defined(SVM_UNSIGNED_SHR)
	  jlong sign = value1 >> 63;
	  /* unsigned shift */
	  jlong result = value1 >> (value2 & 0x3f);
	  /* add leading 1s if necessary */
	  result |= (-1L * sign) << (0x40 - (value2 & 0x3f));
	  *((jlong *) (void *) &stack[stack_size - 2]) = result;
#endif

	}

	 
	}

      END_LSHR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IUSHR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IUSHR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IUSHR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IUSHR) - ((char *) &&INLINED_START_IUSHR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IUSHR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IUSHR");
#endif
	break;

      START_IUSHR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IUSHR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IUSHR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IUSHR");

	  /* instruction body */
	  
	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint =
	    ((_svmt_u32) value1) >> (value2 & 0x1f);
	}

	 
	}

      END_IUSHR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LUSHR:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LUSHR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LUSHR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LUSHR) - ((char *) &&INLINED_START_LUSHR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LUSHR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LUSHR");
#endif
	break;

      START_LUSHR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LUSHR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LUSHR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LUSHR");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    ((_svmt_u64) value1) >> (value2 & 0x3f);
	}

	 
	}

      END_LUSHR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LCMP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCMP:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LCMP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LCMP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LCMP) - ((char *) &&INLINED_START_LCMP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LCMP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LCMP");
#endif
	break;

      START_LCMP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LCMP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LCMP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LCMP");

	  /* instruction body */
	  
	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[stack_size - 2]);
	  stack[(stack_size -= 3) - 1].jint =
	    (value1 > value2) - (value1 < value2);
	}

	 
	}

      END_LCMP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FCMPL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FCMPL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FCMPL) - ((char *) &&INLINED_START_FCMPL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FCMPL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FCMPL");
#endif
	break;

      START_FCMPL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FCMPL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FCMPL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FCMPL");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[stack_size - 1].jint = -1;
	    }
	  else
	    {
	      stack[stack_size - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	 
	}

      END_FCMPL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FCMPG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FCMPG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FCMPG) - ((char *) &&INLINED_START_FCMPG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FCMPG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FCMPG");
#endif
	break;

      START_FCMPG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FCMPG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FCMPG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FCMPG");

	  /* instruction body */
	  
	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[stack_size - 1].jint = 1;
	    }
	  else
	    {
	      stack[stack_size - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	 
	}

      END_FCMPG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPL:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DCMPL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DCMPL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DCMPL) - ((char *) &&INLINED_START_DCMPL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DCMPL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DCMPL");
#endif
	break;

      START_DCMPL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DCMPL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DCMPL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DCMPL");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[stack_size - 2]);

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[(stack_size -= 3) - 1].jint = -1;
	    }
	  else
	    {
	      stack[(stack_size -= 3) - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	 
	}

      END_DCMPL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPG:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DCMPG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DCMPG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DCMPG) - ((char *) &&INLINED_START_DCMPG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DCMPG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DCMPG");
#endif
	break;

      START_DCMPG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DCMPG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DCMPG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DCMPG");

	  /* instruction body */
	  
	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[stack_size - 2]);

	  if (value1 != value1 || value2 != value2)
	    {
	      /* NaN */
	      stack[(stack_size -= 3) - 1].jint = 1;
	    }
	  else
	    {
	      stack[(stack_size -= 3) - 1].jint =
		(value1 > value2) - (value1 < value2);
	    }
	}

	 
	}

      END_DCMPG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IINC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IINC:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IINC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IINC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IINC) - ((char *) &&INLINED_START_IINC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IINC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IINC");
#endif
	break;

      START_IINC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IINC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IINC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IINC");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  jint constant = (pc++)->jint;
	  locals[indx].jint +=constant;
	}

	 
	}

      END_IINC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFEQ;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFEQ;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFEQ) - ((char *) &&INLINED_START_IFEQ);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFEQ;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFEQ");
#endif
	break;

      START_IFEQ:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFEQ]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFEQ:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFEQ");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value == 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFEQ:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNE) - ((char *) &&INLINED_START_IFNE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNE");
#endif
	break;

      START_IFNE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value != 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFLT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFLT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFLT) - ((char *) &&INLINED_START_IFLT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFLT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFLT");
#endif
	break;

      START_IFLT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFLT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFLT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFLT");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value < 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFLT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFLE) - ((char *) &&INLINED_START_IFLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFLE");
#endif
	break;

      START_IFLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFLE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value <= 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFGT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFGT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFGT) - ((char *) &&INLINED_START_IFGT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFGT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFGT");
#endif
	break;

      START_IFGT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFGT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFGT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFGT");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value > 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFGT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFGE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFGE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFGE) - ((char *) &&INLINED_START_IFGE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFGE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFGE");
#endif
	break;

      START_IFGE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFGE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFGE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFGE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value >= 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFGE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPEQ;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPEQ;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPEQ) - ((char *) &&INLINED_START_IF_ICMPEQ);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPEQ;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPEQ");
#endif
	break;

      START_IF_ICMPEQ:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPEQ]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPEQ:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPEQ");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 == value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPEQ:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPNE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPNE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPNE) - ((char *) &&INLINED_START_IF_ICMPNE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPNE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPNE");
#endif
	break;

      START_IF_ICMPNE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPNE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPNE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPNE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 != value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPNE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPLT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPLT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPLT) - ((char *) &&INLINED_START_IF_ICMPLT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPLT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLT");
#endif
	break;

      START_IF_ICMPLT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPLT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPLT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPLT");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 < value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPLT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPLE) - ((char *) &&INLINED_START_IF_ICMPLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLE");
#endif
	break;

      START_IF_ICMPLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPLE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 <= value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPGT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPGT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPGT) - ((char *) &&INLINED_START_IF_ICMPGT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPGT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGT");
#endif
	break;

      START_IF_ICMPGT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPGT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPGT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPGT");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 > value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPGT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPGE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPGE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPGE) - ((char *) &&INLINED_START_IF_ICMPGE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPGE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGE");
#endif
	break;

      START_IF_ICMPGE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPGE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPGE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPGE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 >= value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPGE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ACMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ACMPEQ;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ACMPEQ;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ACMPEQ) - ((char *) &&INLINED_START_IF_ACMPEQ);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ACMPEQ;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ACMPEQ");
#endif
	break;

      START_IF_ACMPEQ:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ACMPEQ]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ACMPEQ:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ACMPEQ");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 == ref2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ACMPEQ:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ACMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ACMPNE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ACMPNE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ACMPNE) - ((char *) &&INLINED_START_IF_ACMPNE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ACMPNE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ACMPNE");
#endif
	break;

      START_IF_ACMPNE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ACMPNE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ACMPNE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ACMPNE");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 != ref2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ACMPNE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFEQ_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFEQ_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFEQ_CHECK) - ((char *) &&INLINED_START_IFEQ_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFEQ_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFEQ_CHECK");
#endif
	break;

      START_IFEQ_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFEQ_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFEQ_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFEQ_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value == 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFEQ_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNE_CHECK) - ((char *) &&INLINED_START_IFNE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNE_CHECK");
#endif
	break;

      START_IFNE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value != 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFLT_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFLT_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFLT_CHECK) - ((char *) &&INLINED_START_IFLT_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFLT_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFLT_CHECK");
#endif
	break;

      START_IFLT_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFLT_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFLT_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFLT_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value < 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFLT_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFLE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFLE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFLE_CHECK) - ((char *) &&INLINED_START_IFLE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFLE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFLE_CHECK");
#endif
	break;

      START_IFLE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFLE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFLE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFLE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value <= 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFLE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFGT_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFGT_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFGT_CHECK) - ((char *) &&INLINED_START_IFGT_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFGT_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFGT_CHECK");
#endif
	break;

      START_IFGT_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFGT_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFGT_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFGT_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value > 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFGT_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFGE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFGE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFGE_CHECK) - ((char *) &&INLINED_START_IFGE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFGE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFGE_CHECK");
#endif
	break;

      START_IFGE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFGE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFGE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFGE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value >= 0)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFGE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPEQ_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPEQ_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPEQ_CHECK) - ((char *) &&INLINED_START_IF_ICMPEQ_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPEQ_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPEQ_CHECK");
#endif
	break;

      START_IF_ICMPEQ_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPEQ_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPEQ_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPEQ_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 == value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPEQ_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPNE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPNE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPNE_CHECK) - ((char *) &&INLINED_START_IF_ICMPNE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPNE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPNE_CHECK");
#endif
	break;

      START_IF_ICMPNE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPNE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPNE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPNE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 != value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPNE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPLT_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPLT_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPLT_CHECK) - ((char *) &&INLINED_START_IF_ICMPLT_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPLT_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLT_CHECK");
#endif
	break;

      START_IF_ICMPLT_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPLT_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPLT_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPLT_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 < value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPLT_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPLE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPLE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPLE_CHECK) - ((char *) &&INLINED_START_IF_ICMPLE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPLE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLE_CHECK");
#endif
	break;

      START_IF_ICMPLE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPLE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPLE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPLE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 <= value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPLE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPGT_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPGT_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPGT_CHECK) - ((char *) &&INLINED_START_IF_ICMPGT_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPGT_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGT_CHECK");
#endif
	break;

      START_IF_ICMPGT_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPGT_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPGT_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPGT_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 > value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPGT_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ICMPGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ICMPGE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ICMPGE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ICMPGE_CHECK) - ((char *) &&INLINED_START_IF_ICMPGE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ICMPGE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGE_CHECK");
#endif
	break;

      START_IF_ICMPGE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ICMPGE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ICMPGE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ICMPGE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 >= value2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ICMPGE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ACMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ACMPEQ_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ACMPEQ_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ACMPEQ_CHECK) - ((char *) &&INLINED_START_IF_ACMPEQ_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ACMPEQ_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ACMPEQ_CHECK");
#endif
	break;

      START_IF_ACMPEQ_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ACMPEQ_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ACMPEQ_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ACMPEQ_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 == ref2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ACMPEQ_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IF_ACMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IF_ACMPNE_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IF_ACMPNE_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IF_ACMPNE_CHECK) - ((char *) &&INLINED_START_IF_ACMPNE_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IF_ACMPNE_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IF_ACMPNE_CHECK");
#endif
	break;

      START_IF_ACMPNE_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IF_ACMPNE_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IF_ACMPNE_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IF_ACMPNE_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 != ref2)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IF_ACMPNE_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GOTO
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GOTO;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GOTO;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GOTO) - ((char *) &&INLINED_START_GOTO);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GOTO;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GOTO");
#endif
	break;

      START_GOTO:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GOTO]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GOTO:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GOTO");

	  /* instruction body */
	  
	pc = pc->addr;

	 
	}

      END_GOTO:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GOTO_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GOTO_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GOTO_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GOTO_CHECK) - ((char *) &&INLINED_START_GOTO_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GOTO_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GOTO_CHECK");
#endif
	break;

      START_GOTO_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GOTO_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GOTO_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GOTO_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	pc = pc->addr;

	 
	}

      END_GOTO_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
JSR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_JSR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_JSR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_JSR) - ((char *) &&INLINED_START_JSR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_JSR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "JSR");
#endif
	break;

      START_JSR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p JSR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_JSR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "JSR");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	 
	}

      END_JSR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
JSR_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_JSR_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_JSR_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_JSR_CHECK) - ((char *) &&INLINED_START_JSR_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_JSR_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "JSR_CHECK");
#endif
	break;

      START_JSR_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p JSR_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_JSR_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "JSR_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	 
	}

      END_JSR_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RET:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_RET;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_RET;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_RET) - ((char *) &&INLINED_START_RET);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_RET;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "RET");
#endif
	break;

      START_RET:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p RET]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_RET:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "RET");

	  /* instruction body */
	  
	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;
	}

	 
	}

      END_RET:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
TABLESWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_TABLESWITCH;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_TABLESWITCH;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_TABLESWITCH) - ((char *) &&INLINED_START_TABLESWITCH);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_TABLESWITCH;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "TABLESWITCH");
#endif
	break;

      START_TABLESWITCH:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p TABLESWITCH]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_TABLESWITCH:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "TABLESWITCH");

	  /* instruction body */
	  
	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint indx = stack[--stack_size].jint;

	  if (indx < low || indx > high)
	    {
	      pc = default_dest;
	    }
	  else
	    {
	      pc = table[indx - low].addr;
	    }
	}

	 
	}

      END_TABLESWITCH:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_TABLESWITCH_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_TABLESWITCH_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_TABLESWITCH_CHECK) - ((char *) &&INLINED_START_TABLESWITCH_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_TABLESWITCH_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "TABLESWITCH_CHECK");
#endif
	break;

      START_TABLESWITCH_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p TABLESWITCH_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_TABLESWITCH_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "TABLESWITCH_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint low = (pc++)->jint;
	  jint high = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint indx = stack[--stack_size].jint;

	  if (indx < low || indx > high)
	    {
	      pc = default_dest;
	    }
	  else
	    {
	      pc = table[indx - low].addr;
	    }
	}

	 
	}

      END_TABLESWITCH_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LOOKUPSWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LOOKUPSWITCH;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LOOKUPSWITCH;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LOOKUPSWITCH) - ((char *) &&INLINED_START_LOOKUPSWITCH);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LOOKUPSWITCH;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LOOKUPSWITCH");
#endif
	break;

      START_LOOKUPSWITCH:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LOOKUPSWITCH]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LOOKUPSWITCH:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LOOKUPSWITCH");

	  /* instruction body */
	  
	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = table[middle * 2].jint;

	      if (key == match)
		{
		  pc = table[middle * 2 + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      pc = default_dest;
	    }
	}

	 
	}

      END_LOOKUPSWITCH:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LOOKUPSWITCH_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LOOKUPSWITCH_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LOOKUPSWITCH_CHECK) - ((char *) &&INLINED_START_LOOKUPSWITCH_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LOOKUPSWITCH_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LOOKUPSWITCH_CHECK");
#endif
	break;

      START_LOOKUPSWITCH_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LOOKUPSWITCH_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LOOKUPSWITCH_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LOOKUPSWITCH_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *default_dest = (pc++)->addr;
	  jint npairs = (pc++)->jint;
	  _svmt_code *table = pc;
	  jint key = stack[--stack_size].jint;

	  jint low = 0;
	  jint high = npairs - 1;

	  while (high >= low)
	    {
	      jint middle = (low + high) / 2;
	      jint match = table[middle * 2].jint;

	      if (key == match)
		{
		  pc = table[middle * 2 + 1].addr;
		  break;
		}

	      if (key > match)
		{
		  low = middle + 1;
		}
	      else
		{
		  high = middle - 1;
		}
	    }

	  if (high < low)
	    {
	      pc = default_dest;
	    }
	}

	 
	}

      END_LOOKUPSWITCH_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IRETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IRETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IRETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IRETURN) - ((char *) &&INLINED_START_IRETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IRETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IRETURN");
#endif
	break;

      START_IRETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IRETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IRETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IRETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  locals[0].jint = stack[stack_size - 1].jint;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_IRETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LRETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LRETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LRETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LRETURN) - ((char *) &&INLINED_START_LRETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LRETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LRETURN");
#endif
	break;

      START_LRETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LRETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LRETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LRETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  *((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]);

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 2;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_LRETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
FRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FRETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_FRETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_FRETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_FRETURN) - ((char *) &&INLINED_START_FRETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_FRETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "FRETURN");
#endif
	break;

      START_FRETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p FRETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_FRETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "FRETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  locals[0].jfloat = stack[stack_size - 1].jfloat;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_FRETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
DRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DRETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_DRETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_DRETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_DRETURN) - ((char *) &&INLINED_START_DRETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_DRETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "DRETURN");
#endif
	break;

      START_DRETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p DRETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_DRETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "DRETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  *((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]);

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 2;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_DRETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ARETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ARETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ARETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ARETURN) - ((char *) &&INLINED_START_ARETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ARETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ARETURN");
#endif
	break;

      START_ARETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ARETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ARETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ARETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  locals[0].reference = stack[stack_size - 1].reference;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 1;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_ARETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
RETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RETURN:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_RETURN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_RETURN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_RETURN) - ((char *) &&INLINED_START_RETURN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_RETURN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "RETURN");
#endif
	break;

      START_RETURN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p RETURN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_RETURN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "RETURN");

	  /* instruction body */
	  
	/* structured locking */
	if (env->stack.current_frame->lock_count != 0
	    && env->vm->enforce_structured_locking)
	  {
	    /* pop stack frame */
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    env->stack.current_frame = (_svmt_stack_frame *) (void *)
	      (((char *) frame) - frame->previous_offset);

	    _svmf_error_IllegalMonitorStateException (env);
	    _svmm_goto_label (exception_handler);
	  }

#if !defined(NDEBUG)

	_svmf_verbose_methods_exit (env);

#endif

	{
	  _svmt_stack_frame *frame;
	  _svmt_method_info *caller_method;
	  _svmt_method_info *callee_method;
	  _svmt_object_instance *this;

	  frame = env->stack.current_frame;
	  callee_method = frame->method;
	  this = frame->this;

#ifndef NDEBUG

	  if (stack[stack_size - 1].reference != NULL &&
	      (DREF (callee_method->descriptor, value)[1] == 'L'
	       || DREF (callee_method->descriptor, value)[1] == '['))
	    {
	      /* check return value type */

	      const char *pdesc = DREF (callee_method->descriptor, value) + 1;
	      jint arg = 0;
	      _svmt_type_info *t;

	      while (*pdesc++ != /* to keep m4 happy: '(' */ ')');

	      /* save state */
	      env->stack.current_frame->pc = pc;
	      env->stack.current_frame->stack_size = 0;	/* artificially empty stack */

	      {
		jobject value;

		if (_svmm_new_native_local (env, value) != JNI_OK)
		  {
		    _svmm_fatal_error ("unsupported failure while debugging");
		  }

		*value = stack[stack_size - 1].reference;

		t =
		  _svmm_get_type_from_within_descriptor (env, callee_method,
							 pdesc, arg);

		env->stack.current_frame->stack_size = stack_size;	/* recover stack */

		/* in case stack was moved around  */
		frame = env->stack.current_frame;
		locals = (_svmt_stack_value *) (void *)
		  (((char *) frame) -
		   callee_method->frame_info->start_offset);
		stack =
		  (_svmt_stack_value *) (void *) (((char *) frame) +
						  _svmv_stack_offset);
		this = frame->this;

		stack[stack_size - 1].reference = *value;

		_svmm_free_native_local (env, value);
	      }

	      if (t != NULL)
		{
		  if (env->vm->verbose_instructions == JNI_TRUE)
		    {
		      _svmf_printf (env, stderr,
				    "** T%d: t = %s\n", env->thread.id,
				    t->name);

		      fflush (stderr);
		    }

		  if (!_svmf_is_assignable_from
		      (env, stack[stack_size - 1].reference->vtable->type, t))
		    {
		      _svmf_dump_stack_trace (env);
		      _svmm_fatal_error ("argument type bug detected");
		    }
		}
	    }

#endif

	  frame =
	    (_svmt_stack_frame *) (void *) (((char *) frame) -
					    frame->previous_offset);
	  env->stack.current_frame = frame;
	  caller_method = frame->method;
	  
	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + 0;
	  pc = frame->pc;

	  /* is method synchronized? */
	  if (callee_method->synchronized)
	    {
	      /* release monitor */
	      if (_svmf_exit_object_monitor (env, this) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}
	    }
	}

	 
	}

      END_RETURN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEVIRTUAL:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INVOKEVIRTUAL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INVOKEVIRTUAL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INVOKEVIRTUAL) - ((char *) &&INLINED_START_INVOKEVIRTUAL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INVOKEVIRTUAL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INVOKEVIRTUAL");
#endif
	break;

      START_INVOKEVIRTUAL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INVOKEVIRTUAL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INVOKEVIRTUAL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INVOKEVIRTUAL");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  goto exception_handler;
		}

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method = method;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_INVOKEVIRTUAL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESPECIAL:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INVOKESPECIAL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INVOKESPECIAL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INVOKESPECIAL) - ((char *) &&INLINED_START_INVOKESPECIAL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INVOKESPECIAL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INVOKESPECIAL");
#endif
	break;

      START_INVOKESPECIAL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INVOKESPECIAL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INVOKESPECIAL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INVOKESPECIAL");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method = method;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_INVOKESPECIAL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESTATIC:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INVOKESTATIC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INVOKESTATIC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INVOKESTATIC) - ((char *) &&INLINED_START_INVOKESTATIC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INVOKESTATIC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INVOKESTATIC");
#endif
	break;

      START_INVOKESTATIC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INVOKESTATIC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INVOKESTATIC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INVOKESTATIC");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  _svmt_method_info *method = (pc++)->method_info;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

	  frame_info = method->frame_info;
	  stack_size -= args_count;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor
		  (env, *(method->class_info->class_instance)) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame->stack_size = stack_size;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method = method;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = *(method->class_info->class_instance);
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 0;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_INVOKESTATIC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEINTERFACE:
      {
	env->vm->instructions[instr].param_count = 4;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INVOKEINTERFACE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INVOKEINTERFACE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INVOKEINTERFACE) - ((char *) &&INLINED_START_INVOKEINTERFACE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INVOKEINTERFACE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INVOKEINTERFACE");
#endif
	break;

      START_INVOKEINTERFACE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INVOKEINTERFACE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INVOKEINTERFACE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INVOKEINTERFACE");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  jint args_count = (pc++)->jint;
	  size_t method_offset = (pc++)->offset;
	  _svmt_object_instance *instance =
	    stack[(stack_size -= args_count)].reference;
	  _svmt_method_info *method;
	  _svmt_method_frame_info *frame_info;
	  _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif /* NOT NDEBUG */

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  
	  assert (_svmf_is_assignable_from
		  (env, instance->vtable->type,
		   _svmf_cast_type_class (method->class_info)));

	  frame_info = method->frame_info;

	  pc++;			/* skip gc map */

	  /* store return pc & stack size */
	  frame = env->stack.current_frame;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  /* syncronized? */
	  if (method->synchronized)
	    {
	      /* preserve references on the stack across GC */
	      frame->stack_size = stack_size + args_count;

	      if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		{
		  _svmm_goto_label (exception_handler);
		}

	      frame->stack_size = stack_size;
	      instance = stack[stack_size].reference;
	    }

	  if (_svmf_ensure_stack_capacity
	      (env, frame_info->java_invoke_frame_size) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  locals = &stack[stack_size];

	  /* initialize reference locals to null */
	  {
	    jint max = frame_info->non_parameter_ref_locals_count;
	    jint java_args_count = method->java_args_count;
	    jint i;

	    for (i = 0; i < max; i++)
	      {
		locals[java_args_count + i].reference = NULL;
	      }
	  }

	  /* setup callee frame */
	  frame =
	    (_svmt_stack_frame *) (void *)
	    (((char *) locals) + frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);
	  pc = frame_info->code;
	  stack_size = 0;

	  frame->previous_offset =
	    ((char *) frame) - ((char *) env->stack.current_frame);
	  frame->end_offset = frame_info->end_offset;
	  frame->method = method;
	  frame->stack_trace_element = NULL;
	  frame->lock_count = 0;
	  frame->this = instance;
	  frame->pc = pc;
	  frame->stack_size = stack_size;

	  env->stack.current_frame = frame;

	  /* check */
	  _svmf_periodic_check (env);

#ifndef NDEBUG

	  {
	    /* check argument types */

	    jint arg_count = method->java_args_count;
	    const char *pdesc = DREF (method->descriptor, value) + 1;
	    jint arg = 1;

	    while (arg < arg_count)
	      {
		jint old_arg = arg;

		if (locals[old_arg].reference != NULL)
		  {
		    _svmt_type_info *t =
		      _svmm_get_type_from_within_descriptor (env, method,
							     pdesc, arg);

		    /* in case stack was moved around  */
		    frame = env->stack.current_frame;
		    locals = (_svmt_stack_value *) (void *)
		      (((char *) frame) - method->frame_info->start_offset);
		    stack = (_svmt_stack_value *) (void *)
		      (((char *) frame) + _svmv_stack_offset);

		    if (t != NULL)
		      {
			if (!_svmf_is_assignable_from
			    (env, locals[old_arg].reference->vtable->type, t))
			  {
			    _svmf_dump_stack_trace (env);
			    _svmm_fatal_error ("argument type bug detected");
			  }
		      }
		  }
		else
		  {
		    _svmm_skip_type_within_descriptor (pdesc, arg);
		  }
	      }
	  }

#endif

	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_INVOKEINTERFACE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEW:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEW;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEW;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEW) - ((char *) &&INLINED_START_NEW);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEW;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEW");
#endif
	break;

      START_NEW:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEW]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEW:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEW");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  _svmt_class_info *class_info = (pc++)->class_info;
	  _svmt_object_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmm_new_object_instance (env, class_info, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference = instance;
	}

	 
	}

      END_NEW:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ARRAYLENGTH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARRAYLENGTH:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ARRAYLENGTH;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ARRAYLENGTH;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ARRAYLENGTH) - ((char *) &&INLINED_START_ARRAYLENGTH);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ARRAYLENGTH;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ARRAYLENGTH");
#endif
	break;

      START_ARRAYLENGTH:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ARRAYLENGTH]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ARRAYLENGTH:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ARRAYLENGTH");

	  /* instruction body */
	  
	{
	  _svmt_array_instance *array = (_svmt_array_instance *)
	    stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (array == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (array == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  assert (array == NULL || array->vtable->type->is_array);

	  
	  /* can cause sigsegv on NULL array ref */
	  stack[stack_size - 1].jint = array->size;

	  
	}

	 
	}

      END_ARRAYLENGTH:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ATHROW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ATHROW:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ATHROW;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ATHROW;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ATHROW) - ((char *) &&INLINED_START_ATHROW);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ATHROW;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ATHROW");
#endif
	break;

      START_ATHROW:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ATHROW]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ATHROW:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ATHROW");

	  /* instruction body */
	  
	{
	  *(env->throwable) = stack[stack_size - 1].reference;

	  env->stack.current_frame->pc = pc;

	  _svmm_goto_label (athrow_handler);
	}

	 
	}

      END_ATHROW:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CHECKCAST:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_CHECKCAST;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_CHECKCAST;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_CHECKCAST) - ((char *) &&INLINED_START_CHECKCAST);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_CHECKCAST;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "CHECKCAST");
#endif
	break;

      START_CHECKCAST:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p CHECKCAST]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_CHECKCAST:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "CHECKCAST");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;
	  _svmt_type_info *T = (pc++)->type_info;

	  if (instance != NULL)
	    {
	      _svmt_type_info *S = instance->vtable->type;

	      if (!_svmf_is_assignable_from (env, S, T))
		{
		  env->stack.current_frame->pc = pc;
		  _svmm_goto_label (classcastexception_handler);
		}
	    }
	}

	 
	}

      END_CHECKCAST:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INSTANCEOF:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INSTANCEOF;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INSTANCEOF;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INSTANCEOF) - ((char *) &&INLINED_START_INSTANCEOF);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INSTANCEOF;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INSTANCEOF");
#endif
	break;

      START_INSTANCEOF:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INSTANCEOF]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INSTANCEOF:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INSTANCEOF");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;
	  _svmt_type_info *T = (pc++)->type_info;

	  if (instance != NULL)
	    {
	      _svmt_type_info *S = instance->vtable->type;

	      if (_svmf_is_assignable_from (env, S, T))
		{
		  stack[stack_size - 1].jint = 1;
		}
	      else
		{
		  stack[stack_size - 1].jint = 0;
		}
	    }
	  else
	    {
	      stack[stack_size - 1].jint = 0;
	    }
	}

	 
	}

      END_INSTANCEOF:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
MONITORENTER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITORENTER:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_MONITORENTER;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_MONITORENTER;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_MONITORENTER) - ((char *) &&INLINED_START_MONITORENTER);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_MONITORENTER;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "MONITORENTER");
#endif
	break;

      START_MONITORENTER:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p MONITORENTER]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_MONITORENTER:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "MONITORENTER");

	  /* instruction body */
	  
	{
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  --stack_size;

	  /* structured locking */
	  env->stack.current_frame->lock_count++;
	}

	 
	}

      END_MONITORENTER:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
MONITOREXIT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITOREXIT:
      {
	env->vm->instructions[instr].param_count = 0;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_MONITOREXIT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_MONITOREXIT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_MONITOREXIT) - ((char *) &&INLINED_START_MONITOREXIT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_MONITOREXIT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "MONITOREXIT");
#endif
	break;

      START_MONITOREXIT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p MONITOREXIT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_MONITOREXIT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "MONITOREXIT");

	  /* instruction body */
	  
	{
	  _svmt_object_instance *instance = stack[--stack_size].reference;

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

	  /* structured locking */
	  if (--(env->stack.current_frame->lock_count) < 0
	      && env->vm->enforce_structured_locking)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmf_error_IllegalMonitorStateException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmf_exit_object_monitor (env, instance) != JNI_OK)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (exception_handler);
	    }
	}

	 
	}

      END_MONITOREXIT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNULL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNULL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNULL) - ((char *) &&INLINED_START_IFNULL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNULL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNULL");
#endif
	break;

      START_IFNULL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNULL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNULL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNULL");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNULL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNULL_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNULL_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNULL_CHECK) - ((char *) &&INLINED_START_IFNULL_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNULL_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNULL_CHECK");
#endif
	break;

      START_IFNULL_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNULL_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNULL_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNULL_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNULL_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNONNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNONNULL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNONNULL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNONNULL) - ((char *) &&INLINED_START_IFNONNULL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNONNULL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNONNULL");
#endif
	break;

      START_IFNONNULL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNONNULL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNONNULL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNONNULL");

	  /* instruction body */
	  
	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNONNULL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
IFNONNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL_CHECK:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_IFNONNULL_CHECK;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_IFNONNULL_CHECK;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_IFNONNULL_CHECK) - ((char *) &&INLINED_START_IFNONNULL_CHECK);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_IFNONNULL_CHECK;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "IFNONNULL_CHECK");
#endif
	break;

      START_IFNONNULL_CHECK:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p IFNONNULL_CHECK]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_IFNONNULL_CHECK:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "IFNONNULL_CHECK");

	  /* instruction body */
	  
	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	 
	}

      END_IFNONNULL_CHECK:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
LINK_NATIVE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LINK_NATIVE_METHOD:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_LINK_NATIVE_METHOD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_LINK_NATIVE_METHOD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_LINK_NATIVE_METHOD) - ((char *) &&INLINED_START_LINK_NATIVE_METHOD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_LINK_NATIVE_METHOD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "LINK_NATIVE_METHOD");
#endif
	break;

      START_LINK_NATIVE_METHOD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p LINK_NATIVE_METHOD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_LINK_NATIVE_METHOD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "LINK_NATIVE_METHOD");

	  /* instruction body */
	  
	{
	  _svmt_method_info *method = env->stack.current_frame->method;
	  _svmt_stack_frame *frame;

	  if (_svmf_bind_native_method (env, method) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  method = frame->method;

	  locals =
	    (_svmt_stack_value *) (void *) (((char *) frame) -
					    method->frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);

	  pc = method->frame_info->code;
	  stack_size = 0;

	}

	 
	}

      END_LINK_NATIVE_METHOD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ABSTRACT_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ABSTRACT_METHOD:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ABSTRACT_METHOD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ABSTRACT_METHOD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ABSTRACT_METHOD) - ((char *) &&INLINED_START_ABSTRACT_METHOD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ABSTRACT_METHOD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ABSTRACT_METHOD");
#endif
	break;

      START_ABSTRACT_METHOD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ABSTRACT_METHOD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ABSTRACT_METHOD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ABSTRACT_METHOD");

	  /* instruction body */
	  
	_svmm_goto_label (abstractmethoderror_handler);

	 
	}

      END_ABSTRACT_METHOD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NATIVE_STATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_STATIC_METHOD:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NATIVE_STATIC_METHOD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NATIVE_STATIC_METHOD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NATIVE_STATIC_METHOD) - ((char *) &&INLINED_START_NATIVE_STATIC_METHOD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NATIVE_STATIC_METHOD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NATIVE_STATIC_METHOD");
#endif
	break;

      START_NATIVE_STATIC_METHOD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NATIVE_STATIC_METHOD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NATIVE_STATIC_METHOD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NATIVE_STATIC_METHOD");

	  /* instruction body */
	  
	{
	  _svmt_method_info *method;
	  _svmt_stack_frame *frame;

	  if (_svmf_invoke_native_static (env) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  method = frame->method;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size;
	  pc = frame->pc;
	}

	 
	}

      END_NATIVE_STATIC_METHOD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NATIVE_NONSTATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_NONSTATIC_METHOD:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NATIVE_NONSTATIC_METHOD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NATIVE_NONSTATIC_METHOD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NATIVE_NONSTATIC_METHOD) - ((char *) &&INLINED_START_NATIVE_NONSTATIC_METHOD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NATIVE_NONSTATIC_METHOD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NATIVE_NONSTATIC_METHOD");
#endif
	break;

      START_NATIVE_NONSTATIC_METHOD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NATIVE_NONSTATIC_METHOD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NATIVE_NONSTATIC_METHOD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NATIVE_NONSTATIC_METHOD");

	  /* instruction body */
	  
	{
	  _svmt_method_info *method;
	  _svmt_stack_frame *frame;

	  if (_svmf_invoke_native_nonstatic (env) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  frame = env->stack.current_frame;
	  method = frame->method;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size;
	  pc = frame->pc;
	}

	 
	}

      END_NATIVE_NONSTATIC_METHOD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_BYTE) - ((char *) &&INLINED_START_GETFIELD_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_BYTE");
#endif
	break;

      START_GETFIELD_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_BYTE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_BYTE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_BYTE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jint =
	    *((jbyte *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_SHORT) - ((char *) &&INLINED_START_GETFIELD_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_SHORT");
#endif
	break;

      START_GETFIELD_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_SHORT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_SHORT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_SHORT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jint =
	    *((jshort *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_CHAR) - ((char *) &&INLINED_START_GETFIELD_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_CHAR");
#endif
	break;

      START_GETFIELD_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_CHAR:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_CHAR != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_CHAR");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jint =
	    *((jchar *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_INT) - ((char *) &&INLINED_START_GETFIELD_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_INT");
#endif
	break;

      START_GETFIELD_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_INT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_INT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_INT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jint =
	    *((jint *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_LONG) - ((char *) &&INLINED_START_GETFIELD_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_LONG");
#endif
	break;

      START_GETFIELD_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_LONG:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_LONG != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_LONG");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  *((jlong *) (void *) &stack[stack_size++ - 1]) =
	    *((jlong *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_FLOAT) - ((char *) &&INLINED_START_GETFIELD_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_FLOAT");
#endif
	break;

      START_GETFIELD_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_FLOAT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_FLOAT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_FLOAT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jfloat =
	    *((jfloat *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_DOUBLE) - ((char *) &&INLINED_START_GETFIELD_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_DOUBLE");
#endif
	break;

      START_GETFIELD_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_DOUBLE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_DOUBLE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_DOUBLE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  *((jdouble *) (void *) &stack[stack_size++ - 1]) =
	    *((jdouble *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_REFERENCE) - ((char *) &&INLINED_START_GETFIELD_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_REFERENCE");
#endif
	break;

      START_GETFIELD_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_REFERENCE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_REFERENCE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_REFERENCE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].reference =
	    *((_svmt_object_instance * *) (void *) (((char *) instance) + offset));

	  	}

	 
	}

      END_GETFIELD_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_BYTE) - ((char *) &&INLINED_START_PUTFIELD_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_BYTE");
#endif
	break;

      START_PUTFIELD_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_BYTE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_BYTE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_BYTE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jbyte value = stack[--stack_size].jint;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BYTE_FIELD)
	  _svmf_put_BYTE_field (env, instance, offset, value);
#else
	  _svmf_put_BYTE_field (instance, offset, value);
#endif /* SVM_PUT_BYTE_FIELD */

	  	}

	 
	}

      END_PUTFIELD_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_SHORT) - ((char *) &&INLINED_START_PUTFIELD_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_SHORT");
#endif
	break;

      START_PUTFIELD_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_SHORT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_SHORT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_SHORT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jshort value = stack[--stack_size].jint;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_SHORT_FIELD)
	  _svmf_put_SHORT_field (env, instance, offset, value);
#else
	  _svmf_put_SHORT_field (instance, offset, value);
#endif /* SVM_PUT_SHORT_FIELD */

	  	}

	 
	}

      END_PUTFIELD_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_CHAR) - ((char *) &&INLINED_START_PUTFIELD_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_CHAR");
#endif
	break;

      START_PUTFIELD_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_CHAR:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_CHAR != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_CHAR");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jchar value = stack[--stack_size].jint;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_CHAR_FIELD)
	  _svmf_put_CHAR_field (env, instance, offset, value);
#else
	  _svmf_put_CHAR_field (instance, offset, value);
#endif /* SVM_PUT_CHAR_FIELD */

	  	}

	 
	}

      END_PUTFIELD_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_INT) - ((char *) &&INLINED_START_PUTFIELD_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_INT");
#endif
	break;

      START_PUTFIELD_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_INT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_INT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_INT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jint value = stack[--stack_size].jint;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_INT_FIELD)
	  _svmf_put_INT_field (env, instance, offset, value);
#else
	  _svmf_put_INT_field (instance, offset, value);
#endif /* SVM_PUT_INT_FIELD */

	  	}

	 
	}

      END_PUTFIELD_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_LONG) - ((char *) &&INLINED_START_PUTFIELD_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_LONG");
#endif
	break;

      START_PUTFIELD_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_LONG:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_LONG != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_LONG");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  *((jlong *) (void *) (((char *) instance) + offset)) = value;

	  	}

	 
	}

      END_PUTFIELD_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_FLOAT) - ((char *) &&INLINED_START_PUTFIELD_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_FLOAT");
#endif
	break;

      START_PUTFIELD_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_FLOAT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_FLOAT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_FLOAT");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jfloat value = stack[--stack_size].jfloat;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_FLOAT_FIELD)
	  _svmf_put_FLOAT_field (env, instance, offset, value);
#else
	  _svmf_put_FLOAT_field (instance, offset, value);
#endif /* SVM_PUT_FLOAT_FIELD */

	  	}

	 
	}

      END_PUTFIELD_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_DOUBLE) - ((char *) &&INLINED_START_PUTFIELD_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_DOUBLE");
#endif
	break;

      START_PUTFIELD_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_DOUBLE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_DOUBLE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_DOUBLE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  *((jdouble *) (void *) (((char *) instance) + offset)) = value;

	  	}

	 
	}

      END_PUTFIELD_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_REFERENCE) - ((char *) &&INLINED_START_PUTFIELD_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_REFERENCE");
#endif
	break;

      START_PUTFIELD_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_REFERENCE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_REFERENCE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_REFERENCE");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance * value = stack[--stack_size].reference;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) && !defined(__s390__)

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_REFERENCE_FIELD)
	  _svmf_put_REFERENCE_field (env, instance, offset, value);
#else
	  _svmf_put_REFERENCE_field (instance, offset, value);
#endif /* SVM_PUT_REFERENCE_FIELD */

	  	}

	 
	}

      END_PUTFIELD_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_BOOLEAN) - ((char *) &&INLINED_START_GETSTATIC_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_BOOLEAN");
#endif
	break;

      START_GETSTATIC_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_BOOLEAN:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_BOOLEAN != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_BOOLEAN");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->z;
	}

	 
	}

      END_GETSTATIC_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_BYTE) - ((char *) &&INLINED_START_GETSTATIC_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_BYTE");
#endif
	break;

      START_GETSTATIC_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_BYTE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_BYTE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_BYTE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->b;
	}

	 
	}

      END_GETSTATIC_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_SHORT) - ((char *) &&INLINED_START_GETSTATIC_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_SHORT");
#endif
	break;

      START_GETSTATIC_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_SHORT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_SHORT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_SHORT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->s;
	}

	 
	}

      END_GETSTATIC_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_CHAR) - ((char *) &&INLINED_START_GETSTATIC_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_CHAR");
#endif
	break;

      START_GETSTATIC_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_CHAR:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_CHAR != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_CHAR");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->c;
	}

	 
	}

      END_GETSTATIC_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_INT) - ((char *) &&INLINED_START_GETSTATIC_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_INT");
#endif
	break;

      START_GETSTATIC_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_INT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_INT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_INT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jint = pvalue->i;
	}

	 
	}

      END_GETSTATIC_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_LONG) - ((char *) &&INLINED_START_GETSTATIC_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_LONG");
#endif
	break;

      START_GETSTATIC_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_LONG:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_LONG != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_LONG");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *((jlong *) (void *) &stack[stack_size]) = pvalue->j;
	  stack_size += 2;
	}

	 
	}

      END_GETSTATIC_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_FLOAT) - ((char *) &&INLINED_START_GETSTATIC_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_FLOAT");
#endif
	break;

      START_GETSTATIC_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_FLOAT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_FLOAT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_FLOAT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].jfloat = pvalue->f;
	}

	 
	}

      END_GETSTATIC_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_DOUBLE) - ((char *) &&INLINED_START_GETSTATIC_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_DOUBLE");
#endif
	break;

      START_GETSTATIC_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_DOUBLE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_DOUBLE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_DOUBLE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *((jdouble *) (void *) &stack[stack_size]) = pvalue->d;
	  stack_size += 2;
	}

	 
	}

      END_GETSTATIC_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_BOOLEAN) - ((char *) &&INLINED_START_PUTSTATIC_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_BOOLEAN");
#endif
	break;

      START_PUTSTATIC_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_BOOLEAN:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_BOOLEAN != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_BOOLEAN");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->z = stack[--stack_size].jint;
	}

	 
	}

      END_PUTSTATIC_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_BYTE) - ((char *) &&INLINED_START_PUTSTATIC_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_BYTE");
#endif
	break;

      START_PUTSTATIC_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_BYTE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_BYTE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_BYTE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->b = stack[--stack_size].jint;
	}

	 
	}

      END_PUTSTATIC_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_SHORT) - ((char *) &&INLINED_START_PUTSTATIC_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_SHORT");
#endif
	break;

      START_PUTSTATIC_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_SHORT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_SHORT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_SHORT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->s = stack[--stack_size].jint;
	}

	 
	}

      END_PUTSTATIC_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_CHAR) - ((char *) &&INLINED_START_PUTSTATIC_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_CHAR");
#endif
	break;

      START_PUTSTATIC_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_CHAR:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_CHAR != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_CHAR");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->c = stack[--stack_size].jint;
	}

	 
	}

      END_PUTSTATIC_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_INT) - ((char *) &&INLINED_START_PUTSTATIC_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_INT");
#endif
	break;

      START_PUTSTATIC_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_INT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_INT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_INT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->i = stack[--stack_size].jint;
	}

	 
	}

      END_PUTSTATIC_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_LONG) - ((char *) &&INLINED_START_PUTSTATIC_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_LONG");
#endif
	break;

      START_PUTSTATIC_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_LONG:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_LONG != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_LONG");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->j = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	}

	 
	}

      END_PUTSTATIC_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_FLOAT) - ((char *) &&INLINED_START_PUTSTATIC_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_FLOAT");
#endif
	break;

      START_PUTSTATIC_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_FLOAT:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_FLOAT != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_FLOAT");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->f = stack[--stack_size].jfloat;
	}

	 
	}

      END_PUTSTATIC_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_DOUBLE) - ((char *) &&INLINED_START_PUTSTATIC_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_DOUBLE");
#endif
	break;

      START_PUTSTATIC_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_DOUBLE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_DOUBLE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_DOUBLE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->d = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	}

	 
	}

      END_PUTSTATIC_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETFIELD_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETFIELD_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETFIELD_BOOLEAN) - ((char *) &&INLINED_START_GETFIELD_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETFIELD_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETFIELD_BOOLEAN");
#endif
	break;

      START_GETFIELD_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETFIELD_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETFIELD_BOOLEAN:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETFIELD_BOOLEAN != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETFIELD_BOOLEAN");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_object_instance *instance = stack[stack_size - 1].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  stack[stack_size - 1].jint =
	    (((_svmt_u8 *) instance)[offset / 8] >> (offset % 8)) & 1;

	  	}

	 
	}

      END_GETFIELD_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTFIELD_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTFIELD_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTFIELD_BOOLEAN) - ((char *) &&INLINED_START_PUTFIELD_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTFIELD_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_BOOLEAN");
#endif
	break;

      START_PUTFIELD_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTFIELD_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTFIELD_BOOLEAN:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTFIELD_BOOLEAN != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTFIELD_BOOLEAN");

	  /* instruction body */
	  
	{
	  size_t offset = (pc++)->offset;
	  _svmt_u8 value = 0x01 & stack[--stack_size].jint;
	  _svmt_u8 nvalue = 0x01 ^ value;
	  _svmt_object_instance *instance = stack[--stack_size].reference;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	  if (instance == NULL)
	    {
	      env->sigsegv_expected = JNI_TRUE;
	    }

#endif

	  /* save pc in case exception is raised */
	  env->stack.current_frame->pc = pc;

#else

	  if (instance == NULL)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (nullpointerexception_handler);
	    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	  
	  /* to avoid conditional jumps we use boolean arithmetic */
	  ((_svmt_u8 *) instance)[offset / 8] |= (value << (offset % 8));
	  ((_svmt_u8 *) instance)[offset / 8] &= ~(nvalue << (offset % 8));

	  	}

	 
	}

      END_PUTFIELD_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_GETSTATIC_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_GETSTATIC_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_GETSTATIC_REFERENCE) - ((char *) &&INLINED_START_GETSTATIC_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_GETSTATIC_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_REFERENCE");
#endif
	break;

      START_GETSTATIC_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p GETSTATIC_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_GETSTATIC_REFERENCE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_GETSTATIC_REFERENCE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "GETSTATIC_REFERENCE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].reference = *(pvalue->l);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	  assert (stack[stack_size - 1].reference == NULL ||
		  strcmp (stack[stack_size - 1].reference->magic,
			  "SableVM") == 0);
#endif
	}

	 
	}

      END_GETSTATIC_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PUTSTATIC_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PUTSTATIC_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PUTSTATIC_REFERENCE) - ((char *) &&INLINED_START_PUTSTATIC_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PUTSTATIC_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_REFERENCE");
#endif
	break;

      START_PUTSTATIC_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PUTSTATIC_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PUTSTATIC_REFERENCE:
	
	{	/* skip preparation address A */
	  if (SVM_INLINEABLE_PUTSTATIC_REFERENCE != SVM_INTRP_FLAG_INLINEABLE) pc++;
	}
 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PUTSTATIC_REFERENCE");

	  /* instruction body */
	  
	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(pvalue->l) = stack[--stack_size].reference;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier (env, (_svmt_object_instance **) pvalue->l);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
	}

	 
	}

      END_PUTSTATIC_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET:
      {
	env->vm->instructions[instr].param_count = 1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_RET;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_RET;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_RET) - ((char *) &&INLINED_START_ASTORE_RET);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_RET;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET");
#endif
	break;

      START_ASTORE_RET:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_RET]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_RET:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_RET");

	  /* instruction body */
	  
	{
	  jint indx = (pc++)->jint;
	  locals[indx].addr = stack[--stack_size].addr;
	}

	 
	}

      END_ASTORE_RET:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_RET_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_0:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_RET_0;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_RET_0;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_RET_0) - ((char *) &&INLINED_START_ASTORE_RET_0);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_RET_0;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_0");
#endif
	break;

      START_ASTORE_RET_0:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_RET_0]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_RET_0:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_RET_0");

	  /* instruction body */
	  
	{
	  locals[0].addr = stack[--stack_size].addr;
	}

	 
	}

      END_ASTORE_RET_0:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_RET_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_1:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_RET_1;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_RET_1;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_RET_1) - ((char *) &&INLINED_START_ASTORE_RET_1);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_RET_1;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_1");
#endif
	break;

      START_ASTORE_RET_1:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_RET_1]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_RET_1:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_RET_1");

	  /* instruction body */
	  
	{
	  locals[1].addr = stack[--stack_size].addr;
	}

	 
	}

      END_ASTORE_RET_1:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_RET_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_2:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_RET_2;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_RET_2;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_RET_2) - ((char *) &&INLINED_START_ASTORE_RET_2);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_RET_2;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_2");
#endif
	break;

      START_ASTORE_RET_2:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_RET_2]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_RET_2:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_RET_2");

	  /* instruction body */
	  
	{
	  locals[2].addr = stack[--stack_size].addr;
	}

	 
	}

      END_ASTORE_RET_2:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ASTORE_RET_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_3:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ASTORE_RET_3;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ASTORE_RET_3;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ASTORE_RET_3) - ((char *) &&INLINED_START_ASTORE_RET_3);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ASTORE_RET_3;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_3");
#endif
	break;

      START_ASTORE_RET_3:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ASTORE_RET_3]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ASTORE_RET_3:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ASTORE_RET_3");

	  /* instruction body */
	  
	{
	  locals[3].addr = stack[--stack_size].addr;
	}

	 
	}

      END_ASTORE_RET_3:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEXT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEXT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEXT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEXT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEXT) - ((char *) &&INLINED_START_NEXT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEXT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEXT");
#endif
	break;

      START_NEXT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEXT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEXT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEXT");

	  /* instruction body */
	  
#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	_svmf_goto ((pc++)->implementation);

#endif

	 
	}

      END_NEXT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_BOOLEAN) - ((char *) &&INLINED_START_NEWARRAY_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_BOOLEAN");
#endif
	break;

      START_NEWARRAY_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_BOOLEAN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_BOOLEAN");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.boolean_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_BYTE) - ((char *) &&INLINED_START_NEWARRAY_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_BYTE");
#endif
	break;

      START_NEWARRAY_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_BYTE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_BYTE");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.byte_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_SHORT) - ((char *) &&INLINED_START_NEWARRAY_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_SHORT");
#endif
	break;

      START_NEWARRAY_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_SHORT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_SHORT");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.short_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_CHAR) - ((char *) &&INLINED_START_NEWARRAY_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_CHAR");
#endif
	break;

      START_NEWARRAY_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_CHAR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_CHAR");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.char_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_INT) - ((char *) &&INLINED_START_NEWARRAY_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_INT");
#endif
	break;

      START_NEWARRAY_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_INT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_INT");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.int_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_LONG) - ((char *) &&INLINED_START_NEWARRAY_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_LONG");
#endif
	break;

      START_NEWARRAY_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_LONG");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.long_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_FLOAT) - ((char *) &&INLINED_START_NEWARRAY_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_FLOAT");
#endif
	break;

      START_NEWARRAY_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_FLOAT");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.float_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
NEWARRAY_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_NEWARRAY_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_NEWARRAY_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_NEWARRAY_DOUBLE) - ((char *) &&INLINED_START_NEWARRAY_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_NEWARRAY_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_DOUBLE");
#endif
	break;

      START_NEWARRAY_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p NEWARRAY_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_NEWARRAY_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "NEWARRAY_DOUBLE");

	  /* instruction body */
	  
	{
	  _svmt_JavaVM *vm = env->vm;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, vm->class_loading.boot_loader.classes.double_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_NEWARRAY_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ANEWARRAY:
      {
	env->vm->instructions[instr].param_count = 2;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ANEWARRAY;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ANEWARRAY;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ANEWARRAY) - ((char *) &&INLINED_START_ANEWARRAY);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ANEWARRAY;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ANEWARRAY");
#endif
	break;

      START_ANEWARRAY:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ANEWARRAY]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ANEWARRAY:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ANEWARRAY");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  _svmt_array_info *array_info = (pc++)->array_info;
	  jint count = stack[--stack_size].jint;
	  _svmt_array_instance *instance;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (count < 0)
	    {
	      _svmf_error_NegativeArraySizeException (env);
	      _svmm_goto_label (exception_handler);
	    }

	  if (_svmm_new_array_instance
	      (env, array_info, count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_ANEWARRAY:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MULTIANEWARRAY:
      {
	env->vm->instructions[instr].param_count = 3;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_MULTIANEWARRAY;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_MULTIANEWARRAY;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_MULTIANEWARRAY) - ((char *) &&INLINED_START_MULTIANEWARRAY);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_MULTIANEWARRAY;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "MULTIANEWARRAY");
#endif
	break;

      START_MULTIANEWARRAY:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p MULTIANEWARRAY]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_MULTIANEWARRAY:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "MULTIANEWARRAY");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	{
	  _svmt_array_info *array_info = (pc++)->array_info;
	  jint dimensions = (pc++)->jint;
	  _svmt_array_instance *instance;

	  stack_size -= dimensions;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmm_multianewarray
	      (env, array_info, dimensions, stack[stack_size],
	       instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	 
	}

      END_MULTIANEWARRAY:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
ERROR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ERROR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_ERROR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_ERROR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_ERROR) - ((char *) &&INLINED_START_ERROR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_ERROR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "ERROR");
#endif
	break;

      START_ERROR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p ERROR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_ERROR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "ERROR");

	  /* instruction body */
	  
	_svmm_fatal_error ("grave internal VM error");

	 
	}

      END_ERROR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
INTERNAL_CALL_END
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INTERNAL_CALL_END:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_INTERNAL_CALL_END;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_INTERNAL_CALL_END;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_INTERNAL_CALL_END) - ((char *) &&INLINED_START_INTERNAL_CALL_END);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_INTERNAL_CALL_END;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "INTERNAL_CALL_END");
#endif
	break;

      START_INTERNAL_CALL_END:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p INTERNAL_CALL_END]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_INTERNAL_CALL_END:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "INTERNAL_CALL_END");

	  /* instruction body */
	  
#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)
	env->signal_handler = previous_signal_handler;
#endif
	return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;

	 
	}

      END_INTERNAL_CALL_END:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
SKIP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SKIP:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_SKIP;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_SKIP;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_SKIP) - ((char *) &&INLINED_START_SKIP);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_SKIP;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "SKIP");
#endif
	break;

      START_SKIP:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p SKIP]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_SKIP:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "SKIP");

	  /* instruction body */
	  
	pc++;			/* skip preparation address */

	 
	}

      END_SKIP:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
REPLACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_REPLACE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_REPLACE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_REPLACE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_REPLACE) - ((char *) &&INLINED_START_REPLACE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_REPLACE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "REPLACE");
#endif
	break;

      START_REPLACE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p REPLACE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_REPLACE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "REPLACE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_code code = *(pc++);

	  *addr = code;
	}

	 
	}

      END_REPLACE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_METHOD:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_METHOD;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_METHOD;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_METHOD) - ((char *) &&INLINED_START_PREPARE_METHOD);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_METHOD;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_METHOD");
#endif
	break;

      START_PREPARE_METHOD:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_METHOD]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_METHOD:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_METHOD");

	  /* instruction body */
	  
	{
	  _svmt_stack_frame *frame = env->stack.current_frame;
	  _svmt_method_info *method = frame->method;

	  if (_svmf_prepare_code (env, method) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  frame = env->stack.current_frame;
	  method = frame->method;

	  locals =
	    (_svmt_stack_value *) (void *) (((char *) frame) -
					    method->frame_info->start_offset);
	  stack =
	    (_svmt_stack_value *) (void *) (((char *) frame) +
					    _svmv_stack_offset);

	  pc = method->frame_info->code;
	  stack_size = 0;
	}

	 
	}

      END_PREPARE_METHOD:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_LDC_STRING;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_LDC_STRING;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_LDC_STRING) - ((char *) &&INLINED_START_PREPARE_LDC_STRING);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_LDC_STRING;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_LDC_STRING");
#endif
	break;

      START_PREPARE_LDC_STRING:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_LDC_STRING]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_LDC_STRING:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_LDC_STRING");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_String_info *stringref_info = (pc++)->stringref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_String (env, stringref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->jobject = stringref_info->value;

	  /* execute bytecode */
	  stack[stack_size++].reference = *(stringref_info->value);
	}

#if defined (MAGIC)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	 
	}

      END_PREPARE_LDC_STRING:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_BOOLEAN) - ((char *) &&INLINED_START_PREPARE_GETFIELD_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_BOOLEAN");
#endif
	break;

      START_PREPARE_GETFIELD_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_BOOLEAN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_BOOLEAN");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jint = _svmf_get_BOOLEAN_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_BYTE) - ((char *) &&INLINED_START_PREPARE_GETFIELD_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_BYTE");
#endif
	break;

      START_PREPARE_GETFIELD_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_BYTE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_BYTE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jint = _svmf_get_BYTE_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_SHORT) - ((char *) &&INLINED_START_PREPARE_GETFIELD_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_SHORT");
#endif
	break;

      START_PREPARE_GETFIELD_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_SHORT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_SHORT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jint = _svmf_get_SHORT_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_CHAR) - ((char *) &&INLINED_START_PREPARE_GETFIELD_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_CHAR");
#endif
	break;

      START_PREPARE_GETFIELD_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_CHAR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_CHAR");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jint = _svmf_get_CHAR_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_INT) - ((char *) &&INLINED_START_PREPARE_GETFIELD_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_INT");
#endif
	break;

      START_PREPARE_GETFIELD_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_INT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_INT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jint = _svmf_get_INT_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_LONG) - ((char *) &&INLINED_START_PREPARE_GETFIELD_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_LONG");
#endif
	break;

      START_PREPARE_GETFIELD_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_LONG");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    *((jlong *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_LONG_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_FLOAT) - ((char *) &&INLINED_START_PREPARE_GETFIELD_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_FLOAT");
#endif
	break;

      START_PREPARE_GETFIELD_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_FLOAT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].jfloat = _svmf_get_FLOAT_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_DOUBLE) - ((char *) &&INLINED_START_PREPARE_GETFIELD_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_DOUBLE");
#endif
	break;

      START_PREPARE_GETFIELD_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_DOUBLE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    *((jdouble *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_DOUBLE_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETFIELD_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETFIELD_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETFIELD_REFERENCE) - ((char *) &&INLINED_START_PREPARE_GETFIELD_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETFIELD_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_REFERENCE");
#endif
	break;

      START_PREPARE_GETFIELD_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETFIELD_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETFIELD_REFERENCE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETFIELD_REFERENCE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    stack[stack_size - 1].reference = _svmf_get_REFERENCE_field (instance, offset);
	  }
	}

	 
	}

      END_PREPARE_GETFIELD_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_BOOLEAN) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_BOOLEAN");
#endif
	break;

      START_PREPARE_PUTFIELD_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_BOOLEAN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_BOOLEAN");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jboolean value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BOOLEAN_FIELD)
	    _svmf_put_BOOLEAN_field (env, instance, offset, value);
#else
	    _svmf_put_BOOLEAN_field (instance, offset, value);
#endif /* SVM_PUT_BOOLEAN_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_BYTE) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_BYTE");
#endif
	break;

      START_PREPARE_PUTFIELD_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_BYTE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_BYTE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jbyte value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_BYTE_FIELD)
	    _svmf_put_BYTE_field (env, instance, offset, value);
#else
	    _svmf_put_BYTE_field (instance, offset, value);
#endif /* SVM_PUT_BYTE_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_SHORT) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_SHORT");
#endif
	break;

      START_PREPARE_PUTFIELD_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_SHORT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_SHORT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jshort value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_SHORT_FIELD)
	    _svmf_put_SHORT_field (env, instance, offset, value);
#else
	    _svmf_put_SHORT_field (instance, offset, value);
#endif /* SVM_PUT_SHORT_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_CHAR) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_CHAR");
#endif
	break;

      START_PREPARE_PUTFIELD_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_CHAR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_CHAR");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jchar value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_CHAR_FIELD)
	    _svmf_put_CHAR_field (env, instance, offset, value);
#else
	    _svmf_put_CHAR_field (instance, offset, value);
#endif /* SVM_PUT_CHAR_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_INT) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_INT");
#endif
	break;

      START_PREPARE_PUTFIELD_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_INT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_INT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jint value = stack[--stack_size].jint;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_INT_FIELD)
	    _svmf_put_INT_field (env, instance, offset, value);
#else
	    _svmf_put_INT_field (instance, offset, value);
#endif /* SVM_PUT_INT_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_LONG) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_LONG");
#endif
	break;

      START_PREPARE_PUTFIELD_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_LONG");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jlong value = *((jlong *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_LONG_FIELD)
	    _svmf_put_LONG_field (env, instance, offset, value);
#else
	    _svmf_put_LONG_field (instance, offset, value);
#endif /* SVM_PUT_LONG_FIELD */
	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_FLOAT) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_FLOAT");
#endif
	break;

      START_PREPARE_PUTFIELD_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_FLOAT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jfloat value = stack[--stack_size].jfloat;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_FLOAT_FIELD)
	    _svmf_put_FLOAT_field (env, instance, offset, value);
#else
	    _svmf_put_FLOAT_field (instance, offset, value);
#endif /* SVM_PUT_FLOAT_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_DOUBLE) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_DOUBLE");
#endif
	break;

      START_PREPARE_PUTFIELD_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_DOUBLE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    jdouble value = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_DOUBLE_FIELD)
	    _svmf_put_DOUBLE_field (env, instance, offset, value);
#else
	    _svmf_put_DOUBLE_field (instance, offset, value);
#endif /* SVM_PUT_DOUBLE_FIELD */
	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTFIELD_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTFIELD_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTFIELD_REFERENCE) - ((char *) &&INLINED_START_PREPARE_PUTFIELD_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTFIELD_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_REFERENCE");
#endif
	break;

      START_PREPARE_PUTFIELD_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTFIELD_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTFIELD_REFERENCE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTFIELD_REFERENCE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->offset = fieldref_info->field->data.instance_field.offset;

	  /* execute bytecode */
	  {
	    size_t offset = fieldref_info->field->data.instance_field.offset;
	    _svmt_object_instance * value = stack[--stack_size].reference;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_REFERENCE_FIELD)
	    _svmf_put_REFERENCE_field (env, instance, offset, value);
#else
	    _svmf_put_REFERENCE_field (instance, offset, value);
#endif /* SVM_PUT_REFERENCE_FIELD */

	  }
	}

	 
	}

      END_PREPARE_PUTFIELD_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_BOOLEAN) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_BOOLEAN");
#endif
	break;

      START_PREPARE_GETSTATIC_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_BOOLEAN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_BOOLEAN");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jint = _svmf_get_BOOLEAN_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_BYTE) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_BYTE");
#endif
	break;

      START_PREPARE_GETSTATIC_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_BYTE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_BYTE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jint = _svmf_get_BYTE_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_SHORT) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_SHORT");
#endif
	break;

      START_PREPARE_GETSTATIC_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_SHORT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_SHORT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jint = _svmf_get_SHORT_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_CHAR) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_CHAR");
#endif
	break;

      START_PREPARE_GETSTATIC_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_CHAR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_CHAR");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jint = _svmf_get_CHAR_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_INT) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_INT");
#endif
	break;

      START_PREPARE_GETSTATIC_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_INT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_INT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jint = _svmf_get_INT_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_LONG) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_LONG");
#endif
	break;

      START_PREPARE_GETSTATIC_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_LONG");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    *((jlong *) (void *) &stack[stack_size]) =
	      _svmf_get_LONG_static (pvalue);
	    stack_size += 2;
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_FLOAT) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_FLOAT");
#endif
	break;

      START_PREPARE_GETSTATIC_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_FLOAT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].jfloat = _svmf_get_FLOAT_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_DOUBLE) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_DOUBLE");
#endif
	break;

      START_PREPARE_GETSTATIC_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_DOUBLE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    *((jdouble *) (void *) &stack[stack_size]) =
	      _svmf_get_DOUBLE_static (pvalue);
	    stack_size += 2;
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_GETSTATIC_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_GETSTATIC_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_GETSTATIC_REFERENCE) - ((char *) &&INLINED_START_PREPARE_GETSTATIC_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_GETSTATIC_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_REFERENCE");
#endif
	break;

      START_PREPARE_GETSTATIC_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_GETSTATIC_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_GETSTATIC_REFERENCE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_GETSTATIC_REFERENCE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    stack[stack_size++].reference = _svmf_get_REFERENCE_static (pvalue);
	  }
	}

	 
	}

      END_PREPARE_GETSTATIC_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_BOOLEAN;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_BOOLEAN;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_BOOLEAN) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_BOOLEAN);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_BOOLEAN;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_BOOLEAN");
#endif
	break;

      START_PREPARE_PUTSTATIC_BOOLEAN:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_BOOLEAN]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_BOOLEAN:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_BOOLEAN");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_BOOLEAN_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_BOOLEAN:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_BYTE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_BYTE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_BYTE) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_BYTE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_BYTE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_BYTE");
#endif
	break;

      START_PREPARE_PUTSTATIC_BYTE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_BYTE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_BYTE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_BYTE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_BYTE_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_BYTE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_SHORT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_SHORT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_SHORT) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_SHORT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_SHORT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_SHORT");
#endif
	break;

      START_PREPARE_PUTSTATIC_SHORT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_SHORT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_SHORT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_SHORT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_SHORT_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_SHORT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_CHAR;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_CHAR;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_CHAR) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_CHAR);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_CHAR;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_CHAR");
#endif
	break;

      START_PREPARE_PUTSTATIC_CHAR:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_CHAR]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_CHAR:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_CHAR");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_CHAR_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_CHAR:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_INT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_INT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_INT) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_INT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_INT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_INT");
#endif
	break;

      START_PREPARE_PUTSTATIC_INT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_INT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_INT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_INT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_INT_static (pvalue, stack[--stack_size].jint);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_INT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_LONG;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_LONG;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_LONG) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_LONG);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_LONG;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_LONG");
#endif
	break;

      START_PREPARE_PUTSTATIC_LONG:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_LONG]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_LONG:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_LONG");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_LONG_static (pvalue,
				 *((jlong *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_LONG:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_FLOAT;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_FLOAT;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_FLOAT) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_FLOAT);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_FLOAT;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_FLOAT");
#endif
	break;

      START_PREPARE_PUTSTATIC_FLOAT:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_FLOAT]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_FLOAT:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_FLOAT");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_FLOAT_static (pvalue, stack[--stack_size].jfloat);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_FLOAT:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_DOUBLE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_DOUBLE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_DOUBLE) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_DOUBLE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_DOUBLE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_DOUBLE");
#endif
	break;

      START_PREPARE_PUTSTATIC_DOUBLE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_DOUBLE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_DOUBLE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_DOUBLE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_DOUBLE_static (pvalue,
				 *((jdouble *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_DOUBLE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_PUTSTATIC_REFERENCE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_PUTSTATIC_REFERENCE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_PUTSTATIC_REFERENCE) - ((char *) &&INLINED_START_PREPARE_PUTSTATIC_REFERENCE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_PUTSTATIC_REFERENCE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_REFERENCE");
#endif
	break;

      START_PREPARE_PUTSTATIC_REFERENCE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_PUTSTATIC_REFERENCE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_PUTSTATIC_REFERENCE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_PUTSTATIC_REFERENCE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Fieldref_info *fieldref_info = (pc++)->fieldref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Fieldref
	      (env, env->stack.current_frame->method->class_info,
	       fieldref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, fieldref_info->field->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->pvalue = &(fieldref_info->field->data.class_field.value);

	  /* execute bytecode */
	  {
	    jvalue *pvalue = &(fieldref_info->field->data.class_field.value);
	    _svmf_put_REFERENCE_static (pvalue, stack[--stack_size].reference);
	  }
	}

	 
	}

      END_PREPARE_PUTSTATIC_REFERENCE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_CHECKCAST;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_CHECKCAST;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_CHECKCAST) - ((char *) &&INLINED_START_PREPARE_CHECKCAST);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_CHECKCAST;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_CHECKCAST");
#endif
	break;

      START_PREPARE_CHECKCAST:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_CHECKCAST]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_CHECKCAST:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_CHECKCAST");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env, env->stack.current_frame->method->class_info,
	       classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->type_info = classref_info->type;

	  /* execute bytecode */
	  {
	    _svmt_type_info *T = classref_info->type;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance != NULL)
	      {
		_svmt_type_info *S = instance->vtable->type;

		if (!_svmf_is_assignable_from (env, S, T))
		  {
		    goto classcastexception_handler;
		  }
	      }
	  }
	}

	 
	}

      END_PREPARE_CHECKCAST:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_INSTANCEOF;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_INSTANCEOF;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_INSTANCEOF) - ((char *) &&INLINED_START_PREPARE_INSTANCEOF);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_INSTANCEOF;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_INSTANCEOF");
#endif
	break;

      START_PREPARE_INSTANCEOF:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_INSTANCEOF]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_INSTANCEOF:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_INSTANCEOF");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env, env->stack.current_frame->method->class_info,
	       classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->type_info = classref_info->type;

	  /* execute bytecode */
	  {
	    _svmt_type_info *T = classref_info->type;
	    _svmt_object_instance *instance = stack[stack_size - 1].reference;

	    if (instance != NULL)
	      {
		_svmt_type_info *S = instance->vtable->type;

		if (_svmf_is_assignable_from (env, S, T))
		  {
		    stack[stack_size - 1].jint = 1;
		  }
		else
		  {
		    stack[stack_size - 1].jint = 0;
		  }
	      }
	    else
	      {
		stack[stack_size - 1].jint = 0;
	      }
	  }
	}

	 
	}

      END_PREPARE_INSTANCEOF:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_NEW:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_NEW;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_NEW;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_NEW) - ((char *) &&INLINED_START_PREPARE_NEW);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_NEW;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_NEW");
#endif
	break;

      START_PREPARE_NEW:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_NEW]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_NEW:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_NEW");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env, env->stack.current_frame->method->class_info,
	       classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, _svmf_cast_class (classref_info->type)) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->class_info = _svmf_cast_class (classref_info->type);

	  /* execute bytecode */
	  {
	    _svmt_class_info *class_info =
	      _svmf_cast_class (classref_info->type);
	    _svmt_object_instance *instance;

	    if (_svmm_new_object_instance
		(env, class_info, instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    stack[stack_size++].reference = instance;
	  }
	}

	 
	}

      END_PREPARE_NEW:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_ANEWARRAY;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_ANEWARRAY;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_ANEWARRAY) - ((char *) &&INLINED_START_PREPARE_ANEWARRAY);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_ANEWARRAY;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_ANEWARRAY");
#endif
	break;

      START_PREPARE_ANEWARRAY:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_ANEWARRAY]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_ANEWARRAY:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_ANEWARRAY");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;
	  _svmt_type_info *type;
	  _svmt_array_info *array_type;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env, env->stack.current_frame->method->class_info,
	       classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  type = classref_info->type;

	  if (_svmm_create_array
	      (env,
	       type->class_loader_info, type->array_type_name,
	       array_type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_array (env, array_type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->array_info = array_type;

	  /* execute bytecode */
	  {
	    _svmt_array_info *array_info = array_type;
	    jint count = stack[--stack_size].jint;
	    _svmt_array_instance *instance;

	    if (count < 0)
	      {
		_svmf_error_NegativeArraySizeException (env);
		goto exception_handler;
	      }

	    if (_svmm_new_array_instance
		(env, array_info, count, instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    stack[stack_size++].reference =
	      _svmf_cast_object_instance (instance);
	  }
	}

	 
	}

      END_PREPARE_ANEWARRAY:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_MULTIANEWARRAY;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_MULTIANEWARRAY;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_MULTIANEWARRAY) - ((char *) &&INLINED_START_PREPARE_MULTIANEWARRAY);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_MULTIANEWARRAY;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_MULTIANEWARRAY");
#endif
	break;

      START_PREPARE_MULTIANEWARRAY:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_MULTIANEWARRAY]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_MULTIANEWARRAY:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_MULTIANEWARRAY");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Class_info *classref_info = (pc++)->classref_info;
	  jint dimensions = (pc++)->jint;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Class
	      (env, env->stack.current_frame->method->class_info,
	       classref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_link_type (env, classref_info->type) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr->array_info = _svmf_cast_array (classref_info->type);

	  /* execute bytecode */
	  {
	    _svmt_array_info *array_info =
	      _svmf_cast_array (classref_info->type);
	    _svmt_array_instance *instance;

	    stack_size -= dimensions;

	    if (_svmm_multianewarray
		(env, array_info, dimensions, stack[stack_size],
		 instance) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    stack[stack_size++].reference =
	      _svmf_cast_object_instance (instance);
	  }
	}

	 
	}

      END_PREPARE_MULTIANEWARRAY:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_INVOKEVIRTUAL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_INVOKEVIRTUAL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_INVOKEVIRTUAL) - ((char *) &&INLINED_START_PREPARE_INVOKEVIRTUAL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_INVOKEVIRTUAL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKEVIRTUAL");
#endif
	break;

      START_PREPARE_INVOKEVIRTUAL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_INVOKEVIRTUAL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_INVOKEVIRTUAL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_INVOKEVIRTUAL");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env, env->stack.current_frame->method->class_info,
	       methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr[0].jint = methodref_info->method->java_args_count;

	  /*
	   * _svmf_resolve_CONSTANT_Methodref() may return an
	   * interface method in certain situations (e.g., virtually
	   * invoking a method on an abstract class, when this method
	   * is inherited from an interface and not implemented in the
	   * abstact class).
	   */
	  if (_svmf_is_set_flag
	      (methodref_info->method->class_info->access_flags,
	       SVM_ACC_INTERFACE))
	    {
	      addr[1].offset =
		-((1 + methodref_info->method->method_id) *
		  sizeof (_svmt_method_info *));
	    }
	  else
	    {
	      addr[1].offset =
		sizeof (_svmt_vtable) +
		(methodref_info->method->method_id *
		 sizeof (_svmt_method_info *));
	    }

	  /* execute bytecode */
	  {
	    jint args_count = addr[0].jint;
	    size_t method_offset = addr[1].offset;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_info *method;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	    if (instance == NULL)
	      {
		env->sigsegv_expected = JNI_TRUE;
	      }

#endif /* NOT NDEBUG */

	    /* save pc in case exception is raised */
	    env->stack.current_frame->pc = pc;

#else

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	    /* the following can cause a segfault */
	    method =
	      *((_svmt_method_info **) (void *)
		(((char *) instance->vtable) + method_offset));

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method = method;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - method->frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_PREPARE_INVOKEVIRTUAL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_INVOKESPECIAL;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_INVOKESPECIAL;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_INVOKESPECIAL) - ((char *) &&INLINED_START_PREPARE_INVOKESPECIAL);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_INVOKESPECIAL;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKESPECIAL");
#endif
	break;

      START_PREPARE_INVOKESPECIAL:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_INVOKESPECIAL]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_INVOKESPECIAL:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_INVOKESPECIAL");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env, env->stack.current_frame->method->class_info,
	       methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  /* select the appropriate method */
	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    if (_svmf_is_set_flag
		(method->class_info->access_flags, SVM_ACC_SUPER)
		&& _svmf_is_super_class (methodref_info->method->class_info,
					 method->class_info)
		&& DREF (methodref_info->method->name, value)[0] != '<')
	      {
		_svmt_method_info *selected_method =
		  _svmf_resolve_special_method
		  (_svmf_cast_class
		   (DREF (method->class_info->super_class, type)),
		   DREF (methodref_info->method->name, value),
		   DREF (methodref_info->method->descriptor, value));

		addr[0].jint = selected_method->java_args_count;
		addr[1].method_info = selected_method;
	      }
	    else
	      {
		addr[0].jint = methodref_info->method->java_args_count;
		addr[1].method_info = methodref_info->method;
	      }
	  }

	  /* execute bytecode */
	  {
	    jint args_count = addr[0].jint;
	    _svmt_method_info *method = addr[1].method_info;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method = method;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - method->frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_PREPARE_INVOKESPECIAL:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_INVOKESTATIC;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_INVOKESTATIC;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_INVOKESTATIC) - ((char *) &&INLINED_START_PREPARE_INVOKESTATIC);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_INVOKESTATIC;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKESTATIC");
#endif
	break;

      START_PREPARE_INVOKESTATIC:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_INVOKESTATIC]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_INVOKESTATIC:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_INVOKESTATIC");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_Methodref_info *methodref_info =
	    (pc++)->methodref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_Methodref
	      (env, env->stack.current_frame->method->class_info,
	       methodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  if (_svmf_class_initialization
	      (env, methodref_info->method->class_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr[0].jint = methodref_info->method->java_args_count;
	  addr[1].method_info = methodref_info->method;

	  /* execute bytecode */
	  {
	    jint args_count = addr[0].jint;
	    _svmt_method_info *method = addr[1].method_info;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (methodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (methodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;
	    stack_size -= args_count;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor
		    (env, *(method->class_info->class_instance)) != JNI_OK)
		  {
		    goto exception_handler;
		  }

		frame->stack_size = stack_size;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method = method;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = *(method->class_info->class_instance);
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 0;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - method->frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_PREPARE_INVOKESTATIC:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
      {
	env->vm->instructions[instr].param_count = -1;

	/* implementation address */
	env->vm->instructions[instr].code.implementation = &&START_PREPARE_INVOKEINTERFACE;
	env->vm->instructions[instr].inlined_code.implementation =
	  &&INLINED_START_PREPARE_INVOKEINTERFACE;

	/* code size */
	env->vm->instructions[instr].inlined_size =
	  ((char *) &&END_PREPARE_INVOKEINTERFACE) - ((char *) &&INLINED_START_PREPARE_INVOKEINTERFACE);

	/* can the implementation be relocated? */
	env->vm->instructions[instr].flag = SVM_INLINEABLE_PREPARE_INVOKEINTERFACE;

#if !defined(NDEBUG) || defined(_SABLEVM_INLINABILITY_TESTING)
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKEINTERFACE");
#endif
	break;

      START_PREPARE_INVOKEINTERFACE:
	{
#ifndef	NDEBUG

	  if (env->vm->verbose_instructions == JNI_TRUE)
	    {
	      _svmf_printf (env, stderr,
			    "T%d: [verbose instructions: executing @%p PREPARE_INVOKEINTERFACE]\n",
			    env->thread.id, (void *) (pc - 1));
	    }

#endif
	}
      INLINED_START_PREPARE_INVOKEINTERFACE:
	 	 
	{

	  _svmm_verbose_instructions_inlined (env, pc, "PREPARE_INVOKEINTERFACE");

	  /* instruction body */
	  
	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_CONSTANT_InterfaceMethodref_info *imethodref_info =
	    (pc++)->imethodref_info;

	  /* skip stack map */
	  assert (stack_size >= pc->stack_gc_map->size);
	  pc++;

	  /* save state */
	  env->stack.current_frame->pc = pc;
	  env->stack.current_frame->stack_size = stack_size;

	  if (_svmf_resolve_CONSTANT_InterfaceMethodref
	      (env, env->stack.current_frame->method->class_info,
	       imethodref_info) != JNI_OK)
	    {
	      goto exception_handler;
	    }

	  {
	    _svmt_stack_frame *frame = env->stack.current_frame;
	    _svmt_method_info *method = frame->method;

	    /* in case stack was moved around  */
	    locals = (_svmt_stack_value *) (void *)
	      (((char *) frame) - method->frame_info->start_offset);
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	  }

	  addr[0].jint = imethodref_info->method->java_args_count;
	  addr[1].offset =
	    -((1 + imethodref_info->method->method_id) *
	      sizeof (_svmt_method_info *));

	  /* execute bytecode */
	  {
	    jint args_count = addr[0].jint;
	    size_t method_offset = addr[1].offset;
	    _svmt_object_instance *instance =
	      stack[(stack_size -= args_count)].reference;
	    _svmt_method_info *method;
	    _svmt_method_frame_info *frame_info;
	    _svmt_stack_frame *frame;

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS

#ifndef NDEBUG

	    if (instance == NULL)
	      {
		env->sigsegv_expected = JNI_TRUE;
	      }

#endif /* NOT NDEBUG */

	    /* save pc in case exception is raised */
	    env->stack.current_frame->pc = pc;

#else

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS */

	    /* the following can cause a segfault */
	    method =
	      *((_svmt_method_info **) (void *)
		(((char *) instance->vtable) + method_offset));

	    assert (_svmf_is_assignable_from
		    (env, instance->vtable->type,
		     _svmf_cast_type_class (method->class_info)));

	    assert (strcmp
		    (DREF (method->name, value),
		     DREF (DREF (imethodref_info->name_and_type, name),
			   value)) == 0
		    && strcmp (DREF (method->descriptor, value),
			       DREF (DREF
				     (imethodref_info->name_and_type,
				      descriptor), value)) == 0);

	    frame_info = method->frame_info;

	    /* store return pc & stack size */
	    frame = env->stack.current_frame;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    /* syncronized? */
	    if (method->synchronized)
	      {
		/* preserve references on the stack across GC */
		frame->stack_size = stack_size + args_count;

		if (_svmf_enter_object_monitor (env, instance) != JNI_OK)
		  {
		    goto exception_handler;
		  }

		frame->stack_size = stack_size;
		instance = stack[stack_size].reference;
	      }

	    if (_svmf_ensure_stack_capacity
		(env, frame_info->java_invoke_frame_size) != JNI_OK)
	      {
		goto exception_handler;
	      }

	    frame = env->stack.current_frame;
	    stack = (_svmt_stack_value *) (void *)
	      (((char *) frame) + _svmv_stack_offset);
	    locals = &stack[stack_size];

	    /* initialize reference locals to null */
	    {
	      jint max = frame_info->non_parameter_ref_locals_count;
	      jint java_args_count = method->java_args_count;
	      jint i;

	      for (i = 0; i < max; i++)
		{
		  locals[java_args_count + i].reference = NULL;
		}
	    }

	    /* setup callee frame */
	    frame =
	      (_svmt_stack_frame *) (void *)
	      (((char *) locals) + frame_info->start_offset);
	    stack =
	      (_svmt_stack_value *) (void *) (((char *) frame) +
					      _svmv_stack_offset);
	    pc = frame_info->code;
	    stack_size = 0;

	    frame->previous_offset =
	      ((char *) frame) - ((char *) env->stack.current_frame);
	    frame->end_offset = frame_info->end_offset;
	    frame->method = method;
	    frame->stack_trace_element = NULL;
	    frame->lock_count = 0;
	    frame->this = instance;
	    frame->pc = pc;
	    frame->stack_size = stack_size;

	    env->stack.current_frame = frame;

	    /* check */
	    _svmf_periodic_check (env);

#ifndef NDEBUG

	    {
	      /* check argument types */

	      jint arg_count = method->java_args_count;
	      const char *pdesc = DREF (method->descriptor, value) + 1;
	      jint arg = 1;

	      while (arg < arg_count)
		{
		  jint old_arg = arg;

		  if (locals[old_arg].reference != NULL)
		    {
		      _svmt_type_info *t =
			_svmm_get_type_from_within_descriptor (env, method,
							       pdesc, arg);

		      /* in case stack was moved around  */
		      frame = env->stack.current_frame;
		      locals = (_svmt_stack_value *) (void *)
			(((char *) frame) - method->frame_info->start_offset);
		      stack = (_svmt_stack_value *) (void *)
			(((char *) frame) + _svmv_stack_offset);

		      if (t != NULL)
			{
			  if (!_svmf_is_assignable_from
			      (env, locals[old_arg].reference->vtable->type,
			       t))
			    {
			      _svmf_dump_stack_trace (env);
			      _svmm_fatal_error
				("argument type bug detected");
			    }
			}
		    }
		  else
		    {
		      _svmm_skip_type_within_descriptor (pdesc, arg);
		    }
		}
	    }

#endif

	  }
	}

#if !defined(NDEBUG)

	_svmf_verbose_methods_enter (env);

#endif

	 
	}

      END_PREPARE_INVOKEINTERFACE:
	{
	  /* dispatch */
	  goto *((pc++)->implementation);
	}
      }
