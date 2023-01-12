class Solution {
public:
    void moveZeroes(vector<int>& list) {
      // 
      int n = list.size() ;
      vector<int> res ;
      int j = 0 ;
      for(int i = 0 ; i < n  ; i++){
         if(list[i] != 0){
           list[j] = list[i] ;
           j++ ;
         }
      }
      
      // res.resize(n) ;
      
      for(int i = j ; i < n ; i++){
        list[i] = 0;
      }
      
    }
};