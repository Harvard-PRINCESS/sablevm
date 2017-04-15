/* This file has been automatically generated from "internal_methods.list" */

/*
----------------------------------------------------------------------
_svmf_initialize_internal_method_tree
----------------------------------------------------------------------
*/

svm_static jint
_svmf_initialize_internal_method_tree (_svmt_JNIEnv *env)
{
  /* pointer to node to insert in the splay tree */
  _svmt_internal_method_node *internal_method_node = NULL;

  assert (env->vm->class_loading.boot_loader.internal_method_tree == NULL);



  /* Put address of Java_java_io_VMObjectStreamClass_hasClassInitializer into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_io_VMObjectStreamClass_hasClassInitializer";
  internal_method_node->code = (void (*)(void)) Java_java_io_VMObjectStreamClass_hasClassInitializer;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_Throwable_nativeGetStackTraceList into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_Throwable_nativeGetStackTraceList";
  internal_method_node->code = (void (*)(void)) Java_java_lang_Throwable_nativeGetStackTraceList;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_isInstance into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_isInstance";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_isInstance;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getModifiers into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getModifiers";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getModifiers;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getDeclaringClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getDeclaringClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getDeclaringClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getDeclaredClasses into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getDeclaredClasses";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getDeclaredClasses;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_isInterface into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_isInterface";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_isInterface;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getSuperclass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getSuperclass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getSuperclass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getInterfaces into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getInterfaces";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getInterfaces;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getDeclaredFields into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getDeclaredFields";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getDeclaredFields;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getDeclaredMethods into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getDeclaredMethods";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getDeclaredMethods;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getDeclaredConstructors into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getDeclaredConstructors";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getDeclaredConstructors;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_isAssignableFrom into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_isAssignableFrom";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_isAssignableFrom;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getClassLoader into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getClassLoader";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getClassLoader;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_getName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_getName";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_getName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_isInitialized into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_isInitialized";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_isInitialized;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_setInitialized into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_setInitialized";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_setInitialized;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_step7 into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_step7";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_step7;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_step8 into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_step8";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_step8;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClass_throwException into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClass_throwException";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClass_throwException;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_nativeGetResource into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_nativeGetResource";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_nativeGetResource;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_newClassLoaderVmData into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_newClassLoaderVmData";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_newClassLoaderVmData;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_getPrimitiveArray into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_getPrimitiveArray";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_getPrimitiveArray;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_getArray into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_getArray";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_getArray;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_nativeDefineArray into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_nativeDefineArray";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_nativeDefineArray;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_nativeDefineClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_nativeDefineClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_nativeDefineClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_linkClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_linkClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_linkClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_initializeClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_initializeClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_initializeClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_nativeLoadClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_nativeLoadClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_nativeLoadClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_nativeCreateArray into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_nativeCreateArray";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_nativeCreateArray;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMClassLoader_getPrimitiveClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMClassLoader_getPrimitiveClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMClassLoader_getPrimitiveClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMObject_notify into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMObject_notify";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMObject_notify;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMObject_notifyAll into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMObject_notifyAll";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMObject_notifyAll;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMObject_wait into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMObject_wait";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMObject_wait;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMObject_clone into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMObject_clone";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMObject_clone;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMObject_getClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMObject_getClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMObject_getClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_availableProcessors into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_availableProcessors";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_availableProcessors;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_freeMemory into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_freeMemory";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_freeMemory;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_totalMemory into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_totalMemory";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_totalMemory;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_maxMemory into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_maxMemory";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_maxMemory;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_gc into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_gc";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_gc;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_runFinalization into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_runFinalization";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_runFinalization;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_runFinalizationForExit into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_runFinalizationForExit";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_runFinalizationForExit;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_traceInstructions into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_traceInstructions";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_traceInstructions;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_traceMethodCalls into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_traceMethodCalls";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_traceMethodCalls;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_runFinalizersOnExit into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_runFinalizersOnExit";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_runFinalizersOnExit;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_exit into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_exit";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_exit;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_nativeLoad into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_nativeLoad";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_nativeLoad;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMRuntime_mapLibraryName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMRuntime_mapLibraryName";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMRuntime_mapLibraryName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMSystem_identityHashCode into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMSystem_identityHashCode";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMSystem_identityHashCode;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMSystem_arraycopy into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMSystem_arraycopy";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMSystem_arraycopy;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_yield into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_yield";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_yield;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_sleep into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_sleep";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_sleep;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_nativeIsAlive into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_nativeIsAlive";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_nativeIsAlive;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_nativeStart into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_nativeStart";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_nativeStart;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_currentThread into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_currentThread";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_currentThread;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_nativeInterrupt into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_nativeInterrupt";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_nativeInterrupt;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_nativeIsInterrupted into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_nativeIsInterrupted";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_nativeIsInterrupted;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_interrupted into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_interrupted";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_interrupted;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_holdsLock into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_holdsLock";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_holdsLock;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_suspend into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_suspend";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_suspend;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VMThread_resume into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VMThread_resume";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VMThread_resume;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_invokeMain into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_invokeMain";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_invokeMain;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__Z into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__Z";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__Z;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__B into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__B";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__B;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__S into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__S";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__S;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__C into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__C";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__C;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__I into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__I";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__I;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__J into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__J";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__J;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__F into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__F";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__F;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__D into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__D";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__D;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_print__Ljava_lang_String_2 into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_print__Ljava_lang_String_2";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_print__Ljava_lang_String_2;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__Z into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__Z";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__Z;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__B into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__B";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__B;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__S into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__S";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__S;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__C into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__C";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__C;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__I into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__I";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__I;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__J into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__J";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__J;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__F into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__F";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__F;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__D into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__D";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__D;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_VirtualMachine_println__Ljava_lang_String_2 into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_VirtualMachine_println__Ljava_lang_String_2";
  internal_method_node->code = (void (*)(void)) Java_java_lang_VirtualMachine_println__Ljava_lang_String_2;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Array_createObjectArray into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Array_createObjectArray";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Array_createObjectArray;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Constructor_nativeGetDeclaringClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Constructor_nativeGetDeclaringClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Constructor_nativeGetDeclaringClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Constructor_nativeGetModifiers into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Constructor_nativeGetModifiers";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Constructor_nativeGetModifiers;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Constructor_nativeGetExceptionTypes into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Constructor_nativeGetExceptionTypes";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Constructor_nativeGetExceptionTypes;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Constructor_constructNative into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Constructor_constructNative";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Constructor_constructNative;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Constructor_nativeGetDescriptor into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Constructor_nativeGetDescriptor";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Constructor_nativeGetDescriptor;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetDeclaringClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetDeclaringClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetDeclaringClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetModifiers into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetModifiers";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetModifiers;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetType into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetType";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetType;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetName";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetReference into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetReference";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetReference;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetBoolean into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetBoolean";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetBoolean;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetByte into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetByte";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetByte;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetChar into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetChar";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetChar;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetShort into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetShort";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetShort;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetInt into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetInt";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetInt;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetLong into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetLong";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetLong;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetFloat into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetFloat";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetFloat;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeGetDouble into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeGetDouble";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeGetDouble;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetReference into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetReference";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetReference;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetBoolean into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetBoolean";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetBoolean;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetByte into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetByte";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetByte;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetChar into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetChar";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetChar;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetShort into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetShort";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetShort;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetInt into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetInt";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetInt;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetLong into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetLong";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetLong;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetFloat into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetFloat";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetFloat;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Field_nativeSetDouble into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Field_nativeSetDouble";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Field_nativeSetDouble;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_nativeGetDeclaringClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_nativeGetDeclaringClass";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_nativeGetDeclaringClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_nativeGetName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_nativeGetName";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_nativeGetName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_nativeGetModifiers into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_nativeGetModifiers";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_nativeGetModifiers;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_nativeGetExceptionTypes into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_nativeGetExceptionTypes";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_nativeGetExceptionTypes;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_invokeNative into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_invokeNative";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_invokeNative;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_java_lang_reflect_Method_nativeGetDescriptor into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_java_lang_reflect_Method_nativeGetDescriptor";
  internal_method_node->code = (void (*)(void)) Java_java_lang_reflect_Method_nativeGetDescriptor;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMStackWalker_getContextSize into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMStackWalker_getContextSize";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMStackWalker_getContextSize;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMStackWalker_fillContext into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMStackWalker_fillContext";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMStackWalker_fillContext;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMStackWalker_fillMethods into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMStackWalker_fillMethods";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMStackWalker_fillMethods;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMStackWalker_getCallingClass into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMStackWalker_getCallingClass";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMStackWalker_getCallingClass;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMStackWalker_getCallingClassLoader into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMStackWalker_getCallingClassLoader";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMStackWalker_getCallingClassLoader;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getSableVMVersion into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getSableVMVersion";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getSableVMVersion;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getOSName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getOSName";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getOSName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getOSArch into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getOSArch";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getOSArch;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getOSVersion into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getOSVersion";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getOSVersion;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getFileSeparator into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getFileSeparator";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getFileSeparator;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getPathSeparator into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getPathSeparator";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getPathSeparator;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getLineSeparator into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getLineSeparator";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getLineSeparator;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getUserName into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getUserName";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getUserName;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getUserHome into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getUserHome";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getUserHome;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getWorkDir into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getWorkDir";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getWorkDir;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_isBigEndian into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_isBigEndian";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_isBigEndian;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getBootstrapLibraryPath;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getBootstrapClassPath;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getJavaHome into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getJavaHome";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getJavaHome;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getPropertyCount into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getPropertyCount";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getPropertyCount;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  /* Put address of Java_gnu_classpath_VMSystemProperties_getProperty into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "Java_gnu_classpath_VMSystemProperties_getProperty";
  internal_method_node->code = (void (*)(void)) Java_gnu_classpath_VMSystemProperties_getProperty;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);


  return JNI_OK;

error:

  return JNI_ERR;
}

