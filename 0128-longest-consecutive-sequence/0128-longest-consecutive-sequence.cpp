class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>  st(nums.begin() , nums.end()) ;
        int maxi = INT_MIN ;
      vector<int>  res ;
        for(auto it :  st){
        res.push_back(it) ;
        }
      int count  = 0 ;
      int n =res.size();
      if(n  <= 1) return  n ;
      
      for(int i = 0 ; i < res.size() - 1 ; i++){
        if(res[i+1] -1 == res[i] ) {
          count++ ;
          cout<<res[i]  <<" "<<res[i + 1]  <<" " <<count<<endl; 
          
          // cout<<count ;
        } 
        else if(res[i+1] -1 != res[i]){
          count =0;
        }
        maxi = max(count , maxi) ;
      }
      
     
      
      return maxi + 1;
    }
  
  // since we cannot sort the elements because the question requires us to generate an algo which runs in O(n) time
  // we cannot sort it and therefore we need to think of another approach to solve the problem 
  
  
};