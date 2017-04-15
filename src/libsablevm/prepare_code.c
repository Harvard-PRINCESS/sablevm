/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
_svmf_initialize_instruction_indices
----------------------------------------------------------------------
*/

/*
  for each bytecode, we find whether it represents the start of an
  instruction or not, and we record the result into a index array.
*/

svm_static jint
_svmf_initialize_instruction_indices (_svmt_JNIEnv *env,
				      _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  jint *instruction_indices;
  jint pc;
  jint code_length = method->data.code_attribute->code_length;
  _svmt_u8 *bytecode = method->data.code_attribute->code;
  jint index = 0;

  /* allocate instruction_indices array */
  if (vm->class_loading.method_preparation.instruction_indices != NULL)
    {
      _svmm_gmfree_ints (vm->class_loading.method_preparation.
			 instruction_indices);
    }

  /* we allocate 1 more for the one past end offset */
  if (_svmm_gmalloc_ints
      (env, code_length + 1,
       vm->class_loading.method_preparation.instruction_indices) != JNI_OK)
    {
      return JNI_ERR;
    }

  instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;

  /* for each byte, in the code array, assign an increasing index if
     it is the head of an instruction, or -1 if it is not. */

  for (pc = 0; pc < code_length; pc++)
    {
      jint param_count = vm->instructions[bytecode[pc]].param_count;

      instruction_indices[pc] = index++;

      if (param_count >= 0)
	{
	  jint i;

	  for (i = 0; i < param_count; i++)
	    {
	      instruction_indices[++pc] = -1;
	    }
	}
      else
	{
	  switch (bytecode[pc])
	    {
	    case SVM_INSTRUCTION_WIDE:
	      {
		switch (bytecode[pc + 1])
		  {
		  case SVM_INSTRUCTION_ILOAD:
		  case SVM_INSTRUCTION_LLOAD:
		  case SVM_INSTRUCTION_FLOAD:
		  case SVM_INSTRUCTION_DLOAD:
		  case SVM_INSTRUCTION_ALOAD:
		  case SVM_INSTRUCTION_ISTORE:
		  case SVM_INSTRUCTION_LSTORE:
		  case SVM_INSTRUCTION_FSTORE:
		  case SVM_INSTRUCTION_DSTORE:
		  case SVM_INSTRUCTION_ASTORE:
		  case SVM_INSTRUCTION_RET:
		    {
		      jint i;
		      for (i = 0; i < 3; i++)
			{
			  instruction_indices[++pc] = -1;
			}
		    }
		    break;

		  case SVM_INSTRUCTION_IINC:
		    {
		      jint i;
		      for (i = 0; i < 5; i++)
			{
			  instruction_indices[++pc] = -1;
			}
		    }
		    break;

		  default:
		    {
		      _svmm_fatal_error ("impossible control flow");
		    }
		    break;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_TABLESWITCH:
	      {
		jint low, high, length;
		jint pad = 3 - (pc % 4);
		jint i;

		low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
		high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);

		length = pad + 12 + 4 * (high - low + 1);

		for (i = 0; i < length; i++)
		  {
		    instruction_indices[++pc] = -1;
		  }
	      }
	      break;

	    case SVM_INSTRUCTION_LOOKUPSWITCH:
	      {
		jint npairs, length;
		jint pad = 3 - (pc % 4);
		jint i;

		npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

		length = pad + 8 + 8 * npairs;

		for (i = 0; i < length; i++)
		  {
		    instruction_indices[++pc] = -1;
		  }
	      }
	      break;

	    default:
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	      break;
	    }
	}
    }

  /* we need to know about the instruction just pas the end */
  instruction_indices[pc] = index;

  vm->class_loading.method_preparation.instruction_count = index;

#ifdef STATISTICS

  vm->bytecode_instruction_count += index;
  vm->bytecode_count += code_length;

#endif

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_initialize_instructions
----------------------------------------------------------------------
*/

/*
  we initialize an instruction array. For each instruction, we record
  its offset in the bytecode array and its length, as well as various
  other informations.
*/
svm_static jint
_svmf_initialize_instructions (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  jint pc = 0;

  jint code_length = method->data.code_attribute->code_length;
  _svmt_u8 *bytecode = method->data.code_attribute->code;

  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;
  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;

  _svmt_instruction_preparation *instructions;

  /* allocate instructions array */
  if (vm->class_loading.method_preparation.instructions != NULL)
    {
      _svmm_gzmfree_instruction_preparation (vm->class_loading.
					     method_preparation.instructions);
    }
  if (_svmm_gzmalloc_instruction_preparation
      (env, instruction_count,
       vm->class_loading.method_preparation.instructions) != JNI_OK)
    {
      return JNI_ERR;
    }

  instructions = vm->class_loading.method_preparation.instructions;

  {
    jint bc_length = 0;

    do
      {
	jint instruction_index = instruction_indices[pc];

	if (instruction_index != -1)
	  {
	    instructions[instruction_index].bc_pc = pc;

	    if (instruction_index > 0)
	      {
		instructions[instruction_index - 1].bc_length = bc_length;
		bc_length = 0;
	      }

	    switch (bytecode[pc])
	      {
	      case SVM_INSTRUCTION_LDC:
		{
		  jint offset = bytecode[pc + 1];
		  _svmt_cp_info **constant_pool =
		    method->class_info->constant_pool;

		  switch (constant_pool[offset]->tag)
		    {
		    case SVM_CONSTANT_String:
		      {
			instructions[instruction_index].data.ldc.
			  stringref_info =
			  _svmf_cast_CONSTANT_String (constant_pool[offset]);
		      }
		      break;

		    case SVM_CONSTANT_Integer:
		    case SVM_CONSTANT_Float:
		      {
		      }
		      break;

		    default:
		      {
			_svmm_fatal_error ("impossible control flow");
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_LDC_W:
		{
		  jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
		  _svmt_cp_info **constant_pool =
		    method->class_info->constant_pool;

		  switch (constant_pool[offset]->tag)
		    {
		    case SVM_CONSTANT_String:
		      {
			instructions[instruction_index].data.ldc.
			  stringref_info =
			  _svmf_cast_CONSTANT_String (constant_pool[offset]);
		      }
		      break;

		    case SVM_CONSTANT_Integer:
		    case SVM_CONSTANT_Float:
		      {
		      }
		      break;

		    default:
		      {
			_svmm_fatal_error ("impossible control flow");
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_ILOAD:
	      case SVM_INSTRUCTION_LLOAD:
	      case SVM_INSTRUCTION_FLOAD:
	      case SVM_INSTRUCTION_DLOAD:
	      case SVM_INSTRUCTION_ALOAD:
	      case SVM_INSTRUCTION_ISTORE:
	      case SVM_INSTRUCTION_LSTORE:
	      case SVM_INSTRUCTION_FSTORE:
	      case SVM_INSTRUCTION_DSTORE:
	      case SVM_INSTRUCTION_ASTORE:
	      case SVM_INSTRUCTION_IINC:
	      case SVM_INSTRUCTION_RET:
		{
		  instructions[instruction_index].data.arg.index =
		    bytecode[pc + 1];
		}
		break;

	      case SVM_INSTRUCTION_ILOAD_0:
	      case SVM_INSTRUCTION_LLOAD_0:
	      case SVM_INSTRUCTION_FLOAD_0:
	      case SVM_INSTRUCTION_DLOAD_0:
	      case SVM_INSTRUCTION_ALOAD_0:
	      case SVM_INSTRUCTION_ISTORE_0:
	      case SVM_INSTRUCTION_LSTORE_0:
	      case SVM_INSTRUCTION_FSTORE_0:
	      case SVM_INSTRUCTION_DSTORE_0:
	      case SVM_INSTRUCTION_ASTORE_0:
		{
		  instructions[instruction_index].data.arg.index = 0;
		}
		break;

	      case SVM_INSTRUCTION_ILOAD_1:
	      case SVM_INSTRUCTION_LLOAD_1:
	      case SVM_INSTRUCTION_FLOAD_1:
	      case SVM_INSTRUCTION_DLOAD_1:
	      case SVM_INSTRUCTION_ALOAD_1:
	      case SVM_INSTRUCTION_ISTORE_1:
	      case SVM_INSTRUCTION_LSTORE_1:
	      case SVM_INSTRUCTION_FSTORE_1:
	      case SVM_INSTRUCTION_DSTORE_1:
	      case SVM_INSTRUCTION_ASTORE_1:
		{
		  instructions[instruction_index].data.arg.index = 1;
		}
		break;

	      case SVM_INSTRUCTION_ILOAD_2:
	      case SVM_INSTRUCTION_LLOAD_2:
	      case SVM_INSTRUCTION_FLOAD_2:
	      case SVM_INSTRUCTION_DLOAD_2:
	      case SVM_INSTRUCTION_ALOAD_2:
	      case SVM_INSTRUCTION_ISTORE_2:
	      case SVM_INSTRUCTION_LSTORE_2:
	      case SVM_INSTRUCTION_FSTORE_2:
	      case SVM_INSTRUCTION_DSTORE_2:
	      case SVM_INSTRUCTION_ASTORE_2:
		{
		  instructions[instruction_index].data.arg.index = 2;
		}
		break;

	      case SVM_INSTRUCTION_ILOAD_3:
	      case SVM_INSTRUCTION_LLOAD_3:
	      case SVM_INSTRUCTION_FLOAD_3:
	      case SVM_INSTRUCTION_DLOAD_3:
	      case SVM_INSTRUCTION_ALOAD_3:
	      case SVM_INSTRUCTION_ISTORE_3:
	      case SVM_INSTRUCTION_LSTORE_3:
	      case SVM_INSTRUCTION_FSTORE_3:
	      case SVM_INSTRUCTION_DSTORE_3:
	      case SVM_INSTRUCTION_ASTORE_3:
		{
		  instructions[instruction_index].data.arg.index = 3;
		}
		break;

	      case SVM_INSTRUCTION_WIDE:
		{
		  instructions[instruction_index].data.arg.index =
		    _svmf_bytes_to_u16 (&bytecode[pc + 2]);
		}
		break;

	      case SVM_INSTRUCTION_IFEQ:
	      case SVM_INSTRUCTION_IFNE:
	      case SVM_INSTRUCTION_IFLT:
	      case SVM_INSTRUCTION_IFGE:
	      case SVM_INSTRUCTION_IFGT:
	      case SVM_INSTRUCTION_IFLE:
	      case SVM_INSTRUCTION_IF_ICMPEQ:
	      case SVM_INSTRUCTION_IF_ICMPNE:
	      case SVM_INSTRUCTION_IF_ICMPLT:
	      case SVM_INSTRUCTION_IF_ICMPGE:
	      case SVM_INSTRUCTION_IF_ICMPGT:
	      case SVM_INSTRUCTION_IF_ICMPLE:
	      case SVM_INSTRUCTION_IF_ACMPEQ:
	      case SVM_INSTRUCTION_IF_ACMPNE:
	      case SVM_INSTRUCTION_GOTO:
	      case SVM_INSTRUCTION_JSR:
	      case SVM_INSTRUCTION_IFNULL:
	      case SVM_INSTRUCTION_IFNONNULL:
		{
		  jint offset = _svmf_bytes_to_s16 (&bytecode[pc + 1]);
		  jint target_index = instruction_indices[pc + offset];

		  instructions[instruction_index].data.branch.target =
		    &instructions[target_index];

		  if (target_index <= instruction_index)
		    {
		      instructions[instruction_index].has_backward_target = 1;
		      instructions[instruction_index].data.branch.target->
			is_backward_branch_target = 1;
		    }
		}
		break;

	      case SVM_INSTRUCTION_GOTO_W:
	      case SVM_INSTRUCTION_JSR_W:
		{
		  jint offset = _svmf_bytes_to_s32 (&bytecode[pc + 1]);
		  jint target_index = instruction_indices[pc + offset];

		  instructions[instruction_index].data.branch.target =
		    &instructions[target_index];

		  if (target_index <= instruction_index)
		    {
		      instructions[instruction_index].has_backward_target = 1;
		      instructions[instruction_index].data.branch.target->
			is_backward_branch_target = 1;
		    }
		}
		break;

	      case SVM_INSTRUCTION_TABLESWITCH:
		{
		  jint default_offset, low, high, length;
		  jint pad = 3 - (pc % 4);
		  jint base = pc + 1 + pad + 12;
		  jint i;

		  default_offset =
		    _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);

		  {
		    jint target_index =
		      instruction_indices[pc + default_offset];

		    if (target_index <= instruction_index)
		      {
			instructions[instruction_index].has_backward_target =
			  1;
		      }
		  }

		  low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
		  high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
		  length = high - low + 1;

		  for (i = 0; i < length; i++)
		    {
		      jint offset =
			_svmf_bytes_to_s32 (&bytecode[base + 4 * i]);
		      jint target_index = instruction_indices[pc + offset];

		      if (target_index <= instruction_index)
			{
			  instructions[instruction_index].
			    has_backward_target = 1;
			}
		    }

		  if (instructions[instruction_index].has_backward_target)
		    {
		      {
			jint target_index =
			  instruction_indices[pc + default_offset];
			_svmt_instruction_preparation *target =
			  &instructions[target_index];

			target->is_backward_switch_target = 1;
		      }

		      for (i = 0; i < length; i++)
			{
			  jint offset =
			    _svmf_bytes_to_s32 (&bytecode[base + 4 * i]);
			  jint target_index =
			    instruction_indices[pc + offset];
			  _svmt_instruction_preparation *target =
			    &instructions[target_index];

			  target->is_backward_switch_target = 1;
			}
		    }
		}
		break;

	      case SVM_INSTRUCTION_LOOKUPSWITCH:
		{
		  jint default_offset, npairs;
		  jint pad = 3 - (pc % 4);
		  jint base = pc + 1 + pad + 8;
		  jint i;

		  default_offset =
		    _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);

		  {
		    jint target_index =
		      instruction_indices[pc + default_offset];

		    if (target_index <= instruction_index)
		      {
			instructions[instruction_index].has_backward_target =
			  1;
		      }
		  }

		  npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

		  for (i = 0; i < npairs; i++)
		    {
		      jint offset =
			_svmf_bytes_to_s32 (&bytecode[base + 8 * i + 4]);
		      jint target_index = instruction_indices[pc + offset];

		      if (target_index <= instruction_index)
			{
			  instructions[instruction_index].
			    has_backward_target = 1;
			}
		    }

		  if (instructions[instruction_index].has_backward_target)
		    {
		      {
			jint target_index =
			  instruction_indices[pc + default_offset];
			_svmt_instruction_preparation *target =
			  &instructions[target_index];

			target->is_backward_switch_target = 1;
		      }

		      npairs =
			_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

		      for (i = 0; i < npairs; i++)
			{
			  jint offset =
			    _svmf_bytes_to_s32 (&bytecode[base + 8 * i + 4]);
			  jint target_index =
			    instruction_indices[pc + offset];
			  _svmt_instruction_preparation *target =
			    &instructions[target_index];

			  target->is_backward_switch_target = 1;
			}
		    }
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC:
	      case SVM_INSTRUCTION_PUTSTATIC:
	      case SVM_INSTRUCTION_GETFIELD:
	      case SVM_INSTRUCTION_PUTFIELD:
		{
		  jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
		  _svmt_cp_info **constant_pool =
		    method->class_info->constant_pool;

		  instructions[instruction_index].data.fieldref.info =
		    _svmf_cast_CONSTANT_Fieldref (constant_pool[offset]);
		}
		break;

	      case SVM_INSTRUCTION_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_INVOKESPECIAL:
	      case SVM_INSTRUCTION_INVOKESTATIC:
		{
		  jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
		  _svmt_cp_info **constant_pool =
		    method->class_info->constant_pool;

		  instructions[instruction_index].data.methodref.info =
		    _svmf_cast_CONSTANT_Methodref (constant_pool[offset]);
		}
		break;

	      case SVM_INSTRUCTION_INVOKEINTERFACE:
		{
		  jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
		  _svmt_cp_info **constant_pool =
		    method->class_info->constant_pool;

		  instructions[instruction_index].data.imethodref.info =
		    _svmf_cast_CONSTANT_InterfaceMethodref (constant_pool
							    [offset]);
		}
		break;
	      }
	  }

	bc_length++;

      }
    while (++pc < code_length);

    instructions[instruction_count - 1].bc_length = bc_length;
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_resolve_gc_site_reach
----------------------------------------------------------------------
*/

/*
  The idea here is that, in a multi-threaded environment, we need to
  check for gc requests at least once in every loop iteration. One
  obvious way is to implement gc checks at every back branch
  point. But, we can be smarter. We need not do a check on a back
  branch if we branch to a basic block that already contains a gc
  check.

  This function marks all instructions that are unconditionally
  followed by a gc check. Of course this is a simplified explanation;
  the reality is more complex (dealing with exceptions, jsr/ret,
  ...). See thesis for details.
 */

svm_static jint
_svmf_resolve_gc_site_reach (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;

  _svmt_u8 *bytecode = method->data.code_attribute->code;

  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;

  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;

  jint i;
  jint reaches_gc_site = 0;

  for (i = instruction_count - 1; i >= 0; i--)
    {
      jint pc = instructions[i].bc_pc;

      switch (bytecode[pc])
	{
	case SVM_INSTRUCTION_RET:
	case SVM_INSTRUCTION_IRETURN:
	case SVM_INSTRUCTION_LRETURN:
	case SVM_INSTRUCTION_FRETURN:
	case SVM_INSTRUCTION_DRETURN:
	case SVM_INSTRUCTION_ARETURN:
	case SVM_INSTRUCTION_RETURN:
	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:
	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_NEWARRAY:
	case SVM_INSTRUCTION_ANEWARRAY:
	case SVM_INSTRUCTION_ATHROW:
	case SVM_INSTRUCTION_MULTIANEWARRAY:
	  {
	    reaches_gc_site = 1;
	  }
	  break;

	case SVM_INSTRUCTION_WIDE:
	  {
	    switch (bytecode[pc + 1])
	      {
	      case SVM_INSTRUCTION_RET:
		{
		  reaches_gc_site = 1;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFEQ:
	case SVM_INSTRUCTION_IFNE:
	case SVM_INSTRUCTION_IFLT:
	case SVM_INSTRUCTION_IFGE:
	case SVM_INSTRUCTION_IFGT:
	case SVM_INSTRUCTION_IFLE:
	case SVM_INSTRUCTION_IF_ICMPEQ:
	case SVM_INSTRUCTION_IF_ICMPNE:
	case SVM_INSTRUCTION_IF_ICMPLT:
	case SVM_INSTRUCTION_IF_ICMPGE:
	case SVM_INSTRUCTION_IF_ICMPGT:
	case SVM_INSTRUCTION_IF_ICMPLE:
	case SVM_INSTRUCTION_IF_ACMPEQ:
	case SVM_INSTRUCTION_IF_ACMPNE:
	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_TABLESWITCH:
	case SVM_INSTRUCTION_LOOKUPSWITCH:
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	case SVM_INSTRUCTION_GOTO_W:
	case SVM_INSTRUCTION_JSR_W:
	  {
	    reaches_gc_site = 0;
	  }
	  break;
	}

      instructions[i].reaches_gc_site = reaches_gc_site;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzalloc_stack_and_local_map
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_stack_and_local_map(env, method, ptr) \
_svmh_gzalloc_stack_and_local_map (env, method, &ptr)

svm_static jint
_svmh_gzalloc_stack_and_local_map (_svmt_JNIEnv *env,
				   _svmt_method_info *method,
				   _svmt_stack_and_local_map **ptr)
{
  _svmt_stack_and_local_map *tmp;

  tmp =
    _svmf_calloc (1, sizeof (_svmt_stack_and_local_map) +
		  (method->data.code_attribute->max_stack +
		   method->data.code_attribute->max_locals) * sizeof (jint));

  if (tmp == NULL)
    {
      _svmf_error_OutOfMemoryError (env);
      return JNI_ERR;
    }

  tmp->stack = (jint *) (tmp + 1);
  tmp->locals = &tmp->stack[method->data.code_attribute->max_stack];

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_gzfree_stack_and_local_map
----------------------------------------------------------------------
*/

#define _svmm_gzfree_stack_and_local_map(ptr) \
_svmh_gzfree_stack_and_local_map (&ptr)

svm_static void
_svmh_gzfree_stack_and_local_map (_svmt_stack_and_local_map **ptr)
{
#ifndef NDEBUG

  if (*ptr == NULL)
    {
      _svmm_fatal_error ("attempt to free a NULL pointer");
    }

#endif /* not NDEBUG */

  _svmf_free (*ptr);
  *ptr = NULL;
}

/*
----------------------------------------------------------------------
_svmh_copy_stack_and_local_map
----------------------------------------------------------------------
*/

#define _svmm_copy_stack_and_local_map(env, method, map, ptr) \
_svmh_copy_stack_and_local_map (env, method, map, &ptr)

svm_static jint
_svmh_copy_stack_and_local_map (_svmt_JNIEnv *env,
				_svmt_method_info *method,
				_svmt_stack_and_local_map *map,
				_svmt_stack_and_local_map **ptr)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_stack_and_local_map *tmp;
  jint stack_size = map->stack_size;
  jint locals_size = method->data.code_attribute->max_locals;
  jint i;

  if (vm->class_loading.method_preparation.free_list != NULL)
    {
      tmp = vm->class_loading.method_preparation.free_list;
      vm->class_loading.method_preparation.free_list = tmp->free_list_next;
      tmp->free_list_next = NULL;
    }
  else
    {
      if (_svmm_gzalloc_stack_and_local_map (env, method, tmp) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  tmp->stack_size = stack_size;

  for (i = 0; i < stack_size; i++)
    {
      tmp->stack[i] = map->stack[i];
    }

  for (i = 0; i < locals_size; i++)
    {
      tmp->locals[i] = map->locals[i];
    }

  *ptr = tmp;
  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_count_descriptor_args
----------------------------------------------------------------------
*/

inline svm_static jint
_svmf_count_descriptor_args (const char *descriptor)
{
  /* skip '(' */
  const char *p = descriptor + 1;
  jint count = 0;

  while (*p != ')')
    {
      switch (*p)
	{
	case 'B':
	case 'C':
	case 'F':
	case 'I':
	case 'S':
	case 'Z':
	  {
	    count++;
	  }
	  break;

	case 'D':
	case 'J':
	  {
	    count += 2;
	  }
	  break;

	case 'L':
	  {
	    count++;

	    /* skip to next ';' */
	    while (*++p != ';');
	  }
	  break;

	case '[':
	  {
	    count++;

	    /* skip all '[' */
	    while (*++p == '[');

	    if (*p == 'L')
	      {
		/* skip to next ';' */
		while (*++p != ';');
	      }
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}

      ++p;
    }

  return count;
}

/*
----------------------------------------------------------------------
_svmf_store_stack_gc_map
----------------------------------------------------------------------
*/

svm_static jint
_svmf_store_stack_gc_map (_svmt_JNIEnv *env,
			  _svmt_instruction_preparation *instruction)
{
  _svmt_JavaVM *vm = env->vm;
  jint stack_size = instruction->stack_and_local_map->stack_size;

  if (_svmm_gzalloc_gc_map_node (env, instruction->stack_gc_map) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* we discard trailing non-reference stack locations */
  while (stack_size > 0)
    {
      if (instruction->stack_and_local_map->stack[stack_size - 1] ==
	  SVM_STACK_MAP_REF)
	{
	  break;
	}

      stack_size--;
    }

  instruction->stack_gc_map->size = stack_size;

  if (stack_size > 0)
    {
      jint i;

      if (_svmm_gzmalloc_ubytes
	  (env, (stack_size + 7) / 8,
	   instruction->stack_gc_map->bits) != JNI_OK)
	{
	  return JNI_ERR;
	}

      for (i = 0; i < stack_size; i++)
	{
	  if (instruction->stack_and_local_map->stack[i] == SVM_STACK_MAP_REF)
	    {
	      _svmf_set_bit (instruction->stack_gc_map->bits, i);
	    }
	}
    }

  /* reuse identical map, if it exists */
  {
    _svmt_gc_map_node *map =
      _svmm_tree_find_gc_map (vm->class_loading.gc_map_tree,
			      instruction->stack_gc_map);

    if (map == NULL)
      {
#ifdef STATISTICS

	vm->total_gc_maps_count++;
	vm->total_gc_maps_size +=
	  _svmf_aligned_size_t (sizeof (_svmt_gc_map_node)) +
	  _svmf_aligned_size_t ((instruction->stack_gc_map->size + 7) / 8);

#endif

	_svmm_tree_insert_gc_map (vm->class_loading.gc_map_tree,
				  instruction->stack_gc_map);
      }
    else
      {
	if (instruction->stack_gc_map->size > 0)
	  {
	    _svmm_gzmfree_ubytes (instruction->stack_gc_map->bits);
	  }

	_svmm_gzfree_gc_map_node (instruction->stack_gc_map);

	instruction->stack_gc_map = map;
      }
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_compute_stack_gc_maps
----------------------------------------------------------------------
*/

/*
  This one is tricky. See explanations in my thesis. Mainly, we take
  advantage that the code is verifiable to implement a one-pass
  pseudo-flow algorithm that (a) computes stack maps, (b) resolves ret
  instructions, and (c) identifies "address" (ret/jsr) operands.

  One could argue that the verifier could have precomputed this
  information, but to reduce the complexity of the VM we assume that
  code loaded through the bootstrap class loader can be trusted to be
  verifiable (these classes are normally restricted to a subset of
  those shipped with the VM). All remaining code should have undergone
  verification before reaching this point. This allows for (partly)
  implementing the verifier in Java. [Of course, a verifier written in
  Java cannot verify its own code, this is why we need to trust an
  initial set of classes].
*/

svm_static jint
_svmf_compute_stack_gc_maps (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;

  _svmt_u8 *bytecode = method->data.code_attribute->code;

  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;

  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;

  /* note: the work list is, in fact, a stack */
  _svmt_instruction_preparation *work_list;

  /* put first instruction on work list */
  work_list = &instructions[0];
  work_list->reachable = 1;

  /* allocate stack/locals of first instruction */
  if (_svmm_gzalloc_stack_and_local_map
      (env, method, work_list->stack_and_local_map) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* allocate global locals information */
  if (vm->class_loading.method_preparation.locals != NULL)
    {
      _svmm_gzmfree_local_preparation (vm->class_loading.method_preparation.
				       locals);
    }

  if (method->data.code_attribute->max_locals > 0)
    {
      if (_svmm_gzmalloc_local_preparation
	  (env, method->data.code_attribute->max_locals,
	   vm->class_loading.method_preparation.locals) != JNI_OK)
	{
	  return JNI_ERR;
	}
    }

  /* make sure free_list is empty (do not *ever* reuse free_list items
     of another method; the stack/local size might not match!) */
  if (vm->class_loading.method_preparation.free_list != NULL)
    {
      _svmt_stack_and_local_map *free_list =
	vm->class_loading.method_preparation.free_list;
      vm->class_loading.method_preparation.free_list = NULL;

      while (free_list != NULL)
	{
	  _svmt_stack_and_local_map *current = free_list;

	  free_list = free_list->free_list_next;
	  _svmm_gzfree_stack_and_local_map (current);
	}
    }

  /* process work list */
  while (work_list != NULL)
    {
      _svmt_instruction_preparation *instruction = work_list;
      _svmt_instruction_preparation *next_instruction = instruction + 1;
      jint pc = instruction->bc_pc;

      work_list = work_list->work_list_next;
      instruction->work_list_next = NULL;

      assert (instruction->reachable);
      assert (instruction->stack_and_local_map->stack_size >= 0);
      assert (instruction->stack_and_local_map->stack_size <=
	      method->data.code_attribute->max_stack);

      /* if instruction requires gc map, store it */
      {
	jint requires_gc_map = 0;

	switch (bytecode[pc])
	  {
	  case SVM_INSTRUCTION_LDC:
	  case SVM_INSTRUCTION_LDC_W:
	  case SVM_INSTRUCTION_GETSTATIC:
	  case SVM_INSTRUCTION_PUTSTATIC:
	  case SVM_INSTRUCTION_GETFIELD:
	  case SVM_INSTRUCTION_PUTFIELD:
	  case SVM_INSTRUCTION_INVOKEVIRTUAL:
	  case SVM_INSTRUCTION_INVOKESPECIAL:
	  case SVM_INSTRUCTION_INVOKESTATIC:
	  case SVM_INSTRUCTION_INVOKEINTERFACE:
	  case SVM_INSTRUCTION_NEW:
	  case SVM_INSTRUCTION_NEWARRAY:
	  case SVM_INSTRUCTION_ANEWARRAY:
	  case SVM_INSTRUCTION_CHECKCAST:
	  case SVM_INSTRUCTION_INSTANCEOF:
	  case SVM_INSTRUCTION_MULTIANEWARRAY:
	  case SVM_INSTRUCTION_MONITORENTER:
	    {
	      /* always require a gc map */
	      requires_gc_map = 1;
	    }
	    break;

	  default:
	    {
	      /* requires a map if it is a backward switch target, or
	         if it is a backward branch target which isn't
	         followed by a gc check site */
	      requires_gc_map = instruction->is_backward_switch_target
		|| (instruction->is_backward_branch_target
		    && !instruction->reaches_gc_site);
	    }
	  }

	if (requires_gc_map)
	  {
#ifdef STATISTICS

	    vm->check_points_count++;

#endif

	    if (_svmf_store_stack_gc_map (env, instruction) != JNI_OK)
	      {
		return JNI_ERR;
	      }
	  }
      }

      /* if the instruction is covered by exception handlers, add
         exception hanlders into work list */
      {
	jint exception_table_length =
	  method->data.code_attribute->exception_table_length;
	_svmt_exception_table *exception_table =
	  method->data.code_attribute->exception_table;
	jint i;

	for (i = 0; i < exception_table_length; i++)
	  {
	    if (pc >= exception_table[i].start_pc &&
		pc < exception_table[i].end_pc)
	      {
		_svmt_instruction_preparation *handler =
		  &instructions[instruction_indices
				[exception_table[i].handler_pc]];

		if (!handler->reachable)
		  {
		    /* put instruction on work list */
		    if (_svmm_copy_stack_and_local_map
			(env, method, instruction->stack_and_local_map,
			 handler->stack_and_local_map) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    handler->reachable = 1;
		    assert (handler->work_list_next == NULL);
		    handler->work_list_next = work_list;
		    work_list = handler;

		    /* empty stack then push a reference */
		    handler->stack_and_local_map->stack_size = 1;
		    handler->stack_and_local_map->stack[0] =
		      SVM_STACK_MAP_REF;
		  }
	      }
	  }
      }

      switch (bytecode[pc])
	{
	case SVM_INSTRUCTION_NOP:
	case SVM_INSTRUCTION_INEG:
	case SVM_INSTRUCTION_LNEG:
	case SVM_INSTRUCTION_FNEG:
	case SVM_INSTRUCTION_DNEG:
	case SVM_INSTRUCTION_I2F:
	case SVM_INSTRUCTION_L2D:
	case SVM_INSTRUCTION_F2I:
	case SVM_INSTRUCTION_D2L:
	case SVM_INSTRUCTION_I2B:
	case SVM_INSTRUCTION_I2C:
	case SVM_INSTRUCTION_I2S:
	case SVM_INSTRUCTION_CHECKCAST:
	  {
	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ACONST_NULL:
	case SVM_INSTRUCTION_NEW:
	  {
	    /* push a reference on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_REF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ICONST_M1:
	case SVM_INSTRUCTION_ICONST_0:
	case SVM_INSTRUCTION_ICONST_1:
	case SVM_INSTRUCTION_ICONST_2:
	case SVM_INSTRUCTION_ICONST_3:
	case SVM_INSTRUCTION_ICONST_4:
	case SVM_INSTRUCTION_ICONST_5:
	case SVM_INSTRUCTION_FCONST_0:
	case SVM_INSTRUCTION_FCONST_1:
	case SVM_INSTRUCTION_FCONST_2:
	case SVM_INSTRUCTION_BIPUSH:
	case SVM_INSTRUCTION_SIPUSH:
	case SVM_INSTRUCTION_I2L:
	case SVM_INSTRUCTION_I2D:
	case SVM_INSTRUCTION_F2L:
	case SVM_INSTRUCTION_F2D:
	  {
	    /* push a nonref on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LCONST_0:
	case SVM_INSTRUCTION_LCONST_1:
	case SVM_INSTRUCTION_DCONST_0:
	case SVM_INSTRUCTION_DCONST_1:
	case SVM_INSTRUCTION_LDC2_W:
	  {
	    /* push 2 nonrefs on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LDC:
	case SVM_INSTRUCTION_LDC_W:
	  {
	    if (instruction->data.ldc.stringref_info != NULL)
	      {
		/* push a reference on stack */
		instruction->stack_and_local_map->stack
		  [instruction->stack_and_local_map->stack_size++] =
		  SVM_STACK_MAP_REF;
	      }
	    else
	      {
		/* push a nonref on stack */
		instruction->stack_and_local_map->stack
		  [instruction->stack_and_local_map->stack_size++] =
		  SVM_STACK_MAP_NONREF;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ILOAD:
	case SVM_INSTRUCTION_FLOAD:
	case SVM_INSTRUCTION_ILOAD_0:
	case SVM_INSTRUCTION_FLOAD_0:
	case SVM_INSTRUCTION_ILOAD_1:
	case SVM_INSTRUCTION_FLOAD_1:
	case SVM_INSTRUCTION_ILOAD_2:
	case SVM_INSTRUCTION_FLOAD_2:
	case SVM_INSTRUCTION_ILOAD_3:
	case SVM_INSTRUCTION_FLOAD_3:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as nonref */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_non_ref = 1;

	    /* push a nonref on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LLOAD:
	case SVM_INSTRUCTION_DLOAD:
	case SVM_INSTRUCTION_LLOAD_0:
	case SVM_INSTRUCTION_DLOAD_0:
	case SVM_INSTRUCTION_LLOAD_1:
	case SVM_INSTRUCTION_DLOAD_1:
	case SVM_INSTRUCTION_LLOAD_2:
	case SVM_INSTRUCTION_DLOAD_2:
	case SVM_INSTRUCTION_LLOAD_3:
	case SVM_INSTRUCTION_DLOAD_3:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as long */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_long = 1;

	    /* push 2 nonrefs on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ALOAD:
	case SVM_INSTRUCTION_ALOAD_0:
	case SVM_INSTRUCTION_ALOAD_1:
	case SVM_INSTRUCTION_ALOAD_2:
	case SVM_INSTRUCTION_ALOAD_3:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as reference */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_ref = 1;

	    /* push a reference on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_REF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_IALOAD:
	case SVM_INSTRUCTION_FALOAD:
	case SVM_INSTRUCTION_BALOAD:
	case SVM_INSTRUCTION_CALOAD:
	case SVM_INSTRUCTION_SALOAD:
	  {
	    /* pop 1 element and replace top by nonref */
	    instruction->stack_and_local_map->stack_size--;
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 1] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LALOAD:
	case SVM_INSTRUCTION_DALOAD:
	  {
	    /* replace top 2 elements by nonref */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 1] =
	      SVM_STACK_MAP_NONREF;
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 2] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_AALOAD:
	  {
	    /* pop 1 element and replace top by ref */
	    instruction->stack_and_local_map->stack_size--;
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 1] =
	      SVM_STACK_MAP_REF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ISTORE:
	case SVM_INSTRUCTION_FSTORE:
	case SVM_INSTRUCTION_ISTORE_0:
	case SVM_INSTRUCTION_FSTORE_0:
	case SVM_INSTRUCTION_ISTORE_1:
	case SVM_INSTRUCTION_FSTORE_1:
	case SVM_INSTRUCTION_ISTORE_2:
	case SVM_INSTRUCTION_FSTORE_2:
	case SVM_INSTRUCTION_ISTORE_3:
	case SVM_INSTRUCTION_FSTORE_3:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as nonref */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_non_ref = 1;

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LSTORE:
	case SVM_INSTRUCTION_DSTORE:
	case SVM_INSTRUCTION_LSTORE_0:
	case SVM_INSTRUCTION_DSTORE_0:
	case SVM_INSTRUCTION_LSTORE_1:
	case SVM_INSTRUCTION_DSTORE_1:
	case SVM_INSTRUCTION_LSTORE_2:
	case SVM_INSTRUCTION_DSTORE_2:
	case SVM_INSTRUCTION_LSTORE_3:
	case SVM_INSTRUCTION_DSTORE_3:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as long */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_long = 1;

	    /* pop 2 elements */
	    instruction->stack_and_local_map->stack_size -= 2;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ASTORE:
	case SVM_INSTRUCTION_ASTORE_0:
	case SVM_INSTRUCTION_ASTORE_1:
	case SVM_INSTRUCTION_ASTORE_2:
	case SVM_INSTRUCTION_ASTORE_3:
	  {
	    jint index = instruction->data.arg.index;

	    if (instruction->stack_and_local_map->
		stack[instruction->stack_and_local_map->stack_size - 1] >= 0)
	      {
		/* mark local as nonref */
		vm->class_loading.method_preparation.locals[index].
		  used_as_non_ref = 1;

		/* record that stack top is an address */
		instruction->addr_stack_top = 1;

		/* copy address into local */
		instruction->stack_and_local_map->locals[index] =
		  instruction->stack_and_local_map->stack[instruction->
							  stack_and_local_map->
							  stack_size - 1];
	      }
	    else
	      {
		/* mark local as reference */
		vm->class_loading.method_preparation.locals[index].
		  used_as_ref = 1;
	      }

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_IASTORE:
	case SVM_INSTRUCTION_FASTORE:
	case SVM_INSTRUCTION_AASTORE:
	case SVM_INSTRUCTION_BASTORE:
	case SVM_INSTRUCTION_CASTORE:
	case SVM_INSTRUCTION_SASTORE:
	case SVM_INSTRUCTION_LCMP:
	case SVM_INSTRUCTION_DCMPL:
	case SVM_INSTRUCTION_DCMPG:
	  {
	    /* pop 3 elements */
	    instruction->stack_and_local_map->stack_size -= 3;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_LASTORE:
	case SVM_INSTRUCTION_DASTORE:
	  {
	    /* pop 4 elements */
	    instruction->stack_and_local_map->stack_size -= 4;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_POP:
	case SVM_INSTRUCTION_IADD:
	case SVM_INSTRUCTION_FADD:
	case SVM_INSTRUCTION_ISUB:
	case SVM_INSTRUCTION_FSUB:
	case SVM_INSTRUCTION_IMUL:
	case SVM_INSTRUCTION_FMUL:
	case SVM_INSTRUCTION_IDIV:
	case SVM_INSTRUCTION_FDIV:
	case SVM_INSTRUCTION_IREM:
	case SVM_INSTRUCTION_FREM:
	case SVM_INSTRUCTION_ISHL:
	case SVM_INSTRUCTION_LSHL:
	case SVM_INSTRUCTION_ISHR:
	case SVM_INSTRUCTION_LSHR:
	case SVM_INSTRUCTION_IUSHR:
	case SVM_INSTRUCTION_LUSHR:
	case SVM_INSTRUCTION_IAND:
	case SVM_INSTRUCTION_IOR:
	case SVM_INSTRUCTION_IXOR:
	case SVM_INSTRUCTION_L2I:
	case SVM_INSTRUCTION_L2F:
	case SVM_INSTRUCTION_D2I:
	case SVM_INSTRUCTION_D2F:
	case SVM_INSTRUCTION_FCMPL:
	case SVM_INSTRUCTION_FCMPG:
	case SVM_INSTRUCTION_MONITORENTER:
	case SVM_INSTRUCTION_MONITOREXIT:
	  {
	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_POP2:
	case SVM_INSTRUCTION_LADD:
	case SVM_INSTRUCTION_DADD:
	case SVM_INSTRUCTION_LSUB:
	case SVM_INSTRUCTION_DSUB:
	case SVM_INSTRUCTION_LMUL:
	case SVM_INSTRUCTION_DMUL:
	case SVM_INSTRUCTION_LDIV:
	case SVM_INSTRUCTION_DDIV:
	case SVM_INSTRUCTION_LREM:
	case SVM_INSTRUCTION_DREM:
	case SVM_INSTRUCTION_LAND:
	case SVM_INSTRUCTION_LOR:
	case SVM_INSTRUCTION_LXOR:
	  {
	    /* pop 2 elements */
	    instruction->stack_and_local_map->stack_size -= 2;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size++;
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 1];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP_X1:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size++;
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    instruction->stack_and_local_map->stack[stack_size - 1] =
	      instruction->stack_and_local_map->stack[stack_size - 2];
	    instruction->stack_and_local_map->stack[stack_size - 2] =
	      instruction->stack_and_local_map->stack[stack_size];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP_X2:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size++;
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    instruction->stack_and_local_map->stack[stack_size - 1] =
	      instruction->stack_and_local_map->stack[stack_size - 2];
	    instruction->stack_and_local_map->stack[stack_size - 2] =
	      instruction->stack_and_local_map->stack[stack_size - 3];
	    instruction->stack_and_local_map->stack[stack_size - 3] =
	      instruction->stack_and_local_map->stack[stack_size];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP2:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size += 2;
	    instruction->stack_and_local_map->stack[stack_size + 1] =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 2];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP2_X1:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size += 2;
	    instruction->stack_and_local_map->stack[stack_size + 1] =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 2];
	    instruction->stack_and_local_map->stack[stack_size - 1] =
	      instruction->stack_and_local_map->stack[stack_size - 3];
	    instruction->stack_and_local_map->stack[stack_size - 2] =
	      instruction->stack_and_local_map->stack[stack_size + 1];
	    instruction->stack_and_local_map->stack[stack_size - 3] =
	      instruction->stack_and_local_map->stack[stack_size];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_DUP2_X2:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    instruction->stack_and_local_map->stack_size += 2;
	    instruction->stack_and_local_map->stack[stack_size + 1] =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    instruction->stack_and_local_map->stack[stack_size] =
	      instruction->stack_and_local_map->stack[stack_size - 2];
	    instruction->stack_and_local_map->stack[stack_size - 1] =
	      instruction->stack_and_local_map->stack[stack_size - 3];
	    instruction->stack_and_local_map->stack[stack_size - 2] =
	      instruction->stack_and_local_map->stack[stack_size - 4];
	    instruction->stack_and_local_map->stack[stack_size - 3] =
	      instruction->stack_and_local_map->stack[stack_size + 1];
	    instruction->stack_and_local_map->stack[stack_size - 4] =
	      instruction->stack_and_local_map->stack[stack_size];

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_SWAP:
	  {
	    int stack_size = instruction->stack_and_local_map->stack_size;
	    jint value1 =
	      instruction->stack_and_local_map->stack[stack_size - 1];
	    jint value2 =
	      instruction->stack_and_local_map->stack[stack_size - 2];
	    instruction->stack_and_local_map->stack[stack_size - 1] = value2;
	    instruction->stack_and_local_map->stack[stack_size - 2] = value1;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_IINC:
	  {
	    jint index = instruction->data.arg.index;

	    /* mark local as nonref */
	    vm->class_loading.method_preparation.locals[index].
	      used_as_non_ref = 1;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_IFEQ:
	case SVM_INSTRUCTION_IFNE:
	case SVM_INSTRUCTION_IFLT:
	case SVM_INSTRUCTION_IFGE:
	case SVM_INSTRUCTION_IFGT:
	case SVM_INSTRUCTION_IFLE:
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	  {
	    _svmt_instruction_preparation *target =
	      instruction->data.branch.target;

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    if (!target->reachable)
	      {
		/* put instruction on work list */
		if (_svmm_copy_stack_and_local_map
		    (env, method, instruction->stack_and_local_map,
		     target->stack_and_local_map) != JNI_OK)
		  {
		    return JNI_ERR;
		  }
		target->reachable = 1;
		assert (target->work_list_next == NULL);
		target->work_list_next = work_list;
		work_list = target;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPEQ:
	case SVM_INSTRUCTION_IF_ICMPNE:
	case SVM_INSTRUCTION_IF_ICMPLT:
	case SVM_INSTRUCTION_IF_ICMPGE:
	case SVM_INSTRUCTION_IF_ICMPGT:
	case SVM_INSTRUCTION_IF_ICMPLE:
	case SVM_INSTRUCTION_IF_ACMPEQ:
	case SVM_INSTRUCTION_IF_ACMPNE:
	  {
	    _svmt_instruction_preparation *target =
	      instruction->data.branch.target;

	    /* pop 2 elements */
	    instruction->stack_and_local_map->stack_size -= 2;

	    if (!target->reachable)
	      {
		/* put instruction on work list */
		if (_svmm_copy_stack_and_local_map
		    (env, method, instruction->stack_and_local_map,
		     target->stack_and_local_map) != JNI_OK)
		  {
		    return JNI_ERR;
		  }
		target->reachable = 1;
		assert (target->work_list_next == NULL);
		target->work_list_next = work_list;
		work_list = target;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_GOTO_W:
	  {
	    _svmt_instruction_preparation *target =
	      instruction->data.branch.target;

	    if (!target->reachable)
	      {
		/* put instruction on work list */
		target->reachable = 1;
		assert (target->work_list_next == NULL);
		target->work_list_next = work_list;
		work_list = target;
		target->stack_and_local_map =
		  instruction->stack_and_local_map;
		instruction->stack_and_local_map = NULL;
	      }
	    else
	      {
		assert (instruction->stack_and_local_map->free_list_next ==
			NULL);
		instruction->stack_and_local_map->free_list_next =
		  vm->class_loading.method_preparation.free_list;
		vm->class_loading.method_preparation.free_list =
		  instruction->stack_and_local_map;
		instruction->stack_and_local_map = NULL;
	      }

	    goto done;
	  }
	  break;

	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_JSR_W:
	  {
	    _svmt_instruction_preparation *target =
	      instruction->data.branch.target;

	    if (instruction->data.branch.target->ret != NULL)
	      {
		/* subroutine has already been processed, and we have
		   found its related ret */

		assert (target->reachable);

		if (!next_instruction->reachable)
		  {
		    _svmt_instruction_preparation *ret =
		      instruction->data.branch.target->ret;
		    jint stack_size = ret->stack_and_local_map->stack_size;
		    jint i;

		    /* stack content is that of ret */
		    instruction->stack_and_local_map->stack_size = stack_size;
		    for (i = 0; i < stack_size; i++)
		      {
			instruction->stack_and_local_map->stack[i] =
			  ret->stack_and_local_map->stack[i];
		      }

		    /* put instruction on work list */
		    next_instruction->reachable = 1;
		    assert (next_instruction->work_list_next == NULL);
		    next_instruction->work_list_next = work_list;
		    work_list = next_instruction;
		    next_instruction->stack_and_local_map =
		      instruction->stack_and_local_map;
		    instruction->stack_and_local_map = NULL;

		    goto done;
		  }
		else
		  {
		    assert (instruction->stack_and_local_map->
			    free_list_next == NULL);
		    instruction->stack_and_local_map->free_list_next =
		      vm->class_loading.method_preparation.free_list;
		    vm->class_loading.method_preparation.free_list =
		      instruction->stack_and_local_map;
		    instruction->stack_and_local_map = NULL;

		    goto done;
		  }
	      }
	    else
	      {
		/* we must process subroutine then come back */

		/* add instruction to unprocessed callers list */
		instruction->next_unprocessed_caller =
		  target->unprocessed_callers;
		target->unprocessed_callers = instruction;

		if (!target->reachable)
		  {
		    /* this is the first time we see this subroutine */

		    assert (instruction->next_unprocessed_caller == NULL);

		    /* put target instruction on work list */
		    if (_svmm_copy_stack_and_local_map
			(env, method, instruction->stack_and_local_map,
			 target->stack_and_local_map) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    target->reachable = 1;
		    assert (target->work_list_next == NULL);
		    target->work_list_next = work_list;
		    work_list = target;

		    /* push subroutine address on target stack */
		    target->stack_and_local_map->stack
		      [target->stack_and_local_map->stack_size++] =
		      target->bc_pc;

		    goto done;
		  }
		else
		  {
		    /* the subroutine is already being processed */
		    assert (instruction->next_unprocessed_caller != NULL);

		    goto done;
		  }
	      }
	  }
	  break;

	case SVM_INSTRUCTION_RET:
	  {
	    jint index = instruction->data.arg.index;
	    _svmt_instruction_preparation *subroutine =
	      &instructions[instruction_indices
			    [instruction->stack_and_local_map->
			     locals[index]]];

	    /* record the relation between the subroutine and this ret */
	    assert (subroutine->ret == NULL);
	    subroutine->ret = instruction;

	    /* put back subroutine calles on work list (stack) making
	       sure the caller that first called this subroutine is on
	       top */
	    while (subroutine->unprocessed_callers != NULL)
	      {
		_svmt_instruction_preparation *caller =
		  subroutine->unprocessed_callers;
		subroutine->unprocessed_callers =
		  caller->next_unprocessed_caller;

		assert (caller->reachable == 1);
		assert (caller->work_list_next == NULL);
		caller->work_list_next = work_list;
		work_list = caller;
	      }

	    /* Note: we do not release the stack and local map of this
	       instruction as it is needed by calling "jsr"s */

	    goto done;
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH:
	  {
	    jint default_offset, low, high, length;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 12;
	    jint i;

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    default_offset = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);

	    {
	      _svmt_instruction_preparation *target =
		&instructions[instruction_indices[pc + default_offset]];

	      if (!target->reachable)
		{
		  /* put instruction on work list */
		  if (_svmm_copy_stack_and_local_map
		      (env, method, instruction->stack_and_local_map,
		       target->stack_and_local_map) != JNI_OK)
		    {
		      return JNI_ERR;
		    }
		  target->reachable = 1;
		  assert (target->work_list_next == NULL);
		  target->work_list_next = work_list;
		  work_list = target;
		}
	    }

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

	    for (i = 0; i < length; i++)
	      {
		jint offset = _svmf_bytes_to_s32 (&bytecode[base + 4 * i]);
		_svmt_instruction_preparation *target =
		  &instructions[instruction_indices[pc + offset]];

		if (!target->reachable)
		  {
		    /* put instruction on work list */
		    if (_svmm_copy_stack_and_local_map
			(env, method, instruction->stack_and_local_map,
			 target->stack_and_local_map) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    target->reachable = 1;
		    assert (target->work_list_next == NULL);
		    target->work_list_next = work_list;
		    work_list = target;
		  }
	      }

	    /* release stack and local map */
	    assert (instruction->stack_and_local_map->free_list_next == NULL);
	    instruction->stack_and_local_map->free_list_next =
	      vm->class_loading.method_preparation.free_list;
	    vm->class_loading.method_preparation.free_list =
	      instruction->stack_and_local_map;
	    instruction->stack_and_local_map = NULL;

	    goto done;
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	  {
	    jint default_offset, npairs;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 8;
	    jint i;

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    default_offset = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);

	    {
	      _svmt_instruction_preparation *target =
		&instructions[instruction_indices[pc + default_offset]];

	      if (!target->reachable)
		{
		  /* put instruction on work list */
		  if (_svmm_copy_stack_and_local_map
		      (env, method, instruction->stack_and_local_map,
		       target->stack_and_local_map) != JNI_OK)
		    {
		      return JNI_ERR;
		    }
		  target->reachable = 1;
		  assert (target->work_list_next == NULL);
		  target->work_list_next = work_list;
		  work_list = target;
		}
	    }

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

	    for (i = 0; i < npairs; i++)
	      {
		jint offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 8 * i + 4]);
		_svmt_instruction_preparation *target =
		  &instructions[instruction_indices[pc + offset]];

		if (!target->reachable)
		  {
		    /* put instruction on work list */
		    if (_svmm_copy_stack_and_local_map
			(env, method, instruction->stack_and_local_map,
			 target->stack_and_local_map) != JNI_OK)
		      {
			return JNI_ERR;
		      }
		    target->reachable = 1;
		    assert (target->work_list_next == NULL);
		    target->work_list_next = work_list;
		    work_list = target;
		  }
	      }

	    /* release stack and local map */
	    assert (instruction->stack_and_local_map->free_list_next == NULL);
	    instruction->stack_and_local_map->free_list_next =
	      vm->class_loading.method_preparation.free_list;
	    vm->class_loading.method_preparation.free_list =
	      instruction->stack_and_local_map;
	    instruction->stack_and_local_map = NULL;

	    goto done;
	  }
	  break;

	case SVM_INSTRUCTION_IRETURN:
	case SVM_INSTRUCTION_LRETURN:
	case SVM_INSTRUCTION_FRETURN:
	case SVM_INSTRUCTION_DRETURN:
	case SVM_INSTRUCTION_ARETURN:
	case SVM_INSTRUCTION_RETURN:
	case SVM_INSTRUCTION_ATHROW:
	  {
	    /* release stack and local map */
	    assert (instruction->stack_and_local_map->free_list_next == NULL);
	    instruction->stack_and_local_map->free_list_next =
	      vm->class_loading.method_preparation.free_list;
	    vm->class_loading.method_preparation.free_list =
	      instruction->stack_and_local_map;
	    instruction->stack_and_local_map = NULL;

	    goto done;
	  }
	  break;

	case SVM_INSTRUCTION_GETSTATIC:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'B':
	      case 'C':
	      case 'F':
	      case 'I':
	      case 'S':
	      case 'Z':
		{
		  /* push a nonref on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		}
		break;

	      case 'D':
	      case 'J':
		{
		  /* push 2 nonrefs on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		}
		break;

	      case 'L':
	      case '[':
		{
		  /* push a reference on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_REF;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_PUTSTATIC:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'B':
	      case 'C':
	      case 'F':
	      case 'I':
	      case 'S':
	      case 'Z':
	      case 'L':
	      case '[':
		{
		  /* pop 1 element */
		  instruction->stack_and_local_map->stack_size--;
		}
		break;

	      case 'D':
	      case 'J':
		{
		  /* pop 2 elements */
		  instruction->stack_and_local_map->stack_size -= 2;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_GETFIELD:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    /* pop 1 element */
	    instruction->stack_and_local_map->stack_size--;

	    switch (c)
	      {
	      case 'B':
	      case 'C':
	      case 'F':
	      case 'I':
	      case 'S':
	      case 'Z':
		{
		  /* push a nonref on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		}
		break;

	      case 'D':
	      case 'J':
		{
		  /* push 2 nonrefs on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		}
		break;

	      case 'L':
	      case '[':
		{
		  /* push a reference on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_REF;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_PUTFIELD:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'B':
	      case 'C':
	      case 'F':
	      case 'I':
	      case 'S':
	      case 'Z':
	      case 'L':
	      case '[':
		{
		  /* pop 2 elements */
		  instruction->stack_and_local_map->stack_size -= 2;
		}
		break;

	      case 'D':
	      case 'J':
		{
		  /* pop 3 elements */
		  instruction->stack_and_local_map->stack_size -= 3;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	  {
	    const char *descriptor =
	      DREF (DREF (instruction->data.methodref.info->name_and_type,
			  descriptor), value);
	    jint length = strlen (descriptor);
	    jint args_count = _svmf_count_descriptor_args (descriptor);

	    /* pop ref and args */
	    instruction->stack_and_local_map->stack_size -= 1 + args_count;

	    /* push result */
	    if (descriptor[length - 2] != ')')
	      {
		/* push a reference on stack */
		instruction->stack_and_local_map->stack
		  [instruction->stack_and_local_map->stack_size++] =
		  SVM_STACK_MAP_REF;
	      }
	    else
	      {
		switch (descriptor[length - 1])
		  {
		  case 'B':
		  case 'C':
		  case 'F':
		  case 'I':
		  case 'S':
		  case 'Z':
		    {
		      /* push a nonref on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'D':
		  case 'J':
		    {
		      /* push 2 nonrefs on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'V':
		    {
		      /* do nothing */
		    }
		    break;

		  default:
		    {
		      _svmm_fatal_error ("impossible control flow");
		    }
		  }
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_INVOKESTATIC:
	  {
	    const char *descriptor =
	      DREF (DREF (instruction->data.methodref.info->name_and_type,
			  descriptor), value);
	    jint length = strlen (descriptor);
	    jint args_count = _svmf_count_descriptor_args (descriptor);

	    /* pop args */
	    instruction->stack_and_local_map->stack_size -= args_count;

	    /* push result */
	    if (descriptor[length - 2] != ')')
	      {
		/* push a reference on stack */
		instruction->stack_and_local_map->stack
		  [instruction->stack_and_local_map->stack_size++] =
		  SVM_STACK_MAP_REF;
	      }
	    else
	      {
		switch (descriptor[length - 1])
		  {
		  case 'B':
		  case 'C':
		  case 'F':
		  case 'I':
		  case 'S':
		  case 'Z':
		    {
		      /* push a nonref on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'D':
		  case 'J':
		    {
		      /* push 2 nonrefs on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'V':
		    {
		      /* do nothing */
		    }
		    break;

		  default:
		    {
		      _svmm_fatal_error ("impossible control flow");
		    }
		  }
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_INVOKEINTERFACE:
	  {
	    const char *descriptor =
	      DREF (DREF (instruction->data.imethodref.info->name_and_type,
			  descriptor), value);
	    jint length = strlen (descriptor);
	    jint args_count = _svmf_count_descriptor_args (descriptor);

	    /* pop ref and args */
	    instruction->stack_and_local_map->stack_size -= 1 + args_count;

	    /* push result */
	    if (descriptor[length - 2] != ')')
	      {
		/* push a reference on stack */
		instruction->stack_and_local_map->stack
		  [instruction->stack_and_local_map->stack_size++] =
		  SVM_STACK_MAP_REF;
	      }
	    else
	      {
		switch (descriptor[length - 1])
		  {
		  case 'B':
		  case 'C':
		  case 'F':
		  case 'I':
		  case 'S':
		  case 'Z':
		    {
		      /* push a nonref on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'D':
		  case 'J':
		    {
		      /* push 2 nonrefs on stack */
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		      instruction->stack_and_local_map->stack
			[instruction->stack_and_local_map->stack_size++] =
			SVM_STACK_MAP_NONREF;
		    }
		    break;

		  case 'V':
		    {
		      /* do nothing */
		    }
		    break;

		  default:
		    {
		      _svmm_fatal_error ("impossible control flow");
		    }
		  }
	      }

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_NEWARRAY:
	case SVM_INSTRUCTION_ANEWARRAY:
	  {
	    /* replace top by reference */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 1] =
	      SVM_STACK_MAP_REF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_ARRAYLENGTH:
	case SVM_INSTRUCTION_INSTANCEOF:
	  {
	    /* replace top by nonref */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size - 1] =
	      SVM_STACK_MAP_NONREF;

	    goto next;
	  }
	  break;

	case SVM_INSTRUCTION_WIDE:
	  {
	    switch (bytecode[pc + 1])
	      {
	      case SVM_INSTRUCTION_ILOAD:
	      case SVM_INSTRUCTION_FLOAD:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as nonref */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_non_ref = 1;

		  /* push a nonref on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_ALOAD:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as reference */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_ref = 1;

		  /* push a reference on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_REF;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_LLOAD:
	      case SVM_INSTRUCTION_DLOAD:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as long */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_long = 1;

		  /* push 2 nonrefs on stack */
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;
		  instruction->stack_and_local_map->stack
		    [instruction->stack_and_local_map->stack_size++] =
		    SVM_STACK_MAP_NONREF;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_ISTORE:
	      case SVM_INSTRUCTION_FSTORE:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as nonref */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_non_ref = 1;

		  /* pop 1 element */
		  instruction->stack_and_local_map->stack_size--;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_ASTORE:
		{
		  jint index = instruction->data.arg.index;

		  if (instruction->stack_and_local_map->
		      stack[instruction->stack_and_local_map->stack_size -
			    1] >= 0)
		    {
		      /* mark local as nonref */
		      vm->class_loading.method_preparation.locals[index].
			used_as_non_ref = 1;

		      /* record that stack top is an address */
		      instruction->addr_stack_top = 1;

		      /* copy address into local */
		      instruction->stack_and_local_map->locals[index] =
			instruction->stack_and_local_map->
			stack[instruction->stack_and_local_map->stack_size -
			      1];
		    }
		  else
		    {
		      /* mark local as reference */
		      vm->class_loading.method_preparation.locals[index].
			used_as_ref = 1;
		    }

		  /* pop 1 element */
		  instruction->stack_and_local_map->stack_size--;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_LSTORE:
	      case SVM_INSTRUCTION_DSTORE:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as long */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_long = 1;

		  /* pop 2 elements */
		  instruction->stack_and_local_map->stack_size -= 2;

		  goto next;
		}
		break;

	      case SVM_INSTRUCTION_RET:
		{
		  jint index = instruction->data.arg.index;
		  _svmt_instruction_preparation *subroutine =
		    &instructions[instruction_indices
				  [instruction->stack_and_local_map->
				   locals[index]]];

		  /* record the relation between the subroutine and
		     this ret */
		  assert (subroutine->ret == NULL);
		  subroutine->ret = instruction;

		  /* we do not release the stack and local map, as it
		     is needed by enclosing "jsr" instructions */

		  goto done;
		}
		break;

	      case SVM_INSTRUCTION_IINC:
		{
		  jint index = instruction->data.arg.index;

		  /* mark local as nonref */
		  vm->class_loading.method_preparation.locals[index].
		    used_as_non_ref = 1;

		  goto next;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_MULTIANEWARRAY:
	  {
	    jint dimensions = bytecode[pc + 3];

	    /* pop dimensions */
	    instruction->stack_and_local_map->stack_size -= dimensions;

	    /* push a reference on stack */
	    instruction->stack_and_local_map->stack
	      [instruction->stack_and_local_map->stack_size++] =
	      SVM_STACK_MAP_REF;

	    goto next;
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}

      _svmm_fatal_error ("impossible control flow");

    next:
      if (!next_instruction->reachable)
	{
	  /* put instruction on work list */
	  next_instruction->reachable = 1;
	  assert (next_instruction->work_list_next == NULL);
	  next_instruction->work_list_next = work_list;
	  work_list = next_instruction;
	  next_instruction->stack_and_local_map =
	    instruction->stack_and_local_map;
	  instruction->stack_and_local_map = NULL;
	}
      else
	{
	  assert (instruction->stack_and_local_map->free_list_next == NULL);
	  instruction->stack_and_local_map->free_list_next =
	    vm->class_loading.method_preparation.free_list;
	  vm->class_loading.method_preparation.free_list =
	    instruction->stack_and_local_map;
	  instruction->stack_and_local_map = NULL;
	}

    done:
      /* ANSI/ISO C requires an instruction for this label, so we put
         an empty one. */
      ;
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_compute_locals_gc_map
----------------------------------------------------------------------
*/

svm_static jint
_svmf_compute_locals_gc_map (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_local_preparation *locals =
    vm->class_loading.method_preparation.locals;

  /* record parameter mapping */
  {
    const char *descriptor = DREF (method->descriptor, value);

    /* skip '(' */
    const char *p = descriptor + 1;
    jint number = 0;

    if (DREF (method->name, value)[0] == '<')
      {
	if (strcmp (DREF (method->name, value), "<init>") == 0)
	  {
	    /* implicit "this" parameter */
	    locals[number++].method_arg_type = 1;
	  }
	else
	  {
	    /* just making sure the verifier works... */
	    assert (strcmp (DREF (method->name, value), "<clinit>") == 0);
	  }
      }
    else
      {
	if (!_svmf_is_set_flag (method->access_flags, SVM_ACC_STATIC))
	  {
	    /* implicit "this" parameter */
	    locals[number++].method_arg_type = 1;
	  }
      }

    while (*p != ')')
      {
	switch (*p)
	  {
	  case 'B':
	  case 'C':
	  case 'F':
	  case 'I':
	  case 'S':
	  case 'Z':
	    {
	      locals[number++].method_arg_type = 2;
	    }
	    break;

	  case 'D':
	  case 'J':
	    {
	      locals[number++].method_arg_type = 2;
	      locals[number++].method_arg_type = 2;
	    }
	    break;

	  case 'L':
	    {
	      locals[number++].method_arg_type = 1;

	      /* skip to next ';' */
	      while (*++p != ';');
	    }
	    break;

	  case '[':
	    {
	      locals[number++].method_arg_type = 1;

	      /* skip all '[' */
	      while (*++p == '[');

	      if (*p == 'L')
		{
		  /* skip to next ';' */
		  while (*++p != ';');
		}
	    }
	    break;

	  default:
	    {
	      _svmm_fatal_error ("impossible control flow");
	    }
	    break;
	  }

	++p;
      }
  }

  /* now, we split the locals */
  {
    jint locals_size = method->data.code_attribute->max_locals;
    jint i;

    /* local just after parameters */
    jint next_local = method->java_args_count;

    /* initialize all indices to -1 */
    for (i = 0; i < locals_size; i++)
      {
	locals[i].ref_index = -1;
	locals[i].non_ref_index = -1;
	locals[i].long_index = -1;
      }

    /* assign mandatory indices (locals used as parameter) and put all
       locals used as reference just after parameters */
    for (i = 0; i < locals_size; i++)
      {
	switch (locals[i].method_arg_type)
	  {
	  case 0:		/* not a parameter */
	    {
	      if (locals[i].used_as_ref)
		{
		  locals[i].ref_index = next_local++;
		}
	    }
	    break;

	  case 1:		/* reference parameter */
	    {
	      locals[i].ref_index = i;
	    }
	    break;

	  case 2:		/* nonref parameter */
	    {
	      locals[i].non_ref_index = i;

	      if (locals[i].used_as_ref)
		{
		  locals[i].ref_index = next_local++;
		}
	    }
	    break;
	  }
      }

    method->prepared_info.non_parameter_ref_locals_count =
      next_local - method->java_args_count;

    /* assign indices for remaining local usage */
    for (i = 0; i < locals_size; i++)
      {
#ifdef STATISTICS

	if (!(locals[i].used_as_non_ref ||
	      locals[i].used_as_long || locals[i].used_as_ref))
	  {
	    vm->total_unused_locals_count++;
	    method->prepared_info.local_count--;
	  }

#endif

	if (locals[i].used_as_non_ref)
	  {
	    if (locals[i].non_ref_index == -1)
	      {
		if (i > 0 && locals[i - 1].used_as_long)
		  {
		    locals[i].non_ref_index = locals[i - 1].long_index + 1;
		  }
		else
		  {
		    locals[i].non_ref_index = next_local++;
		  }
	      }
	  }

	if (locals[i].used_as_long)
	  {
	    if (locals[i].non_ref_index != -1)
	      {
		if (locals[i + 1].non_ref_index ==
		    locals[i].non_ref_index + 1)
		  {
		    locals[i].long_index = locals[i].non_ref_index;
		  }
		else if (next_local == locals[i].non_ref_index + 1)
		  {
		    locals[i].long_index = locals[i].non_ref_index;
		    next_local++;
		  }
		else if (i > 0 && locals[i - 1].used_as_long
			 && next_local == locals[i - 1].long_index + 2)
		  {
		    locals[i].long_index = locals[i - 1].long_index + 1;
		    next_local++;
		  }
		else
		  {
		    locals[i].long_index = next_local;
		    next_local += 2;
		  }
	      }
	    else
	      {
		if (i > 0 && locals[i - 1].used_as_long
		    && next_local == locals[i - 1].long_index + 2)
		  {
		    locals[i].long_index = locals[i - 1].long_index + 1;
		    next_local++;
		  }
		else
		  {
		    locals[i].long_index = next_local;
		    next_local += 2;
		  }
	      }
	  }
      }

#ifdef STATISTICS

    vm->total_orig_locals_count += method->data.code_attribute->max_locals;
    vm->total_added_locals_count +=
      next_local - method->data.code_attribute->max_locals;

    method->prepared_info.local_count +=
      method->data.code_attribute->max_locals;
    method->prepared_info.local_split_count =
      next_local - method->prepared_info.local_count;

#endif

    method->prepared_info.start_offset =
      next_local * sizeof (_svmt_stack_value);
    method->prepared_info.end_offset =
      _svmv_stack_offset +
      method->data.code_attribute->max_stack * sizeof (_svmt_stack_value);
    method->prepared_info.java_invoke_frame_size =
      method->prepared_info.start_offset + method->prepared_info.end_offset;
    method->prepared_info.internal_invoke_frame_size =
      _svmf_aligned_size_t (sizeof (_svmt_stack_frame)) +
      method->prepared_info.java_invoke_frame_size;
  }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_translate_bytecode
----------------------------------------------------------------------
*/

svm_static jint
_svmf_translate_bytecode (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_u8 *bytecode = method->data.code_attribute->code;
  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;
  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;
  _svmt_local_preparation *locals =
    vm->class_loading.method_preparation.locals;
  jint i;
#ifdef _SABLEVM_INLINABILITY_TESTING
  _svmt_method_info *current_method = env->stack.current_frame->method;
  jint no_inlining = _svmf_no_inlining (env, SVM_INSTRUCTION_UNDEFINED_186,
					SVM_IS_INLINED_METHOD);
  jint bytecode_by_name = 0;
#endif

  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];
      jint pc = instruction->bc_pc;
#ifdef _SABLEVM_INLINABILITY_TESTING
      if (!no_inlining)
	bytecode_by_name =
	  _svmf_get_bytecode_by_method_name (env, DREF (method->name, value));
#endif
      /* skip dead code */
      if (!instruction->reachable)
	{
	  instruction->code = SVM_INSTRUCTION_ERROR;
	  continue;
	}

      switch (bytecode[pc])
	{
	case SVM_INSTRUCTION_NOP:
	case SVM_INSTRUCTION_ACONST_NULL:
	case SVM_INSTRUCTION_ICONST_M1:
	case SVM_INSTRUCTION_ICONST_0:
	case SVM_INSTRUCTION_ICONST_1:
	case SVM_INSTRUCTION_ICONST_2:
	case SVM_INSTRUCTION_ICONST_3:
	case SVM_INSTRUCTION_ICONST_4:
	case SVM_INSTRUCTION_ICONST_5:
	case SVM_INSTRUCTION_LCONST_0:
	case SVM_INSTRUCTION_LCONST_1:
	case SVM_INSTRUCTION_FCONST_0:
	case SVM_INSTRUCTION_FCONST_1:
	case SVM_INSTRUCTION_FCONST_2:
	case SVM_INSTRUCTION_DCONST_0:
	case SVM_INSTRUCTION_DCONST_1:
	case SVM_INSTRUCTION_IALOAD:
	case SVM_INSTRUCTION_LALOAD:
	case SVM_INSTRUCTION_FALOAD:
	case SVM_INSTRUCTION_DALOAD:
	case SVM_INSTRUCTION_AALOAD:
	case SVM_INSTRUCTION_BALOAD:
	case SVM_INSTRUCTION_CALOAD:
	case SVM_INSTRUCTION_SALOAD:
	case SVM_INSTRUCTION_IASTORE:
	case SVM_INSTRUCTION_LASTORE:
	case SVM_INSTRUCTION_FASTORE:
	case SVM_INSTRUCTION_DASTORE:
	case SVM_INSTRUCTION_AASTORE:
	case SVM_INSTRUCTION_BASTORE:
	case SVM_INSTRUCTION_CASTORE:
	case SVM_INSTRUCTION_SASTORE:
	case SVM_INSTRUCTION_POP:
	case SVM_INSTRUCTION_POP2:
	case SVM_INSTRUCTION_DUP:
	case SVM_INSTRUCTION_DUP_X1:
	case SVM_INSTRUCTION_DUP_X2:
	case SVM_INSTRUCTION_DUP2:
	case SVM_INSTRUCTION_DUP2_X1:
	case SVM_INSTRUCTION_DUP2_X2:
	case SVM_INSTRUCTION_SWAP:
	case SVM_INSTRUCTION_IADD:
	case SVM_INSTRUCTION_LADD:
	case SVM_INSTRUCTION_FADD:
	case SVM_INSTRUCTION_DADD:
	case SVM_INSTRUCTION_ISUB:
	case SVM_INSTRUCTION_LSUB:
	case SVM_INSTRUCTION_FSUB:
	case SVM_INSTRUCTION_DSUB:
	case SVM_INSTRUCTION_IMUL:
	case SVM_INSTRUCTION_LMUL:
	case SVM_INSTRUCTION_FMUL:
	case SVM_INSTRUCTION_DMUL:
	case SVM_INSTRUCTION_IDIV:
	case SVM_INSTRUCTION_LDIV:
	case SVM_INSTRUCTION_FDIV:
	case SVM_INSTRUCTION_DDIV:
	case SVM_INSTRUCTION_IREM:
	case SVM_INSTRUCTION_LREM:
	case SVM_INSTRUCTION_FREM:
	case SVM_INSTRUCTION_DREM:
	case SVM_INSTRUCTION_INEG:
	case SVM_INSTRUCTION_LNEG:
	case SVM_INSTRUCTION_FNEG:
	case SVM_INSTRUCTION_DNEG:
	case SVM_INSTRUCTION_ISHL:
	case SVM_INSTRUCTION_LSHL:
	case SVM_INSTRUCTION_ISHR:
	case SVM_INSTRUCTION_LSHR:
	case SVM_INSTRUCTION_IUSHR:
	case SVM_INSTRUCTION_LUSHR:
	case SVM_INSTRUCTION_IAND:
	case SVM_INSTRUCTION_LAND:
	case SVM_INSTRUCTION_IOR:
	case SVM_INSTRUCTION_LOR:
	case SVM_INSTRUCTION_IXOR:
	case SVM_INSTRUCTION_LXOR:
	case SVM_INSTRUCTION_IINC:
	case SVM_INSTRUCTION_I2L:
	case SVM_INSTRUCTION_I2F:
	case SVM_INSTRUCTION_I2D:
	case SVM_INSTRUCTION_L2I:
	case SVM_INSTRUCTION_L2F:
	case SVM_INSTRUCTION_L2D:
	case SVM_INSTRUCTION_F2I:
	case SVM_INSTRUCTION_F2L:
	case SVM_INSTRUCTION_F2D:
	case SVM_INSTRUCTION_D2I:
	case SVM_INSTRUCTION_D2L:
	case SVM_INSTRUCTION_D2F:
	case SVM_INSTRUCTION_I2B:
	case SVM_INSTRUCTION_I2C:
	case SVM_INSTRUCTION_I2S:
	case SVM_INSTRUCTION_LCMP:
	case SVM_INSTRUCTION_FCMPL:
	case SVM_INSTRUCTION_FCMPG:
	case SVM_INSTRUCTION_DCMPL:
	case SVM_INSTRUCTION_DCMPG:
	case SVM_INSTRUCTION_RET:
	case SVM_INSTRUCTION_IRETURN:
	case SVM_INSTRUCTION_LRETURN:
	case SVM_INSTRUCTION_FRETURN:
	case SVM_INSTRUCTION_DRETURN:
	case SVM_INSTRUCTION_ARETURN:
	case SVM_INSTRUCTION_RETURN:
	case SVM_INSTRUCTION_ARRAYLENGTH:
	case SVM_INSTRUCTION_ATHROW:
	case SVM_INSTRUCTION_MONITORENTER:
	case SVM_INSTRUCTION_MONITOREXIT:
	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:
	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_ANEWARRAY:
	case SVM_INSTRUCTION_CHECKCAST:
	case SVM_INSTRUCTION_INSTANCEOF:
	case SVM_INSTRUCTION_MULTIANEWARRAY:
	  {
	    instruction->code = bytecode[pc];
	  }
	  break;

	case SVM_INSTRUCTION_BIPUSH:
	case SVM_INSTRUCTION_SIPUSH:
	  {
	    instruction->code = SVM_INSTRUCTION_LDC_INTEGER;
	  }
	  break;

	case SVM_INSTRUCTION_LDC:
	  {
	    jint offset = bytecode[pc + 1];
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;

	    switch (constant_pool[offset]->tag)
	      {
	      case SVM_CONSTANT_String:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_STRING;
		}
		break;

	      case SVM_CONSTANT_Integer:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_INTEGER;
		}
		break;

	      case SVM_CONSTANT_Float:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_FLOAT;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LDC_W:
	  {
	    jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;

	    switch (constant_pool[offset]->tag)
	      {
	      case SVM_CONSTANT_String:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_STRING;
		}
		break;

	      case SVM_CONSTANT_Integer:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_INTEGER;
		}
		break;

	      case SVM_CONSTANT_Float:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_FLOAT;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LDC2_W:
	  {
	    jint offset = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;

	    switch (constant_pool[offset]->tag)
	      {
	      case SVM_CONSTANT_Long:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_LONG;
		}
		break;

	      case SVM_CONSTANT_Double:
		{
		  instruction->code = SVM_INSTRUCTION_LDC_DOUBLE;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_ILOAD:
	case SVM_INSTRUCTION_ILOAD_0:
	case SVM_INSTRUCTION_ILOAD_1:
	case SVM_INSTRUCTION_ILOAD_2:
	case SVM_INSTRUCTION_ILOAD_3:
	  {
	    switch (locals[instruction->data.arg.index].non_ref_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_ILOAD_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_ILOAD_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_ILOAD_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_ILOAD_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_ILOAD;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LLOAD:
	case SVM_INSTRUCTION_LLOAD_0:
	case SVM_INSTRUCTION_LLOAD_1:
	case SVM_INSTRUCTION_LLOAD_2:
	case SVM_INSTRUCTION_LLOAD_3:
	  {
	    switch (locals[instruction->data.arg.index].long_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_LLOAD_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_LLOAD_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_LLOAD_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_LLOAD_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_LLOAD;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_FLOAD:
	case SVM_INSTRUCTION_FLOAD_0:
	case SVM_INSTRUCTION_FLOAD_1:
	case SVM_INSTRUCTION_FLOAD_2:
	case SVM_INSTRUCTION_FLOAD_3:
	  {
	    switch (locals[instruction->data.arg.index].non_ref_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_FLOAD_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_FLOAD_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_FLOAD_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_FLOAD_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_FLOAD;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_DLOAD:
	case SVM_INSTRUCTION_DLOAD_0:
	case SVM_INSTRUCTION_DLOAD_1:
	case SVM_INSTRUCTION_DLOAD_2:
	case SVM_INSTRUCTION_DLOAD_3:
	  {
	    switch (locals[instruction->data.arg.index].long_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_DLOAD_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_DLOAD_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_DLOAD_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_DLOAD_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_DLOAD;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_ALOAD:
	case SVM_INSTRUCTION_ALOAD_0:
	case SVM_INSTRUCTION_ALOAD_1:
	case SVM_INSTRUCTION_ALOAD_2:
	case SVM_INSTRUCTION_ALOAD_3:
	  {
	    switch (locals[instruction->data.arg.index].ref_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_ALOAD_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_ALOAD_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_ALOAD_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_ALOAD_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_ALOAD;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_ISTORE:
	case SVM_INSTRUCTION_ISTORE_0:
	case SVM_INSTRUCTION_ISTORE_1:
	case SVM_INSTRUCTION_ISTORE_2:
	case SVM_INSTRUCTION_ISTORE_3:
	  {
	    switch (locals[instruction->data.arg.index].non_ref_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_ISTORE_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_ISTORE_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_ISTORE_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_ISTORE_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_ISTORE;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LSTORE:
	case SVM_INSTRUCTION_LSTORE_0:
	case SVM_INSTRUCTION_LSTORE_1:
	case SVM_INSTRUCTION_LSTORE_2:
	case SVM_INSTRUCTION_LSTORE_3:
	  {
	    switch (locals[instruction->data.arg.index].long_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_LSTORE_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_LSTORE_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_LSTORE_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_LSTORE_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_LSTORE;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_FSTORE:
	case SVM_INSTRUCTION_FSTORE_0:
	case SVM_INSTRUCTION_FSTORE_1:
	case SVM_INSTRUCTION_FSTORE_2:
	case SVM_INSTRUCTION_FSTORE_3:
	  {
	    switch (locals[instruction->data.arg.index].non_ref_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_FSTORE_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_FSTORE_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_FSTORE_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_FSTORE_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_FSTORE;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_DSTORE:
	case SVM_INSTRUCTION_DSTORE_0:
	case SVM_INSTRUCTION_DSTORE_1:
	case SVM_INSTRUCTION_DSTORE_2:
	case SVM_INSTRUCTION_DSTORE_3:
	  {
	    switch (locals[instruction->data.arg.index].long_index)
	      {
	      case 0:
		{
		  instruction->code = SVM_INSTRUCTION_DSTORE_0;
		}
		break;

	      case 1:
		{
		  instruction->code = SVM_INSTRUCTION_DSTORE_1;
		}
		break;

	      case 2:
		{
		  instruction->code = SVM_INSTRUCTION_DSTORE_2;
		}
		break;

	      case 3:
		{
		  instruction->code = SVM_INSTRUCTION_DSTORE_3;
		}
		break;

	      default:
		{
		  instruction->code = SVM_INSTRUCTION_DSTORE;
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_ASTORE:
	case SVM_INSTRUCTION_ASTORE_0:
	case SVM_INSTRUCTION_ASTORE_1:
	case SVM_INSTRUCTION_ASTORE_2:
	case SVM_INSTRUCTION_ASTORE_3:
	  {
	    if (instruction->addr_stack_top)
	      {
		switch (locals[instruction->data.arg.index].non_ref_index)
		  {
		  case 0:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_RET_0;
		    }
		    break;

		  case 1:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_RET_1;
		    }
		    break;

		  case 2:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_RET_2;
		    }
		    break;

		  case 3:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_RET_3;
		    }
		    break;

		  default:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_RET;
		    }
		    break;
		  }
	      }
	    else
	      {
		switch (locals[instruction->data.arg.index].ref_index)
		  {
		  case 0:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_0;
		    }
		    break;

		  case 1:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_1;
		    }
		    break;

		  case 2:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_2;
		    }
		    break;

		  case 3:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE_3;
		    }
		    break;

		  default:
		    {
		      instruction->code = SVM_INSTRUCTION_ASTORE;
		    }
		    break;
		  }
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFEQ:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFEQ_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFEQ;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFNE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFNE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFNE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFLT:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFLT_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFLT;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFGE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFGE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFGE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFGT:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFGT_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFGT;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFLE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFLE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFLE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPEQ:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPEQ_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPEQ;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPNE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPNE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPNE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPLT:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPLT_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPLT;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPGE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPGE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPGE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPGT:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPGT_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPGT;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ICMPLE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPLE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ICMPLE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ACMPEQ:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ACMPEQ_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ACMPEQ;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IF_ACMPNE:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IF_ACMPNE_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IF_ACMPNE;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_GOTO_W:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_GOTO_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_GOTO;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_JSR_W:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_JSR_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_JSR;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH:
	  {
	    if (instruction->has_backward_target)
	      {
		instruction->code = SVM_INSTRUCTION_TABLESWITCH_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_TABLESWITCH;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	  {
	    if (instruction->has_backward_target)
	      {
		instruction->code = SVM_INSTRUCTION_LOOKUPSWITCH_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_LOOKUPSWITCH;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFNULL:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFNULL_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFNULL;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFNONNULL:
	  {
	    if (instruction->has_backward_target
		&& !instruction->data.branch.target->reaches_gc_site)
	      {
		instruction->code = SVM_INSTRUCTION_IFNONNULL_CHECK;
	      }
	    else
	      {
		instruction->code = SVM_INSTRUCTION_IFNONNULL;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_GETSTATIC:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'Z':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_BOOLEAN;
		}
		break;

	      case 'B':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_BYTE;
		}
		break;

	      case 'S':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_SHORT;
		}
		break;

	      case 'C':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_CHAR;
		}
		break;

	      case 'I':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_INT;
		}
		break;

	      case 'J':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_LONG;
		}
		break;

	      case 'F':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_FLOAT;
		}
		break;

	      case 'D':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_DOUBLE;
		}
		break;

	      case 'L':
	      case '[':
		{
		  instruction->code = SVM_INSTRUCTION_GETSTATIC_REFERENCE;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_PUTSTATIC:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'Z':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_BOOLEAN;
		}
		break;

	      case 'B':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_BYTE;
		}
		break;

	      case 'S':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_SHORT;
		}
		break;

	      case 'C':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_CHAR;
		}
		break;

	      case 'I':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_INT;
		}
		break;

	      case 'J':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_LONG;
		}
		break;

	      case 'F':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_FLOAT;
		}
		break;

	      case 'D':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_DOUBLE;
		}
		break;

	      case 'L':
	      case '[':
		{
		  instruction->code = SVM_INSTRUCTION_PUTSTATIC_REFERENCE;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_GETFIELD:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'Z':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_BOOLEAN;
		}
		break;

	      case 'B':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_BYTE;
		}
		break;

	      case 'S':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_SHORT;
		}
		break;

	      case 'C':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_CHAR;
		}
		break;

	      case 'I':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_INT;
		}
		break;

	      case 'J':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_LONG;
		}
		break;

	      case 'F':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_FLOAT;
		}
		break;

	      case 'D':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_DOUBLE;
		}
		break;

	      case 'L':
	      case '[':
		{
		  instruction->code = SVM_INSTRUCTION_GETFIELD_REFERENCE;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_PUTFIELD:
	  {
	    /* first character of descriptor */
	    char c =
	      *DREF (DREF (instruction->data.fieldref.info->name_and_type,
			   descriptor), value);

	    switch (c)
	      {
	      case 'Z':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_BOOLEAN;
		}
		break;

	      case 'B':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_BYTE;
		}
		break;

	      case 'S':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_SHORT;
		}
		break;

	      case 'C':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_CHAR;
		}
		break;

	      case 'I':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_INT;
		}
		break;

	      case 'J':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_LONG;
		}
		break;

	      case 'F':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_FLOAT;
		}
		break;

	      case 'D':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_DOUBLE;
		}
		break;

	      case 'L':
	      case '[':
		{
		  instruction->code = SVM_INSTRUCTION_PUTFIELD_REFERENCE;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_NEWARRAY:
	  {
	    switch (bytecode[pc + 1])
	      {
	      case SVM_T_BOOLEAN:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_BOOLEAN;
		}
		break;

	      case SVM_T_CHAR:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_CHAR;
		}
		break;

	      case SVM_T_FLOAT:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_FLOAT;
		}
		break;

	      case SVM_T_DOUBLE:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_DOUBLE;
		}
		break;

	      case SVM_T_BYTE:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_BYTE;
		}
		break;

	      case SVM_T_SHORT:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_SHORT;
		}
		break;

	      case SVM_T_INT:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_INT;
		}
		break;

	      case SVM_T_LONG:
		{
		  instruction->code = SVM_INSTRUCTION_NEWARRAY_LONG;
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_WIDE:
	  {
	    switch (bytecode[pc + 1])
	      {
	      case SVM_INSTRUCTION_ILOAD:
		{
		  switch (locals[instruction->data.arg.index].non_ref_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_ILOAD_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_ILOAD_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_ILOAD_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_ILOAD_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_ILOAD;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_LLOAD:
		{
		  switch (locals[instruction->data.arg.index].long_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_LLOAD_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_LLOAD_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_LLOAD_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_LLOAD_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_LLOAD;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_FLOAD:
		{
		  switch (locals[instruction->data.arg.index].non_ref_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_FLOAD_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_FLOAD_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_FLOAD_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_FLOAD_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_FLOAD;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_DLOAD:
		{
		  switch (locals[instruction->data.arg.index].long_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_DLOAD_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_DLOAD_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_DLOAD_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_DLOAD_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_DLOAD;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_ALOAD:
		{
		  switch (locals[instruction->data.arg.index].ref_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_ALOAD_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_ALOAD_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_ALOAD_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_ALOAD_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_ALOAD;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_ISTORE:
		{
		  switch (locals[instruction->data.arg.index].non_ref_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_ISTORE_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_ISTORE_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_ISTORE_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_ISTORE_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_ISTORE;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_LSTORE:
		{
		  switch (locals[instruction->data.arg.index].long_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_LSTORE_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_LSTORE_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_LSTORE_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_LSTORE_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_LSTORE;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_FSTORE:
		{
		  switch (locals[instruction->data.arg.index].non_ref_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_FSTORE_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_FSTORE_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_FSTORE_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_FSTORE_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_FSTORE;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_DSTORE:
		{
		  switch (locals[instruction->data.arg.index].long_index)
		    {
		    case 0:
		      {
			instruction->code = SVM_INSTRUCTION_DSTORE_0;
		      }
		      break;

		    case 1:
		      {
			instruction->code = SVM_INSTRUCTION_DSTORE_1;
		      }
		      break;

		    case 2:
		      {
			instruction->code = SVM_INSTRUCTION_DSTORE_2;
		      }
		      break;

		    case 3:
		      {
			instruction->code = SVM_INSTRUCTION_DSTORE_3;
		      }
		      break;

		    default:
		      {
			instruction->code = SVM_INSTRUCTION_DSTORE;
		      }
		      break;
		    }
		}
		break;

	      case SVM_INSTRUCTION_ASTORE:
		{
		  if (instruction->addr_stack_top)
		    {
		      switch (locals[instruction->data.arg.index].
			      non_ref_index)
			{
			case 0:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_RET_0;
			  }
			  break;

			case 1:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_RET_1;
			  }
			  break;

			case 2:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_RET_2;
			  }
			  break;

			case 3:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_RET_3;
			  }
			  break;

			default:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_RET;
			  }
			  break;
			}
		    }
		  else
		    {
		      switch (locals[instruction->data.arg.index].ref_index)
			{
			case 0:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_0;
			  }
			  break;

			case 1:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_1;
			  }
			  break;

			case 2:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_2;
			  }
			  break;

			case 3:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE_3;
			  }
			  break;

			default:
			  {
			    instruction->code = SVM_INSTRUCTION_ASTORE;
			  }
			  break;
			}
		    }
		}
		break;

	      case SVM_INSTRUCTION_RET:
	      case SVM_INSTRUCTION_IINC:
		{
		  instruction->code = bytecode[pc + 1];
		}
		break;

	      default:
		{
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }
	  }
	  break;

	default:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_identify_sequences
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

svm_static jint
_svmf_identify_sequences (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;

  _svmt_u8 *bytecode = method->data.code_attribute->code;

  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;
  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;
  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;

  jint exception_table_length =
    method->data.code_attribute->exception_table_length;
  _svmt_exception_table *exception_table =
    method->data.code_attribute->exception_table;

  jint i;

  /* identify all block heads */

  /* first instruction */
  instructions[0].is_sequence_head = 1;

  /* make sure sequences don't include unreachable code by starting a
     new sequence for each unreachable instruction. (Later, we will
     simply skip these instructions). */
  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];

      if (!instruction->reachable)
	{
	  instructions->is_sequence_head = 1;
	}
    }

  /* exception boundaries and handlers */
  for (i = 0; i < exception_table_length; i++)
    {
      jint start = instruction_indices[exception_table[i].start_pc];
      jint end = instruction_indices[exception_table[i].end_pc];
      jint handler = instruction_indices[exception_table[i].handler_pc];

      instructions[start].is_sequence_head = 1;
      instructions[handler].is_sequence_head = 1;

      if (end != instruction_count)
	{
	  instructions[end].is_sequence_head = 1;
	}
    }

  /* branch targets and instruction following branch */
  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];
      jint pc = instruction->bc_pc;

      /* skip dead code */
      if (!instruction->reachable)
	{
	  continue;
	}

      switch (instruction->code)
	{
	case SVM_INSTRUCTION_IFEQ:
	case SVM_INSTRUCTION_IFNE:
	case SVM_INSTRUCTION_IFLT:
	case SVM_INSTRUCTION_IFGE:
	case SVM_INSTRUCTION_IFGT:
	case SVM_INSTRUCTION_IFLE:
	case SVM_INSTRUCTION_IF_ICMPEQ:
	case SVM_INSTRUCTION_IF_ICMPNE:
	case SVM_INSTRUCTION_IF_ICMPLT:
	case SVM_INSTRUCTION_IF_ICMPGE:
	case SVM_INSTRUCTION_IF_ICMPGT:
	case SVM_INSTRUCTION_IF_ICMPLE:
	case SVM_INSTRUCTION_IF_ACMPEQ:
	case SVM_INSTRUCTION_IF_ACMPNE:
	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	case SVM_INSTRUCTION_IFEQ_CHECK:
	case SVM_INSTRUCTION_IFNE_CHECK:
	case SVM_INSTRUCTION_IFLT_CHECK:
	case SVM_INSTRUCTION_IFGE_CHECK:
	case SVM_INSTRUCTION_IFGT_CHECK:
	case SVM_INSTRUCTION_IFLE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
	case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
	case SVM_INSTRUCTION_JSR_CHECK:
	case SVM_INSTRUCTION_IFNULL_CHECK:
	case SVM_INSTRUCTION_IFNONNULL_CHECK:
	  {
	    assert (i + 1 < instruction_count);

	    instruction->data.branch.target->is_sequence_head = 1;
	    instructions[i + 1].is_sequence_head = 1;
	  }
	  break;

	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_GOTO_CHECK:
	  {
	    instruction->data.branch.target->is_sequence_head = 1;
	    if (i + 1 < instruction_count)
	      {
		instructions[i + 1].is_sequence_head = 1;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_RET:
	  {
	    if (i + 1 < instruction_count)
	      {
		instructions[i + 1].is_sequence_head = 1;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH:
	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	  {
	    jint low, high, length;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 12;
	    jint j;

	    if (i + 1 < instruction_count)
	      {
		instructions[i + 1].is_sequence_head = 1;
	      }

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

	      target->is_sequence_head = 1;
	    }

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

	    for (j = 0; j < length; j++)
	      {
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 4 * j]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

		target->is_sequence_head = 1;
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	  {
	    jint npairs;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 8;
	    jint j;

	    if (i + 1 < instruction_count)
	      {
		instructions[i + 1].is_sequence_head = 1;
	      }

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

	      target->is_sequence_head = 1;
	    }

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

	    for (j = 0; j < npairs; j++)
	      {
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 8 * j + 4]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

		target->is_sequence_head = 1;
	      }
	  }
	  break;
	}
    }

  /* calls */
  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];

#ifdef _SABLEVM_INLINABILITY_TESTING
      if (_svmf_no_inlining (env, instruction->code, SVM_IS_INLINED_BYTECODE))
#else
      if (vm->instructions[instruction->code].flag ==
	  SVM_INTRP_FLAG_CONTAINS_BRANCH_OR_CALL)
#endif
	{
	  instruction->is_sequence_head = 1;
	  if (i + 1 < instruction_count)
	    {
	      instructions[i + 1].is_sequence_head = 1;
	    }
	}
    }

  /* compute sequence tails */
  {
    jint tail = 1;

    for (i = instruction_count - 1; i >= 0; i--)
      {
	_svmt_instruction_preparation *instruction = &instructions[i];

	instruction->is_sequence_tail = tail;
	tail = instruction->is_sequence_head;
      }
  }

  /* compute sequence length and size, and record whether sequence
     contains resolution/initialization code */
  {
    size_t length = 0;
    size_t size = 0;
    jint contains_resolution = 0;

    for (i = instruction_count - 1; i >= 0; i--)
      {
	_svmt_instruction_preparation *instruction = &instructions[i];

	length += 1;
	size += vm->instructions[instruction->code].inlined_size;

	if (!contains_resolution)
	  {
	    switch (instruction->code)
	      {
	      case SVM_INSTRUCTION_INVOKEVIRTUAL:
	      case SVM_INSTRUCTION_INVOKESPECIAL:
	      case SVM_INSTRUCTION_INVOKESTATIC:
	      case SVM_INSTRUCTION_INVOKEINTERFACE:
	      case SVM_INSTRUCTION_NEW:
	      case SVM_INSTRUCTION_ANEWARRAY:
	      case SVM_INSTRUCTION_CHECKCAST:
	      case SVM_INSTRUCTION_INSTANCEOF:
	      case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
	      case SVM_INSTRUCTION_GETSTATIC_BYTE:
	      case SVM_INSTRUCTION_GETSTATIC_SHORT:
	      case SVM_INSTRUCTION_GETSTATIC_CHAR:
	      case SVM_INSTRUCTION_GETSTATIC_INT:
	      case SVM_INSTRUCTION_GETSTATIC_LONG:
	      case SVM_INSTRUCTION_GETSTATIC_FLOAT:
	      case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
	      case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
	      case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
	      case SVM_INSTRUCTION_PUTSTATIC_BYTE:
	      case SVM_INSTRUCTION_PUTSTATIC_SHORT:
	      case SVM_INSTRUCTION_PUTSTATIC_CHAR:
	      case SVM_INSTRUCTION_PUTSTATIC_INT:
	      case SVM_INSTRUCTION_PUTSTATIC_LONG:
	      case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
	      case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
	      case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
	      case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
	      case SVM_INSTRUCTION_GETFIELD_BYTE:
	      case SVM_INSTRUCTION_GETFIELD_SHORT:
	      case SVM_INSTRUCTION_GETFIELD_CHAR:
	      case SVM_INSTRUCTION_GETFIELD_INT:
	      case SVM_INSTRUCTION_GETFIELD_LONG:
	      case SVM_INSTRUCTION_GETFIELD_FLOAT:
	      case SVM_INSTRUCTION_GETFIELD_DOUBLE:
	      case SVM_INSTRUCTION_GETFIELD_REFERENCE:
	      case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
	      case SVM_INSTRUCTION_PUTFIELD_BYTE:
	      case SVM_INSTRUCTION_PUTFIELD_SHORT:
	      case SVM_INSTRUCTION_PUTFIELD_CHAR:
	      case SVM_INSTRUCTION_PUTFIELD_INT:
	      case SVM_INSTRUCTION_PUTFIELD_LONG:
	      case SVM_INSTRUCTION_PUTFIELD_FLOAT:
	      case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
	      case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
	      case SVM_INSTRUCTION_LDC_STRING:
	      case SVM_INSTRUCTION_MULTIANEWARRAY:
		{
		  contains_resolution = 1;
		  instruction->is_sequence_last_resolution = 1;
		}
		break;
	      }
	  }

	if (instruction->is_sequence_head)
	  {
	    instruction->sequence_length = length;
	    instruction->sequence_contains_resolution = contains_resolution;

	    size += vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size;

	    if (contains_resolution)
	      {
		size += vm->instructions[SVM_INSTRUCTION_SKIP].inlined_size;
	      }

	    instruction->sequence_size = size;

	    length = 0;
	    size = 0;
	    contains_resolution = 0;
	  }
      }
  }

  return JNI_OK;
}

#endif /* defined (_SABLEVM_INLINED_THREADED_INTERPRETER) */

/*
----------------------------------------------------------------------
_svmf_compute_offsets
----------------------------------------------------------------------
*/

svm_static jint
_svmf_compute_offsets (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;

  _svmt_u8 *bytecode = method->data.code_attribute->code;

  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;

  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;

  jint i;
  size_t offset = 0;		/* offset of current instruction */
  size_t extra = 0;		/* extra space needed for preparation
				   of some instructions */

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  jint within_initialization_sequence = 0;
#endif

  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];
      jint pc = instruction->bc_pc;

      instruction->code_offset = offset;

      /* skip dead code */
      if (!instruction->reachable)
	{
	  continue;
	}

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

      assert (vm->instructions[instruction->code].flag !=
	      SVM_INTRP_FLAG_UNUSED);

      if (instruction->is_sequence_head)
	{
	  within_initialization_sequence =
	    instruction->sequence_contains_resolution;

	  /* sequence head */
	  if (within_initialization_sequence)
	    {
	      instruction->code_length = 2;
	    }
	  else
	    {
	      instruction->code_length = 1;
	    }
	}
      else
	{
	  instruction->code_length = 0;
	}

#else

      instruction->code_length = 1;

#endif

      switch (instruction->code)
	{
	default:
	case SVM_INSTRUCTION_BIPUSH:
	case SVM_INSTRUCTION_SIPUSH:
	case SVM_INSTRUCTION_LDC:
	case SVM_INSTRUCTION_LDC_W:
	case SVM_INSTRUCTION_LDC2_W:
	case SVM_INSTRUCTION_GETSTATIC:
	case SVM_INSTRUCTION_PUTSTATIC:
	case SVM_INSTRUCTION_GETFIELD:
	case SVM_INSTRUCTION_PUTFIELD:
	case SVM_INSTRUCTION_UNDEFINED_186:
	case SVM_INSTRUCTION_NEWARRAY:
	case SVM_INSTRUCTION_WIDE:
	case SVM_INSTRUCTION_GOTO_W:
	case SVM_INSTRUCTION_JSR_W:
	case SVM_INSTRUCTION_PREPARE_METHOD:
	case SVM_INSTRUCTION_LINK_NATIVE_METHOD:
	case SVM_INSTRUCTION_ABSTRACT_METHOD:
	case SVM_INSTRUCTION_NATIVE_STATIC_METHOD:
	case SVM_INSTRUCTION_NATIVE_NONSTATIC_METHOD:
	case SVM_INSTRUCTION_NEXT:
	case SVM_INSTRUCTION_ERROR:
	case SVM_INSTRUCTION_INTERNAL_CALL_END:
	case SVM_INSTRUCTION_PREPARE_LDC_STRING:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_INT:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE:
	case SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE:
	case SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_INT:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_LONG:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE:
	case SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_INT:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE:
	case SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE:
	case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
	case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
	case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
	case SVM_INSTRUCTION_PREPARE_NEW:
	case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
	case SVM_INSTRUCTION_PREPARE_CHECKCAST:
	case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
	case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
	case SVM_INSTRUCTION_REPLACE:
	case SVM_INSTRUCTION_SKIP:
	  {
	    _svmm_fatal_error ("impossible control flow");
	  }
	  break;

	case SVM_INSTRUCTION_NOP:
	case SVM_INSTRUCTION_ACONST_NULL:
	case SVM_INSTRUCTION_ICONST_M1:
	case SVM_INSTRUCTION_ICONST_0:
	case SVM_INSTRUCTION_ICONST_1:
	case SVM_INSTRUCTION_ICONST_2:
	case SVM_INSTRUCTION_ICONST_3:
	case SVM_INSTRUCTION_ICONST_4:
	case SVM_INSTRUCTION_ICONST_5:
	case SVM_INSTRUCTION_LCONST_0:
	case SVM_INSTRUCTION_LCONST_1:
	case SVM_INSTRUCTION_FCONST_0:
	case SVM_INSTRUCTION_FCONST_1:
	case SVM_INSTRUCTION_FCONST_2:
	case SVM_INSTRUCTION_DCONST_0:
	case SVM_INSTRUCTION_DCONST_1:
	case SVM_INSTRUCTION_ILOAD_0:
	case SVM_INSTRUCTION_ILOAD_1:
	case SVM_INSTRUCTION_ILOAD_2:
	case SVM_INSTRUCTION_ILOAD_3:
	case SVM_INSTRUCTION_LLOAD_0:
	case SVM_INSTRUCTION_LLOAD_1:
	case SVM_INSTRUCTION_LLOAD_2:
	case SVM_INSTRUCTION_LLOAD_3:
	case SVM_INSTRUCTION_FLOAD_0:
	case SVM_INSTRUCTION_FLOAD_1:
	case SVM_INSTRUCTION_FLOAD_2:
	case SVM_INSTRUCTION_FLOAD_3:
	case SVM_INSTRUCTION_DLOAD_0:
	case SVM_INSTRUCTION_DLOAD_1:
	case SVM_INSTRUCTION_DLOAD_2:
	case SVM_INSTRUCTION_DLOAD_3:
	case SVM_INSTRUCTION_ALOAD_0:
	case SVM_INSTRUCTION_ALOAD_1:
	case SVM_INSTRUCTION_ALOAD_2:
	case SVM_INSTRUCTION_ALOAD_3:
	case SVM_INSTRUCTION_IALOAD:
	case SVM_INSTRUCTION_LALOAD:
	case SVM_INSTRUCTION_FALOAD:
	case SVM_INSTRUCTION_DALOAD:
	case SVM_INSTRUCTION_AALOAD:
	case SVM_INSTRUCTION_BALOAD:
	case SVM_INSTRUCTION_CALOAD:
	case SVM_INSTRUCTION_SALOAD:
	case SVM_INSTRUCTION_ISTORE_0:
	case SVM_INSTRUCTION_ISTORE_1:
	case SVM_INSTRUCTION_ISTORE_2:
	case SVM_INSTRUCTION_ISTORE_3:
	case SVM_INSTRUCTION_LSTORE_0:
	case SVM_INSTRUCTION_LSTORE_1:
	case SVM_INSTRUCTION_LSTORE_2:
	case SVM_INSTRUCTION_LSTORE_3:
	case SVM_INSTRUCTION_FSTORE_0:
	case SVM_INSTRUCTION_FSTORE_1:
	case SVM_INSTRUCTION_FSTORE_2:
	case SVM_INSTRUCTION_FSTORE_3:
	case SVM_INSTRUCTION_DSTORE_0:
	case SVM_INSTRUCTION_DSTORE_1:
	case SVM_INSTRUCTION_DSTORE_2:
	case SVM_INSTRUCTION_DSTORE_3:
	case SVM_INSTRUCTION_ASTORE_0:
	case SVM_INSTRUCTION_ASTORE_1:
	case SVM_INSTRUCTION_ASTORE_2:
	case SVM_INSTRUCTION_ASTORE_3:
	case SVM_INSTRUCTION_IASTORE:
	case SVM_INSTRUCTION_LASTORE:
	case SVM_INSTRUCTION_FASTORE:
	case SVM_INSTRUCTION_DASTORE:
	case SVM_INSTRUCTION_AASTORE:
	case SVM_INSTRUCTION_BASTORE:
	case SVM_INSTRUCTION_CASTORE:
	case SVM_INSTRUCTION_SASTORE:
	case SVM_INSTRUCTION_POP:
	case SVM_INSTRUCTION_POP2:
	case SVM_INSTRUCTION_DUP:
	case SVM_INSTRUCTION_DUP_X1:
	case SVM_INSTRUCTION_DUP_X2:
	case SVM_INSTRUCTION_DUP2:
	case SVM_INSTRUCTION_DUP2_X1:
	case SVM_INSTRUCTION_DUP2_X2:
	case SVM_INSTRUCTION_SWAP:
	case SVM_INSTRUCTION_IADD:
	case SVM_INSTRUCTION_LADD:
	case SVM_INSTRUCTION_FADD:
	case SVM_INSTRUCTION_DADD:
	case SVM_INSTRUCTION_ISUB:
	case SVM_INSTRUCTION_LSUB:
	case SVM_INSTRUCTION_FSUB:
	case SVM_INSTRUCTION_DSUB:
	case SVM_INSTRUCTION_IMUL:
	case SVM_INSTRUCTION_LMUL:
	case SVM_INSTRUCTION_FMUL:
	case SVM_INSTRUCTION_DMUL:
	case SVM_INSTRUCTION_IDIV:
	case SVM_INSTRUCTION_LDIV:
	case SVM_INSTRUCTION_FDIV:
	case SVM_INSTRUCTION_DDIV:
	case SVM_INSTRUCTION_IREM:
	case SVM_INSTRUCTION_LREM:
	case SVM_INSTRUCTION_FREM:
	case SVM_INSTRUCTION_DREM:
	case SVM_INSTRUCTION_INEG:
	case SVM_INSTRUCTION_LNEG:
	case SVM_INSTRUCTION_FNEG:
	case SVM_INSTRUCTION_DNEG:
	case SVM_INSTRUCTION_ISHL:
	case SVM_INSTRUCTION_LSHL:
	case SVM_INSTRUCTION_ISHR:
	case SVM_INSTRUCTION_LSHR:
	case SVM_INSTRUCTION_IUSHR:
	case SVM_INSTRUCTION_LUSHR:
	case SVM_INSTRUCTION_IAND:
	case SVM_INSTRUCTION_LAND:
	case SVM_INSTRUCTION_IOR:
	case SVM_INSTRUCTION_LOR:
	case SVM_INSTRUCTION_IXOR:
	case SVM_INSTRUCTION_LXOR:
	case SVM_INSTRUCTION_I2L:
	case SVM_INSTRUCTION_I2F:
	case SVM_INSTRUCTION_I2D:
	case SVM_INSTRUCTION_L2I:
	case SVM_INSTRUCTION_L2F:
	case SVM_INSTRUCTION_L2D:
	case SVM_INSTRUCTION_F2I:
	case SVM_INSTRUCTION_F2L:
	case SVM_INSTRUCTION_F2D:
	case SVM_INSTRUCTION_D2I:
	case SVM_INSTRUCTION_D2L:
	case SVM_INSTRUCTION_D2F:
	case SVM_INSTRUCTION_I2B:
	case SVM_INSTRUCTION_I2C:
	case SVM_INSTRUCTION_I2S:
	case SVM_INSTRUCTION_LCMP:
	case SVM_INSTRUCTION_FCMPL:
	case SVM_INSTRUCTION_FCMPG:
	case SVM_INSTRUCTION_DCMPL:
	case SVM_INSTRUCTION_DCMPG:
	case SVM_INSTRUCTION_IRETURN:
	case SVM_INSTRUCTION_LRETURN:
	case SVM_INSTRUCTION_FRETURN:
	case SVM_INSTRUCTION_DRETURN:
	case SVM_INSTRUCTION_ARETURN:
	case SVM_INSTRUCTION_RETURN:
	case SVM_INSTRUCTION_ARRAYLENGTH:
	case SVM_INSTRUCTION_ATHROW:
	case SVM_INSTRUCTION_MONITOREXIT:
	case SVM_INSTRUCTION_ASTORE_RET_0:
	case SVM_INSTRUCTION_ASTORE_RET_1:
	case SVM_INSTRUCTION_ASTORE_RET_2:
	case SVM_INSTRUCTION_ASTORE_RET_3:
	  {
	    /* do nothing */

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 1;
		extra += 1;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_ILOAD:
	case SVM_INSTRUCTION_LLOAD:
	case SVM_INSTRUCTION_FLOAD:
	case SVM_INSTRUCTION_DLOAD:
	case SVM_INSTRUCTION_ALOAD:
	case SVM_INSTRUCTION_ISTORE:
	case SVM_INSTRUCTION_LSTORE:
	case SVM_INSTRUCTION_FSTORE:
	case SVM_INSTRUCTION_DSTORE:
	case SVM_INSTRUCTION_ASTORE:
	case SVM_INSTRUCTION_IFEQ:
	case SVM_INSTRUCTION_IFNE:
	case SVM_INSTRUCTION_IFLT:
	case SVM_INSTRUCTION_IFGE:
	case SVM_INSTRUCTION_IFGT:
	case SVM_INSTRUCTION_IFLE:
	case SVM_INSTRUCTION_IF_ICMPEQ:
	case SVM_INSTRUCTION_IF_ICMPNE:
	case SVM_INSTRUCTION_IF_ICMPLT:
	case SVM_INSTRUCTION_IF_ICMPGE:
	case SVM_INSTRUCTION_IF_ICMPGT:
	case SVM_INSTRUCTION_IF_ICMPLE:
	case SVM_INSTRUCTION_IF_ACMPEQ:
	case SVM_INSTRUCTION_IF_ACMPNE:
	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_RET:
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	case SVM_INSTRUCTION_ASTORE_RET:
	case SVM_INSTRUCTION_LDC_INTEGER:
	case SVM_INSTRUCTION_LDC_FLOAT:
	case SVM_INSTRUCTION_LDC_LONG:
	case SVM_INSTRUCTION_LDC_DOUBLE:
	case SVM_INSTRUCTION_MONITORENTER:
	case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
	case SVM_INSTRUCTION_NEWARRAY_CHAR:
	case SVM_INSTRUCTION_NEWARRAY_FLOAT:
	case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
	case SVM_INSTRUCTION_NEWARRAY_BYTE:
	case SVM_INSTRUCTION_NEWARRAY_SHORT:
	case SVM_INSTRUCTION_NEWARRAY_INT:
	case SVM_INSTRUCTION_NEWARRAY_LONG:
	  {
	    instruction->code_length++;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 2;
		extra += 2;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_IINC:
	case SVM_INSTRUCTION_IFEQ_CHECK:
	case SVM_INSTRUCTION_IFNE_CHECK:
	case SVM_INSTRUCTION_IFLT_CHECK:
	case SVM_INSTRUCTION_IFGE_CHECK:
	case SVM_INSTRUCTION_IFGT_CHECK:
	case SVM_INSTRUCTION_IFLE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
	case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
	case SVM_INSTRUCTION_GOTO_CHECK:
	case SVM_INSTRUCTION_JSR_CHECK:
	case SVM_INSTRUCTION_IFNULL_CHECK:
	case SVM_INSTRUCTION_IFNONNULL_CHECK:
	  {
	    instruction->code_length += 2;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 3;
		extra += 3;
	      }

#endif
	  }
	  break;


	case SVM_INSTRUCTION_TABLESWITCH:
	  {
	    jint low, high, length;
	    jint pad = 3 - (pc % 4);

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

	    instruction->code_length += 3 + length;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 4 + length;
		extra += 4 + length;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	  {
	    jint npairs;
	    jint pad = 3 - (pc % 4);

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

	    instruction->code_length += 2 + 2 * npairs;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 3 + 2 * npairs;
		extra += 3 + 2 * npairs;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	  {
	    jint low, high, length;
	    jint pad = 3 - (pc % 4);

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

	    instruction->code_length += 3 + length + 1;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 4 + length + 1;
		extra += 4 + length + 1;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	  {
	    jint npairs;
	    jint pad = 3 - (pc % 4);

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

	    instruction->code_length += 2 + (2 * npairs) + 1;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (within_initialization_sequence)
	      {
		instruction->prepare_offset = extra;
		instruction->prepare_length = 3 + 2 * npairs + 1;
		extra += 3 + 2 * npairs + 1;
	      }

#endif
	  }
	  break;

	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    instruction->code_length += 3;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 4;
	    extra += 4;

#else

	    instruction->code_length += 4;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 9;
	    extra += 9;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_ANEWARRAY:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    instruction->code_length += 2;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 4;
	    extra += 4;

#else

	    instruction->code_length += 3;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 9;
	    extra += 9;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_CHECKCAST:
	case SVM_INSTRUCTION_INSTANCEOF:
	case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_GETSTATIC_BYTE:
	case SVM_INSTRUCTION_GETSTATIC_SHORT:
	case SVM_INSTRUCTION_GETSTATIC_CHAR:
	case SVM_INSTRUCTION_GETSTATIC_INT:
	case SVM_INSTRUCTION_GETSTATIC_LONG:
	case SVM_INSTRUCTION_GETSTATIC_FLOAT:
	case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
	case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
	case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_PUTSTATIC_BYTE:
	case SVM_INSTRUCTION_PUTSTATIC_SHORT:
	case SVM_INSTRUCTION_PUTSTATIC_CHAR:
	case SVM_INSTRUCTION_PUTSTATIC_INT:
	case SVM_INSTRUCTION_PUTSTATIC_LONG:
	case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
	case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
	case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
	case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
	case SVM_INSTRUCTION_GETFIELD_BYTE:
	case SVM_INSTRUCTION_GETFIELD_SHORT:
	case SVM_INSTRUCTION_GETFIELD_CHAR:
	case SVM_INSTRUCTION_GETFIELD_INT:
	case SVM_INSTRUCTION_GETFIELD_LONG:
	case SVM_INSTRUCTION_GETFIELD_FLOAT:
	case SVM_INSTRUCTION_GETFIELD_DOUBLE:
	case SVM_INSTRUCTION_GETFIELD_REFERENCE:
	case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
	case SVM_INSTRUCTION_PUTFIELD_BYTE:
	case SVM_INSTRUCTION_PUTFIELD_SHORT:
	case SVM_INSTRUCTION_PUTFIELD_CHAR:
	case SVM_INSTRUCTION_PUTFIELD_INT:
	case SVM_INSTRUCTION_PUTFIELD_LONG:
	case SVM_INSTRUCTION_PUTFIELD_FLOAT:
	case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
	case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
	case SVM_INSTRUCTION_LDC_STRING:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    instruction->code_length += 1;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 4;
	    extra += 4;

#else

	    instruction->code_length += 2;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 9;
	    extra += 9;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_MULTIANEWARRAY:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    instruction->code_length += 3;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 5;
	    extra += 5;

#else

	    instruction->code_length += 4;

	    instruction->prepare_offset = extra;
	    instruction->prepare_length = 10;
	    extra += 10;

#endif
	  }
	  break;
	}

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

      if (within_initialization_sequence)
	{
	  if (instruction->is_sequence_last_resolution)
	    {
	      instruction->prepare_length += 3;
	      extra += 3;
	    }

	  if (instruction->is_sequence_tail)
	    {
	      instruction->prepare_length += 2;
	      extra += 2;
	    }
	}

#endif

      offset += instruction->code_length;
    }

  vm->class_loading.method_preparation.code_length = offset + extra;

#ifdef STATISTICS

  vm->code_size +=
    vm->class_loading.method_preparation.code_length * sizeof (_svmt_code);

#endif

  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];

      if (instruction->prepare_length != 0)
	{
	  instruction->prepare_offset += offset;
	}
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmh_get_sequence
----------------------------------------------------------------------
*/

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

#define _svmm_get_sequence(env, method, instruction, sequence_implementation) \
_svmh_get_sequence (env, method, instruction, &sequence_implementation)

svm_static jint
_svmh_get_sequence (_svmt_JNIEnv *env, _svmt_method_info *method,
		    _svmt_instruction_preparation *instruction,
		    void **psequence_implementation)
{
  _svmt_JavaVM *vm = env->vm;
  size_t i;

  if (vm->class_loading.method_preparation.sequence != NULL)
    {
      if (vm->class_loading.method_preparation.sequence->instructions != NULL)
	{
	  _svmm_gmfree_ints (vm->class_loading.method_preparation.sequence->
			     instructions);
	}

      if (vm->class_loading.method_preparation.sequence->implementation !=
	  NULL)
	{
	  _svmf_free (vm->class_loading.method_preparation.sequence->
		      implementation);
	  vm->class_loading.method_preparation.sequence->implementation =
	    NULL;
	}

      _svmm_gzfree_sequence_node (vm->class_loading.method_preparation.
				  sequence);
    }

  if (_svmm_gzalloc_sequence_node
      (env, vm->class_loading.method_preparation.sequence) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmm_gmalloc_ints
      (env, instruction->sequence_length,
       vm->class_loading.method_preparation.sequence->instructions) != JNI_OK)
    {
      return JNI_ERR;
    }

  vm->class_loading.method_preparation.sequence->instructions_length =
    instruction->sequence_length;

  for (i = 0; i < instruction->sequence_length; i++)
    {
      vm->class_loading.method_preparation.sequence->instructions[i] =
	(instruction + i)->code;
    }

  {
    _svmt_sequence_node *sequence =
      _svmm_tree_find_sequence (vm->class_loading.sequence_tree,
				vm->class_loading.method_preparation.
				sequence);

    if (sequence == NULL)
      {
	void *implementation;

	vm->class_loading.method_preparation.sequence->implementation_length =
	  instruction->sequence_size;
	vm->class_loading.method_preparation.sequence->implementation =
	  _svmf_malloc (instruction->sequence_size);

	if (vm->class_loading.method_preparation.sequence->implementation ==
	    NULL)
	  {
	    _svmf_error_OutOfMemoryError (env);
	    return JNI_ERR;
	  }

	implementation =
	  vm->class_loading.method_preparation.sequence->implementation;

#if defined (__ia64__)

	/* Give execution permission to implementation memory */
	{
	  /* mprotect manages permissions on a PAGE_SIZE basis */

	  /* Note that POSIX says that mprotect can be used only on
	     regions of memory obtained from mmap.  As we have
	     obtained this memory from malloc, the following code is
	     not necessarily portable. */

	  void *first_page =
	    (void *) (((_svmt_word) implementation) &
		      ~((_svmt_word) (SVM_PAGE_SIZE - 1)));
	  size_t length =
	    instruction->sequence_size +
	    (((_svmt_word) implementation) &
	     ((_svmt_word) (SVM_PAGE_SIZE - 1)));

	  if (mprotect
	      (first_page, length, PROT_WRITE | PROT_READ | PROT_EXEC) != 0)
	    {
	      _svmm_fatal_error
		("cannot give execution permission to inlined code");
	    }
	}

#endif

	if (instruction->sequence_contains_resolution)
	  {
	    size_t j;
	    size_t size = vm->instructions[SVM_INSTRUCTION_SKIP].inlined_size;

	    for (j = 0; j < size; j++)
	      {
		*((char *) implementation) =
		  ((char *) vm->instructions[SVM_INSTRUCTION_SKIP].
		   inlined_code.implementation)[j];
		implementation = ((char *) implementation) + 1;
	      }
	  }

	for (i = 0; i < instruction->sequence_length; i++)
	  {
	    jint code = (instruction + i)->code;
	    size_t j;
	    size_t size = vm->instructions[code].inlined_size;

	    for (j = 0; j < size; j++)
	      {
		*((char *) implementation) =
		  ((char *) vm->instructions[code].inlined_code.
		   implementation)[j];
		implementation = ((char *) implementation) + 1;
	      }

	  }

	{
	  size_t j;
	  size_t size = vm->instructions[SVM_INSTRUCTION_NEXT].inlined_size;

	  for (j = 0; j < size; j++)
	    {
	      *((char *) implementation) =
		((char *) vm->instructions[SVM_INSTRUCTION_NEXT].inlined_code.
		 implementation)[j];
	      implementation = ((char *) implementation) + 1;
	    }
	}

	assert (implementation ==
		((char *) vm->class_loading.method_preparation.sequence->
		 implementation) + instruction->sequence_size);

	{
	  /* update instruction cache */
	  _svmt_word *pword =
	    (_svmt_word *) vm->class_loading.method_preparation.sequence->
	    implementation;
	  size_t updated = 0;
	  size_t sequence_size = instruction->sequence_size;

	  while (updated < sequence_size)
	    {
	      _svmf_iflush (pword++);
	      updated += sizeof (_svmt_word);
	    }
	}

#ifdef STATISTICS

	vm->distinct_inlined_threads_count++;
	vm->total_distinct_thread_bc_length +=
	  vm->class_loading.method_preparation.sequence->instructions_length;
	vm->total_distinct_thread_inlined_length +=
	  vm->class_loading.method_preparation.sequence->
	  implementation_length;

	vm->inlined_threads_count++;
	vm->total_thread_bc_length +=
	  vm->class_loading.method_preparation.sequence->instructions_length;
	vm->total_thread_inlined_length +=
	  vm->class_loading.method_preparation.sequence->
	  implementation_length;

	if (vm->class_loading.method_preparation.sequence->
	    instructions_length > vm->max_thread_bc_length)
	  {
	    vm->max_thread_bc_length =
	      vm->class_loading.method_preparation.sequence->
	      instructions_length;
	  }

	if (vm->class_loading.method_preparation.sequence->
	    implementation_length > vm->max_thread_inlined_length)
	  {
	    vm->max_thread_inlined_length =
	      vm->class_loading.method_preparation.sequence->
	      implementation_length;
	  }

#endif

	_svmm_tree_insert_sequence (vm->class_loading.sequence_tree,
				    vm->class_loading.method_preparation.
				    sequence);
      }
    else
      {
#ifdef STATISTICS

	vm->inlined_threads_count++;
	vm->total_thread_bc_length += sequence->instructions_length;
	vm->total_thread_inlined_length += sequence->implementation_length;

#endif

	_svmm_gmfree_ints (vm->class_loading.method_preparation.sequence->
			   instructions);
	_svmm_gzfree_sequence_node (vm->class_loading.method_preparation.
				    sequence);

	vm->class_loading.method_preparation.sequence = sequence;
      }
  }

  *psequence_implementation =
    vm->class_loading.method_preparation.sequence->implementation;
  vm->class_loading.method_preparation.sequence = NULL;

  return JNI_OK;
}

#endif

/*
----------------------------------------------------------------------
_svmf_compute_code_array
----------------------------------------------------------------------
*/

svm_static jint
_svmf_compute_code_array (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  _svmt_u8 *bytecode = method->data.code_attribute->code;
  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;
  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;
  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;
  _svmt_local_preparation *locals =
    vm->class_loading.method_preparation.locals;

  size_t offset = 0;
  size_t extra =
    instructions[instruction_count - 1].code_offset +
    instructions[instruction_count - 1].code_length;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  jint is_resolution_sequence = 0;
#endif

  jint i;
  _svmt_code *code;

  /* allocate code array */
  if (_svmm_cl_malloc_code
      (env,
       method->class_info->class_loader_info,
       vm->class_loading.method_preparation.code_length,
       method->prepared_info.code) != JNI_OK)
    {
      return JNI_ERR;
    }

  code = method->prepared_info.code;

  for (i = 0; i < instruction_count; i++)
    {
      _svmt_instruction_preparation *instruction = &instructions[i];
      jint pc = instruction->bc_pc;

      assert (offset == instruction->code_offset);
      assert (instruction->prepare_length == 0
	      || extra == instruction->prepare_offset);

      /* skip dead code */
      if (!instruction->reachable)
	{
	  continue;
	}

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

      if (instruction->is_sequence_head)
	{
#ifdef _SABLEVM_INLINABILITY_TESTING
	  if (_svmf_no_inlining
	      (env, instruction->code, SVM_IS_INLINED_BYTECODE))
#else
	  if (vm->instructions[instruction->code].flag ==
	      SVM_INTRP_FLAG_CONTAINS_BRANCH_OR_CALL)
#endif
	    {
	      assert (instruction->sequence_length == 1);

	      code[offset++] = vm->instructions[instruction->code].code;
	    }
	  else
	    {
	      void *sequence_implementation;

	      if (_svmm_get_sequence
		  (env, method, instruction,
		   sequence_implementation) != JNI_OK)
		{
		  return JNI_ERR;
		}

	      code[offset++].implementation = sequence_implementation;
	    }

	  is_resolution_sequence = instruction->sequence_contains_resolution;

	  if (is_resolution_sequence)
	    {
	      code[offset++].addr = &code[extra];
	    }
	}

      if (is_resolution_sequence)
	{
	  code[extra++] = vm->instructions[instruction->code].code;
	}

#else

      code[offset++] = vm->instructions[instruction->code].code;

#endif

      switch (instruction->code)
	{
	case SVM_INSTRUCTION_ILOAD:
	case SVM_INSTRUCTION_FLOAD:
	case SVM_INSTRUCTION_ISTORE:
	case SVM_INSTRUCTION_FSTORE:
	case SVM_INSTRUCTION_RET:
	case SVM_INSTRUCTION_ASTORE_RET:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint =
		  locals[instruction->data.arg.index].non_ref_index;
	      }

#endif

	    code[offset++].jint =
	      locals[instruction->data.arg.index].non_ref_index;
	  }
	  break;

	case SVM_INSTRUCTION_LLOAD:
	case SVM_INSTRUCTION_DLOAD:
	case SVM_INSTRUCTION_LSTORE:
	case SVM_INSTRUCTION_DSTORE:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint =
		  locals[instruction->data.arg.index].long_index;
	      }

#endif

	    code[offset++].jint =
	      locals[instruction->data.arg.index].long_index;
	  }
	  break;

	case SVM_INSTRUCTION_ALOAD:
	case SVM_INSTRUCTION_ASTORE:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint =
		  locals[instruction->data.arg.index].ref_index;
	      }

#endif

	    code[offset++].jint =
	      locals[instruction->data.arg.index].ref_index;
	  }
	  break;

	case SVM_INSTRUCTION_IINC:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint =
		  locals[instruction->data.arg.index].non_ref_index;

		if (bytecode[pc] == SVM_INSTRUCTION_IINC)
		  {
		    code[extra++].jint = (_svmt_s8) (bytecode[pc + 2]);
		  }
		else
		  {
		    assert (bytecode[pc] == SVM_INSTRUCTION_WIDE);
		    assert (bytecode[pc + 1] == SVM_INSTRUCTION_IINC);

		    code[extra++].jint =
		      _svmf_bytes_to_s16 (&bytecode[pc + 4]);
		  }
	      }

#endif

	    code[offset++].jint =
	      locals[instruction->data.arg.index].non_ref_index;

	    if (bytecode[pc] == SVM_INSTRUCTION_IINC)
	      {
		code[offset++].jint = (_svmt_s8) (bytecode[pc + 2]);
	      }
	    else
	      {
		assert (bytecode[pc] == SVM_INSTRUCTION_WIDE);
		assert (bytecode[pc + 1] == SVM_INSTRUCTION_IINC);

		code[offset++].jint = _svmf_bytes_to_s16 (&bytecode[pc + 4]);
	      }
	  }
	  break;

	case SVM_INSTRUCTION_IFEQ:
	case SVM_INSTRUCTION_IFNE:
	case SVM_INSTRUCTION_IFLT:
	case SVM_INSTRUCTION_IFGE:
	case SVM_INSTRUCTION_IFGT:
	case SVM_INSTRUCTION_IFLE:
	case SVM_INSTRUCTION_IF_ICMPEQ:
	case SVM_INSTRUCTION_IF_ICMPNE:
	case SVM_INSTRUCTION_IF_ICMPLT:
	case SVM_INSTRUCTION_IF_ICMPGE:
	case SVM_INSTRUCTION_IF_ICMPGT:
	case SVM_INSTRUCTION_IF_ICMPLE:
	case SVM_INSTRUCTION_IF_ACMPEQ:
	case SVM_INSTRUCTION_IF_ACMPNE:
	case SVM_INSTRUCTION_GOTO:
	case SVM_INSTRUCTION_JSR:
	case SVM_INSTRUCTION_IFNULL:
	case SVM_INSTRUCTION_IFNONNULL:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].addr =
		  &code[instruction->data.branch.target->code_offset];
	      }

#endif

	    code[offset++].addr =
	      &code[instruction->data.branch.target->code_offset];
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH:
	  {
	    jint low, high, length;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 12;
	    jint j;

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	      if (is_resolution_sequence)
		{
		  code[extra++].addr = &code[target->code_offset];
		}

#endif

	      code[offset++].addr = &code[target->code_offset];
	    }

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint = low;
		code[extra++].jint = high;
	      }

#endif

	    code[offset++].jint = low;
	    code[offset++].jint = high;

	    for (j = 0; j < length; j++)
	      {
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 4 * j]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

		if (is_resolution_sequence)
		  {
		    code[extra++].addr = &code[target->code_offset];
		  }

#endif

		code[offset++].addr = &code[target->code_offset];
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH:
	  {
	    jint npairs;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 8;
	    jint j;

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	      if (is_resolution_sequence)
		{
		  code[extra++].addr = &code[target->code_offset];
		}

#endif

	      code[offset++].addr = &code[target->code_offset];
	    }

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint = npairs;
	      }

#endif

	    code[offset++].jint = npairs;

	    for (j = 0; j < npairs; j++)
	      {
		jint match = _svmf_bytes_to_s32 (&bytecode[base + 8 * j]);
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 8 * j + 4]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

		if (is_resolution_sequence)
		  {
		    code[extra++].jint = match;
		    code[extra++].addr = &code[target->code_offset];
		  }

#endif

		code[offset++].jint = match;
		code[offset++].addr = &code[target->code_offset];
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LDC_INTEGER:
	  {
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;
	    jint value;

	    switch (bytecode[pc])
	      {
	      case SVM_INSTRUCTION_BIPUSH:
		{
		  value = (_svmt_s8) bytecode[pc + 1];
		}
		break;

	      case SVM_INSTRUCTION_SIPUSH:
		{
		  value = _svmf_bytes_to_s16 (&bytecode[pc + 1]);
		}
		break;

	      case SVM_INSTRUCTION_LDC:
		{
		  value =
		    _svmf_cast_CONSTANT_Integer (constant_pool
						 [bytecode[pc + 1]])->value;
		}
		break;

	      case SVM_INSTRUCTION_LDC_W:
		{
		  value =
		    _svmf_cast_CONSTANT_Integer (constant_pool
						 [_svmf_bytes_to_u16
						  (&bytecode[pc + 1])])->
		    value;
		}
		break;

	      default:
		{
		  value = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jint = value;
	      }

#endif

	    code[offset++].jint = value;
	  }
	  break;

	case SVM_INSTRUCTION_LDC_FLOAT:
	  {
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;
	    jint index;

	    switch (bytecode[pc])
	      {
	      case SVM_INSTRUCTION_LDC:
		{
		  index = bytecode[pc + 1];
		}
		break;

	      case SVM_INSTRUCTION_LDC_W:
		{
		  index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);
		}
		break;

	      default:
		{
		  index = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].jfloat =
		  _svmf_cast_CONSTANT_Float (constant_pool[index])->value;
	      }

#endif

	    code[offset++].jfloat =
	      _svmf_cast_CONSTANT_Float (constant_pool[index])->value;
	  }
	  break;

	case SVM_INSTRUCTION_LDC_LONG:
	  {
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;
	    jint index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].pjlong =
		  &_svmf_cast_CONSTANT_Long (constant_pool[index])->value;
	      }

#endif

	    code[offset++].pjlong =
	      &_svmf_cast_CONSTANT_Long (constant_pool[index])->value;
	  }
	  break;

	case SVM_INSTRUCTION_LDC_DOUBLE:
	  {
	    _svmt_cp_info **constant_pool = method->class_info->constant_pool;
	    jint index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    if (is_resolution_sequence)
	      {
		code[extra++].pjdouble =
		  &_svmf_cast_CONSTANT_Double (constant_pool[index])->value;
	      }

#endif

	    code[offset++].pjdouble =
	      &_svmf_cast_CONSTANT_Double (constant_pool[index])->value;
	  }
	  break;

	case SVM_INSTRUCTION_MONITORENTER:
	case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
	case SVM_INSTRUCTION_NEWARRAY_CHAR:
	case SVM_INSTRUCTION_NEWARRAY_FLOAT:
	case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
	case SVM_INSTRUCTION_NEWARRAY_BYTE:
	case SVM_INSTRUCTION_NEWARRAY_SHORT:
	case SVM_INSTRUCTION_NEWARRAY_INT:
	case SVM_INSTRUCTION_NEWARRAY_LONG:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    assert (!is_resolution_sequence);

#endif

	    code[offset++].stack_gc_map = instruction->stack_gc_map;
	  }
	  break;

	case SVM_INSTRUCTION_IFEQ_CHECK:
	case SVM_INSTRUCTION_IFNE_CHECK:
	case SVM_INSTRUCTION_IFLT_CHECK:
	case SVM_INSTRUCTION_IFGE_CHECK:
	case SVM_INSTRUCTION_IFGT_CHECK:
	case SVM_INSTRUCTION_IFLE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
	case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
	case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
	case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
	case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
	case SVM_INSTRUCTION_GOTO_CHECK:
	case SVM_INSTRUCTION_JSR_CHECK:
	case SVM_INSTRUCTION_IFNULL_CHECK:
	case SVM_INSTRUCTION_IFNONNULL_CHECK:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    assert (!is_resolution_sequence);

#endif

	    code[offset++].stack_gc_map =
	      instruction->data.branch.target->stack_gc_map;
	    code[offset++].addr =
	      &code[instruction->data.branch.target->code_offset];
	  }
	  break;

	case SVM_INSTRUCTION_TABLESWITCH_CHECK:
	  {
	    jint low, high, length;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 12;
	    jint j;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    assert (!is_resolution_sequence);

#endif

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

	      code[offset++].stack_gc_map = target->stack_gc_map;
	      code[offset++].addr = &code[target->code_offset];
	    }

	    low = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);
	    high = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 8]);
	    length = high - low + 1;

	    code[offset++].jint = low;
	    code[offset++].jint = high;

	    for (j = 0; j < length; j++)
	      {
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 4 * j]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

		code[offset++].addr = &code[target->code_offset];
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
	  {
	    jint npairs;
	    jint pad = 3 - (pc % 4);
	    jint base = pc + 1 + pad + 8;
	    jint j;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    assert (!is_resolution_sequence);

#endif

	    {
	      jint default_offset =
		_svmf_bytes_to_s32 (&bytecode[pc + 1 + pad]);
	      jint target_index = instruction_indices[pc + default_offset];
	      _svmt_instruction_preparation *target =
		&instructions[target_index];

	      code[offset++].stack_gc_map = target->stack_gc_map;
	      code[offset++].addr = &code[target->code_offset];
	    }

	    npairs = _svmf_bytes_to_s32 (&bytecode[pc + 1 + pad + 4]);

	    code[offset++].jint = npairs;

	    for (j = 0; j < npairs; j++)
	      {
		jint match = _svmf_bytes_to_s32 (&bytecode[base + 8 * j]);
		jint target_offset =
		  _svmf_bytes_to_s32 (&bytecode[base + 8 * j + 4]);
		jint target_index = instruction_indices[pc + target_offset];
		_svmt_instruction_preparation *target =
		  &instructions[target_index];

		code[offset++].jint = match;
		code[offset++].addr = &code[target->code_offset];
	      }
	  }
	  break;

	case SVM_INSTRUCTION_LDC_STRING:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] =
	      vm->instructions[SVM_INSTRUCTION_PREPARE_LDC_STRING].code;
	    code[extra++].addr = &code[offset++];
	    code[extra++].stringref_info =
	      instruction->data.ldc.stringref_info;
	    code[extra++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_GETSTATIC_BYTE:
	case SVM_INSTRUCTION_GETSTATIC_SHORT:
	case SVM_INSTRUCTION_GETSTATIC_CHAR:
	case SVM_INSTRUCTION_GETSTATIC_INT:
	case SVM_INSTRUCTION_GETSTATIC_LONG:
	case SVM_INSTRUCTION_GETSTATIC_FLOAT:
	case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
	case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
	case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
	case SVM_INSTRUCTION_PUTSTATIC_BYTE:
	case SVM_INSTRUCTION_PUTSTATIC_SHORT:
	case SVM_INSTRUCTION_PUTSTATIC_CHAR:
	case SVM_INSTRUCTION_PUTSTATIC_INT:
	case SVM_INSTRUCTION_PUTSTATIC_LONG:
	case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
	case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
	case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
	case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
	case SVM_INSTRUCTION_GETFIELD_BYTE:
	case SVM_INSTRUCTION_GETFIELD_SHORT:
	case SVM_INSTRUCTION_GETFIELD_CHAR:
	case SVM_INSTRUCTION_GETFIELD_INT:
	case SVM_INSTRUCTION_GETFIELD_LONG:
	case SVM_INSTRUCTION_GETFIELD_FLOAT:
	case SVM_INSTRUCTION_GETFIELD_DOUBLE:
	case SVM_INSTRUCTION_GETFIELD_REFERENCE:
	case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
	case SVM_INSTRUCTION_PUTFIELD_BYTE:
	case SVM_INSTRUCTION_PUTFIELD_SHORT:
	case SVM_INSTRUCTION_PUTFIELD_CHAR:
	case SVM_INSTRUCTION_PUTFIELD_INT:
	case SVM_INSTRUCTION_PUTFIELD_LONG:
	case SVM_INSTRUCTION_PUTFIELD_FLOAT:
	case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
	case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
	  {
	    jint prepare_code;

	    switch (instruction->code)
	      {
	      case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_BYTE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_SHORT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_CHAR:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_INT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_INT;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_LONG:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_FLOAT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE;
		}
		break;

	      case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_BYTE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_SHORT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_CHAR:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_INT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_LONG:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE;
		}
		break;

	      case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_BYTE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_SHORT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_CHAR:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_INT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_INT;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_LONG:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_LONG;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_FLOAT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_DOUBLE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE;
		}
		break;

	      case SVM_INSTRUCTION_GETFIELD_REFERENCE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_BYTE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_SHORT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_CHAR:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_INT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_INT;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_LONG:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_FLOAT:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE;
		}
		break;

	      case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE;
		}
		break;

	      default:
		{
		  prepare_code = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] = vm->instructions[prepare_code].code;
	    code[extra++].addr = &code[offset++];
	    code[extra++].fieldref_info = instruction->data.fieldref.info;
	    code[extra++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_INVOKEVIRTUAL:
	case SVM_INSTRUCTION_INVOKESPECIAL:
	case SVM_INSTRUCTION_INVOKESTATIC:
	case SVM_INSTRUCTION_INVOKEINTERFACE:
	  {
	    jint prepare_code;

	    switch (instruction->code)
	      {
	      case SVM_INSTRUCTION_INVOKEVIRTUAL:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL;
		}
		break;

	      case SVM_INSTRUCTION_INVOKESPECIAL:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_INVOKESPECIAL;
		}
		break;

	      case SVM_INSTRUCTION_INVOKESTATIC:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_INVOKESTATIC;
		}
		break;

	      case SVM_INSTRUCTION_INVOKEINTERFACE:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE;
		}
		break;

	      default:
		{
		  prepare_code = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] = vm->instructions[prepare_code].code;
	    code[extra++].addr = &code[offset++];

	    if (instruction->code == SVM_INSTRUCTION_INVOKEINTERFACE)
	      {
		code[extra++].imethodref_info =
		  instruction->data.imethodref.info;
	      }
	    else
	      {
		code[extra++].methodref_info =
		  instruction->data.methodref.info;
	      }

	    code[extra++].stack_gc_map = instruction->stack_gc_map;

	    offset++;
	    code[offset++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_NEW:
	case SVM_INSTRUCTION_ANEWARRAY:
	  {
	    jint prepare_code;

	    switch (instruction->code)
	      {
	      case SVM_INSTRUCTION_NEW:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_NEW;
		}
		break;

	      case SVM_INSTRUCTION_ANEWARRAY:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_ANEWARRAY;
		}
		break;

	      default:
		{
		  prepare_code = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] = vm->instructions[prepare_code].code;
	    code[extra++].addr = &code[offset++];

	    {
	      _svmt_cp_info **constant_pool =
		method->class_info->constant_pool;
	      jint index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);

	      code[extra++].classref_info =
		_svmf_cast_CONSTANT_Class (constant_pool[index]);
	    }

	    code[extra++].stack_gc_map = instruction->stack_gc_map;

	    code[offset++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_CHECKCAST:
	case SVM_INSTRUCTION_INSTANCEOF:
	  {
	    jint prepare_code;

	    switch (instruction->code)
	      {
	      case SVM_INSTRUCTION_CHECKCAST:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_CHECKCAST;
		}
		break;

	      case SVM_INSTRUCTION_INSTANCEOF:
		{
		  prepare_code = SVM_INSTRUCTION_PREPARE_INSTANCEOF;
		}
		break;

	      default:
		{
		  prepare_code = 0;
		  _svmm_fatal_error ("impossible control flow");
		}
		break;
	      }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] = vm->instructions[prepare_code].code;
	    code[extra++].addr = &code[offset++];

	    {
	      _svmt_cp_info **constant_pool =
		method->class_info->constant_pool;
	      jint index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);

	      code[extra++].classref_info =
		_svmf_cast_CONSTANT_Class (constant_pool[index]);
	    }

	    code[extra++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;

	case SVM_INSTRUCTION_MULTIANEWARRAY:
	  {
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
	    --extra;
#else
	    code[offset++].addr = &code[extra];
#endif

	    code[extra++] =
	      vm->instructions[SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY].code;
	    code[extra++].addr = &code[offset++];

	    {
	      _svmt_cp_info **constant_pool =
		method->class_info->constant_pool;
	      jint index = _svmf_bytes_to_u16 (&bytecode[pc + 1]);

	      code[extra++].classref_info =
		_svmf_cast_CONSTANT_Class (constant_pool[index]);
	    }

	    code[extra++].jint = bytecode[pc + 3];
	    code[extra++].stack_gc_map = instruction->stack_gc_map;

	    code[offset++].jint = bytecode[pc + 3];
	    code[offset++].stack_gc_map = instruction->stack_gc_map;

#if !defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	    code[extra++].addr = &code[instruction->code_offset];
	    code[extra++] = code[instruction->code_offset];

	    code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	    code[extra++].addr = &code[offset];

	    code[instruction->code_offset] =
	      vm->instructions[SVM_INSTRUCTION_GOTO].code;

#endif
	  }
	  break;
	}

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

      if (instruction->is_sequence_last_resolution)
	{
	  _svmt_instruction_preparation *first = instruction;

	  while (!first->is_sequence_head)
	    {
	      first--;
	    }

	  code[extra++] = vm->instructions[SVM_INSTRUCTION_REPLACE].code;
	  code[extra++].addr = &code[first->code_offset];
	  code[extra++] = code[first->code_offset];

	  code[first->code_offset] =
	    vm->instructions[SVM_INSTRUCTION_GOTO].code;
	}

      if (is_resolution_sequence && instruction->is_sequence_tail)
	{
	  code[extra++] = vm->instructions[SVM_INSTRUCTION_GOTO].code;
	  code[extra++].addr = &code[offset];
	}

#endif
    }

  assert (offset ==
	  instructions[instruction_count - 1].code_offset +
	  instructions[instruction_count - 1].code_length);
  assert (extra == vm->class_loading.method_preparation.code_length);

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_fix_line_number_table
----------------------------------------------------------------------
*/

svm_static int
_svmf_fix_line_number_table (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;
  jint instruction_count =
    vm->class_loading.method_preparation.instruction_count;
  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;
  _svmt_code *code = method->prepared_info.code;

  jint attributes_count = method->data.code_attribute->attributes_count;
  _svmt_attribute_info **attributes = method->data.code_attribute->attributes;
  _svmt_LineNumberTable_attribute *attribute = NULL;

  jint table_length;
  _svmt_line_number_table *table;
  jint i;

  for (i = 0; i < attributes_count; i++)
    {
      if (strcmp (DREF (attributes[i]->name, value), "LineNumberTable") == 0)
	{
	  attribute = _svmf_cast_LineNumberTable_attribute (attributes[i]);
	  method->data.code_attribute->line_numbers = attribute;
	  break;
	}
    }

  if (attribute == NULL)
    {
      return JNI_OK;
    }

  table_length = attribute->line_number_table_length;
  table = attribute->line_number_table;

  for (i = 0; i < table_length; i++)
    {
      _svmt_instruction_preparation *start =
	&instructions[instruction_indices[table[i].start_pc]];
      _svmt_instruction_preparation *end;

      if (i + 1 < table_length)
	{
	  /* Special case: current entry has length 0 */
	  if (table[i].start_pc == table[i + 1].start_pc)
	    {
	      /* table[i].normal/prepare_start/end remain NULL */
	      continue;
	    }
	}

      /* "inclusive" end instruction */
      if (i + 1 < table_length)
	{
	  end = &instructions[instruction_indices[table[i + 1].start_pc] - 1];
	}
      else
	{
	  end = &instructions[instruction_count - 1];
	}

      /* we add 1 because, in the interpreter, "pc" points to the next
         code to be read */
      table[i].normal_start = &code[start->code_offset + 1];
      table[i].normal_end = &code[end->code_offset + end->code_length];

      {
	jint j;
	jint start_index = instruction_indices[table[i].start_pc];
	jint end_index;

	if (i + 1 < table_length)
	  {
	    end_index = instruction_indices[table[i + 1].start_pc];
	  }
	else
	  {
	    end_index = instruction_count;
	  }

	for (j = start_index; j < end_index; j++)
	  {
	    _svmt_instruction_preparation *instruction = &instructions[j];

	    if (instruction->prepare_length > 0)
	      {
		if (table[i].prepare_start == NULL)
		  {
		    table[i].prepare_start =
		      &code[instruction->prepare_offset + 1];
		  }

		table[i].prepare_end =
		  &code[instruction->prepare_offset +
			instruction->prepare_length];
	      }
	  }
      }
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_fix_exception_table
----------------------------------------------------------------------
*/

svm_static jint
_svmf_fix_exception_table (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  jint *instruction_indices =
    vm->class_loading.method_preparation.instruction_indices;
  _svmt_instruction_preparation *instructions =
    vm->class_loading.method_preparation.instructions;
  _svmt_code *code = method->prepared_info.code;

  jint table_length = method->data.code_attribute->exception_table_length;
  _svmt_exception_table *table = method->data.code_attribute->exception_table;
  jint i;

  for (i = 0; i < table_length; i++)
    {
      _svmt_instruction_preparation *start =
	&instructions[instruction_indices[table[i].start_pc]];
      /* "inclusive" end instruction */
      _svmt_instruction_preparation *end =
	&instructions[instruction_indices[table[i].end_pc] - 1];
      _svmt_instruction_preparation *handler =
	&instructions[instruction_indices[table[i].handler_pc]];

      /* we add 1 because, in the interpreter, "pc" is pointing to the next thing to do. */
      table[i].normal_start = &code[start->code_offset + 1];
      table[i].normal_end = &code[end->code_offset + end->code_length];

      table[i].handler = &code[handler->code_offset];

      {
	jint j;
	jint start_index = instruction_indices[table[i].start_pc];
	jint end_index = instruction_indices[table[i].end_pc];

	for (j = start_index; j < end_index; j++)
	  {
	    _svmt_instruction_preparation *instruction = &instructions[j];

	    if (instruction->prepare_length > 0)
	      {
		if (table[i].prepare_start == NULL)
		  {
		    table[i].prepare_start =
		      &code[instruction->prepare_offset + 1];
		  }

		table[i].prepare_end =
		  &code[instruction->prepare_offset +
			instruction->prepare_length];
	      }
	  }
      }
    }

  return JNI_OK;
}

/*
----------------------------------------------------------------------
_svmf_prepare_code
----------------------------------------------------------------------
*/

svm_static jint
_svmf_prepare_code (_svmt_JNIEnv *env, _svmt_method_info *method)
{
  _svmt_JavaVM *vm = env->vm;
  jboolean monitor_acquired = JNI_FALSE;

  /* We really need to acquire a unique global monitor as we use
     global structures (vm->class_loading.method_preparation). */
  if (vm->initialization == NULL)
    {
      if (_svmf_enter_object_monitor
	  (env,
	   *(vm->class_loading.boot_loader.classes.virtualmachine->
	     class_instance)) != JNI_OK)
	{
	  goto error;
	}

      monitor_acquired = JNI_TRUE;
    }

  if (method->frame_info == &method->prepared_info)
    {
      goto ok;
    }

#ifdef COMMENT
  if (vm->verbose_class)
    {
      _svmf_printf (env, stderr, "[verbose class: preparing %s.%s%s]\n",
		    method->class_info->name, DREF (method->name, value),
		    DREF (method->descriptor, value));
    }
#endif

  if (_svmf_initialize_instruction_indices (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_initialize_instructions (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_resolve_gc_site_reach (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_compute_stack_gc_maps (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_compute_locals_gc_map (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_translate_bytecode (env, method) != JNI_OK)
    {
      goto error;
    }

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

  if (_svmf_identify_sequences (env, method) != JNI_OK)
    {
      goto error;
    }

#endif

  if (_svmf_compute_offsets (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_compute_code_array (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_fix_line_number_table (env, method) != JNI_OK)
    {
      goto error;
    }

  if (_svmf_fix_exception_table (env, method) != JNI_OK)
    {
      goto error;
    }

  /* preparation is done */
  method->frame_info = &method->prepared_info;

  /* now we're ready to fix the stack */

  {
    _svmt_stack_frame frame_data = *(env->stack.current_frame);
    size_t diff = method->prepared_info.start_offset -
      method->non_prepared_info.start_offset;

    if (_svmf_ensure_stack_capacity (env, diff) != JNI_OK)
      {
	goto error;
      }

    frame_data.previous_offset += diff;
    frame_data.end_offset = method->prepared_info.end_offset;
    assert (frame_data.method == method);
    frame_data.pc = method->prepared_info.code;
    assert (frame_data.stack_size == 0);

    env->stack.current_frame =
      (_svmt_stack_frame *) (void *) (((char *) env->stack.current_frame) +
				      diff);
    *(env->stack.current_frame) = frame_data;
  }

  /* clear reference locals */
  {
    _svmt_stack_value *locals = (_svmt_stack_value *) (void *)
      (((char *) env->stack.current_frame) -
       method->frame_info->start_offset);
    jint first = method->java_args_count;
    jint last = first + method->frame_info->non_parameter_ref_locals_count;
    jint i;

    for (i = first; i < last; i++)
      {
	locals[i].reference = NULL;
      }
  }

ok:
  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env,
	   *(vm->class_loading.boot_loader.classes.virtualmachine->
	     class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

#ifdef STATISTICS

  vm->method_count++;

#endif

#ifdef _SABLEVM_INLINABILITY_TESTING
  /* set alarm() to wake us in case sth. in this method can be inlinable
     and we might get into an infinite loop or sth.
     On the other side - turn off alarm when we're in normal method */
  if (_svmf_no_inlining
      (env, SVM_INSTRUCTION_UNDEFINED_186, SVM_IS_INLINED_METHOD))
    alarm (0);
  else
    alarm (SVM_ALARM_PERIOD);
#endif

  return JNI_OK;

error:

  if (monitor_acquired)
    {
      monitor_acquired = JNI_FALSE;

      if (_svmf_exit_object_monitor
	  (env,
	   *(vm->class_loading.boot_loader.classes.virtualmachine->
	     class_instance)) != JNI_OK)
	{
	  goto error;
	}
    }

  return JNI_ERR;
}
