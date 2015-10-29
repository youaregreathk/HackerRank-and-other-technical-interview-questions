/*****************************************************************************
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

https://leetcode.com/problems/permutations/
****************************************************************************/
class Solution {
public:
    
  void backtracking ( vector<int>& nums,vector<vector<int>>&result,int k,int n){
    if(n==k)
      result.push_back(nums);
         
    for(int i=k;i<=n;i++){
      swap(nums[i],nums[k]);
      backtracking(nums,result,k+1,nums.size()-1);
      swap(nums[k],nums[i]);
    }
  }
    
    
    
  vector<vector<int>> permute(vector<int>& nums) {
    backtracking(nums,result,0,nums.size()-1);
    return result;
  }
private:
  vector<vector<int>> result;
};
