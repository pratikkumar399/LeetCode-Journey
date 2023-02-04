class Solution {
public:
   bool matches(vector<int> p , vector<int> s){
     for(int i = 0 ; i < 26 ; i++){
       if(p[i] != s[i]) return false ;
     }
     
     return true ;
   }
  
    bool checkInclusion(string p, string s) {
        vector<int> phash(26 , 0) ;
        vector<int> hash(26 , 0) ;
        vector<int> ans ;   
      
       int p_size = p.size() ;
       int s_size = s.size() ;
       
      if(s_size < p_size) return false ;
      
      for(int i = 0 ; i < p_size ; i++){
        phash[p[i] - 'a']++ ;
         hash[s[i] - 'a']++ ;
      }
      
      for(int i = 0 ; i < s_size - p_size ; i++){
         if(matches(phash , hash)){
           return true ;
         }
          hash[s[i +  p_size] - 'a'] += 1 ;
          hash[s[i] - 'a'] -= 1 ;
      }
      
     
      return matches(phash  ,hash) ;
    }
};