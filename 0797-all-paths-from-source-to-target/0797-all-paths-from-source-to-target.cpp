class Solution {
public:
  
    void  path(vector<vector<int>> &res, vector<vector<int>>  &graph ,  int currNode, vector<int> &currPath ,int n  , vector<bool>  &visited){ 
      
      // if the currentNode has reached the last node i.e. n-1 than we have reached our required destination 
      if(currNode ==n-1){
        //storing all the currentPaths in a container 
        res.push_back(currPath) ;
        return  ;
      }
  
      
      //now the traversal trhough a particular path in a graph 
      for(auto it :  graph[currNode])
      { 
        //add each node in the currentPath
        currPath.push_back(it) ;
        // apply dfs for each path
        path(res ,  graph , it , currPath ,  n ,visited ) ;
        //
        currPath.pop_back() ;
      }      
     
      
      
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      //variable to store all the paths that form a path from source to target
            vector<vector<int>> res ;
      //to traverse all the current node paths in the graph 
            vector<int>  currPath ;
            int n = graph.size() ;
      //maintaining a visited container
            vector<bool>  visited(n) ;
      //starting the current traversal from 0th vertex 
            currPath.push_back(0) ;
            path(res , graph , 0 , currPath , n , visited) ;
            
      return res ;
    }
};