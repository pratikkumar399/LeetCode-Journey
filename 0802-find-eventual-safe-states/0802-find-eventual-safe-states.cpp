class Solution {
public:
  
    bool dfs(int source , vector<int> &visited , vector<int> &check , vector<vector<int>> &graph){
      visited[source] = 1 ;
      
      for(auto it : graph[source]){
          if(!visited[it]){
            if(dfs(it , visited , check , graph  )) {
              check[source] = 0 ;
              return true ;
            } 
          }
          else if(visited[it] == 1) {
            check[source] = 0 ;
            return true ;
            }
      }
      
      visited[source] = 2 ;
      check[source] = 1 ;
      
      return false ;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size() ;
        vector<int> visited(n , 0) ;
        vector<int> check(n,0) ;
        vector<int>  ans ;
        for(int i = 0 ; i < n ; i++){
          if(!visited[i]){
            dfs(i , visited , check , graph) ;
          }
        }
        for(int i = 0 ; i < n ; i++){
          if(check[i] == 1) ans.push_back(i) ;
        }
      
      return ans ;
    } 
};