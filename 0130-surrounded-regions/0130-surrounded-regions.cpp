class Solution {
public:
    
  bool isValid(int i , int j , int n , int m){
    return (i >= 0 && i < n && j >= 0 && j< m);
      
    
  }
    bool isBorder(int i , int j , int n , int m){
      return ( i == n-1 || j == m -1 || i == 0 || j== 0);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size() ;
        int m = board[0].size() ;
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}}; 
        
        queue<pair<int, int>>  q ;
        
         for(int i = 0 ; i <n ; i++){
           for(int  j = 0 ; j < m ; j++){
             if(board[i][j] == 'O' && isBorder(i , j , n , m)){
               board[i][j] = '.' ;
               q.push(make_pair(i , j)) ;
             }
           }
         }
      
      while(!q.empty()){
        auto top = q.front() ;
        q.pop() ;
        
        for(auto it : directions){
          int nx = top.first + it.first ;
          int ny = top.second + it.second ;
          
          if(isValid(nx , ny , n , m) && board[nx][ny] == 'O'){
              board[nx][ny] ='.' ;
              q.push(make_pair(nx,ny)) ;
            
          }
        }
      }
      
      for(int i = 0 ; i <n ; i++){
           for(int  j = 0 ; j < m ; j++){
             if(board[i][j] == 'O'){
               board[i][j] = 'X' ;
             }else if(board[i][j] == '.'){
               board[i][j] = 'O' ;
             }
           }
         }
    
    }
};