/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_class_initialization
----------------------------------------------------------------------
*/

svm_static jint
_svmf_class_initialization (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  if (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_INITIALIZED))
    {
      return JNI_OK;
    }

  if (_svmm_invoke_nonvirtual_jlclass_initialize
      (env, class->class_instance, env->thread.id) != JNI_OK)
    {
      return JNI_ERR;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_initialize_fields
----------------------------------------------------------------------
*/

svm_static jint
_svmf_initialize_fields (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  jint fields_count = class->fields_count;
  _svmt_field_info *fields = class->fields;
  jint i;

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  for (i = 0; i < fields_count; i++)
    {
      if (_svmf_is_set_flag (fields[i].access_flags, SVM_ACC_STATIC))
	{
	  jint j;
	  jint attributes_count = fields[i].attributes_count;
	  _svmt_attribute_info **attributes = fields[i].attributes;

	  for (j = 0; j < attributes_count; j++)
	    {
	      if (strcmp (DREF (attributes[j]->name, value), "ConstantValue")
		  == 0)
		{
		  _svmt_ConstantValue_attribute *attribute =
		    _svmf_cast_ConstantValue (attributes[j]);

		  switch (DREF (attribute->constantvalue, tag))
		    {
		    default:
		      {
			_svmm_fatal_error ("verifier bug!");
		      }
		      break;

		    case SVM_CONSTANT_Long:
		      {
			_svmt_CONSTANT_Long_info *constant =
			  _svmf_cast_CONSTANT_Long (*
						    (attribute->
						     constantvalue));

			fields[i].data.class_field.value.j = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Float:
		      {
			_svmt_CONSTANT_Float_info *constant =
			  _svmf_cast_CONSTANT_Float (*
						     (attribute->
						      constantvalue));

			fields[i].data.class_field.value.f = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Double:
		      {
			_svmt_CONSTANT_Double_info *constant =
			  _svmf_cast_CONSTANT_Double (*
						      (attribute->
						       constantvalue));

			fields[i].data.class_field.value.d = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Integer:
		      {
			_svmt_CONSTANT_Integer_info *constant =
			  _svmf_cast_CONSTANT_Integer (*
						       (attribute->
							constantvalue));

			char c = *DREF (fields[i].descriptor, value);

			switch (c)
			  {
			  default:
			    {
			      _svmm_fatal_error ("verifier bug!");
			    }
			    break;

			  case 'I':
			    {
			      fields[i].data.class_field.value.i =
				constant->value;
			    }
			    break;

			  case 'S':
			    {
			      fields[i].data.class_field.value.s =
				constant->value;
			    }
			    break;

			  case 'C':
			    {
			      fields[i].data.class_field.value.c =
				constant->value;
			    }
			    break;

			  case 'B':
			    {
			      fields[i].data.class_field.value.b =
				constant->value;
			    }
			    break;

			  case 'Z':
			    {
			      fields[i].data.class_field.value.z =
				constant->value;
			    }
			    break;
			  }
		      }
		      break;

		    case SVM_CONSTANT_String:
		      {
			_svmt_CONSTANT_String_info *constant =
			  _svmf_cast_CONSTANT_String (*
						      (attribute->
						       constantvalue));

			assert (fields[i].data.class_field.value.l != NULL);
			assert (*(fields[i].data.class_field.value.l) ==
				NULL);

			if (_svmf_resolve_CONSTANT_String (env, constant) !=
			    JNI_OK)
			  {
			    return JNI_ERR;
			  }

			*(fields[i].data.class_field.value.l) =
			  *(constant->value);
		      }
		      break;
		    }
		}
	    }
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_special_initialization
----------------------------------------------------------------------
*/

/* This special initialization should only be called at bootstrapping
   time for internally created classes. */

svm_static jint
_svmf_special_initialization (_svmt_JNIEnv *env, _svmt_class_info *class)
{
  jint methods_count = class->methods_count;
  jint fields_count = class->fields_count;
  _svmt_method_info *methods = class->methods;
  _svmt_field_info *fields = class->fields;
  jint i;

  assert (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_PREPARED));

  if (_svmf_is_set_flag (class->state, SVM_TYPE_STATE_INITIALIZED))
    {
      return JNI_OK;
    }

  if (CAN_DREF (class->super_class))
    {
      _svmt_class_info *super_class =
	_svmf_cast_class (DREF (class->super_class, type));

      if (!_svmf_is_set_flag (super_class->state, SVM_TYPE_STATE_INITIALIZED))
	{
	  if (_svmf_special_initialization (env, super_class) != JNI_OK)
	    {
	      return JNI_ERR;
	    }
	}
    }

  for (i = 0; i < methods_count; i++)
    {
      if (strcmp (DREF (methods[i].name, value), "<clinit>") == 0)
	{
	  _svmf_error_InternalError (env);
	  return JNI_ERR;
	}
    }

  for (i = 0; i < fields_count; i++)
    {
      if (_svmf_is_set_flag (fields[i].access_flags, SVM_ACC_STATIC))
	{
	  jint j;
	  jint attributes_count = fields[i].attributes_count;
	  _svmt_attribute_info **attributes = fields[i].attributes;

	  for (j = 0; j < attributes_count; j++)
	    {
	      if (strcmp (DREF (attributes[j]->name, value), "ConstantValue")
		  == 0)
		{
		  _svmt_ConstantValue_attribute *attribute =
		    _svmf_cast_ConstantValue (attributes[j]);

		  switch (DREF (attribute->constantvalue, tag))
		    {
		    default:
		      {
			_svmm_fatal_error ("verifier bug!");
		      }
		      break;

		    case SVM_CONSTANT_Long:
		      {
			_svmt_CONSTANT_Long_info *constant =
			  _svmf_cast_CONSTANT_Long (*
						    (attribute->
						     constantvalue));

			fields[i].data.class_field.value.j = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Float:
		      {
			_svmt_CONSTANT_Float_info *constant =
			  _svmf_cast_CONSTANT_Float (*
						     (attribute->
						      constantvalue));

			fields[i].data.class_field.value.f = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Double:
		      {
			_svmt_CONSTANT_Double_info *constant =
			  _svmf_cast_CONSTANT_Double (*
						      (attribute->
						       constantvalue));

			fields[i].data.class_field.value.d = constant->value;
		      }
		      break;

		    case SVM_CONSTANT_Integer:
		      {
			_svmt_CONSTANT_Integer_info *constant =
			  _svmf_cast_CONSTANT_Integer (*
						       (attribute->
							constantvalue));

			char c = *DREF (fields[i].descriptor, value);

			switch (c)
			  {
			  default:
			    {
			      _svmm_fatal_error ("verifier bug!");
			    }
			    break;

			  case 'I':
			    {
			      fields[i].data.class_field.value.i =
				constant->value;
			    }
			    break;

			  case 'S':
			    {
			      fields[i].data.class_field.value.s =
				constant->value;
			    }
			    break;

			  case 'C':
			    {
			      fields[i].data.class_field.value.c =
				constant->value;
			    }
			    break;

			  case 'B':
			    {
			      fields[i].data.class_field.value.b =
				constant->value;
			    }
			    break;

			  case 'Z':
			    {
			      fields[i].data.class_field.value.z =
				constant->value;
			    }
			    break;
			  }
		      }
		      break;

		    case SVM_CONSTANT_String:
		      {
			/* we do not support "String" constants in specially initialized classes */
			_svmf_error_InternalError (env);
			return JNI_ERR;
		      }
		      break;
		    }
		}
	    }
	}
    }

  _svmm_set_flag (class->state, SVM_TYPE_STATE_INITIALIZED);

  return JNI_OK;
}
