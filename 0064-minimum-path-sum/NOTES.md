```cpp
int minPath(vector<vector<int>>& grid , int n , int m , vector<vector<int>> &dp){
if( n < 0 || m < 0 ) return INT_MAX ;
else if(n== 0 && m== 0)
return grid[n][m] ;
if(dp[n][m] != -1){
return dp[n][m] ;
}
return dp[n][m] = grid[n][m] + min(minPath(grid , n- 1 , m , dp) , minPath(grid , n , m-1 , dp)) ;
}
int minPathSum(vector<vector<int>>& grid) {
int n = grid.size() ;
int m = grid[0].size() ;
vector<vector<int>> dp(n ,vector<int> (m , -1)) ;
return minPath(grid , n-1 , m-1 , dp) ;
}
```
​
##### Tabulation
​
```cpp
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
```
​
​
​