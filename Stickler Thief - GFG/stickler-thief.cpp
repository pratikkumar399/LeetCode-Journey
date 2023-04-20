//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    int maxRob(int nums[],vector<int>&dp,int n){
        if(n<0)return 0;
        if(n==0)return nums[0];
        if(dp[n]!=-1)return dp[n];
        int take = nums[1] ;
        if(n > 1) take = nums[n] + maxRob(nums ,dp , n-2) ;
        int notTake = 0 + maxRob(nums , dp , n-1) ;
        return dp[n] = max(take , notTake) ;
    }
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int>  dp(n +1 , -1);
        return maxRob(arr , dp , n -1);
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