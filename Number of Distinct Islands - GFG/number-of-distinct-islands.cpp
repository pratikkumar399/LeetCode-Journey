//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &grid , int x , int y , vector<vector<int>> &visited,  vector<pair<int,int>> & vec ,
  int row ,int col ){
       int n = grid.size() ;
        int m = grid[0].size() ;
        visited[x][y] = 1 ;
        vec.push_back({x- row , y - col}) ;
        vector<pair<int, int>> directions = {{1,0} , {0,1} , { -1 ,0 } , { 0 , -1} } ;
        
        for(auto it : directions){
            int nx  =  x + it.first ;
            int ny =  y + it.second ;
            if(nx  >= 0 && nx < n && ny >= 0 && ny< m && !visited[nx][ny] && grid[nx][ny] == 1){
                dfs(grid , nx , ny ,  visited , vec , row , col  ) ;
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> visited(n , vector<int> (m , 0)) ;
        set<vector<pair<int, int>>> st ;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j< m ;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    vector<pair<int , int>> vec ;
                    dfs(grid , i , j , visited  , vec ,  i  ,  j ) ;
                    st.insert(vec) ;
                }
            }
        }
        
        return st.size() ;
        
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends