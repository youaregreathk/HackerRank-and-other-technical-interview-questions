/*************************************************************************
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

Remarks
We use few for loop to traverse the entire Sequence to keep checking if it is valid

https://leetcode.com/problems/restore-ip-addresses/
*****************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsValid(string s){
  if(s.size()>3)
    return false;
    
  if(s[0]=='0'&& s.size()>1)
    return false;
    
  int value= stoi(s);
  if(value<=0 || value>=255)
    return false;
    
  return true;
}

vector<string> restoreIpAddresses(string s) {
  vector<string> result;
  for(int i=1;i<4&&i<s.size();i++){
    string tmp1=s.substr(0,i);   //substring function second character is the number of characters
    if(IsValid(tmp1)){
            
      for(int j=1;j<4&&i+j<s.size();j++){
	string tmp2=s.substr(i,j);
	if(IsValid(tmp2)){
	  for(int k=1;k<4&&i+j+k<s.size();k++){
	    string tmp3=s.substr(i+j,k);
	    string tmp4=s.substr(i+j+k);
	    if(IsValid(tmp3)&&IsValid(tmp4))
	      result.push_back(tmp1+"."+tmp2+"."+tmp3+"."+tmp4);
	  }
	}
      }
    }
  }
  return result;
}
    
int main()
{
  string yolo="19216811";
  vector<string> ans=restoreIpAddresses(yolo);
        
  for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<endl;
}
