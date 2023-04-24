class Solution {
public:
    
    int memo(vector<vector<int>>&dp,vector<vector<char>>&matrix,int n,int m,int &maxi){
        // if(n < 0 or m < 0) return 0;
        if(n>=matrix.size() or m>=matrix[0].size()){
            return 0 ;
        }
        if(dp[n][m]!= -1)return dp[n][m]; 
        int diagonal = memo(dp,matrix,n+1,m,maxi);
        int right =memo(dp,matrix,n+1,m+1,maxi);
        int down = memo(dp,matrix,n,m+1,maxi);
        if(matrix[n][m] =='1'){
             dp[n][m] = 1 + min({right,diagonal, down});
            maxi=max(maxi,dp[n][m]);
            return dp[n][m];
        }
        else{
            return dp[n][m] = 0;
        }
        
    }
    
    
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0 ;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int res=0;
        memo(dp,matrix,0,0,res);
        
        // lets make a dp vector to store the values in the square matrix
//         vector<vector<int>> dp(n+1, vector<int> (m+1 , 0));
//         int res = 0;
//         for(int i=1;i<=n;++i){
//             for(int j=1;j<=m;++j){
//                 if(matrix[i-1][j-1]=='1'){
//                     dp[i][j]=min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]})  +1;
//                      res=max(res,dp[i][j]);
//                 }
               
//             }
            
//         }
        
        return res*res;
    }
};