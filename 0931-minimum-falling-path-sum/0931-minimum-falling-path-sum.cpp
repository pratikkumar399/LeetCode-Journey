class Solution {
public:
  // memoization
    int minipath(vector<vector<int>> &dp ,  int i , int j ,int m , vector<vector<int>> &matrix){
      // checking the boundary of the matrix , if the boundary is excedded then we can simply return int max values which can not be returned 
        if(j < 0 || j >= m  ) return 1e9 ;
      // if we reach tht ith row then we can simply return the different values from the ith row 
        if(i == 0 )  return matrix[0][j] ;
        
       if(dp[i][j]  != -1) return dp[i][j] ;
        
      // there are total three path that we can take 
      // the upper and the left diagonal and the right daigonal 
        int upper = matrix[i][j] +  minipath(dp ,  i - 1 , j ,m ,   matrix)  ;
        int ld  = matrix[i][j] + minipath(dp ,  i - 1 , j- 1 ,m ,   matrix) ;
        int rd = matrix[i][j] + minipath(dp , i - 1 , j + 1 ,m ,  matrix) ;
      
      
       // since we have to find the minimum path among all the options so we will store the minimum of all the results in the dp array   
        return dp[i][j] = min(upper ,  min(ld , rd)) ;
    }
  
  
  // tabulation
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        
        // vector<vector<int>>  dp(n , vector<int> (m , -1)) ;
        vector<vector<int>>  dp(n , vector<int> (m , 0)) ;
      
      
      // tabulation  store the initial value of the zeroth row in the dp matrix 
      for(int i = 0 ; i < m ; i++){
        dp[0][i] = matrix[0][i] ; 
      }
      
      for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j< m ; j++){
          
          // explore all the options that we have 
          // we are starting from i == 1 because we have already taken all the possibilies for the first row and thereforwe cannot include it 
          // again
          
          // since we are starting from i == 1 therefore we are not required to check the boundary in that case 
          int up =  matrix[i][j] + dp[i-1][j] ;
          
          int ld =  matrix[i][j] ;
          
          // check the boundaries 
          if(j-1 >= 0) {
             ld += dp[i-1][j-1] ;
          }
          // since we are checking for the minimum path sum so if the boundaries are excedded what we can do is that we can simpply return 
          // the max int value so that path is not taken again 
          else {
            ld+= 1e9 ;
          }
          
          // do the similar kind of thing for the right diagonal 
          int rd =  matrix[i][j] ;
          if(j+1 < m ) {
             rd += dp[i-1][j+1] ;
          }
          else {
            rd+= 1e9 ;
          }
          // finding the minimum out of all the paths that we get 
          dp[i][j] = min(up , min(ld, rd)) ;
        }
      }
      
      // now simply take up the minimum among all the path after we reach the first row
        int mini = INT_MAX ;
        for(int i = 0 ; i < m ; i++){
          mini = min(mini , dp[n-1][i] );
        }
      
        return mini;
    }
};


//  so the thing is that  the path can be either row , col ,  row  + 1   col + 1 