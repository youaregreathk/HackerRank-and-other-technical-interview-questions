/***************************************************************************
Reverse words in a string
For example
From "I am fine"
to
"fine am I"

Algorithm
Reverse the entire string first
then reverse individual words

***************************************************************************/
#include <iostream>
#include <vector>
using namespace std;


string Reverse(string in,int start,int end){
    
  for(int i=start,j=end;i<=j;i++,j--){
    char tmp=in[i];
    in[i]=in[j];
    in[j]=tmp;
  }
  return in;
}


string Reverse_words(string in){
  int Insize=in.size();
  //Check if the string is empty
  if(Insize==0)
    return in;
  //Reverse the entire string
  in=Reverse(in,0,Insize-1);
  
  //Reverse individual string
    
  int from_index=0;
  for(int i=0;i<Insize;i++){
        
    if(in[i]==' '){
      in=Reverse(in,from_index,i-1);
      from_index=i+1;
    }
  }
    
  in=Reverse(in,from_index,Insize-1);
    
  return in;
}




int main(int argc, const char * argv[]) {
  string yo="Interviews are awesume!";    
  string tmp=Reverse_words(yo);
  cout<<tmp;
    
  return 0;
}
