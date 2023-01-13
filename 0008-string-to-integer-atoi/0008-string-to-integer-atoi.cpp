class Solution {
public:
    int myAtoi(string str) {
        long sign = 1 ,  base = 0 , i = 0 ;
      
      if(str.length() == 0) return 0 ;
      while(str[i] == ' '){
        // ignoring the whitespaces 
        i++ ;
      }
      
      str = str.substr(i) ;
      
      if(str[0] =='-') sign = -1;
      int MAX = INT_MAX ;
      int MIN = INT_MIN ;
      
      i = (str[0] == '+' || str[0] == '-' ) ? 1 : 0 ;
      
       while(i < str.length()){
         if(str[0] == ' ' || !isdigit(str[i])) break ;
         base = base *10 + str[i] - '0' ;
         
         if(sign == -1 && -1 *base < MIN ) return MIN ;
         if(sign == 1 && base > MAX ) return MAX ;
         i++;
         
       }
    return base * sign;
      }
      
      
      
    
};