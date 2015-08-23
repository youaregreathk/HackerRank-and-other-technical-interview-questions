/****************************************************************************
Problem Statement

Mark and Jane are very happy after having their first kid. Their son is very fond of toys, so Mark wants to buy some. There are N different toys lying in front of him, tagged with their prices, but he has only $K. He wants to maximize the number of toys he buys with this money.

  Now, you are Mark's best friend and have to help him buy as many toys as possible.

Input Format 
The first line contains two integers, N and K, followed by a line containing N space separated integers indicating the products' prices.

Output Format 
An integer that denotes maximum number of toys Mark can buy for his son.

Constraints 
1<=N<=105 
1<=K<=109 
1<=price of any toy<=109 
A toy can't be bought multiple times.

Sample Input

7 50
1 12 5 111 200 1000 10
Sample Output

4
Explanation

He can buy only 4 toys at most. These toys have the following prices: 1,12,5,10.
*****************************************************************************/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;



int main()
{
  long long n, k; cin >> n >> k;
  vector<int> prices;
  for(int i = 0; i < n; i++)
    {
      int p; cin >> p;
      prices.push_back(p);
    }
    
  int answer = 0;
  sort(prices.begin(),prices.end());
    
  int sum=0;
  for(int i=0;i<n;i++)
    {
      sum+=prices[i];
      ++answer;
      if(sum>k)
        {
	  --answer;
	  break;
        }
    }
    
    
  cout << answer << endl;
    
  return 0;
}


//Time Complexity: O(N logN)
