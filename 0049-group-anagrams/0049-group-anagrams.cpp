class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      
        if(strs.size() == 1) return {{strs[0]}} ;
        vector<vector<string>> ans ;
        unordered_map<string ,vector<string>> um ;
        for(int i = 0 ; i<strs.size() ;i++) {
           string str = strs[i] ;
           sort(strs[i].begin() , strs[i].end()) ;
           um[strs[i]].push_back(str) ;
        }
        
        for(auto i : um){
          ans.push_back(i.second) ;
        }
      
      return ans ;
    }
};

// sort the words and then we can keep the similar kind of words togerther 
// what we can do is that we can creat a map and then store all the words in that map 
// also the map can have a vector of strings
// the vector of strings can then have all the related words together 
// before sorting we need to keep up the original string as it is so that we can letter on use it to store it any place 

// this solution takes O(n log n ) time for sorting and the inserion in unordered map is a constant operation