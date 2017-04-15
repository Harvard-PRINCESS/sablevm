/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include "gc_gencopy.h"

/*
----------------------------------------------------------------------
_svmf_bytes_to_u16
----------------------------------------------------------------------
*/

inline svm_static _svmt_u16
_svmf_bytes_to_u16 (_svmt_u8 *bytes)
{
  jint i;
  _svmt_u16 result = 0;

  for (i = 0; i < 2; i++)
    {
      result = (result << 8) | bytes[i];
    }

  return result;
}

/*
----------------------------------------------------------------------
_svmf_bytes_to_s32
----------------------------------------------------------------------
*/

inline svm_static _svmt_s32
_svmf_bytes_to_s32 (_svmt_u8 *bytes)
{
  jint i;
  _svmt_s32 result = 0;

  for (i = 0; i < 4; i++)
    {
      result = (result << 8) | bytes[i];
    }

  return result;
}

/*
----------------------------------------------------------------------
_svmf_bytes_to_s16
----------------------------------------------------------------------
*/

inline svm_static _svmt_s16
_svmf_bytes_to_s16 (_svmt_u8 *bytes)
{
  jint i;
  _svmt_s16 result = 0;

  for (i = 0; i < 2; i++)
    {
      result = (result << 8) | bytes[i];
    }

  return result;
}

/*
----------------------------------------------------------------------
_svmf_aligned_size_t
----------------------------------------------------------------------
*/

inline static size_t
_svmf_aligned_size_t (size_t size)
{
  return (size + (SVM_ALIGNMENT - 1)) & ~((size_t) (SVM_ALIGNMENT - 1));
}

/*
----------------------------------------------------------------------
_svmf_max_jint
----------------------------------------------------------------------
*/

inline static jint
_svmf_max_jint (jint value1, jint value2)
{
  return (value1 >= value2) ? value1 : value2;
}

/*
----------------------------------------------------------------------
_svmf_min_jint
----------------------------------------------------------------------
*/

inline static jint
_svmf_min_jint (jint value1, jint value2)
{
  return (value1 <= value2) ? value1 : value2;
}

/*
----------------------------------------------------------------------
_svmf_get_bit
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_get_bit (_svmt_u8 *bytes, jint index)
{
  return (bytes[index / 8] >> (index % 8)) & 1;
}

/*
----------------------------------------------------------------------
_svmf_set_bit
----------------------------------------------------------------------
*/

inline static void
_svmf_set_bit (_svmt_u8 *bytes, jint index)
{
  bytes[index / 8] |= ((_svmt_u8) 1) << (index % 8);
}

/*
----------------------------------------------------------------------
_svmf_clear_bit
----------------------------------------------------------------------
*/

inline static void
_svmf_clear_bit (_svmt_u8 *bytes, jint index)
{
  bytes[index / 8] &= ~(((_svmt_u8) 1) << (index % 8));
}

/*
----------------------------------------------------------------------
_svmf_is_set_flag
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_is_set_flag (jint value, jint flag)
{
  return (value & flag) == flag;
}

/*
----------------------------------------------------------------------
_svmh_set_flag
----------------------------------------------------------------------
*/

inline static void
_svmh_set_flag (jint *pvalue, jint flag)
{
  *pvalue |= flag;
}

/*
----------------------------------------------------------------------
_svmh_clear_flag
----------------------------------------------------------------------
*/

inline static void
_svmh_clear_flag (jint *pvalue, jint flag)
{
  *pvalue &= ~flag;
}

/*
----------------------------------------------------------------------
_svmf_is_interface
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_is_interface (_svmt_class_info *class)
{
  return _svmf_is_set_flag (class->access_flags, SVM_ACC_INTERFACE);
}

/*
----------------------------------------------------------------------
_svmf_aligned_to_increment
----------------------------------------------------------------------
*/

inline static size_t
_svmf_aligned_to_increment (size_t size, size_t increment)
{
  return ((size + (increment - 1)) / increment) * increment;
}

/*
----------------------------------------------------------------------
_svmh_validate_min_max_increment
----------------------------------------------------------------------
*/

svm_static jint
_svmh_validate_min_max_increment (size_t *pmin, size_t *pmax, size_t *pincr)
{
  *pmin = _svmf_aligned_size_t (*pmin);
  *pmax = _svmf_aligned_size_t (*pmax);
  *pincr = _svmf_aligned_size_t (*pincr);

  /* Allow shortcut for specifying fixed size */
  if (*pmin == *pmax)
    {
      *pincr = 0;
    }
  else if (*pincr == 0)
    {
      *pmax = *pmin;
    }

  /* min must be positive */
  if (*pmin == 0)
    {
      return JNI_ERR;
    }

  /* max size of 0 means no maximum */
  if (*pmax == 0 && *pincr == 0)
    {
      return JNI_ERR;
    }

  /* if not 0, max size must be >= the min size */
  if (*pmax > 0 && *pmax < *pmin)
    {
      return JNI_ERR;
    }

  /* incr should be zero for fixed size, non-zero otherwise */
  if ((*pmax == *pmin && *pincr != 0) || (*pmax != *pmin && *pincr == 0))
    {
      return JNI_ERR;
    }

  /* make (max - min) a multiple of incr */
  if (*pmax > *pmin)
    {
      *pmax = *pmin + _svmf_aligned_to_increment (*pmax - *pmin, *pincr);

      if (*pmax <= *pmin)
	{
	  return JNI_ERR;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_get_boolean_array_element
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_get_boolean_array_element (_svmt_array_instance *array, jint indx)
{
  _svmt_u8 *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (_svmt_u8 *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return _svmf_get_bit (elements, indx);
}

/*
----------------------------------------------------------------------
_svmf_set_boolean_array_element
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_set_boolean_array_element (_svmt_array_instance *array, jint indx,
				 jboolean value)
{
  _svmt_u8 *elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

  elements = (_svmt_u8 *)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  if (value)
    {
      _svmf_set_bit (elements, indx);
    }
  else
    {
      _svmf_clear_bit (elements, indx);
    }
}

/*
----------------------------------------------------------------------
_svmf_get_reference_array_element
----------------------------------------------------------------------
*/

inline svm_static _svmt_object_instance *
_svmf_get_reference_array_element (_svmt_array_instance *array, jint indx)
{
  _svmt_object_instance **elements;

#ifndef _SABLEVM_INLINED_THREADED_INTERPRETER
  assert (array != NULL);
  assert (array->vtable->type->is_array);
  assert (indx >= 0 && indx < array->size);
#endif

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  elements = (_svmt_object_instance **) array;
  return elements[(-1) - indx];

#else

  elements = (_svmt_object_instance **)
    (((char *) array) + _svmf_aligned_size_t (sizeof (_svmt_array_instance)));

  return elements[indx];

#endif
}

/*
----------------------------------------------------------------------
_svmf_printf
----------------------------------------------------------------------
*/

svm_static void
_svmf_printf (_svmt_JNIEnv *env, FILE *stream, const char *format, ...)
{
  _svmt_JavaVM *vm = env->vm;
  va_list ap;

  va_start (ap, format);

  (*(vm->vfprintf)) (stream, format, ap);

#if (!defined(NDEBUG)) || defined(_SABLEVM_INLINABILITY_TESTING)
  fflush (NULL);
#endif

  va_end (ap);
}

/*
----------------------------------------------------------------------
_svmf_parse_size_t
----------------------------------------------------------------------
*/

svm_static jint
_svmf_parse_size_t (size_t *size, const char *value)
{
  size_t result = 0;

  if (*value == 0)
    {
      return JNI_ERR;
    }

  do
    {
      char c = *value++;

      if (c >= '0' && c <= '9')
	{
	  size_t old = result;
	  result = (result * 10) + (c - '0');
	  if (result < old)
	    {
	      return JNI_ERR;
	    }
	}
      else if (c == 0)
	{
	  *size = result;
	  return JNI_OK;
	}
      else
	{
	  return JNI_ERR;
	}
    }
  while (1);
}

/*
----------------------------------------------------------------------
_svmf_get_BOOLEAN_field
----------------------------------------------------------------------
*/

inline static jboolean
_svmf_get_BOOLEAN_field (_svmt_object_instance *instance, size_t offset)
{
  return _svmf_get_bit ((_svmt_u8 *) instance, offset);
}

/*
----------------------------------------------------------------------
_svmf_put_BOOLEAN_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_BOOLEAN_field (_svmt_object_instance *instance, size_t offset,
			 jboolean value)
{
  if (value)
    {
      _svmf_set_bit ((_svmt_u8 *) instance, offset);
    }
  else
    {
      _svmf_clear_bit ((_svmt_u8 *) instance, offset);
    }
}

/*
----------------------------------------------------------------------
_svmf_get_REFERENCE_field
----------------------------------------------------------------------
*/

inline static _svmt_object_instance *
_svmf_get_REFERENCE_field (_svmt_object_instance *instance, size_t offset)
{
  _svmt_object_instance *result =
    *((_svmt_object_instance **) (void *) (((char *) instance) + offset));

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  assert (result == NULL || strcmp (result->magic, "SableVM") == 0);
#endif

  return result;
}

/*
----------------------------------------------------------------------
_svmf_put_REFERENCE_field
----------------------------------------------------------------------
*/

inline static void
_svmf_put_REFERENCE_field (_svmt_JNIEnv *env SVM_UNUSED,
			   _svmt_object_instance *instance, size_t offset,
			   _svmt_object_instance *value)
{
  *((_svmt_object_instance **) (void *) (((char *) instance) + offset)) =
    value;
#if defined (_SABLEVM_GC_WRITE_BARRIER)
  _svmf_write_barrier
    (env, (_svmt_object_instance **) (void *) ((char *) instance + offset));
#endif /* _SABLEVM_GC_WRITE_BARRIER */
}

/*
----------------------------------------------------------------------
_svmf_get_REFERENCE_static
----------------------------------------------------------------------
*/

inline static _svmt_object_instance *
_svmf_get_REFERENCE_static (jvalue *pvalue)
{
  _svmt_object_instance *result = *(pvalue->l);

#if defined (MAGIC) && !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  assert (result == NULL || strcmp (result->magic, "SableVM") == 0);
#endif

  return result;
}

/*
----------------------------------------------------------------------
_svmf_put_REFERENCE_static
----------------------------------------------------------------------
*/

inline static void
_svmf_put_REFERENCE_static (jvalue *pvalue, _svmt_object_instance *value)
{
  *(pvalue->l) = value;
}

/*
----------------------------------------------------------------------
_svmf_dump_stack_trace
----------------------------------------------------------------------
*/

svm_static void
_svmf_dump_stack_trace (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_frame *frame = env->stack.current_frame;
  _svmt_method_info *method = frame->method;

  jint lineNumber = -1;
  jboolean isNative = JNI_FALSE;

  _svmf_printf (env, stderr, "--- stack trace dump (begin) ---\n");
  _svmf_printf (env, stderr, "Thread ID: %d, Posix ID: %d\n", env->thread.id,
		env->thread.pthread);

  while (method != &vm->stack_bottom_method)
    {
      _svmt_class_info *class;

      /* skip internal frames */
      if (_svmf_is_set_flag (method->access_flags, SVM_ACC_INTERNAL))
	{
	  _svmf_printf (env, stderr, "(internal frame)\n");

	  frame = (_svmt_stack_frame *) (void *)
	    (((char *) frame) - frame->previous_offset);
	  method = frame->method;
	  continue;
	}

      isNative = _svmf_is_set_flag (method->access_flags, SVM_ACC_NATIVE);

      class = method->class_info;

      if ((!isNative) && method->data.code_attribute->line_numbers != NULL)
	{
	  jint table_length =
	    method->data.code_attribute->line_numbers->
	    line_number_table_length;
	  _svmt_line_number_table *table =
	    method->data.code_attribute->line_numbers->line_number_table;
	  _svmt_code *pc = frame->pc;
	  jint i;

	  for (i = 0; i < table_length; i++)
	    {
	      if ((pc >= table[i].normal_start && pc <= table[i].normal_end)
		  || (pc >= table[i].prepare_start
		      && pc <= table[i].prepare_end))
		{
		  lineNumber = table[i].line_number;
		  break;
		}
	    }
	}

      _svmf_printf (env, stderr, "(%s:%d)  %s.%s  %c\n", class->file_name,
		    lineNumber, class->name, DREF (method->name, value),
		    (jint) (isNative ? 'n' : ' '));

      lineNumber = -1;
      isNative = JNI_FALSE;

      frame = (_svmt_stack_frame *) (void *)
	(((char *) frame) - frame->previous_offset);
      method = frame->method;
    }

  _svmf_printf (env, stderr, "--- stack trace dump (end) ---\n");

}






#ifdef COMMENT

#include "includes.h"

static jboolean have_identical_package_name
  (const char *name1, const char *name2);


/*
----------------------------------------------------------------------
have_identical_package_name
----------------------------------------------------------------------
*/

svm_static jboolean
have_identical_package_name (const char *name1, const char *name2)
{
  size_t i, j;
  size_t length;
  size_t len1 = strlen (name1);
  size_t len2 = strlen (name2);

  length = (len1 >= len2) ? len1 : len2;

  /* skip common prefix */
  for (i = 0; i < length; i++)
    {
      if (name1[i] != name2[i])
	{
	  break;
	}
    }

  /* if the remaining of name1 or name2 contains a '/', then the packages differ */
  for (j = i; j < len1; j++)
    {
      if (name1[j] == '/')
	{
	  return JNI_FALSE;
	}
    }

  for (j = i; j < len2; j++)
    {
      if (name2[j] == '/')
	{
	  return JNI_FALSE;
	}
    }

  return JNI_TRUE;
}

/*
----------------------------------------------------------------------
_svmf_has_same_runtime_package
----------------------------------------------------------------------
*/

jboolean
_svmf_have_same_runtime_package (_svmt_type_info *type1,
				 _svmt_type_info *type2)
{
  return
    (type1->class_loader_info == type2->class_loader_info &&
     have_identical_package_name (type1->name, type2->name))
    ? JNI_TRUE : JNI_FALSE;
}

/*
----------------------------------------------------------------------
_svmf_debug_print_stack_trace
----------------------------------------------------------------------
*/

void
_svmf_debug_print_stack_trace (_svmt_JNIEnv *env)
{
  _svmt_stack_frame *frame = env->stack.current_frame;

  /*  if (strcmp(DREF(frame->method->name, value), "loadLibrary") == 0)
     {
     printf ("gotcha!\n");
     } */

  printf ("--------------------\n");
  while (1)
    {
      _svmt_method_info *method = frame->method;

      if (IS_SET (method->access_flags, SVM_ACC_DUMMY))
	{
	  printf (" -- \n");
	}
      else if (IS_SET (method->access_flags, SVM_ACC_NATIVE))
	{
	  printf
	    ("%s.%s %s (native)\n",
	     method->class_info->name,
	     DREF (method->name, value), DREF (method->descriptor, value));
	}
      else if (method->code != method->code_attribute->prepared_code)
	{
	  printf
	    ("%s.%s %s (being prepared)\n",
	     method->class_info->name,
	     DREF (method->name, value), DREF (method->descriptor, value));
	}
      else
	{
	  _svmt_bytecode_info *bc_info = method->code_attribute->bc_info;
	  jint attributes_count = method->code_attribute->attributes_count;
	  jint i;
	  _svmt_LineNumberTable_attribute *attribute = NULL;
	  size_t offset = frame->pc - method->code;
	  jint table_length;
	  _svmt_line_number_table *table;
	  jboolean printed = JNI_FALSE;

	  for (i = 0; i < attributes_count; i++)
	    {
	      if (strcmp
		  (DREF (method->code_attribute->attributes[i]->name, value),
		   "LineNumberTable") == 0)
		{
		  attribute = (_svmt_LineNumberTable_attribute *)
		    method->code_attribute->attributes[i];
		}
	    }

	  if (attribute != NULL)
	    {
	      table_length = attribute->line_number_table_length;
	      table = attribute->line_number_table;

	      for (i = table_length - 1; i >= 0; i--)
		{
		  if (offset >=
		      bc_info[table[i].start_pc].code_offset +
		      bc_info[table[i].start_pc].code_length)
		    {
		      printf
			("%s.%s %s (line %d)\n",
			 method->class_info->name,
			 DREF (method->name, value),
			 DREF (method->descriptor, value),
			 table[i].line_number);
		      printed = JNI_TRUE;
		      break;
		    }
		}
	    }

	  if (!printed)
	    {
	      jint bc_length = method->code_attribute->code_length;
	      for (i = 0; i < bc_length; i++)
		{
		  if (offset ==
		      bc_info[i].code_offset + bc_info[i].code_length)
		    {
		      printf
			("%s.%s %s (at bytecode # %d)\n",
			 method->class_info->name,
			 DREF (method->name, value),
			 DREF (method->descriptor, value), i);
		      printed = JNI_TRUE;
		      break;
		    }
		}
	    }

	  if (!printed)
	    {
	      printf
		("%s.%s %s (unknown)\n",
		 method->class_info->name,
		 DREF (method->name, value),
		 DREF (method->descriptor, value));
	      break;
	    }
	}

      if (frame->previous_offset == 0)
	{
	  break;
	}

      frame =
	(_svmt_stack_frame *) (((char *) frame) - frame->previous_offset);
    }
}


#endif /* COMMENT */
