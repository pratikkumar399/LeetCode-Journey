class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size() ;
      int ans ;
      map<int,int> mp ;
      for(auto it : nums){
        mp[it]++ ;
      }
        
      
      for(auto it : mp){
        if(it.second > 1 ){
          ans = it.first ;
          break ;
        }
      }
      
      return ans ;
    }
};