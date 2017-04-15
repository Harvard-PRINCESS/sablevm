/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_array_element
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_array_element)
 */

m4svm_define_begin v = ":], [:m4svm_array_element:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_get_$1_array_element
-----------------------------------m4_dnl
-----------------------------------
*/

inline static j$1
_svmf_get_$1_array_element (_svmt_array_instance *array, jint indx)
{
  j$1 *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (j$1 *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_set_$1_array_element
-----------------------------------m4_dnl
-----------------------------------
*/

inline static void
_svmf_set_$1_array_element (_svmt_array_instance *array, jint indx, j$1 value)
{
  j$1 *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (j$1 *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_getset_field
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_getset_field)
 */

m4svm_define_begin v = ":], [:m4svm_getset_field:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_get_$1_field
-----------------------------------m4_dnl
-----------------------------------
*/

inline static $2
_svmf_get_$1_field (_svmt_object_instance *instance, size_t offset)
{
  return *(($2 *) (void *) (((char *) instance) + offset));
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_put_$1_field
-----------------------------------m4_dnl
-----------------------------------
*/

inline static void
_svmf_put_$1_field (_svmt_object_instance *instance, size_t offset, $2 value)
{
  *(($2 *) (void *) (((char *) instance) + offset)) = value;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_getset_static
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_getset_static)
 */

m4svm_define_begin v = ":], [:m4svm_getset_static:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_get_$1_static
-----------------------------------m4_dnl
-----------------------------------
*/

inline static $2
_svmf_get_$1_static (jvalue *pvalue)
{
  return pvalue->$3;
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_put_$1_static
-----------------------------------m4_dnl
-----------------------------------
*/

inline static void
_svmf_put_$1_static (jvalue *pvalue, $2 value)
{
  pvalue->$3 = value;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
head
----------------------------------------------------------------------

m4svm_file_name

m4svm_array_element_begin[:

byte
char
short
int
long
float
double

:]m4svm_array_element_end

m4svm_getset_field_begin[:

BYTE, jbyte
CHAR, jchar
SHORT, jshort
INT, jint
LONG, jlong
FLOAT, jfloat
DOUBLE, jdouble

:]m4svm_getset_field_end

m4svm_getset_static_begin[:

BOOLEAN, jboolean, z
BYTE, jbyte, b
CHAR, jchar, c
SHORT, jshort, s
INT, jint, i
LONG, jlong, j
FLOAT, jfloat, f
DOUBLE, jdouble, d

:]m4svm_getset_static_end

*/
