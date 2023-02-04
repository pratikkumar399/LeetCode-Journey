

class Solution
{
    public:
    
    void subsets(int index , vector<vector<int>> &ans , vector<int> &arr , vector<int> ds){
        if(index == arr.size()){
            ans.push_back(ds) ;
            return ;
        }
        subsets(index+1,ans,arr,ds);
        ds.push_back(arr[index]) ;
        subsets(index+1,ans,arr,ds) ;
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

