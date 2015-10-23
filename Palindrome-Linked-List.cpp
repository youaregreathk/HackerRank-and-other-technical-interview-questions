/**************************************************************************
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
*********************************************************************
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
  bool isPalindrome(ListNode* head) {
    if (!head || !head->next) return true;
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *last = slow->next, *pre = head;
    while (last->next) {
      ListNode *tmp = last->next;
      last->next = tmp->next;
      tmp->next = slow->next;
      slow->next = tmp;
    }
    while (slow->next) {
      slow = slow->next;
      if (pre->val != slow->val) return false;
      pre = pre->next;
    }
    return true;
  }

};
