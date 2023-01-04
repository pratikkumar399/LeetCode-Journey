class Solution {
public:
    vector<int> rearrangeArray(vector<int>&nums ) {
      int n = nums.size();
        vector<int> ans;
      // simply store the index of all the elements and tehn place the elements at that index 
        // int indexpos = 0, indexneg=1;
        // for(auto num: nums){
        //     if(num>0){
        //         ans[indexpos] = num;
        //         indexpos+=2;
        //     }
        //     if(num<0){
        //         ans[indexneg] = num;
        //         indexneg += 2;
        //     }
        // }
      
      
       for(int i = 0 , j = 0 ; i <  n && j < n ; i++ , j++){
          
         while(nums[i] < 0){
           i++ ;
         }
        ans.push_back(nums[i]) ;
         while(nums[j] > 0 ){
           j++ ;
         }
         ans.push_back(nums[j]) ;
       }
        return ans;
    }
};

// so in this question we are given an array of nums and we have to make a pair of numbers with the same sign 
// and also we have to take care that the numbers with same sign maintain their order 
// so lets discuss the approach 
// the approach might be a little bit lengthy but it can do the work 
// lets see if it works 
// so what we can do is that 
// first we can push_back a positive integer
// now when we push_back  a negative integer we need to take care that the element before it is a positive number 
// and if its a positive number then we need to check if the number has not been repeated 
// also this will help us to maintain the order of the elements 
// while pushing a positive integer we can have similar kinds of check that if the element beside is a negative number or not
// and while checking the above condtion we also need to check if that number occurs previously or not 

// now the question remains the way we are going to deal with these cases that we have to complete in order to solve the question
//  {3 -2 1 -5 2 -4 }  
// 3 1 2 | -2 -5 -4  => 3 -2 | 1 -5 | 2 -4