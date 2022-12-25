class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int,  int >  mp ;
      
      for(auto it :  nums){
        mp[it]++ ;
      }
      int ans = 0 ; 
      for(auto it : mp){
        if(it.second == 1) {
          ans = it.first ;
          break ;
        }
      }
      
      return ans ;
    }
};