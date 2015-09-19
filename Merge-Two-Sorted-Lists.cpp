/*****************************************************************************
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

https://leetcode.com/problems/merge-two-sorted-lists/

*******************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL&&l2==NULL){return NULL;}
    if(l1==NULL&&l2!=NULL){return l2;}
    if(l1!=NULL&&l2==NULL){return l1;}
        
    ListNode*head,*ptr,*itr1=l1,*itr2=l2;
    ListNode*tmp=new ListNode(-1); //Dummy node
    head=tmp;
    ptr=tmp;
    while(itr1!=NULL&&itr2!=NULL){
      int val1=itr1->val;
      int val2=itr2->val;
            
      if(val1<=val2){
	ptr->next=itr1;
	itr1=itr1->next;
      }
      else{
	ptr->next=itr2;
	itr2=itr2->next;
      }
      ptr=ptr->next;
    }
    if(itr2!=NULL)
      ptr->next=itr2;
    else if(itr1!=NULL)
      ptr->next=itr1;
    return head->next;
  }
};
