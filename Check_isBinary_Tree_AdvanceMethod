/**************************************************************************************
Method 3

 1) Do In-Order Traversal of the given tree and store the result in a temp array.
 3) Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
 
 Time Complexity: O(n)
 
 We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can keep track of previously visited node. If the value of the currently visited node is less than the previous value, then tree is not BST. 
**************************************************************************************/
bool
binary_tree::isBinarySearchTree_Method3()
{
    return isBinarySearchTree_Method3(root);
}

bool
binary_tree::isBinarySearchTree_Method3(node*tmp)
{
    if(tmp==NULL)
        return true;
    
    static node*prev=NULL;  //Using a static variable so that in doing recursion we can keep track of the prev node
    
    if(!isBinarySearchTree_Method3(tmp->left))
        return false;
    if(prev!=NULL&&tmp->item<prev->item)
        return false;
     prev=tmp;
    if(!isBinarySearchTree_Method3(tmp->right))
        return false;
    
    return true;
    
}