class Solution {
public:
    int majorityElement(vector<int>& nums) {
   
      int majority , count = 0 ; 
      int n = nums.size() ;
      
      for(int i = 0 ; i < n ; i++){
            if(count){
              (nums[i] == majority) ? count++ : count-- ;
            }
            else{
              majority = nums[i] ;
              count = 1 ;
            }
      }
      
      return majority ;
      
    }
};