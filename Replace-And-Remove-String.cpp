/***************************************************************************
We want to remove all the 'b' in a given string and convert all the 'a'\ 
in the string into 'dd'

For example: "egahbke"
will become "egddhke"

First step we move all the character witout b forward
so egahbke will become egahkee
Forward for loop

Second step we will do a backward for loop to 
replace all the a into dd
******************************************************************************/


#include <iostream>
using namespace std;

string ReplaceString(string s){
  int num_a=0;
  int reg_size=0;
    
  for(int i=0;i<s.size();i++){
    if(s[i]!='b'){
      s[reg_size]=s[i];
      reg_size++;
            
      if(s[i]=='a')
	num_a++;
    }
  }
  int total_size=reg_size+num_a;
  s.resize(total_size);
  int start_index=reg_size-1;
    
  for(int i=total_size-1;i>=0;i--){
        
    if(s[start_index]!='a'){
      s[i]=s[start_index];
      start_index--;
    }
    else if(s[start_index]=='a'){
      s[i]='d';
      s[i-1]='d';
      start_index--;
      i--;
    }
  }
  return s;
}

int main(int argc, const char * argv[]) {
  string tmp="aaefgbw";
  string yo=ReplaceString(tmp);
  cout<<yo;
  return 0;
}
