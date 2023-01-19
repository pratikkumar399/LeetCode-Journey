class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      
      unordered_map<int, int> mp ;
      int n = nums.size() ;
      for(auto it :  nums){
        mp[it]++ ;
      }
      nums.clear() ;
      for(auto it : mp){
        if(it.second>  n / 3 ){
          nums.push_back(it.first) ;
        }
      }
      
      return nums ;
      
    }
};