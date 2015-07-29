void binary_tree::Convert_BST_DLL()
{
  node *head = NULL;
  node *prev = NULL;
    
  BinaryTree2DoubleLinkedList(root, &head, &prev);
    
  while (head!=NULL)
    {
      cout << head->item << endl;
      head = head->right;
    }
 }
   
void binary_tree::Convert_BST_DLL(node *root, node **head, node **prev)
{
  // Base case
  if (root == NULL) 
   return;
    
  // Recursively convert left subtree
  Convert_BST_DLL(root->left, head, prev);
    
  // Now convert this node
  if (*prev == NULL)
    *head = root;
  else
    {
      root->left = *prev;
      (*prev)->right = root;
    }
  *prev = root;
    
  // Finally convert right subtree
  Convert_BST_DLL(root->right, head, prev);
}
