//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& prerequisites) {
	    // Code here
	     vector<vector<int>> graph(n) ;
      vector<int>  indegree(n,0);
      for(auto it : prerequisites){
        graph[it.second].push_back(it.first);
	            indegree[it.first]++ ;
      }
	    queue<int> q ;
	    for(int i = 0 ; i <n ; i++){
	        if(indegree[i] == 0){
	            q.push(i) ;
	        }
	    }
      int count = 0;
	    while(!q.empty()){
	        auto top = q.front() ;
	        q.pop() ;
          count++ ;
	        for(auto it : graph[top]){
	            if(--indegree[it] == 0){
	            q.push(it) ;
	        }
	        }
	        
	    }
	    
	    return count ==n ;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends