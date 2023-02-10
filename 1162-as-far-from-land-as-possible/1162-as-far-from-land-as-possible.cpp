class node{
  public : 
  int _x , _y ;
  node(int x , int y){
    _x = x ;
    _y = y ;
    
  }
};


//checking if the index lies within the boundaries of the matrix
bool isvalid(int i,int j,int m,int n)
{
        if(i==m||j==n||j<0||i<0)
            return false;
        return true;
}

// coordinates (x,y) for traversing in the graph
int dx[] = {1, 0 , 0 , -1} ; 
int dy[] =  {0 , 1 , -1, 0} ;



class Solution {
public:
    int maxDistance(vector<vector<int>>& mat) {
        vector<vector<int>>  ans ;
        int n = mat.size() ;
        int m = mat[0].size();

        queue<node>  q  ;
        
        for(int i = 0 ; i < n ; i++){
          for(int j = 0 ; j < m ; j++ ){
            //checking if the cell is water or land 
             if(mat[i][j] == 1){
               //if it is a land then push it in the queue 
              q.push(node(i,j)) ;
            }
          }
        }
      int distance = 0 ;
      //traversing each of the land cells 
      while(!q.empty()){
          int x =  q.front()._x ;
          int y =  q.front()._y ;
          q.pop() ;
          for(int i = 0 ; i < 4 ; i++){
            // traversing each of the cells 
                int nx = x + dx[i] ;
                int ny = y + dy[i] ;
            //checking if the cells lie within the boundaries of the matrix and if they are water 
                if(isvalid(nx , ny ,  n , m) && mat[nx][ny] == 0){
                  //if its water then push in the queue
                  q.push(node(nx , ny)) ;
                  //add 1 to distance of the new cell
                  mat[nx][ny] = mat[x][y] +1  ;
                  //check if it is the maximum of all the closest distances 
                  distance = max(mat[nx][ny] , distance) ;
            }
          }
        }
      
      return distance > 0 ? distance -1 : -1  ;
    }
};