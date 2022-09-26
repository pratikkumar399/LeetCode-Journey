class Solution {
public:
    int pivotIndex(vector<int>& nums) {
      int sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
          sum  += nums[i] ;
        }
      int leftSum  = 0 ; 
      int rightSum  = sum  ;
      int ans = -1 ;
      
      for(int  i = 0 ;  i < nums.size() ; i++){
        rightSum  -=  nums[i] ;
        
        if(leftSum == rightSum){
          ans = i ;
          break ;
        }
        
        leftSum += nums[i] ;
      }
      
      return ans ;
    } 
};