class Solution {
public:
    int numSquares(int n) {
        
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        int count=1;
        while(count*count<=n){
            int square=count*count;
            for(int i=square;i<n+1;i++){
                dp[i]= min(dp[i-square]+1,dp[i]);
            }
            count=count+1;
        }
        
        return dp[n];
    }
};