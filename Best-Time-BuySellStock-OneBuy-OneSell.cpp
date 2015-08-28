/***************************************************************************
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

If array is [2, 3, 10, 6, 4, 8, 1] then returned value should be 8 (Diff between 10 and 2). If array is [ 7, 9, 5, 6, 3, 2 ] then returned value should be 2 (Diff between 7 and 9)

******************************************************************************/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if(prices.size()==0)
      return 0;
    
    int min_element=prices[0];
    int max_diff=prices[1]-prices[0];
    
    for(int i=0;i<prices.size();i++)
      {
        if(prices[i]-min_element> max_diff)
	  max_diff=prices[i]-min_element;
        if(prices[i]<min_element)
	  min_element=prices[i];
      }
    return max_diff;

  }
};

//*****************************************************************************
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_max_profit(vector<int>&Array)
{
  int max_diff=Array[1]-Array[0];
  for(int i=0;i<Array.size();i++)                    //O(n^2)
    {
      for(int j=i+1;j<Array.size();j++)
	{
	  if(Array[j]-Array[i]> max_diff)
            max_diff=Array[j]-Array[i];
	}
    }
  return max_diff;
}

int find_max_profit_n(vector<int>&Array)
{
  if(Array.size()==0)
    return 0;
    
  int min_element=Array[0];
  int max_diff=Array[1]-Array[0];              //O(n)
    
  for(int i=0;i<Array.size();i++)
    {
      if(Array[i]-min_element> max_diff)
	max_diff=Array[i]-min_element;
      if(Array[i]<min_element)
	min_element=Array[i];
    }
  return max_diff;
}
int main() {
  vector<int> Array={2, 3, 10, 6, 4, 8, 1};
    
  cout<<find_max_profit_n(Array);
  return 0;
}
