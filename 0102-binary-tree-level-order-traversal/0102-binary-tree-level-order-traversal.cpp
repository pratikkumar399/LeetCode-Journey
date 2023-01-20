/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>  ans ;
      if(root == NULL) return ans ;
        queue<TreeNode*> q ;
      
        q.push(root) ;
       
        while(!q.empty()){
          int size = q.size() ;
          vector<int>  res ;
          
          for(int i = 0 ; i < size ; i++){
            auto top = q.front() ;
            q.pop() ;
            if(top->left != NULL) q.push(top->left) ;
            if(top->right != NULL) q.push(top->right) ;
            res.push_back(top->val) ;
          }
            ans.push_back(res); 
        }
        return ans ;
    }
};