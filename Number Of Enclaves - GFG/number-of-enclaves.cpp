//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    void dfs(int i , int j , vector<vector<int>>  &visited , vector<vector<int>> &grid){
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<pair<int ,int>>  directions = {{1,0}  , {0, 1} , {-1 ,0 } , {0 ,-1}} ;
        visited[i][j] = 1;
        
        for(auto it :  directions){
            int nx  = i + it.first ;
            int ny = j + it.second ;
            
            if(nx >= 0 && nx < n && ny >=0 && ny < m && !visited[nx][ny] && grid[nx][ny] == 1){
                dfs(nx , ny , visited , grid ) ;
            }
            
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> visited (n +1 , vector<int> (m , 0)) ;
        queue<pair<int, int>>  q ;
        
        for(int i = 0 ; i < n ;i++){
            //firstcol
            
            if(!visited[i][0]  && grid[i][0] == 1){
                dfs(i , 0  , visited , grid) ;
            }
            
            //last col 
            
            if(!visited[i][m-1]  && grid[i][m-1] == 1){
                dfs(i  , m-1, visited , grid) ;
            }
        }
        
         for(int i = 0 ; i < m ;i++){
            //firstrow
            
            if(!visited[0][i]  && grid[0][i] == 1){
                dfs(0 , i , visited , grid) ;
            }
            
            //last col 
            
            if(!visited[n-1][i]  && grid[n-1][i] == 1){
                dfs(n-1  , i, visited , grid) ;
            }
        }
        
        int count = 0 ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    count++ ;
                }
            }
        }
        
        return count  ;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends