/* This file has been automatically generated from "instructions.m4.c" */

/*
----------------------------------------------------------------------
BIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BIPUSH:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "BIPUSH");
#endif
	break;
      }

/*
----------------------------------------------------------------------
SIPUSH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SIPUSH:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "SIPUSH");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_W:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_W");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC2_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC2_W:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC2_W");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY");
#endif
	break;
      }

/*
----------------------------------------------------------------------
WIDE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_WIDE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "WIDE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GOTO_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_W:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 4;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GOTO_W");
#endif
	break;
      }

/*
----------------------------------------------------------------------
JSR_W
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_W:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 4;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "JSR_W");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NOP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NOP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NOP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ACONST_NULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ACONST_NULL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ACONST_NULL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_M1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_M1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_M1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_4
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_4:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_4");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ICONST_5
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ICONST_5:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ICONST_5");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LCONST_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCONST_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LCONST_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FCONST_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FCONST_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FCONST_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCONST_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FCONST_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DCONST_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DCONST_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DCONST_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCONST_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DCONST_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_INTEGER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_INTEGER:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_INTEGER");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_STRING:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_STRING");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDC_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDC_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ILOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ILOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LLOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FLOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DLOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DLOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ILOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ILOAD_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ILOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ILOAD_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ILOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ILOAD_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ILOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ILOAD_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ILOAD_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LLOAD_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LLOAD_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LLOAD_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LLOAD_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LLOAD_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FLOAD_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FLOAD_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FLOAD_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FLOAD_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FLOAD_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DLOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DLOAD_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DLOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DLOAD_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DLOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DLOAD_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DLOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DLOAD_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DLOAD_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
CALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "CALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
SALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "SALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ALOAD_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ALOAD_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ALOAD_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ALOAD_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ALOAD_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ALOAD_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ALOAD_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ALOAD_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ALOAD_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
AALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "AALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
BALOAD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BALOAD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "BALOAD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISTORE_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISTORE_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISTORE_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISTORE_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISTORE_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSTORE_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSTORE_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSTORE_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSTORE_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSTORE_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSTORE_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSTORE_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSTORE_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSTORE_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSTORE_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSTORE_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSTORE_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSTORE_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSTORE_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSTORE_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
CASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "CASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
SASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "SASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
BASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_BASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "BASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
AASTORE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_AASTORE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "AASTORE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
POP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "POP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
POP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_POP2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "POP2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP_X1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP_X2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP_X2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP2_X1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP2_X1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DUP2_X2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DUP2_X2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DUP2_X2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
SWAP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SWAP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "SWAP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IADD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IADD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LADD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LADD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FADD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FADD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DADD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DADD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DADD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISUB:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISUB");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSUB:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSUB");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FSUB:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FSUB");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DSUB
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DSUB:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DSUB");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IMUL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IMUL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LMUL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LMUL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FMUL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FMUL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DMUL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DMUL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DMUL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FDIV:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FDIV");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DDIV:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DDIV");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INEG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INEG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LNEG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LNEG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FNEG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FNEG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DNEG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DNEG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DNEG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IAND:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IAND");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LAND
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LAND:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LAND");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IOR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IOR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LOR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IXOR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IXOR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LXOR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LXOR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LXOR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2L:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2L");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2F:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2F");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2D:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2D");
#endif
	break;
      }

/*
----------------------------------------------------------------------
L2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2I:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "L2I");
#endif
	break;
      }

/*
----------------------------------------------------------------------
L2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2F:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "L2F");
#endif
	break;
      }

/*
----------------------------------------------------------------------
L2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_L2D:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "L2D");
#endif
	break;
      }

/*
----------------------------------------------------------------------
F2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2I:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "F2I");
#endif
	break;
      }

/*
----------------------------------------------------------------------
F2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2L:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "F2L");
#endif
	break;
      }

/*
----------------------------------------------------------------------
F2D
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_F2D:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "F2D");
#endif
	break;
      }

/*
----------------------------------------------------------------------
D2I
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2I:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "D2I");
#endif
	break;
      }

/*
----------------------------------------------------------------------
D2L
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2L:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "D2L");
#endif
	break;
      }

/*
----------------------------------------------------------------------
D2F
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_D2F:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "D2F");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2B
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2B:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2B");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2C
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2C:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2C");
#endif
	break;
      }

/*
----------------------------------------------------------------------
I2S
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_I2S:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "I2S");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IDIV:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IDIV");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LDIV
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LDIV:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LDIV");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IREM:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IREM");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LREM:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LREM");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FREM:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FREM");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DREM
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DREM:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DREM");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISHL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSHL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSHL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ISHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ISHR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ISHR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LSHR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LSHR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IUSHR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IUSHR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LUSHR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LUSHR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LUSHR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LCMP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LCMP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LCMP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FCMPL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FCMPG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FCMPG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DCMPL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DCMPL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DCMPG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DCMPG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DCMPG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IINC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IINC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IINC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFEQ");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFLT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFGT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFGE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPEQ");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPNE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPLT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPGT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPGE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ACMPEQ
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ACMPEQ");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ACMPNE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ACMPNE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFEQ_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFEQ_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLT_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFLT_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFLE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFLE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGT_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFGT_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFGE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFGE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPEQ_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPEQ_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPNE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPNE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPLT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLT_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLT_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPLE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPLE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPLE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPGT_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGT_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGT_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ICMPGE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ICMPGE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ICMPGE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ACMPEQ_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPEQ_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ACMPEQ_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IF_ACMPNE_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IF_ACMPNE_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IF_ACMPNE_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GOTO
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GOTO");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GOTO_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GOTO_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GOTO_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
JSR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "JSR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
JSR_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_JSR_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "JSR_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RET:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "RET");
#endif
	break;
      }

/*
----------------------------------------------------------------------
TABLESWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "TABLESWITCH");
#endif
	break;
      }

/*
----------------------------------------------------------------------
TABLESWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_TABLESWITCH_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "TABLESWITCH_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LOOKUPSWITCH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LOOKUPSWITCH");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LOOKUPSWITCH_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LOOKUPSWITCH_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LOOKUPSWITCH_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IRETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IRETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LRETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LRETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
FRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_FRETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "FRETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
DRETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_DRETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "DRETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ARETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ARETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
RETURN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_RETURN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "RETURN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEVIRTUAL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INVOKEVIRTUAL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESPECIAL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INVOKESPECIAL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKESTATIC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INVOKESTATIC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INVOKEINTERFACE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 4;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INVOKEINTERFACE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEW:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEW");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ARRAYLENGTH
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ARRAYLENGTH:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ARRAYLENGTH");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ATHROW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ATHROW:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ATHROW");
#endif
	break;
      }

/*
----------------------------------------------------------------------
CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_CHECKCAST:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "CHECKCAST");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INSTANCEOF:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INSTANCEOF");
#endif
	break;
      }

/*
----------------------------------------------------------------------
MONITORENTER
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITORENTER:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "MONITORENTER");
#endif
	break;
      }

/*
----------------------------------------------------------------------
MONITOREXIT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MONITOREXIT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 0;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "MONITOREXIT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNULL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNULL_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNULL_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNONNULL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNONNULL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
IFNONNULL_CHECK
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_IFNONNULL_CHECK:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "IFNONNULL_CHECK");
#endif
	break;
      }

/*
----------------------------------------------------------------------
LINK_NATIVE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_LINK_NATIVE_METHOD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "LINK_NATIVE_METHOD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ABSTRACT_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ABSTRACT_METHOD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ABSTRACT_METHOD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NATIVE_STATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_STATIC_METHOD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NATIVE_STATIC_METHOD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NATIVE_NONSTATIC_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NATIVE_NONSTATIC_METHOD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NATIVE_NONSTATIC_METHOD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETFIELD_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTFIELD_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_GETSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "GETSTATIC_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PUTSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PUTSTATIC_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_RET
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_RET_0
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_0:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_0");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_RET_1
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_1:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_1");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_RET_2
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_2:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_2");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ASTORE_RET_3
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ASTORE_RET_3:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ASTORE_RET_3");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEXT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEXT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEXT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
NEWARRAY_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_NEWARRAY_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "NEWARRAY_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ANEWARRAY:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 2;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ANEWARRAY");
#endif
	break;
      }

/*
----------------------------------------------------------------------
MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_MULTIANEWARRAY:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = 3;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "MULTIANEWARRAY");
#endif
	break;
      }

/*
----------------------------------------------------------------------
ERROR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_ERROR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "ERROR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
INTERNAL_CALL_END
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_INTERNAL_CALL_END:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "INTERNAL_CALL_END");
#endif
	break;
      }

/*
----------------------------------------------------------------------
SKIP
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_SKIP:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "SKIP");
#endif
	break;
      }

/*
----------------------------------------------------------------------
REPLACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_REPLACE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "REPLACE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_METHOD
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_METHOD:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_METHOD");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_LDC_STRING
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_LDC_STRING:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_LDC_STRING");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETFIELD_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETFIELD_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTFIELD_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTFIELD_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTFIELD_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_GETSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_GETSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_GETSTATIC_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BOOLEAN
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BOOLEAN:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_BOOLEAN");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_BYTE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_BYTE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_BYTE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_SHORT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_SHORT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_SHORT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_CHAR
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_CHAR:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_CHAR");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_INT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_INT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_INT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_LONG
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_LONG:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_LONG");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_FLOAT
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_FLOAT:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_FLOAT");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_DOUBLE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_DOUBLE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_DOUBLE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_PUTSTATIC_REFERENCE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_PUTSTATIC_REFERENCE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_PUTSTATIC_REFERENCE");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_CHECKCAST
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_CHECKCAST:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_CHECKCAST");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_INSTANCEOF
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INSTANCEOF:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_INSTANCEOF");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_NEW
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_NEW:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_NEW");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_ANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_ANEWARRAY:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_ANEWARRAY");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_MULTIANEWARRAY
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_MULTIANEWARRAY:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_MULTIANEWARRAY");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKEVIRTUAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEVIRTUAL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKEVIRTUAL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKESPECIAL
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESPECIAL:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKESPECIAL");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKESTATIC
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKESTATIC:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKESTATIC");
#endif
	break;
      }

/*
----------------------------------------------------------------------
PREPARE_INVOKEINTERFACE
----------------------------------------------------------------------
*/

    case SVM_INSTRUCTION_PREPARE_INVOKEINTERFACE:
      {
	env->vm->instructions[instr].code.jint = instr;
	env->vm->instructions[instr].param_count = -1;
#ifndef NDEBUG
	strcpy (env->vm->instructions[instr].name, "PREPARE_INVOKEINTERFACE");
#endif
	break;
      }
