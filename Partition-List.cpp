/******************************************************************************
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

https://leetcode.com/problems/partition-list/

Remarks
I used two pointers cur and prev for this problem. In my  first soltion I solve the problem through two cases, 
case 1 the node which head is pointer is greater than or equal to x (the first node)
case 2 the node which is not the first node is greater than or equal to x

I use two if statement inside the while loop to take care this two case. But when testing in leetcode, it shows that time exceed.

Then I improve my solution by first inserting a dummy variable which value is smaller than x. Then I no longer have to implement the code for case 1. The code become simpler and more efficient and also pass the time requirement in leetcode.

******************************************************************************/
//My first solution which dont pass the time requirement in leetcode
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 

    ListNode* partition(ListNode* head, int x) {
        //The case where there are no node in the linked list or only have one node in the linked list
        if(head==NULL ||head->next==NULL){return head;}
        ListNode*tail_ptr=head,*prev_ptr=head,*cur_ptr=head->next,*fixedEnd_ptr;
        for(;tail_ptr->next!=NULL;tail_ptr=tail_ptr->next){}
            //After this line the tail_ptr is pointing to the last node in the linked list
        fixedEnd_ptr=tail_ptr;   //fixedEnd_ptr is pointing to the end of the original linked list before any rearrangment
        //for(;cur_ptr!=fixedEnd_ptr;cur_ptr=cur_ptr->next,prev_ptr=prev_ptr->next)
        while(cur_ptr!=fixedEnd_ptr)
        {
            //case 1 the first node is greater than x
            if(head->val>=x)
            {
                tail_ptr->next=head;
                head->next=NULL;
                head=cur_ptr;
                prev_ptr=cur_ptr;
                cur_ptr=cur_ptr->next;
                tail_ptr=tail_ptr->next;
                continue;
            }
            //case 2 the node is not the first node in the list and is greater or equal to x
            if(cur_ptr->val>=x)
            {
                tail_ptr->next=cur_ptr;
                cur_ptr=cur_ptr->next;
                prev_ptr->next=cur_ptr;
                tail_ptr=tail_ptr->next;
                tail_ptr->next=NULL;
                continue;
            }
            cur_ptr=cur_ptr->next;
            prev_ptr=prev_ptr->next;
        }
        if(tail_ptr!=fixedEnd_ptr)   //If tail_ptr==fixed_ptr means that no node is greater or equal to the x number and even if the last node is greater or equal to the number we dont have to move it.
            
        {//cur is now pointing to the fixed node
          if(cur_ptr->val>=x)
          {
              tail_ptr->next=cur_ptr;   //or fixed_pointer
              prev_ptr->next=cur_ptr->next;
              cur_ptr->next=NULL;
          }
            
            if(head->val>=x){
                tail_ptr->next=head;
                head=cur_ptr;}
        }
        return head;
    }

//****************************************************************************
//My second solution which passes the time requirement in leetcode
ListNode* partition(ListNode* head, int x) {
    
  if(head==NULL ||head->next==NULL){return head;}
    
  int y=x-1;
  ListNode dummy_node(y);
  dummy_node.next=head;
  head=&dummy_node;         //create a dummy node for convinient
    
  ListNode*tail_ptr=head,*prev_ptr=head,*cur_ptr=head->next,*fixedEnd_ptr;
    
  for(;tail_ptr->next!=NULL;tail_ptr=tail_ptr->next){}
    
  fixedEnd_ptr=tail_ptr;
    
  while(cur_ptr!=fixedEnd_ptr)
    {
      if(cur_ptr->val>=x)
        {
	  tail_ptr->next=cur_ptr;
	  cur_ptr=cur_ptr->next;
	  prev_ptr->next=cur_ptr;
	  tail_ptr=tail_ptr->next;
	  tail_ptr->next=NULL;
	  continue;
        }
      cur_ptr=cur_ptr->next;
      prev_ptr=prev_ptr->next;
    }
  if(tail_ptr!=fixedEnd_ptr)   //If tail_ptr==fixed_ptr means that no node is greater or equal to the x number and even if the last node is greater or equal to the number we dont have to move it.
        
    {//cur is now pointing to the fixed node
      if(cur_ptr->val>=x)
        {
	  tail_ptr->next=cur_ptr;   //or fixed_pointer
	  prev_ptr->next=cur_ptr->next;
	  cur_ptr->next=NULL;
        }
        
    }
  return head->next;
}

