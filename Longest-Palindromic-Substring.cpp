/**************************************************************************
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

https://leetcode.com/problems/longest-palindromic-substring/


Method 1 Using Dynamic Programming
In the following method, we first create a 2D bool array for storing the result of smaller size palindromic substring and then using buttom up appoach to find larger size palindromic substring
 We consider the palindromic substring into 3 cases, 
Case 1 Every character is a palindromic substring itself. We use a for loop to store the result example Memory[0][0], Memory[1][1] is true;

Case 2 We want to find all the palindromic substring with size of 2 character, we use if(s[i]==s[i+1]) to check if the next character is equal to itself

Case 3 For palindromic substring size larger or equal to 3, We use the previous result to check if Momory[Start_index+1][End_index-1] and if string[Start_index]==string[End_index]. The two above condition must be true for a palindromic substring.

The runtime for the above method is O(n power 2)


*************************************************************************************************/
class Solution {
public:
  string longestPalindrome(string s) {
    bool Memory_table[s.length()][s.length()];
    int Max_length;
    int start_index;
    
    for(int i=0;i<s.length();i++)
      {
        for(int j=0;j<s.length();j++)
	  {
            Memory_table[i][j]=false;
	  }
      }
    
    //int n=(int)s.length();
    int n=s.length();
    //For length is 1, it self is always a Palindromic string for one character
    for(int i=0;i<n;i++)
      Memory_table[i][i]=true;
    
    //For Palindromic substring which size is 2    
    for(int i=0;i<n-1;i++)
      {
        if(s[i]==s[i+1])
	  {
            Memory_table[i][i+1]=true;
            start_index=i;
            Max_length=2;
	  }
      }
    //For length greater than 2 characher, to check if it is a Palindromic string
    
    for(int k=3;k<=n;k++)
      {
        
        for(int i=0;i<n-k+1;i++)
	  {
            int end_index=i+k-1;
            if(Memory_table[i+1][end_index-1] && s[i]==s[end_index])
	      {
                Memory_table[i][end_index]=true;
                if(k>Max_length)
		  {
		    start_index=i;
		    Max_length=k;
		  }
	      }
	  }
      }
    
    return s.substr(start_index,Max_length);
  }

};

//*********************************************************************************************************************************

#include <iostream>
using namespace std;



string longestPalindrome(string s) {
    
  int const size=s.length();
  bool Memory_table[size][size];
  int Max_length;
  int start_index;
  for(int i=0;i<s.length();i++)
    {
      for(int j=0;j<s.length();j++)
        {
	  Memory_table[i][j]=false;
        }
    }
  int n=s.length();
  //For length is 1, it self is always a Palindromic string for one character
  for(int i=0;i<n;i++)
    Memory_table[i][i]=true;
    
  for(int i=0;i<n-1;i++)
    {
      if(s[i]==s[i+1])
        {
	  Memory_table[i][i+1]=true;
	  start_index=i;
	  Max_length=2;
        }
    }
  //For length greater than 2 characher, to check if it is a Palindromic string
    
  for(int k=3;k<=n;k++)
    {
        
      for(int i=0;i<n-k+1;i++)
        {
	  int end_index=i+k-1;
	  if(Memory_table[i+1][end_index-1] && s[i]==s[end_index])
            {
	      Memory_table[i][end_index]=true;
	      if(k>Max_length)
                {
		  start_index=i;
		  Max_length=k;
                }
            }
        }
    }
     
  return s.substr(start_index,Max_length);
}


int main(int argc, const char * argv[]) {
    
  string tmp=longestPalindrome("aaabaaaaa");
  cout<<tmp;
  return 0;
}
