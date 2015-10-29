/***********************************************************************
This program will print out the element which appears k times in an array.

Remarks
We use hash table (unordered map).
****************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

vector<int> time_occur(int* arr,int k,int size){
  unordered_map<int, int> hash_table;
  vector<int> result;
    
  for(int i=0;i<size;i++){
    auto it = hash_table.find(arr[i]);
    if(it==hash_table.end())
      hash_table.insert(make_pair(arr[i],1));
    else
      hash_table[arr[i]]++;
  }
    
  for(auto kv : hash_table){
    if(kv.second==k)
      result.push_back(kv.first);
  }
  return result;
}
int main(int argc, const char * argv[]) {
  int yolo[]={1,2,4,5,3,6,2,3,4,3,2,5,6,6};
  int size=sizeof(yolo)/sizeof(yolo[0]);
    
  vector<int> res=time_occur(yolo, 3,size);
    
  for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
  return 0;
}
