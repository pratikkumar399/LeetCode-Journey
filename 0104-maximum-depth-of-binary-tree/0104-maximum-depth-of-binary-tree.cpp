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
    int maxDepth(TreeNode* root) {
        if(root ==NULL)  return 0 ; 
      queue<TreeNode*>  q;
      q.push(root) ;
      int height =0;
      
      while(!q.empty()){
          height = height + 1 ;
          int size = q.size() ;
          for(int i = 0 ; i < size ; i++){
            TreeNode *temp =  q.front() ;
            q.pop() ;
            if(temp->left != NULL) q.push(temp->left) ;
            if(temp->right != NULL) q.push(temp->right) ;
          }
      }
        return height ; 
//       int leftHeight  =  maxDepth(root->left) ;
//       int rightHeight = maxDepth(root->right) ;
      
//       return 1 + max(leftHeight ,rightHeight) ;
    }
};