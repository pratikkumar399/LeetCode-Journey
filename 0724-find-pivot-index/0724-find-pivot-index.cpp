class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int i = 0;
        int left = 0;
        int right = accumulate(nums.begin(),nums.end(),0);
        int ans = -1;
        while(i< nums.size()){
            
            right -= nums[i];
            if(left == right){
                ans = i;
                break;
            }
            left += nums[i];
            i++;
        }
        
        return ans;
    }
};