class Solution {
public:
    string removeOuterParentheses(string s) {
      string ans ;
      int count = 0 ;
        for(auto c : s ){
          if(c == '(' and count == 0){
            count++ ;
          }
          else if(c == '(' and count > 0){
            ans += c ;
            count++ ;
          }
          else if(c == ')' and count > 1){
            ans += c ;
            count-- ;
          }
          else if(c == ')' and count == 1){
            count-- ;
          }
        }
      return ans ;
    }
};