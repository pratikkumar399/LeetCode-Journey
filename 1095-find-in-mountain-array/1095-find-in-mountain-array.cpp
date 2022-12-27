/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak = findPeakElement(mountainArr) ;
        int firstTry = binarySearch(mountainArr , 0 , peak , target) ;
      // cout<<firstTry ;
      // cout<<mountainArr.get(peak) ;
      if(firstTry!= -1){
        return firstTry ;
      }
      // cout<<binarySearch(mountainArr ,  peak + 1 , mountainArr.length() - 1 , target) ;
      return binarySearch(mountainArr ,  peak + 1 , mountainArr.length() - 1 , target) ;
    }
  
  int findPeakElement(MountainArray & arr) {
       int n = arr.length() ;
        int start = 0;
        int end = n - 1; 
      
        while(start < end){
          int mid =  start + (end - start) / 2 ;
          
          if(arr.get(mid) < arr.get(mid+ 1)){
            start = mid + 1 ;
            
          }
          else {
            end = mid ;
          }
          
        }
      
      return start ;
    }
  
  int binarySearch( MountainArray &nums , int start , int end  , int target){
    bool asc = false; 
    if(nums.get(start) < nums.get(end)) asc = true ;
    
    while(start <= end){
      int mid = start + (end - start) / 2 ;
      // cout<< nums.get(start)<< " " << nums.get(end)<<" "<< nums.get(mid) <<endl;
       if(nums.get(mid ) == target) {
         return mid ;
           // cout<<nums.get(mid) ;
         } 
        cout<<asc;
        if(asc == true){
          if(nums.get(mid) < target){
            start = mid + 1 ;
          }
          else {
            end = mid - 1; 
          }
        }
      else{
        if(nums.get(mid) > target){
            start = mid + 1 ;
          }
          else {
            end = mid - 1; 
          }
      }
      
      
    }
    
    
    return  -1 ;
    
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
};