class Solution {
public:
  
  bool dfs(int n , vector<int> &visited , vector<vector<int>> &graph){
     if(visited[n] == -1) visited[n] = 1 ;
     for(auto it :  graph[n]){
       if(visited[it] == -1){
         visited[it] = !visited[n];
         
         if(!dfs(it , visited ,graph)) {
           return false ;
         }
       }
       else if(visited[it] == visited[n] ){
         return false ;
       }
     }
    return true ; 
  }
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size() ;
        vector<int> visited(n,-1) ;
      
        for(int i= 0 ; i< n ;i++){
          if(visited[i] == -1){
            if(!dfs(i,visited,graph)) return false ;
          }
        }
      return true ;
    }
  
  
};