/* This file has been automatically generated from "global_alloc.list" */

#ifndef SVM_GLOBAL_ALLOC_H
#define SVM_GLOBAL_ALLOC_H

/*
----------------------------------------------------------------------
_svmm_gzalloc_env_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_env_no_exception(ptr) \
_svmh_gzalloc_env_no_exception (&ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_env_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzfree_env_no_exception(ptr) \
_svmh_gzfree_env_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_fat_lock_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_fat_lock_no_exception(ptr) \
_svmh_gzalloc_fat_lock_no_exception (&ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_fat_lock_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzfree_fat_lock_no_exception(ptr) \
_svmh_gzfree_fat_lock_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_initialization_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_initialization_no_exception(ptr) \
_svmh_gzalloc_initialization_no_exception (&ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_initialization_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzfree_initialization_no_exception(ptr) \
_svmh_gzfree_initialization_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_native_ref_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_native_ref_no_exception(ptr) \
_svmh_gzalloc_native_ref_no_exception (&ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_native_ref_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzfree_native_ref_no_exception(ptr) \
_svmh_gzfree_native_ref_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_vm_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_vm_no_exception(ptr) \
_svmh_gzalloc_vm_no_exception (&ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_vm_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzfree_vm_no_exception(ptr) \
_svmh_gzfree_vm_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_cchars_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_cchars_no_exception(n, ptr) \
_svmh_gzmalloc_cchars_no_exception (n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_cchars_no_exception
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_cchars_no_exception(ptr) \
_svmh_gzmfree_cchars_no_exception (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_class_loader_info
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_class_loader_info(env, ptr) \
_svmh_gzalloc_class_loader_info (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_class_loader_info
----------------------------------------------------------------------
*/

#define _svmm_gzfree_class_loader_info(ptr) \
_svmh_gzfree_class_loader_info (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_gc_map_node
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_gc_map_node(env, ptr) \
_svmh_gzalloc_gc_map_node (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_gc_map_node
----------------------------------------------------------------------
*/

#define _svmm_gzfree_gc_map_node(ptr) \
_svmh_gzfree_gc_map_node (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_imethod_signature_node
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_imethod_signature_node(env, ptr) \
_svmh_gzalloc_imethod_signature_node (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_imethod_signature_node
----------------------------------------------------------------------
*/

#define _svmm_gzfree_imethod_signature_node(ptr) \
_svmh_gzfree_imethod_signature_node (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_memory_block
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_memory_block(env, ptr) \
_svmh_gzalloc_memory_block (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_memory_block
----------------------------------------------------------------------
*/

#define _svmm_gzfree_memory_block(ptr) \
_svmh_gzfree_memory_block (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_type_node
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_type_node(env, ptr) \
_svmh_gzalloc_type_node (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_type_node
----------------------------------------------------------------------
*/

#define _svmm_gzfree_type_node(ptr) \
_svmh_gzfree_type_node (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_internal_method_node
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_internal_method_node(env, ptr) \
_svmh_gzalloc_internal_method_node (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_internal_method_node
----------------------------------------------------------------------
*/

#define _svmm_gzfree_internal_method_node(ptr) \
_svmh_gzfree_internal_method_node (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzalloc_zip_file
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_zip_file(env, ptr) \
_svmh_gzalloc_zip_file (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_zip_file
----------------------------------------------------------------------
*/

#define _svmm_gzfree_zip_file(ptr) \
_svmh_gzfree_zip_file (&ptr)


#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmm_gzalloc_sequence_node
----------------------------------------------------------------------
*/

#define _svmm_gzalloc_sequence_node(env, ptr) \
_svmh_gzalloc_sequence_node (env, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzfree_sequence_node
----------------------------------------------------------------------
*/

#define _svmm_gzfree_sequence_node(ptr) \
_svmh_gzfree_sequence_node (&ptr)


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */

/*
----------------------------------------------------------------------
_svmm_gmalloc_cchars
----------------------------------------------------------------------
*/

#define _svmm_gmalloc_cchars(env, n, ptr) \
_svmh_gmalloc_cchars (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gmfree_cchars
----------------------------------------------------------------------
*/

#define _svmm_gmfree_cchars(ptr) \
_svmh_gmfree_cchars (&ptr)


/*
----------------------------------------------------------------------
_svmm_gmalloc_ints
----------------------------------------------------------------------
*/

#define _svmm_gmalloc_ints(env, n, ptr) \
_svmh_gmalloc_ints (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gmfree_ints
----------------------------------------------------------------------
*/

#define _svmm_gmfree_ints(ptr) \
_svmh_gmfree_ints (&ptr)


/*
----------------------------------------------------------------------
_svmm_gmalloc_ubytes
----------------------------------------------------------------------
*/

#define _svmm_gmalloc_ubytes(env, n, ptr) \
_svmh_gmalloc_ubytes (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gmfree_ubytes
----------------------------------------------------------------------
*/

#define _svmm_gmfree_ubytes(ptr) \
_svmh_gmfree_ubytes (&ptr)


/*
----------------------------------------------------------------------
_svmm_gmalloc_chars
----------------------------------------------------------------------
*/

#define _svmm_gmalloc_chars(env, n, ptr) \
_svmh_gmalloc_chars (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gmfree_chars
----------------------------------------------------------------------
*/

#define _svmm_gmfree_chars(ptr) \
_svmh_gmfree_chars (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_env_array
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_env_array(env,n,ptr) \
_svmh_gzmalloc_env_array (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_env_array
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_env_array(ptr) \
_svmh_gzmfree_env_array (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_fat_lock_array
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_fat_lock_array(env,n,ptr) \
_svmh_gzmalloc_fat_lock_array (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_fat_lock_array
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_fat_lock_array(ptr) \
_svmh_gzmfree_fat_lock_array (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_instruction_info
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_instruction_info(env,n,ptr) \
_svmh_gzmalloc_instruction_info (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_instruction_info
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_instruction_info(ptr) \
_svmh_gzmfree_instruction_info (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_instruction_preparation
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_instruction_preparation(env,n,ptr) \
_svmh_gzmalloc_instruction_preparation (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_instruction_preparation
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_instruction_preparation(ptr) \
_svmh_gzmfree_instruction_preparation (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_local_preparation
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_local_preparation(env,n,ptr) \
_svmh_gzmalloc_local_preparation (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_local_preparation
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_local_preparation(ptr) \
_svmh_gzmfree_local_preparation (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_ubytes
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_ubytes(env,n,ptr) \
_svmh_gzmalloc_ubytes (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_ubytes
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_ubytes(ptr) \
_svmh_gzmfree_ubytes (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_boot_class_path_entry
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_boot_class_path_entry(env,n,ptr) \
_svmh_gzmalloc_boot_class_path_entry (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_boot_class_path_entry
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_boot_class_path_entry(ptr) \
_svmh_gzmfree_boot_class_path_entry (&ptr)


/*
----------------------------------------------------------------------
_svmm_gzmalloc_zip_file_entry
----------------------------------------------------------------------
*/

#define _svmm_gzmalloc_zip_file_entry(env,n,ptr) \
_svmh_gzmalloc_zip_file_entry (env, n, &ptr)

/*
----------------------------------------------------------------------
_svmm_gzmfree_zip_file_entry
----------------------------------------------------------------------
*/

#define _svmm_gzmfree_zip_file_entry(ptr) \
_svmh_gzmfree_zip_file_entry (&ptr)


#endif /* NOT SVM_GLOBAL_ALLOC_H */
