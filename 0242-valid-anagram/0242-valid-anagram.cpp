class Solution {
public:
    bool isAnagram(string str, string t) {
      if(str.size() !=  t.size() ) return false ;
      vector<int> frequency(26 , 0 ) ;
      
      
      // storing frequency of each element 
      for(auto it : str){
        frequency[it-'a'] = frequency[it- 'a'] + 1 ;
      }
      
      // decrementing the frequency of each element in another string 
      for(auto it : t){
        frequency[it-'a'] = frequency[it- 'a'] - 1 ;
      }
      
      // if the strings are the anagrams of each other than they will return 0 otherwise they are not anagrams of each other 
      for(int i = 0 ; i < 26 ; i++ ){
      if(frequency[i] != 0) return false ;
      }
      
      return true ;
    }
};