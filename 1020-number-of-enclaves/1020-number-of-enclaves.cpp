class Solution {
public:
  
    bool isBorder(int i , int j , int n , int m){
      return (i == n-1 || j == m-1 || i == 0 || j== 0) ;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<pair<int , int>> directions = {{1,0} , { 0,1} , {-1 ,0} , {0,-1}} ;
        vector<vector<int>>  visited(n+1 , vector<int> (m , 0)) ;
        queue<pair<int, int >>  q ;
        
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1 && isBorder(i,j , n , m) && !visited[i][j] ){
              visited[i][j] = 1;
              q.push({i , j}) ;
        
            }
          }
        }
      
        while(!q.empty()){
          auto top = q.front() ;
          q.pop() ;
          
          for(auto it: directions){
            int nx = top.first + it.first;
            int ny = top.second + it.second;
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1 && !visited[nx][ny] ){
              visited[nx][ny] = 1 ;
              q.push({nx, ny}) ;
            }
          }
        }
          int count = 0 ;
          for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 1  && !visited[i][j] ){
              count++ ;
            }
          }
        }
          
          return count ;
     } 
};