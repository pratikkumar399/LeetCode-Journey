class Solution {
public:
      
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>> dp(n ,vector<int> (m , 0)) ;
        vector<int> prev(m , 0) ;
        for(int i = 0 ; i < n ; i++){
           vector<int> cur(m , 0) ;
          for(int j = 0 ; j < m ; j++){
           
            if(i== 0 && j == 0) cur[j] = grid[0][0] ;
            else{
                int up = grid[i][j] ;
                if(i> 0 ) up +=  prev[j] ;
                else up+= 1e9 ;
              
              
                int left = grid[i][j] ;
                if(j>0) left +=  cur[j-1] ;
                else left += 1e9 ;
              
              
                cur[j] = min(left , up ); 
            }
          }
          prev = cur ;
        }
        
        return prev[m-1];
    }
};
// cost is the minimum path of the current paths alongwith the sum of previous paths