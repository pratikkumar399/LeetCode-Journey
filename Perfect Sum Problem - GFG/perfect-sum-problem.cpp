//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int subset(int n , vector<vector<int>> &dp , int arr[],int target){
	    
	    if(n == 0)
         {
            if(target==0 and arr[0]==0) return 2;
            if(target==0 or target==arr[0]) return 1;
            return 0;
        }
	    if(dp[n][target] != -1) return dp[n][target] ;
	    
	    int take = 0 ;
	    if(arr[n] <= target){
	       take = subset(n-1 , dp , arr , target - arr[n]) % mod ;
	    }
	   
	      int   notTake = subset(n - 1 , dp , arr , target) % mod ;
	    
	    
	   return dp[n][target] = (take % mod + notTake % mod)  ; 
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n +1 , vector<int>(sum + 1,-1)) ;
        return subset(n-1, dp , arr , sum) % mod ;
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends