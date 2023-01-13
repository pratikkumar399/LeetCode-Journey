class Solution {
public:
    int lengthOfLastWord(string s) {
        // for(auto it : s){
        //   cout<< it <<endl ;
        // }
      int count  = 0 ;
      for(int i = s.size() -1 ; i >= 0 ; i--){
        
        if(s[i] != ' ') count++ ;
        else  if(s[i] == ' ') {
         
         if(count > 0) break ; 
        } 

      }
      
      return  count ;
    }
};