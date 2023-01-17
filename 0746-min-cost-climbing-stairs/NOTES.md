### Tabulation for the problem
```cpp
int minCostClimbingStairs(vector<int>& cost) {
int n = cost.size() ;
vector<int>  dp(n ) ;
int prev =  0 ;
int prev2 = 0 ;
for(int i = n-1 ; i >= 0 ; i--){
int curi = 0  ;
curi  = cost[i] + min(prev , prev2) ;
prev = prev2 ;
prev2 = curi ;
}
return min(prev , prev2);
}
​
```