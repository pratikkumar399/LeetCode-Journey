class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int> mp ; 
        
      for(auto it : arr){
        mp[it]++; 
      }
      
      priority_queue<int,vector<int> , greater<int>> pq ;
      
      for(auto it : mp){
         pq.push(it.second) ;
      }
      
      while(k > 0){
         k  -= pq.top() ;
         if(k >= 0) pq.pop() ;
      }
      
      
      return pq.size() ;
    }
};

// 1 1 2 3 3 3 4 