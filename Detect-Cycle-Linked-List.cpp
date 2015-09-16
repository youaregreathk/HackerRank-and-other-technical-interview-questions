/****************************************************************************
Given a linked list, determine if it has a cycle in it.

https://leetcode.com/problems/linked-list-cycle/

We create two pointer fast and slow.The fast one will meet the slow one if there exists a circle.
****************************************************************************/

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
  bool hasCycle(ListNode *head) {
    if(head!=NULL&&head->next==head)
      return true;
    
    ListNode*Fast_ptr=head;
    ListNode*Slow_ptr=head;
     
    while(Fast_ptr!=NULL&&Fast_ptr->next!=NULL)
      {
	Fast_ptr=Fast_ptr->next->next;
	Slow_ptr=Slow_ptr->next;
	if(Fast_ptr==Slow_ptr)
	  return true;
      }
     
    return false;
  }
};
