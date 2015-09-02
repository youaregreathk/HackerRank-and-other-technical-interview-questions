/***************************************************************************
https://leetcode.com/problems/word-break/

Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

Method 1 (Without Dynamic Programming)    Run time O(n^2)
Approach

First matching words in the dictinary to the string from the beginning of the string.

Once we found a match we break the string and recursively to match the remainning of the string with the dictionary.
If we cannot find any matches than we return back to the previous step

Example "abcde"    ab abc de
We start from ab
then the string "abcde" -> "cde"
but "cde" donot match any words in the dictionry
return back
start from abc
then the string "abcde" -> "de"
we have "de" in the dictionary    return TRUE   
 ***************************************************************************/
//Appoarch 1  Recusion

class Solution {
public:
  bool wordBreakHelper(string s, unordered_set<string>&  dict, int start){
    string tmp;
    if(start == s.length())
      return true;
    
    for(string word: dict){
      int len = (int)a.length();
      int end = start+len;
      //cout<<a<<endl;
      if(end > s.length())
	continue;
       
      tmp=s.substr(start, len);
      if(tmp==word)
	if(wordBreakHelper(s, dict, start+len))
	  return true;
    }
    return false;
  }

  bool wordBreak(string s, unordered_set<string>&   dict) {
    return wordBreakHelper(s, dict, 0);
  }

};


//**************************************************************************

#include <cmath>
#include <cstdio>
#include<string>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


bool wordBreakHelper(string s, unordered_set<string>&  dict, int start){
  string tmp;
  if(start == s.length())
    return true;
    
  for(string word: dict){
    int len = (int)word.length();
    int end = start+len;
    cout<<word<<endl;
    if(end > s.length())
      continue;
       
    tmp=s.substr(start, len);
            
    if(tmp==word)
      {   cout<<"  In"<<endl;
	if(wordBreakHelper(s, dict, start+len))
	  {
	    return true;
	  }
      }
  }
  return false;
}

bool wordBreak(string s, unordered_set<string>&   dict) {
  return wordBreakHelper(s, dict, 0);
}

int main()
{
  unordered_set<string> dict ({"bcc","db","a"});
  wordBreak("bccdba", dict)? cout<<"Yes":cout<<"No";
}
