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
        
        // vector<vector<int>>  dp(n , vector<int> (m , -1)) ;
        vector<vector<int>>  dp(n , vector<int> (m , 0)) ;
      
      for(int i = 0 ; i < m ; i++){
        dp[0][i] = matrix[0][i] ; 
      }
      
      for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j< m ; j++){
          int up =  matrix[i][j] + dp[i-1][j] ;
          
          int ld =  matrix[i][j] ;
          if(j-1 >= 0) {
             ld += dp[i-1][j-1] ;
          }
          else {
            ld+= 1e9 ;
          }
          
          int rd =  matrix[i][j] ;
          if(j+1 < m ) {
             rd += dp[i-1][j+1] ;
          }
          else {
            rd+= 1e9 ;
          }
          
          dp[i][j] = min(up , min(ld, rd)) ;
        }
      }
        int mini = INT_MAX ;
        for(int i = 0 ; i < m ; i++){
          mini = min(mini , dp[n-1][i] );
        }
      
        return mini;
    }
};


//  so the thing is that  the path can be either row , col ,  row  + 1   col + 1 