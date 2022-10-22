//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool detect(int source , int V , vector<int> adj[] , vector<int> &visited ){
        
        visited[source] = 1;        
        queue<pair<int,int>>  q ;
        
        q.push({source,-1}) ;
        
        while(!q.empty()){
            int node = q.front().first ;
            int parent = q.front().second ;
            q.pop() ;
            
           for(auto it : adj[node]){
               if(!visited[it]){
                   visited[it] = 1 ;
                   q.push({it , node}) ;
               } 
               else if(parent != it){
                   return true ;
               }
           }
            
        }
        
        return false ;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>  visited(V,0) ;
        
        for(int i = 0 ; i < V ; i++)
        {
            if(!visited[i]){
               if(detect(i, V , adj  , visited) ) return true ;
            }
        }
        
        return false ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends