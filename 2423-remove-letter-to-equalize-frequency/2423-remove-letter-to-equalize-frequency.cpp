class Solution {
public:
  
  set<int> st ;
   bool equalFrequency(string word) {
     unordered_map<char,int> mp ;
      for(int i = 0 ; i< word.size() ; i++){
        mp[word[i]]++ ;
      }
      for(int i=0; i<word.size(); i++){
        mp[word[i]]-- ;
        int freq = (i<word.size()-1) ? mp[word[i+1]]: mp[word[i-1]];
        if(valid(mp , freq)) return true ;
        mp[word[i]]++ ;
      }
      return false ;
    }
  
  bool valid(unordered_map<char,int> mp , int freq){
          for(auto it : mp){
            if(it.second>= 1 && it.second!= freq){
              return false;
            }
          }
    
          
           return true ;
        }
};

