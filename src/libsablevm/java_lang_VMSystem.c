/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
Java_java_lang_VMSystem_identityHashCode
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMSystem
 * Method:    identityHashCode
 * Signature: (Ljava/lang/Object;)I
 */

JNIEXPORT static jint JNICALL
Java_java_lang_VMSystem_identityHashCode (JNIEnv *_env,
					  jclass _class SVM_UNUSED,
					  jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint hashcode = 0;

  _svmm_resuming_java (env);

  _svmm_identity_hashcode (env, obj, hashcode);

  _svmm_stopping_java (env);

  return hashcode;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMSystem_arraycopy
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMSystem
 * Method:    arraycopy
 * Signature: (Ljava/lang/Object;ILjava/lang/Object;II)V
 */
JNIEXPORT static void JNICALL
Java_java_lang_VMSystem_arraycopy (JNIEnv *_env, jclass class SVM_UNUSED,
				   jobject src, jint src_position,
				   jobject dst, jint dst_position,
				   jint length)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  if (dst == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  if (src == NULL)
    {
      _svmf_error_NullPointerException (env);
      goto end;
    }

  if (!((*src)->vtable->type->is_array))
    {
      _svmf_error_ArrayStoreException (env);
      goto end;
    }

  if (!((*dst)->vtable->type->is_array))
    {
      _svmf_error_ArrayStoreException (env);
      goto end;
    }

  {
    _svmt_array_instance *src_instance = *_svmf_cast_jarray (src);
    _svmt_array_instance *dst_instance = *_svmf_cast_jarray (dst);
    _svmt_array_info *src_type =
      _svmf_cast_array (src_instance->vtable->type);
    _svmt_array_info *dst_type =
      _svmf_cast_array (dst_instance->vtable->type);

    assert (src_instance->size >= 0 && dst_instance->size >= 0);

    if (src_type->dimensions == 1 &&
	dst_type->dimensions == 1 &&
	src_type->base_type != dst_type->base_type)
      {
	_svmf_error_ArrayStoreException (env);
	goto end;
      }

    if (src_type->dimensions == 1 &&
	src_type->base_type != SVM_TYPE_REFERENCE && dst_type->dimensions > 1)
      {
	_svmf_error_ArrayStoreException (env);
	goto end;
      }

    if (src_type->dimensions > 1 &&
	dst_type->dimensions == 1 &&
	dst_type->base_type != SVM_TYPE_REFERENCE)
      {
	_svmf_error_ArrayStoreException (env);
	goto end;
      }

    if (src_position < 0 ||
	dst_position < 0 ||
	length < 0 ||
	(_svmt_u32) src_position + (_svmt_u32) length >
	(_svmt_u32) src_instance->size
	|| (_svmt_u32) dst_position + (_svmt_u32) length >
	(_svmt_u32) dst_instance->size)
      {
	_svmf_error_ArrayIndexOutOfBoundsException (env);
	goto end;
      }

    /* The easy cases first... */

    if (length == 0)
      {
	/* we're done */
	goto end;
      }

    if (!_svmf_is_assignable_from
	(env, _svmf_cast_type_array (src_type),
	 _svmf_cast_type_array (dst_type)))
      {
	/* incompatible array types */

	jint i;

	assert (src_instance != dst_instance);
	assert (src_type->dimensions > 1
		|| src_type->base_type == SVM_TYPE_REFERENCE);
	assert (dst_type->dimensions > 1
		|| dst_type->base_type == SVM_TYPE_REFERENCE);

	for (i = 0; i < length; i++)
	  {
	    _svmt_object_instance *value =
	      _svmf_get_reference_array_element (src_instance,
						 src_position + i);

	    if (_svmf_set_reference_array_element_no_exception
		(env, dst_instance, dst_position + i, value) != JNI_OK)
	      {
		_svmf_error_ArrayStoreException (env);
		goto end;
	      }
	  }

	goto end;
      }

    /* src_type is assignable to dst_type.

       Note: Remember that src_type and dst_type are actual "runtime"
       types, not declared types.  This means that any value that was
       successfully inserted into src is type compatible with dst, as dst
       has a "wider" element type. */

    if (src_type->dimensions > 1 || src_type->base_type == SVM_TYPE_REFERENCE)
      {
	/* compatible reference array types */

	_svmt_object_instance **src_elements;
	_svmt_object_instance **dst_elements;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

	src_elements = (_svmt_object_instance **) src_instance;
	dst_elements = (_svmt_object_instance **) dst_instance;

	/* we must be careful; increasing array element indices are
	   stored in decreasing memory locations. */

	memmove (&dst_elements[-(dst_position + length)],
		 &src_elements[-(src_position + length)],
		 length * sizeof (void *));
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	{
	  void *ref;
	  for (ref = &dst_elements[-(dst_position + length)];
	       ref < (void *) dst_elements;
	       ref = (char *) ref + sizeof (void *))
	    {
	      _svmf_write_barrier (env, (_svmt_object_instance **) ref);
	    }
	}
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#else

	src_elements = (_svmt_object_instance **) (void *)
	  (((char *) src_instance) +
	   _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	dst_elements = (_svmt_object_instance **) (void *)
	  (((char *) dst_instance) + _svmf_aligned_size_t
	   (sizeof (_svmt_array_instance)));

	memmove (&dst_elements[dst_position],
		 &src_elements[src_position], length * sizeof (void *));
#if defined (_SABLEVM_GC_WRITE_BARRIER)
	{
	  void *ref;
	  for (ref = &dst_elements[dst_position];
	       ref < (void *)
	       (&dst_elements[dst_position] + length * sizeof (void *));
	       ref = (char *) ref + sizeof (void *))
	    {
	      _svmf_write_barrier (env, (_svmt_object_instance **) tmp);
	    }
	}
#endif /* _SABLEVM_GC_WRITE_BARRIER */

#endif

	goto end;
      }

    assert (src_type->dimensions == 1
	    && src_type->base_type != SVM_TYPE_REFERENCE);

    switch (src_type->base_type)
      {
      case SVM_TYPE_BOOLEAN:
	{
	  jint i;

	  for (i = 0; i < length; i++)
	    {
	      jboolean value = _svmf_get_boolean_array_element
		(src_instance, src_position + i);

	      _svmf_set_boolean_array_element
		(dst_instance, dst_position + i, value);
	    }

	  goto end;
	}
	break;

      case SVM_TYPE_BYTE:
	{
	  jbyte *src_elements = (jbyte *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jbyte *dst_elements =
	    (jbyte *) (void *) (((char *) dst_instance) +
				_svmf_aligned_size_t (sizeof
						      (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jbyte));
	  goto end;
	}
	break;

      case SVM_TYPE_SHORT:
	{
	  jshort *src_elements = (jshort *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jshort *dst_elements =
	    (jshort *) (void *) (((char *) dst_instance) +
				 _svmf_aligned_size_t (sizeof
						       (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jshort));
	  goto end;
	}
	break;

      case SVM_TYPE_CHAR:
	{
	  jchar *src_elements = (jchar *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jchar *dst_elements =
	    (jchar *) (void *) (((char *) dst_instance) +
				_svmf_aligned_size_t (sizeof
						      (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jchar));
	  goto end;
	}
	break;

      case SVM_TYPE_INT:
	{
	  jint *src_elements = (jint *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jint *dst_elements =
	    (jint *) (void *) (((char *) dst_instance) +
			       _svmf_aligned_size_t (sizeof
						     (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jint));
	  goto end;
	}
	break;

      case SVM_TYPE_LONG:
	{
	  jlong *src_elements = (jlong *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jlong *dst_elements =
	    (jlong *) (void *) (((char *) dst_instance) +
				_svmf_aligned_size_t (sizeof
						      (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jlong));
	  goto end;
	}
	break;

      case SVM_TYPE_FLOAT:
	{
	  jfloat *src_elements = (jfloat *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jfloat *dst_elements =
	    (jfloat *) (void *) (((char *) dst_instance) +
				 _svmf_aligned_size_t (sizeof
						       (_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jfloat));
	  goto end;
	}
	break;

      case SVM_TYPE_DOUBLE:
	{
	  jdouble *src_elements = (jdouble *) (void *)
	    (((char *) src_instance) +
	     _svmf_aligned_size_t (sizeof (_svmt_array_instance)));
	  jdouble *dst_elements =
	    (jdouble *) (void *) (((char *) dst_instance) +
				  _svmf_aligned_size_t (sizeof
							(_svmt_array_instance)));

	  memmove (&dst_elements[dst_position],
		   &src_elements[src_position], length * sizeof (jdouble));
	  goto end;
	}
	break;

      default:
	{
	  _svmm_fatal_error ("impossible control flow");
	}
	break;
      }

    assert (src_instance->size >= 0 && dst_instance->size >= 0);
  }

end:
  _svmm_stopping_java (env);
}
