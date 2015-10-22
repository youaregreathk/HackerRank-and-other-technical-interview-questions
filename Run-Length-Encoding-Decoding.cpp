/*************************************************************************

Run code Encoding 
"aaaabcccaa" to "4a1b3c2a"
Run code Decoding
"4a1b3c2a" to "aaaabcccaa"

*****************************************************************************/
#include <iostream>
using namespace std;

string Run_Lenght_Encoding(string s)  //"aaaabcccaa"  to  "4a1b3c2a"
{
  string result;
  if(s.size()==1){
    result= '1'+s[0];
    return result;
  }
  int count=1;
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1])
      count++;
    else{
      result+=to_string(count)+s[i-1];
      count=1;
    }
  }
  result+=to_string(count)+s[s.size()-1];
  return result;
}

string Run_Lenght_Decoding(string s){  //"4a1b3c2a" to "aaaabcccaa"
  string result;
  for(int i=1;i<s.size();i+=2){
    int count=s[i-1]-'0';
    result.append(count,s[i]);
  }
  return result;
}

int main(int argc, const char * argv[]) {
  //string in="aaaabcccaa";
  //cout<<Run_Lenght_Encoding(in);
  string in="1a1b4b5h6j7k";
  cout<<Run_Lenght_Decoding(in);
  return 0;
}
