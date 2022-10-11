class Solution {
public:
// vector<vector<int>  dp ;
   long long int solve(vector<int> &coins , int amount ,  vector<vector<int>> &dp , int n){
      
      if(amount == 0){
        return 0 ;
      }
      if(n==0){
        return INT_MAX ;
      }
      if(dp[n][amount] != -1) return dp[n][amount] ;
      long long int best ;
      if(coins[n-1] > amount){
        best = solve(coins , amount ,dp  , n-1) ;
      }
      else{
        best = min(solve(coins , amount , dp , n- 1) , 1+ solve(coins , amount - coins[n-1] , dp , n)) ;
      }
      
      return dp[n][amount]  = best ;
    }
    int coinChange(vector<int>& coins, int amount) {
      int n = coins.size() ;
        vector<vector<int>>  dp ( n+1 , vector<int> (amount+1,-1)) ;
        int ans = solve(coins , amount ,dp , n ) ;
      
        // dp[0] = 0 ;
      return (ans==INT_MAX) ? -1 : ans;
    }
};


