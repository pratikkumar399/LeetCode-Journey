class Solution {
public:
  
    int unique(int i ,  int j ,  vector<vector<int>> &dp){
        
      if(i == 0 && j == 0) return  1 ;
      
      if(i < 0 || j < 0) return 0 ;
      
      if(dp[i][j] != -1) return dp[i][j] ;
      
      int left = unique(i-1, j  , dp) ;
      int right = unique(i,j-1 , dp) ;
      
      return dp[i][j] = left + right ;
    }
  
  
  
  
    int uniquePaths(int m, int n) {
             int dp[m][n] ;
             // dp[0][0] = 1 ; 
      int left , up ;
            for(int i = 0 ; i < m  ; i++){
              for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) dp[i][j] =  1 ;
                else{
                  up = 0 , left = 0 ; 
                 if(i> 0 ) up = dp[i-1][j] ;
                  if(j > 0 )  left = dp[i][j-1] ;
                  
                  dp[i][j] = left + up;
                }
              }
            }
          return dp[m-1][n-1] ;
    }
};