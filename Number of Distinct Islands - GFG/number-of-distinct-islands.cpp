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
        
        // visiting the node 
        visited[x][y] = 1 ;
        
        // storing the coordinates of graph (x - row)(y - col)  
        vec.push_back({x- row ,y - col});
        // pair of directions
        vector<pair<int, int>> directions = {{1,0} ,{0,1} , {-1 ,0} , {0 , -1}} ;
        
        for(auto it : directions){
            // move in other directions 
            int nx  =  x + it.first ;
            int ny =   y + it.second ;
            // defining the boundaries of our search space
            // if the element is within the boundary and not visited 
            if(nx  >= 0 && nx < n && ny >= 0 && ny< m && !visited[nx][ny] && grid[nx][ny] == 1){
                // then we can simply run a dfs search on it 
                dfs(grid , nx , ny ,  visited , vec , row , col  ) ;
            }
        }
    }
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        // n is the row size 
        int n = grid.size() ;
        // m is the column size
        int m = grid[0].size() ;
        
        vector<vector<int>> visited(n , vector<int> (m , 0)) ;
        
        // to store if the islands are same 
        set<vector<pair<int, int>>> st ;
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j< m ;j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    // make a vec pair to store the x and y coordinates
                    vector<pair<int , int>> vec ;
                    // if not visited then make a dfs call
                    dfs(grid , i , j , visited  , vec ,  i  ,  j ) ;
                    // storing the vector 
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