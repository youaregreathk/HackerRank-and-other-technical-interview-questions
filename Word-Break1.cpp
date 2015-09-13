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

/******************************************************************************
Method 2(Dynamic Programming)

We traverse the target word from the first character, it any word in the dictionary matches the target word from the fist character we change the ending index into true and then save it into the array. Then we keep traverse the target wor. We then only look at thoes index which are true we use a for loop to compare the next character with the dictionary. If the last index in the memory array is true, then all the characters in the target word match the dictionart 




 ****************************************************************************/

class Solution {
public:
  bool wordBreak(string s, unordered_set<string>& wordDict) {
    bool *Memoey_array=new bool[s.length()+1] { false }; //Create a boolean array to store
    Memoey_array[0]=true;        //The first index is true, so that we can begin comparing the rest
    for(int i=0;i<s.length();i++)
      {
        if(Memoey_array[i]==false)    //Only process thoese which is true
	  continue;
    
        for( string word: wordDict)
	  {
	    int len= (int)word.length();   
	    int end= i+len;
        
	    if(end>s.length())
	      continue;
        
	    string tmp;
	    tmp=s.substr(i, len);
            if(tmp==word){
	      //cout<<"It is now true "<<end<<endl;
	      Memoey_array[end]=true; //Change the index to true
            
            }
	  }
      }
    return Memoey_array[s.length()];   //If the last index is true then return true
  }
};
