

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int mid = 0 ,  low = 0 , high = nums.size() -1 ;
      
      while(mid <= high)
      {
        if(nums[mid] == 0){
          swap(nums[mid] , nums[low]) ;
          low++ ;
          mid++ ;
        } 
        else if(nums[mid] == 1){
          mid++ ;
        }
        else if(nums[mid] == 2){
          swap(nums[mid] , nums[high]) ; 
          high-- ;}
      }
    }
};


/*
 2 0 2 1 1 0 
 
in order to solve this what we can do is that take all the zerroes and place them in the begining of the array
and we can do this by using two pointers 
first take all the zeroes and place them in the begining index 
and then find the ones and simply keep them in  the mid because it is the mid number 
find all the twos and start placing them from the last index and reduce the index to reach till  mid

nums[0] == 2 
swap(nums[0] , nums[5]) ;
5-- ; 

nums[]


*/