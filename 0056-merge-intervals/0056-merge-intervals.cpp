class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  res ;
       int n = intervals.size() ;
      if(n <= 1) return intervals;
       
        
      
      sort(intervals.begin() , intervals.end()) ;
      res.push_back(intervals[0]) ;
        for(int i = 0 ; i <  n  ; i++){
          if(res.back()[1] >= intervals[i][0]){
            res.back()[1] = max(intervals[i][1] , res.back()[1] ) ;
            
          }
          
          else res.push_back(intervals[i]) ;
          
        }
        
      
      return res ;
    }
  
  
  // we need to merge the elements if they overlap 
  // 
};