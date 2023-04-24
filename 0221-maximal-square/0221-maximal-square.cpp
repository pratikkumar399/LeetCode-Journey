class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0 ;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        // lets make a dp vector to store the values in the square matrix
        vector<vector<int>> dp(n+1, vector<int> (m+1 , 0));
        int res = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})  +1;
                     res=max(res,dp[i][j]);
                }
               
            }
            
        }
        
        return res*res;
    }
};