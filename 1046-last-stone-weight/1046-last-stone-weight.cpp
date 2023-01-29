class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
      
       for(auto it : stones){
         pq.push(it) ;
       }
       while(pq.size() > 1){
          int largest = pq.top() ;
          pq.pop() ;
          int second_largest = pq.top() ;
          pq.pop() ;         
          if(largest - second_largest > 0) {
             pq.push(largest - second_largest) ;
          }
       }
      
      
       if(!pq.empty()) return pq.top() ;
      
       return 0 ;
      
      }
};