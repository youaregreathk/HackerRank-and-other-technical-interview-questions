/****************************************************************************
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.


https://leetcode.com/problems/longest-palindromic-substring/

I learnt this algorithm from the following youtube video.
https://www.youtube.com/watch?v=nbTSfrEfo6M

The main concept of this algorithm is that

In the case

L   |   R
 ABABABA
1357531

The symmetric property of the palindrimic string allow us to preditic the next index.

There are three general case
1. In the case
    ----L * | ? R----- 
         ABABABA 
	  *
    If B is a palindromic center and it goes beyond the Left bound
    then the P[?]is Rightbound_index-?(B)=3

2. If B is a palindromic center and it is within the Left bound              
    then the P[?]is = P[mirror]

3. Expand beyond the minimum length from 1&2         


Run time is O(n)

 ****************************************************************************/

class Solution {
public:
  string preProcess(string s) {
    int n = s.length();
    if (n == 0) return "^$";
    string ret = "^";
    for (int i = 0; i < n; i++)
      ret += "#" + s.substr(i, 1);
    
    ret += "#$";
    return ret;
  }

  string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    //int *P = new int[n];
    int P[n];
    int Center = 0;
    int RightBound = 0;
    
    for (int i = 1; i < n-1; i++) {
      int i_mirror = 2*Center-i; // equals to i' = C - (i-C)
        
      if(i<RightBound)         //If it is within the right bound
	P[i]=min(RightBound-i, P[i_mirror]);  //Select the smaller one
      else
	P[i]=0;
        
      // Attempt to expand palindrome centered at i
      while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
	P[i]++;
        
      // If palindrome centered at i expand past R,
      // adjust center based on expanded palindrome.
      if (i + P[i] > RightBound) {
	Center = i;
	RightBound = i + P[i];
      }
    }
    
    // Find the maximum element in P.
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
      if (P[i] > maxLen) {
	maxLen = P[i];
	centerIndex = i;
      }
    }
    
    return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
  }


};

//************************************************************************

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking

// Transform S into T.
// For example, S = "abba", T = "^#a#b#b#a#$".
// ^ and $ signs are sentinels appended to each end to avoid bounds checking
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
    
  ret += "#$";
  return ret;
}

string longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  //int *P = new int[n];
  int P[n];
  int Center = 0;
  int RightBound = 0;
    
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*Center-i; // equals to i' = C - (i-C)
        
    //P[i] = (RightBound > i) ? min(RightBound-i, P[i_mirror]) : 0;
    if(RightBound > i)
      P[i]=min(RightBound-i, P[i_mirror]);
    else
      P[i]=0;
        
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
        
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > RightBound) {
      Center = i;
      RightBound = i + P[i];
    }
  }
    
  // Find the maximum element in P.
  int maxLen = 0;
  int centerIndex = 0;
  for (int i = 1; i < n-1; i++) {
    if (P[i] > maxLen) {
      maxLen = P[i];
      centerIndex = i;
    }
  }
    
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);
}

int main() {
  string in="banana";
  string tmp=longestPalindrome(in);
  cout<<tmp;
    return 0;
}
