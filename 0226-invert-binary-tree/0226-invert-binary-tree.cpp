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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return NULL ;
        queue<TreeNode*> q ;
        q.push(root) ;
        while(!q.empty()){
          auto current = q.front() ;
          q.pop();
          swap(current->left , current->right) ;
          if(current->left !=NULL) q.push(current->left) ;
          if(current->right != NULL ) q.push(current->right) ;
        }
      
        return root ;
    }
};