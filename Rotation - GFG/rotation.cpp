//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int ans = 0 ;
	   // int n = sizeof(arr)/sizeof(int) ;
	    int mini = INT_MAX ;
	    for(int i = 0 ; i < n  ; i++){
	        if(mini > arr[i]){ mini = arr[i] ;
	            ans  = i ;
	        }
	        
	    }
	    
	    return ans ;
	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends