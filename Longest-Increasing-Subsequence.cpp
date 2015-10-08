/****************************************************************************
Find the longest increasing subsequence in an array
For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

Using dynamic programming
 O(n^2)

Algorithm
We iterate through the array using a for loop
and we have an inside for loop to loop through the element
from thestart up to the iterator.
For every note, we need to find the lognest subsequence before that node with its last node in the subsequence smaller than the current node
Ex  3,2,6,4,5,1

We have the memory array.When we are at the node 6, we search for the previous subsequence with longest size and its last node smaller than 6. Since we iterate from the begining. We get 2 and we append the current node to the result and we get 2,6. 
3 2 2
    6

3 2 2 2
    6 4

Same case for 4

3 2 2 2 2
    6 4 4
        5
Now we are at node 5.Since we want the longest previous substring and with its last node last than 5 we have 2,4,5


At last we traverse the entire memory loop to find the longest subsequence and return it.
Reference
http://www.cs.berkeley.edu/~vazirani/algorithms/chap6.pdf
*****************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

vector<int> LongestIncreasing(vector<int>&Arr)
{
  vector<vector<int>> Memory(Arr.size());
  vector<int> finalSequence;
  Memory[0].push_back(Arr[0]);
  for(int i=1;i<Arr.size();i++) {
    for(int j=0;j<i;j++){
      if(Arr[i]>Arr[j]&& Memory[j].size()+1>Memory[i].size())
	Memory[i]=Memory[j];
    }
    Memory[i].push_back(Arr[i]);
  }
  int max_size=Memory[0].size();
  for(int i=0;i<Arr.size();i++){
    if(Memory[i].size()>max_size){
      max_size=Memory[i].size();
      finalSequence=Memory[i];
    }
  }
  return finalSequence;
}


int main(int argc, const char * argv[]) {
  vector<int> yolo {10, 22, 9, 33, 21, 50, 41, 60, 80};
  vector<int>tmp=LongestIncreasing(yolo);
    
  for(int i=0;i<tmp.size();i++)
    cout<<tmp[i]<<" ";
  return 0;
}
