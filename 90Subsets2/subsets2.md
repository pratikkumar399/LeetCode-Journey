## Solution

    > 1st approach : Brute Force approach (set with recursion)
    time complexity 0(2^n * nlog(n) ) + 0(n) + 0(nlogn)

```cpp
class Solution {
  public:
  //  time complexity 0(2^n * nlog(n) ) + 0(n) + 0(nlogn) 
    set<vector<int>> st;
    void subsets(int index , vector<int> &arr , vector<int> &ds){
        if(index == arr.size()){
            st.insert(ds) ;
            return ;
        }
        subsets(index+1,arr,ds);
        ds.push_back(arr[index]) ;
        subsets(index+1,arr,ds) ;
        ds.pop_back();
    }
    vector<vector<int> > subsetsWithDup(vector<int>& A)
    {
        //code here
      sort(A.begin() , A.end()) ;
        vector<vector<int>> ans ;
        vector<int> ds ;
        subsets(0, A , ds) ;
        for(auto &it : st){
          ans.push_back(it) ;
        }
       
        return ans;
    }
};
```
    2nd approach : Optimized approach 
    Time Complexity  - O(2^n * n) 

```cpp
class Solution {
  public:
  //  time complexity 0(2^n * n)
    void subsets(int index , vector<int> &arr , vector<int> &ds , vector<vector<int>> &ans){
        ans.push_back(ds);
      for(int i = index ; i < arr.size() ; i++){
        //   chechking if the first instance of the elemnent is considered in the subset --> if there is a duplicate element then we will not pick it and move onto the next element
        if(i != index && arr[i] == arr[i-1]) continue ;
        
        ds.push_back(arr[i]) ;
        subsets(i+1,arr,ds,ans) ;
        ds.pop_back();
      }
       
    }
    vector<vector<int> > subsetsWithDup(vector<int>& A)
    {
        //code here
        sort(A.begin() , A.end()) ;
        vector<vector<int>> ans ;
        vector<int> ds ;
        subsets(0, A , ds ,ans ) ;
       
        return ans;
    }
};


```