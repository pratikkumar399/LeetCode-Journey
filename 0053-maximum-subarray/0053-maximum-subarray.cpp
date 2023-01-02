class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      // kadanes also for maximum subarray sum
        int sum = 0 ;
      // initially taking the min value 
        int maximum = INT_MIN ;
        
        for(auto it :  nums ){
          // take the sum of each numbers 
            sum += it ;
            // keep checking the subarray
            maximum =  max(sum  , maximum ) ;
            // if the sum becomes negative them simply make the sum equal to 0 again .
            if(sum< 0)  sum= 0 ;
        }
        
        return maximum ;
        
    }
};