class Solution {
public:
    bool canJump(vector<int>& nums) {
        int min_index = nums.size() - 1;
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (i + nums[i] >= min_index) {
                min_index = i;
            }
        }
        
        return min_index == 0;
    }
};
