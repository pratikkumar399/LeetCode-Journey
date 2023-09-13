//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        // vector<vector<int>> dp(n  +1, vector(m + 1 , -1));
         vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        int maxLength = 0; // To keep track of the length of the longest common substring
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLength = max(maxLength, dp[i][j]); // Update the maxLength if needed
                } else {
                    dp[i][j] = 0;
                }
            }
        }
    
        return maxLength;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends