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
             vector<vector<int>> dp(m , vector<int> (n)) ;
              vector<int> prev (n , 0) ;
             // dp[0][0] = 1 ; 
      int left , up ;
            for(int i = 0 ; i < m  ; i++){
              // int temp = dp[n] ;
              vector<int> cur(n , 0) ;
              for(int j = 0 ; j < n ; j++){
                if(i == 0 && j == 0) cur[j] =  1 ;
                else{up = 0 , left = 0 ;
                 if(i> 0 ) up = prev[j] ;
                  if(j > 0 )  left = cur[j-1] ;
                  
                  cur[j] = left + up;
                }
              }
              prev =cur ;
            }
          return prev[n-1] ;
    }
};