/*****************************************************************************
https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

******************************************************************************/
class Solution {
public:
  bool check_k(stack<char>& left_stack,char target_item)
  {
    if(left_stack.empty())  return false;
    char tmp=left_stack.top();
    if(tmp!=target_item)    return false;
    left_stack.pop();
    return true;
  }

  bool isValid(string s) {
    stack<char> left_stack;

    for(int i=0;i<s.size();i++)
      {
        switch (s[i]) {
	case '(':
	  left_stack.push('(');
	  break;
	case '{':
	  left_stack.push('{');
	  break;
	case '[':
	  left_stack.push('[');
	  break;
        }
	switch(s[i]) {
	case ')': {
	  if(!check_k(left_stack,'('))
	    return false;
	  break;  }
	case '}': {
	  if(!check_k(left_stack,'{'))
	    return false;
	  break; }
	case ']':{
	  if(!check_k(left_stack,'['))
	    return false;
	  break; }
	}
      }
    return left_stack.empty() ? true : false;
  }
};
