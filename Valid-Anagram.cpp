/***************************************************************************
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

https://leetcode.com/problems/valid-anagram/
*****************************************************************************/

#include <iostream>
using namespace std;

bool isAnagram(string s, string t) {
  int table[26]={0};
  for(int i=0;i<s.size();i++){
    char tmp=s[i];
    table[tmp-'a']++;
  }
    
  for(int i=0;i<t.size();i++){
    char tm=t[i];
    table[tm-'a']--;
  }
    
  for(int i=0;i<26;i++){
    if(table[i]!=0)
      return false;
  }
  return true;
}

int main(int argc, const char * argv[]) {
  string s = "anagram", t = "nagaram";
  if(isAnagram(s,t))
    cout<<"yes";
  else
    cout<<"NO";
  return 0;
}
