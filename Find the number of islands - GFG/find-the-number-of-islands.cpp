//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    bool isvalid(int i,int j,int m,int n , vector<vector<int>>  &visited)
    {
        if(i==m||j==n||j<0||i<0 ||visited[i][j]==1)
            return false;
        return true;
    }
    
    void bfs(int row , int col , vector<vector<int>>  &visited , vector<vector<char>>  &grid  ){
         vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1} , {1,1} , {-1,-1} , {1,-1} , {-1 , 1}}; 
          int n = grid.size() ;
        int m = grid[0].size() ;
        visited[row][col] = 1 ;
        queue<pair<int,int>>  q ;
        q.push({row , col})  ;
        while(!q.empty()){
            auto top = q.front() ;
            q.pop() ;
            
            for(auto it : directions){
                int nx = top.first + it.first ;
                int ny = top.second + it.second ;
                
                if(isvalid(nx, ny , n , m , visited) && grid[nx][ny] == '1'){
                    visited[nx][ny] = 1 ;
                    q.push(make_pair(nx,ny)) ;
                }
            }
            
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        int islands = 0 ;
        vector<vector<int>> visited(n+1 , vector<int> (m , 0)) ;
        
        for(int i = 0 ; i <  n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(isvalid(i , j, n , m , visited) && grid[i][j] == '1'){
                    bfs(i , j , visited , grid ) ;
                    islands++ ;
                }
            }
        }
    return islands ;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends