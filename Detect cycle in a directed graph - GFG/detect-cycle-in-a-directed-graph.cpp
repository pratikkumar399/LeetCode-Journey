// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool checkCycle(int source, vector<int> graph[], vector<int> &visited)
    {
        // mark each node as visited
        visited[source] = 1;

        for (auto it : graph[source])
        {
            // if its not visited run a dfs call for it
            if (visited[it]==0)
            {
                if (checkCycle(it, graph, visited))
                    return true;
            }
            // if it has been previously visited and is on the same path then that means there is a cycle 
            else if (visited[it]==1)
                return true;
        }
        
        // if the node is not on the same path mark it as 2 . This will help us to differentiate the nodes
        // that contain a cycle 
        visited[source] = 2;
        return false;
    }
    
    
    
    
    bool isCyclic(int V, vector<int> graph[]) {
        // code here
         vector<int> visited(V, 0);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (checkCycle(i, graph, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.

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
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends