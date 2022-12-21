class Solution {
public:
    int myAtoi(string str) {
      int res = 0; 
        stringstream ss ;
      ss<<str ;
      ss>>res;
      
      return res ;
    }
};