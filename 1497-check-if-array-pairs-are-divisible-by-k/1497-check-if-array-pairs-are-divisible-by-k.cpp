class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int ,int> mp ;
        for(auto it : arr){
            it = it % k ;
            if( it < 0 ) it += k ;
            mp[it]++ ;
        }
        bool ans = false ;
      
      for(auto it : mp ){
        if(it.first == 0) 
        {
          if(mp[it.first] % 2 != 0){
            return false ;
          }
        }
          else if(mp.find(k - it.first ) == mp.end()){
            return false ;
          }
          else if(mp[it.first] != mp[k - it.first]){
            return false ;
          }
        }  
        
      

        return true  ;
      
    }
};