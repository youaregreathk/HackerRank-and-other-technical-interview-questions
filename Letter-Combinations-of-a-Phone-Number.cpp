/**************************************************************************
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Algotithm-Backtracking
Death First Search

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
**************************************************************************/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void recursion(string tmp,string a[],vector<string> &result,string digit,int position){
    
  if(position>digit.length()-1){
    result.push_back(tmp);
    return;
  }

  for(int i=0;i<a[digit[position]-'0'].length();i++){
        
    tmp+=a[digit[position]-'0'][i];
    //22     //1       //1
    recursion(tmp,a,result,digit,(int)position+1);
    tmp.pop_back();
 
  }
    
}


vector<string> letterCombinations(string digits) {
  int length=digits.length();
  vector<string> result;
  if(length==0)
    return result;
  string a[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  //cout<<length;
   
  string tmp;
  //a       //2     //1
  recursion(tmp,a,result,digits,0);
  return result;
}




int main(int argc, const char * argv[]) {

  vector<string> re= letterCombinations("2");
  for(int i=0;i<re.size();i++)
    cout<<re[i]<<endl;
    
  return 0;
}
