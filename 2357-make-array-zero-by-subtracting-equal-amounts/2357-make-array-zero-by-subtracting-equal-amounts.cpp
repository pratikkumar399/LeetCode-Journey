class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int , int> mp ;
        for(auto it :  nums) mp[it]++ ;
       
        int count = 0 ;
      
       for(auto it : mp){
         if(it.first != 0) count++ ;
       }
      
      return count ;
    }
};