/******************************************************************************
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*******************************************************************************/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
        
    {
      if(prices.size()<=1)
        return 0;
    
      int local_diff=0;
      for(int i=1;i<prices.size();i++)
	{
          if(prices[i]-prices[i-1]>0)
	    local_diff=local_diff+prices[i]-prices[i-1];
	}
      return local_diff;
    }

  }
};

//*****************************************************************************
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int find_max_profit_n(vector<int>&Array)
{
  if(Array.size()<=1)
    return 0;
    
  int local_diff=0;
  for(int i=1;i<Array.size();i++)
    {
      if(Array[i]-Array[i-1]>0)
	local_diff=local_diff+Array[i]-Array[i-1];
    }
  return local_diff;
}
int main() {
  vector<int> Array={100, 180, 260, 310, 40, 535, 695};
    
  cout<<find_max_profit_n(Array);
  return 0;
}
