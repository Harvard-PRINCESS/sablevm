/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_FATAL_H
#define SVM_FATAL_H

/* The __func__ is only defined in C99, and it CANNOT be tested by #ifdef,
   so we use autoconf test that sets HAVE___func__ for us. */
#ifdef HAVE___func__
#  define _svmm_fatal_error(msg) \
     _svmh_fatal_error(__FILE__, __func__, __LINE__, msg)
#else
#  define _svmm_fatal_error(msg) \
     _svmh_fatal_error(__FILE__, "unknown", __LINE__, msg)
#endif

#endif /* not SVM_FATAL_H */
