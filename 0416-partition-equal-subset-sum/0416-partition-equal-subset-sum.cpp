class Solution {
public:
    bool f(int index , vector<int> &nums , vector<vector<int>> &dp , int target){
      if(target < 0) return false ;
      if(target == 0) return true ;
      if(index == 0) return (nums[0] == target) ;
      
     if(dp[index][target] != -1) return dp[index][target] ;
     bool notTake = f(index - 1 , nums , dp , target) ;
     bool take = f(index - 1 , nums , dp , target - nums[index]) ;
     
     return dp[index][target] = take or notTake ; 
   }
  
   
   bool subset(  int index ,int target , vector<int> &nums){
    
    vector<vector<int>> dp(index , vector<int>(target +1 , -1)) ;
     
     return f(index -1 , nums , dp , target) ;
   }
  
    bool canPartition(vector<int>& nums) {
         int sum = 0 ;
         for(auto it: nums) sum += it ;
         
        if(sum % 2) return false ;
        int target = sum /2 ;
        return subset(nums.size() , target , nums) ;
    }
};