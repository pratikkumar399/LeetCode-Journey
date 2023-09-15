//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string text1){
		    // Code here
		    string text2 = text1;
		    int n = text1.size() ;
            int m = text2.size() ;
            // vector<vector<int>> dp(n  +1, vector(m + 1 , -1)) ;
            vector<vector<int>> dp(n  +1, vector<int>(m + 1 , 0)) ;
           // return f(n , m , text1 , text2 , dp) ;
            for(int i = 1 ; i  <= n ; i ++){
              for(int j = 1 ; j <= m ; j++){
                if(text1[i-1] == text2[j-1] && i!=j ) dp[i][j] = 1 + dp[i-1][j-1] ;
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]) ;
                } 
                }
            }
          
          return dp[n][m] ;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends