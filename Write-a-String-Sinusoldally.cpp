/***************************************************************************
"Hello World!"


 e   _    l
H l o  W r d
   l    o   !

print out: "e_lHloWrdlo!"
*****************************************************************************/

#include <iostream>
using namespace std;

string SnakeString(string s){
  string result;
  if(s.size()==1)
    return s;
    
  for(int i=1;i<s.size();i+=4)   //top row
    result+=s[i];
    
  for(int j=0;j<s.size();j+=2)   //middle row
    result+=s[j];
    
  if(s.size()>=4){
    for(int k=3;k<s.size();k+=4)
      result+=s[k];
  }
  return result;
}

int main(int argc, const char * argv[]) {
  string in="abcd";
    
  cout<<SnakeString(in);
  return 0;
}
