class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> phash(26 , 0) ;
        vector<int> hash(26 , 0) ;
        vector<int> ans ;   
      
       int p_size = p.size() ;
       int s_size = s.size() ;
       
      if(s_size < p_size) return ans ;
      
      int left = 0 , right = 0 ;
      
       while(right < p_size){
         phash[p[right] - 'a']++ ;
         hash[s[right] - 'a']++ ;
         right++ ;
       }
      
      right-- ;
      while(right < s_size){
        if(phash == hash){
          ans.push_back(left) ;
        }
        right++ ;
        if(right != s_size){
          hash[s[right] - 'a'] += 1 ;
        }
        
        hash[s[left] - 'a'] -= 1 ;
        
        left++ ;
      }
      return ans ;
    }
};





