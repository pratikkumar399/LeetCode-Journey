//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>  g[N] ;
        
        for(auto it :  edges){
            int u =  it[0] ;
            int v = it[1] ;
            g[u].push_back(v) ;
            g[v].push_back(u) ;
        }
        
        vector<int>  dist (N , -1) ;
        dist[src] = 0 ;
        queue<int> q ;
        q.push(src) ;
        
        while(!q.empty()){
            int top = q.front() ;
            q.pop() ;
            
            if(dist[top] == -1) continue ;
            for(auto it : g[top]){
                if(dist[it] == -1 || dist[top] + 1 < dist[it]){
                    dist[it] = dist[top] +1 ;
                    q.push(it) ;
                }
            }
        } 
        return dist ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends