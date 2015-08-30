/*******************************************************************************
https://leetcode.com/problems/jump-game/
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
***************************************************************************/
class Solution {
public:
  bool canJump(vector<int>& nums) {
    if(nums[0]==0 && nums.size()>1)
      return false;
    bool zero_flag=false;
    bool flag=true;
    int zero_position

    vector<int> Max_distance;
    
    for(int i=0;i<nums.size()-1;i++)
      {
	if(nums[i]==0)
	  Max_distance.push_back(0);
        else
	  Max_distance.push_back(nums[i]+i);
      }
    
    for(int i=(int)Max_distance.size()-1;i>=0;i--)
      {
        if(Max_distance[i]==0 && !zero_flag)
	  {
            zero_position=i;
            zero_flag=true;
            flag=false;
	  }
        if(zero_flag)
	  { 
	    if(Max_distance[i]>zero_position)
	      {
		cout<<Max_distance[i]+i;
		cout<<endl;
		flag=true;
		zero_flag=false;
	      }
	  }
      }
    return flag ? true:false;
  }
};


