class Solution {
public:
  
   
    int findCircleNum(vector<vector<int>>& G) {
      int count = 0 ; 
         int n = G.size() ; 
        if(n == 0)return 0 ;
          vector<bool> visited(n,0) ;
          
        for(int i = 0 ; i < n ; i++){
         if(!visited[i]){
           count++ ;
          dfs(i , visited , G) ;
          
        }
          
      }
      return count ;
    }
      
      void dfs(int index  , vector<bool> &visited , vector<vector<int>>& G){
        visited[index] = 1 ;
        
        for(int j = 0 ; j < G.size() ; j++){
          if(!visited[j] && G[index][j] ==1){
            dfs(j , visited , G) ;
          }
        }
       
      }
}; 