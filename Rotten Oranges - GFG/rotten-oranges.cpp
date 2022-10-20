//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size() ;
        int m = grid[0].size() ;
        queue<pair<pair<int , int> , int>>  q ;
        vector<pair<int,int>> directions =  { {1,0} , {0,1} , {-1, 0} , {0,-1}} ;
        
        int count = 0 ;
        int countOranges = 0;
        
        for(int i = 0 ; i< n ;i++){
            for(int j = 0 ; j< m  ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0}) ;
                }
                
                if(grid[i][j] != 0){
                    count++ ;
                }
            }
        }
        int ans = 0 ;
        
        while(!q.empty()){
            auto top = q.front() ;
            q.pop();
            countOranges++ ;
            int timer = top.second ;
            ans = max(ans , timer ) ;
            for(auto it : directions){
                int nx = top.first.first + it.first ;
                int ny = top.first.second + it.second ;
                
                if((nx >= 0 && nx< n && ny>= 0 && ny < m ) && grid[nx][ny] == 1 ){
                    grid[nx][ny] = 2 ;
                    q.push({{nx , ny } , timer + 1 }) ;
                }
            }
            
        }
        
        if(count == countOranges) {
            return ans ;
        }
        
        return  -1 ;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends