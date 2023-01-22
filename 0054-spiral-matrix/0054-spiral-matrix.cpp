class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;
        vector<int> ans ;
        // ans.resize(m*n) ;
        int top = 0 , bottom = n - 1;
        int left = 0 ,  right = m - 1 ;
      
       while(left <= right && top <= bottom){
          
         for(int i = left ; i <= right ; i++)
         {
           ans.push_back(matrix[top][i]) ;
         }
         top++;
         for(int i = top ; i <= bottom  ; i++){
           ans.push_back(matrix[i][right]) ;
         }
         right-- ;
         
         if(left > right or top > bottom ) break ;
         for(int i = right ; i >= left ; i--)
         {
           ans.push_back(matrix[bottom][i]) ;
         }
         bottom--;
         for(int i = bottom  ; i >= top  ; i--){
           ans.push_back(matrix[i][left]) ;
         }
         left++ ;
       }
       return ans ;
       
    } 
};