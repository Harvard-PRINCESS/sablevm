/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_SYSTEM_H
#define SVM_SYSTEM_H

/*
IMPORTANT: "ALIGNMENT" should be >= sizeof (void *) and a power of 2

This program computes the alignment (assuming a conforming ISO C compiler).

#include "jni_system_specific.h"


union value
{
  void *p;
  _svmt_u8 u8;
  _svmt_s8 s8;
  _svmt_u16 u16;
  _svmt_s16 s16;
  _svmt_u32 u32;
  _svmt_s32 s32;
  _svmt_u64 u64;
  _svmt_s64 s64;
  _svmt_f32 f32;
  _svmt_d64 d64;
};


struct align
{
  char c;
  union value v;
};

int main (int argc, char *argv[])
{
  struct align a;

  printf ("alignment = %u\n", (unsigned int) (((char *) &a.v) - ((char *) &a)));

  return 0;
}

*/

#if (( \
       defined (__sparc__) || defined (__ia64__) || defined (__alpha__) \
    || defined (__i386__) || defined (__powerpc__) || defined (__s390__) \
    || defined (__hppa__) || defined (__arm__) || defined (__m68k__) \
    || defined (__mc68000__) || defined (__mips__) || defined (__mipsel__) \
    || defined (__x86_64__) || defined (_POWER)       \
     ) && defined (__GNUC__))

/* "inline" is now an official keyword since the latest C standard (1999).
   So, it is a reasonable assuption to expect a target compiler to
   support it.  If your compiler doesn't, then you should define
   "inline" as nothing.
*/
#define inline __inline__

#define SVM_UNUSED __attribute__((unused))
#define SVM_CAST_EXTENSION __extension__

/* _svmt_word is an unsigned integral type such that:
 *
 *   sizeof (void *) == sizeof(_svmt_word).
 *
 * I guess that on most architectures, an "unsigned int" is a "word".
 */

#define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)

#if defined (__alpha__)

typedef _svmt_u64 _svmt_word;
typedef _svmt_d64 _svmt_float_word;

#define SVM_WORD_SIZE 8		/* size in bytes */
#define SVM_WORD_BIT_COUNT 64	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 8192

#include <inlined_alpha.h>

#elif defined (__arm__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 4
#define SVM_ALIGNMENT_POWER 2	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_arm.h>

#elif defined (__hppa__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_hppa.h>

#elif defined (__i386__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 4
#define SVM_ALIGNMENT_POWER 2	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#if   (GCC_VERSION >= 2095) && (GCC_VERSION <3000)
#include <inlined_i386-gcc-2.95.h>
#else
#include <inlined_i386-gcc-3.3.h>
#endif /* (GCC_VERSION >= 2095) && (GCC_VERSION <3000) */

#elif defined (__ia64__)

typedef _svmt_u64 _svmt_word;
typedef _svmt_d64 _svmt_float_word;

#define SVM_WORD_SIZE 8		/* size in bytes */
#define SVM_WORD_BIT_COUNT 64	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 16384

#include <inlined_ia64.h>


#elif defined (__m68k__) || defined (__mc68000__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 2
#define SVM_ALIGNMENT_POWER 1	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_m68k.h>

#elif (defined (__mips__) || defined (__mipsel__))

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#elif defined (__powerpc__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_powerpc-no-reorder.h>

#elif defined (__s390__)
/* yes, that's strange, but s390 is 32bit - apparently at least in the userspace */
typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_s390.h>

#elif defined (__sparc__)

typedef _svmt_u32 _svmt_word;
typedef _svmt_f32 _svmt_float_word;

#define SVM_WORD_SIZE 4		/* size in bytes */
#define SVM_WORD_BIT_COUNT 32	/* size in bits */

/* see comments at the head of this file */
/* http://www.acm.org/crossroads/xrds1-3/free.html says you can have either
 * processor with 4k page size (old sparc) or 8k page size (ultra sparc).
 * We should probably choose the bigger value - shouldn't we? (GBP) */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 8192

#include <inlined_sparc.h>

#elif defined (__x86_64__)

typedef _svmt_u64 _svmt_word;
typedef _svmt_d64 _svmt_float_word;

#define SVM_WORD_SIZE 8		/* size in bytes */
#define SVM_WORD_BIT_COUNT 64	/* size in bits */

/* see comments at the head of this file */
#define SVM_ALIGNMENT 8
#define SVM_ALIGNMENT_POWER 3	/* 2 ^^ SVM_ALIGNMENT_POWER == SVM_ALIGNMENT */
#define SVM_PAGE_SIZE 4096

#include <inlined_x86_64.h>

#else
#error "unknown system"
#endif


/* FFI specific types */
#define ffi_type_float32 ffi_type_float
#define ffi_type_float64 ffi_type_double

/* Does ">>" behaves as a "signed" or "unsigned" shift when
   applied to a signed argument?  I personally think that the C
   standard should have specified this, unstead of leaving the choice
   in the hands of each compiler designer.  But what can I do? */

#define SVM_SIGNED_SHR 1	/* uncomment when: (-1 >> 1) == -1 */

#ifdef COMMENT
#define SVM_UNSIGNED_SHR 1	/* uncomment when: (-1 >> 1) != -1 */
#endif /* COMMENT */

/* Max integer that can be stored in a size_t variable */
#ifndef SIZE_T_MAX
#define SIZE_T_MAX UINT_MAX
#endif /* !SIZE_T_MAX */

#if defined (_SABLEVM_NO_GC)

#define SVM_HEAP_DEFAULT_SIZE 67108864

#elif defined (_SABLEVM_COPY_GC) || (_SABLEVM_GENCOPY_GC)

#define SVM_HEAP_DEFAULT_MIN_SIZE 16777216
#define SVM_HEAP_DEFAULT_MAX_SIZE 0
#define SVM_HEAP_DEFAULT_ALLOCATION_INCREMENT 1048576

#if defined (_SABLEVM_GENCOPY_GC)

#define SVM_HEAP_DEFAULT_NURSERY_SIZE (1<<20)
#define SVM_HEAP_DEFAULT_LARGE_OBJECT_SIZE (1<<11)
#define SVM_HEAP_REMSET_BUCKET_NUM (1<<5)
#define SVM_HEAP_REMSET_BUCKET_SIZE (1<<5)

#endif /* defined (_SABLEVM_GENCOPY_GC) */

#endif /* defined (_SABLEVM_NO_GC) */

#define SVM_STACK_DEFAULT_MIN_SIZE 65536
#define SVM_STACK_DEFAULT_MAX_SIZE 0
#define SVM_STACK_DEFAULT_ALLOCATION_INCREMENT 65536

#define SVM_CLASS_LOADER_DEFAULT_MIN_SIZE 1048576
#define SVM_CLASS_LOADER_DEFAULT_MAX_SIZE 0
#define SVM_CLASS_LOADER_DEFAULT_ALLOCATION_INCREMENT 1048576

#define SVM_THINLOCK_MAX_RECURSIVE_COUNT 0x01f
#define SVM_MAX_FATLOCK_ID 0x07fff
#define SVM_MAX_THREAD_ID 0x03ff

#define SVM_HASH_NONE 0
#define SVM_HASH_NOT_MOVED 1
#define SVM_HASH_MOVED 2

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

#define SVM_LOCKWORD_START_OVERFLOW 0x03f
#define SVM_LOCKWORD_END_OVERFLOW 0x03f

#define SVM_LOCKWORD_START_OVERFLOW_OFFSET (SVM_LOCKWORD_START_OVERFLOW * SVM_ALIGNMENT)
#define SVM_LOCKWORD_END_OVERFLOW_OFFSET (SVM_LOCKWORD_END_OVERFLOW * SVM_ALIGNMENT + \
                                          _svmf_aligned_size_t (sizeof (_svmt_object_instance)))

#endif

#else

#error "unknown system"

#endif

#endif /* not SVM_SYSTEM_H */
