```cpp
// iterative height of a binary tree
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
```