class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      vector<int> ans ;
        if(nums.size() == 2) {
          if(nums[0] == nums[1]) {
            ans.push_back(nums[0]) ;
            return ans ;
          }
          else{
            return nums ;
          }
        }
      
      unordered_map<int, int> mp ;
      int n = nums.size() ;
      for(auto it :  nums){
        mp[it]++ ;
      }
      
      for(auto it : mp){
        if(it.second>  n / 3 ){
          ans.push_back(it.first) ;
        }
      }
      
      return ans ;
      
    }
};