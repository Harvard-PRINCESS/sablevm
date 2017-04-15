/* This file has been automatically generated from "bootstrap.m4.c" */

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
     SableVM's "no <clinit>" requirement. */
     
  /* Create, link, and initialize class: java/lang/Object */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/Object", vm->class_loading.boot_loader.classes.jlobject) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/Object.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlobject) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/Object.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlobject) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/Object.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/io/Serializable */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/io/Serializable", vm->class_loading.boot_loader.classes.jiserializable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/io/Serializable.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jiserializable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/io/Serializable.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jiserializable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/io/Serializable.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/Cloneable */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/Cloneable", vm->class_loading.boot_loader.classes.jlcloneable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/Cloneable.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlcloneable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/Cloneable.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlcloneable) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/Cloneable.\n");
      return JNI_ERR;
    }

  /* Create and link array: [B */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[B", vm->class_loading.boot_loader.classes.byte_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.byte_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/VMClass */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/VMClass", vm->class_loading.boot_loader.classes.jlvmclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/VMClass.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlvmclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/VMClass.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlvmclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/VMClass.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/Class */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/Class", vm->class_loading.boot_loader.classes.jlclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/Class.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/Class.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlclass) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/Class.\n");
      return JNI_ERR;
    }

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

  /* create, link, and intialize various classes and arrays */
     
  /* Create, link, and initialize class: java/lang/StackTraceElement */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/StackTraceElement", vm->class_loading.boot_loader.classes.jlstacktraceelement) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/StackTraceElement.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlstacktraceelement) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/StackTraceElement.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlstacktraceelement) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/StackTraceElement.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/StringCreator */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/StringCreator", vm->class_loading.boot_loader.classes.stringcreator) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/StringCreator.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.stringcreator) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/StringCreator.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.stringcreator) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/StringCreator.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/VirtualMachine */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/VirtualMachine", vm->class_loading.boot_loader.classes.virtualmachine) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/VirtualMachine.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.virtualmachine) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/VirtualMachine.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.virtualmachine) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/VirtualMachine.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/reflect/Constructor */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/reflect/Constructor", vm->class_loading.boot_loader.classes.jlrconstructor) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/reflect/Constructor.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlrconstructor) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/reflect/Constructor.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlrconstructor) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/reflect/Constructor.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/reflect/Field */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/reflect/Field", vm->class_loading.boot_loader.classes.jlrfield) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/reflect/Field.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlrfield) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/reflect/Field.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlrfield) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/reflect/Field.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/reflect/InvocationTargetException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/reflect/InvocationTargetException", vm->class_loading.boot_loader.classes.jlrinvocationtargetexception) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/reflect/InvocationTargetException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlrinvocationtargetexception) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/reflect/InvocationTargetException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlrinvocationtargetexception) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/reflect/InvocationTargetException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/reflect/Method */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/reflect/Method", vm->class_loading.boot_loader.classes.jlrmethod) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/reflect/Method.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.jlrmethod) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/reflect/Method.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.jlrmethod) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/reflect/Method.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/nio/ByteBuffer$vm */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/nio/ByteBuffer$vm", vm->class_loading.boot_loader.classes.niobytebuffervm) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/nio/ByteBuffer$vm.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.niobytebuffervm) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/nio/ByteBuffer$vm.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.niobytebuffervm) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/nio/ByteBuffer$vm.\n");
      return JNI_ERR;
    }

  /* Create and link array: [Ljava/lang/reflect/Field; */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[Ljava/lang/reflect/Field;", vm->class_loading.boot_loader.classes.jlrfield_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.jlrfield_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [Z */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[Z", vm->class_loading.boot_loader.classes.boolean_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.boolean_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [S */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[S", vm->class_loading.boot_loader.classes.short_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.short_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [C */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[C", vm->class_loading.boot_loader.classes.char_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.char_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [I */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[I", vm->class_loading.boot_loader.classes.int_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.int_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [J */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[J", vm->class_loading.boot_loader.classes.long_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.long_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [F */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[F", vm->class_loading.boot_loader.classes.float_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.float_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create and link array: [D */
  if (_svmm_create_array
      (env, vm->class_loading.boot_loader.class_loader_info,
       "[D", vm->class_loading.boot_loader.classes.double_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  if (_svmf_link_array
      (env, vm->class_loading.boot_loader.classes.double_array) != JNI_OK)
    {
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ArithmeticException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ArithmeticException", vm->class_loading.boot_loader.classes.ArithmeticException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ArithmeticException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ArithmeticException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ArithmeticException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ArithmeticException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ArithmeticException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ArrayIndexOutOfBoundsException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ArrayIndexOutOfBoundsException", vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ArrayIndexOutOfBoundsException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ArrayIndexOutOfBoundsException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ArrayIndexOutOfBoundsException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ArrayStoreException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ArrayStoreException", vm->class_loading.boot_loader.classes.ArrayStoreException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ArrayStoreException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ArrayStoreException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ArrayStoreException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ArrayStoreException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ArrayStoreException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ClassCastException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ClassCastException", vm->class_loading.boot_loader.classes.ClassCastException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ClassCastException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ClassCastException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ClassCastException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ClassCastException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ClassCastException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/IllegalMonitorStateException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/IllegalMonitorStateException", vm->class_loading.boot_loader.classes.IllegalMonitorStateException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/IllegalMonitorStateException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.IllegalMonitorStateException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/IllegalMonitorStateException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.IllegalMonitorStateException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/IllegalMonitorStateException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NegativeArraySizeException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NegativeArraySizeException", vm->class_loading.boot_loader.classes.NegativeArraySizeException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NegativeArraySizeException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NegativeArraySizeException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NegativeArraySizeException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NegativeArraySizeException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NegativeArraySizeException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NoSuchFieldException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NoSuchFieldException", vm->class_loading.boot_loader.classes.NoSuchFieldException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NoSuchFieldException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NoSuchFieldException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NoSuchFieldException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NoSuchFieldException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NoSuchFieldException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NoSuchMethodException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NoSuchMethodException", vm->class_loading.boot_loader.classes.NoSuchMethodException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NoSuchMethodException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NoSuchMethodException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NoSuchMethodException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NoSuchMethodException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NoSuchMethodException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NullPointerException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NullPointerException", vm->class_loading.boot_loader.classes.NullPointerException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NullPointerException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NullPointerException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NullPointerException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NullPointerException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NullPointerException.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/InterruptedException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/InterruptedException", vm->class_loading.boot_loader.classes.InterruptedException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/InterruptedException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.InterruptedException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/InterruptedException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.InterruptedException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/InterruptedException.\n");
      return JNI_ERR;
    }

     #if defined(_SABLEVM_INLINABILITY_TESTING)
     
  /* Create, link, and initialize class: java/lang/InliningException */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/InliningException", vm->class_loading.boot_loader.classes.InliningException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/InliningException.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.InliningException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/InliningException.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.InliningException) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/InliningException.\n");
      return JNI_ERR;
    }

     #endif
     
  /* Create, link, and initialize class: java/lang/AbstractMethodError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/AbstractMethodError", vm->class_loading.boot_loader.classes.AbstractMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/AbstractMethodError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.AbstractMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/AbstractMethodError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.AbstractMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/AbstractMethodError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ClassCircularityError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ClassCircularityError", vm->class_loading.boot_loader.classes.ClassCircularityError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ClassCircularityError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ClassCircularityError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ClassCircularityError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ClassCircularityError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ClassCircularityError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ClassFormatError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ClassFormatError", vm->class_loading.boot_loader.classes.ClassFormatError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ClassFormatError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ClassFormatError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ClassFormatError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ClassFormatError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ClassFormatError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/ExceptionInInitializerError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/ExceptionInInitializerError", vm->class_loading.boot_loader.classes.ExceptionInInitializerError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/ExceptionInInitializerError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.ExceptionInInitializerError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/ExceptionInInitializerError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.ExceptionInInitializerError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/ExceptionInInitializerError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/IncompatibleClassChangeError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/IncompatibleClassChangeError", vm->class_loading.boot_loader.classes.IncompatibleClassChangeError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/IncompatibleClassChangeError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.IncompatibleClassChangeError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/IncompatibleClassChangeError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.IncompatibleClassChangeError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/IncompatibleClassChangeError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/InternalError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/InternalError", vm->class_loading.boot_loader.classes.InternalError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/InternalError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.InternalError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/InternalError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.InternalError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/InternalError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/LinkageError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/LinkageError", vm->class_loading.boot_loader.classes.LinkageError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/LinkageError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.LinkageError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/LinkageError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.LinkageError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/LinkageError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NoClassDefFoundError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NoClassDefFoundError", vm->class_loading.boot_loader.classes.NoClassDefFoundError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NoClassDefFoundError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NoClassDefFoundError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NoClassDefFoundError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NoClassDefFoundError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NoClassDefFoundError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NoSuchFieldError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NoSuchFieldError", vm->class_loading.boot_loader.classes.NoSuchFieldError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NoSuchFieldError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NoSuchFieldError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NoSuchFieldError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NoSuchFieldError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NoSuchFieldError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/NoSuchMethodError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/NoSuchMethodError", vm->class_loading.boot_loader.classes.NoSuchMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/NoSuchMethodError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.NoSuchMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/NoSuchMethodError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.NoSuchMethodError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/NoSuchMethodError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/OutOfMemoryError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/OutOfMemoryError", vm->class_loading.boot_loader.classes.OutOfMemoryError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/OutOfMemoryError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.OutOfMemoryError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/OutOfMemoryError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.OutOfMemoryError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/OutOfMemoryError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/UnsatisfiedLinkError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/UnsatisfiedLinkError", vm->class_loading.boot_loader.classes.UnsatisfiedLinkError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/UnsatisfiedLinkError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.UnsatisfiedLinkError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/UnsatisfiedLinkError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.UnsatisfiedLinkError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/UnsatisfiedLinkError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/UnsupportedClassVersionError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/UnsupportedClassVersionError", vm->class_loading.boot_loader.classes.UnsupportedClassVersionError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/UnsupportedClassVersionError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.UnsupportedClassVersionError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/UnsupportedClassVersionError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.UnsupportedClassVersionError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/UnsupportedClassVersionError.\n");
      return JNI_ERR;
    }

  /* Create, link, and initialize class: java/lang/VerifyError */
  if (_svmm_create_class
      (env, vm->class_loading.boot_loader.class_loader_info,
       "java/lang/VerifyError", vm->class_loading.boot_loader.classes.VerifyError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to create essential class java/lang/VerifyError.\n");
      return JNI_ERR;
    }

  if (_svmf_link_class
      (env, vm->class_loading.boot_loader.classes.VerifyError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to link essential class java/lang/VerifyError.\n");
      return JNI_ERR;
    }

  if (_svmf_special_initialization
      (env, vm->class_loading.boot_loader.classes.VerifyError) != JNI_OK)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to initialize essential class java/lang/VerifyError.\n");
      return JNI_ERR;
    }

  /* find some methods */
     
  /* Find method: jlclass.<init>(C)V */
  vm->class_loading.boot_loader.methods.jlclass_init_primitive =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlclass,
			  "<init>", "(C)V");

  if (vm->class_loading.boot_loader.methods.jlclass_init_primitive == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlclass class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlstacktraceelement.<init>(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Z)V */
  vm->class_loading.boot_loader.methods.jlstacktraceelement_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlstacktraceelement,
			  "<init>", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Z)V");

  if (vm->class_loading.boot_loader.methods.jlstacktraceelement_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlstacktraceelement class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlrinvocationtargetexception.<init>(Ljava/lang/Throwable;)V */
  vm->class_loading.boot_loader.methods.jlrinvocationtargetexception_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlrinvocationtargetexception,
			  "<init>", "(Ljava/lang/Throwable;)V");

  if (vm->class_loading.boot_loader.methods.jlrinvocationtargetexception_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlrinvocationtargetexception class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlrconstructor.<init>([B)V */
  vm->class_loading.boot_loader.methods.jlrconstructor_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlrconstructor,
			  "<init>", "([B)V");

  if (vm->class_loading.boot_loader.methods.jlrconstructor_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlrconstructor class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlrfield.<init>([B)V */
  vm->class_loading.boot_loader.methods.jlrfield_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlrfield,
			  "<init>", "([B)V");

  if (vm->class_loading.boot_loader.methods.jlrfield_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlrfield class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlrmethod.<init>([B)V */
  vm->class_loading.boot_loader.methods.jlrmethod_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlrmethod,
			  "<init>", "([B)V");

  if (vm->class_loading.boot_loader.methods.jlrmethod_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in jlrmethod class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.createArray(Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class; */
  vm->class_loading.boot_loader.methods.virtualmachine_createarray =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "createArray", "(Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class;");

  if (vm->class_loading.boot_loader.methods.virtualmachine_createarray == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createArray in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.createClass(Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class; */
  vm->class_loading.boot_loader.methods.virtualmachine_createclass =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "createClass", "(Ljava/lang/ClassLoader;Ljava/lang/String;)Ljava/lang/Class;");

  if (vm->class_loading.boot_loader.methods.virtualmachine_createclass == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createClass in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.createInternedString([B)Ljava/lang/String; */
  vm->class_loading.boot_loader.methods.stringcreator_createinternedstring =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "createInternedString", "([B)Ljava/lang/String;");

  if (vm->class_loading.boot_loader.methods.stringcreator_createinternedstring == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createInternedString in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.createRootThread([B)Ljava/lang/Thread; */
  vm->class_loading.boot_loader.methods.virtualmachine_createrootthread =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "createRootThread", "([B)Ljava/lang/Thread;");

  if (vm->class_loading.boot_loader.methods.virtualmachine_createrootthread == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createRootThread in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.createString([B)Ljava/lang/String; */
  vm->class_loading.boot_loader.methods.stringcreator_createstring =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "createString", "([B)Ljava/lang/String;");

  if (vm->class_loading.boot_loader.methods.stringcreator_createstring == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createString in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.createStringFromChars([C)Ljava/lang/String; */
  vm->class_loading.boot_loader.methods.stringcreator_createstringfromchars =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "createStringFromChars", "([C)Ljava/lang/String;");

  if (vm->class_loading.boot_loader.methods.stringcreator_createstringfromchars == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method createStringFromChars in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.exceptionDescribe(Ljava/lang/Throwable;)V */
  vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescribe =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "exceptionDescribe", "(Ljava/lang/Throwable;)V");

  if (vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescribe == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method exceptionDescribe in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.exceptionDescription(Ljava/lang/Throwable;)Ljava/lang/String; */
  vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescription =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "exceptionDescription", "(Ljava/lang/Throwable;)Ljava/lang/String;");

  if (vm->class_loading.boot_loader.methods.virtualmachine_exceptiondescription == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method exceptionDescription in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.exceptionTruncatedDescription(Ljava/lang/Throwable;)Ljava/lang/String; */
  vm->class_loading.boot_loader.methods.virtualmachine_exceptiontruncateddescription =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "exceptionTruncatedDescription", "(Ljava/lang/Throwable;)Ljava/lang/String;");

  if (vm->class_loading.boot_loader.methods.virtualmachine_exceptiontruncateddescription == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method exceptionTruncatedDescription in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.getChars(Ljava/lang/String;)[C */
  vm->class_loading.boot_loader.methods.stringcreator_getchars =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "getChars", "(Ljava/lang/String;)[C");

  if (vm->class_loading.boot_loader.methods.stringcreator_getchars == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method getChars in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.getLength(Ljava/lang/String;)I */
  vm->class_loading.boot_loader.methods.stringcreator_getlength =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "getLength", "(Ljava/lang/String;)I");

  if (vm->class_loading.boot_loader.methods.stringcreator_getlength == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method getLength in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.getSystemClassLoader()[B */
  vm->class_loading.boot_loader.methods.virtualmachine_getsystemcl =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "getSystemClassLoader", "()[B");

  if (vm->class_loading.boot_loader.methods.virtualmachine_getsystemcl == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method getSystemClassLoader in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.getUTFChars(Ljava/lang/String;)[B */
  vm->class_loading.boot_loader.methods.stringcreator_getutfchars =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "getUTFChars", "(Ljava/lang/String;)[B");

  if (vm->class_loading.boot_loader.methods.stringcreator_getutfchars == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method getUTFChars in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: stringcreator.getUTFLength(Ljava/lang/String;)I */
  vm->class_loading.boot_loader.methods.stringcreator_getutflength =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.stringcreator,
			  "getUTFLength", "(Ljava/lang/String;)I");

  if (vm->class_loading.boot_loader.methods.stringcreator_getutflength == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method getUTFLength in stringcreator class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: jlclass.initialize(I)V */
  vm->class_loading.boot_loader.methods.jlclass_initialize =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.jlclass,
			  "initialize", "(I)V");

  if (vm->class_loading.boot_loader.methods.jlclass_initialize == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method initialize in jlclass class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: virtualmachine.runThread()V */
  vm->class_loading.boot_loader.methods.virtualmachine_runthread =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.virtualmachine,
			  "runThread", "()V");

  if (vm->class_loading.boot_loader.methods.virtualmachine_runthread == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method runThread in virtualmachine class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: niobytebuffervm.vmGetDirectBufferCapacity(Ljava/nio/ByteBuffer;)J */
  vm->class_loading.boot_loader.methods.niobytebuffervm_getcapacity =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.niobytebuffervm,
			  "vmGetDirectBufferCapacity", "(Ljava/nio/ByteBuffer;)J");

  if (vm->class_loading.boot_loader.methods.niobytebuffervm_getcapacity == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method vmGetDirectBufferCapacity in niobytebuffervm class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

     #if SVM_WORD_BIT_COUNT == 32
     
  /* Find method: niobytebuffervm.vmGetDirectBufferAddress32(Ljava/nio/ByteBuffer;)I */
  vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress32 =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.niobytebuffervm,
			  "vmGetDirectBufferAddress32", "(Ljava/nio/ByteBuffer;)I");

  if (vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress32 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method vmGetDirectBufferAddress32 in niobytebuffervm class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: niobytebuffervm.vmNewDirectByteBuffer32(IJ)Ljava/nio/ByteBuffer; */
  vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer32 =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.niobytebuffervm,
			  "vmNewDirectByteBuffer32", "(IJ)Ljava/nio/ByteBuffer;");

  if (vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer32 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method vmNewDirectByteBuffer32 in niobytebuffervm class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

     #elif SVM_WORD_BIT_COUNT == 64
     
  /* Find method: niobytebuffervm.vmGetDirectBufferAddress64(Ljava/nio/ByteBuffer;)J */
  vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress64 =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.niobytebuffervm,
			  "vmGetDirectBufferAddress64", "(Ljava/nio/ByteBuffer;)J");

  if (vm->class_loading.boot_loader.methods.niobytebuffervm_getaddress64 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method vmGetDirectBufferAddress64 in niobytebuffervm class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: niobytebuffervm.vmNewDirectByteBuffer64(JJ)Ljava/nio/ByteBuffer; */
  vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer64 =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.niobytebuffervm,
			  "vmNewDirectByteBuffer64", "(JJ)Ljava/nio/ByteBuffer;");

  if (vm->class_loading.boot_loader.methods.niobytebuffervm_newbuffer64 == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method vmNewDirectByteBuffer64 in niobytebuffervm class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

     #endif
     
  /* Find method: ArithmeticException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ArithmeticException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ArithmeticException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ArithmeticException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ArithmeticException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ArrayIndexOutOfBoundsException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ArrayIndexOutOfBoundsException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ArrayIndexOutOfBoundsException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ArrayIndexOutOfBoundsException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ArrayStoreException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ArrayStoreException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ArrayStoreException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ArrayStoreException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ArrayStoreException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ClassCastException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ClassCastException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ClassCastException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ClassCastException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ClassCastException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: IllegalMonitorStateException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.IllegalMonitorStateException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.IllegalMonitorStateException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.IllegalMonitorStateException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in IllegalMonitorStateException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NegativeArraySizeException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NegativeArraySizeException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NegativeArraySizeException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NegativeArraySizeException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NegativeArraySizeException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NoSuchFieldException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NoSuchFieldException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NoSuchFieldException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NoSuchFieldException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NoSuchFieldException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NoSuchMethodException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NoSuchMethodException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NoSuchMethodException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NoSuchMethodException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NoSuchMethodException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NullPointerException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NullPointerException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NullPointerException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NullPointerException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NullPointerException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: InterruptedException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.InterruptedException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.InterruptedException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.InterruptedException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in InterruptedException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

     #if defined(_SABLEVM_INLINABILITY_TESTING)
     
  /* Find method: InliningException.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.InliningException_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.InliningException,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.InliningException_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in InliningException class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

     #endif
     
  /* Find method: AbstractMethodError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.AbstractMethodError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.AbstractMethodError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.AbstractMethodError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in AbstractMethodError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ClassCircularityError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ClassCircularityError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ClassCircularityError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ClassCircularityError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ClassCircularityError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ClassFormatError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ClassFormatError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ClassFormatError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ClassFormatError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ClassFormatError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: ExceptionInInitializerError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.ExceptionInInitializerError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.ExceptionInInitializerError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.ExceptionInInitializerError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in ExceptionInInitializerError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: IncompatibleClassChangeError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.IncompatibleClassChangeError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.IncompatibleClassChangeError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.IncompatibleClassChangeError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in IncompatibleClassChangeError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: InternalError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.InternalError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.InternalError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.InternalError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in InternalError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: LinkageError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.LinkageError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.LinkageError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.LinkageError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in LinkageError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NoClassDefFoundError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NoClassDefFoundError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NoClassDefFoundError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NoClassDefFoundError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NoClassDefFoundError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NoSuchFieldError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NoSuchFieldError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NoSuchFieldError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NoSuchFieldError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NoSuchFieldError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: NoSuchMethodError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.NoSuchMethodError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.NoSuchMethodError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.NoSuchMethodError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in NoSuchMethodError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: OutOfMemoryError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.OutOfMemoryError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.OutOfMemoryError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.OutOfMemoryError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in OutOfMemoryError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: UnsatisfiedLinkError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.UnsatisfiedLinkError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.UnsatisfiedLinkError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.UnsatisfiedLinkError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in UnsatisfiedLinkError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: UnsupportedClassVersionError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.UnsupportedClassVersionError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.UnsupportedClassVersionError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.UnsupportedClassVersionError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in UnsupportedClassVersionError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* Find method: VerifyError.<init>(Ljava/lang/String;)V */
  vm->class_loading.boot_loader.methods.VerifyError_init =
    _svmf_resolve_method (vm->class_loading.boot_loader.classes.VerifyError,
			  "<init>", "(Ljava/lang/String;)V");

  if (vm->class_loading.boot_loader.methods.VerifyError_init == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential method <init> in VerifyError class.\n");
      _svmf_error_NoSuchMethodError (env);
      return JNI_ERR;
    }

  /* find some fields */
     
  /* Find field: jlclass.(Ljava/lang/Object;)vmdata */
  vm->class_loading.boot_loader.fields.jlclass_vmdata =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlclass,
			 "vmdata", "Ljava/lang/Object;");

  if (vm->class_loading.boot_loader.fields.jlclass_vmdata == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field vmdata in jlclass class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* Find field: jlrfield.([B)vmData */
  vm->class_loading.boot_loader.fields.jlrfield_vmdata =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlrfield,
			 "vmData", "[B");

  if (vm->class_loading.boot_loader.fields.jlrfield_vmdata == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field vmData in jlrfield class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* Find field: jlrmethod.([B)vmData */
  vm->class_loading.boot_loader.fields.jlrmethod_vmdata =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlrmethod,
			 "vmData", "[B");

  if (vm->class_loading.boot_loader.fields.jlrmethod_vmdata == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field vmData in jlrmethod class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* Find field: jlrconstructor.([B)vmData */
  vm->class_loading.boot_loader.fields.jlrconstructor_vmdata =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlrconstructor,
			 "vmData", "[B");

  if (vm->class_loading.boot_loader.fields.jlrconstructor_vmdata == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field vmData in jlrconstructor class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* Find field: jlstacktraceelement.(Ljava/lang/StackTraceElement;)next */
  vm->class_loading.boot_loader.fields.jlstacktraceelement_next =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlstacktraceelement,
			 "next", "Ljava/lang/StackTraceElement;");

  if (vm->class_loading.boot_loader.fields.jlstacktraceelement_next == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field next in jlstacktraceelement class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* Find field: jlstacktraceelement.(I)length */
  vm->class_loading.boot_loader.fields.jlstacktraceelement_length =
    _svmf_resolve_field (vm->class_loading.boot_loader.classes.jlstacktraceelement,
			 "length", "I");

  if (vm->class_loading.boot_loader.fields.jlstacktraceelement_length == NULL)
    {
      _svmf_printf (env, stderr,
		    "*** Fatal error: Unable to find essential field length in jlstacktraceelement class.\n");
      _svmf_error_NoSuchFieldError (env);
      return JNI_ERR;
    }

  /* create default error and exception instances */
     
  /* instantiate and init the boolean class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'Z') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.boolean_type = obj;
  }

  /* instantiate and init the byte class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'B') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.byte_type = obj;
  }

  /* instantiate and init the short class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'S') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.short_type = obj;
  }

  /* instantiate and init the char class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'C') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.char_type = obj;
  }

  /* instantiate and init the int class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'I') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.int_type = obj;
  }

  /* instantiate and init the long class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'J') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.long_type = obj;
  }

  /* instantiate and init the float class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'F') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.float_type = obj;
  }

  /* instantiate and init the double class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'D') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.double_type = obj;
  }

  /* instantiate and init the void class instance */
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

    if (_svmm_invoke_nonvirtual_jlclass_init_primitive (env, obj, 'V') !=
	JNI_OK)
      {
	_svmm_free_native_global (env, obj);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.void_type = obj;
  }

  /* instantiate and init the default ArithmeticException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArithmeticException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ArithmeticException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ArithmeticException = error;
  }

  /* instantiate and init the default ArrayIndexOutOfBoundsException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayIndexOutOfBoundsException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ArrayIndexOutOfBoundsException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ArrayIndexOutOfBoundsException = error;
  }

  /* instantiate and init the default ArrayStoreException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ArrayStoreException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ArrayStoreException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ArrayStoreException = error;
  }

  /* instantiate and init the default ClassCastException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCastException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ClassCastException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ClassCastException = error;
  }

  /* instantiate and init the default IllegalMonitorStateException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IllegalMonitorStateException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_IllegalMonitorStateException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_IllegalMonitorStateException = error;
  }

  /* instantiate and init the default NegativeArraySizeException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NegativeArraySizeException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NegativeArraySizeException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NegativeArraySizeException = error;
  }

  /* instantiate and init the default NoSuchFieldException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NoSuchFieldException = error;
  }

  /* instantiate and init the default NoSuchMethodException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NoSuchMethodException = error;
  }

  /* instantiate and init the default NullPointerException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NullPointerException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NullPointerException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NullPointerException = error;
  }

  /* instantiate and init the default InterruptedException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InterruptedException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_InterruptedException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_InterruptedException = error;
  }

     #if defined(_SABLEVM_INLINABILITY_TESTING)
     
  /* instantiate and init the default InliningException instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InliningException, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_InliningException_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_InliningException = error;
  }

     #endif
     
  /* instantiate and init the default ExceptionInInitializerError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ExceptionInInitializerError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ExceptionInInitializerError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ExceptionInInitializerError = error;
  }

  /* instantiate and init the default AbstractMethodError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.AbstractMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_AbstractMethodError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_AbstractMethodError = error;
  }

  /* instantiate and init the default ClassCircularityError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassCircularityError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ClassCircularityError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ClassCircularityError = error;
  }

  /* instantiate and init the default ClassFormatError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.ClassFormatError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_ClassFormatError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_ClassFormatError = error;
  }

  /* instantiate and init the default IncompatibleClassChangeError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.IncompatibleClassChangeError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_IncompatibleClassChangeError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_IncompatibleClassChangeError = error;
  }

  /* instantiate and init the default InternalError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.InternalError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_InternalError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_InternalError = error;
  }

  /* instantiate and init the default LinkageError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.LinkageError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_LinkageError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_LinkageError = error;
  }

  /* instantiate and init the default NoClassDefFoundError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoClassDefFoundError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NoClassDefFoundError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NoClassDefFoundError = error;
  }

  /* instantiate and init the default NoSuchFieldError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchFieldError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NoSuchFieldError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NoSuchFieldError = error;
  }

  /* instantiate and init the default NoSuchMethodError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.NoSuchMethodError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_NoSuchMethodError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_NoSuchMethodError = error;
  }

  /* instantiate and init the default OutOfMemoryError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.OutOfMemoryError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_OutOfMemoryError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_OutOfMemoryError = error;
  }

  /* instantiate and init the default UnsatisfiedLinkError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsatisfiedLinkError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_UnsatisfiedLinkError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_UnsatisfiedLinkError = error;
  }

  /* instantiate and init the default UnsupportedClassVersionError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.UnsupportedClassVersionError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_UnsupportedClassVersionError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_UnsupportedClassVersionError = error;
  }

  /* instantiate and init the default VerifyError instance */
  {
    jobject error;

    if (_svmm_new_native_global (env, error) != JNI_OK)
      {
	return JNI_ERR;
      }

    if (_svmm_new_object_instance
	(env, vm->class_loading.boot_loader.classes.VerifyError, *error) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    if (_svmm_invoke_nonvirtual_VerifyError_init (env, error, NULL) != JNI_OK)
      {
	_svmm_free_native_global (env, error);
	return JNI_ERR;
      }

    vm->class_loading.boot_loader.instances.default_VerifyError = error;
  }

  return JNI_OK;
}
