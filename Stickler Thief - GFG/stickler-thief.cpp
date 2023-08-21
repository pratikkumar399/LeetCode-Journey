//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int fSum(int arr[],int n,vector<int> &dp){
        if(n < 0 )return 0;
        if(n==0) return arr[n];
        
        if(dp[n]!= -1) return dp[n];
        
        int first = arr[n] + fSum(arr, n -2 , dp);
        int second = 0 + fSum(arr , n-1 , dp);
        
        return dp[n] = max(first,second);
        
    }
    
    
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n+1 , -1);
        return fSum(arr,n-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends