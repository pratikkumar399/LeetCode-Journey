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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        if(root == NULL)  return ans ;
        
        queue<TreeNode*> q  ;
        q.push(root) ;
      // initially setting the left and right values for the tree
        bool leftRight = true ;
        while(!q.empty()) {
           int size = q.size() ;
          // finding the size of the queue 
          // in each iteration we will look at each of the adjacent elements of the current node 
          // this is because  we are doing a bfs traversal of the tree
          // and therefore we need to traverse the adjacent nodes of the current node in order to conisder all the opetions available
          
          // taking a vector which stores all the nodes at that level
           vector<int> row(size) ;             
            for(int i = 0 ; i < size ; i++){
               TreeNode* node = q.front() ;
               q.pop() ; 
               // 
               int index = (leftRight) ? i : size - 1 - i ; 
               row[index] = node->val ;
               if(node->left) q.push(node->left) ;
               if(node->right) q.push(node->right) ;
            }
          leftRight = !leftRight ; 
          ans.push_back(row) ;
        }
      return ans ;
    }
};