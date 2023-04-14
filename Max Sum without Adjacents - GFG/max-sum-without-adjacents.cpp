//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solveMax(vector<int> &dp , int *arr,int n){
	    if(n<0)return 0;
	    if(n==0)return arr[0];
	    if(dp[n] != -1) return dp[n];
	   // int second =0 ;
	    int first = 0 + solveMax(dp, arr, n-1);
	    
	    int second = arr[n] + solveMax(dp , arr,n-2);
	    
	    return dp[n] = max(first,second);
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n, -1);
	    return solveMax(dp,arr,n-1);	   
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends