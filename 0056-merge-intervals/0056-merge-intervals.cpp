class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  res ;
       int n = intervals.size() ;
      if(n <= 1) return intervals;
       
        
      // sorting the intervals 
      sort(intervals.begin() , intervals.end()) ;
      // pushing the initial intervals 
      res.push_back(intervals[0]) ;
        for(int i = 1 ; i <  n  ; i++){
          //now check if the interval can be megerd or not 
          if(res.back()[1] >= intervals[i][0]){
            // check if the last interval is inside the range or not
            res.back()[1] = max(intervals[i][1] , res.back()[1] ) ;
            
          }
          
          else res.push_back(intervals[i]) ;
          
        }
        
      
      return res ;
    }
  
  
  // we need to merge the elements if they overlap 
  // 
};