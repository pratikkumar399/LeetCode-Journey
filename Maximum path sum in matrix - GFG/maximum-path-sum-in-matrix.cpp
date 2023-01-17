//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

   int maxi(vector<vector<int>> &matrix , int n , vector<vector<int>> &dp , int i , int j){
           
            if( j < 0 || j >= n  ) return -1e8 ;
            if(i == 0  ) return matrix[0][j] ; 
           
           
           if(dp[i][j] != -1) return dp[i][j] ;
           
           int top = matrix[i][j] + maxi(matrix ,  n , dp ,  i - 1 , j) ;
           int rdiag = matrix[i][j] + maxi(matrix ,  n , dp ,  i - 1 , j + 1) ;
           int ldiag = matrix[i][j] + maxi(matrix ,  n , dp ,  i  -  1 , j -1 ) ;
           
           
           return dp[i][j] =  max(top , max( rdiag  , ldiag)) ;
   }
    
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N ,vector<int> (N , -1)) ;
        int maxii = -1e8 ;
        for(int i = 0 ;  i < N ; i++){
            maxii = max(maxii  , maxi(Matrix ,  N , dp ,  N-1 , i));
        }
        return maxii ;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends