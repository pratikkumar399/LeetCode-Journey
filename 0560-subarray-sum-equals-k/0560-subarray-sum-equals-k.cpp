class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0 ;
        int sum = 0 ;
        unordered_map<int,int> m ;
        // m[sum]++ ;
       
        for(int i = 0 ; i < arr.size(); i++){
           sum  += arr[i];
          if(sum == k ) count++ ;
          
          // 6 - 3 
           int ans = sum - k;
          //1 2 3
          // (1  , 1) (3 , 1)  (6 , 1)  
          
          
             count += m[ans];
          m[sum]++ ;
           }
        return count ;
    }
};

