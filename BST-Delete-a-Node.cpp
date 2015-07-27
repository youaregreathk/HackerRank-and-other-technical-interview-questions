/**********************************************************************************
Remove node Function
 There are 3 cases
 
 1.Node to be removed has no children.
   This case is quite simple. Algorithm sets corresponding link of the parent to NULL and disposes the node.
 
 2.Node to be removed has one child.
   It this case, node is cut from the tree and algorithm links single child (with it's subtree) directly to the parent of the removed node.
 
 3.Node to be removed has two children.
   This is the most complex case. To solve it, let us see one useful BST property first. We are going to use the idea, that the same set of values may be represented as different binary-search trees. For example those BSTs:
 
********************************************************************************/


//A helper funtion finding the parent of a node
node* binary_tree::Parent_node(node*cur,node* root)
{
  if(root==NULL)
    return NULL;
    
  if(root->left==cur||root->right==cur)
    return root;
  else
    {
      if(cur->item<root->item)
	return Parent_node(cur, root->left);
        
      else
	return Parent_node(cur, root->right);
    }
    
}

//A helper funtion that returns the max node
node* binary_tree:: Find_Max_element(node*tmp)
{
  if(tmp->right==NULL)
    return tmp;
  node* max=Find_Max_element(tmp->right);
  return max;
}

bool binary_tree::Remove_node(int value)
{
  if(!Binary_search(value))
    return false;
    
  node*target=Binary_search(value);
    
  //Case 1 Node to be removed has no children
  if(target->left==NULL&&target->right==NULL)
    {
      if(target==root)
	root=NULL;        //If the node to be deleted is the root
      else
        {
	  node*parent=Parent_node(target, root);
	  if(parent->right==target)
	    parent->right=NULL;
	  else
	    parent->left=NULL;
	  delete target;
        }
      return true;
    }
    
  //Case 2 Node to be removed has one child.
  else if(target->left==NULL&&target->right!=NULL)
    {
      if(target==root)
	{
	  root=target->right;
	  delete target;
	}
      else
        {
	  node*parent=Parent_node(target, root);
	  if(parent->left==target)
	    parent->left=target->right;
	  else
	    parent->right=target->right;
	  delete target;
        }
      return true;
    }
    
  else if(target->left!=NULL&&target->right==NULL)
    {
      if(target==root)
        {
	  root=target->left;
	  delete target;
        }
      else
        {
	  node*parent=Parent_node(target, root);
	  if(parent->left==target)
	    parent->left=target->left;
	  else
	    parent->right=target->left;
	  delete target;
        }
      return true;
    }
    
  //Case 3 3.Node to be removed has two children.
  //We first need to find the smallest node in the right subtree or the largest node in the left subtree and then replace the target node with it and then delete the target node. Also we need to set the target's parent node to (left/right)pointer to NULL
  else
    {
      node* Replace_node=Find_Max_element(target->left);
      node*parent=Parent_node(Replace_node, root);
      target->item=Replace_node->item;
      if(parent->right==Replace_node)
	parent->right=NULL;
      else
	parent->left=NULL;
      delete Replace_node;

      return true;
    }
    
  return false;
}
