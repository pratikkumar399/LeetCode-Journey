//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    // code here
	    map<int, int >  mp ;
	    
	    int maxi = 0 ;
	   // int ans  = 0 ;
	    int count = 0 ;
	    
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < m ; j++){
	            if(arr[i][j] == 1)
	                count++ ;
	               // mp[i]++ ;
	        }
	        mp[i] = count ;
	        maxi = max(count , maxi) ; 
	        count = 0 ;
	        
	         
	    }
	   // int mint ini = 0 ;
	   
	   if(maxi == 0) return -1 ;
	    vector<int> mini ;
	    for(auto it : mp){
	        
	        if(it.second == maxi) {
	            int ans = it.first ;
	            
	            mini.push_back(ans) ;
	        }
	        
	       // cout<<it.first<<" "<<it.second <<endl ;
	    }
	    
	    return *min_element(mini.begin() , mini.end()) ;
	   
	}
	
	

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends