class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,  int>  um ;
        
      for(auto it :  nums) {
        um[it]++ ;
      }
      
      int maxi = INT_MIN ;
      
      for(auto it : um){
        if(maxi < it.second){
          maxi =  it.second ;
        }
      }
      int ans = 0 ;
      for(auto it : um){
        if(maxi == it.second){
         ans = it.first ;
        }
      }
      
      return ans ;
    }
};