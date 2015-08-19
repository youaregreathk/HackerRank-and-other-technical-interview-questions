/************************************************************************************
 Lowest Common Ancestor for a Binary Tree (Different from a Binary Search Tree....More 
complicated)

Using a bottom-up approach, we can improve over the top-down approach by avoiding traversing the same nodes over and over again.

We first travel from the bottom and once we reah a node that matches one of the two target nodes, we pass it up to its parent. The parent will then test its left and right subtree if each contain one of the two nodes, it is the LCA. And we will pass it up to the root. If not we pass the lower node to its parent and continue to compare the left and right subtree until both match

Worst case O(n)
****************************************************************************************/

node* binary_tree::BinayTree_LowerestCommonAncestor(int x,int y)
{
  node*tmp1=Binary_search(x);
  node*tmp2=Binary_search(y);
  if(tmp1==NULL || tmp2==NULL)
    return NULL;
  return LowerestCommonAncestor(root,tmp1,tmp2);
}


node* binary_tree::BinayTree_LowerestCommonAncestor(node*root,node* tmp1,node*tmp2)
{
  if(root==NULL)
    return NULL;
  if(root == tmp1 || root == tmp2)    //return when the current node is one of the target node
    return root;
    
  node*left=BinayTree_LowerestCommonAncestor(root->left,tmp1,tmp2);   
  node*right=BinayTree_LowerestCommonAncestor(root->right,tmp1,tmp2);

  if(left && right)           //If each subtree  contain one of the two nodes
    return root;              //The current node is the LCA, return it to the top
  if (left)                   //If the target node is in the left subtree return it to its parent
    return left;
  else
    return right;            //If the target node is in the right subtree return it to its par \
ent                            
}








