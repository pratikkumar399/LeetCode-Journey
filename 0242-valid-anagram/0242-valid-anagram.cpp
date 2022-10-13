class Solution {
public:
    bool isAnagram(string str, string t) {
      if(str.size() !=  t.size() ) return false ;
      vector<int> frequency(26 , 0 ) ;
      
      for(auto it : str){
        frequency[it-'a'] = frequency[it- 'a'] + 1 ;
      }
      
      for(auto it : t){
        frequency[it-'a'] = frequency[it- 'a'] - 1 ;
      }
      
      for(int i = 0 ; i < 26 ; i++ ){
      if(frequency[i] != 0) return false ;
      }
      
      return true ;
    }
};