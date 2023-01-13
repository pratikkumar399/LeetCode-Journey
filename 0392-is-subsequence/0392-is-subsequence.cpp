class Solution {
public:
    bool isSubsequence(string s, string t) {
      bool ans = true ;
      
      int  i = 0 ,  j = 0 ; 
      
      while(i < s.size() &&  j < t.size() ){
        if(s[i] == t[j]){
          i++ ;
        }
        
        j++ ;
      }
      
      if(i >= s.size()) return true ;
      return false ; ;
    }
  
  // Time Complexity is O(N) where n is the size of the target string.
// Space Complexity is O(1)



};