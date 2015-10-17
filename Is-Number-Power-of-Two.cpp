/**************************************************************************
Write 2 functions to determine if a given function is a power of 2 or not

1. Recursive
   Continue to % by2 to see if the result is!=0

2. Straight forward
   


***********************************************************************/
#include <iostream>
using namespace std;


//Recursive
bool IsPowerof2_Recursive(int num){
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
