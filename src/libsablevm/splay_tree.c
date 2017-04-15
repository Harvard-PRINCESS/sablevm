/* This file has been automatically generated from "splay_tree.list" */

/*
----------------------------------------------------------------------
_svmf_tree_splay_type
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_type (_svmt_type_node ** proot, _svmt_type_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_type_node *parent = node->parent;
      _svmt_type_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
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
	  _svmt_type_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_type_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_type_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_type_node *A = *node_second;
	  _svmt_type_node *B = *parent_other;

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
	_svmt_type_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_type_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_type_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_type_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_type_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_type_node *A = *node_second;
	_svmt_type_node *B = same ? *parent_other : *node_first;

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
----------------------------------------------------------------------
_svmh_tree_find_type
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_type (_svmt_type_node * value1, _svmt_type_node * value2);

#define _svmm_tree_find_type(root, value) \
_svmh_tree_find_type (&root, value)

svm_static _svmt_type_node * _svmh_tree_find_type (_svmt_type_node ** proot, _svmt_type_node * value)
{
  _svmt_type_node *current = *proot;
  _svmt_type_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_type (value, current);

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
	  _svmf_tree_splay_type (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_type (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_type
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_type(root, value) \
_svmh_tree_insert_type (&root, value)

svm_static void
_svmh_tree_insert_type (_svmt_type_node ** proot, _svmt_type_node * value)
{
  _svmt_type_node **pcurrent = proot;
  _svmt_type_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_type (value, *pcurrent);

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

  _svmf_tree_splay_type (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_type
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_type(root, node) \
_svmh_tree_remove_type (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_type (_svmt_type_node ** proot, _svmt_type_node * node)
{
  _svmt_type_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_type_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_type (proot, next);

      /* the next value is now the root of the tree, so there cannot
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
      _svmt_type_node *parent = node->parent;

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
      _svmf_tree_splay_type (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_gc_map
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_gc_map_node *parent = node->parent;
      _svmt_gc_map_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
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
	  _svmt_gc_map_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_gc_map_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_gc_map_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_gc_map_node *A = *node_second;
	  _svmt_gc_map_node *B = *parent_other;

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
	_svmt_gc_map_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_gc_map_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_gc_map_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_gc_map_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_gc_map_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_gc_map_node *A = *node_second;
	_svmt_gc_map_node *B = same ? *parent_other : *node_first;

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
----------------------------------------------------------------------
_svmh_tree_find_gc_map
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_gc_map (_svmt_gc_map_node * value1, _svmt_gc_map_node * value2);

#define _svmm_tree_find_gc_map(root, value) \
_svmh_tree_find_gc_map (&root, value)

svm_static _svmt_gc_map_node * _svmh_tree_find_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * value)
{
  _svmt_gc_map_node *current = *proot;
  _svmt_gc_map_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_gc_map (value, current);

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
	  _svmf_tree_splay_gc_map (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_gc_map (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_gc_map
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_gc_map(root, value) \
_svmh_tree_insert_gc_map (&root, value)

svm_static void
_svmh_tree_insert_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * value)
{
  _svmt_gc_map_node **pcurrent = proot;
  _svmt_gc_map_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_gc_map (value, *pcurrent);

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

  _svmf_tree_splay_gc_map (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_gc_map
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_gc_map(root, node) \
_svmh_tree_remove_gc_map (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_gc_map (_svmt_gc_map_node ** proot, _svmt_gc_map_node * node)
{
  _svmt_gc_map_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_gc_map_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_gc_map (proot, next);

      /* the next value is now the root of the tree, so there cannot
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
      _svmt_gc_map_node *parent = node->parent;

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
      _svmf_tree_splay_gc_map (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_imethod_signature
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_imethod_signature_node *parent = node->parent;
      _svmt_imethod_signature_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
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
	  _svmt_imethod_signature_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_imethod_signature_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_imethod_signature_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_imethod_signature_node *A = *node_second;
	  _svmt_imethod_signature_node *B = *parent_other;

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
	_svmt_imethod_signature_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_imethod_signature_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_imethod_signature_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_imethod_signature_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_imethod_signature_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_imethod_signature_node *A = *node_second;
	_svmt_imethod_signature_node *B = same ? *parent_other : *node_first;

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
----------------------------------------------------------------------
_svmh_tree_find_imethod_signature
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_imethod_signature (_svmt_imethod_signature_node * value1, _svmt_imethod_signature_node * value2);

#define _svmm_tree_find_imethod_signature(root, value) \
_svmh_tree_find_imethod_signature (&root, value)

svm_static _svmt_imethod_signature_node * _svmh_tree_find_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * value)
{
  _svmt_imethod_signature_node *current = *proot;
  _svmt_imethod_signature_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_imethod_signature (value, current);

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
	  _svmf_tree_splay_imethod_signature (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_imethod_signature (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_imethod_signature
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_imethod_signature(root, value) \
_svmh_tree_insert_imethod_signature (&root, value)

svm_static void
_svmh_tree_insert_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * value)
{
  _svmt_imethod_signature_node **pcurrent = proot;
  _svmt_imethod_signature_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_imethod_signature (value, *pcurrent);

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

  _svmf_tree_splay_imethod_signature (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_imethod_signature
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_imethod_signature(root, node) \
_svmh_tree_remove_imethod_signature (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_imethod_signature (_svmt_imethod_signature_node ** proot, _svmt_imethod_signature_node * node)
{
  _svmt_imethod_signature_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_imethod_signature_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_imethod_signature (proot, next);

      /* the next value is now the root of the tree, so there cannot
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
      _svmt_imethod_signature_node *parent = node->parent;

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
      _svmf_tree_splay_imethod_signature (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}


/*
----------------------------------------------------------------------
_svmf_tree_splay_internal_method
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_internal_method_node *parent = node->parent;
      _svmt_internal_method_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
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
	  _svmt_internal_method_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_internal_method_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_internal_method_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_internal_method_node *A = *node_second;
	  _svmt_internal_method_node *B = *parent_other;

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
	_svmt_internal_method_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_internal_method_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_internal_method_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_internal_method_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_internal_method_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_internal_method_node *A = *node_second;
	_svmt_internal_method_node *B = same ? *parent_other : *node_first;

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
----------------------------------------------------------------------
_svmh_tree_find_internal_method
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_internal_method (_svmt_internal_method_node * value1, _svmt_internal_method_node * value2);

#define _svmm_tree_find_internal_method(root, value) \
_svmh_tree_find_internal_method (&root, value)

svm_static _svmt_internal_method_node * _svmh_tree_find_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * value)
{
  _svmt_internal_method_node *current = *proot;
  _svmt_internal_method_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_internal_method (value, current);

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
	  _svmf_tree_splay_internal_method (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_internal_method (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_internal_method
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_internal_method(root, value) \
_svmh_tree_insert_internal_method (&root, value)

svm_static void
_svmh_tree_insert_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * value)
{
  _svmt_internal_method_node **pcurrent = proot;
  _svmt_internal_method_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_internal_method (value, *pcurrent);

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

  _svmf_tree_splay_internal_method (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_internal_method
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_internal_method(root, node) \
_svmh_tree_remove_internal_method (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_internal_method (_svmt_internal_method_node ** proot, _svmt_internal_method_node * node)
{
  _svmt_internal_method_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_internal_method_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_internal_method (proot, next);

      /* the next value is now the root of the tree, so there cannot
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
      _svmt_internal_method_node *parent = node->parent;

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
      _svmf_tree_splay_internal_method (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}


#if defined (_SABLEVM_INLINED_THREADED_INTERPRETER)

/*
----------------------------------------------------------------------
_svmf_tree_splay_sequence
----------------------------------------------------------------------
*/

inline svm_static void
_svmf_tree_splay_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  assert (node != NULL);

  while (1)
    {
      _svmt_sequence_node *parent = node->parent;
      _svmt_sequence_node *grand_parent = (parent == NULL) ? NULL : parent->parent;
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
	  _svmt_sequence_node **node_second =
	    is_left_parent_child ? &node->right : &node->left;
	  _svmt_sequence_node **parent_this =
	    is_left_parent_child ? &parent->left : &parent->right;
	  _svmt_sequence_node **parent_other =
	    is_left_parent_child ? &parent->right : &parent->left;

	  _svmt_sequence_node *A = *node_second;
	  _svmt_sequence_node *B = *parent_other;

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
	_svmt_sequence_node **node_first = is_left_parent_child ? &node->left : &node->right;
	_svmt_sequence_node **node_second = is_left_parent_child ? &node->right : &node->left;
	_svmt_sequence_node **parent_this =
	  is_left_parent_child ? &parent->left : &parent->right;
	_svmt_sequence_node **parent_other =
	  is_left_parent_child ? &parent->right : &parent->left;
	_svmt_sequence_node **grand_parent_this =
	  is_left_grand_parent_child ? &grand_parent->left
	  : &grand_parent->right;

	jint same = is_left_parent_child == is_left_grand_parent_child;

	_svmt_sequence_node *A = *node_second;
	_svmt_sequence_node *B = same ? *parent_other : *node_first;

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
----------------------------------------------------------------------
_svmh_tree_find_sequence
----------------------------------------------------------------------
*/

/* prototype for comparison function */
inline svm_static jint _svmf_tree_compare_sequence (_svmt_sequence_node * value1, _svmt_sequence_node * value2);

#define _svmm_tree_find_sequence(root, value) \
_svmh_tree_find_sequence (&root, value)

svm_static _svmt_sequence_node * _svmh_tree_find_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node *current = *proot;
  _svmt_sequence_node *last = NULL;

  assert (value != NULL);

  while (current != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence (value, current);

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
	  _svmf_tree_splay_sequence (proot, current);
	  return current;
	}
    }

  if (last != NULL)
    {
      _svmf_tree_splay_sequence (proot, last);
    }

  return NULL;
}

/*
----------------------------------------------------------------------
_svmh_tree_insert_sequence
----------------------------------------------------------------------
*/

#define _svmm_tree_insert_sequence(root, value) \
_svmh_tree_insert_sequence (&root, value)

svm_static void
_svmh_tree_insert_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * value)
{
  _svmt_sequence_node **pcurrent = proot;
  _svmt_sequence_node *parent = NULL;

  assert (value != NULL);

  while (*pcurrent != NULL)
    {
      jint comparison = _svmf_tree_compare_sequence (value, *pcurrent);

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

  _svmf_tree_splay_sequence (proot, value);
}

/*
----------------------------------------------------------------------
_svmh_tree_remove_sequence
----------------------------------------------------------------------
*/

#define _svmm_tree_remove_sequence(root, node) \
_svmh_tree_remove_sequence (&root, node)

svm_static void SVM_UNUSED
_svmh_tree_remove_sequence (_svmt_sequence_node ** proot, _svmt_sequence_node * node)
{
  _svmt_sequence_node **parent_ptr;

  assert (node != NULL);

  /* make sure one of the two children is null */
  if (node->left != NULL && node->right != NULL)
    {
      _svmt_sequence_node *next = node->right;

      while (next->left != NULL)
	{
	  next = next->left;
	}

      /* splay will make "next" root of the tree */
      _svmf_tree_splay_sequence (proot, next);

      /* the next value is now the root of the tree, so there cannot
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
      _svmt_sequence_node *parent = node->parent;

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
      _svmf_tree_splay_sequence (proot, node->parent);
    }

  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
}


#endif /* _SABLEVM_INLINED_THREADED_INTERPRETER */
