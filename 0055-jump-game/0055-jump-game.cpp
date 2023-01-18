class Solution {
public:
   
    bool canJump(vector<int>& nums) {
         int jumps = 0 ;
        for(int curr = 0 ; jumps < nums.size() && jumps <= curr  ; jumps++ ){
             curr = max(jumps +  nums[jumps] , curr) ;
        }
      
      return (jumps == nums.size()) ;
    }
};