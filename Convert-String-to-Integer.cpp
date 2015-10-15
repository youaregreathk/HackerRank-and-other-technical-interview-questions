/*************************************************************************
Convert String to Integer

For Example
  "123" change to 123
  "-321" change to -321

**********************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

int StringtoInt(string in){
  int the_number;
  int sizeofin=in.size();
  bool flag=true;
    
  if(in[0]=='-')
    flag=false;
        
  for(int i= flag==true ? 0:1 ;i<sizeofin;i++){
    int num=in[i]-'0';
    the_number+=num*pow(10,sizeofin-1-i);
  }
  return flag==true ? the_number:the_number*-1;
}
 

int main(int argc, const char * argv[]) {
  
    string in="-123";
    int tmp=StringtoInt(in);
    cout<<tmp;
  return 0;
}
