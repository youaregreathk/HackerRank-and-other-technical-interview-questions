/**************************************************************************
Write 2 functions to determine if a given function is a power of 2 or not
Given an integer, write a function to determine if it is a power of two.

1. Recursive
   Continue to % by2 to see if the result is!=0

2. Straight forward
   
https://leetcode.com/problems/power-of-two/

***********************************************************************/
#include <iostream>
using namespace std;


//Recursive
bool IsPowerof2_Recursive(int num){
  if(num==0)
    return false;
  if(num==1){
    //cout<<"YO";
    return true;
  }
  if(num%2!=0){
    return false;
  }
   
    
  return IsPowerof2_Recursive(num/=2);
    
}
//Non Recursive
bool IsPowerof2_NonRecursive(int num){
  bool flag=true;
  do{
    int tmp=num%2;
    //cout<<tmp<<endl;
    if(tmp!=0){
      //cout<<"Yo"<<" "<<tmp<<endl;
      flag=false;
    }
    num/=2;
        
        
  }while(num!=1);
    
  return flag;
}


int main(int argc, const char * argv[]) {
  if(IsPowerof2_NonRecursive(8))
    cout<<"Yes";
  else
    cout<<"No";
  return 0;
}
