class Solution {
public:
    bool rotateString(string s, string goal) {
        
      if(s.size() != goal.size()) return false ;
      string str = s + s ;
      
      if(str.find(goal) != string::npos) return true ;
      return false ;
    }
};