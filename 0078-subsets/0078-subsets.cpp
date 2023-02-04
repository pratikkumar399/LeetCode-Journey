// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subs;
//         vector<int> sub;
//         subsets(nums, 0, sub, subs);
//         return subs;
//     }
// private:
//     void subsets(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& subs) {
//         subs.push_back(sub);
//         for (int j = i; j < nums.size(); j++) {
//             sub.push_back(nums[j]);
//             subsets(nums, j + 1, sub, subs);
//             sub.pop_back();
//         }
//     }
// };


class Solution
{
    public:
    
    void subsets(int index , vector<vector<int>> &ans , vector<int> &arr , vector<int> &ds){
        if(index == arr.size()){
            ans.push_back(ds) ;
            return ;
        }
        subsets(index+1,ans,arr,ds);
        ds.push_back(arr[index]) ;
        subsets(index+1,ans,arr,ds) ;
        ds.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<vector<int>> ans ;
        vector<int> ds ;
        subsets(0, ans , A , ds) ;
        return ans;
    }
};

