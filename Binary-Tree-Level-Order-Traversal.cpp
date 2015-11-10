/***************************************************************************
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

https://leetcode.com/problems/binary-tree-level-order-traversal/


Remarks:
To solve this problem I used two vector to store the current level and the next level node.

******************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if(!root) return result;
    vector<TreeNode*> q;
    vector<TreeNode*> nextlevel;
        
    vector<int> level_result;
    q.push_back(root);
        
    while(!q.empty()){
      for(int i=0;i<q.size();i++){
	level_result.push_back(q[i]->val);
	if(q[i]->left!=NULL)
	  nextlevel.push_back(q[i]->left);
	if(q[i]->right!=NULL)
	  nextlevel.push_back(q[i]->right);
      }
        
      result.push_back(level_result);
      level_result.clear();
      swap(q,nextlevel);
      nextlevel.clear();
    }
        
    return result;
  }


};
