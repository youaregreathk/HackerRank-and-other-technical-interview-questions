/****************************************************************************************
 Find distance between two given keys of a Binary Tree
 
 Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)
 
 The following program find the distance of two nodes in a Binary Tree
***************************************************************************************/
//A helper funtion to find the distance from the root to a certain node
int binary_tree::NodeDistancefromRoot(int x)
{
  return NodeDistancefromRoot(x, root);
}

int binary_tree::NodeDistancefromRoot(int x,node* root)
{
  if(root== NULL)
    return 0;
  int dis=NodeDistancefromRoot(x, root->left)+NodeDistancefromRoot(x, root->right);
  if(root->item==x)
    return 1;
    
  return dis ? ++dis : 0;
}

//Dist(n1, n2) = Dist(root, n1) + Dist(root, n2) - 2*Dist(root, lca)

int binary_tree::TwoNodesDistance(int x, int y)
{
  int dist1=NodeDistancefromRoot(x)-1;
  int dist2=NodeDistancefromRoot(y)-1;
  node*LCA_Node=BinayTree_LowerestCommonAncestor(x,y);
  int distLCA=NodeDistancefromRoot(LCA_Node->item)-1;
  return dist1+dist2-2*distLCA;
}
