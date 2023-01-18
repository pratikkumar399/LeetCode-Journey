class Solution {
public:
   
    bool canJump(vector<int>& nums) {
      int jumps = 0 ;
      int curr = 0 ;
      while(jumps< nums.size() && jumps <= curr){
        curr = max(curr , jumps + nums[jumps]) ;
        jumps++ ;
      }
      
      return (jumps == nums.size()) ;
    }
};