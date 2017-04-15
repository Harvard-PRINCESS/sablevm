/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_SABLEVM_H
#define SVM_SABLEVM_H

#if defined(__GNUC__)
#define SVM_CAST_EXTENSION __extension__
#else
#define SVM_CAST_EXTENSION
#endif

/*
  Note: By not defining headers for static non-recursive
  functions, we give the compiler better opportunities
  to inline functions.
  The final result might look a little like Pascal;-).
*/

typedef struct property_struct property_t;
typedef struct property_info_struct property_info_t;

struct property_struct
{
  char *value;
  property_t *next;
};

struct property_info_struct
{
  property_t *tail;
  size_t count;
  size_t size;
};

int main (const int argc, const char *argv[]);

#endif /* not SVM_SABLEVM_H */
