class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int , vector<int> , greater<int>> pq ;
      
      for(auto it : matrix){
        for(auto i : it){
          pq.push(i) ;
        }
      }
      
      int count = 0 ;
      while(!pq.empty()){
        if(k== 1) break;
        int top = pq.top();
        pq.pop() ;
        cout<<"top-> "<<  top<<" " ;
        count++ ;
        cout<<count <<endl ;
        
        if(count  == k - 1) break ;
      }
      return pq.top() ;
    }
};