class Solution {
public:
  
    // climbing stais
  
  // 
  int stairs(vector<int> &ans , int n){
    if(n < 0  ){
      return 0 ;
    }
    if(n == 0) return  1 ;
    if(ans[n] != -1 ){
      return ans[n] ;
    }
    return ans[n] = stairs(ans , n-1) + stairs(ans , n-2) ;
  }
    int climbStairs(int n) {
      vector<int> ans(n+1 , -1) ;
        
        return stairs(ans , n) ;
      
    }
};