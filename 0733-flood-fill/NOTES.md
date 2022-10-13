```
class Solution {
public:
void dfs(int i , int j , int inColor ,int newColor ,vector<vector<int>> &image){
int n = image.size() ;
int m = image[0].size() ;
if( i < 0 || j < 0 || i >=  n || j>= m || image[i][j] != inColor) return ;
image[i][j] = newColor ;
dfs(i-1,j,inColor,newColor,image ) ;
dfs(i+1,j,inColor,newColor,image ) ;
dfs(i,j-1,inColor,newColor,image ) ;
dfs(i,j+1,inColor,newColor,image ) ;
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int Color) {
int inColor = image[sr][sc] ;
if(inColor!= Color) dfs(sr,sc,inColor,Color,image) ;
return image ;
}
};
```