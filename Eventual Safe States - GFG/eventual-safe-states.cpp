//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool  dfs(int source , vector<int> &visited ,  vector<int> adj[] ,  vector<int> &check){
        visited[source] = 1;
        check[source] = 1;
        for(auto it : adj[source]){
            if(visited[it] ==0 ){
                if(dfs(it , visited , adj , check))
                {check[source] = 0 ;
                    return true ;} 
            }
            else if(visited[it] == 1) {
                check[source] = 0 ;
            return true ;}
            
        } 
        
        check[source] =1 ;
        visited[source]=2 ;
        return false ;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        
        vector<int>  visited(V , 0) ;
        vector<int>  ans ;
        vector<int>  check ( V ,0) ;
        for(int i = 0 ; i < V ;i++){
            if(!visited[i]){
                dfs(i ,  visited , adj , check) ; 
            }
        }
        
        for(int i = 0 ; i < V ; i++){
            if(check[i] == 1){
                ans.push_back(i) ;
            }
        }
        
        return ans ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends