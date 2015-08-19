/************************************************************************************
https://leetcode.com/problems/invert-binary-tree/
The following problem invert a BinayTree in the following way

       4                 4
      / \               / \
     2   7       to    7   2 
    / \ / \           / \ / \
   1  3 6  9         9  6 3  1

**********************************************************************************/

void
binary_tree::InvertBST()
{
  InvertBST(root);
}



void
binary_tree::InvertBST(node*root)
{
  if(root==NULL)    //Base Case
    return;
    
  InvertBST(root->left);
  InvertBST(root->right);
  node*tmp=root->left;
  root->left=root->right;
  root->right=tmp;
    
}
