class Solution {
public:
    int steps(vector<int> &dp , int n){
        if(n < 0 ) return  0 ;
        if(n == 0) return 1 ;
        if(dp[n] != -1) return dp[n] ;
        return dp[n] = steps(dp , n-1) + steps(dp , n-2) ;
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1) ;
        return steps(dp , n) ;

    }
};