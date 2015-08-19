/************************************************************************************
  4 cases
 1.Both nodes are to the left of the tree.
 2.Both nodes are to the right of the tree.
 3.One node is on the left while the other is on the right.
 4.When the current node equals to either of the two nodes, this node must be the LCA too.
 
 For Case1 the LCA must be on the left subtree, as a result we recursively travel to the left
 
 For Case2 the LCA must be on the lright subtree, as a result we recursively travel to the right
 
 For Case3  we concludes that we have found the LCA.
 
 For Case4 When the current node equals to either of the two nodes, this node must be the LCA too.
 
 The run time complexity is O(h)    h is height of the tree
*****************************************************************************************/
node* binary_tree::LowerestCommonAncestor(int x,int y)
{
  node*tmp1=Binary_search(x);
  node*tmp2=Binary_search(y);
  if(tmp1==NULL || tmp2==NULL)
    return NULL;
  return LowerestCommonAncestor(root,tmp1,tmp2);
}

node* binary_tree::LowerestCommonAncestor(node*root,node* tmp1,node*tmp2)
{
  if(root==NULL)     //Base Case
    return NULL;
    
  if( (tmp1->item>root->item) && (tmp2->item>root->item) )    //Case 1
    return LowerestCommonAncestor(root->right,tmp1,tmp2);
    
  else if( (tmp1->item <root->item) && (tmp2->item<root->item) )  //Case 2
    return LowerestCommonAncestor(root->left,tmp1,tmp2);
  else                         //Case 3 &4
    return root;
}
