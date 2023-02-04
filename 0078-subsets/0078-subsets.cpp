// class Solution {
// public:
//     vector<vector<int>> ans;
    
//     void sub(vector<int> &nums, int i, vector<int> temp)
//     {
//         if(i==nums.size())
//         {
//             ans.push_back(temp);
//             return;
//         }
        
//         sub(nums, i+1, temp);
//         temp.push_back(nums[i]);
//         sub(nums, i+1, temp);
//     }
    
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> temp;       
//         sub(nums, 0, temp); // or sub(nums, 0, vector<int> {});
//         return ans;
//     }
// };

class Solution
{
    public:
     vector<vector<int>> ans ;
    void subsets(int index , vector<int> &arr , vector<int> ds){
        if(index == arr.size()){
            ans.push_back(ds) ;
            return ;
        }
        subsets(index+1,arr,ds);
        ds.push_back(arr[index]) ;
        subsets(index+1,arr,ds) ;
        // ds.pop_back();
    }
    vector<vector<int> > subsets(vector<int>& A)
    {
        //code here
        vector<int> ds ;
        subsets(0, A , ds) ;
        return ans;
    }
};

