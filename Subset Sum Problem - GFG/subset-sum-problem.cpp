//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
   bool f(vector<int> &arr , int sum , vector<vector<int>> &dp , int n){
       if(n == 0) return (arr[0] == sum) ;
       if(sum == 0) return true ;
       
       if(dp[n][sum] != -1) return dp[n][sum] ;
       bool notTake = f(arr , sum  , dp , n-1) ;
       bool take = false; 
       if(sum >= arr[n]){
           take = f(arr , sum - arr[n] , dp , n-1 )  ;
       }
       
       return dp[n][sum] = take or notTake ;
       
   }

   
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size() ;
        // vector<vector<int>> dp(n , vector<int> (sum + 1 , -1)) ;
        vector<vector<bool>> dp(n , vector<bool> (sum + 1 , false)) ;
        for(int i = 0 ; i < n ; i++) dp[i][0] = true ; 
        dp[0][arr[0]] =  true ;
        for(int i =  1 ; i < n ; i++){
            for(int j = 1 ; j <= sum ; j++){
                bool notTake = dp[i-1][j]  ;
                bool take= false ;
                if(j >= arr[i]){
                    take = dp[i-1][j- arr[i]] ;
                }
                
                dp[i][j] = take or notTake ;
                
            }
        }
        return dp[n - 1][sum] ;
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