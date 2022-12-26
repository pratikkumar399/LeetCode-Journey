class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size() ;
        int start = 0;
        int end = n - 1; 
      
        while(start < end){
          int mid =  start + (end - start) / 2 ;
          
          if(arr[mid] > arr[mid + 1]){
            end = mid  ;
          }
          else {
            start = mid + 1  ;
          }
          
        }
      
      return start ;
    }
};