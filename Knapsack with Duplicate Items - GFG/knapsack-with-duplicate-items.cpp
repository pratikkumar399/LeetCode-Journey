//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int memo(int W , int wt[] , int val[] , int n , vector<vector<int>> &dp){
            
            // return 0;
             if(n==0){
               return ((int)(W/wt[0])) * val[0];
            }
            
            if(dp[n][W] != -1) return dp[n][W];
            
            
            if(wt[n] <= W) return dp[n][W] = max(val[n] + memo(W - wt[n] , wt , val , n, dp), memo(W , wt, val , n-1, dp));
             return dp[n][W] = 0+  memo(W , wt, val , n-1, dp);
        }
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
         vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return memo(W , wt , val , n - 1 , dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends