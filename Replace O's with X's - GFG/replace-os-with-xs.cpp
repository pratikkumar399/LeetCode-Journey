//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    void dfs(int r , int c  , vector<vector<int>> &visited , int row[] , int col[] , 
    vector<vector<char>> &mat){
        visited[r][c] = 1 ;
        
        int n = mat.size() ;
        int m = mat[0].size() ;
        
        for(int i = 0 ; i < 4 ; i++){
            int nx = r + row[i] ;
            int ny = c + col[i] ;
            
            if(nx >= 0 && nx < n  && ny >= 0 && ny< m && mat[nx][ny] == 'O' && !visited[nx][ny]){
                dfs(nx , ny , visited , row , col , mat) ;
            }
        }
    } 
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
       int row[] = {-1,  0 , 1,  0} ;
       int col[] = { 0 , 1 , 0 , -1} ;
       vector<vector<int>> visited(n+1 ,  vector<int> (m , 0)) ;
       
       for(int i = 0 ; i < m  ; i++){
        //   int firstrow
           if(visited[0][i] == 0 && mat[0][i]=='O'){
               dfs(0 , i, visited , row , col , mat) ;
           }
           //int lastrow
           if(visited[n-1][i] == 0 && mat[n-1][i]=='O'){
               dfs(n-1 , i  , visited , row , col , mat) ;
           }
       }
       
       for(int i = 0 ; i < n  ; i++){
        //   int firscol
           if(visited[i][0] == 0 && mat[i][0]=='O'){
               dfs(i , 0, visited , row , col , mat) ;
           }
           //int lastcol
           if(visited[i][m-1] == 0 && mat[i][m-1]=='O'){
               dfs(i, m-1  , visited , row , col , mat) ;
           }
       }
       
       for(int i = 0 ; i< n ; i++){
           for(int j = 0 ; j < m ; j++){
               if(!visited[i][j] && mat[i][j] == 'O'){
                   mat[i][j] = 'X' ;
               }
           }
       }
       
       return mat ;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends