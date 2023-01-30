class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
      // x ^2  - y ^2  =  r *r 
      vector<int> ans(queries.size()) ; 
       
      for(int i = 0 ; i < queries.size() ; i++){
        int x = queries[i][0] ;
        int y = queries[i][1] ;
        int r = queries[i][2] ;
        
        for(auto it : points){
           if((x - it[0]) * (x - it[0]) + (y - it[1]) * (y - it[1])   <= r * r) 
             ans[i]++ ;
        }
      }
      return ans ;
    }
};