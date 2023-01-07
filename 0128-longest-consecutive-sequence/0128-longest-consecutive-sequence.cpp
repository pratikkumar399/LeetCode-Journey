class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      // since we cannot sort the number therefore we have to find other ways to convert the number into sorted order 
        set<int>  st(nums.begin() , nums.end()) ;
        int maxi = INT_MIN ;
      
        vector<int>  res ;
      
        for(auto it :  st){
        res.push_back(it) ;
        }
     
        int count  = 0 ;
      
        int n =res.size();
        if(n  <= 1) return  n ;
      
       for(int i = 0 ; i < n - 1 ; i++){
        if(res[i+1] -1 == res[i] ) {
          count++ ;
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