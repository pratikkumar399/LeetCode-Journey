class Solution {
public:
     int f(int n , int m , string &text1 , string &text2 ,vector<vector<int>> &dp ){
       if(m== 0 or n==0) return 0 ; 
       
       
       if(dp[n][m] != -1) return dp[n][m] ;
       if(text1[n-1] == text2[m-1]) 
         return dp[n][m] =  1 + f(n-1 , m-1 , text1 ,text2 , dp) ;
       
       else
       return dp[n][m] = max( 0 + f(n-1 , m , text1 , text2 , dp) , 0 + f(n , m-1 , text1 , text2 , dp)) ;
       
     }
   
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size() ;
        int m = text2.size() ;
        vector<vector<int>> dp(n  +1, vector(m + 1 , -1)) ;
       return f(n , m , text1 , text2 , dp) ;
    }
};