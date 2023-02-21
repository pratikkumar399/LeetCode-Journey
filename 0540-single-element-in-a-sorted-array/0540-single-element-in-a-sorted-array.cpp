class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int,int> um ;
        for(auto it : nums){
          um[it]++ ;
        }
          
        for(auto [first , second] : um){
          if(second == 1 ) return first ;
        }
        
      return 0 ;
    }
};