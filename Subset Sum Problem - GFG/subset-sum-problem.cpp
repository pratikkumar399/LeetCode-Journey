// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

// a variation of the kanpsack problem 
// here we have the array and the sum is given and then we have to return is there is a subset which
// contains subset with values equal to given sum 

// so basically in knapsack we were given a weight array and we were required to find the max profit that we can take 
//from the given items 
    bool isSubsetSum(vector<int>arr, int sum){
        // lett is first talk  about theb base cases 
        // so we can clearly see that if there is no item in the kanpsack then we can have an empty subset 
        // also if there is no item in then there will be no value of the sum 
        int n = arr.size() ;
        // lets take a dp array with the states that are bound to change 
        // here we have twpo values that can change i.e n and the sum of the values in the array 
        bool dp[n+1][sum+1] ;
        
        for(int i = 0 ; i <  n + 1; i++){
            for(int j = 0 ; j < sum +1  ; j++){
                if(i == 0) dp[i][j] = false ;
                if(j == 0 ) dp[i][j] = true ;
            }
        }
        // now since we have already intialized the base cases therefore now we can move forward and check the other cases
        // the cases are 
        // if we can take the element in the subset or not
        // now a number can opnly be taken if the subset sum is less than the actuially given sum
        // so either we can take that item or choose to ignore it 
        // if we choose it then we can have two options that we include the subset or nor include it
        // now since we are handling a boolean case therefore we cannot return a max of both like we did in the knapsack 
        // problem , here we need to take care of that thing and then probably we can deal with the edge cases 
        for(int i =1  ; i < n +1 ; i++){
            for(int  j = 1 ; j < sum +1 ; j++){
                // lets check if the current sum gives us the subset sum equal to the given sum or not 
                // if it is equal then we can store a true value at that place in the dp array 
                bool notTaken =  dp[i-1][j]  ;
                bool taken = false ;
                if(arr[i-1] <= j){
                    taken = ( dp[i-1][j - arr[i-1]])  ;
                }
                // if we ignoring the item then we are left with a single choice to ignore the item and move forward 
              
                dp[i][j] = taken or notTaken ;
                
            }
        }
        
        return dp[n][sum] ;
    }
};

// { Driver Code Starts.
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