class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {      
      // Optimized appraoch  -->  using minHeap O(n*log k)
      priority_queue<int> pq ;
      for(auto it : nums){
        pq.push(it) ;
      }
      
      nums.clear() ;
      
      while(!pq.empty()){
        int top = pq.top();
        pq.pop();
        nums.push_back(top) ;
      }
      
      return nums[k-1];
    }
};