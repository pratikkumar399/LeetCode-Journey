//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int> maxi ; 
        unordered_map<int, int> um;
        priority_queue<int> ans ;
        for(int i = 0 ; i < k ; i ++){
            ans.push(arr[i]) ;
            um[arr[i]]++ ;
        }
        maxi.push_back(ans.top()) ;
        
        for(int i = k ; i < n ; i++){
            um[arr[i]]++ ;
            um[arr[i - k]]-- ;
            ans.push(arr[i]) ;
            
            while(!um[ans.top()]){
                ans.pop() ;
            }
            
            maxi.push_back(ans.top()) ;
        }
        
        return maxi ;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends