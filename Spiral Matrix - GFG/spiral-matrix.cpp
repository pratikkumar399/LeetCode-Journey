//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        // Your code goes here
        int top = 0 ;
        int bottom = n - 1 ;
        int left = 0 ;
        int right = m -1 ;
        vector<int> ans ;
        while(left <= right and top <= bottom){
            for(int i = left ; i <= right ; i++){
                ans.push_back(a[top][i]) ;
            }
            top++ ;
            for(int i = top ; i <= bottom ; i++){
                ans.push_back(a[i][right]) ;
            }
            right-- ;
            
            if(top> bottom or left > right) break ;
            
            for(int i = right ; i >= left ; i--){
                ans.push_back(a[bottom][i]) ;
            }
            bottom-- ;
            for(int i = bottom ; i >= top ; i--){
                ans.push_back(a[i][left]);
            }
            left++ ;
        }
        
        return ans[k-1] ;
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends