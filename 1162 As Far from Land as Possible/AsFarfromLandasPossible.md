# Solution

## [As Far from Land as Possible](https://leetcode.com/problems/as-far-from-land-as-possible/)

    Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.

    The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.

> bfs approach

```cpp
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
             if(mat[i][j] == 1){
              q.push(node(i,j)) ;
            }
          }
        }
      int distance = 0 ;
      
      while(!q.empty()){
          int x =  q.front()._x ;
          int y =  q.front()._y ;
          q.pop() ;
          for(int i = 0 ; i < 4 ; i++){
                int nx = x + dx[i] ;
                int ny = y + dy[i] ;
                if(isvalid(nx , ny ,  n , m) && mat[nx][ny] == 0){
                  q.push(node(nx , ny)) ;
                  mat[nx][ny] = mat[x][y] +1  ;
                  distance = max(mat[nx][ny] , distance) ;
            }
          }
        }
      
      return distance > 0 ? distance -1 : -1  ;
    }
};
```


    Time complexity: O(r⋅c)
    Space complexity:O(r⋅c)
    An additional O(r⋅c) space is required to maintain the queue.

