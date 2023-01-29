class Solution {
  
public:
    static bool cmp(pair<int, int> &a , pair<int , int> &b)
    { 
      return a.second > b.second ;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
      map<int , int> mp ;
      
      for(auto i :  nums){
        mp[i]++ ;
      }
      vector<pair<int,int>> maximum ;
      
       for(auto it : mp){
         maximum.push_back({it.first, it.second}) ;
       }
      
      sort(maximum.begin() , maximum.end() , cmp) ;
      vector<int> ans ;
      
       for(auto it : maximum){
         ans.push_back(it.first) ;
         if(ans.size() == k) break;
       }
      
      
      return ans ;
    }
};