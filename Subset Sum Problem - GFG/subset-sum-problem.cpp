//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool f(int index , int target , vector<int> &arr , vector<vector<int>> &dp){
    if(index == 0) return (arr[0] == target ) ;
    if(target == 0) return true; 
     
    if(dp[index][target] != -1) return dp[index][target] ;
    bool notTake = f(index - 1 , target , arr , dp);
    bool take = false ;
    if(arr[index] <= target){
        take = f(index - 1 , target - arr[index] , arr , dp) ;
    }

    return dp[index][target] = take | notTake ;
  }  
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size() ;
        vector<vector<int>> dp(n , vector<int> (sum + 1 , -1)) ;
        return f(n-1 , sum , arr , dp) ;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends