class Solution {
public:
    
    int binarysearch(vector<int> &nums ,int target){
        int start = 0 ;
        int end = nums.size() - 1 ;
        int result = -1 ;
        
        while(start <= end){
            int mid = start + (end -start) /2 ;
            
            if(nums[mid] == target){
                result = mid ;
                end = mid - 1 ;
               
                
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
    
    
     int binarysearch2(vector<int> &nums ,int target){
        int start = 0 ;
        int end = nums.size() - 1 ;
        int result = -1 ;
        
        while(start <= end){
            int mid = start + (end -start) /2 ;
            
            if(nums[mid] == target){
                result = mid ;
               
                start = mid + 1 ;
                
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
        
        int first = binarysearch(nums,target) ;
        int last = binarysearch2(nums,target) ;
        
        vector<int> out ;
        out.push_back(first) ;
        out.push_back(last) ;
        
        return out ;
        
        
        
    }
};