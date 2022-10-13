class Solution {
public:
  
  bool isvalid(int i,int j,int m,int n)
    {
        if(i>=m||j>=n||j<0||i<0)
            return false;
        return true;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n =  image.size() ;
        int m = image[0].size() ;
      
        vector<pair<int,int>> directions={{1,0},{-1,0},{0,1},{0,-1}}; 
      
        queue<pair<int, int>>  q ;
          
        int inColor = image[sr][sc] ;
        
        if(image[sr][sc] == color) return image ;
      
        q.push({sr,sc}) ;
        image[sr][sc] =color ;
      
        while(!q.empty()){
          auto top = q.front() ;
          q.pop() ;
          
          for(auto it : directions){
            int nx = top.first + it.first ;
            int ny = top.second + it.second ;
            
            if(isvalid(nx,ny , n, m) && image[nx][ny] == inColor){
              q.push({nx,ny}) ;
              image[nx][ny] = color ;
            }
          }
        }
      
      return image ;
        
    }
};