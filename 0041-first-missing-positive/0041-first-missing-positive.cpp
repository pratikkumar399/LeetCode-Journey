class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n = nums.size();
        
       vector<bool> occurence(n+1,0);
        
        for(auto it:nums){
            if(it > 0 and it<=n){
                occurence[it] = true;
            }
        }
        for(int i=1;i<=n;i++){
            if(!occurence[i])return i;
        }
        return n+1;
    }
};