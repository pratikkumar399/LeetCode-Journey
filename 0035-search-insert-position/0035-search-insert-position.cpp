class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       auto lower = lower_bound(nums.begin() , nums.end() , target) - nums.begin() ;
      return lower ;
    }
};