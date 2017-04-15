/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined(_SABLEVM_INLINED_THREADED_INTERPRETER)

/* NOTE: architectures are in *alphabetical* order */

#if defined(__alpha) || defined(__arm__) || defined(__i386__) || \
    defined(__hppa__) || defined(__ia64__) || defined (__m68k__) || \
    defined (__mc68000__) || defined(__powerpc__) || defined(__s390__) \
    || defined(__sparc__) || defined (_POWER)

#define _svmm_goto_label(towhere) _svmf_goto(&&towhere)

static inline void
_svmf_goto (register const void *target)
{
#if   defined(__alpha__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	jmp	$31,(%0) \n\t"
			"	"::"g" (target));
/* *INDENT-ON* */

#elif defined(__arm__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	mov	pc, %0 \n\t"
			"	"::"r" (target));
/* *INDENT-ON* */

#elif defined(__hppa__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("      bv,n    %%r0(%0) \n" 
                        "       "::"r" (target));
/* *INDENT-ON* */

#elif defined(__i386__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	jmp	*%0 \n\t"
			"	"::"r" (target));
/* *INDENT-ON* */

#elif defined(__ia64__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	mov	b6 = %0 \n\t"
			"	br	b6 \n\t"
			"	"::"r" (target));			  
/* *INDENT-ON* */

#elif defined (__m68k__) || defined (__mc68000__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	jmp	%0@ \n\t"
			"	"::"a" (target));
/* *INDENT-ON* */

#elif defined(__powerpc__) || defined (_POWER)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	mtctr %0 \n\t"
			"	bctr \n\t"
			"	"::"r" (target));
/* *INDENT-ON* */

#elif defined(__s390__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	br	%0 \n\t"
                        "	"::"r" (target));
/* *INDENT-ON* */

#elif defined(__sparc__)

/* *INDENT-OFF* */
  __asm__ __volatile__ ("	jmp  %0 \n\t"
			"	nop \n\t"
			"	"::"r" (target));
/* *INDENT-ON* */

#endif
}
#else /* not in architectures list */

/* #warning doesn't seem to be part of standard C */
#if defined (__GNUC__)
#warning There is  NO _svmf_goto defined for your architecture and
#warning you are compiling an INLINED version of SableVM.
#warning It might result in program crashing!!!
#endif

#define _svmm_goto_label(towhere) goto towhere

#endif /* architectures list */

#else /* defined(_SABLEVM_INLINED_THREADED_INTERPRETER) */

#define _svmm_goto_label(towhere) goto towhere

#endif
