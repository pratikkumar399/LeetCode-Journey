class Solution {
public:
    bool f(int index , int target , vector<int> &arr , vector<vector<int>> &dp){
      if(target < 0 ) return false; 
      if(target == 0) return true; 
      if(index == 0) return (arr[0] == target ) ;

     
      if(dp[index][target] != -1) return dp[index][target] ;
      bool notTake = f(index - 1 , target , arr , dp);
      bool take = f(index - 1 , target - arr[index] , arr , dp) ;

      return dp[index][target] = take | notTake ;
    } 

    bool subsetSumToK(int n, int k, vector<int> &arr) {
        // Write your code here.
        vector<vector<int>> dp(n , vector<int> (k + 1 , -1)) ;
        return f(n-1 , k , arr , dp) ;
    }
  
    bool canPartition(vector<int>& nums) {
         int sum = 0 ;
         for(auto it: nums) sum += it ;
         
        if(sum % 2) return false ;
        int target = sum /2 ;
        return subsetSumToK(nums.size() , target , nums) ;
    }
};