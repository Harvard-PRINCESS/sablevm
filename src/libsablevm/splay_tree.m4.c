/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
----------------------------------------------------------------------
m4svm_splay_tree
----------------------------------------------------------------------
*/

/*
 * This macro can be multi-called.
 * m4svm_multicall(m4svm_splay_tree)
 */

m4svm_define_begin v = ":], [:m4svm_splay_tree:])";

/*
-----------------------------------m4_dnl
-----------------------------------
_svmf_tree_splay_$1
-----------------------------------m4_dnl
-----------------------------------
*/

inline svm_static void
_svmf_tree_splay_$1 ($2 ** proot, $2 * node)
{
  assert (node != NULL);

  while (1)
    {
      $2 *parent = node->parent;
      $2 *grand_parent = (parent == NULL) ? NULL : parent->parent;
      jint is_left_parent_child =
	(parent != NULL && node == parent->left) ? 1 : 0;
      jint is_left_grand_parent_child =
	(grand_parent != NULL && parent == grand_parent->left) ? 1 : 0;

      if (parent == NULL)
	{
	  assert (*proot == node);

	  return;
	}

      if (grand_parent == NULL)
	{
	  $2 **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  $2 **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  $2 **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  $2 *A = *node_second;
	  $2 *B = *parent_other;

	  node->parent = parent->parent;

	  *node_second = parent;
	  parent->parent = node;

	  *parent_this = A;
	  if (A != NULL)
	    {
	      A->parent = parent;
	    }

	  *parent_other = B;
	  if (B != NULL)
	    {
	      B->parent = parent;
	    }

	  assert (node->parent == NULL);
	  assert (*proot == parent);

	  *proot = node;
	  return;
	}

      {
	$2 **node_first = is_left_parent_child ? &node->left : &node->right;
	$2 **node_second = is_left_parent_child ? &node->right : &node->left;
	$2 **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	$2 **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	$2 **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	$2 *A = *node_second;
	$2 *B = same ? *parent_other : *node_first;

	node->parent = grand_parent->parent;

	if (same)
	  {
	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *parent_other = grand_parent;
	    grand_parent->parent = parent;

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }
	else
	  {
	    *node_first = grand_parent;
	    grand_parent->parent = node;

	    *node_second = parent;
	    parent->parent = node;

	    *parent_this = A;
	    if (A != NULL)
	      {
		A->parent = parent;
	      }

	    *grand_parent_this = B;
	    if (B != NULL)
	      {
		B->parent = grand_parent;
	      }
	  }

	if (node->parent == NULL)
	  {
	    assert (*proot == grand_parent);

	    *proot = node;
	    return;
	  }
	else
	  {
	    if (node->parent->left == grand_parent)
	      {
		node->parent->left = node;
	      }
	    else
	      {
		assert (node->parent->right == grand_parent);

		node->parent->right = node;
	      }
	  }
      }
    }
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_tree_find_$1
-----------------------------------m4_dnl
-----------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_$1 ($2 * value1, $2 * value2);

#define _svmm_tree_find_$1(root, value) \
_svmh_tree_find_$1 (&root, value)

svm_static $2 * _svmh_tree_find_$1 ($2 ** proot, $2 * value)
{
  $2 *current = *proot;
  $2 *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_$1 (value, current);

      last = current;

      if (comparison < 0)
	{
	  current = current->left;
	}
      else if (comparison > 0)
	{
	  current = current->right;
	}
      else
	{
	  _svmf_tree_splay_$1 (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_$1 (proot, last);
    }

  return NULL;
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_tree_insert_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_tree_insert_$1(root, value) \
_svmh_tree_insert_$1 (&root, value)

svm_static void
_svmh_tree_insert_$1 ($2 ** proot, $2 * value)
{
  $2 **pcurrent = proot;
  $2 *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_$1 (value, *pcurrent);

      parent = *pcurrent;

      if (comparison < 0)
	{
	  pcurrent = &((*pcurrent)->left);
	}
      else if (comparison > 0)
	{
	  pcurrent = &((*pcurrent)->right);
	}
      else
	{
	  /* node already in tree ! */
	  assert (1 == 0);
	}
    }

  *pcurrent = value;
  value->parent = parent;

  _svmf_tree_splay_$1 (proot, value);
}

/*
-----------------------------------m4_dnl
-----------------------------------
_svmh_tree_remove_$1
-----------------------------------m4_dnl
-----------------------------------
*/

#define _svmm_tree_remove_$1(root, node) \
_svmh_tree_remove_$1 (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_$1 ($2 ** proot, $2 * node)
{
  $2 **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      $2 *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_$1 (proot, next);

      /* the next value is now the root of the tree[:,:] so there cannot
         remain a right child. */
      assert (node->right == NULL);
    }

  /* retrieve the parent pointer to node */
  if (node->parent == NULL)
    {
      assert (*proot == node);

      parent_ptr = proot;
    }
  else
    {
      $2 *parent = node->parent;

      if (parent->left == node)
	{
	  parent_ptr = &parent->left;
	}
      else
	{
	  assert (parent->right == node);

	  parent_ptr = &parent->right;
	}
    }

  /* remove node from the tree */
  if (node->left != NULL)
    {
      assert (node->right == NULL);

      *parent_ptr = node->left;
      node->left->parent = node->parent;
    }
  else if (node->right != NULL)
    {
      assert (node->left == NULL);

      *parent_ptr = node->right;
      node->right->parent = node->parent;
    }
  else
    {
      *parent_ptr = NULL;
    }

  /* apply splay operation */
  if (node->parent != NULL)
    {
      _svmf_tree_splay_$1 (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}

m4svm_define_end v = ":])";
