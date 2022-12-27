class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 ;
        int last = nums.size()-1 ;
        
        while(start <= last){
            int mid = start + (last - start) /2 ;
            
            if(target == nums[mid]){
                return mid ;
            }
            // checking the search space 
            if(nums[mid] >= nums[start]){
              // if the target lies between start and mid 
                if(target < nums[mid] && target >= nums[start]){
                    last = mid -1;
                }
              // other wise move the next part
                else{
                    start = mid +1 ;
                }
            }
            else{
              //  if target lies between mid and last 
                if(target>=nums[mid] && target <= nums[last]){
                    start = mid +1 ;
                    
                }
              // other wise move to previuos part
                else{
                    last = mid -1;
                }
            }
        }
        return -1 ;
    }
};