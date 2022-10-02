class Solution {
public:
    
    
    int tabulation(vector<vector<int>>& grid , int n , int m , vector<vector<int>> dp){
      dp[n-1][m-1] = grid[n-1][m-1] ;
      
      for(int i = m-2 ; i >=0 ; i-- ){
        dp[n-1][i]= dp[n-1][i+1] + grid[n-1][i] ;
      }
      for(int i = n-2; i >=0 ; i-- ){
        dp[i][m-1]= dp[i+1][m-1] + grid[i][m-1] ;
      }
      for(int i = n-2 ; i >=0 ; i-- ){
        for(int j = m-2 ; j >=0 ; j-- ){
              dp[i][j] = min(dp[i+1][j] , dp[i][j+1]) + grid[i][j] ;
         }
      }
      
      return dp[0][0] ;
      
    }
  
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        vector<vector<int>> dp(n ,vector<int> (m , 0)) ;  
      dp[0][0] = grid[0][0] ;
        for(int i = 1 ; i < m ; i++ ){
          dp[0][i] = grid[0][i] + dp[0][i-1] ;
        }
      for(int i = 1 ; i < n ; i++ ){
          dp[i][0] = grid[i][0] + dp[i-1][0] ;
        }
     for(int i = 1 ; i < n ; i++ ){
          for(int j = 1 ; j < m ; j++ ){
          dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
        }
        }
      
      return dp[n-1][m-1]; 
    }
};


// cost is the minimum path of the current paths alongwith the sum of previous paths