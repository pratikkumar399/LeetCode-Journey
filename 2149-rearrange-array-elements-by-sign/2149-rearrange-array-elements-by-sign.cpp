class Solution {
public:
    vector<int> rearrangeArray(vector<int>&nums ) {
      int n = nums.size();
        vector<int> ans(n);
      // simply store the index of all the elements and tehn place the elements at that index 
        int indexpos = 0, indexneg=1;
        for(auto num: nums){
            if(num>0){
                ans[indexpos] = num;
                indexpos+=2;
            }
            if(num<0){
                ans[indexneg] = num;
                indexneg += 2;
            }
        }
      
     return ans ; 
    }
      
//        for(int i = 0 , j = 0 ; i <  n && j < n ; i++ , j++){
          
//          while(nums[i] < 0){
//            i++ ;
//          }
//         ans.push_back(nums[i]) ;
//          while(nums[j] > 0 ){
//            j++ ;
//          }
//          ans.push_back(nums[j]) ;
//        }
//         return ans;
    
};



// now the question remains the way we are going to deal with these cases that we have to complete in order to solve the question
//  {3 -2 1 -5 2 -4 }  
// 3 1 2 | -2 -5 -4  => 3 -2 | 1 -5 | 2 -4