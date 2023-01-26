class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long windowStart = 0 ;
        long windowEnd = 0 ; 
        long sum = 0 ;
        sort(nums.begin() , nums.end()) ;
        for(windowEnd = 0 ; windowEnd < nums.size() ; windowEnd++){
            sum += nums[windowEnd] ;
            if( k < nums[windowEnd]  * (windowEnd - windowStart + 1) -sum) 
              sum -= nums[windowStart++] ;
        }
      
      return windowEnd - windowStart ;
    }
};