# Solution 


## [Problem : LeetCode 102( Binary Tree Level Order Traversal) ](https://leetcode.com/problems/binary-tree-level-order-traversal/)


    Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

```cpp
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
        vector<vector<int>> ans ;
      
        if(root ==  NULL) return ans ;
        
        queue <TreeNode*> q ;
        q.push(root) ;
        
      while(!q.empty()){
        vector<int> level ;
        int size = q.size() ;
        for(int i = 0 ; i < size ; i++){
          root =  q.front()  ;
          q.pop() ;
          if(root->left != NULL) q.push(root->left) ;
          if(root->right != NULL) q.push(root->right) ;
          level.push_back(root->val) ;
        }
        ans.push_back(level) ;
     
      }
      return ans  ;
    } 
};
```