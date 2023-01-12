class Solution {
public:
    void moveZeroes(vector<int>& list) {
      // 
      int n = list.size() ;
      vector<int> res ;
      
      for(int i = 0 ; i < n  ; i++){
         if(list[i] != 0){
           res.push_back(list[i]) ;
         }
      }
      
      res.resize(n) ;
      
      for(int i = 0 ; i < n ; i++){
        list[i] = res[i] ;
      }
      
    }
};