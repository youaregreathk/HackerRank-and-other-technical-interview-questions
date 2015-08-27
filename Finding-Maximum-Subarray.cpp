/*****************************************************************************
Given an array A={a1,a2,…,aN} of N elements, find the maximum possible sum of a
https://www.hackerrank.com/challenges/maxsubarray
Contiguous subarray
Non-contiguous (not necessarily contiguous) subarray.

Sample Input

2 
4 
1 2 3 4
6
2 -1 2 3 4 -5
Sample Output

10 10
10 11
*****************************************************************************/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max(int x, int y)
{ return (y > x)? y : x; }

int Max_sub(int* array,int element)
{
  int max_so_far = array[0], i;
  int curr_max = array[0];
    
  for (i = 1; i < element; i++)
    {
      curr_max = max(array[i], curr_max+array[i]);
      max_so_far = max(max_so_far, curr_max);
    }
  return max_so_far;
}

int Max_pov(int* array,int element)
{
  int sum=0;
  for(int i=0;i<element;i++)
    {
      if(array[i]>=0)
	sum+=array[i];
    }
  return sum;
}
int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int numtestcase;
  cin>>numtestcase;
  for(int i=0;i<numtestcase;i++)
    {
      int element;
      cin>>element;
      int array[element];
      for(int j=0;j<element;j++)
	cin>>array[j];
      int tmp=Max_sub(array, element);
      cout<<Max_sub(array, element)<<" ";
      if(tmp<0)
	cout<<tmp<<endl;
      else
        cout<<Max_pov(array, element)<<endl;
        
    }
    
  return 0;
}
