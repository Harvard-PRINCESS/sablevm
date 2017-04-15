/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* m4svm_file_name */

/*
----------------------------------------------------------------------
m4svm_create_link_and_initialize_class
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_create_link_and_initialize_class:])";

  /* Create[:,:] link[:,:] and initialize class: $1 */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "$1", vm->class_loading.boot_loader.classes.$2) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class $1.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.$2) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class $1.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.$2) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class $1.\n");
      return JNI_ERR;
    }
  m4svm_define_end v = ":])";
}

/*
----------------------------------------------------------------------
m4svm_create_and_link_array
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_create_and_link_array:])";

  /* Create and link array: $1 */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "$1", vm->class_loading.boot_loader.classes.$2) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.$2) != JNI_OK)
    {
      return JNI_ERR;
    }
  m4svm_define_end v = ":])";
}

/*
----------------------------------------------------------------------
m4svm_find_method
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_find_method:])";

  /* Find method: $3.$1$2 */
  vm->class_loading.boot_loader.methods.$3_$4 =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.$3,
			  "$1", "$2");

  if (vm->class_loading.boot_loader.methods.$3_$4 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method $1 in $3 class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }
  m4svm_define_end v = ":])";
}

/*
----------------------------------------------------------------------
m4svm_find_field
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_find_field:])";

  /* Find field: $3.($2)$1 */
  vm->class_loading.boot_loader.fields.$3_$4 =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.$3,
			 "$1", "$2");

  if (vm->class_loading.boot_loader.fields.$3_$4 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field $1 in $3 class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }
  m4svm_define_end v = ":])";
}

/*
----------------------------------------------------------------------
m4svm_instantiate_and_init_primitive_type
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_instantiate_and_init_primitive_type:])";

  /* instantiate and init the $2 class instance */
  {
    jobject obj;

    if (_svmm_new_native_global (env, obj) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.jlclass, *obj) != JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, '$1') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.$2_type = obj;
  }
  m4svm_define_end v = ":])";
}

/*
----------------------------------------------------------------------
m4svm_instantiate_and_init_error
----------------------------------------------------------------------
*/

void
m4_dnl ()
{
  m4svm_define_begin v = ":], [:m4svm_instantiate_and_init_error:])";

  /* instantiate and init the default $1 instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.$1, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_$1_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_$1 = error;
  }
  m4svm_define_end v = ":])";
}

/* m4svm_on(0)m4_dnl */

/*
----------------------------------------------------------------------
_svmf_bootstrap
----------------------------------------------------------------------
*/

svm_static jint
_svmf_bootstrap (_svmt_JNIEnv *env)
{
  _svmt_JavaVM *vm = env->vm;

  if (_svmf_bootcl_internal_split_bootcl (env) != JNI_OK)
    return JNI_ERR;

  /* We must create the following classes and array first. This will
     allow us to create java/lang/Class instances.

     Initialization is done in a special way. Initialization checks
     that there is no <clinit> method.  This is a requirement SableVM
     imposes on classes internally created.

     Rationale: Initialization can possibly cause the execution of an
     arbitrary amount of bytecode in an unrestricted number of
     classes.  At bootstrapping time, though, SableVM is not yet ready
     to run arbitrary code.

     If you really need to use static initializers in such classes,
     simply put your static initializers in static inner classes;
     you'll achieve equivalent semantics while also complying with
     SableVM's "no <clinit>" requirement. *[::]/
     m4svm_off()

     m4svm_create_link_and_initialize_class(java/lang/Object, jlobject)
     m4svm_create_link_and_initialize_class(java/io/Serializable, jiserializable)
     m4svm_create_link_and_initialize_class(java/lang/Cloneable, jlcloneable)
     m4svm_create_and_link_array([B, byte_array)
     m4svm_create_link_and_initialize_class(java/lang/VMClass, jlvmclass)
     m4svm_create_link_and_initialize_class(java/lang/Class, jlclass)

     m4svm_on(0)m4_dnl */

  /* find java/lang/Class constructor */

  vm->class_loading.boot_loader.methods.jlclass_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlclass,
			  "<init>",
			  "(Ljava/lang/Object;Ljava/security/ProtectionDomain;)V");

  if (vm->class_loading.boot_loader.methods.jlclass_init == NULL)
    {
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Now, we're ready to create "java/lang/Class" instances.

     IMPORTANT: Usually, this is automatically done by
     _svmf_create_class and _svmf_create_array, so you should not call
     _svmf_new_class.  In this particular case, though,
     "java/lang/Class" was't yet created, so _svmf_create_class and
     _svmf_create_array were not able to invoke _svmf_new_class; so we
     do it now. */

  /*
     The constructor of java.lang.Class should look like this:

     private Class(byte[] vmData)
     {
     this.vmData = vmData;
     }

     In bytecode:

     0 aload_0
     1 invokespecial <Method java.lang.Object()>
     4 aload_0
     5 aload_1
     6 putfield <Field byte[] vmData>
     9 return


     *** Update for Classpath 0.06 ************************************

     With Classpath 0.06 the constructor of java.lang.Class looks like:

     Class(RawData vmData)
     {
     this.vmClass = new VMClass(vmData);
     this.vmData = vmData;
     }

     Ideally, it should look like:

     Class(VMClass vmClass)
     {
     this.vmClass = vmClass;
     }

     We are still in transition towards the VM{Classes} interface.

     Note also that RawData still correspond to a Java byte[].  In
     other words the runtime type of RawData is byte[] although its
     compile type is RawData.  It is still used the same way as before.

     ******************************************************************

   */

  if (_svmf_new_class
      (env, _svmf_cast_type_class
       (vm->class_loading.boot_loader.classes.jlobject)) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_new_class
      (env, _svmf_cast_type_class
       (vm->class_loading.boot_loader.classes.jiserializable)) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_new_class
      (env, _svmf_cast_type_class
       (vm->class_loading.boot_loader.classes.jlcloneable)) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_new_class
      (env, _svmf_cast_type_array
       (vm->class_loading.boot_loader.classes.byte_array)) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_new_class
      (env, _svmf_cast_type_class
       (vm->class_loading.boot_loader.classes.jlvmclass)) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_new_class
      (env, _svmf_cast_type_class
       (vm->class_loading.boot_loader.classes.jlclass)) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* create, link, and intialize various classes and arrays *[::]/
     m4svm_off()

     m4svm_create_link_and_initialize_class(java/lang/StackTraceElement, jlstacktraceelement)
     m4svm_create_link_and_initialize_class(java/lang/StringCreator, stringcreator)
     m4svm_create_link_and_initialize_class(java/lang/VirtualMachine, virtualmachine)
     m4svm_create_link_and_initialize_class(java/lang/reflect/Constructor, jlrconstructor)
     m4svm_create_link_and_initialize_class(java/lang/reflect/Field, jlrfield)
     m4svm_create_link_and_initialize_class(java/lang/reflect/InvocationTargetException, jlrinvocationtargetexception)
     m4svm_create_link_and_initialize_class(java/lang/reflect/Method, jlrmethod)
     m4svm_create_link_and_initialize_class(java/nio/ByteBuffer$vm, niobytebuffervm)

     m4svm_create_and_link_array([Ljava/lang/reflect/Field;, jlrfield_array)

     m4svm_create_and_link_array([Z, boolean_array)
     m4svm_create_and_link_array([S, short_array)
     m4svm_create_and_link_array([C, char_array)
     m4svm_create_and_link_array([I, int_array)
     m4svm_create_and_link_array([J, long_array)
     m4svm_create_and_link_array([F, float_array)
     m4svm_create_and_link_array([D, double_array)

     m4svm_create_link_and_initialize_class(java/lang/ArithmeticException, ArithmeticException)
     m4svm_create_link_and_initialize_class(java/lang/ArrayIndexOutOfBoundsException, ArrayIndexOutOfBoundsException)
     m4svm_create_link_and_initialize_class(java/lang/ArrayStoreException, ArrayStoreException)
     m4svm_create_link_and_initialize_class(java/lang/ClassCastException, ClassCastException)
     m4svm_create_link_and_initialize_class(java/lang/IllegalMonitorStateException, IllegalMonitorStateException)
     m4svm_create_link_and_initialize_class(java/lang/NegativeArraySizeException, NegativeArraySizeException)
     m4svm_create_link_and_initialize_class(java/lang/NoSuchFieldException, NoSuchFieldException)
     m4svm_create_link_and_initialize_class(java/lang/NoSuchMethodException, NoSuchMethodException)
     m4svm_create_link_and_initialize_class(java/lang/NullPointerException, NullPointerException)
     m4svm_create_link_and_initialize_class(java/lang/InterruptedException, InterruptedException)
     m4svm_on(0)
     #if defined(_SABLEVM_INLINABILITY_TESTING)
     m4svm_off()
     m4svm_create_link_and_initialize_class(java/lang/InliningException, InliningException)
     m4svm_on(0)
     #endif
     m4svm_off()

     m4svm_create_link_and_initialize_class(java/lang/AbstractMethodError, AbstractMethodError)
     m4svm_create_link_and_initialize_class(java/lang/ClassCircularityError, ClassCircularityError)
     m4svm_create_link_and_initialize_class(java/lang/ClassFormatError, ClassFormatError)
     m4svm_create_link_and_initialize_class(java/lang/ExceptionInInitializerError, ExceptionInInitializerError)
     m4svm_create_link_and_initialize_class(java/lang/IncompatibleClassChangeError, IncompatibleClassChangeError)
     m4svm_create_link_and_initialize_class(java/lang/InternalError, InternalError)
     m4svm_create_link_and_initialize_class(java/lang/LinkageError, LinkageError)
     m4svm_create_link_and_initialize_class(java/lang/NoClassDefFoundError, NoClassDefFoundError)
     m4svm_create_link_and_initialize_class(java/lang/NoSuchFieldError, NoSuchFieldError)
     m4svm_create_link_and_initialize_class(java/lang/NoSuchMethodError, NoSuchMethodError)
     m4svm_create_link_and_initialize_class(java/lang/OutOfMemoryError, OutOfMemoryError)
     m4svm_create_link_and_initialize_class(java/lang/UnsatisfiedLinkError, UnsatisfiedLinkError)
     m4svm_create_link_and_initialize_class(java/lang/UnsupportedClassVersionError, UnsupportedClassVersionError)
     m4svm_create_link_and_initialize_class(java/lang/VerifyError, VerifyError)

     m4svm_on(0)m4_dnl */

  /* find some methods *[::]/
     m4svm_off()

     m4svm_find_method(<init>, (C)V, jlclass, init_primitive)
     m4svm_find_method(<init>, (Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Z)V, jlstacktraceelement, init)
     m4svm_find_method(<init>, (Ljava/lang/Throwable;)V, jlrinvocationtargetexception, init)
     m4svm_find_method(<init>, ([B)V, jlrconstructor, init)
     m4svm_find_method(<init>, ([B)V, jlrfield, init)
     m4svm_find_method(<init>, ([B)V, jlrmethod, init)
     m4svm_find_method(createArray, (Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class;, virtualmachine, createarray)
     m4svm_find_method(createClass, (Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class;, virtualmachine, createclass)
     m4svm_find_method(createInternedString, ([B)Ljava/lang/String;, stringcreator, createinternedstring)
     m4svm_find_method(createRootThread, ([B)Ljava/lang/Thread;, virtualmachine, createrootthread)
     m4svm_find_method(createString, ([B)Ljava/lang/String;, stringcreator, createstring)
     m4svm_find_method(createStringFromChars, ([C)Ljava/lang/String;, stringcreator, createstringfromchars)
     m4svm_find_method(exceptionDescribe, (Ljava/lang/Throwable;)V, virtualmachine, exceptiondescribe)
     m4svm_find_method(exceptionDescription, (Ljava/lang/Throwable;)Ljava/lang/String;, virtualmachine, exceptiondescription)
     m4svm_find_method(exceptionTruncatedDescription, (Ljava/lang/Throwable;)Ljava/lang/String;, virtualmachine, exceptiontruncateddescription)
     m4svm_find_method(getChars, (Ljava/lang/String;)[C, stringcreator, getchars)
     m4svm_find_method(getLength, (Ljava/lang/String;)I, stringcreator, getlength)
     m4svm_find_method(getSystemClassLoader, ()[B, virtualmachine, getsystemcl)
     m4svm_find_method(getUTFChars, (Ljava/lang/String;)[B, stringcreator, getutfchars)
     m4svm_find_method(getUTFLength, (Ljava/lang/String;)I, stringcreator, getutflength)
     m4svm_find_method(initialize, (I)V, jlclass, initialize)
     m4svm_find_method(runThread, ()V, virtualmachine, runthread)
     m4svm_find_method(vmGetDirectBufferCapacity, (Ljava/nio/ByteBuffer;)J, niobytebuffervm, getcapacity)

     m4svm_on(0)
     #if SVM_WORD_BIT_COUNT == 32
     m4svm_off()

     m4svm_find_method(vmGetDirectBufferAddress32, (Ljava/nio/ByteBuffer;)I, niobytebuffervm, getaddress32)
     m4svm_find_method(vmNewDirectByteBuffer32, (IJ)Ljava/nio/ByteBuffer;, niobytebuffervm, newbuffer32)

     m4svm_on(0)
     #elif SVM_WORD_BIT_COUNT == 64
     m4svm_off()

     m4svm_find_method(vmGetDirectBufferAddress64, (Ljava/nio/ByteBuffer;)J, niobytebuffervm, getaddress64)
     m4svm_find_method(vmNewDirectByteBuffer64, (JJ)Ljava/nio/ByteBuffer;, niobytebuffervm, newbuffer64)

     m4svm_on(0)
     #endif
     m4svm_off()

     m4svm_find_method(<init>, (Ljava/lang/String;)V, ArithmeticException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ArrayIndexOutOfBoundsException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ArrayStoreException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ClassCastException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, IllegalMonitorStateException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NegativeArraySizeException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NoSuchFieldException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NoSuchMethodException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NullPointerException, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, InterruptedException, init)
     m4svm_on(0)
     #if defined(_SABLEVM_INLINABILITY_TESTING)
     m4svm_off()
     m4svm_find_method(<init>, (Ljava/lang/String;)V, InliningException, init)
     m4svm_on(0)
     #endif
     m4svm_off()

     m4svm_find_method(<init>, (Ljava/lang/String;)V, AbstractMethodError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ClassCircularityError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ClassFormatError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, ExceptionInInitializerError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, IncompatibleClassChangeError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, InternalError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, LinkageError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NoClassDefFoundError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NoSuchFieldError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, NoSuchMethodError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, OutOfMemoryError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, UnsatisfiedLinkError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, UnsupportedClassVersionError, init)
     m4svm_find_method(<init>, (Ljava/lang/String;)V, VerifyError, init)

     m4svm_on(0)m4_dnl */

  /* find some fields *[::]/
     m4svm_off()

     m4svm_find_field(vmdata, Ljava/lang/Object;, jlclass, vmdata)
     m4svm_find_field(vmData, [B, jlrfield, vmdata)
     m4svm_find_field(vmData, [B, jlrmethod, vmdata)
     m4svm_find_field(vmData, [B, jlrconstructor, vmdata)
     m4svm_find_field(next, Ljava/lang/StackTraceElement;, jlstacktraceelement, next)
     m4svm_find_field(length, I, jlstacktraceelement, length)

     m4svm_on(0)m4_dnl */

  /* create default error and exception instances *[::]/
     m4svm_off()

     m4svm_instantiate_and_init_primitive_type(Z, boolean)
     m4svm_instantiate_and_init_primitive_type(B, byte)
     m4svm_instantiate_and_init_primitive_type(S, short)
     m4svm_instantiate_and_init_primitive_type(C, char)
     m4svm_instantiate_and_init_primitive_type(I, int)
     m4svm_instantiate_and_init_primitive_type(J, long)
     m4svm_instantiate_and_init_primitive_type(F, float)
     m4svm_instantiate_and_init_primitive_type(D, double)
     m4svm_instantiate_and_init_primitive_type(V, void)

     m4svm_instantiate_and_init_error(ArithmeticException)
     m4svm_instantiate_and_init_error(ArrayIndexOutOfBoundsException)
     m4svm_instantiate_and_init_error(ArrayStoreException)
     m4svm_instantiate_and_init_error(ClassCastException)
     m4svm_instantiate_and_init_error(IllegalMonitorStateException)
     m4svm_instantiate_and_init_error(NegativeArraySizeException)
     m4svm_instantiate_and_init_error(NoSuchFieldException)
     m4svm_instantiate_and_init_error(NoSuchMethodException)
     m4svm_instantiate_and_init_error(NullPointerException)
     m4svm_instantiate_and_init_error(InterruptedException)
     m4svm_on(0)
     #if defined(_SABLEVM_INLINABILITY_TESTING)
     m4svm_off()
     m4svm_instantiate_and_init_error(InliningException)
     m4svm_on(0)
     #endif
     m4svm_off()

     m4svm_instantiate_and_init_error(ExceptionInInitializerError)
     m4svm_instantiate_and_init_error(AbstractMethodError)
     m4svm_instantiate_and_init_error(ClassCircularityError)
     m4svm_instantiate_and_init_error(ClassFormatError)
     m4svm_instantiate_and_init_error(IncompatibleClassChangeError)
     m4svm_instantiate_and_init_error(InternalError)
     m4svm_instantiate_and_init_error(LinkageError)
     m4svm_instantiate_and_init_error(NoClassDefFoundError)
     m4svm_instantiate_and_init_error(NoSuchFieldError)
     m4svm_instantiate_and_init_error(NoSuchMethodError)
     m4svm_instantiate_and_init_error(OutOfMemoryError)
     m4svm_instantiate_and_init_error(UnsatisfiedLinkError)
     m4svm_instantiate_and_init_error(UnsupportedClassVersionError)
     m4svm_instantiate_and_init_error(VerifyError)

     m4svm_on(0)m4_dnl */

  return JNI_OK;
}
