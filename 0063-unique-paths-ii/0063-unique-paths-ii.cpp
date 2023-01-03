class Solution {
public:
  
    int minipath(vector<vector<int>>  &dp  , vector<vector<int>> &matrix , int i , int j ){
      if(i == 0 && j == 0 && matrix[0][0] != 1) return 1 ;
      if(i < 0 || j < 0 ) return 0 ; 
      if(matrix[i][j] == 1) return 0 ;
    cout<<matrix[i][j] <<endl ;
      if(dp[i][j] != -1 ) return dp[i][j] ;
      int left = minipath(dp , matrix , i - 1 , j) ;
      int up =  minipath(dp , matrix , i , j -1) ;
      
      return dp[i][j] = left + up ;
      
    }
  
  
  
  
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
      if(matrix[0][0]==1) return 0;
      int n = matrix.size() ;
      int m = matrix[0].size() ;
        // vector<vector<int>>  dp(n ,  vector<int> (m , -1)) ;
      vector<vector<int>>  dp(n , vector<int> (m )) ;
      // storing the initial value in the dp array 
      dp[0][0] = 1 ;
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
          
          // if the i and j value are greater than 0 then we have to take the dp value as 0 
          if(i != 0 && j != 0 )  dp[i][j] = 0 ;
          // ignoring the obstacle and then taking up both the opetions 
          
          if( matrix[i][j] != 1) 
          { 
            if(i > 0) dp[i][j] += dp[i-1][j] ;
            if(j > 0)dp[i][j] += dp[i][j-1] ;
          }
          }
      }
      return dp[n- 1][m-1] ;
    }
};





// so the thing is that there is an obstacle in the road and we need to avoid the obstacle 
// so what we can do is that if we find any obstacle in the path we are taking we will not take that road 