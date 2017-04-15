/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This file is part of SableVM.                             *
 * See the file "LICENSE" for Copyright information and the  *
 * terms and conditions for copying, distribution and        *
 * modification of SableVM.                                  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_file_head
----------------------------------------------------------------------
*/

m4svm_define_begin v = ":], [:m4svm_file_head:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_initialize_internal_method_tree
-----------------------------------m4_dnl
-----------------------------------
*/

svm_static jint
_svmf_initialize_internal_method_tree (_svmt_JNIEnv *env)
{
  /* pointer to node to insert in the splay tree */
  _svmt_internal_method_node *internal_method_node = NULL;

  assert (env->vm->class_loading.boot_loader.internal_method_tree == NULL);


  m4svm_define_end v = ":])";

}

/*
----------------------------------------------------------------------
m4svm_file_tail
----------------------------------------------------------------------
*/

void
dummy (void)
{
  m4svm_define_begin v = ":], [:m4svm_file_tail:])";

  return JNI_OK;

error:

  return JNI_ERR;
}

m4svm_define_end v = ":])";

/*
----------------------------------------------------------------------
m4svm_internal_method
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_internal_method)
 */

void
dummy (void)
{

  m4svm_define_begin v = ":], [:m4svm_internal_method:])";

  /* Put address of $1 into splay tree */

  if (_svmm_gzalloc_internal_method_node (env, internal_method_node) !=
      JNI_OK)
    {
      goto error;
    }

  internal_method_node->name = "$1";
  internal_method_node->code = (void (*)(void)) $1;

  _svmm_tree_insert_internal_method (env->vm->class_loading.boot_loader.
				     internal_method_tree,
				     internal_method_node);

  m4svm_define_end v = ":])";

}
