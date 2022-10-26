```
class Solution {
public:
bool checkBipartite(int n , vector<int> &visited , vector<vector<int>> &graph){
visited[n] = 1 ;
queue<int>  q ;
q.push(n);
while(!q.empty()){
int top = q.front() ;
q.pop() ;
for(auto it : graph[top]){
if(visited[it] == -1) {
visited[it] = 1-  visited[top] ;
q.push(it);
}else if(visited[it] == visited[top])
{
return false ;
}
}
}
return true ;
}
bool isBipartite(vector<vector<int>>& graph) {
int n = graph.size() ;
vector<int> visited(n,-1) ;
for(int i= 0 ; i< n ;i++){
if(visited[i] == -1){
if(!checkBipartite(i,visited,graph)) return false ;
}
}
return true ;
}
};
```
​