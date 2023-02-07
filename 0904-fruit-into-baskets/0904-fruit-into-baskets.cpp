class Solution {
public:
  
    int totalFruit(vector<int>& fruits) {
        int count = 0 ; 
        unordered_map<int, int>  m ;
        
       int start = 0 ;
       int end = 0 ;
       int maxi = INT_MIN ;
        while(end<fruits.size()){
           m[fruits[end]]++ ;
           end++ ;
            while(m.size() >  2){ 
              m[fruits[start]]-- ;
              if(m[fruits[start]] == 0){
              m.erase(fruits[start]) ; 
            }
            start++ ;
          }
           maxi =max(maxi , end - start);
        }
        return maxi ;
    }
};