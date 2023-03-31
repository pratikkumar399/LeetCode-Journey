class Solution {
public:
    
    bool isValid(int i , int j , int n  , int m){
        return (i< 0 or i >= n  or j < 0 or j >= m);
    }
    
    
    void dfs(vector<vector<char>> &grid , int i , int j , int n , int m){
        if( isValid(i , j , n , m) or grid[i][j] != '1') return  ;
        
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
