class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // next_permutation(nums.begin(), nums.end());
          int pivot = -1 ;
      
        for(int i = nums.size() - 1  ; i > 0 ; i-- ){
          if(nums[i-1] < nums[i]){
            pivot =  i -1 ;
            break ;
          }
        }
      
      if(pivot < 0) {
        reverse(nums.begin() , nums.end()) ; 
        return ;
      }
      for(int i = nums.size() - 1  ; i > 0 ; i-- ){
          if(nums[i] > nums[pivot]){
            swap(nums[i] ,  nums[pivot]) ;
            reverse(nums.begin() + pivot + 1 ,nums.end()) ;
            break ;
          }
        }
      
      
      
     
    }
};

// we have to find permutation of an array of integers 
// basically permutation is the linear  ordering of array members 
// 