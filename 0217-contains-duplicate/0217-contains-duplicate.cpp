class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
     /* 1st solution using sorting
     sort(nums.begin() , nums.end()) ;
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i] == nums[i+1]){
                return true ;
            }
        }
        return false ;
        */
      
      /*    2nd Solution -> takes more time and memory 
        map<int,int> m ;
      for(int i = 0 ;i< nums.size() ;i++){
        m[nums[i]]++ ;
      }
      for(auto i :  m){
        if(i.second > 1){
          return true ;
          break ;
        }
      }
      return false ;
      */
      
//       3rd solution using sets 
      set<int> mySet(nums.begin() , nums.end());
    // unordered_set<int> mySet;
    // multiset<int> mySet;
    // unordered_multiset<int> mySet;
    
    return (mySet.size() != nums.size());
    }
};