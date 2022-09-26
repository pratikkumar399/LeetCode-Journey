class Solution {
  int parent[26] ;
  int find_parent(int v){
    if(parent[v] == v){
      return v ;
    }
    return parent[v] = find_parent(parent[v]) ;
  }
public:
    bool equationsPossible(vector<string>& equations) {
          
      for(int i = 0 ; i  < 26 ; i ++){
        parent[i] = i ;
      }
      
      for(auto it : equations){
        if(it[1] == '=') parent[find_parent(it[0] - 'a')] = find_parent(it[3] - 'a') ;
      }
      
      for(auto it : equations){
        if(it[1] == '!' &&find_parent(it[0] - 'a') == find_parent(it[3] - 'a')) return false  ;
      }
      
      return true ;
    }
};