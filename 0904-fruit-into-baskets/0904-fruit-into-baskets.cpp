class Solution {
public:
  
    static bool cmp(const pair<int, int> a , const pair<int, int> b){
        return  a.second < b.second ;
    }
    
    int totalFruit(vector<int>& fruits) {
        int count = 0 ; 
        map<int, int>  m ;
        
       int start = 0 ;
       int end = 0 ;
       int maxi = INT_MIN ;
        for(auto it : fruits){
           m[fruits[end]]++ ;
           end++ ;
            while(m.size() >  2){ 
              m[fruits[start]]-- ;
            // we can remove that element from the map
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