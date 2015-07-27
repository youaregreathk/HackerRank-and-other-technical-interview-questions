int binary_tree::Max_element(node*tmp)
{
  if(tmp->right==NULL)
    return tmp->item;
  int max=Max_element(tmp->right);
  return max;
}

int binary_tree::Find_Second_Largest()
{
  int largest=Max_element();
  node*tmp=root;
  node*ptr=Binary_search(largest);
    
  //case 1 The largest value does not have a left subtree
  if(ptr->left==NULL)
    {
      while(tmp->right!=ptr)
	tmp=tmp->right;
      return tmp->item;
    }
    
  //case 2 the largest value does has a left subtree
  else{
    //node*itr=ptr->left;                 //This also works
    //while(itr->right!=NULL)
    //  itr=itr->right;
    return Max_element(ptr->left);
  }
    
}
