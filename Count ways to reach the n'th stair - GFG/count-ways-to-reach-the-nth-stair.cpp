//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    
    #define mod 1000000007
    int count(vector<int> &dp , int n){
        if(n < 0 ) return 0 ;
        if( n <= 1) return 1;
        if(dp[n] != -1) return dp[n] % mod ;
        
        long long first =  count(dp , n-1) %mod ;
        long long second = count(dp , n-2) % mod ;
        
        return dp[n] = (first + second) % mod  ; 
        
    }
    
    int countWays(int n)
    {
        // your code here
        vector<int> dp(10001 , -1) ;
        return count(dp , n)  ;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends