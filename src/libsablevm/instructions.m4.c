/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */

/*
----------------------------------------------------------------------
instructions
----------------------------------------------------------------------
*/

void
dummy ()
{
  switch (dummy)
    {
    case dummy:
      {

/*
----------------------------------------------------------------------
UNUSED BYTECODES
----------------------------------------------------------------------
*/
	/* m4_define([:m4svm_instruction_unused:], [: */
	m4svm_instruction_head ($1, $2);

	/* this bytecode should have been replaced by another code */
	_svmm_fatal_error ("impossible control flow");

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_unused(BIPUSH, 1) */
	/* m4svm_instruction_unused(SIPUSH, 2) */
	/* m4svm_instruction_unused(LDC, 1) */
	/* m4svm_instruction_unused(LDC_W, 2) */
	/* m4svm_instruction_unused(LDC2_W, 2) */
	/* m4svm_instruction_unused(GETSTATIC, 2) */
	/* m4svm_instruction_unused(PUTSTATIC, 2) */
	/* m4svm_instruction_unused(GETFIELD, 2) */
	/* m4svm_instruction_unused(PUTFIELD, 2) */
	/* m4svm_instruction_unused(NEWARRAY, 1) */
	/* m4svm_instruction_unused(WIDE, -1) */
	/* m4svm_instruction_unused(GOTO_W, 4) */
	/* m4svm_instruction_unused(JSR_W, 4) */

	/* m4_undefine([:m4svm_instruction_unused:]) */

/*
----------------------------------------------------------------------
NOP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NOP, 0);

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ACONST_NULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ACONST_NULL, 0);

	stack[stack_size++].reference = NULL;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<I/F/L/D>CONST_<X> 
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_const_x:], [: */
	m4svm_instruction_head ($1CONST_$3, 0);

	stack[stack_size++].$2 = $4;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_const_x:], [: */
	m4svm_instruction_head ($1CONST_$3, 0);

	*(($2 *) (void *) &stack[stack_size]) = $4;
	stack_size += 2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_const_x(I, jint, M1, -1)
	 * m4svm_instruction_if_const_x(I, jint, 0, 0)
	 * m4svm_instruction_if_const_x(I, jint, 1, 1)
	 * m4svm_instruction_if_const_x(I, jint, 2, 2)
	 * m4svm_instruction_if_const_x(I, jint, 3, 3)
	 * m4svm_instruction_if_const_x(I, jint, 4, 4)
	 * m4svm_instruction_if_const_x(I, jint, 5, 5)
	 * m4svm_instruction_ld_const_x(L, jlong, 0, 0)
	 * m4svm_instruction_ld_const_x(L, jlong, 1, 1)
	 * m4svm_instruction_if_const_x(F, jfloat, 0, 0)
	 * m4svm_instruction_if_const_x(F, jfloat, 1, 1)
	 * m4svm_instruction_if_const_x(F, jfloat, 2, 2)
	 * m4svm_instruction_ld_const_x(D, jdouble, 0, 0)
	 * m4svm_instruction_ld_const_x(D, jdouble, 1, 1) */

	/* m4_undefine([:m4svm_instruction_if_const_x:])
	 * m4_undefine([:m4svm_instruction_ld_const_x:]) */


/*
----------------------------------------------------------------------
LDC_INTEGER
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_INTEGER, -1);

	stack[stack_size++].jint = (pc++)->jint;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_FLOAT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_FLOAT, -1);

	stack[stack_size++].jfloat = (pc++)->jfloat;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_STRING
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_STRING, -1);

	stack[stack_size++].reference = *((pc++)->jobject);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL ||
		strcmp (stack[stack_size - 1].reference->magic,
			"SableVM") == 0);
#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_LONG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_LONG, -1);

	*((jlong *) (void *) &stack[stack_size]) = *((pc++)->pjlong);
	stack_size += 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDC_DOUBLE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LDC_DOUBLE, -1);

	*((jdouble *) (void *) &stack[stack_size]) = *((pc++)->pjdouble);
	stack_size += 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>LOAD<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_load:], [: */
	m4svm_instruction_head ($1LOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].$2 = locals[indx].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_load:], [: */
	m4svm_instruction_head ($1LOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  *(($2 *) (void *) &stack[stack_size]) =
	    *(($2 *) (void *) &locals[indx]);
	  stack_size += 2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_load(I, jint)
	 * m4svm_instruction_ld_load(L, jlong)
	 * m4svm_instruction_if_load(F, jfloat)
	 * m4svm_instruction_ld_load(D, jdouble) */

	/* m4_undefine([:m4svm_instruction_if_load:])
	 * m4_undefine([:m4svm_instruction_ld_load:]) */

	/* m4_define([:m4svm_instruction_if_load_x:], [: */
	m4svm_instruction_head ($1LOAD_$3, 0);

	stack[stack_size++].$2 = locals[$3].$2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_load_x:], [: */
	m4svm_instruction_head ($1LOAD_$3, 0);

	*(($2 *) (void *) &stack[stack_size]) =
	  *(($2 *) (void *) &locals[$3]);
	stack_size += 2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_load_x(I, jint, 0)
	 * m4svm_instruction_if_load_x(I, jint, 1)
	 * m4svm_instruction_if_load_x(I, jint, 2)
	 * m4svm_instruction_if_load_x(I, jint, 3)
	 * m4svm_instruction_ld_load_x(L, jlong, 0)
	 * m4svm_instruction_ld_load_x(L, jlong, 1)
	 * m4svm_instruction_ld_load_x(L, jlong, 2)
	 * m4svm_instruction_ld_load_x(L, jlong, 3)
	 * m4svm_instruction_if_load_x(F, jfloat, 0)
	 * m4svm_instruction_if_load_x(F, jfloat, 1)
	 * m4svm_instruction_if_load_x(F, jfloat, 2)
	 * m4svm_instruction_if_load_x(F, jfloat, 3)
	 * m4svm_instruction_ld_load_x(D, jdouble, 0)
	 * m4svm_instruction_ld_load_x(D, jdouble, 1)
	 * m4svm_instruction_ld_load_x(D, jdouble, 2)
	 * m4svm_instruction_ld_load_x(D, jdouble, 3) */

	/* m4_undefine([:m4svm_instruction_if_load_x:])
	 * m4_undefine([:m4svm_instruction_ld_load_x:]) */

	/* m4_define([:m4svm_instruction_ifcs_aload:], [: */
	m4svm_instruction_head ($1ALOAD, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  stack[stack_top].$3 = _svmf_get_$2_array_element (array, indx);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_aload:], [: */
	m4svm_instruction_head ($1ALOAD, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  if (indx < 0 || indx >= size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  *(($3 *) (void *) &stack[stack_size - 2]) =
	    _svmf_get_$2_array_element (array, indx);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifcs_aload(I, int, jint)
	 * m4svm_instruction_ld_aload(L, long, jlong)
	 * m4svm_instruction_ifcs_aload(F, float, jfloat)
	 * m4svm_instruction_ld_aload(D, double, jdouble)
	 * m4svm_instruction_ifcs_aload(C, char, jint)
	 * m4svm_instruction_ifcs_aload(S, short, jint) */

	/* m4_undefine([:m4svm_instruction_ifcs_aload:])
	 * m4_undefine([:m4svm_instruction_ld_aload:]) */

/*
----------------------------------------------------------------------
ALOAD<X>
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ALOAD, 1);

	{
	  jint indx = (pc++)->jint;
	  stack[stack_size++].reference = locals[indx].reference;
	}

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	m4svm_instruction_tail ();

	/* m4_define([:m4svm_instruction_a_load_x:], [: */
	m4svm_instruction_head (ALOAD_$1, 0);

	stack[stack_size++].reference = locals[$1].reference;

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	assert (stack[stack_size - 1].reference == NULL
		|| strcmp (stack[stack_size - 1].reference->magic,
			   "SableVM") == 0);
#endif

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_a_load_x(0)
	 * m4svm_instruction_a_load_x(1)
	 * m4svm_instruction_a_load_x(2)
	 * m4svm_instruction_a_load_x(3) */

	/* m4_undefine([:m4svm_instruction_a_load:]) */

/*
----------------------------------------------------------------------
AALOAD
----------------------------------------------------------------------
*/
	m4svm_instruction_head (AALOAD, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
BALOAD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (BALOAD, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>STORE<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_ifa_store:], [: */
	m4svm_instruction_head ($1STORE, 1);

	{
	  jint indx = (pc++)->jint;
	  locals[indx].$2 = stack[--stack_size].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_store:], [: */
	m4svm_instruction_head ($1STORE, 1);

	{
	  jint indx = (pc++)->jint;
	  stack_size -= 2;
	  *(($2 *) (void *) &locals[indx]) =
	    *(($2 *) (void *) &stack[stack_size]);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifa_store(I, jint)
	 * m4svm_instruction_ld_store(L, jlong)
	 * m4svm_instruction_ifa_store(F, jfloat)
	 * m4svm_instruction_ld_store(D, jdouble)
	 * m4svm_instruction_ifa_store(A, reference) */

	/* m4_undefine([:m4svm_instruction_ifa_store:])
	 * m4_undefine([:m4svm_instruction_ld_store:]) */

	/* m4_define([:m4svm_instruction_ifa_store_x:], [: */
	m4svm_instruction_head ($1STORE_$3, 0);

	locals[$3].$2 = stack[--stack_size].$2;

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_store_x:], [: */
	m4svm_instruction_head ($1STORE_$3, 0);

	stack_size -= 2;
	*(($2 *) (void *) &locals[$3]) =
	  *(($2 *) (void *) &stack[stack_size]);

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifa_store_x(I, jint, 0)
	 * m4svm_instruction_ifa_store_x(I, jint, 1)
	 * m4svm_instruction_ifa_store_x(I, jint, 2)
	 * m4svm_instruction_ifa_store_x(I, jint, 3)
	 * m4svm_instruction_ld_store_x(L, jlong, 0)
	 * m4svm_instruction_ld_store_x(L, jlong, 1)
	 * m4svm_instruction_ld_store_x(L, jlong, 2)
	 * m4svm_instruction_ld_store_x(L, jlong, 3)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 0)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 1)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 2)
	 * m4svm_instruction_ifa_store_x(F, jfloat, 3)
	 * m4svm_instruction_ld_store_x(D, jdouble, 0)
	 * m4svm_instruction_ld_store_x(D, jdouble, 1)
	 * m4svm_instruction_ld_store_x(D, jdouble, 2)
	 * m4svm_instruction_ld_store_x(D, jdouble, 3)
	 * m4svm_instruction_ifa_store_x(A, reference, 0)
	 * m4svm_instruction_ifa_store_x(A, reference, 1)
	 * m4svm_instruction_ifa_store_x(A, reference, 2)
	 * m4svm_instruction_ifa_store_x(A, reference, 3) */

	/* m4_undefine([:m4svm_instruction_ifa_store_x:])
	 * m4_undefine([:m4svm_instruction_ld_store_x:]) */

	/* m4_define([:m4svm_instruction_ifcs_astore:], [: */
	m4svm_instruction_head ($1ASTORE, 0);

	{
	  $4 value = stack[--stack_size].$3;
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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_$2_array_element (array, indx, value);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_ld_astore:], [: */
	m4svm_instruction_head ($1ASTORE, 0);

	{
	  $4 value = *(($3 *) (void *) &stack[(stack_size -= 2)]);
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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

	  /* check array bounds */
	  if (((_svmt_u32) indx) >= (_svmt_u32) size)
	    {
	      env->stack.current_frame->pc = pc;
	      _svmm_goto_label (arrayindexoutofboundsexception_handler);
	    }

	  _svmf_set_$2_array_element (array, indx, value);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_ifcs_astore(I, int, jint, jint)
	 * m4svm_instruction_ld_astore(L, long, jlong, jlong)
	 * m4svm_instruction_ifcs_astore(F, float, jfloat, jfloat)
	 * m4svm_instruction_ld_astore(D, double, jdouble, jdouble)
	 * m4svm_instruction_ifcs_astore(C, char, jint, jchar)
	 * m4svm_instruction_ifcs_astore(S, short, jint, jshort) */

	/* m4_undefine([:m4svm_instruction_ifcs_astore:])
	 * m4_undefine([:m4svm_instruction_ld_astore:]) */

/*
----------------------------------------------------------------------
BASTORE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (BASTORE, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
AASTORE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (AASTORE, 0);

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

	  m4svm_expect_sigsegv ();

	  size = array->size;	/* can cause sigsegv on NULL array ref */

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
POP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (POP, 0);

	stack_size--;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
POP2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (POP2, 0);

	stack_size -= 2;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP, 0);

	stack[stack_size] = stack[stack_size - 1];
	stack_size++;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP_X1
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP_X1, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	  stack[stack_size] = value1;
	  stack_size++;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP_X2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP_X2, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size++] = value2;
	  stack[stack_size++] = value1;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2_X1
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2_X1, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DUP2_X2
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DUP2_X2, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
SWAP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (SWAP, 0);

	{
	  _svmt_stack_value value2 = stack[stack_size - 2];
	  _svmt_stack_value value1 = stack[stack_size - 1];
	  stack[stack_size - 2] = value1;
	  stack[stack_size - 1] = value2;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
OPERATORS
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_operator_111:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value1 = stack[stack_size - 2].$2;
	  $3 value2 = stack[--stack_size].$3;
	  stack[stack_size - 1].$4 = value1 $5 value2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_222:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value1 = *(($2 *) (void *) &stack[stack_size - 4]);
	  $3 value2 = *(($3 *) (void *) &stack[(stack_size -= 2)]);
	  *(($4 *) (void *) &stack[stack_size - 2]) = value1 $5 value2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_11:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = stack[stack_size - 1].$2;
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].$3 = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].$3 = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_22:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = *(($2 *) (void *) &stack[stack_size - 2]);
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      *(($3 *) (void *) &stack[stack_size - 2]) = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      *(($3 *) (void *) &stack[stack_size - 2]) = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_12:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = stack[stack_size - 1].$2;
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      *(($3 *) (void *) &stack[stack_size++ - 1]) = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_operator_21:], [: */
	m4svm_instruction_head ($1, 0);

	{
	  $2 value = *(($2 *) (void *) &stack[--stack_size - 1]);
/* SVM__MAX is never defined. */
#ifdef SVM_$5_MAX
	  if (value != value)
	    {			/* NaN */
	      stack[stack_size - 1].$3 = 0;
	    }
	  else if (value >= SVM_$5_MAX)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MAX;
	    }
	  else if (value <= SVM_$5_MIN)
	    {
	      stack[stack_size - 1].$3 = SVM_$5_MIN;
	    }
	  else
#endif
	    {
	      stack[stack_size - 1].$3 = $4 value;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_operator_111(IADD, jint, jint, jint, +)
	 * m4svm_instruction_operator_222(LADD, jlong, jlong, jlong, +)
	 * m4svm_instruction_operator_111(FADD, jfloat, jfloat, jfloat, +)
	 * m4svm_instruction_operator_222(DADD, jdouble, jdouble, jdouble, +)
	 * m4svm_instruction_operator_111(ISUB, jint, jint, jint, -)
	 * m4svm_instruction_operator_222(LSUB, jlong, jlong, jlong, -)
	 * m4svm_instruction_operator_111(FSUB, jfloat, jfloat, jfloat, -)
	 * m4svm_instruction_operator_222(DSUB, jdouble, jdouble, jdouble, -)
	 * m4svm_instruction_operator_111(IMUL, jint, jint, jint, *)
	 * m4svm_instruction_operator_222(LMUL, jlong, jlong, jlong, *)
	 * m4svm_instruction_operator_111(FMUL, jfloat, jfloat, jfloat, *)
	 * m4svm_instruction_operator_222(DMUL, jdouble, jdouble, jdouble, *)
	 * m4svm_instruction_operator_111(FDIV, jfloat, jfloat, jfloat, /)
	 * m4svm_instruction_operator_222(DDIV, jdouble, jdouble, jdouble, /)
	 * m4svm_instruction_operator_11(INEG, jint, jint, -)
	 * m4svm_instruction_operator_22(LNEG, jlong, jlong, -)
	 * m4svm_instruction_operator_11(FNEG, jfloat, jfloat, -)
	 * m4svm_instruction_operator_22(DNEG, jdouble, jdouble, -)
	 * m4svm_instruction_operator_111(IAND, jint, jint, jint, &)
	 * m4svm_instruction_operator_222(LAND, jlong, jlong, jlong, &)
	 * m4svm_instruction_operator_111(IOR, jint, jint, jint, |)
	 * m4svm_instruction_operator_222(LOR, jlong, jlong, jlong, |)
	 * m4svm_instruction_operator_111(IXOR, jint, jint, jint, ^)
	 * m4svm_instruction_operator_222(LXOR, jlong, jlong, jlong, ^)
	 * m4svm_instruction_operator_12(I2L, jint, jlong)
	 * m4svm_instruction_operator_11(I2F, jint, jfloat)
	 * m4svm_instruction_operator_12(I2D, jint, jdouble)
	 * m4svm_instruction_operator_21(L2I, jlong, jint)
	 * m4svm_instruction_operator_21(L2F, jlong, jfloat)
	 * m4svm_instruction_operator_22(L2D, jlong, jdouble)
	 * m4svm_instruction_operator_11(F2I, jfloat, jint, , JINT)
	 * m4svm_instruction_operator_12(F2L, jfloat, jlong, , JLONG)
	 * m4svm_instruction_operator_12(F2D, jfloat, jdouble)
	 * m4svm_instruction_operator_21(D2I, jdouble, jint, , JINT)
	 * m4svm_instruction_operator_22(D2L, jdouble, jlong, , JLONG)
	 * m4svm_instruction_operator_21(D2F, jdouble, jfloat)
	 * m4svm_instruction_operator_11(I2B, jint, jint, (jbyte))
	 * m4svm_instruction_operator_11(I2C, jint, jint, (jchar))
	 * m4svm_instruction_operator_11(I2S, jint, jint, (jshort)) */

	/* m4_undefine([:m4svm_instruction_operator_111:])
	 * m4_undefine([:m4svm_instruction_operator_222:])
	 * m4_undefine([:m4svm_instruction_operator_11:])
	 * m4_undefine([:m4svm_instruction_operator_22:])
	 * m4_undefine([:m4svm_instruction_operator_12:])
	 * m4_undefine([:m4svm_instruction_operator_21:]) */

/*
----------------------------------------------------------------------
IDIV
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IDIV, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LDIV
----------------------------------------------------------------------
*/

	/* Note: GCC's generated code seems to include a function call
	   or some other kind of branch statement which unfortunately
	   precludes inlining this instruction. */

	m4svm_instruction_head (LDIV, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IREM, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LREM
----------------------------------------------------------------------
*/

	/* Note: GCC's generated code seems to include a function call
	   or some other kind of branch statement which unfortunately
	   precludes inlining this instruction. */

	m4svm_instruction_head (LREM, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FREM, 0);

	{
	  jfloat value1 = stack[stack_size - 2].jfloat;
	  jfloat value2 = stack[--stack_size].jfloat;
	  stack[stack_size - 1].jfloat = _svmm_fmod (value1, value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DREM
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DREM, 0);

	{
	  jdouble value1 = *((jdouble *) (void *) &stack[stack_size - 4]);
	  jdouble value2 = *((jdouble *) (void *) &stack[(stack_size -= 2)]);
	  *((jdouble *) (void *) &stack[stack_size - 2]) =
	    _svmm_fmod (value1, value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ISHL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ISHL, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint = value1 << (value2 & 0x1f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LSHL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LSHL, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    value1 << (value2 & 0x3f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ISHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ISHR, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LSHR, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IUSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IUSHR, 0);

	{
	  jint value1 = stack[stack_size - 2].jint;
	  jint value2 = stack[--stack_size].jint;
	  stack[stack_size - 1].jint =
	    ((_svmt_u32) value1) >> (value2 & 0x1f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LUSHR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LUSHR, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 3]);
	  jint value2 = stack[--stack_size].jint;
	  *((jlong *) (void *) &stack[stack_size - 2]) =
	    ((_svmt_u64) value1) >> (value2 & 0x3f);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LCMP
----------------------------------------------------------------------
*/

	/* Note: GCC's uses branch statements to compare values. */

	m4svm_instruction_head (LCMP, 0);

	{
	  jlong value1 = *((jlong *) (void *) &stack[stack_size - 4]);
	  jlong value2 = *((jlong *) (void *) &stack[stack_size - 2]);
	  stack[(stack_size -= 3) - 1].jint =
	    (value1 > value2) - (value1 < value2);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FCMPL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FCMPL, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
FCMPG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (FCMPG, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DCMPL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DCMPL, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
DCMPG
----------------------------------------------------------------------
*/

	m4svm_instruction_head (DCMPG, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IINC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IINC, 2);

	{
	  jint indx = (pc++)->jint;
	  jint constant = (pc++)->jint;
	  locals[indx].jint +=constant;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IF<X>(_CHECK)
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_if_x:], [: */
	m4svm_instruction_head (IF$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value = stack[--stack_size].jint;

	  if (value $2 0)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_x_check:], [: */
	m4svm_instruction_head (IF$1_CHECK, -1);

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

	  if (value $2 0)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_icmpx:], [: */
	m4svm_instruction_head (IF_ICMP$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  jint value1 = stack[(stack_size -= 2)].jint;
	  jint value2 = stack[stack_size + 1].jint;

	  if (value1 $2 value2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_icmpx_check:], [: */
	m4svm_instruction_head (IF_ICMP$1_CHECK, -1);

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

	  if (value1 $2 value2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_acmpx:], [: */
	m4svm_instruction_head (IF_ACMP$1, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *ref1 = stack[(stack_size -= 2)].reference;
	  _svmt_object_instance *ref2 = stack[stack_size + 1].reference;

	  if (ref1 $2 ref2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_if_acmpx_check:], [: */
	m4svm_instruction_head (IF_ACMP$1_CHECK, -1);

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

	  if (ref1 $2 ref2)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_if_x(EQ, ==)
	 * m4svm_instruction_if_x(NE, !=)
	 * m4svm_instruction_if_x(LT, <)
	 * m4svm_instruction_if_x(LE, <=)
	 * m4svm_instruction_if_x(GT, >)
	 * m4svm_instruction_if_x(GE, >=)
	 * m4svm_instruction_if_icmpx(EQ, ==)
	 * m4svm_instruction_if_icmpx(NE, !=)
	 * m4svm_instruction_if_icmpx(LT, <)
	 * m4svm_instruction_if_icmpx(LE, <=)
	 * m4svm_instruction_if_icmpx(GT, >)
	 * m4svm_instruction_if_icmpx(GE, >=)
	 * m4svm_instruction_if_acmpx(EQ, ==)
	 * m4svm_instruction_if_acmpx(NE, !=) */

	/* m4svm_instruction_if_x_check(EQ, ==)
	 * m4svm_instruction_if_x_check(NE, !=)
	 * m4svm_instruction_if_x_check(LT, <)
	 * m4svm_instruction_if_x_check(LE, <=)
	 * m4svm_instruction_if_x_check(GT, >)
	 * m4svm_instruction_if_x_check(GE, >=)
	 * m4svm_instruction_if_icmpx_check(EQ, ==)
	 * m4svm_instruction_if_icmpx_check(NE, !=)
	 * m4svm_instruction_if_icmpx_check(LT, <)
	 * m4svm_instruction_if_icmpx_check(LE, <=)
	 * m4svm_instruction_if_icmpx_check(GT, >)
	 * m4svm_instruction_if_icmpx_check(GE, >=)
	 * m4svm_instruction_if_acmpx_check(EQ, ==)
	 * m4svm_instruction_if_acmpx_check(NE, !=) */

	/* m4_undefine([:m4svm_instruction_if_x:])
	 * m4_undefine([:m4svm_instruction_if_icmpx:])
	 * m4_undefine([:m4svm_instruction_if_acmpx:]) */

	/* m4_undefine([:m4svm_instruction_if_x_check:])
	 * m4_undefine([:m4svm_instruction_if_icmpx_check:])
	 * m4_undefine([:m4svm_instruction_if_acmpx_check:]) */

/*
----------------------------------------------------------------------
GOTO
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GOTO, 2);

	pc = pc->addr;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
GOTO_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GOTO_CHECK, -1);

	/* skip stack map */
	assert (stack_size >= pc->stack_gc_map->size);
	pc++;

	/* save state */
	env->stack.current_frame->pc = pc;
	env->stack.current_frame->stack_size = stack_size;

	/* check */
	_svmf_periodic_check (env);

	pc = pc->addr;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
JSR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (JSR, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  stack[stack_size++].addr = pc;
	  pc = destination;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
JSR_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (JSR_CHECK, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
RET
----------------------------------------------------------------------
*/

	m4svm_instruction_head (RET, 1);

	{
	  jint indx = pc->jint;
	  pc = locals[indx].addr;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
TABLESWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (TABLESWITCH, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (TABLESWITCH_CHECK, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LOOKUPSWITCH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LOOKUPSWITCH, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LOOKUPSWITCH_CHECK, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<X>RETURN
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_xreturn:], [: */
	m4svm_instruction_head ($1RETURN, 0);

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
	  m4svm_$1return_assign;

	  locals = (_svmt_stack_value *) (void *)
	    (((char *) frame) - caller_method->frame_info->start_offset);
	  stack = (_svmt_stack_value *) (void *)
	    (((char *) frame) + _svmv_stack_offset);
	  stack_size = frame->stack_size + m4svm_$1return_size;
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

	m4svm_instruction_tail ();
	/* :]) */

/*
m4_define([:m4svm_return_assign:],[:[:m4_:]dnl:])m4_dnl
m4_define([:m4svm_Ireturn_assign:],[:locals[0].jint = stack[stack_size - 1].jint:])m4_dnl
m4_define([:m4svm_Freturn_assign:],[:locals[0].jfloat = stack[stack_size - 1].jfloat:])m4_dnl
m4_define([:m4svm_Areturn_assign:],[:locals[0].reference = stack[stack_size - 1].reference:])m4_dnl
m4_define([:m4svm_Lreturn_assign:],[:*((jlong *) (void *) &locals[0]) = *((jlong *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_Dreturn_assign:],[:*((jdouble *) (void *) &locals[0]) = *((jdouble *) (void *) &stack[stack_size - 2]):])m4_dnl
m4_define([:m4svm_return_size:],[:0:])m4_dnl
m4_define([:m4svm_Ireturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Freturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Areturn_size:],[:1:])m4_dnl
m4_define([:m4svm_Lreturn_size:],[:2:])m4_dnl
m4_define([:m4svm_Dreturn_size:],[:2:])m4_dnl
m4svm_instruction_xreturn(I)
m4svm_instruction_xreturn(L)
m4svm_instruction_xreturn(F)
m4svm_instruction_xreturn(D)
m4svm_instruction_xreturn(A)
m4svm_instruction_xreturn()
m4_undefine([:m4svm_instruction_xreturn:])
m4_undefine([:m4svm_return_assign:])
m4_undefine([:m4svm_Ireturn_assign:])
m4_undefine([:m4svm_Freturn_assign:])
m4_undefine([:m4svm_Areturn_assign:])
m4_undefine([:m4svm_Lreturn_assign:])
m4_undefine([:m4svm_Dreturn_assign:])
m4_undefine([:m4svm_return_size:])
m4_undefine([:m4svm_Ireturn_size:])
m4_undefine([:m4svm_Freturn_size:])
m4_undefine([:m4svm_Areturn_size:])
m4_undefine([:m4svm_Lreturn_size:])
m4_undefine([:m4svm_Dreturn_size:])
*/

/*
----------------------------------------------------------------------
INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKEVIRTUAL, 2);

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

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKESPECIAL, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKESTATIC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKESTATIC, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INVOKEINTERFACE, 4);

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

	  m4svm_expect_sigsegv ();

	  /* the following can cause a segfault */
	  method =
	    *((_svmt_method_info **) (void *)
	      (((char *) instance->vtable) + method_offset));

	  m4svm_dont_expect_sigsegv ();

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NEW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NEW, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ARRAYLENGTH
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ARRAYLENGTH, 0);

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

	  m4svm_expect_sigsegv ();

	  /* can cause sigsegv on NULL array ref */
	  stack[stack_size - 1].jint = array->size;

	  m4svm_dont_expect_sigsegv ();

	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ATHROW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ATHROW, 0);

	{
	  *(env->throwable) = stack[stack_size - 1].reference;

	  env->stack.current_frame->pc = pc;

	  _svmm_goto_label (athrow_handler);
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
CHECKCAST
----------------------------------------------------------------------
*/

	m4svm_instruction_head (CHECKCAST, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INSTANCEOF
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INSTANCEOF, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MONITORENTER
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MONITORENTER, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MONITOREXIT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MONITOREXIT, 0);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNULL, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference == NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNULL_CHECK, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNONNULL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNONNULL, 2);

	{
	  _svmt_code *destination = (pc++)->addr;
	  _svmt_object_instance *reference = stack[--stack_size].reference;

	  if (reference != NULL)
	    {
	      pc = destination;
	    }
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
IFNONNULL_CHECK
----------------------------------------------------------------------
*/

	m4svm_instruction_head (IFNONNULL_CHECK, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
LINK_NATIVE_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (LINK_NATIVE_METHOD, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ABSTRACT_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ABSTRACT_METHOD, -1);

	_svmm_goto_label (abstractmethoderror_handler);

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NATIVE_STATIC_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NATIVE_STATIC_METHOD, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NATIVE_NONSTATIC_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NATIVE_NONSTATIC_METHOD, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
<GET/PUT><FIELD/STATIC>_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_getfield_x:], [: */
	m4svm_instruction_head (GETFIELD_$1, -1);

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

	  m4svm_expect_sigsegv ();

	  stack[stack_size - 1].$2 =
	    *(($3 *) (void *) (((char *) instance) + offset));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getfield_x2:], [: */
	m4svm_instruction_head (GETFIELD_$1, -1);

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

	  m4svm_expect_sigsegv ();

	  *(($2 *) (void *) &stack[stack_size++ - 1]) =
	    *(($2 *) (void *) (((char *) instance) + offset));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_getfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_getfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_getfield_x(INT, jint, jint)
	 * m4svm_instruction_getfield_x2(LONG, jlong)
	 * m4svm_instruction_getfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_getfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_getfield_x:])
	 * m4_undefine([:m4svm_instruction_getfield_x2:]) */

	/* m4_define([:m4svm_instruction_putfield_x:], [: */
	m4svm_instruction_head (PUTFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  $3 value = stack[--stack_size].$2;
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

	  m4svm_expect_sigsegv ();

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	  _svmf_put_$1_field (env, instance, offset, value);
#else
	  _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putfield_x2:], [: */
	m4svm_instruction_head (PUTFIELD_$1, -1);

	{
	  size_t offset = (pc++)->offset;
	  $2 value = *(($2 *) (void *) &stack[(stack_size -= 2)]);
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

	  m4svm_expect_sigsegv ();

	  *(($2 *) (void *) (((char *) instance) + offset)) = value;

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_putfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_putfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_putfield_x(INT, jint, jint)
	 * m4svm_instruction_putfield_x2(LONG, jlong)
	 * m4svm_instruction_putfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_putfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_putfield_x:])
	 * m4_undefine([:m4svm_instruction_putfield_x2:]) */

	/* m4_define([:m4svm_instruction_getstatic_x:], [: */
	m4svm_instruction_head (GETSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].$2 = pvalue->$3;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getstatic_x2:], [: */
	m4svm_instruction_head (GETSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(($2 *) (void *) &stack[stack_size]) = pvalue->$3;
	  stack_size += 2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getstatic_x(BOOLEAN, jint, z)
	 * m4svm_instruction_getstatic_x(BYTE, jint, b)
	 * m4svm_instruction_getstatic_x(SHORT, jint, s)
	 * m4svm_instruction_getstatic_x(CHAR, jint, c)
	 * m4svm_instruction_getstatic_x(INT, jint, i)
	 * m4svm_instruction_getstatic_x2(LONG, jlong, j)
	 * m4svm_instruction_getstatic_x(FLOAT, jfloat, f)
	 * m4svm_instruction_getstatic_x2(DOUBLE, jdouble, d) */

	/* m4_undefine([:m4svm_instruction_getstatic_x:])
	 * m4_undefine([:m4svm_instruction_getstatic_x2:]) */

	/* m4_define([:m4svm_instruction_putstatic_x:],  [: */
	m4svm_instruction_head (PUTSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->$3 = stack[--stack_size].$2;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putstatic_x2:], [: */
	m4svm_instruction_head (PUTSTATIC_$1, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  pvalue->$3 = *(($2 *) (void *) &stack[(stack_size -= 2)]);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putstatic_x(BOOLEAN, jint, z)
	 * m4svm_instruction_putstatic_x(BYTE, jint, b)
	 * m4svm_instruction_putstatic_x(SHORT, jint, s)
	 * m4svm_instruction_putstatic_x(CHAR, jint, c)
	 * m4svm_instruction_putstatic_x(INT, jint, i)
	 * m4svm_instruction_putstatic_x2(LONG, jlong, j)
	 * m4svm_instruction_putstatic_x(FLOAT, jfloat, f)
	 * m4svm_instruction_putstatic_x2(DOUBLE, jdouble, d)

	 /* m4_undefine([:m4svm_instruction_putstatic_x:])
	 * m4_undefine([:m4svm_instruction_putstatic_x2:]) */

/*
----------------------------------------------------------------------
GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GETFIELD_BOOLEAN, -1);

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

	  m4svm_expect_sigsegv ();

	  stack[stack_size - 1].jint =
	    (((_svmt_u8 *) instance)[offset / 8] >> (offset % 8)) & 1;

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PUTFIELD_BOOLEAN, -1);

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

	  m4svm_expect_sigsegv ();

	  /* to avoid conditional jumps we use boolean arithmetic */
	  ((_svmt_u8 *) instance)[offset / 8] |= (value << (offset % 8));
	  ((_svmt_u8 *) instance)[offset / 8] &= ~(nvalue << (offset % 8));

	  m4svm_dont_expect_sigsegv ();
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (GETSTATIC_REFERENCE, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  stack[stack_size++].reference = *(pvalue->l);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	  assert (stack[stack_size - 1].reference == NULL ||
		  strcmp (stack[stack_size - 1].reference->magic,
			  "SableVM") == 0);
#endif
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PUTSTATIC_REFERENCE, -1);

	{
	  jvalue *pvalue = (pc++)->pvalue;
	  *(pvalue->l) = stack[--stack_size].reference;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	  _svmf_write_barrier (env, (_svmt_object_instance **) pvalue->l);
#endif /* _SABLEVM_GC_WRITE_BARRIER */
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ASTORE_RET
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ASTORE_RET, 1);

	{
	  jint indx = (pc++)->jint;
	  locals[indx].addr = stack[--stack_size].addr;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ASTORE_RET_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_astore_ret_x:], [: */
	m4svm_instruction_head (ASTORE_RET_$1, -1);

	{
	  locals[$1].addr = stack[--stack_size].addr;
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_astore_ret_x(0)
	 * m4svm_instruction_astore_ret_x(1)
	 * m4svm_instruction_astore_ret_x(2)
	 * m4svm_instruction_astore_ret_x(3) */

	/* m4_undefine([:m4svm_instruction_astore_ret_x:]) */

/*
----------------------------------------------------------------------
NEXT
----------------------------------------------------------------------
*/

	m4svm_instruction_head (NEXT, -1);

#ifdef _SABLEVM_INLINED_THREADED_INTERPRETER

	_svmf_goto ((pc++)->implementation);

#endif

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
NEWARRAY_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_newarray_x:], [: */
	m4svm_instruction_head (NEWARRAY_$1, -1);

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
	      (env, vm->class_loading.boot_loader.classes.$2_array,
	       count, instance) != JNI_OK)
	    {
	      _svmm_goto_label (exception_handler);
	    }

	  stack[stack_size++].reference =
	    _svmf_cast_object_instance (instance);
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_newarray_x(BOOLEAN, boolean)
	 * m4svm_instruction_newarray_x(BYTE, byte)
	 * m4svm_instruction_newarray_x(SHORT, short)
	 * m4svm_instruction_newarray_x(CHAR, char)
	 * m4svm_instruction_newarray_x(INT, int)
	 * m4svm_instruction_newarray_x(LONG, long)
	 * m4svm_instruction_newarray_x(FLOAT, float)
	 * m4svm_instruction_newarray_x(DOUBLE, double) */

	/* m4_undefine([:m4svm_instruction_newarray_x:]) */

/*
----------------------------------------------------------------------
ANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ANEWARRAY, 2);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
MULTIANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (MULTIANEWARRAY, 3);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
ERROR
----------------------------------------------------------------------
*/

	m4svm_instruction_head (ERROR, -1);

	_svmm_fatal_error ("grave internal VM error");

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
INTERNAL_CALL_END
----------------------------------------------------------------------
*/

	m4svm_instruction_head (INTERNAL_CALL_END, -1);

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)
	env->signal_handler = previous_signal_handler;
#endif
	return (*(env->throwable) == NULL) ? JNI_OK : JNI_ERR;

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
SKIP
----------------------------------------------------------------------
*/

	m4svm_instruction_head (SKIP, -1);

	pc++;			/* skip preparation address */

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
REPLACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (REPLACE, -1);

	{
	  _svmt_code *addr = (pc++)->addr;
	  _svmt_code code = *(pc++);

	  *addr = code;
	}

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_METHOD
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_METHOD, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_LDC_STRING
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_LDC_STRING, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_<GET/PUT><FIELD/STATIC>_<X>
----------------------------------------------------------------------
*/

	/* m4_define([:m4svm_instruction_getfield_x:], [: */
	m4svm_instruction_head (PREPARE_GETFIELD_$1, -1);

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

	    stack[stack_size - 1].$2 = _svmf_get_$1_field (instance, offset);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getfield_x2:], [: */
	m4svm_instruction_head (PREPARE_GETFIELD_$1, -1);

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

	    *(($2 *) (void *) &stack[stack_size++ - 1]) =
	      _svmf_get_$1_field (instance, offset);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getfield_x(BOOLEAN, jint)
	 * m4svm_instruction_getfield_x(BYTE, jint)
	 * m4svm_instruction_getfield_x(SHORT, jint)
	 * m4svm_instruction_getfield_x(CHAR, jint)
	 * m4svm_instruction_getfield_x(INT, jint)
	 * m4svm_instruction_getfield_x2(LONG, jlong)
	 * m4svm_instruction_getfield_x(FLOAT, jfloat)
	 * m4svm_instruction_getfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getfield_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_getfield_x:])
	 * m4_undefine([:m4svm_instruction_getfield_x2:]) */

	/* m4_define([:m4svm_instruction_putfield_x:], [: */
	m4svm_instruction_head (PREPARE_PUTFIELD_$1, -1);

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
	    $3 value = stack[--stack_size].$2;
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	    _svmf_put_$1_field (env, instance, offset, value);
#else
	    _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */

	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putfield_x2:], [: */
	m4svm_instruction_head (PREPARE_PUTFIELD_$1, -1);

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
	    $2 value = *(($2 *) (void *) &stack[(stack_size -= 2)]);
	    _svmt_object_instance *instance = stack[--stack_size].reference;

	    if (instance == NULL)
	      {
		goto nullpointerexception_handler;
	      }

/* Note: only SVM_PUT_REFERENCE_FIELD is ever defined */
#if defined(SVM_PUT_$1_FIELD)
	    _svmf_put_$1_field (env, instance, offset, value);
#else
	    _svmf_put_$1_field (instance, offset, value);
#endif /* SVM_PUT_$1_FIELD */
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putfield_x(BOOLEAN, jint, jboolean)
	 * m4svm_instruction_putfield_x(BYTE, jint, jbyte)
	 * m4svm_instruction_putfield_x(SHORT, jint, jshort)
	 * m4svm_instruction_putfield_x(CHAR, jint, jchar)
	 * m4svm_instruction_putfield_x(INT, jint, jint)
	 * m4svm_instruction_putfield_x2(LONG, jlong)
	 * m4svm_instruction_putfield_x(FLOAT, jfloat, jfloat)
	 * m4svm_instruction_putfield_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putfield_x(REFERENCE, reference, _svmt_object_instance *) */

	/* m4_undefine([:m4svm_instruction_putfield_x:])
	 * m4_undefine([:m4svm_instruction_putfield_x2:]) */

	/* m4_define([:m4svm_instruction_getstatic_x:], [: */
	m4svm_instruction_head (PREPARE_GETSTATIC_$1, -1);

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
	    stack[stack_size++].$2 = _svmf_get_$1_static (pvalue);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_getstatic_x2:], [: */
	m4svm_instruction_head (PREPARE_GETSTATIC_$1, -1);

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
	    *(($2 *) (void *) &stack[stack_size]) =
	      _svmf_get_$1_static (pvalue);
	    stack_size += 2;
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_getstatic_x(BOOLEAN, jint)
	 * m4svm_instruction_getstatic_x(BYTE, jint)
	 * m4svm_instruction_getstatic_x(SHORT, jint)
	 * m4svm_instruction_getstatic_x(CHAR, jint)
	 * m4svm_instruction_getstatic_x(INT, jint)
	 * m4svm_instruction_getstatic_x2(LONG, jlong)
	 * m4svm_instruction_getstatic_x(FLOAT, jfloat)
	 * m4svm_instruction_getstatic_x2(DOUBLE, jdouble)
	 * m4svm_instruction_getstatic_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_getstatic_x:])
	 * m4_undefine([:m4svm_instruction_getstatic_x2:]) */

	/* m4_define([:m4svm_instruction_putstatic_x:],  [: */
	m4svm_instruction_head (PREPARE_PUTSTATIC_$1, -1);

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
	    _svmf_put_$1_static (pvalue, stack[--stack_size].$2);
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4_define([:m4svm_instruction_putstatic_x2:], [: */
	m4svm_instruction_head (PREPARE_PUTSTATIC_$1, -1);

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
	    _svmf_put_$1_static (pvalue,
				 *(($2 *) (void *)
				   &stack[(stack_size -= 2)]));
	  }
	}

	m4svm_instruction_tail ();
	/* :]) */

	/* m4svm_instruction_putstatic_x(BOOLEAN, jint)
	 * m4svm_instruction_putstatic_x(BYTE, jint)
	 * m4svm_instruction_putstatic_x(SHORT, jint)
	 * m4svm_instruction_putstatic_x(CHAR, jint)
	 * m4svm_instruction_putstatic_x(INT, jint)
	 * m4svm_instruction_putstatic_x2(LONG, jlong)
	 * m4svm_instruction_putstatic_x(FLOAT, jfloat)
	 * m4svm_instruction_putstatic_x2(DOUBLE, jdouble)
	 * m4svm_instruction_putstatic_x(REFERENCE, reference) */

	/* m4_undefine([:m4svm_instruction_putstatic_x:])
	 * m4_undefine([:m4svm_instruction_putstatic_x2:]) */

/*
----------------------------------------------------------------------
PREPARE_CHECKCAST
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_CHECKCAST, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INSTANCEOF
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INSTANCEOF, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_NEW
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_NEW, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_ANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_ANEWARRAY, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_MULTIANEWARRAY
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_MULTIANEWARRAY, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKEVIRTUAL, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKESPECIAL
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKESPECIAL, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKESTATIC
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKESTATIC, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
PREPARE_INVOKEINTERFACE
----------------------------------------------------------------------
*/

	m4svm_instruction_head (PREPARE_INVOKEINTERFACE, -1);

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

	m4svm_instruction_tail ();

/*
----------------------------------------------------------------------
End of instructions
----------------------------------------------------------------------
*/

      }
    }
}
