class Solution {
public:

    vector<vector<int>> dp;
    long long int solve(vector<int>& coins, int n, int amount){
        if(amount==0) return 0;
        if(n==0) return INT_MAX;
        if(dp[n][amount]!=-1) 
            return dp[n][amount];
        long long int ans;
        if(coins[n-1]>amount) 
            ans = solve(coins, n-1, amount);
        else 
            ans = min(solve(coins, n-1, amount), 1+solve(coins, n, amount-coins[n-1]));
        return dp[n][amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+1, vector<int>(amount+1, -1));
        int ans = solve(coins, coins.size(), amount);
        return (ans==INT_MAX) ? -1 : ans;
    }
};