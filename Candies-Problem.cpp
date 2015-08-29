/***************************************************************************
https://www.hackerrank.com/challenges/candies
Problem Statement

Alice is a kindergarden teacher. She wants to give some candies to the children in her class.  All the children sit in a line, and each  of them has a rating score according to his or her performance in the class.  Alice wants to give at least 1 candy to each child. If two children sit next to each other, then the one with the higher rating must get more candies. Alice wants to save money, so she needs to minimize the total number of candies.
*****************************************************************************/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    
  int NumberOfTestCase;
  cin>>NumberOfTestCase;
    
  vector<int> student(NumberOfTestCase);    //vector for input
  vector<int> candy(NumberOfTestCase,1);      //vector for candy initailize to 1 in the beginning
    
  for(int i=0;i<NumberOfTestCase;i++)
    {
      cin>>student[i];
    }
    
  for(int i=1;i< NumberOfTestCase;i++)    //Forward
    {
      if(student[i]>student[i-1])
        {
	  candy[i]=candy[i-1]+1;
        }
    }
    
  for(int i=NumberOfTestCase-1;i>0;i--)   //Backward
    {
      if(student[i-1]>student[i])
        {
	  if(candy[i-1]<=candy[i])
            candy[i-1]=candy[i]+1;
        }
    }

    
  int total_candy=0;
  for(int i=0;i<NumberOfTestCase;i++)
    {
        
      total_candy+=candy[i];
    }
  cout<<total_candy;
  return 0;
}
