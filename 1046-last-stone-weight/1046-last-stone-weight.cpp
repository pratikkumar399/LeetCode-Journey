class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq ;
      
       for(auto it : stones){
         pq.push(it) ;
       }
       int size = stones.size() ;
       while(size > 1){
          int largest = pq.top() ;
          pq.pop() ;
          int second_largest = pq.top() ;
          pq.pop() ;
          size = size - 2 ;
         
          if(largest - second_largest > 0) {
             pq.push(largest - second_largest) ;
             size = size + 1 ;
          }
       }
      
      
       if(!pq.empty()) return pq.top() ;
      
       return 0 ;
      
      }
};