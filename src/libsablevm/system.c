/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#if defined (HAS_SYSTEM_CLEAR_CACHE)
/* A clever hack to avoid time consuming writing of an optimized
 * cache flush instruction for every architecture in the world.
 * Unfotunatelly it won't work w/o GCC (GBP) */
extern void __clear_cache (char *beg, char *end);
#endif

/* Beware: Architecture-specific pieces are in *alphabetical* order */
#if (( defined (__sparc__) || defined (__ia64__) || defined (__alpha__) \
    || defined (__i386__) || defined (__powerpc__) || defined (__s390__) \
    || defined (__hppa__) || defined (__arm__) || defined (__m68k__) \
    || defined (__mc68000__) || defined (__mips__) || defined (__mipsel__) \
    || defined (__x86_64__) || defined (_POWER)  \
     ) && defined (__GNUC__))

/*
----------------------------------------------------------------------
_svmf_iflush
----------------------------------------------------------------------
*/

/* This function updates the word "*pword" (pointed to by pword) in
   the INSTRUCTION cache, on processors with separate data and
   instruction caches.  This a requirement for getting the
   inline-threading engine to work on such relatively common
   processors. */

svm_static inline void
_svmf_iflush (_svmt_word *pword SVM_UNUSED)
{
/* *INDENT-OFF* */
#if defined (__alpha__)

  /* 134 is the code for IMB.  I am not sure if after below code we
     don't need another 44 NOP instructions beggining byte16 aligned
     (whatever that means) helpful:
     http://www.atomised.org/docs/XFree86-4.2.1/compiler_8h-source.html
     I was told that "call_pal %0 imb" costs about 300 CPU cycles and
     that first memory barrier "mb" is probably not needed. (GBP) */

  __asm__ __volatile__ ("mb; call_pal %0 #imb"::"i" (134):"memory");

#elif defined (__hppa__)

  __asm__ __volatile__ ("fdc 0(%0)\n"
                       "fic 0(%%sr4, %0)\n"
                       "sync\n" 
                       :: "r" ((unsigned long)pword & ~63) : "memory");

#elif defined (__i386__)
  /* do nothing */
#elif defined (__ia64__)

  /* also based on the above "helpful" address, so I think it's OK. (GBP) */
  __asm__ __volatile__ ("fc %0;;; sync.i;;; mf;;; srlz.i;;;"::
			"r" (pword):"memory");

#elif defined (__powerpc__) || defined (_POWER)

  __asm__ __volatile__ ("dcbst 0,%0\n\t"
			"sync\n\t"
			"icbi 0,%0\n\t"
			"isync" : : "r" (pword));

#elif defined (__sparc__)

  /* http://www.wcug.wwu.edu/lists/smpdev/199702/msg00023.html
     http://www.haskell.org/pipermail/glasgow-haskell-bugs/2002-April/002345.html
     In fact the flush instruction flushes *two* words. It may take up to 5
     instructions before the flush is visible but it might work w/o it - for
     SableVM I doubt the flushed code will be exectued before any 5 other
     assembler intructions? */

  __asm__ __volatile__ ("flush %0; nop; nop; nop; nop; nop;" : : "r" (pword));

/* ARM version: 
  http://cvs.perl.org/cgi/viewcvs.cgi/parrot/jit/arm/jit_emit.h?rev=1.18
*/
			         
#elif defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
#if defined (HAS_SYSTEM_CLEAR_CACHE)
  __clear_cache((char *) pword, (char *) (pword + 1));
#else
#error "SableVM is not prepared to run the inlined threaded interpreter on this kind of a system or __clear_cache is not available."
#endif
#endif
/* *INDENT-ON* */
}

/*
----------------------------------------------------------------------
_svmh_compare_and_swap
----------------------------------------------------------------------
*/

#define _svmm_compare_and_swap(word, old_value, new_value) \
_svmh_compare_and_swap (&word, old_value, new_value)

/* this function ATOMICALLY does the following:

   if (*pword == old_value)
     {
       *pword = new_value;
       return 1;
     }
   else
     {
       return 0;
     }
*/

svm_static inline jboolean
_svmh_compare_and_swap (volatile _svmt_word *pword, _svmt_word old_value,
			_svmt_word new_value)
{
  /* Yes, some inline assembly source code... Unfortunaltely, this
     cannot be expressed in C. */

#if defined (__alpha__)
  register _svmt_word result, tmp;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("1:  mb\n\t"			/* make sure */
			"    ldq_l      %1,%4\n\t"	/* load *pword into tmp (reg,<= mem) */
			"    cmpeq      %1,%5,%0\n\t"	/* result = (*pword == tmp) */
			"    beq        %0,3f\n\t"	/* nothing to do if they differ(0) - jump away */
			"    mov        %3,%1\n\t"	/* copy tmp<=new so that we didnt lose it */
			"    stq_c      %1,%4\n\t"	/* *pword = new_value (reg,=> mem) */
			"    beq        %1,2f\n\t"	/* store could fail! (%1 overwritten!) */
			"    mb\n\t"			/* make sure */
			"    br         3f\n\t"		/* were done */
			"2:  br         1b\n\t"		/* goto "again" */
			"3:  nop"
			:"=&r" (result), "=&r" (tmp), "=m" (*pword)
			:"r" (new_value), "m" (*pword), "r" (old_value));
/* *INDENT-ON* */

#elif defined (__arm__)
  /* borrowed from glibc so is LGPL - file atomicity.h for arm (GBP) */
  int result, tmp;
/* *INDENT-OFF* */
	__asm__ ("\n"
           "0:\tldr\t%1,[%2]\n\t"
           "mov\t%0,#0\n\t"
           "cmp\t%1,%4\n\t"
           "bne\t1f\n\t"
           "swp\t%0,%3,[%2]\n\t"
           "cmp\t%1,%0\n\t"
           "swpne\t%1,%0,[%2]\n\t"
           "bne\t0b\n\t"
           "mov\t%0,#1\n"
           "1:"
           : "=&r" (result), "=&r" (tmp)
           : "r" (pword), "r" (new_value), "r" (old_value)
           : "cc", "memory");
/* *INDENT-ON* */

#elif defined (__hppa__)

  /* The only atomic insn available on hppa is "load and clear";
   * locks are initialized to 1 on hppa. In this simple implementation
   * we use a global lock to make compare-and-swap atomic
   */

#define __ldcw(a) ({ \
    unsigned int __ret; \
    __asm__ __volatile__("ldcw 0(%1),%0" : "=r" (__ret) : "r" (a)); \
    __ret; \
  })

  static struct
  {
    volatile unsigned int __attribute__ ((aligned (16))) lock;
  } lock;

  static int lock_initialized = 0;
  int result;

  if (!lock_initialized)
    {
      lock.lock = 1;
    }

  /* spinlock */
  while (__ldcw (&lock.lock) == 0);
  if (*pword == old_value)
    {
      *pword = new_value;
      result = 1;
    }
  else
    {
      result = 0;
    }
  /* unlock */
  lock.lock = 1;
  /* Prevent reordering */
  __asm__ __volatile__ ("":::"memory");

#elif defined (__i386__)

  /* On the ia32, cmpxchgl has a side effect.  When swapping fails,
     the following variable contains the value that is currently in
     *pword (presumably different from old_value). */

  _svmt_word current_value;
  _svmt_u8 result;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("lock\n\t"
			"cmpxchgl %3, %1\n\t"
			"sete %0"
			:"=q" (result), "=m" (*pword), "=a" (current_value)
			:"r" (new_value), "m" (*pword), "a" (old_value)
			:"memory");
/* *INDENT-ON* */

#elif defined (__ia64__)

#include <ia64intrin.h>

  jboolean result;
  result = __sync_bool_compare_and_swap (pword, old_value, new_value);

#elif defined (__m68k__) || defined (__mc68000__)

  /* borrowed from glibc so is LGPL - file atomicity.h for m68k (GBP) */

  char result;
  long int readval;

/* *INDENT-OFF* */

  __asm__ __volatile__ ("cas%.l %2,%3,%1; seq %0"
                        : "=dm" (result), "=m" (*pword), "=d" (readval)
                        : "d" (new_value), "m" (*pword), "2" (old_value));
/* *INDENT-ON* */

#elif defined (__mips__) || defined (__mipsel__)

  /* borrowed from glibc so is LGPL - file atomicity.h for mips (GBP) */

  long int result, temp;

/* *INDENT-OFF* */
  __asm__ __volatile__
    ("/* Inline compare & swap */\n"
     "1:\n\t"
     ".set      push\n\t"
     ".set      mips2\n\t"
     "ll        %1,%5\n\t"
     "move      %0,$0\n\t"
     "bne       %1,%3,2f\n\t"
     "move      %0,%4\n\t"
     "sc        %0,%2\n\t"
     ".set      pop\n\t"
     "beqz      %0,1b\n"
     "2:\n\t"
     "/* End compare & swap */"
     : "=&r" (result), "=&r" (temp), "=m" (*pword)
     : "r" (old_value), "r" (new_value), "m" (*pword)
     : "memory");
/* *INDENT-ON* */

#elif defined (__powerpc__)

  int result;

  /*
   * Adapted from the glibc-linuxthreads, file pt-machine.h
   */

/* *INDENT-OFF* */
  __asm__ __volatile__ ("0:    lwarx %0,0,%1\n\t"
			"      xor. %0,%3,%0\n\t"
			"      bne 1f\n\t"
			"      stwcx. %2,0,%1\n\t"
			"      bne- 0b\n\t"
			"1:    ":"=&r" (result):"r" (pword), "r" (new_value),
			"r" (old_value):"cr0", "memory");
  /* This version of __compare_and_swap is to be used when acquiring
     a lock, so we don't need to worry about whether other memory
     operations have completed, but we do need to be sure that any loads
     after this point really occur after we have acquired the lock.  */
  __asm__ __volatile__ ("isync" : : : "memory");
/* *INDENT-ON* */

  /* flip the value of result */
  result = !result;

#elif defined (_POWER)

  int result;

  /*
   * Adapted from the glibc-linuxthreads, file pt-machine.h
   */

/* *INDENT-OFF* */
  __asm__ __volatile__ ("SVM0:    lwarx %0,0,%1\n\t"
			"      xor. %0,%3,%0\n\t"
			"      bne SVM1\n\t"
			"      stwcx. %2,0,%1\n\t"
			"      bne- SVM0\n\t"
			"SVM1:    ":"=&r" (result):"r" (pword), "r" (new_value),
			"r" (old_value):"cr0", "memory");
  /* This version of __compare_and_swap is to be used when acquiring
     a lock, so we don't need to worry about whether other memory
     operations have completed, but we do need to be sure that any loads
     after this point really occur after we have acquired the lock.  */
  __asm__ __volatile__ ("isync" : : : "memory");
/* *INDENT-ON* */

  /* flip the value of result */
  result = !result;

#elif defined (__s390__)

  /* borrowed from glibc so is LGPL - file atomicity.h for s390-32 (GBP) */

  int result;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("  la   1,%1\n"
                        "  lr   0,%2\n"
                        "  cs   0,%3,0(1)\n"
                        "  ipm  %0\n"
                        "  srl  %0,28\n"
                        "0:"
                        : "=&r" (result), "+m" (*pword)
                        : "d" (old_value) , "d" (new_value)
                        : "memory", "0", "1", "cc");
/* *INDENT-ON* */

  result = !result;

#elif defined (__sparc__)

/* Unfortunatelly we have to use the simplest CPU instruction set if
 * we don't want to see errors like:
 * ... (Requires v9|v9a|v9b; requested architecture is sparclite.)
 * There may be some filed for improvements here.
 * Code borrowed from glibc atomicity.h for sparc32 (GBP) */

  register long int result, tmp2;

/* *INDENT-OFF* */
  static unsigned char lock;
  __asm__ __volatile__ ("1:      ldstub  [%1], %0\n\t"
                        "        cmp     %0, 0\n\t"
                        "        bne     1b\n\t"
                        "         nop"
                        : "=&r" (tmp2)
                        : "r" (&lock)
                        : "memory");
  if (*pword != old_value)
     result = 0;
  else {
     *pword = new_value;
     result = 1;
  }
  __asm__ __volatile__ ("stb     %%g0, [%0]"
                        : /* no outputs */
                        : "r" (&lock)
                        : "memory");
/* *INDENT-ON* */

#elif defined (__x86_64__)

  _svmt_word current_value;
  _svmt_u8 result;

/* *INDENT-OFF* */
  __asm__ __volatile__ ("lock\n\t"
                        "cmpxchgq %3, %1\n\t"
                        "sete %0"
                        :"=q" (result), "=m" (*pword), "=a" (current_value)
                        :"r" (new_value), "m" (*pword), "a" (old_value)
                        :"memory");
/* *INDENT-ON* */

#else
#error "SableVM is not prepared to run on this kind of a system; no atomic compare&swap defined."
#endif

  return result ? JNI_TRUE : JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_calloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

static void *
_svmf_calloc (size_t nmemb, size_t size)
{
  return calloc (nmemb, size);
}

/*
----------------------------------------------------------------------
_svmf_realloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

static void *
_svmf_realloc (void *ptr, size_t size)
{
  return realloc (ptr, size);
}

/*
----------------------------------------------------------------------
_svmf_malloc
----------------------------------------------------------------------
*/

/* must return aligned memory */

static void *
_svmf_malloc (size_t size)
{
  return malloc (size);
}

/*
----------------------------------------------------------------------
_svmf_free
----------------------------------------------------------------------
*/

static void
_svmf_free (void *ptr)
{
  free (ptr);
}

/*
----------------------------------------------------------------------
_svmf_prepare_class_lockword
----------------------------------------------------------------------
*/

/* lockword layout (high to low bits):
     1  : fat(1) / thin(0)
     15 :
       thin:
         10 : thread ID (min value = 0x0001, max value = 0x03ff)
	      (value = 0 means that the object is unlocked)
         5  : recursion count (min value = 0x000, max value = 0x01f)
       fat:
         15 : lock ID (min value = 0x00000, max value = 0x07fff)

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

     6 : start offset div alignment (overflow value = 0x03f)
     6 : end offset div alignment (overflow value = 0x03f) [add 1 if hash_moved]
     2 : no-hash(0x00) / hash-notmoved (0x01) / hash-moved (0x02)
     1 : non-array(0x0)
     1 : always 1 (to deferentiate header word from ptr)

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

     1 : unused (0)
     3 : end offset div alignment [add 1 if hash_moved]
     7 : reference fields bit layout
     1 : info in header (0) / overflow (1)
     2 : no-hash(0x00) / hash-notmoved (0x01) / hash-moved (0x02)
     1 : non-array(0x0)
     1 : always 1 (to deferentiate header word from ptr)

So, if a class type has a maximum of 12 words of fields, the layout of
reference fields is embedded in the object header.

#endif

*/

svm_static void
_svmf_prepare_class_lockword (_svmt_class_info *class)
{
  _svmt_word lockword = 0;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)
  _svmt_word start = class->data.noninterface.start_offset / SVM_ALIGNMENT;
  _svmt_word end =
    (class->data.noninterface.next_offset_no_hashcode - _svmf_aligned_size_t
     (sizeof (_svmt_object_instance))) / SVM_ALIGNMENT;

  if (start > SVM_LOCKWORD_START_OVERFLOW)
    {
      start = SVM_LOCKWORD_START_OVERFLOW;
    }

  if (end > SVM_LOCKWORD_END_OVERFLOW)
    {
      end = SVM_LOCKWORD_END_OVERFLOW;
    }

  lockword = start << 10;
  lockword |= end << 4;
  lockword |= 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  _svmt_word end =
    (class->data.noninterface.next_offset_no_hashcode - _svmf_aligned_size_t
     (sizeof (_svmt_object_instance))) / sizeof (void *);
  _svmt_word offsets = 0;
  const size_t head_size =
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));
  jint i;
  jint ref_field_count = class->data.noninterface.ref_field_count;
  size_t *ref_field_offsets = class->data.noninterface.ref_field_offsets;
  jboolean overflow = JNI_FALSE;

  if (end > 7)
    {
      overflow = JNI_TRUE;
    }
  else
    {
      for (i = 0; i < ref_field_count; i++)
	{
	  size_t bit = (ref_field_offsets[i] - head_size) / sizeof (void *);

	  assert (bit < 7);

	  offsets |= ((_svmt_word) 1) << bit;
	}
    }

  if (overflow)
    {
      lockword = 1 << 4;
    }
  else
    {
      lockword = end << 12;
      lockword |= offsets << 5;
    }

  lockword |= 0x01;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  assert (!_svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE));

  class->data.noninterface.initial_lockword = lockword;
}

/*
----------------------------------------------------------------------
_svmf_prepare_array_lockword
----------------------------------------------------------------------
*/

/* lockword layout (high to low bits):
     1  : fat(1) / thin(0)
     15 :
       thin:
         10 : thread ID
         5  : recursion count
       fat:
         15 : lock ID

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

    10 : unused (0)
     4 : SVM_TYPE_XXX (base type)
     1 : array(0x1)
     1 : always 1 (to deferentiate header word from ptr)

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

    10 : unused (0)
     4 : SVM_TYPE_XXX (base type)
     1 : array(0x1)
     1 : always 1 (to deferentiate header word from ptr)

#endif

*/

svm_static void
_svmf_prepare_array_lockword (_svmt_array_info *array)
{
  _svmt_word lockword = 0;
  _svmt_word type =
    (array->dimensions == 1) ? array->base_type : SVM_TYPE_REFERENCE;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  lockword |= type << 2;
  lockword |= 0x01 << 1;
  lockword |= 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  lockword |= type << 2;
  lockword |= 0x01 << 1;
  lockword |= 0x01;

#endif /* defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT) */

  array->initial_lockword = lockword;
}

/*
----------------------------------------------------------------------
_svmf_initialize_thinlock_id
----------------------------------------------------------------------
*/

static inline void
_svmf_initialize_thinlock_id (_svmt_JNIEnv *env)
{
  assert (env->thread.id < 0x03ff);

  env->thread.thinlock_id = env->thread.id << 21;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_extra_bits
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_extra_bits (_svmt_word lockword)
{
  return lockword & 0x0ffff;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_thin
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_thin (_svmt_word lockword)
{
  return (lockword & 0x80000000) == 0;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_forward_reference
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_forward_reference (_svmt_word lockword)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword & 0x01) == 0;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword & 0x01) == 0;

#endif
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_thinlock_id
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_thinlock_id (_svmt_word lockword)
{
  return lockword & 0x7fe00000;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_thread_id
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_thread_id (_svmt_word lockword)
{
  return (lockword & 0x7fe00000) >> 21;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_fatlockindex
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_fatlock_index (_svmt_word lockword)
{
  return (lockword & 0x7fff0000) >> 16;
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_recursive_count
----------------------------------------------------------------------
*/

inline static jint
_svmf_lockword_get_thinlock_recursive_count (_svmt_word lockword)
{
  return (lockword & 0x001f0000) >> 16;
}

/*
----------------------------------------------------------------------
_svmf_lockword_thinlock
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_thinlock (_svmt_word thinlock_id, jint recursive_count,
			 _svmt_word extra_bits)
{
  return thinlock_id | (((_svmt_word) recursive_count) << 16) | extra_bits;
}

/*
----------------------------------------------------------------------
_svmf_lockword_fatlock
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_fatlock (_svmt_word fatlock_id, _svmt_word extra_bits)
{
  return (1 << 31) | (fatlock_id << 16) | extra_bits;
}

/*
----------------------------------------------------------------------
_svmf_lockword_is_array
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_lockword_is_array (_svmt_word lockword)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 1) & 0x01;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 1) & 0x01;

#endif
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_array_type
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_array_type (_svmt_word lockword)
{
  assert (_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x0f;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x0f;

#endif
}

/*
----------------------------------------------------------------------
_svmf_lockword_get_hashstate
----------------------------------------------------------------------
*/

inline static _svmt_word
_svmf_lockword_get_hashstate (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x03;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (lockword >> 2) & 0x03;

#endif
}

/*
----------------------------------------------------------------------
_svmm_lockword_set_hashstate
----------------------------------------------------------------------
*/

#define _svmm_lockword_set_hashstate(lockword, state) \
_svmh_lockword_set_hashstate (&lockword, state)

inline static void
_svmh_lockword_set_hashstate (_svmt_word *plockword, _svmt_word state)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  *plockword = (*plockword & 0xFFFFFFF3) | (state << 2);

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  *plockword = (*plockword & 0xFFFFFFF3) | (state << 2);

#endif
}

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_end_offset
----------------------------------------------------------------------
*/

inline static size_t
_svmf_lockword_object_get_end_offset (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (((lockword >> 4) & 0x03f) * (size_t) SVM_ALIGNMENT) +
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));

#elif defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (((lockword >> 12) & 0x07) * (size_t) SVM_ALIGNMENT) +
    _svmf_aligned_size_t (sizeof (_svmt_object_instance));

#endif
}

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_start_offset
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

inline static size_t
_svmf_lockword_object_get_start_offset (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return (((lockword >> 10) & 0x03f) * (size_t) SVM_ALIGNMENT);
}

#endif

/*
----------------------------------------------------------------------
_svmf_lockword_object_is_info_in_header
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

inline static jboolean
_svmf_lockword_object_is_info_in_header (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return ((lockword >> 4) & 0x01) == 0;
}

#endif

/*
----------------------------------------------------------------------
_svmf_lockword_object_get_ref_layout
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

inline static _svmt_word
_svmf_lockword_object_get_ref_layout (_svmt_word lockword)
{
  assert (!_svmf_lockword_is_array (lockword));

  return (lockword >> 5) & 0x07f;
}

#endif

/*
----------------------------------------------------------------------
_svmf_word_is_reference
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_word_is_reference (_svmt_word word)
{
#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  return (word & 0x01) == 0;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  return (word & 0x01) == 0;

#endif
}

#endif /* (defined (__i386__) && defined (__GNUC__)) */
