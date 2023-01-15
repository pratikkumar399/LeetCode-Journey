class Solution {
public:
  
   
    int find(int x , vector<int> &parent){
      if(parent[x] == x){
        return x ;
      }
      
      return parent[x] = find(parent[x] , parent) ;
    }
    
    void unionOp(int x ,  int y , vector<int> &parent){
      x = find(x , parent) ;
      y = find(y , parent) ;
      
      if(x == y){
        return ;
      }
      
      (x < y) ? (parent[y] = x ) : (parent[x] = y ) ;
      
    }
  
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       
      vector<int> parent(26 , 0 ) ;
      for(int i = 0 ; i < 26 ; i++){
        parent[i] = i ;
      }
      
      for(int i = 0 ; i < s1.size() ; i++){
        unionOp(s1[i] - 'a' , s2[i] - 'a' , parent) ;
      }
      
      string ans  ;
      
      for(auto it : baseStr){
        ans += (char)(find(it - 'a' , parent) + 'a') ;
      }
      
      return ans ;
    } 
};