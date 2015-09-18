/****************************************************************************
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

https://leetcode.com/problems/add-two-numbers/

I did two different solution for this problem
The first one is modified from the second one.
The first one is alot cleaner and more efficient.
The second one is my first attempt to this problem.(Avoid bad programming practice)

The first solution only contains one for loop to iterate throught both of the given linked list

In the situation that one linked list is longer than the other one
ltrl1=ltrl1==NULL?NULL:ltrl1->next
int ptr1_val=ltrl1==NULL?0:ltrl1->val;

We will set that pointer to NULL and its value to 0.
In the original solution I use another for loop to iterate the rest of the linked list which is not necessary.
**************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    if(l1==NULL&&l2==NULL)
      return NULL;
    
    int carry=0;
    ListNode*tail_ptr=NULL;ListNode*head=NULL;ListNode* ltrl2=l2,*ltrl1=l1;
    
    for(; ltrl1!=NULL || ltrl2!=NULL; ltrl1=ltrl1==NULL?NULL:ltrl1->next, ltrl2=ltrl2==NULL?NULL:ltrl2->next)
      {
        int ptr1_val=ltrl1==NULL?0:ltrl1->val;
        int ptr2_val=ltrl2==NULL?0:ltrl2->val;
        
        int tmp_sum=(ptr1_val+ptr2_val+carry)%10;
        carry=(ptr1_val+ptr2_val+carry)/10;
        
        if(head==NULL)             //add note
	  {
            ListNode*tmp=new ListNode(tmp_sum);
            head=tmp;
            tail_ptr=tmp;
	  }
        else{
	  ListNode*tmp=new ListNode(tmp_sum);
	  tail_ptr->next=tmp;
	  tail_ptr= tail_ptr->next;
        }
        
      }
    if(carry==1)
      {
        ListNode*tmp=new ListNode(carry);
        tail_ptr->next=tmp;
        tail_ptr= tail_ptr->next; //This is optional
      }
    
    return head;
  }

};
//*****************************************************************************
//The second solution (Bad programming practise) Review

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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
    if(l1==NULL&&l2==NULL)
      return NULL;
        
    int carry=0;
    ListNode*tail_ptr=NULL;ListNode*  ltrl1=l1; ListNode* ltrl2=l2; ListNode*head=NULL;
        
    for(; ltrl1!=NULL&& ltrl2!=NULL; ltrl1= ltrl1->next, ltrl2= ltrl2->next)
      {
	int tmp_sum=(ltrl1->val+ltrl2->val+carry)%10;
	carry=(ltrl1->val+ltrl2->val+carry)/10;
            
	if(head==NULL)             //add note
	  {
	    ListNode*tmp=new ListNode(tmp_sum);
	    tmp->next=NULL;
	    head=tmp;
	    tail_ptr=tmp;
	  }
	else{
	  ListNode*tmp=new ListNode(tmp_sum);
	  tmp->next=NULL;
	  tail_ptr->next=tmp;
	  tail_ptr= tail_ptr->next;
	}

      }
    ListNode*var=NULL;
        
    if(ltrl1!=NULL){var=ltrl1;}
    else if(ltrl2!=NULL){var=ltrl2;}
    if(var)
      {
	for(;var!=NULL;var=var->next){
	  int tmp_sum=var->val+carry;
	  if(tmp_sum>=10){
	    carry=1;
	    tmp_sum=tmp_sum%10;
	  }
	  else
	    carry=0;
            
	  ListNode*tmp=new ListNode(tmp_sum);
	  tmp->next=NULL;
	  tail_ptr->next=tmp;
	  tail_ptr= tail_ptr->next;
	}
      }
    if(carry==1)
      {
	ListNode*tmp=new ListNode(carry);
	tmp->next=NULL;
	tail_ptr->next=tmp;
	tail_ptr= tail_ptr->next;
      }
        
    return head;
  }
};
