class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k %=nums.size();
      // 7 6 5 4 3 2 1 
      int n = nums.size() ;
     reverse(nums.begin() , nums.end()) ;
      nums.clear() ;
      vector<int> ans ;
      // 5 6 7 
      for(int i = k - 1 ; i >= 0 ; i--){
        ans.push_back(nums[i]) ;
      }
      
      for(int i = n - 1  ; i >= k  ; i-- ){
        ans.push_back(nums[i]) ;
      }
      
      for(auto it :  ans){
        nums.push_back(it) ;
      }
      ans.clear() ;
    } 
};