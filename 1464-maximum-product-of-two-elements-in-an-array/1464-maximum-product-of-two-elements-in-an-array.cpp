class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> pq ;
        for(auto it : nums){
          pq.push(it);
        }
      nums.clear();
      while(!pq.empty()){
        int top = pq.top() ;
        pq.pop() ;
        nums.push_back(top) ;
      }
      
      return  (nums[0] - 1) * (nums[1] -1) ;
    }
};