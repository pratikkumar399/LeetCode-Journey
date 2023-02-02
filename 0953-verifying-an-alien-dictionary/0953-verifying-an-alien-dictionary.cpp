class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mp[26] ;
      
       for(int i = 0 ; i < order.size() ; i++){
         mp[order[i] - 'a'] = i ;
       }
      for(auto &it : words){
          for(auto &i : it ){
            i = mp[i - 'a'] ;
          }
       }
      return is_sorted(words.begin() , words.end()) ;
    }
};