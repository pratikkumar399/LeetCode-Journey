class Solution {
public:
      
  
    int minipath(vector<vector<int>> &dp , vector<vector<int>> &grid ,  int i , int j){
      if(i== 0 && j == 0) return 1 ;
      if(i  < 0 || j < 0 ) return 1e9 ;
      
      
      if(dp[i][j] != -1 ) return dp[i][j] ;
      int left =  grid[i][j] + minipath(dp , grid , i ,  j - 1) ;
      int up = grid[i][j] + minipath(dp , grid ,  i - 1 , j ) ;   
      
      
      return dp[i][j] = min(left , up) ;
    }
  
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> dp(n ,vector<int> (m , 0)) ;
      
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            // the base case 
            if(i== 0 && j == 0) dp[i][j] = grid[0][0] ;
            else{
              int up = grid[i][j] ;
              if(i> 0 ) up +=  dp[i-1][j] ;
              else up+= 1e9 ;
              int left = grid[i][j] ;
              if(j>0) left +=  dp[i][j-1] ;
              else left += 1e9 ;
               dp[i][j] = min(left , up ); 
            }
             }
        }
        
        return dp[n-1][m-1];
    }
};
// cost is the minimum path of the current paths alongwith the sum of previous paths