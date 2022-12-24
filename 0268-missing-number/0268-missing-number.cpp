class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int flag  ;   
      int n = nums.size() ;
      int totalSum =  (n * (n + 1)) / 2 ;
      // sort(nums.begin()  , nums.end()) ;
      int ans  =  accumulate(nums.begin() ,  nums.end() , 0) ;
      flag = totalSum - ans ; 
      
      
      return flag ;
    }
};