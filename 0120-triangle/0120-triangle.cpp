class Solution {
public:
  
 
    int minimumTotal(vector<vector<int>>& triangle) {
          int n = triangle.size() ;
      // vector<vector<int>>  dp (n  , vector<int> (n , 0)) ;
      vector<int>  front(n ,  0) ,  cur(n , 0) ;
      
      
      // initially taking up all the last rows value for the dp matrix
      for(int i = 0 ; i < n ;i++) front[i] = triangle[n-1][i] ;
      for(int i = n-2 ;  i>= 0 ; i--){
        for(int j = i ; j >= 0 ; j--){
          int left = triangle[i][j] + front[j] ;
          int right = triangle[i][j] + front[j+1] ;
          cur[j] = min(left , right) ;
        }
        front = cur ;
      }
          return front[0] ;
    }
};


