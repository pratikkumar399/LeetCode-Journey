class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0 ; 
         int j = n  ;
        
        vector<int>  ans ; 
         while(i <= n -1 && j < 2*n){
           ans.push_back(nums[i]) ;
           ans.push_back(nums[j]) ;
           i++ ;
           j++ ;
         }
      
      return ans ;
    }
};