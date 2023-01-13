class Solution {
public:
    bool isSubsequence(string s, string t) {
      bool ans = true ;
      
      int  i = 0 ,  j = 0 ; 
      // using two pointers we can do this question easily 
      // if the character of the s string matches with the character in the t string 
      // if the character doesnot match then we can 
      while(i < s.size() &&  j < t.size() ){
        if(s[i] == t[j]){
          i++ ;
        }
        
        j++ ;
      }
      
     return (i == s.size()) ;
    }
  
  // Time Complexity is O(N) where n is the size of the target string.
// Space Complexity is O(1)



};