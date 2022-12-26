class Solution {
public:
    
  // since we are finding the first occurence of a digit so we search in the left side 
  // even if the target is found continue searching the left side to get the correct answer 
    int binarysearch(vector<int> &nums ,int target , bool ans){
        int start = 0 ;
        int end = nums.size() - 1 ;
        int result = -1 ;
        
        while(start <= end){
            int mid = start + (end -start) /2 ;
            
            if(nums[mid] == target){
                result = mid ;
                if(ans == true){
                  end = mid - 1 ;
                }
              else {
                start = mid + 1;
              }
               
                
            }
            else if(target  < nums[mid]){
                end = mid - 1 ;
            }
            else{
               start = mid + 1 ; 
            }
        }
        return result ;
    } 
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        bool ans =  false;
        int first = binarysearch(nums,target , true) ;
        int last = binarysearch(nums,target ,  false ) ;
        
        vector<int> out ;
        out.push_back(first) ;
        out.push_back(last) ;
        
        return out ;
        
        
        
    }
};