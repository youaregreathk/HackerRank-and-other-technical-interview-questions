/******************************************************************************
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character

https://leetcode.com/problems/edit-distance/

Time Complexity O(mn)

Remarks
I used dynamic programming to solve this problem

There are 3 operation in this problem.
Insertion
Subtraction
Substitution

The problem can be recursely solvd
E(i,j)

*Case1  if x(i)=y(j)

Ex   EATB
     EBTA
Then it become E(i-1,j-1)
Since no operation has to be done

*Case2 if x(i)!=y(j)  Substitution

Ex   EATB
     EDTC
It become E(i-1,j-1)+1
                  For the substitution operation

Case3 E(i,j)=E(i-1,j)+1  Deletion
Ex   EATY
     EBT
E(4,3) can be converted to E(3,3) in this case

Case4 E(i,j)=E(i,j-1)+1     Insertion
Ex    EAT
      EATS

E(3,4) is converted into E(3,3)

E(i,j)=min { E(i,j-1)+1,E(i-1,j)+1,E(i-1,j-1)+Diff(i,j)}
           Diff=1 if x(i)!=y(j)

*****************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int minn(int a,int b,int c)
{
  if(((a<b)&&(a<c)) || ((a==b)&&(a<c)) || ((a==c)&&(a<b)) || ((a<c)&&(c<b)) || ((b==c)&&(a<b)))
    return a;
    
  else if(((b<a)&&(b<c)) || ((b==a)&&(b<c)) || ((b==c)&&(b<a)) || ((b<c)&&(c<a)) || ((a==c)&&(b<a)))
    return b;
    
  else
    return c;
}

int Edit_distance(string in,string target)
{
  if(in==target)
    return 0;
  int memory_table[target.size()+1][in.size()+1];
  //Fill the first column
    
  for(int i=0;i<target.size()+1;i++)
    memory_table[i][0]=i;
  //fill the first row
  for(int j=0;j<in.size()+1;j++)
    memory_table[0][j]=j;
    
  for(int i=1;i<target.size()+1;i++){
    for(int j=1;j<in.size()+1;j++){
      if(in[j-1]==target[i-1]){
	memory_table[i][j]=memory_table[i-1][j-1];
      }
      else{
	memory_table[i][j]=1+minn(memory_table[i-1][j],memory_table[i][j-1],memory_table[i-1][j-1]);
               
      }
    }
        
  }
  //cout<<memory_table[3][3]<<endl;
    
  return memory_table[target.size()][in.size()];
}



int main(int argc, const char * argv[]) {
  string in= "";
  string target="";
    
  int tmp=Edit_distance(in, target);
  cout<<tmp;


  return 0;
}


