/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*
 * Note: None of the methods that unwraps VMClass instances (to get the
 *       corresponding _svmt_type_info data structure) works with Class
 *       objects for primitive types.  These special classes must be
 *       handled on the Java side as they do not have an associated
 *       _svmt_type_info data structure in the VM.
 *
 */


/*
----------------------------------------------------------------------
Java_java_lang_VMClass_isInstance
----------------------------------------------------------------------
*/


/*
 * Class:     java_lang_VMClass
 * Method:    isInstance
 * Signature: (Ljava/lang/Class;Ljava/lang/Object;)Z
 */

JNIEXPORT static jboolean JNICALL
Java_java_lang_VMClass_isInstance (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				   jclass theclass, jobject obj)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *T = _svmf_unwrap_class_instance (env, theclass);
    _svmt_type_info *S = (*obj)->vtable->type;

    result = _svmf_is_assignable_from (env, S, T);
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getModifiers
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getModifiers
 * Signature: (Ljava/lang/Class;)I
 */

JNIEXPORT static jint JNICALL
Java_java_lang_VMClass_getModifiers (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				     jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jint result;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    /* make sure not to return any internal flags */
    result = type->access_flags &
      (SVM_ACC_PUBLIC |
       SVM_ACC_FINAL | SVM_ACC_SUPER | SVM_ACC_INTERFACE | SVM_ACC_ABSTRACT);
  }

  _svmm_stopping_java (env);

  return result;
}


/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getDeclaringClass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaringClass
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClass_getDeclaringClass (JNIEnv *_env,
					  jclass vmclass SVM_UNUSED,
					  jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass class = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    if (!type->is_array)
      {
	_svmt_class_info *class_info = _svmf_cast_class (type);
	jint i;

	for (i = 0; i < class_info->attributes_count; i++)
	  {
	    _svmt_attribute_info *attribute;
	    attribute = class_info->attributes[i];
	    if (strcmp (DREF (attribute->name, value), "InnerClasses") == 0)
	      {
		_svmt_InnerClasses_attribute *inner_attribute;
		jint j;

		inner_attribute =
		  _svmf_cast_InnerClasses_attribute (attribute);

		for (j = 0; j < inner_attribute->number_of_classes; j++)
		  {
		    _svmt_inner_classes *inner_classes;
		    _svmt_CONSTANT_Class_info *inner_class_info;
		    _svmt_CONSTANT_Class_info *outer_class_info;

		    inner_classes = &inner_attribute->classes[j];

		    inner_class_info = *(inner_classes->inner_class_info);

		    /*
		     * Do we need to resolve the inner class?
		     *
		     */
		    if (_svmf_resolve_CONSTANT_Class
			(env, class_info, inner_class_info) != JNI_OK)
		      {
			goto end;
		      }

		    if (_svmf_cast_class (inner_class_info->type) ==
			class_info)
		      {
			/* resolve outer_class_info */
			outer_class_info = *(inner_classes->outer_class_info);

			if (_svmf_resolve_CONSTANT_Class
			    (env, class_info, outer_class_info) != JNI_OK)
			  {
			    goto end;
			  }
			class = _svmf_get_jni_frame_native_local (env);
			*class = *(outer_class_info->type->class_instance);
			break;
		      }
		  }

		break;
	      }
	  }

      }

  }
end:

  _svmm_stopping_java (env);

  return class;
}


/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getDeclaredClasses
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredClasses
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/Class;
 */

JNIEXPORT static jobjectArray JNICALL
Java_java_lang_VMClass_getDeclaredClasses (JNIEnv *_env,
					   jclass vmclass SVM_UNUSED,
					   jclass theclass,
					   jboolean publicOnly)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobjectArray classes = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    if (!type->is_array)
      {
	_svmt_class_info *class_info = _svmf_cast_class (type);
	jint i;

	for (i = 0; i < class_info->attributes_count; i++)
	  {
	    _svmt_attribute_info *attribute;
	    attribute = class_info->attributes[i];
	    if (strcmp (DREF (attribute->name, value), "InnerClasses") == 0)
	      {
		_svmt_InnerClasses_attribute *inner_attribute;
		jint count = 0;
		jint j;

		inner_attribute =
		  _svmf_cast_InnerClasses_attribute (attribute);

		/* Count the number of inner classes */
		for (j = 0; j < inner_attribute->number_of_classes; j++)
		  {
		    _svmt_inner_classes *inner_classes;
		    _svmt_CONSTANT_Class_info *outer_class_info;

		    inner_classes = &inner_attribute->classes[j];

		    outer_class_info = *(inner_classes->outer_class_info);

		    /*
		     * Do we need to resolve it?
		     *
		     */
		    if (_svmf_resolve_CONSTANT_Class
			(env, class_info, outer_class_info) != JNI_OK)
		      {
			goto end;
		      }

		    if (_svmf_cast_class (outer_class_info->type) ==
			class_info)
		      {

			if (publicOnly)
			  {
			    if (_svmf_is_set_flag
				(inner_classes->inner_class_access_flags,
				 SVM_ACC_PUBLIC))
			      {
				count++;
			      }
			  }
			else
			  {
			    count++;
			  }
		      }
		  }


		/* create array */
		{
		  _svmt_class_info *class_class_info;
		  _svmt_array_info *class_array_info = NULL;

		  class_class_info =
		    vm->class_loading.boot_loader.classes.jlclass;

		  /* creates type Class[] */
		  if (_svmm_create_array
		      (env,
		       class_class_info->class_loader_info,
		       class_class_info->array_type_name,
		       class_array_info) != JNI_OK)
		    {
		      goto end;
		    }

		  /* link the type Class[] */
		  if (_svmf_link_array (env, class_array_info) != JNI_OK)
		    {
		      goto end;
		    }


		  classes = _svmf_get_jni_frame_native_local_array (env);
		  if (_svmm_new_array_instance (env,
						class_array_info,
						count, *classes) != JNI_OK)
		    {
		      goto end;
		    }

		}


		/* fill in array */
		count = 0;
		for (j = 0; j < inner_attribute->number_of_classes; j++)
		  {
		    _svmt_inner_classes *inner_classes;
		    _svmt_CONSTANT_Class_info *inner_class_info;
		    _svmt_CONSTANT_Class_info *outer_class_info;

		    inner_classes = &inner_attribute->classes[j];

		    outer_class_info = *(inner_classes->outer_class_info);

		    if (_svmf_cast_class (outer_class_info->type) ==
			class_info)
		      {

			if (publicOnly)
			  {
			    if (!_svmf_is_set_flag
				(inner_classes->inner_class_access_flags,
				 SVM_ACC_PUBLIC))
			      {
				/* skip non public inner classes */
				continue;
			      }
			  }

			inner_class_info = *(inner_classes->inner_class_info);

			if (_svmf_resolve_CONSTANT_Class
			    (env, class_info, inner_class_info) != JNI_OK)
			  {
			    goto end;
			  }

			/* add to array */
			if (_svmf_set_reference_array_element_no_exception
			    (env, *classes, count++,
			     *(inner_class_info->type->class_instance)) !=
			    JNI_OK)
			  {
			    goto end;
			  }

		      }
		  }


		break;
	      }
	  }
      }

  }
end:

  _svmm_stopping_java (env);

  return classes;
}



/*
----------------------------------------------------------------------
Java_java_lang_VMClass_isInterface
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    isInterface
 * Signature: (Ljava/lang/Class;)Z
 */

JNIEXPORT static jboolean JNICALL
Java_java_lang_VMClass_isInterface (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				    jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    if (!(type->is_array) &&
	_svmf_is_set_flag (type->access_flags, SVM_ACC_INTERFACE))
      {
	result = JNI_TRUE;
      }
    else
      {
	result = JNI_FALSE;
      }
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getSuperclass
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getSuperclass
 * Signature: (Ljava/lang/Class;)Ljava/lang/Class;
 */

JNIEXPORT static jclass JNICALL
Java_java_lang_VMClass_getSuperclass (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				      jclass theclass)
{

  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jclass super = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    if (type->is_array)
      {
	super = _svmf_get_jni_frame_native_local (env);
	*super =
	  *(vm->class_loading.boot_loader.classes.jlobject->class_instance);
	goto end;
      }
    if (_svmf_is_set_flag (type->access_flags, SVM_ACC_INTERFACE))
      {
	goto end;
      }

    /* has super type */
    {
      _svmt_CONSTANT_Class_info *super_class;
      super_class = *(_svmf_cast_class (type)->super_class);
      if (super_class == NULL)
	{
	  goto end;
	}
      else
	{
	  super = _svmf_get_jni_frame_native_local (env);
	  *super = *(super_class->type->class_instance);
	}
    }

  }

end:
  _svmm_stopping_java (env);

  return super;
}


/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getInterfaces
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getInterfaces
 * Signature: (Ljava/lang/Class;)[Ljava/lang/Class;
 */

JNIEXPORT static jobjectArray JNICALL
Java_java_lang_VMClass_getInterfaces (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				      jclass theclass)
{

  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobjectArray interfaces_array = NULL;	/* The result. */

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;

    /* The type Class[] */
    static _svmt_array_info *class_array_info = NULL;

    {
      /* Load/link/init type Class[] if necessary. */

      if (class_array_info == NULL)
	{
	  _svmt_class_info *class_class_info;

	  class_class_info = vm->class_loading.boot_loader.classes.jlclass;

	  /* creates type Class[] */
	  if (_svmm_create_array
	      (env,
	       class_class_info->class_loader_info,
	       class_class_info->array_type_name, class_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	  /* link the type Class[] */
	  if (_svmf_link_array (env, class_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	}
    }


    {
      /* Create the Class[] to hold the result. */
      _svmt_CONSTANT_Class_info ***interfaces;
      int nbinterfaces;
      int i;
      _svmt_type_info *type;
      _svmt_class_info *class_info;

      type = _svmf_unwrap_class_instance (env, theclass);
      class_info = _svmf_cast_class (type);


      /* Create the array Class[] */
      nbinterfaces = class_info->interfaces_count;
      /* may need global lock to get native ref? */
      interfaces_array = _svmf_get_jni_frame_native_local_array (env);
      if (_svmm_new_array_instance (env,
				    class_array_info,
				    nbinterfaces,
				    *interfaces_array) != JNI_OK)
	{
	  goto end;
	}

      /* Fill in the array */
      interfaces = class_info->interfaces;
      for (i = 0; i < nbinterfaces; i++)
	{
	  _svmt_type_info *interface_type;
	  jclass interface;

	  interface_type = (*interfaces[i])->type;
	  interface = interface_type->class_instance;

	  /* add to array */
	  if (_svmf_set_reference_array_element_no_exception
	      (env, *interfaces_array, i, *interface) != JNI_OK)
	    {
	      _svmm_release_jni_frame_native_local_array (interfaces_array);
	      goto end;
	    }
	}
    }

  }

end:
  _svmm_stopping_java (env);

  return interfaces_array;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getDeclaredFields
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredFields
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Field;
 */

JNIEXPORT static jobjectArray JNICALL
Java_java_lang_VMClass_getDeclaredFields (JNIEnv *_env,
					  jclass vmclass SVM_UNUSED,
					  jclass theclass,
					  jboolean public_only)
{
  /* pointer to current environment (or thread-specific) structure; */
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  /* array reference that contains the return value */
  jobjectArray fields_array = NULL;

  /* disable concurrent garbage collection, stopping the world if
     garbage collection is in progress */
  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;
    jboolean monitor_acquired = JNI_FALSE;

    /* The type Field */
    _svmt_class_info *field_class_info;

    /* The type Field[] */
    _svmt_array_info *field_array_info;

    /* The class we are looking at. */
    _svmt_class_info *class_info;

    /* get classes loaded and linked at bootstrap */
    field_class_info = vm->class_loading.boot_loader.classes.jlrfield;
    field_array_info = vm->class_loading.boot_loader.classes.jlrfield_array;

    /* unwrap the pointer to the _svmt_class_info of the class which
       declares the fields we want to retrieve */
    class_info =
      _svmf_cast_class (_svmf_unwrap_class_instance (env, theclass));

    /* a class must have been prepared before a Class instance is
       associated with it.  Assert that this is true here, in debug
       mode, to detect bugs in the VM. */
    assert (_svmf_is_set_flag (class_info->state, SVM_TYPE_STATE_PREPARED));

    /* we have to protect against concurrent creation of
       java.lang.reflect.Field instances for the same fields of a
       class on multiple threads */
    assert (*(class_info->class_instance) == *(theclass));
    if (_svmf_enter_object_monitor (env, *(theclass)) != JNI_OK)
      {
	goto end;
      }

    monitor_acquired = JNI_TRUE;

    {
      jint i;
      _svmt_field_info *fields = class_info->fields;

      /* create array of correct size */
      {
	jint fields_count = 0;

	if (public_only)
	  {
	    /* need to count them first */
	    for (i = 0; i < class_info->fields_count; i++)
	      {
		_svmt_field_info *field;
		field = &fields[i];
		if (_svmf_is_set_flag (field->access_flags, SVM_ACC_PUBLIC))
		  {
		    fields_count++;
		  }
	      }
	  }
	else
	  {
	    fields_count = class_info->fields_count;
	  }


	/* as this reference will be returned to the JNI caller
	   function, _svmf_get_jni_frame_native_local_array must be
	   used to obtain a JNI local reference from the current JNI
	   local reference frame.  */
	fields_array = _svmf_get_jni_frame_native_local_array (env);

	/* create the Field[] array of the appropriate size */
	if (_svmm_new_array_instance
	    (env, field_array_info, fields_count, *fields_array) != JNI_OK)
	  {
	    goto end;
	  }
      }

      {
	jint array_index = 0;

	for (i = 0; i < class_info->fields_count; i++)
	  {
	    _svmt_field_info *field_info;
	    jobject fieldObject;

	    field_info = &fields[i];

	    if (public_only)
	      {
		if (!_svmf_is_set_flag
		    (field_info->access_flags, SVM_ACC_PUBLIC))
		  {
		    continue;
		  }
	      }

	    /* Create a Field object, if none already exists for this
	       field.  The monitor above was acquired specifically to
	       prevent this code from executing concurrently on two
	       thread.  We want to avoid creating more than one Field
	       instance for this field (which could happen if we did
	       not use synchronization). */
	    if (field_info->reflection_instance == NULL)
	      {
		jbyteArray wrapper;

		/* Wrap the pointer to this _svmt_field_info into a
		   byte array, and store the pointer to that array
		   into a local reference.

		   A local reference is a reference which holds a
		   "pointer" to an object which can be moved by the
		   garbage collector.  Note that garbage collection
		   can obviously happen during the call to
		   _svmm_new_object_instance() below.  As the garbage
		   collector can move objects around, the use of a
		   local reference is necessary so that the code that
		   follows the call still refers to the (possibly
		   moved) wrapper array.

		   The difference between local and a global
		   references is that local references are obtained
		   and released without any synchronization.  This
		   has 2 consequences:

		   (a) it is faster, but 

		   (b) it is unsafe to share local references with
		   other threads.

		   A local reference is usually used by the VM to
		   temporarily store an object references in it.
		   Unlike a JNI reference returned to the caller
		   function, a local reference must be freed by the
		   VM before the end of the current function. */
		if (_svmm_local_wrap_pointer (env, field_info, wrapper) !=
		    JNI_OK)
		  {
		    _svmm_release_jni_frame_native_local_array (fields_array);
		    goto end;
		  }

		if (_svmm_new_native_local (env, fieldObject) != JNI_OK)
		  {
		    _svmm_free_native_local_array (env, wrapper);
		    _svmm_release_jni_frame_native_local_array (fields_array);
		    goto end;
		  }

		/* create the Field instance */
		if (_svmm_new_object_instance
		    (env,
		     vm->class_loading.boot_loader.classes.jlrfield,
		     *fieldObject) != JNI_OK)
		  {
		    _svmm_free_native_local (env, fieldObject);
		    _svmm_free_native_local_array (env, wrapper);
		    _svmm_release_jni_frame_native_local_array (fields_array);
		    goto end;
		  }

		/* call the constructor of the Field instance */
		if (_svmm_invoke_nonvirtual_jlrfield_init
		    (env, fieldObject,
		     _svmf_cast_jobject (wrapper)) != JNI_OK)
		  {
		    _svmm_free_native_local (env, fieldObject);
		    _svmm_free_native_local_array (env, wrapper);
		    _svmm_release_jni_frame_native_local_array (fields_array);
		    goto end;
		  }

		/* create a global reference to permanently store a
		   pointer to the newly created Field instance in the
		   _svmt_field_info structure. */

		if (_svmm_new_native_global
		    (env, field_info->reflection_instance) != JNI_OK)
		  {
		    _svmm_free_native_local (env, fieldObject);
		    _svmm_free_native_local_array (env, wrapper);
		    _svmm_release_jni_frame_native_local_array (fields_array);
		    goto end;
		  }

		/* Store the Field reference. */
		*(field_info->reflection_instance) = *fieldObject;

		/* release local native refs, now that we're done with
		   them.  Actually, we're in a loop, so if we don't do
		   it, we will leak native references. */
		_svmm_free_native_local (env, fieldObject);
		_svmm_free_native_local_array (env, wrapper);
	      }

	    /* Copy the permanently stored the reference into the
	       Field[] array. */
	    if (_svmf_set_reference_array_element_no_exception
		(env, *fields_array, array_index++,
		 *(field_info->reflection_instance)) != JNI_OK)
	      {
		_svmm_fatal_error ("impossible control flow");
	      }
	  }
      }
    }

  end:
    if (monitor_acquired)
      {
	monitor_acquired = JNI_FALSE;

	if (_svmf_exit_object_monitor (env, *(theclass)) != JNI_OK)
	  {
	    goto end;
	  }
      }
  }

  /* returning to foreing JNI code.  As we don't know when this code
     will call back (or return to) the VM, we must enable concurrent
     garbage collection.  */
  _svmm_stopping_java (env);

  return fields_array;
}


/*
 * Common code to both getDeclaredMethods and getDeclaredConstructors
 * on the native side.
 *
 * methodFlag - specifies whether want want the regular methods or the
 *              constructors.
 *    JNI_TRUE  - return methods (excluding constructors)
 *    JNI_FALSE - return constructors
 *
 */

static jobjectArray
getDeclaredMethodsConstructors_helper (_svmt_JNIEnv *env, jclass theclass,
				       jboolean publicOnly,
				       jboolean methodFlag)
{
  jobjectArray methods_array = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_JavaVM *vm = env->vm;


    /* The type Method[] */
    static _svmt_array_info *method_array_info = NULL;
    /* The type Constructor[] */
    static _svmt_array_info *constructor_array_info = NULL;

    /* A Class for type Method or Constructor */
    _svmt_class_info *mc_class_info;
    /* A Method[] or Constructor[] array_info */
    _svmt_array_info *mc_array_info = NULL;

    jboolean monitor_acquired = JNI_FALSE;

    if (_svmf_enter_object_monitor (env, *(theclass)) != JNI_OK)
      {
	goto end;
      }

    monitor_acquired = JNI_TRUE;

    {
      /* Load/link/init type Method[] (or Constructor[]) if necessary. */

      mc_array_info = methodFlag ? method_array_info : constructor_array_info;

      if (mc_array_info == NULL)
	{
	  mc_class_info = methodFlag ?
	    vm->class_loading.boot_loader.classes.jlrmethod :
	    vm->class_loading.boot_loader.classes.jlrconstructor;

	  /* creates type Method[] or Constructor[] */
	  if (_svmm_create_array
	      (env,
	       mc_class_info->class_loader_info,
	       mc_class_info->array_type_name, mc_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	  /* link the type Method[] or Constructor[] */
	  if (_svmf_link_array (env, mc_array_info) != JNI_OK)
	    {
	      goto end;
	    }

	  /* Cache resulting type. */
	  if (methodFlag)
	    {
	      method_array_info = mc_array_info;
	    }
	  else
	    {
	      constructor_array_info = mc_array_info;
	    }
	}
    }

    {
      /* Create a Method[] or Constructor[] to hold the result. */
      _svmt_type_info *type;
      _svmt_class_info *class_info;
      int nb_declared_methods;
      char *name;
      jint i;
      _svmt_method_info *method_info;
      _svmt_method_info *methods;
      int methods_count;

      type = _svmf_unwrap_class_instance (env, theclass);
      class_info = _svmf_cast_class (type);

      /* Need to link class - to fill in method_info */
      if (_svmf_link_class (env, class_info) != JNI_OK)
	{
	  goto end;
	}

      /* Count the number of method/constructors */
      methods = class_info->methods;
      methods_count = class_info->methods_count;
      nb_declared_methods = 0;
      for (i = 0; i < methods_count; i++)
	{
	  method_info = &methods[i];

	  if (publicOnly)
	    {
	      if ((method_info->access_flags & SVM_ACC_PUBLIC) == 0)
		{
		  /* skip non-public method */
		  continue;
		}
	    }

	  name = (*(method_info->name))->value;
	  /*        printf("name: %s\n", name); */
	  if (strcmp (name, "<clinit>") == 0)
	    {
	      continue;
	    }
	  else if (methodFlag && !(strcmp (name, "<init>") == 0))
	    {
	      nb_declared_methods++;
	    }
	  else if (!methodFlag && (strcmp (name, "<init>") == 0))
	    {
	      nb_declared_methods++;
	    }
	}

      /* Create the array */
      methods_array = _svmf_get_jni_frame_native_local_array (env);
      if (_svmm_new_array_instance
	  (env, mc_array_info, nb_declared_methods, *methods_array) != JNI_OK)
	{
	  goto end;
	}


      {
	/* Fill the array */
	jint index;

	index = 0;
	for (i = 0; i < methods_count; i++)
	  {
	    jobject method;

	    method_info = &methods[i];


	    if (publicOnly)
	      {
		if ((method_info->access_flags & SVM_ACC_PUBLIC) == 0)
		  {
		    /* skip non-public methods */
		    continue;
		  }
	      }


	    /*      printf("name: %s\n", name); */

	    /* skip what we are not counting */
	    name = (*(method_info->name))->value;
	    if (strcmp (name, "<clinit>") == 0)
	      {
		/* always skip static initializer */
		continue;
	      }
	    else if (methodFlag && (strcmp (name, "<init>") == 0))
	      {
		/* want methods, skip constructor */
		continue;
	      }
	    else if (!methodFlag && !(strcmp (name, "<init>") == 0))
	      {
		/* want constructors, skip regular methods */
		continue;
	      }
	    /*
	     * Create a Method/Constructor object for the method/constructor
	     * if needed.
	     */
	    if (method_info->reflection_instance == NULL)
	      {
		jbyteArray wrapper;

		/* wrap it */
		wrapper = _svmf_get_jni_frame_native_local_array (env);
		if (_svmm_local_wrap_pointer (env, method_info, wrapper) !=
		    JNI_OK)
		  {
		    goto end;
		  }

		method = _svmf_get_jni_frame_native_local (env);
		if (_svmm_new_object_instance
		    (env,
		     methodFlag ?
		     vm->class_loading.boot_loader.classes.jlrmethod
		     :
		     vm->class_loading.boot_loader.classes.jlrconstructor,
		     *method) != JNI_OK)
		  {
		    goto end;
		  }

		/* fprintf(stderr, "*method = %x\n", *((unsigned int *) method)); */

		if (methodFlag)
		  {
		    if (_svmm_invoke_nonvirtual_jlrmethod_init
			(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
		      {
			goto end;
		      }
		  }
		else
		  {
		    if (_svmm_invoke_nonvirtual_jlrconstructor_init
			(env, method, _svmf_cast_jobject (wrapper)) != JNI_OK)
		      {
			goto end;
		      }
		  }

		if (_svmm_new_native_global
		    (env, method_info->reflection_instance) != JNI_OK)
		  {
		    goto end;
		  }

		/* Cache the resulting object */
		*(method_info->reflection_instance) = *method;

		/* release native refs */
		_svmm_release_jni_frame_native_local (method);
		_svmm_release_jni_frame_native_local_array (wrapper);

	      }

	    /* add to array */
	    if (_svmf_set_reference_array_element_no_exception
		(env, *methods_array, index++,
		 *(method_info->reflection_instance)) != JNI_OK)
	      {
		goto end;
	      }
	  }
      }
    }


  end:
    if (monitor_acquired)
      {
	monitor_acquired = JNI_FALSE;

	if (_svmf_exit_object_monitor (env, *(theclass)) != JNI_OK)
	  {
	    goto end;
	  }
      }
  }


  _svmm_stopping_java (env);
  return methods_array;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getDeclaredMethods
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredMethods
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Method;
 */

JNIEXPORT static jobjectArray JNICALL
Java_java_lang_VMClass_getDeclaredMethods (JNIEnv *_env,
					   jclass vmclass SVM_UNUSED,
					   jclass theclass,
					   jboolean publicOnly)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  return getDeclaredMethodsConstructors_helper (env, theclass, publicOnly,
						JNI_TRUE);
}



/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getDeclaredConstructors
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getDeclaredConstructors
 * Signature: (Ljava/lang/Class;Z)[Ljava/lang/reflect/Constructor;
 */

JNIEXPORT static jobjectArray JNICALL
Java_java_lang_VMClass_getDeclaredConstructors (JNIEnv *_env,
						jclass vmclass SVM_UNUSED,
						jclass theclass,
						jboolean publicOnly)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  return getDeclaredMethodsConstructors_helper (env, theclass, publicOnly,
						JNI_FALSE);
}



/*
----------------------------------------------------------------------
Java_java_lang_VMClass_isAssignableFrom
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    isAssignableFrom
 * Signature: (Ljava/lang/Class;Ljava/lang/Class;)Z
 */

JNIEXPORT static jboolean JNICALL
Java_java_lang_VMClass_isAssignableFrom (JNIEnv *_env,
					 jclass vmclass SVM_UNUSED,
					 jclass theclass, jclass c)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean is_assignable;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *to = _svmf_unwrap_class_instance (env, theclass);
    _svmt_type_info *from = _svmf_unwrap_class_instance (env, c);

    is_assignable = _svmf_is_assignable_from (env, from, to);
  }

  _svmm_stopping_java (env);

  return is_assignable;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getClassLoader
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getClassLoader
 * Signature: (Ljava/lang/Class;)Ljava/lang/ClassLoader;
 */

JNIEXPORT static jobject JNICALL
Java_java_lang_VMClass_getClassLoader (JNIEnv *_env,
				       jclass vmclass SVM_UNUSED,
				       jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jobject class_loader = NULL;

  _svmm_resuming_java (env);

  {
    _svmt_type_info *type = _svmf_unwrap_class_instance (env, theclass);

    if (type->class_loader_info->class_loader != NULL)
      {
	class_loader = _svmf_get_jni_frame_native_local (env);
	*class_loader = *(type->class_loader_info->class_loader);
      }
  }

  _svmm_stopping_java (env);

  return class_loader;
}


/*
----------------------------------------------------------------------
Java_java_lang_VMClass_getName
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    getName
 * Signature: (Ljava/lang/Class;)Ljava/lang/String;
 */

JNIEXPORT static jstring JNICALL
Java_java_lang_VMClass_getName (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jstring name;

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      (_svmt_class_info *) _svmf_unwrap_class_instance (env, theclass);

    name = _svmf_get_jni_frame_native_local (env);
    _svmf_get_string (env, class->name, name);
  }

  _svmm_stopping_java (env);

  return name;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_isInitialized
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    isInitialized
 * Signature: (Ljava/lang/Class;)Z
 */

JNIEXPORT static jboolean JNICALL
Java_java_lang_VMClass_isInitialized (JNIEnv *_env, jclass vmclass SVM_UNUSED,
				      jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);
  jboolean result;

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      (_svmt_class_info *) _svmf_unwrap_class_instance (env, theclass);

    result =
      _svmf_is_set_flag (class->state,
			 SVM_TYPE_STATE_INITIALIZED) ? JNI_TRUE : JNI_FALSE;
  }

  _svmm_stopping_java (env);

  return result;
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_setInitialized
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    setInitialized
 * Signature: (Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMClass_setInitialized (JNIEnv *_env,
				       jclass vmclass SVM_UNUSED,
				       jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      (_svmt_class_info *) _svmf_unwrap_class_instance (env, theclass);

    _svmm_set_flag (class->state, SVM_TYPE_STATE_INITIALIZED);
  }

  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_step7
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    step7
 * Signature: (Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMClass_step7 (JNIEnv *_env, jclass vmclass SVM_UNUSED,
			      jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      (_svmt_class_info *) _svmf_unwrap_class_instance (env, theclass);

    /* if not interface, initialize super class */
    if (!_svmf_is_interface (class))
      {
	if (CAN_DREF (class->super_class))
	  {
	    _svmt_class_info *super_class =
	      _svmf_cast_class (DREF (class->super_class, type));

	    if (_svmf_class_initialization (env, super_class) != JNI_OK)
	      {
		goto end;
	      }
	  }
      }
  }

end:
  _svmm_stopping_java (env);
}

/*
----------------------------------------------------------------------
Java_java_lang_VMClass_step8
----------------------------------------------------------------------
*/

/*
 * Class:     java_lang_VMClass
 * Method:    step8
 * Signature: (Ljava/lang/Class;)V
 */

JNIEXPORT static void JNICALL
Java_java_lang_VMClass_step8 (JNIEnv *_env, jclass vmclass SVM_UNUSED,
			      jclass theclass)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    _svmt_class_info *class =
      (_svmt_class_info *) _svmf_unwrap_class_instance (env, theclass);
    _svmt_method_info *clinit;

    /* initialize constant fields */
    if (_svmf_initialize_fields (env, class) != JNI_OK)
      {
	goto end;
      }

    /* invoke <clinit>, if it exists */
    clinit = _svmf_resolve_method (class, "<clinit>", "()V");

    if (clinit != NULL)
      {
	if (_svmm_invoke_specific_static_clinit (env, clinit) != JNI_OK)
	  {
	    goto end;
	  }
      }
  }

end:
  _svmm_stopping_java (env);
}


JNIEXPORT static void JNICALL
Java_java_lang_VMClass_throwException (JNIEnv *_env, jclass _class SVM_UNUSED,
				       jthrowable exception)
{
  _svmt_JNIEnv *env = _svmf_cast_svmt_JNIEnv (_env);

  _svmm_resuming_java (env);

  {
    *(env->throwable) = *exception;
  }

  _svmm_stopping_java (env);
}
