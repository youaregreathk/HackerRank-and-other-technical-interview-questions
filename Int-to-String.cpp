/**************************************************************************
Convert Int to String
For Example
123 to "123"
-321 tp"-321"

***************************************************************************/

#include <iostream>
#include <math.h>
using namespace std;

string InttoString(int in){
  string the_string;
  bool negative_flag=false;
  if(in<0){
    the_string+='-';
    negative_flag=true;
    in=in*-1;
  }
    
  do{
    int tmp=in%10;
    the_string+='0'+tmp;
    in=in/10;
  }while(in!=0);
    
  //Reverse the string
  for(int i=negative_flag==true?1:0,j=the_string.size()-1;i<j;i++,j--){
    char tt=the_string[i];
    the_string[i]=the_string[j];
    the_string[j]=tt;
  }
    
  return the_string;
}

int main(int argc, const char * argv[]) {
  /*
    string in="-123";
    int tmp=StringtoInt(in);
    cout<<tmp;
  */
  int lol=-123;
  string mine=InttoString(lol);
  cout<<mine;
  return 0;
}
