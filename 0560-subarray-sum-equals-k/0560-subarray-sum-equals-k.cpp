class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0 ;
        int sum = 0 ;
        unordered_map<int,int> m ;
        m[sum]++ ;
       
        for(int i = 0 ; i < arr.size(); i++){
           sum  += arr[i];
           // if(sum == k ) count++ ;
           int ans = sum - k;
           count += m[ans];
           m[sum]++ ;
          }
        return count ;
    }
};

