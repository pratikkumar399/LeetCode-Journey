## Solution using hashing 

> The approach follwed here is that at every index of the given array , we check if the prefixSum(till that element) -target = any element previously found . If that happens , then it means that we have found a subarray with sum equal to k

*Linear time complexity*


```cpp
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count = 0 ;
        int sum = 0 ;
        unordered_map<int,int> m ;
        m[sum]++ ;
       
        for(int i = 0 ; i < arr.size(); i++){
           sum  += arr[i]   ;
           int ans = sum - k ;
           count += m[ans] ;
           m[sum]++ ;
           }
        return count ;
    }
};
```