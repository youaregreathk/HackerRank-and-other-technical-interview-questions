/*************************************************************************
Reverse a singly linked list.   (Review needed)
https://leetcode.com/problems/reverse-linked-list/

In this problem
Ex head->1->2->3->4->5

* This is an easy question, but supprisingly it took me a while to solve it.*

I spent a lot of time figuring out how to implement the next pointer(tmp)of the cur pointer. In the situation that the cur pointer is at 4 the next pointer will be pointing at 5 and in my original  code cur=tmp(the next pointer) after exexcuting this line of code the loop stop since my loop condition is (cur->next!=NULL). The cur pointer is pointing at 5, but its cur->next is not set.
    It took me a while to figure out that ater the while loop, I need to connect the cur pointer (node 5) to the rest of the linked list
The line cur->next=prev; outside the while loop solved this problem.

Later I figured out that, we can change the loop condition to (cur!=NULL)
This implementation is alot easier. We dont have to consider the consern above.
we just need to add few lines to check the next pointer of the cur pointer inside the while loop
The line
tmp=cur->next;
...
if(tmp!=NULL)
cur=tmp;
else
break;

These few lines check the condition that if the cur is pointer to the last node and its next pointer(tmp) in this case will be pointing to NULL pointer.





************************************************************************/
//Iterative solution
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
  ListNode* reverseList(ListNode* head) {
    if(head==NULL||head->next==NULL){return head;}
        
    ListNode*cur=head->next,*prev=head,*tmp,*fix=head;
    while(cur->next!=NULL){   //stop at 4
      tmp=cur->next;    //tmp can point to 5
      cur->next=prev;
      prev=cur;
      cur=tmp;
    }
    cur->next=prev;
    head=cur;
    fix->next=NULL;
    return head;
  }
};

//Better solution

ListNode* reverseList(ListNode* head) {
  if(head==NULL||head->next==NULL){return head;}
    
  ListNode*cur=head->next,*prev=head,*tmp;
  head->next=NULL;
  while(cur!=NULL){   //stop at 4
    tmp=cur->next;    //tmp can point to 5
    cur->next=prev;
    prev=cur;
    if(tmp!=NULL)
      cur=tmp;
    else
      break;
  }
  head=cur;
  return head;
}
//*****************************************************************************
//Recursive Solution
//(Review needed)
class Solution {
public:
  //In the case head->1->2->3->4->5
  ListNode* reverseList(ListNode* head)   //Recursive Solution
  {
    if(head==NULL)
      return NULL;
    if(head->next==NULL)
      return head;

    ListNode* tmp=head->next;
    head->next=NULL;
    //tmp->next=head;//Cannot put here otherwise infinite loop
    ListNode*result=reverseList(tmp);    //Go to the the end at 5
   
    tmp->next=head;               //From 5 go back to 1
    return result;                 //Always pass back 5
  }

    
};
