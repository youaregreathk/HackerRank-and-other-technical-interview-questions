/*******************************************************************
Remove Duplicates from Sorted List My Submissions Question Solution 
Total Accepted: 76202 Total Submissions: 219946 Difficulty: Easy
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Remarks
I first thought that inserting a dummy node in the beginning will be easier to solve this problem. I later noticed that there is no need to add a dummy node.

Run time O(n)
*****************************************************************************/

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head) {
  if(head==NULL||head->next==NULL){return head;}
  /*
        int value=head->val-1;
        
        ListNode Dummy_node(value);
        Dummy_node.next=head;
        head=&Dummy_node;              //Create a dummy node
  */
  ListNode*cur=head->next,*prev=head;
  while(cur!=NULL)
    {
      if(prev->val==cur->val&&cur->next==NULL){
	prev->next=NULL;
	break;
      }
      else if(prev->val==cur->val&&cur->next){
	prev->next=cur->next;
	cur=prev->next;
	continue;
      }
      cur=cur->next;
      prev=prev->next;
    }
  return head; //return head->next if we add a dummy node
}
