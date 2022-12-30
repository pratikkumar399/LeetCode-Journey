class Solution {
public:
    int minipath(vector<vector<int>> &dp ,  int i , int j ,int m , vector<vector<int>> &matrix){
        if(j < 0 || j >= m  ) return 1e9 ;
        if(i == 0 )  return matrix[0][j] ;
        
       if(dp[i][j]  != -1) return dp[i][j] ;
        
        int upper = matrix[i][j] +  minipath(dp ,  i - 1 , j ,m ,   matrix)  ;
        int ld  = matrix[i][j] + minipath(dp ,  i - 1 , j- 1 ,m ,   matrix) ;
        int rd = matrix[i][j] + minipath(dp , i - 1 , j + 1 ,m ,  matrix) ;
        
        return dp[i][j] = min(upper ,  min(ld , rd)) ;
    }
  
  
  
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        
        vector<vector<int>>  dp(n , vector<int> (m , -1)) ;
      
        int mini = INT_MAX ;
        for(int i = 0 ; i < m ; i++){
          mini = min(mini , minipath(dp , n-1 , i , m , matrix) );
        }
      
        return mini;
    }
};


//  so the thing is that  the path can be either row , col ,  row  + 1   col + 1 