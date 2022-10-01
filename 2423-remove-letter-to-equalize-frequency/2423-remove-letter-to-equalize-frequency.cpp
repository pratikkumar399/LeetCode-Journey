class Solution {
public:
  
   bool equalFrequency(string word) {
      for(int i=0;i<word.size();i++) //this is for selecting element we want to delete
        {
            map<char,int>mp;
            map<int,int>freq;
            for(int j=0;j<word.size();j++)
            {
                if(j!=i)  //means we have not taken ith element
                    mp[word[j]]++;
            }
            
            for(auto it:mp)
                freq[it.second]++;
            
            if(freq.size()==1)  
                return true;
            
           
         }
        
        return false;
    }
  
 
};

