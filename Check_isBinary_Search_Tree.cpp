/****************************************************************************************
Method 1
This is valid method but not efficient
 
 For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.
***************************************************************************************/

bool
binary_tree::isBinarySearchTree_Method1()
{
  return isBinarySearchTree_Method1(root);
}

bool
binary_tree::isBinarySearchTree_Method1(node*tmp)
{
  if(tmp==NULL)
    return true;
  if(tmp->left!=NULL && Max_element(tmp->left)>tmp->item)
    return false;
  if(tmp->right!=NULL && Min_element(tmp->right)<tmp->item)
    return false;
    
  if(!isBinarySearchTree_Method1(tmp->left)||!isBinarySearchTree_Method1(tmp->right))
    return false;
  return true;
}

/******************************************************************************************
Method 2

Method 2 above runs slowly since it traverses over some parts of the tree many times. A better solution looks at each node only once. The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.

 Time Complexity: O(n)
 Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)

******************************************************************************************/

bool
binary_tree::isBinarySearchTree_Method2()
{
  return isBinarySearchTree_Method2(root,INT_MIN,INT_MAX);
}

bool
binary_tree::isBinarySearchTree_Method2(node*tmp,int min,int max)
{
  if(tmp==NULL)
    return true;
  if(tmp->item>max||tmp->item<min)
    return false;
  if(!isBinarySearchTree_Method2(tmp->left, min, tmp->item-1)&& !isBinarySearchTree_Method2(tmp->right, tmp->item+1, max))
    return false;
       
  return true;
    
}

//Wrong Fuction
bool binary_tree::isBinarySearchTree()
{
  return isBinarySearchTree(root);
}

bool binary_tree::isBinarySearchTree(node*tmp)
{
  if(tmp==NULL)
    return true;
  if(tmp->left!=NULL&&tmp->left->item>tmp->item)
    return false;
  if(tmp->right!=NULL&&tmp->right->item<tmp->item)
    return false;
  if(!isBinarySearchTree(tmp->left)||!isBinarySearchTree(tmp->right))
    return false;
    
  return true;
    
}
