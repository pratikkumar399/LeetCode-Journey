class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count= 1;
        int min_val = INT_MIN ;
        for(int i = 0; i < nums.size()-1 ;i++){
            if(nums[i] <= nums[i+1]){
                min_val = nums[i];
            }else{
                if(nums[i+1] < min_val){
                    nums[i+1] = nums[i];
                }
                count -= 1;
            }
            
        }
        
        
        return (count>=0) ;
    }
};