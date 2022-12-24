class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int flag  ;   
      sort(nums.begin()  , nums.end()) ;
      for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] != i){
         flag = i ;
          break ;
        }
      }
      
      return flag ;
    }
};