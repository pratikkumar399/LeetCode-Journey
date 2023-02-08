class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     if(s.size() == 0) return 0 ;
      unordered_map<char, int> mp ;
      int maxi = INT_MIN ; 
      int left = 0 ,  end = 0 ;
       while(end < s.size()){
         mp[s[end]]++ ;
         
         while(mp.size() < end -left  + 1){
           mp[s[left]]--;
           if(mp[s[left]] == 0) mp.erase(s[left]) ;
           left++ ;
         }
         
         maxi = max(maxi , end - left + 1 ) ;
         end++ ;
       }
      
      return maxi ;
    }
};