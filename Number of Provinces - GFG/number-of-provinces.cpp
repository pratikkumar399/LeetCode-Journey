//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int dfs(vector<vector<int>>  &adj , int index , vector<int>&visited){
        visited[index] = 1 ;
        
        for(int i = 0 ; i < adj.size() ; i++){
            if(!visited[i] && adj[index][i] == 1){
                dfs(adj , i , visited) ;
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int> visited(V+1 , 0 ) ;
        
        if(V== 0) return 0 ;
        int count = 0 ;
        
        for(int it = 0 ; it < adj.size() ; it++){
            if(!visited[it]){
                count++ ;
                dfs(adj , it , visited) ;
            }
        }
        
        return count ;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends