class Solution {
public:
    int maxProfit(vector<int>& prices) {
      
      
      int least =  INT_MAX ;
      int profit = 0 ;
      int price= 0 ;
      
      for(int i = 0 ; i < prices.size() ; i++){
        if(prices[i] < least ){
          least = prices[i] ;
        }
        price = prices[i] - least ;
        profit = max(profit , price ) ;
      }
      
      return profit ;
    }
};

// a variety of kadanes algorithm 
// so the question basically needs us to purchase an item on any given day and sell it in the future 
// and we have to do that is such a way that the profit gets maximized 
// wo lets discuss the approach for the question
// we are required to find pair that can give us the maximum profit 
// so what we can do is that first find a day on which we can buy an item 
// now suppose it the number is arranged in the descinding order then it is certain that we cannot take that option
// like we can only take an option if the result that we are getting gives a profit 
// otherwise that option will not be considered 
// so the appraoch that we are going to take is that we will maintain two variables which will store our current price 
// and max price and then we can take the max of both of them 
