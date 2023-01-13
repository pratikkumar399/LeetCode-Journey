class Solution {
public:
    bool isAnagram(string str, string t) {
      
      if(str.size() != t.size()) return false ;
      map<char , int>mp  ;
      
      // mp[str]++ ;
      int n = str.size() ;
      
      for(int i = 0 ; i < n ; i++)
      {
        mp[str[i]]++ ;
        mp[t[i]]-- ;
      }
      
        
      for(auto it : mp){
        if(it.second > 0) return false ;
      }
        return true  ;
    }
};

// i think the alternating solution for this question is that we can sort the original string and then compare both the strings if they are equal then we can say that they are anagrams of each other 
// but since this solution will be in O (n log n ) time therefore we need to think of a better soluton 



// if we want to do that in O(n)  time complexity then what we can do is that we can store the frequency of each element in the first string and then reduce the fequency if the same letter is found in another string . If they return xer0 then  we can say that the  strings are anagrams of each other . 