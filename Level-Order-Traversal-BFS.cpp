void binary_tree::level_print(node*tmp)
{
  queue<node*> q;
  q.push(tmp);
    
  while(!q.empty())
    {
      node*ptr=q.front();
      cout<<ptr->item<<" ";
      q.pop();
        
      if(ptr->left!=NULL)
	q.push(ptr->left);
        
      if(ptr->right!=NULL)
	q.push(ptr->right);
    }
    
}
