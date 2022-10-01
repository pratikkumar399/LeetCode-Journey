class Solution {
public:
    
  
    int minCost(vector<vector<int>> &cost,int m, int n,vector<vector<int>>& memo) { 
      if (n <0 || m <0) 
         return INT_MAX; 
      else if(m==0 && n==0) 
         return cost[m][n]; 
      if(memo[m][n]!=-1)
          return memo[m][n];
      int r=cost[m][n]+min(minCost(cost,m-1,n,memo),minCost(cost,m,n-1,memo));
        memo[m][n]=r;
      return r;
    } 
    
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> memo(m,vector<int>(n, -1));
        return minCost(grid,m-1,n-1,memo);
    }
};