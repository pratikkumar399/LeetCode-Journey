class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
          int n = intervals.size()  ;
           
          vector<vector<int>> res  ;
          int   i = 0 ;
        
        // case 1 when there is no overlapping means the case when the first of the newIntervals is 
      // smaller than the second value of the intervals current node [a, b]  && [c , d]   b > c 
          while(i < n  ){
            if(newInterval[0] > intervals[i][1] ){
               res.push_back(intervals[i]) ;
            }
            
            // if in any case we reach a point where the first vakue of the intervals 
            // is greater than the second value of the newInterval then we can not 
            // insert anything in the intervals because the values inside has been already sorted 
            else if(intervals[i][0] > newInterval[1]){
              break ;
            }
            else{
              newInterval[0] = min(newInterval[0] ,intervals[i][0] );
              newInterval[1] = max(newInterval[1]  , intervals[i][1]) ;
            }
            
            i++  ;
           
            
          }
      
      // case 2 :  when there is an overlapping case 
      
      // means that we have a case when we need to merge the intervals 
      // what we have to while mergring is that we need to merge the smaller values first and then
      // we have to merge the larger values afterwards 
      
           res.push_back(newInterval) ;
        
      // case 3 :  after all the intervals have been merged from the newIntervals 
      // we just have to push the intervals in the answer 
          while(i < n){
             res.push_back(intervals[i]) ;
             i++ ;
          }
      return res  ; 
    }
};