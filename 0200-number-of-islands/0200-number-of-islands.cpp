class Solution {
public:
    
    bool isValid(int i , int j , int n  , int m){
        return (i< 0 or i >= n  or j < 0 or j >= m);
    }
    
    
    void dfs(vector<vector<char>> &grid , int i , int j , int n , int m){
        if( (i< 0 or i >= n  or j < 0 or j >= m) or grid[i][j] != '1') return  ;
        
        grid[i][j] = ' 2' ;
        dfs(grid , i + 1 , j  , n , m);
        dfs(grid , i  , j - 1 , n , m);
        dfs(grid , i  , j + 1  , n , m);
        dfs(grid , i - 1 , j  , n , m);
           
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size();
        if(n == NULL) return 0 ;
        
        
        int count = 0 ; 
        for(int i = 0 ; i < n ;i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == '1'){
                    dfs(grid , i , j , n , m) ;
                    count++ ;
                }
            }
        }
        
        return count ;
    }
};
// class Solution {
//     void make_current_island(vector<vector<char>> &matrix , int x , int y , int r , int c){
//         if(x < 0 || x >= r ||y < 0  || y>= c || matrix[x][y] != '1'){
//             return ;
//         }
//         matrix[x][y] = ' 2' ;
//         make_current_island (matrix , x+1 , y , r,c) ;
//          make_current_island (matrix , x , y+1 , r,c) ;
//          make_current_island (matrix , x-1 , y , r,c) ;
//          make_current_island (matrix , x , y-1 , r,c) ;
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//        int rows = grid.size() ;
//         if(rows ==  NULL) {
//             return 0 ;
//         }
//         int cols = grid[0].size() ;
//         int no_of_islands =  0 ;
//         for(int i= 0 ; i<rows  ; i++){
//             for(int j =  0 ; j <cols ;j++){
//                 if(grid[i][j] == '1'){
//                     make_current_island(grid,i,j,rows , cols) ;
//                     no_of_islands += 1 ;
//                 }
//             }
//         }
//         return no_of_islands ;
//     }
// };

