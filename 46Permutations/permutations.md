## Solution: 

- Approach #1 : Recursion using a data structure to mark the elements as picked or not picked 

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> ds ;
        int map[nums.size()];  //data structure to mark the elements
        for(int i = 0 ; i< nums.size() ;i++) map[i] = 0 ; // --> marking all the elements as 0 
        findPermutation(ans, ds , nums , map);
        return ans ;
    }
  
    void findPermutation(vector<vector<int>> &ans, vector<int> &ds , vector<int> &nums , int map[]){
        if(ds.size() ==nums.size()){
          ans.push_back(ds) ;
          return ;
        }
        for(int i = 0 ; i <nums.size() ;i++){
          if(map[i] != 1) {  // --> checking if the elements have been marked or not
            ds.push_back(nums[i]) ;
            map[i] = 1 ;
            findPermutation(ans,ds,nums, map) ; //-> after the elements gets picked , unmark it so that it can be available for making other permutation of the array .
            map[i] = 0 ;
            ds.pop_back() ;
          }
        }
    }
};

// Time complexity --> O(n! * n) 
// Space complexity --> O(n) + O(n) -->(extra space for the mapping data structure)
```
- Approach #2 :  Recursion with no other data structure for picking and not picking the elements

```cpp
class Solution {
public:
  
  
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans ;
        findPermutation(0, ans, nums);
        return ans ;
    }
  
    void findPermutation(int index  ,vector<vector<int>> &ans, vector<int> &nums){
        if(index ==nums.size()){
          ans.push_back(nums) ; //--> if  all the elements are checked , it is a possible permutation so push that in the the ans vector
          return ;
        }
        for(int i = index ; i <nums.size() ;i++){
         swap(nums[index] , nums[i]) ;  // --> swap the element with itself 
          findPermutation(index+1,ans,nums) ; // --> moving onto the next element
          swap(nums[index] , nums[i]) ; //swapping the element with its next adjacent element
        }
    }
};
```