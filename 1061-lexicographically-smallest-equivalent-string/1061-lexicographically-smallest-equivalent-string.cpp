class Solution {
public:
  
  void dfs(int source , vector<vector<int>> &mat , vector<int> &visited , vector<int> &component , int &mini){
       //  mark the character as visited 
      visited[source] = 1 ;
    // add it to the list 
     component.push_back(source) ;
    // update the minimum character in the component 
    mini = min(mini , source ) ;
    
    for(int i = 0 ; i < 26  ; i++){
      //perform dfs and if the edge is there aur visited nahi hai
       if(mat[source][i] && ! visited[i]){
         dfs(i , mat , visited ,  component , mini) ;
       }
    }
    
  }
  
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
      // first create a adjacency matrix to store the graph
      // since there are 26 characters in the alphabet there fore we will need a matrix of size 26 * 26
      vector<vector<int>>  mat(26 ,vector<int> (26 , 0)) ;
      
      
      // take size of s1 string 
      int n = s1.size() ;
      
      // now the step to fill the adjacency matrix with the required values 
      for(int i = 0 ;  i < n ; i++){
        mat[s1[i] - 'a'][s2[i] - 'a'] = 1 ;
        mat[s2[i] - 'a'][s1[i] - 'a'] = 1 ;
      } 
      
      vector<int>  mapp(26 , 0) ;
      
      for(int i  = 0 ; i <26 ; i++){
        mapp[i] = i ;
      } 
      
      vector<int>  visited(26 , 0) ;
      
      for(int i = 0 ;  i < 26 ; i++){
        if(!visited[i]){
          vector<int>  component ;
          int mini = 27 ;
          
          dfs(i , mat , visited , component , mini) ;
          
          for(auto vertex : component){
            mapp[vertex] = mini ;
          }
          
        }
      }
      
      string ans ;
      
      for(auto it  : baseStr){
        ans += (char)(mapp[it -'a'] + 'a') ;
      }
      
      return ans ;
      
    }
};


// so we need to group together the words with equivalent value 
// and then sort them lexographically 
// and then find the chars from the basestr in their respective groups 
// after they are found append them to a final answer 