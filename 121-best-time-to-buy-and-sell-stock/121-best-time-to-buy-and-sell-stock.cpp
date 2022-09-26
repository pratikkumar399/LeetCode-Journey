class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int min = *min_element(prices.begin() , prices.end()) ;
        
          int least_price = INT_MAX ;
          int profit_today = 0 ,  max_profit=0;
      
        for(int i = 0 ; i < prices.size() ; i++){
            if(prices[i] < least_price ){
              least_price = prices[i] ;
            }
            profit_today = prices[i] - least_price ;
            
            if (max_profit < profit_today){
              max_profit = profit_today ;
            }
            
        }
      
      return max_profit ;
    }
};