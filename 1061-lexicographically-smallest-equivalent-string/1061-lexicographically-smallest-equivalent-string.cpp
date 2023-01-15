class Solution {
public:
  
  void dfs(int source , vector<vector<int>> &mat , vector<int> &visited , vector<int> &component , int &mini){
      //  mark the character as visited 
      visited[source] = 1 ;
     // add it to the list 
    // after the component gets visited we need to add it inside out list 
     component.push_back(source) ;
    // update the minimum character in the component 
    // and then we have to take the minimum char out of all the chars 
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
        // mat[a].push_back(b) 
        // mat[b].push_back(a) 
        mat[s1[i] - 'a'][s2[i] - 'a'] = 1 ;
        mat[s2[i] - 'a'][s1[i] - 'a'] = 1 ;
      } 
      
      
      vector<int>  mapp(26 , 0) ;
      // mapping of the characters , since there are 26 char therefore we need to  
      for(int i  = 0 ; i <26 ; i++){
        mapp[i] = i ;
      } 
      
      
      // creating a visited matrix 
      vector<int>  visited(26 , 0) ;
      
      for(int i = 0 ;  i < 26 ; i++){
        //checking if each of the chracters has been visited
        if(!visited[i]){
          vector<int>  component ;
          // since we have to store the chars in sorted order , therefore we need to store the minimum chars first
          // and since there are only 26  chars therfore we are taking 27 as the threshold 
          int mini = 27 ;
          
          // run a dfs call on the given char 
          dfs(i , mat , visited , component , mini) ;
          
          
          // ab hamare pas components hain aur hmko min chars le ke chlna hoga aur usko store krna hoga 
          // kuki question me yhi pucha ja rha hain
          for(auto vertex : component){
            mapp[vertex] = mini ;
          }
          
        }
      }
      
      string ans ;
      
      // now simply we have to find the matching of the chars 
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