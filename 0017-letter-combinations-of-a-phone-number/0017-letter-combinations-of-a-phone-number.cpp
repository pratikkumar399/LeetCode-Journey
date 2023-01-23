class Solution {
public:
  
  
void build(string builder, int i,string& digits, vector<string>& chars,vector<string>& combs){
        if(i == digits.size()) {
          combs.push_back(builder) ; 
          return ; 
        }
        int d =  digits[i] - '0' ; 
        for(char ch :  chars[d]) {
          build(builder + ch ,  i + 1 ,  digits ,  chars , combs ) ; 
        }
  }
    vector<string> letterCombinations(string digits) {
        if(!digits.size()) return {} ; 

	      vector<string> combinations ; 
	      vector<string> chars = { "0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	      string builder=  "";
	      build(builder , 0 , digits ,  chars,  combinations) ;
      
      return combinations ; 
       }
};