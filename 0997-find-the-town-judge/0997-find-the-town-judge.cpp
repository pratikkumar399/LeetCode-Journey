class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      if(trust.empty() && n==1)
            return 1;
      
      vector<int> ans(n+1 , 0) ;  // initialising all the nodes with value 0
      for(auto it :  trust){
        
//         finding indegree and outdegree for each of the nodes 
        // 1, 3 || 2 , 3 --> 1 : -1 , 3 : 1 , 2 : -1 , 3 : 1++ = 2 
//         (1,3) , (2,3) , (3,1) --> 1 : -1 , 3++ : 1 , 2-- : -1 , 3++ : 2 , 3-- : 1 , 1++ : 0
//         since none of the people is trusted by n-1 i.e. 3-1 = 2 other people , therefore no one is judge overhere
        ans[it[0]]-- ;
        ans[it[1]]++ ;
      
      }
      
      for(int i = 1 ; i <=n ;i++){
        
//         checking if the judge is trusted by all the people except himself
        if(ans[i] == n-1) return i ;
      }
      return -1 ;
    }
  
  
 
};