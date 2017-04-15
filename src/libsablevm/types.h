/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_SABLEVM_H
#define SVM_SABLEVM_H

/* This file is really at the heart of SableVM.  It defines the data
   structures used in SableVM.  When looking at the VM for a first
   time, you should spend some time reading this file.
*/

/* *INDENT-OFF* */

typedef struct _svmt_CONSTANT_Class_info_struct _svmt_CONSTANT_Class_info;
typedef struct _svmt_CONSTANT_Double_info_struct _svmt_CONSTANT_Double_info;
typedef struct _svmt_CONSTANT_Fieldref_info_struct _svmt_CONSTANT_Fieldref_info;
typedef struct _svmt_CONSTANT_Float_info_struct _svmt_CONSTANT_Float_info;
typedef struct _svmt_CONSTANT_Integer_info_struct _svmt_CONSTANT_Integer_info;
typedef struct _svmt_CONSTANT_InterfaceMethodref_info_struct _svmt_CONSTANT_InterfaceMethodref_info;
typedef struct _svmt_CONSTANT_Long_info_struct _svmt_CONSTANT_Long_info;
typedef struct _svmt_CONSTANT_Methodref_info_struct _svmt_CONSTANT_Methodref_info;
typedef struct _svmt_CONSTANT_NameAndType_info_struct _svmt_CONSTANT_NameAndType_info;
typedef struct _svmt_CONSTANT_String_info_struct _svmt_CONSTANT_String_info;
typedef struct _svmt_CONSTANT_Utf8_info_struct _svmt_CONSTANT_Utf8_info;
typedef struct _svmt_Code_attribute_struct _svmt_Code_attribute;
typedef struct _svmt_ConstantValue_attribute_struct _svmt_ConstantValue_attribute;
typedef struct _svmt_Deprecated_attribute_struct _svmt_Deprecated_attribute;
typedef struct _svmt_Exceptions_attribute_struct _svmt_Exceptions_attribute;
typedef struct _svmt_InnerClasses_attribute_struct _svmt_InnerClasses_attribute;
typedef struct _svmt_JNIEnv_struct _svmt_JNIEnv;
typedef struct _svmt_JavaVM_struct _svmt_JavaVM;
typedef struct _svmt_LineNumberTable_attribute_struct _svmt_LineNumberTable_attribute;
typedef struct _svmt_LocalVariableTable_attribute_struct _svmt_LocalVariableTable_attribute;
typedef struct _svmt_SourceFile_attribute_struct _svmt_SourceFile_attribute;
typedef struct _svmt_Synthetic_attribute_struct _svmt_Synthetic_attribute;
typedef struct _svmt_arg_preparation_struct _svmt_arg_preparation;
typedef struct _svmt_array_info_struct _svmt_array_info;
typedef struct _svmt_array_instance_struct _svmt_array_instance;
typedef struct _svmt_attribute_info_struct _svmt_attribute_info;
typedef struct _svmt_zip_file_struct _svmt_zip_file;
typedef struct _svmt_zip_file_entry_struct _svmt_zip_file_entry;
typedef struct _svmt_boot_class_path_entry_struct _svmt_boot_class_path_entry;
typedef struct _svmt_bootstrap_classloader_struct _svmt_bootstrap_classloader;
typedef struct _svmt_branch_preparation_struct _svmt_branch_preparation;
typedef struct _svmt_bytecode_info_struct _svmt_bytecode_info;
typedef struct _svmt_class_field_data_struct _svmt_class_field_data;
typedef struct _svmt_class_file_struct _svmt_class_file;
typedef struct _svmt_class_info_struct _svmt_class_info;
typedef struct _svmt_class_loader_info_struct _svmt_class_loader_info;
typedef struct _svmt_class_loading_struct _svmt_class_loading;
typedef struct _svmt_classes_struct _svmt_classes;
typedef struct _svmt_cp_info_struct _svmt_cp_info;
typedef struct _svmt_exception_table_struct _svmt_exception_table;
typedef struct _svmt_fat_lock_struct _svmt_fat_lock;
typedef struct _svmt_fat_locks_struct _svmt_fat_locks;
typedef struct _svmt_field_info_struct _svmt_field_info;
typedef struct _svmt_fieldref_preparation_struct _svmt_fieldref_preparation;
typedef struct _svmt_fields_struct _svmt_fields;
typedef struct _svmt_free_block_struct _svmt_free_block;
typedef struct _svmt_gc_map_node_struct _svmt_gc_map_node;
typedef struct _svmt_heap_struct _svmt_heap;
typedef struct _svmt_imethodref_preparation_struct _svmt_imethodref_preparation;
typedef struct _svmt_initialization_struct _svmt_initialization;
typedef struct _svmt_inner_classes_struct _svmt_inner_classes;
typedef struct _svmt_instance_field_data_struct _svmt_instance_field_data;
typedef struct _svmt_instanceof_info_struct _svmt_instanceof_info;
typedef struct _svmt_instances_struct _svmt_instances;
typedef struct _svmt_instruction_info_struct _svmt_instruction_info;
typedef struct _svmt_instruction_preparation_struct _svmt_instruction_preparation;
typedef struct _svmt_interface_class_data_struct _svmt_interface_class_data;
typedef struct _svmt_imethod_signature_node_struct _svmt_imethod_signature_node;
typedef struct _svmt_internal_method_node_struct _svmt_internal_method_node;
typedef struct _svmt_ldc_preparation_struct _svmt_ldc_preparation;
typedef struct _svmt_line_number_table_struct _svmt_line_number_table;
typedef struct _svmt_local_preparation_struct _svmt_local_preparation;
typedef struct _svmt_local_split_struct _svmt_local_split;
typedef struct _svmt_local_variable_table_struct _svmt_local_variable_table;
typedef struct _svmt_memory_block_struct _svmt_memory_block;
typedef struct _svmt_method_frame_info_struct _svmt_method_frame_info;
typedef struct _svmt_method_info_struct _svmt_method_info;
typedef struct _svmt_method_preparation_struct _svmt_method_preparation;
typedef struct _svmt_methodref_preparation_struct _svmt_methodref_preparation;
typedef struct _svmt_methods_struct _svmt_methods;
typedef struct _svmt_native_globals_struct _svmt_native_globals;
typedef struct _svmt_native_library_struct _svmt_native_library;
typedef struct _svmt_native_locals_struct _svmt_native_locals;
typedef struct _svmt_native_method_data_struct _svmt_native_method_data;
typedef struct _svmt_native_ref_struct _svmt_native_ref;
typedef struct _svmt_noninterface_class_data_struct _svmt_noninterface_class_data;
typedef struct _svmt_object_instance_struct _svmt_object_instance;
typedef struct _svmt_sequence_node_struct _svmt_sequence_node;
typedef struct _svmt_stack_and_local_map_struct _svmt_stack_and_local_map;
typedef struct _svmt_stack_frame_struct _svmt_stack_frame;
typedef struct _svmt_stack_struct _svmt_stack;
typedef struct _svmt_system_properties_struct _svmt_system_properties;
typedef struct _svmt_thread_struct _svmt_thread;
typedef struct _svmt_threads_struct _svmt_threads;
typedef struct _svmt_type_info_struct _svmt_type_info;
typedef struct _svmt_type_node_struct _svmt_type_node;
typedef struct _svmt_unknown_attribute_struct _svmt_unknown_attribute;
typedef struct _svmt_vtable_struct _svmt_vtable;
typedef union _svmt_code_union _svmt_code;
typedef union _svmt_stack_native_reference_union _svmt_stack_native_reference;
typedef union _svmt_stack_value_union _svmt_stack_value;

#ifdef _SABLEVM_INLINABILITY_TESTING
typedef struct _svmt_inlinability_testing_struct _svmt_inlinability_testing;
#endif

/* *INDENT-ON* */

/*
----------------------------------------------------------------------
_svmt_thread
----------------------------------------------------------------------
*/

struct _svmt_thread_struct
{
  pthread_t pthread;
  jint id;
  _svmt_word thinlock_id;
  jboolean is_daemon;
  jobject thread_instance;

  /* We need these for Thread.interrupt() implementation.
   * They are "volatile" because we set/read it from different threads
   * sometimes w/o help of atomic compare&swap. */

  /* see SVM_THREAD* flags in constants.h */
  volatile _svmt_word interrupted_status;
  /* if != NULL then thread is sleeping on it */
  _svmt_fat_lock *volatile sleeping_on_fat_lock;
};

/*
----------------------------------------------------------------------
_svmt_native_locals
----------------------------------------------------------------------
*/

struct _svmt_native_locals_struct
{
  _svmt_native_ref *list;
  _svmt_native_ref *free_list;
};

/*
----------------------------------------------------------------------
_svmt_stack
----------------------------------------------------------------------
*/

struct _svmt_stack_struct
{
  /* each thread has a single contiguous "Java stack", that can grow
     (thus it can move around) */
  void *start;
  void *end;

  _svmt_stack_frame *current_frame;
};

/*
----------------------------------------------------------------------
_svmt_inlinability_testing
----------------------------------------------------------------------
*/

#ifdef _SABLEVM_INLINABILITY_TESTING

struct _svmt_inlinability_testing_struct
{
  jbyte bytecode_inlinability[SVM_INSTRUCTION_COUNT];
  jbyte bytecode_recognizability[SVM_INSTRUCTION_COUNT];
  jboolean ever_used;
  jint last_signal;
  volatile jint sigsegv_expected;
};

#endif

/*
----------------------------------------------------------------------
_svmt_JNIEnv
----------------------------------------------------------------------
*/

struct _svmt_JNIEnv_struct
{
  const JNINativeInterface *interface;	/* This must be first for JNI */

  _svmt_JavaVM *vm;

  _svmt_JNIEnv *previous;	/* for threads (doubly-linked) list */
  _svmt_JNIEnv *next;

  jboolean is_alive;

  _svmt_thread thread;
  _svmt_native_locals native_locals;
  _svmt_stack stack;


  /* "throwable" is a pre-allocated native ref pointing to:
     - NULL when there's no pending error/exception
     - a throwable object otherwise.
   */
  jthrowable throwable;

  /* number of time a "critical" JNI function was entered */
  jint critical_section_count;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

  /* We maintain a pointer to the innermost exception handler.
     If an error/exception signal happens, we jump to it.  The
     signal handler DOES NOT create/set "throwable"; it only
     sets "signal_code" to the appropriate value, and delegates
     to the exception handler the delicate task of actually
     creating a throwable object.
   */
  sigjmp_buf *volatile signal_handler;
  volatile jint signal_code;

#ifndef NDEBUG

  volatile jint sigsegv_expected;
  volatile jint sigfpe_expected;

#endif				/* not NDEBUG */

#ifdef _SABLEVM_INLINABILITY_TESTING

  _svmt_inlinability_testing inlinability_testing;

#endif

#endif				/* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

  /* fields for "stop_the_world" and "suspend" operations */
  volatile _svmt_word thread_status;

  /* flags used to indicate the reason why a thread status is not
     RUNNING_JAVA or NOT_RUNNING_JAVA_RESUMING_ALLOWED.  Access to
     this variable should be protected by the global mutex. */
  jint status_flags;

  /* condition variable used by this thread to wake up from
     stop_the_world and suspend operations */
  pthread_cond_t wakeup_cond;

  struct
  {
    /* list of threads that have requested the suspension of this
       thread.  Protected by global mutex. */
    _svmt_JNIEnv *suspender_list;

    /* points to the next thread when this thread is in the
       suspender_list of another thread. */
    _svmt_JNIEnv *suspender_list_next;

    /* condition variable used by this thread to receive suspension
       notifications */
    pthread_cond_t cond;
  }
  suspension;

  /* fields for dealing with thinlock contention */
  struct
  {
    struct
    {
      pthread_mutex_t mutex;
      volatile _svmt_word flag;	/* 0: no contention, 1: contention */

      _svmt_JNIEnv *wait_list;
    }
    owner;

    struct
    {
      pthread_cond_t cond;

      jobject jobject;
      _svmt_JNIEnv *wait_list_next;
    }
    requester;
  }
  contention;

  /* we use 1 bit per error type to avoid recursively
     creating the same error. In other words, we don't like
     things like an OutOfMemoryError triggering the creation
     of another OutOfMemoryError.  When such a thing happens,
     we simply return a "pre-instantiated" error object, which
     stops this nasty type of recursion.

     Of course, we use m4 to nicely generate the stuff for us.  Much
     better than hand coding, for maintenance;-).  Who was it that
     said that m4 can be addictive?  I think it was written in the m4
     "info" pages...
   */

#include "error_bits.h"

#ifndef NDEBUG

  struct
  {
    jint last_index;
    struct
    {
      const char *action;
      const char *file;
      const char *func;
      int line;
      _svmt_word entry;
      _svmt_word exit;
    } info[SVM_STOP_RESUME_TRACE_SIZE];
  } stop_resume;

#endif

};

/*
----------------------------------------------------------------------
_svmt_classes
----------------------------------------------------------------------
*/
struct _svmt_classes_struct
{
  _svmt_class_info *jiserializable;
  _svmt_class_info *jlclass;
  _svmt_class_info *jlcloneable;
  _svmt_class_info *jlobject;
  _svmt_class_info *jlrconstructor;
  _svmt_class_info *jlrfield;
  _svmt_class_info *jlrinvocationtargetexception;
  _svmt_class_info *jlrmethod;
  _svmt_class_info *jlstacktraceelement;
  _svmt_class_info *jlvmclass;
  _svmt_class_info *niobytebuffervm;
  _svmt_class_info *stringcreator;
  _svmt_class_info *virtualmachine;

  _svmt_array_info *jlrfield_array;

  /* primitive arrays */
  _svmt_array_info *boolean_array;
  _svmt_array_info *byte_array;
  _svmt_array_info *short_array;
  _svmt_array_info *char_array;
  _svmt_array_info *int_array;
  _svmt_array_info *long_array;
  _svmt_array_info *float_array;
  _svmt_array_info *double_array;

#include "error_classes.h"

};

/*
----------------------------------------------------------------------
_svmt_methods
----------------------------------------------------------------------
*/

struct _svmt_methods_struct
{
  _svmt_method_info *jlclass_init;
  _svmt_method_info *jlclass_init_primitive;
  _svmt_method_info *jlclass_initialize;
  _svmt_method_info *jlrconstructor_init;
  _svmt_method_info *jlrfield_init;
  _svmt_method_info *jlrinvocationtargetexception_init;
  _svmt_method_info *jlrmethod_init;
  _svmt_method_info *jlstacktraceelement_init;
  _svmt_method_info *stringcreator_createinternedstring;
  _svmt_method_info *stringcreator_createstring;
  _svmt_method_info *stringcreator_createstringfromchars;
  _svmt_method_info *stringcreator_getchars;
  _svmt_method_info *stringcreator_getlength;
  _svmt_method_info *stringcreator_getutfchars;
  _svmt_method_info *stringcreator_getutflength;
  _svmt_method_info *virtualmachine_createarray;
  _svmt_method_info *virtualmachine_createclass;
  _svmt_method_info *virtualmachine_createrootthread;
  _svmt_method_info *virtualmachine_exceptiondescribe;
  _svmt_method_info *virtualmachine_exceptiondescription;
  _svmt_method_info *virtualmachine_exceptiontruncateddescription;
  _svmt_method_info *virtualmachine_getsystemcl;
  _svmt_method_info *virtualmachine_runthread;
  _svmt_method_info *niobytebuffervm_getcapacity;

#if SVM_WORD_BIT_COUNT == 32
  _svmt_method_info *niobytebuffervm_newbuffer32;
  _svmt_method_info *niobytebuffervm_getaddress32;
#elif SVM_WORD_BIT_COUNT == 64
  _svmt_method_info *niobytebuffervm_newbuffer64;
  _svmt_method_info *niobytebuffervm_getaddress64;
#endif

#include "error_init_methods.h"

};

/*
----------------------------------------------------------------------
_svmt_fields
----------------------------------------------------------------------
*/

struct _svmt_fields_struct
{
  _svmt_field_info *jlclass_vmdata;
  _svmt_field_info *jlrfield_vmdata;
  _svmt_field_info *jlrmethod_vmdata;
  _svmt_field_info *jlrconstructor_vmdata;
  _svmt_field_info *jlstacktraceelement_next;
  _svmt_field_info *jlstacktraceelement_length;
};

/*
----------------------------------------------------------------------
_svmt_instances
----------------------------------------------------------------------
*/

struct _svmt_instances_struct
{
  jobject boolean_type;
  jobject byte_type;
  jobject short_type;
  jobject char_type;
  jobject int_type;
  jobject long_type;
  jobject float_type;
  jobject double_type;
  jobject void_type;

#include "error_instances.h"
};

/*
----------------------------------------------------------------------
_svmt_system_properties
----------------------------------------------------------------------
*/

struct _svmt_system_properties_struct
{
  jint count;

  char **properties;
};

/*
----------------------------------------------------------------------
_svmt_class_file
----------------------------------------------------------------------
*/

struct _svmt_class_file_struct
{
  jint length;
  jboolean free_bytes_after_use;
  _svmt_u8 *bytes;
};

/*
----------------------------------------------------------------------
_svmt_zip_file_struct
----------------------------------------------------------------------
*/

struct _svmt_zip_file_struct
{
  int fd;
  char *name;
  _svmt_u32 file_len;
  _svmt_u8 *content;		/* mmaped */
  _svmt_u16 entries_no;
  _svmt_zip_file_entry *entries;
};

/*
----------------------------------------------------------------------
_svmt_zip_file_entry_struct
----------------------------------------------------------------------
*/

struct _svmt_zip_file_entry_struct
{
  char *name;
  _svmt_u32 local_header_offset;
  _svmt_u32 size_compressed;
  _svmt_u32 size_uncompressed;
  _svmt_u32 compression_method;
};

/*
----------------------------------------------------------------------
_svmt_boot_class_path_entry
----------------------------------------------------------------------
*/

struct _svmt_boot_class_path_entry_struct
{
  jboolean is_valid;		/* non-existan dir/files, or non-zip files get this flag set */
  jboolean is_file;		/* class_path should point to a directory or zip/jar file */
  char *class_path;
  _svmt_zip_file *zip_file;	/* only if not NULL for non-zip/jar class_path */
};

/*
----------------------------------------------------------------------
_svmt_bootstrap_classloader
----------------------------------------------------------------------
*/

struct _svmt_bootstrap_classloader_struct
{
  char *boot_class_path, *boot_class_path_prepend, *boot_class_path_append;
  char *boot_library_path;

  /* boot_class_path split in elements separated by ':' */
  _svmt_boot_class_path_entry *boot_class_path_entries;
  jint boot_class_path_entries_no;

  /* system properties received through the VM creation structure. */
  _svmt_system_properties system_properties;

  _svmt_classes classes;
  _svmt_methods methods;
  _svmt_fields fields;
  _svmt_instances instances;

  _svmt_type_node *initiated_type_tree;
  _svmt_type_node *partially_derived_type_tree;

  _svmt_internal_method_node *internal_method_tree;

  _svmt_class_loader_info *class_loader_info;
};

/*
----------------------------------------------------------------------
_svmt_arg_preparation
----------------------------------------------------------------------
*/

struct _svmt_arg_preparation_struct
{
  jint index;
};

/*
----------------------------------------------------------------------
_svmt_branch_preparation
----------------------------------------------------------------------
*/

struct _svmt_branch_preparation_struct
{
  _svmt_instruction_preparation *target;
};

/*
----------------------------------------------------------------------
_svmt_ldc_preparation
----------------------------------------------------------------------
*/

struct _svmt_ldc_preparation_struct
{
  _svmt_CONSTANT_String_info *stringref_info;	/* is not NULL if this
						   is an ldc[_w]
						   String */
};

/*
----------------------------------------------------------------------
_svmt_fieldref_preparation
----------------------------------------------------------------------
*/

struct _svmt_fieldref_preparation_struct
{
  _svmt_CONSTANT_Fieldref_info *info;
};

/*
----------------------------------------------------------------------
_svmt_methodref_preparation
----------------------------------------------------------------------
*/

struct _svmt_methodref_preparation_struct
{
  _svmt_CONSTANT_Methodref_info *info;
};

/*
----------------------------------------------------------------------
_svmt_imethodref_preparation
----------------------------------------------------------------------
*/

struct _svmt_imethodref_preparation_struct
{
  _svmt_CONSTANT_InterfaceMethodref_info *info;
};

/*
----------------------------------------------------------------------
_svmt_gc_map_node
----------------------------------------------------------------------
*/

struct _svmt_gc_map_node_struct
{
  jint size;			/* number of bits */
  _svmt_u8 *bits;		/* NULL when size is 0 */

  _svmt_gc_map_node *parent;
  _svmt_gc_map_node *left;
  _svmt_gc_map_node *right;
};

/*
----------------------------------------------------------------------
_svmt_stack_and_local_map
----------------------------------------------------------------------
*/

struct _svmt_stack_and_local_map_struct
{
  jint stack_size;
  jint *stack;
  jint *locals;
  _svmt_stack_and_local_map *free_list_next;
};

/*
----------------------------------------------------------------------
_svmt_code
----------------------------------------------------------------------
*/

union _svmt_code_union
{
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER) || defined (_SABLEVM_DIRECT_THREADED_INTERPRETER)
  const void *implementation;
#endif

  _svmt_CONSTANT_Class_info *classref_info;
  _svmt_CONSTANT_String_info *stringref_info;
  _svmt_CONSTANT_Fieldref_info *fieldref_info;
  _svmt_CONSTANT_Methodref_info *methodref_info;
  _svmt_CONSTANT_InterfaceMethodref_info *imethodref_info;
  _svmt_gc_map_node *stack_gc_map;

  _svmt_method_info *method_info;
  _svmt_type_info *type_info;
  _svmt_class_info *class_info;
  _svmt_array_info *array_info;

  _svmt_code *addr;
  size_t offset;

  jint jint;
  jfloat jfloat;

  jlong *pjlong;
  jdouble *pjdouble;

  jvalue *pvalue;

  jobject jobject;
};

/*
----------------------------------------------------------------------
_svmt_instruction_preparation
----------------------------------------------------------------------
*/

struct _svmt_instruction_preparation_struct
{
  unsigned reaches_gc_site:1;	/* true if instruction is
				   unconditionally followed by a gc
				   check */

  unsigned reachable:1;		/* true if there is a path that
				   reaches this instruction */

  unsigned addr_stack_top:1;	/* true if this is an "astore" and
				   stack top holds an address */

  unsigned is_backward_branch_target:1;
  unsigned is_backward_switch_target:1;
  unsigned has_backward_target:1;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  unsigned is_sequence_head:1;
  unsigned is_sequence_tail:1;
  unsigned sequence_contains_resolution:1;
  unsigned is_sequence_last_resolution:1;
#endif

  jint bc_pc;			/* position in the bytecode array */
  jint bc_length;		/* length in the bytecode array */

  size_t code_offset;		/* offset of instruction in code
				   array */
  size_t code_length;		/* length of instruction in code
				   array */

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  size_t sequence_length;	/* number of instructions in sequence */
  size_t sequence_size;		/* implementation size */
#endif

  size_t prepare_offset;
  size_t prepare_length;

  jint code;			/* code translation of bytecode
				   instruction */

  _svmt_stack_and_local_map *stack_and_local_map;
  _svmt_gc_map_node *stack_gc_map;

  /* fields for subroutine head */
  _svmt_instruction_preparation *ret;
  _svmt_instruction_preparation *unprocessed_callers;

  /* field for jsr */
  _svmt_instruction_preparation *next_unprocessed_caller;

  /* for work list */
  _svmt_instruction_preparation *work_list_next;

  union
  {
    _svmt_arg_preparation arg;
    _svmt_branch_preparation branch;
    _svmt_ldc_preparation ldc;
    _svmt_fieldref_preparation fieldref;
    _svmt_methodref_preparation methodref;
    _svmt_imethodref_preparation imethodref;
  }
  data;
};

/*
----------------------------------------------------------------------
_svmt_local_preparation
----------------------------------------------------------------------
*/

struct _svmt_local_preparation_struct
{
  unsigned method_arg_type:2;	/* 0:none, 1:ref, 2:non_ref */

  unsigned used_as_ref:1;
  unsigned used_as_non_ref:1;
  unsigned used_as_long:1;	/* first word of local pair */

  jint ref_index;
  jint non_ref_index;
  jint long_index;
};

/*
----------------------------------------------------------------------
_svmt_method_preparation
----------------------------------------------------------------------
*/

struct _svmt_method_preparation_struct
{
  jint *instruction_indices;

  jint instruction_count;
  _svmt_instruction_preparation *instructions;

  _svmt_local_preparation *locals;
  _svmt_stack_and_local_map *free_list;

  _svmt_sequence_node *sequence;

  size_t code_length;
};

/*
----------------------------------------------------------------------
_svmt_class_loading
----------------------------------------------------------------------
*/

struct _svmt_class_loading_struct
{
  _svmt_class_loader_info *class_loader_list;
  _svmt_bootstrap_classloader boot_loader;

  jint next_interface_id;
  jint next_interface_method_id;
  _svmt_imethod_signature_node *interface_method_signature_tree;

  _svmt_method_preparation method_preparation;
  _svmt_gc_map_node *gc_map_tree;
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  _svmt_sequence_node *sequence_tree;
#endif
};

/*
----------------------------------------------------------------------
_svmt_threads
----------------------------------------------------------------------
*/

struct _svmt_threads_struct
{
  jint next_thread_id;		/* no thread should have id = 0 (for thin
				   locks to work) */

  _svmt_JNIEnv **array;		/* Array of all JNIEnv structures indexed according to
				   their thread.id */

  _svmt_JNIEnv *user;		/* user thread list */
  _svmt_JNIEnv *system;		/* system thread list */

  _svmt_JNIEnv *free_list;	/* freed JNIEnv structures, for recycling */

  pthread_cond_t vm_destruction_cond;
};

/*
----------------------------------------------------------------------
_svmt_native_globals
----------------------------------------------------------------------
*/

struct _svmt_native_globals_struct
{
  _svmt_native_ref *list;	/* list of all global refs currently in use */
  _svmt_native_ref *free_list;
};

/*
----------------------------------------------------------------------
_svmt_remember_set
----------------------------------------------------------------------
*/
#if defined (_SABLEVM_GENCOPY_GC)
struct _svmt_remember_set_struct
{
  struct _svmt_remember_set_struct *next;
  void *ref_hash[SVM_HEAP_REMSET_BUCKET_NUM][SVM_HEAP_REMSET_BUCKET_SIZE];
};

typedef struct _svmt_remember_set_struct _svmt_remember_set;
#endif /* _SABLEVM_GENCOPY_GC */

/*
----------------------------------------------------------------------
_svmt_heap
----------------------------------------------------------------------
*/

struct _svmt_heap_struct
{
#if defined (_SABLEVM_NO_GC)

  size_t size;

  void *start;
  void *end;

  void *alloc;			/* current allocation position */
  jint hashcode_base;

#elif defined (_SABLEVM_COPY_GC) || defined (_SABLEVM_GENCOPY_GC)

  size_t min_size;
  size_t max_size;		/* 0 means no max */
  size_t allocation_increment;	/* 0 means fixed size */

  void *start;
  void *end;

  void *alloc;			/* current allocation position */
  jint hashcode_base;
  size_t hashed_notmoved;	/* number of objects that will inflate on next GC */

  size_t suggested_next_heap_size;	/* for variable size heap */
  void *next_heap;		/* for fixed size heap */

  long total_gc_secs;
  long total_gc_usecs;

#if defined (_SABLEVM_GENCOPY_GC)

  int global_gc;

  size_t nursery_size;
  void *nursery_start;
  void *nursery_end;
  void *nursery_alloc;

  size_t large_object_size;

  _svmt_remember_set remember_set;

  jint hashcode_base_nursery;
  size_t hashed_notmoved_nursery;	/* number of objects that will inflate on next Local GC */

#endif				/* defined (_SABLEVM_GENCOPY_GC) */
#endif				/* defined (_SABLEVM_NO_GC) */
};

/*
----------------------------------------------------------------------
_svmt_instruction_info
----------------------------------------------------------------------
*/

struct _svmt_instruction_info_struct
{
  _svmt_code code;
  jint param_count;		/* number of arguments to the original bytecode instruction */
#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  jint flag;
  _svmt_code inlined_code;
  size_t inlined_size;
#endif
#if !defined(NDEBUG) || defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  /* See comment about static allocation in inlined_testing.c file. */
  char name[_SABLEVM_BYTECODE_NAME_MAX_LENGTH];
#endif
};

/*
----------------------------------------------------------------------
_svmt_method_frame_info
----------------------------------------------------------------------
*/

struct _svmt_method_frame_info_struct
{
  /* The actual sablevm internal code array */
  _svmt_code *code;

  /* number of non-parameter reference local variables */
  jint non_parameter_ref_locals_count;

  size_t start_offset;
  size_t end_offset;

  size_t java_invoke_frame_size;
  size_t internal_invoke_frame_size;

#ifdef STATISTICS

  size_t local_count;
  size_t local_split_count;

#endif
};

/*
----------------------------------------------------------------------
_svmt_method_info
----------------------------------------------------------------------
*/

struct _svmt_method_info_struct
{
  jint access_flags;
  _svmt_CONSTANT_Utf8_info **name;
  _svmt_CONSTANT_Utf8_info **descriptor;

  jint attributes_count;
  _svmt_attribute_info **attributes;

  _svmt_class_info *class_info;

  jint method_id;

  jint synchronized;		/* yes = 1; no = 0 */
  jint java_args_count;		/* int,ref,boolean,... = 1; double, long = 2 */
  _svmt_gc_map_node *parameters_gc_map;

  _svmt_method_frame_info *frame_info;

  _svmt_method_frame_info prepared_info;
  _svmt_method_frame_info non_prepared_info;

  jobject reflection_instance;

  union
  {
    _svmt_Code_attribute *code_attribute;
    _svmt_native_method_data *native_method;
  }
  data;
};

/*
----------------------------------------------------------------------
_svmt_fat_locks
----------------------------------------------------------------------
*/

struct _svmt_fat_locks_struct
{
  jint next_fat_lock_id;

  _svmt_fat_lock **array;

  _svmt_fat_lock *free_list;
};

/*
----------------------------------------------------------------------
_svmt_JavaVM
----------------------------------------------------------------------
*/

struct _svmt_JavaVM_struct
{
  const JNIInvokeInterface *interface;	/* This must be first for JNI */

  /* hooks into the linked list of created vms */
  _svmt_JavaVM *previous;
  _svmt_JavaVM *next;

  /* The initialization ptr is non-NULL during vm initialization.
     The vm is guaranteed to be single threaded as long as
     (initialization != NULL). [Please make sure you don't
     break this rule if you modify SableVM].
   */
  _svmt_initialization *initialization;

  /* mutex used to synchronize for global operations like stoppping the world */
  pthread_mutex_t global_mutex;

  /* stop-the-world fields */
  struct
  {
    jint pending_halt_thread_count;
    pthread_cond_t requesting_thread_cond;
  }
  stop_the_world;

  /* raw instruction pointer array */
  _svmt_instruction_info *instructions;	/* [SVM_INSTRUCTION_COUNT]; */

  /* special methods */
  _svmt_method_info stack_bottom_method;
  _svmt_method_info internal_call_method;
  _svmt_method_info vm_initiated_call_method;

  /* class loading related data */
  _svmt_class_loading class_loading;

  /* threads */
  _svmt_threads threads;

  /* fat_locks */
  _svmt_fat_locks fat_locks;

  /* global data */
  _svmt_native_globals native_globals;
  _svmt_heap heap;

  /* function pointers received through JNI */

  int (*vfprintf) (FILE *stream, const char *format, va_list ap);
  void (*exit) (int status);
  void (*abort) (void);
  const char *boot_working_directory;

  /* global options */

  jboolean verbose_class;
  jboolean verbose_gc;
  jboolean verbose_jni;

  jboolean enforce_structured_locking;

#if !defined(NDEBUG)

  jboolean verbose_exceptions;	/* dump stack trace for every thrown exception */
  jboolean exit_stack_trace;	/* dump stack trace on java.lang.Runtime.exit() */

#endif

#if !defined(NDEBUG) || defined(_SABLEVM_VERBOSE_INSTRUCTIONS_INLINED)

  jboolean verbose_methods;
  jboolean verbose_instructions;
  jboolean verbose_synchronization;

#endif

#ifdef STATISTICS

  size_t class_count;		/* number of prepared classes */
  size_t interface_count;
  size_t array_count;
  size_t method_count;		/* number of prepared methods */
  size_t bytecode_instruction_count;	/* number of prepared bytecode instructions */
  size_t bytecode_count;	/* number of prepared bytecodes */
  size_t code_size;		/* size of code arrays in bytes (prepared methods) */

  size_t max_stack_size;	/* max stack size in bytes */
  size_t stack_local_count;	/* locals count on stack */
  size_t stack_local_split_count;	/* Number of split locals on stack */

  /* sparse interface virtual tables */
  size_t total_ivtables;	/* size */
  size_t total_holes;		/* size */
  size_t total_lost_holes;	/* size that have leaked out of the class
				   loader's free_blocks array */

  /* gc maps */
  size_t total_gc_maps_size;
  size_t total_gc_maps_count;
  size_t check_points_count;

  /* locals */
  size_t total_orig_locals_count;
  size_t total_unused_locals_count;
  size_t total_added_locals_count;

#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

  /* inlined threads */
  size_t distinct_inlined_threads_count;
  size_t total_distinct_thread_bc_length;
  size_t total_distinct_thread_inlined_length;

  size_t inlined_threads_count;
  size_t total_thread_bc_length;
  size_t total_thread_inlined_length;

  size_t max_thread_bc_length;
  size_t max_thread_inlined_length;

#endif

#endif


  size_t stack_min_size;
  size_t stack_max_size;
  size_t stack_allocation_increment;

  size_t class_loader_min_size;
  size_t class_loader_max_size;
  size_t class_loader_allocation_increment;
};

/*
----------------------------------------------------------------------
_svmt_initialization
----------------------------------------------------------------------
*/

struct _svmt_initialization_struct
{
  sigjmp_buf unrecoverable_exception_handler;
};

/*
----------------------------------------------------------------------
_svmt_free_block
----------------------------------------------------------------------
*/

struct _svmt_free_block_struct
{
  size_t size;
  void *block;
};

/*
----------------------------------------------------------------------
_svmt__svmt_class_loader_info
----------------------------------------------------------------------
*/

struct _svmt_class_loader_info_struct
{
  jobject class_loader;

  _svmt_class_loader_info *previous;
  _svmt_class_loader_info *next;

  /* memory management */
  size_t total_allocation_size;
  _svmt_memory_block *memory_block_list;	/* allocated memory blocks */
  _svmt_free_block free_blocks[SVM_CLASS_LOADER_FREE_ARRAY_SIZE];	/* current free blocks */

  /* native libraries
     Note: We must keep this list in loading order (to this
     end, we use a tail pointer).
   */
  _svmt_native_library *native_library_list;
  _svmt_native_library **native_library_list_tail;
};

/*
----------------------------------------------------------------------
_svmt_native_ref
----------------------------------------------------------------------
*/

struct _svmt_native_ref_struct
{
  _svmt_object_instance *ref;
  _svmt_native_ref *previous;
  _svmt_native_ref *next;
};

/*
----------------------------------------------------------------------
_svmt_type_info
----------------------------------------------------------------------
*/

struct _svmt_type_info_struct
{
  char *name;
  char *array_type_name;
  _svmt_class_loader_info *class_loader_info;
  jclass class_instance;
  jint access_flags;
  jint is_array;
};

/*
----------------------------------------------------------------------
_svmt_array_info
----------------------------------------------------------------------
*/

struct _svmt_array_info_struct
{
  char *name;
  char *array_type_name;
  _svmt_class_loader_info *class_loader_info;
  jclass class_instance;
  jint access_flags;
  jint is_array;		/* JNI_TRUE */

  jint state;			/* SVM_TYPE_STATE_XXX mask */
  jthrowable preparation_error;

  jint dimensions;		/* 0 < dimensions < 256 */
  jint base_type;		/* SVM_TYPE_XXX */
  _svmt_class_info *base_class;	/* NULL if primitive  array */
  _svmt_array_info *array_element;	/* NULL if dimension == 1 */

  _svmt_vtable *vtable;
  _svmt_word initial_lockword;
};

/*
----------------------------------------------------------------------
_svmt_noninterface_class_data
----------------------------------------------------------------------
*/

struct _svmt_noninterface_class_data_struct
{
  _svmt_vtable *vtable;
  _svmt_word initial_lockword;

  /* instanceof data */
  jint super_classes_size;
  _svmt_class_info **super_classes;

  jint max_interface_id;
  _svmt_u8 *super_interfaces;	/* bit array */

  /* methods data */
  jint max_virtual_method_id;
  jint max_interface_method_id;

  /* instance data */
  size_t next_offset_no_hashcode;
  size_t next_offset_with_hashcode;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  jint ref_field_count;
  size_t start_offset;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  jint ref_field_count;
  size_t *ref_field_offsets;

#endif

  /* available free space for subclasses */
  jint free_bits_count;
  size_t free_bits_offset;
  size_t free_space_offset[SVM_ALIGNMENT_POWER];
};

/*
----------------------------------------------------------------------
_svmt_interface_class_data
----------------------------------------------------------------------
*/

struct _svmt_interface_class_data_struct
{
  /* instanceof data */
  jint interface_id;
  _svmt_u8 *super_interfaces;	/* bit array */

  /* methods data */
  jint max_interface_method_id;
};

/*
----------------------------------------------------------------------
_svmt_class_info
----------------------------------------------------------------------
*/

struct _svmt_class_info_struct
{
  char *name;
  char *array_type_name;
  _svmt_class_loader_info *class_loader_info;
  jclass class_instance;
  jint access_flags;
  jint is_array;		/* JNI_FALSE */

  jint state;			/* SVM_TYPE_STATE_XXX mask */
  jthrowable preparation_error;
  jthrowable verification_error;
  jobject protection_domain;

  jint minor_version;
  jint major_version;

  jint constant_pool_count;
  _svmt_cp_info **constant_pool;

  _svmt_CONSTANT_Class_info **this_class;
  _svmt_CONSTANT_Class_info **super_class;

  jint interfaces_count;
  _svmt_CONSTANT_Class_info ***interfaces;

  jint fields_count;
  _svmt_field_info *fields;

  jint methods_count;
  _svmt_method_info *methods;

  jint attributes_count;
  _svmt_attribute_info **attributes;

  char *file_name;

  union
  {
    _svmt_noninterface_class_data noninterface;
    _svmt_interface_class_data interface;
  }
  data;
};

/*
----------------------------------------------------------------------
_svmt_cp_info
----------------------------------------------------------------------
*/

struct _svmt_cp_info_struct
{
  jint tag;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Class_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Class_info_struct
{
  jint tag;
  _svmt_CONSTANT_Utf8_info **name;

  _svmt_type_info *type;
  jthrowable resolution_error;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Fieldref_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Fieldref_info_struct
{
  jint tag;
  _svmt_CONSTANT_Class_info **class;
  _svmt_CONSTANT_NameAndType_info **name_and_type;

  _svmt_field_info *field;
  jthrowable resolution_error;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Methodref_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Methodref_info_struct
{
  jint tag;
  _svmt_CONSTANT_Class_info **class;
  _svmt_CONSTANT_NameAndType_info **name_and_type;

  _svmt_method_info *method;
  jthrowable resolution_error;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_InterfaceMethodref_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_InterfaceMethodref_info_struct
{
  jint tag;
  _svmt_CONSTANT_Class_info **class;
  _svmt_CONSTANT_NameAndType_info **name_and_type;

  _svmt_method_info *method;
  jthrowable resolution_error;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_String_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_String_info_struct
{
  jint tag;
  _svmt_CONSTANT_Utf8_info **string;

  _svmt_class_info *class_info;
  jstring value;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Integer_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Integer_info_struct
{
  jint tag;
  jint value;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Float_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Float_info_struct
{
  jint tag;
  jfloat value;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Long_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Long_info_struct
{
  jint tag;
  jlong value;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Double_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Double_info_struct
{
  jint tag;
  jdouble value;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_NameAndType_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_NameAndType_info_struct
{
  jint tag;
  _svmt_CONSTANT_Utf8_info **name;
  _svmt_CONSTANT_Utf8_info **descriptor;
};

/*
----------------------------------------------------------------------
_svmt_CONSTANT_Utf8_info
----------------------------------------------------------------------
*/

struct _svmt_CONSTANT_Utf8_info_struct
{
  jint tag;
  jint length;
  char *value;
};

/*
----------------------------------------------------------------------
_svmt_instance_field_data
----------------------------------------------------------------------
*/

struct _svmt_instance_field_data_struct
{
  /* the offset is calculated in bytes, except for boolean fields in
     which the offset is calculated in bits */
  size_t offset;
};

/*
----------------------------------------------------------------------
_svmt_class_field_data
----------------------------------------------------------------------
*/

struct _svmt_class_field_data_struct
{
  jvalue value;
};

/*
----------------------------------------------------------------------
_svmt_field_info
----------------------------------------------------------------------
*/

struct _svmt_field_info_struct
{
  jint access_flags;
  _svmt_CONSTANT_Utf8_info **name;
  _svmt_CONSTANT_Utf8_info **descriptor;

  jint attributes_count;
  _svmt_attribute_info **attributes;

  _svmt_class_info *class_info;

  jint type;			/* SVM_TYPE_XXX */

  jobject reflection_instance;

  union
  {
    _svmt_instance_field_data instance_field;
    _svmt_class_field_data class_field;
  }
  data;
};

/*
----------------------------------------------------------------------
_svmt_native_method_data
----------------------------------------------------------------------
*/

struct _svmt_native_method_data_struct
{
  char *short_name;
  char *long_name;
  void (*code) (void);

  jint args_count;
  jint *arg_types;
  jint ret_type;

  /* max (java_args_count, ret_size[which is 0,1 or 2]) */
  jint java_args_and_ret_count;

  jint refargs_count;

  ffi_type **args;
  ffi_type *ret;
  ffi_cif *cif;
};

/*
----------------------------------------------------------------------
_svmt_attribute_info
----------------------------------------------------------------------
*/

struct _svmt_attribute_info_struct
{
  _svmt_CONSTANT_Utf8_info **name;
};

/*
----------------------------------------------------------------------
_svmt_ConstantValue_attribute
----------------------------------------------------------------------
*/

struct _svmt_ConstantValue_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  _svmt_cp_info **constantvalue;
};

/*
----------------------------------------------------------------------
_svmt_exception_table
----------------------------------------------------------------------
*/

struct _svmt_exception_table_struct
{
  jint start_pc;
  jint end_pc;
  jint handler_pc;
  _svmt_CONSTANT_Class_info **catch_type;

  _svmt_code *normal_start;
  _svmt_code *normal_end;
  _svmt_code *prepare_start;
  _svmt_code *prepare_end;
  _svmt_code *handler;
};

/*
----------------------------------------------------------------------
_svmt_Code_attribute
----------------------------------------------------------------------
*/

struct _svmt_Code_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  jint max_stack;
  jint max_locals;

  jlong code_length;
  _svmt_u8 *code;		/* original bytecode array */

  jint exception_table_length;
  _svmt_exception_table *exception_table;

  jint attributes_count;
  _svmt_attribute_info **attributes;

  _svmt_LineNumberTable_attribute *line_numbers;
};

/*
----------------------------------------------------------------------
_svmt_Exceptions_attribute
----------------------------------------------------------------------
*/

struct _svmt_Exceptions_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  jint number_of_exceptions;
  _svmt_CONSTANT_Class_info ***exception_table;
};

/*
----------------------------------------------------------------------
_svmt_inner_classes
----------------------------------------------------------------------
*/

struct _svmt_inner_classes_struct
{
  _svmt_CONSTANT_Class_info **inner_class_info;
  _svmt_CONSTANT_Class_info **outer_class_info;
  _svmt_CONSTANT_Utf8_info **inner_name;
  jint inner_class_access_flags;
};

/*
----------------------------------------------------------------------
_svmt_InnerClasses_attribute
----------------------------------------------------------------------
*/

struct _svmt_InnerClasses_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  jint number_of_classes;
  _svmt_inner_classes *classes;
};

/*
----------------------------------------------------------------------
_svmt_Synthetic_attribute
----------------------------------------------------------------------
*/

struct _svmt_Synthetic_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;
};

/*
----------------------------------------------------------------------
_svmt_SourceFile_attribute
----------------------------------------------------------------------
*/

struct _svmt_SourceFile_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  _svmt_CONSTANT_Utf8_info **sourcefile;
};

/*
----------------------------------------------------------------------
_svmt_line_number_table
----------------------------------------------------------------------
*/

struct _svmt_line_number_table_struct
{
  jint start_pc;
  jint line_number;
  _svmt_code *normal_start;
  _svmt_code *normal_end;
  _svmt_code *prepare_start;
  _svmt_code *prepare_end;
};

/*
----------------------------------------------------------------------
_svmt_LineNumberTable_attribute
----------------------------------------------------------------------
*/

struct _svmt_LineNumberTable_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  jint line_number_table_length;
  _svmt_line_number_table *line_number_table;
};

/*
----------------------------------------------------------------------
_svmt_local_variable_table
----------------------------------------------------------------------
*/

struct _svmt_local_variable_table_struct
{
  jint start_pc;
  jint length;
  _svmt_CONSTANT_Utf8_info **name;
  _svmt_CONSTANT_Utf8_info **descriptor;
  jint index;
};

/*
----------------------------------------------------------------------
_svmt_LocalVariableTable_attribute
----------------------------------------------------------------------
*/

struct _svmt_LocalVariableTable_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;

  jint local_variable_table_length;
  _svmt_local_variable_table *local_variable_table;
};

/*
----------------------------------------------------------------------
_svmt_Deprecated_attribute
----------------------------------------------------------------------
*/

struct _svmt_Deprecated_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;
};

/*
----------------------------------------------------------------------
_svmt_unknown_attribute
----------------------------------------------------------------------
*/

struct _svmt_unknown_attribute_struct
{
  _svmt_CONSTANT_Utf8_info **name;
  _svmt_u32 length;
  _svmt_u8 *info;
};

/*
----------------------------------------------------------------------
_svmt_stack_frame
----------------------------------------------------------------------
*/

struct _svmt_stack_frame_struct
{
  size_t previous_offset;
  size_t end_offset;
  _svmt_method_info *method;
  _svmt_object_instance *stack_trace_element;	/* cached element */
  jint lock_count;		/* structured locking */
  _svmt_object_instance *this;	/* for static methods, this points to
				   the class instance */
  _svmt_code *pc;
  jint stack_size;
};

/*
----------------------------------------------------------------------
_svmt_stack_value
----------------------------------------------------------------------
*/

union _svmt_stack_value_union
{
  jint jint;
  jfloat jfloat;
  _svmt_object_instance *reference;
  _svmt_code *addr;
  void *ptr;
  char alignment[SVM_ALIGNMENT];
};

/*
----------------------------------------------------------------------
_svmt_object_instance
----------------------------------------------------------------------
*/

struct _svmt_object_instance_struct
{
  _svmt_word lockword;
#ifdef MAGIC
  char magic[8];
#endif
  _svmt_vtable *vtable;

};

/*
----------------------------------------------------------------------
_svmt_array_instance
----------------------------------------------------------------------
*/

struct _svmt_array_instance_struct
{
  _svmt_word lockword;
#ifdef MAGIC
  char magic[8];
#endif
  _svmt_vtable *vtable;
  jint size;
  jint hashcode;
};

/*
----------------------------------------------------------------------
_svmt_vtable
----------------------------------------------------------------------
*/

struct _svmt_vtable_struct
{
  _svmt_type_info *type;
  size_t hashcode_offset;

#if defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)

  size_t next_offset_no_hashcode;
  size_t next_offset_with_hashcode;
  size_t start_offset;

#elif defined(_SABLEVM_TRADITIONAL_OBJECT_LAYOUT)

  size_t next_offset_no_hashcode;
  size_t next_offset_with_hashcode;
  jint ref_field_count;
  size_t *ref_field_offsets;

#endif
};

/*
----------------------------------------------------------------------
_svmt_stack_native_reference
----------------------------------------------------------------------
*/

union _svmt_stack_native_reference_union
{
  jint jint;
  size_t size_t;
  jobject jobject;
};

/*
----------------------------------------------------------------------
_svmt_native_library
----------------------------------------------------------------------
*/

struct _svmt_native_library_struct
{
  char *name;
  lt_dlhandle handle;

  _svmt_native_library *next;
};

/*
----------------------------------------------------------------------
_svmt_memory_block
----------------------------------------------------------------------
*/

struct _svmt_memory_block_struct
{
  size_t size;
  void *block;

  _svmt_memory_block *next;
};

/*
----------------------------------------------------------------------
_svmt_type_node
----------------------------------------------------------------------
*/

struct _svmt_type_node_struct
{
  const char *name;
  _svmt_type_info *type;

  _svmt_type_node *parent;
  _svmt_type_node *left;
  _svmt_type_node *right;
};

/*
----------------------------------------------------------------------
_svmt_imethod_signature_node
----------------------------------------------------------------------
*/

struct _svmt_imethod_signature_node_struct
{
  const char *name;
  const char *descriptor;
  jint interface_method_id;

  _svmt_imethod_signature_node *parent;
  _svmt_imethod_signature_node *left;
  _svmt_imethod_signature_node *right;
};

/*
----------------------------------------------------------------------
_svmt_sequence_node
----------------------------------------------------------------------
*/

struct _svmt_sequence_node_struct
{
  size_t instructions_length;
  jint *instructions;
  size_t implementation_length;
  void *implementation;

  _svmt_sequence_node *parent;
  _svmt_sequence_node *left;
  _svmt_sequence_node *right;
};

/*
----------------------------------------------------------------------
_svmt_fat_lock
----------------------------------------------------------------------
*/

struct _svmt_fat_lock_struct
{
  _svmt_word id;

  _svmt_fat_lock *next;

  pthread_mutex_t mutex;
  pthread_cond_t cond;

  _svmt_JNIEnv *owner;
  jint recursive_count;

  pthread_cond_t notification_cond;
};

/*
----------------------------------------------------------------------
_svmt_internal_method_node
----------------------------------------------------------------------
*/

struct _svmt_internal_method_node_struct
{
  const char *name;
  void (*code) (void);

  _svmt_internal_method_node *parent;
  _svmt_internal_method_node *left;
  _svmt_internal_method_node *right;
};

#endif /* not SVM_SABLEVM_H */
