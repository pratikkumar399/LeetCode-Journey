# Solution 


## [ Problem : LeetCode 94 Binary Tree Inorder Traversal ](https://leetcode.com/problems/binary-tree-inorder-traversal/)

    Given the root of a binary tree, return the inorder traversal of its nodes' values.



>Recursive Solution

```cpp
//**
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
      inorder(root,ans) ;
      
      return ans ; 
    }
    
  void inorder(TreeNode* root , vector<int>& ans ){
     if(root== NULL)  return ;
      inorder(root->left ,ans)  ;
      ans.push_back(root->val) ;
      inorder(root->right , ans) ;
  }

    
};
```

>Iterative Solution

```cpp
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
       stack<TreeNode*> st ;
      TreeNode* node = root ;
      vector<int> inOrder ;
      while(true){
        if(node!= NULL){
          st.push(node) ;
          node = node->left ;
        }
        else{
          if(st.empty() == true) break ;
          node = st.top() ;
          st.pop() ;
          inOrder.push_back(node->val) ;
          node = node->right ;
        }
      }
      return inOrder ;
  }

    
};
```