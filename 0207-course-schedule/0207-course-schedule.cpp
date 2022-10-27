class Solution {
public:
  
   
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
      
      vector<vector<int>> graph(n) ;
       vector<int>  indegree(n,0);
      for(auto it : prerequisites){
        graph[it[1]].push_back(it[0]);
	            indegree[it[0]]++ ;
      }
	     queue<int> q ;
	    
	    
	    for(int i = 0 ; i <n ; i++){
	        if(indegree[i] == 0){
	            q.push(i) ;
	        }
	    }
      int count = 0;
	    while(!q.empty()){
	        auto top = q.front() ;
	        q.pop() ;
        count++ ;
	        for(auto it : graph[top]){
	            if(--indegree[it] == 0){
	            q.push(it) ;
	        }
	        }
	        
	    }
	    
	    if(count == n){
        return true ;
      } 
      return false ;
    }
};