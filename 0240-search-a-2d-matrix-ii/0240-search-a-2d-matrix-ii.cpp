class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      // from observation we observe that if we take a particular element then the element in the next row is greater to it and the element in its left is smaller than it 
          int n = matrix.size() ;
          int m = matrix[0].size() - 1;
          int row = 0 ;
      // row increases till n and col decreases till 0 
          while(row < n && m > -1){
            int curr = matrix[row][m] ;
            if(curr == target) return true  ;
             if(curr < target) row++ ;
             else {
               m-- ;
             }  
          }
         return false ;
    }
};
