class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        
      int count = 0 ;
      string str = "" ;
      while(str.size() < b.size()) {
        str += a;
        count++ ;
      }
      if(str.find(b) != string::npos) return count ;
      str += a ;
      count++ ;
      if(str.find(b) != string::npos) return count ;
      
      
      return -1 ;
    }

};