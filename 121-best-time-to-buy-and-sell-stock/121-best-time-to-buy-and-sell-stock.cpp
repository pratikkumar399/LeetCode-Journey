class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
      
      //improved version of kadane's algo 
      int current_price = 0 ; 
      int max_price = 0 ;
      
      for(int i = 1 ; i < prices.size() ; i++){
        current_price = max(0 , (current_price += prices[i] - prices[i-1])) ;
        max_price = max(current_price , max_price) ;
      }
          return max_price ;
    }
};