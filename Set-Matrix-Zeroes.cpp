/**************************************************************************
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

https://leetcode.com/problems/set-matrix-zeroes/
****************************************************************************/

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    bool firstRowZero=false;
    bool firstColumnZero=false;
    
    //if first Column contains any zero then set the bool variable to true
    for(int i=0;i<matrix.size();i++){
      if(matrix[i][0]==0){
	firstColumnZero=true;
	break;
      }
    }
    
    //if first Column contains any zero then set the bool variable to true
    for(int i=0;i<matrix[0].size();i++){
      if(matrix[0][i]==0){
	firstRowZero=true;
	break;
      }
    }
    
    //If any element in the matrix is 0, change the corrisponding 0th row element and 0th column element to zero (like using DP indicating it)
    
    for(int i=1;i<matrix.size();i++){
      for(int j=1;j<matrix[0].size();j++)
        {
	  if(matrix[i][j]==0){
	    matrix[i][0]=0;
	    matrix[0][j]=0;
	  }
        }
    }
    
    //Oberverse the 0 element in the first row and first Column, turn all its row and column into 0
    
    for(int i=1;i<matrix.size();i++){
      for(int j=1;j<matrix[0].size();j++)
        {
	  if(matrix[i][0]==0||matrix[0][j]==0)
            {
	      matrix[i][j]=0;
            }
        }
    }
    
    //set column to all 0 if Columncontain0 is true
    if(firstColumnZero)
      {
        for(int i=0;i<matrix.size();i++)
	  {
            matrix[i][0]=0;
	  }
      }
    //set column to all 0 if Rpecontain0 is true
    if(firstRowZero)
      {
        for(int i=0;i<matrix[0].size();i++)
	  {
            matrix[0][i]=0;
	  }
      }
    
  }


};
