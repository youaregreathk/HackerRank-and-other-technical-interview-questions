/**************************************************************************
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

https://leetcode.com/problems/count-and-say/


1,11,21,1211,111221,312211,13112221,1113213211
****************************************************************************/


#include <iostream>
using namespace std;

string number(string s){
  string result;
  int count=1;
  if(s=="1")
    return "11";
  int i=1;
  for(;i<s.size();i++){
    if(s[i]==s[i-1])
      count++;
    else{
      result+=to_string(count)+s[i-1];
      count=1;
    }
  }
    
  if(count>1)
    result+=to_string(count)+s[i-1];
  else{
    
    result+=to_string(count)+s[s.size()-1];
  }
  return result;
}

string countAndSay(int n) {
  string s="1";
  if(n==1)
    return s;
  for(int i=1;i<n;i++)
    {
      s=number(s);
    }
  return s;
}

int main(int argc, const char * argv[]) {
  cout<<countAndSay(5);
  return 0;
}
