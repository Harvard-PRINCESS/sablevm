/* This file has been automatically generated from "util.m4.c" */

/*
----------------------------------------------------------------------
_svmf_get_byte_array_element
----------------------------------------------------------------------
*/

inline static jbyte
_svmf_get_byte_array_element (_svmt_array_instance *array, jint indx)
{
  jbyte *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jbyte *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_byte_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_byte_array_element (_svmt_array_instance *array, jint indx, jbyte value)
{
  jbyte *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jbyte *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_char_array_element
----------------------------------------------------------------------
*/

inline static jchar
_svmf_get_char_array_element (_svmt_array_instance *array, jint indx)
{
  jchar *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jchar *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_char_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_char_array_element (_svmt_array_instance *array, jint indx, jchar value)
{
  jchar *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jchar *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_short_array_element
----------------------------------------------------------------------
*/

inline static jshort
_svmf_get_short_array_element (_svmt_array_instance *array, jint indx)
{
  jshort *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jshort *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_short_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_short_array_element (_svmt_array_instance *array, jint indx, jshort value)
{
  jshort *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jshort *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_int_array_element
----------------------------------------------------------------------
*/

inline static jint
_svmf_get_int_array_element (_svmt_array_instance *array, jint indx)
{
  jint *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jint *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_int_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_int_array_element (_svmt_array_instance *array, jint indx, jint value)
{
  jint *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jint *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_long_array_element
----------------------------------------------------------------------
*/

inline static jlong
_svmf_get_long_array_element (_svmt_array_instance *array, jint indx)
{
  jlong *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jlong *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_long_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_long_array_element (_svmt_array_instance *array, jint indx, jlong value)
{
  jlong *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jlong *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_float_array_element
----------------------------------------------------------------------
*/

inline static jfloat
_svmf_get_float_array_element (_svmt_array_instance *array, jint indx)
{
  jfloat *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jfloat *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_float_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_float_array_element (_svmt_array_instance *array, jint indx, jfloat value)
{
  jfloat *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jfloat *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_double_array_element
----------------------------------------------------------------------
*/

inline static jdouble
_svmf_get_double_array_element (_svmt_array_instance *array, jint indx)
{
  jdouble *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jdouble *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];
}

/*
----------------------------------------------------------------------
_svmf_set_double_array_element
----------------------------------------------------------------------
*/

inline static void
_svmf_set_double_array_element (_svmt_array_instance *array, jint indx, jdouble value)
{
  jdouble *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (jdouble *) (void *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  elements[indx] = value;
}


/*
----------------------------------------------------------------------
_svmf_get_BYTE_field
----------------------------------------------------------------------
*/

inline static jbyte
_svmf_get_BYTE_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jbyte *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_BYTE_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_BYTE_field (_svmt_object_instance *instance, size_t offset, jbyte value)
{
  *((jbyte *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_CHAR_field
----------------------------------------------------------------------
*/

inline static jchar
_svmf_get_CHAR_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jchar *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_CHAR_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_CHAR_field (_svmt_object_instance *instance, size_t offset, jchar value)
{
  *((jchar *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_SHORT_field
----------------------------------------------------------------------
*/

inline static jshort
_svmf_get_SHORT_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jshort *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_SHORT_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_SHORT_field (_svmt_object_instance *instance, size_t offset, jshort value)
{
  *((jshort *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_INT_field
----------------------------------------------------------------------
*/

inline static jint
_svmf_get_INT_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jint *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_INT_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_INT_field (_svmt_object_instance *instance, size_t offset, jint value)
{
  *((jint *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_LONG_field
----------------------------------------------------------------------
*/

inline static jlong
_svmf_get_LONG_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jlong *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_LONG_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_LONG_field (_svmt_object_instance *instance, size_t offset, jlong value)
{
  *((jlong *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_FLOAT_field
----------------------------------------------------------------------
*/

inline static jfloat
_svmf_get_FLOAT_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jfloat *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_FLOAT_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_FLOAT_field (_svmt_object_instance *instance, size_t offset, jfloat value)
{
  *((jfloat *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_DOUBLE_field
----------------------------------------------------------------------
*/

inline static jdouble
_svmf_get_DOUBLE_field (_svmt_object_instance *instance, size_t offset)
{
  return *((jdouble *) (void *) (((char *) instance) + offset));
}

/*
----------------------------------------------------------------------
_svmf_put_DOUBLE_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_DOUBLE_field (_svmt_object_instance *instance, size_t offset, jdouble value)
{
  *((jdouble *) (void *) (((char *) instance) + offset)) = value;
}


/*
----------------------------------------------------------------------
_svmf_get_BOOLEAN_static
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_get_BOOLEAN_static (jvalue *pvalue)
{
  return pvalue->z;
}

/*
----------------------------------------------------------------------
_svmf_put_BOOLEAN_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_BOOLEAN_static (jvalue *pvalue, jboolean value)
{
  pvalue->z = value;
}


/*
----------------------------------------------------------------------
_svmf_get_BYTE_static
----------------------------------------------------------------------
*/

inline static jbyte
_svmf_get_BYTE_static (jvalue *pvalue)
{
  return pvalue->b;
}

/*
----------------------------------------------------------------------
_svmf_put_BYTE_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_BYTE_static (jvalue *pvalue, jbyte value)
{
  pvalue->b = value;
}


/*
----------------------------------------------------------------------
_svmf_get_CHAR_static
----------------------------------------------------------------------
*/

inline static jchar
_svmf_get_CHAR_static (jvalue *pvalue)
{
  return pvalue->c;
}

/*
----------------------------------------------------------------------
_svmf_put_CHAR_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_CHAR_static (jvalue *pvalue, jchar value)
{
  pvalue->c = value;
}


/*
----------------------------------------------------------------------
_svmf_get_SHORT_static
----------------------------------------------------------------------
*/

inline static jshort
_svmf_get_SHORT_static (jvalue *pvalue)
{
  return pvalue->s;
}

/*
----------------------------------------------------------------------
_svmf_put_SHORT_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_SHORT_static (jvalue *pvalue, jshort value)
{
  pvalue->s = value;
}


/*
----------------------------------------------------------------------
_svmf_get_INT_static
----------------------------------------------------------------------
*/

inline static jint
_svmf_get_INT_static (jvalue *pvalue)
{
  return pvalue->i;
}

/*
----------------------------------------------------------------------
_svmf_put_INT_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_INT_static (jvalue *pvalue, jint value)
{
  pvalue->i = value;
}


/*
----------------------------------------------------------------------
_svmf_get_LONG_static
----------------------------------------------------------------------
*/

inline static jlong
_svmf_get_LONG_static (jvalue *pvalue)
{
  return pvalue->j;
}

/*
----------------------------------------------------------------------
_svmf_put_LONG_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_LONG_static (jvalue *pvalue, jlong value)
{
  pvalue->j = value;
}


/*
----------------------------------------------------------------------
_svmf_get_FLOAT_static
----------------------------------------------------------------------
*/

inline static jfloat
_svmf_get_FLOAT_static (jvalue *pvalue)
{
  return pvalue->f;
}

/*
----------------------------------------------------------------------
_svmf_put_FLOAT_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_FLOAT_static (jvalue *pvalue, jfloat value)
{
  pvalue->f = value;
}


/*
----------------------------------------------------------------------
_svmf_get_DOUBLE_static
----------------------------------------------------------------------
*/

inline static jdouble
_svmf_get_DOUBLE_static (jvalue *pvalue)
{
  return pvalue->d;
}

/*
----------------------------------------------------------------------
_svmf_put_DOUBLE_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_DOUBLE_static (jvalue *pvalue, jdouble value)
{
  pvalue->d = value;
}

