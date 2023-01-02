//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int arr[], int n)
    {
        // code here 
        
        int mid = 0 ;
        int low =  0 ;
        
        while(mid < n){
            if(arr[mid] == 0) {
                swap(arr[mid] , arr[low]) ;
                mid++ ;
                low++ ;
            }
            else if(arr[mid] == 1) {
                mid++ ;
            }
            else if(arr[mid] == 2){
                swap(arr[mid] , arr[n-1]) ;
                n-- ;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends