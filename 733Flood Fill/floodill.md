# Solution

## [733. Flood Fill](https://leetcode.com/problems/flood-fill/)

    An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
    You are also given three integers sr, sc, and color. You should perform a flood fill on the image starting from the pixel image[sr][sc].
    To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
    Return the modified image after performing the flood fill.



> dfs approach

```cpp
class Solution {
public:
  
  void dfs(int i , int j , int inColor ,int newColor ,vector<vector<int>> &image){
    int n = image.size() ;
    int m = image[0].size() ;
      if( i < 0 || j < 0) return ;
      if( i >= n || j >= m) return ;
      if(image[i][j] != inColor)  return ;
    
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


    Time Complexity: O(N), where NN is the number of pixels in the image. We might process every pixel.

    Space Complexity: O(N), the size of the implicit call stack when calling dfs

