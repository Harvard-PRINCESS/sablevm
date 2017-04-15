/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_UTIL_H
#define SVM_UTIL_H

#define _svmm_global_copy_jobject(env,src,dest) \
_svmh_global_copy_jobject (env, src, &dest)

#define _svmm_zero_memory(var) \
memset(&var, 0, sizeof(var))

#define _svmm_set_flag(value,flag) \
_svmh_set_flag(&value, flag)

#define _svmm_clear_flag(value,flag) \
_svmh_clear_flag(&value, flag)

#define _svmm_validate_min_max_increment(min,max,incr) \
_svmh_validate_min_max_increment (&min, &max, &incr)

#define CANNOT_DREF(structure) (*(structure) == NULL)
#define CAN_DREF(structure) (*(structure) != NULL)
#define DREF(structure,member) ((*(structure))->member)

#define _svmm_new_native_global_array(env, arrayref) \
_svmh_new_native_global_array (env, &arrayref)

#define _svmm_free_native_global_array(env, arrayref) \
_svmh_free_native_global_array (env, &arrayref)

#define _svmm_new_native_local_array(env, arrayref) \
_svmh_new_native_local_array (env, &arrayref)

#define _svmm_free_native_local_array(env, arrayref) \
_svmh_free_native_local_array (env, &arrayref)

#define _svmm_local_wrap_pointer(env, pointer, wrapper) \
_svmh_local_wrap_pointer (env, pointer, &wrapper)

#endif /* NOT SVM_UTIL_H */

#ifdef COMMENT

#define SVM_SET_ARRAY_REFERENCE_ELEMENT(Env,Instance,Index,Value)					\
{													\
  _svmt_array_instance *_array_ = (_svmt_array_instance *) (Instance);					\
  _svmt_array_info *_array_info_ = (_svmt_array_info *) (_array_->vtable->type);			\
  jint _dimensions_ = _array_info_->dimensions;								\
  _svmt_object_instance *_value_ = (_svmt_object_instance *) (Value);					\
													\
  if (_value_ != NULL)											\
    {													\
      if (_dimensions_ == 1)										\
	{												\
	  if (!_svmf_instanceof ((Env), _value_, (_svmt_type_info *) (_array_info_->base_class)))	\
	    {												\
	      goto arraystoreexception;									\
	    }												\
	}												\
      else if (!_svmf_instanceof ((Env), _value_, (_svmt_type_info *) (_array_info_->array_element)))	\
	{												\
	  goto arraystoreexception;									\
	}												\
    }													\
													\
  ((_svmt_object_instance **) (Instance))[- _array_->size + (Index)] = (Value);				\
  WRITE_CARD (((_svmt_object_instance **) (Instance))[- _array_->size + (Index)], ((Env)->vm));		\
}

char *_svmf_current_working_directory (void);
jboolean _svmf_have_same_runtime_package (_svmt_type_info *type1,
					  _svmt_type_info *type2);
jint _svmf_max_jint (jint value1, jint value2);

void _svmf_debug_print_stack_trace (_svmt_JNIEnv *env);
jboolean _svmf_instanceof (_svmt_JNIEnv *env, _svmt_object_instance *obj,
			   _svmt_type_info *type);

#endif /* COMMENT */
