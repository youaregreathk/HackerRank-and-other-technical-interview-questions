//Pre-order Traversal Root-Left-Right 
void binary_tree::Preorder_print(node*tmp)
{
  if(tmp==NULL)
    return;
  cout<<tmp->item<<" ";
  Preorder_print(tmp->left);
  Preorder_print(tmp->right);
}

//In-order Traversal Left-Root-Right
void binary_tree::Inorder_print(node*tmp)
{
  if(tmp==NULL)
    return;
  Inorder_print(tmp->left);
  cout<<tmp->item<<" ";
  Inorder_print(tmp->right);
}

//Post-order traversal Left-Right-Root
void binary_tree::Postorder_print(node*tmp)
{
  if(tmp==NULL)
    return;
  Postorder_print(tmp->left);
  Postorder_print(tmp->right);
  cout<<tmp->item<<" ";
}
