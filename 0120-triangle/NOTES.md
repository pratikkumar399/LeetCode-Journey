```cpp
int solve(vector<vector<int>>  &triangle , int i , int j , int n, vector<vector<int>> &dp){
if(i == n) return 0 ;
if(dp[i][j] != -1) return dp[i][j] ;
int left = triangle[i][j] + solve(triangle , i+ 1 , j , n ,dp) ;
int right = triangle[i][j] + solve(triangle , i + 1,  j+1 , n ,dp) ;
return dp[i][j] = min (left , right) ;
}
```