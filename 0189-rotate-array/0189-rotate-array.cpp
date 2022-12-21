class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      k %=nums.size();
      // cout<< k << endl ;  
      //   reverse(nums.begin(), nums.end()); //7 6 5 4 3 2 1
      //   reverse(nums.begin(), nums.begin()+k);  //5 6 7 
      //   reverse(nums.begin()+k, nums.end()); //1 2 3 4 5
        vector<int>  ans ;
        for(auto it :  nums){
          ans.push_back(it) ; 
        }
        nums.clear() ;
      // reverse(ans.begin() , ans.end()) ; // 7 6 5 4 3 2 1 || 1 2 3 4 5 6 7
        for(int i =ans.size() -1  ; i >=ans.size() - k ;i--){ // 6  5 4 || 4 = 7-3
          cout<<ans[i]<<" " ;
          nums.push_back(ans[i]); // nums -> 7 6 5 
          
        }
      
      reverse(nums.begin() , nums.end()) ; // 5 6 7
      for(int i = 0 ; i < ans.size()-k ; i++){
        nums.push_back(ans[i]) ;
      }
      
      ans.clear() ;
    } 
};