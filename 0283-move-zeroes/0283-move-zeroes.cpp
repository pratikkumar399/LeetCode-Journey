class Solution {
public:
    void moveZeroes(vector<int>& list) {
        
      int n = list.size() ;
      // int count = 0 ;
      // for(int i = 0 ; i < n ; i++ ){
      //   if(nums[i]  == 0){
      //     nums.erase(nums.begin() + i) ; 
      //     count++ ;
      //   }
      // }
      // nums.resize(n) ;
      
      list.erase( remove (list.begin(), list.end(), 0), list.end() );
      list.resize(n) ;
      
    }
};