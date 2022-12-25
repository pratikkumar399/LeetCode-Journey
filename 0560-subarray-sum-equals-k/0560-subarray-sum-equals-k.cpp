class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0 ;
        int sum = 0 ;
        unordered_map<int,int> m ;
        m[sum]++ ;
       
        for(int i = 0 ; i < arr.size(); i++){
           sum  += arr[i];
           int ans = sum - k;
          if(m.find(ans) != m.end()){
             count += m[ans];
          }
          m[sum]++ ;
           }
        return count ;
    }
};