class Solution {
public:
  
    int minipath(vector<vector<int>>  &dp  , vector<vector<int>> &matrix , int i , int j ){
      if(i == 0 && j == 0 && matrix[0][0] != 1) return 1 ;
      if(i < 0 || j < 0 ) return 0 ; 
      if(matrix[i][j] == 1) return 0 ;
    cout<<matrix[i][j] <<endl ;
      if(dp[i][j] != -1 ) return dp[i][j] ;
      int left = minipath(dp , matrix , i - 1 , j) ;
      int right =  minipath(dp , matrix , i , j -1) ;
      
      return dp[i][j] = left + right ;
      
    }
  
  
  
  
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
      int n = matrix.size() ;
      int m = matrix[0].size() ;
        vector<vector<int>>  dp(n ,  vector<int> (m , -1)) ;
      
     return minipath(dp ,matrix , n-1 , m-1 ) ;
    }
};

// so the thing is that there is an obstacle in the road and we need to avoid the obstacle 
// so what we can do is that if we find any obstacle in the path we are taking we will not take that road 