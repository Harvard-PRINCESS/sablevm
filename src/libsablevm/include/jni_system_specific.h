/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file has been released into the public domain by    *
 * the developers of SableVM (http://www.sablevm.org/).            *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_JNI_SYSTEM_SPECIFIC_H
#define SVM_JNI_SYSTEM_SPECIFIC_H

/* system specific primitive types */

/* legend:
   u = unsigned intger,  s = signed integer, f = float, d = double
   8,16,32,64 = 8 bits, 16 bits, ...
   So, "u8" means an 8 bits unsigned integer. */

/* it seems that *many* of systems is identical here */

#if (( \
       defined (__sparc__) || defined (__ia64__) || defined (__alpha__) \
    || defined (__i386__) || defined (__powerpc__) || defined (__s390__) \
    || defined (__hppa__) || defined (__arm__) || defined (__m68k__) \
    || defined (__mc68000__) || defined (__mips__) || defined (__mipsel__) \
    || defined (__x86_64__) || defined (_POWER)     \
     ) && defined (__GNUC__))

#define JNICALL

/* See http://sablevm.org/bugs/14 for more information about the following */
#define JNIEXPORT
#define JNIIMPORT

typedef unsigned char _svmt_u8;
typedef signed char _svmt_s8;
typedef unsigned short _svmt_u16;
typedef signed short _svmt_s16;
typedef unsigned int _svmt_u32;
typedef signed int _svmt_s32;
__extension__ typedef unsigned long long _svmt_u64;
__extension__ typedef signed long long _svmt_s64;
typedef float _svmt_f32;
typedef double _svmt_d64;

#else

#error "unknown system"

#endif
#endif /* NOT SVM_JNI_SYSTEM_SPECIFIC_H */
