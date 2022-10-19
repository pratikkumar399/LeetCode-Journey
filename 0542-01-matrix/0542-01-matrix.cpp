class node{
  public : 
  int _x , _y ;
  node(int x , int y){
    _x = x ;
    _y = y ;
    
  }
};

//checking for valid input 
 bool isvalid(int i,int j,int m,int n)
    {
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
    }

//marking the coordinates of the matrix 
 int dx[] = {1, 0 , 0 , -1} ;
 int dy[] =  {0 , 1 , -1, 0} ;
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>  ans ;
      //get the number of rows
        int n = mat.size() ;
      //get the number of coloumns
        int m = mat[0].size() ;
      
      //making a queue of node class
        queue<pair<int,int>>  q  ;
        // initially taking all the distances as -1
      vector<vector<int>>  distance(n , vector<int>(m , -1)) ;
      
      // if the element in the row is zero mark the distance as zero and then we will store the node in the queue
      for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++ ){
          if(mat[i][j] == 0){
            q.push(make_pair(i,j)) ;
            distance[i][j] = 0 ;
          }
        }
      }
        
      while(!q.empty()){
        //getting x and y coordinates of the matrix 
        auto [x,y] = q.front() ;
        q.pop() ;
        for(int i = 0 ; i < 4 ; i++){
          int nx = x + dx[i] ;
          int ny =  y + dy[i] ;
          if(isvalid(nx , ny ,  n , m) && distance[nx][ny] == -1){
            q.push(make_pair(nx , ny)) ;
            distance[nx][ny] = distance[x][y] +1  ;
          }
        }
      }
      
      return distance ;
    }
};