class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size() ;
          int m = matrix[0].size() - 1;
          int row = 0 ;
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