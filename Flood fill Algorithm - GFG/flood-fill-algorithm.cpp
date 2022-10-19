//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool isValid(int i , int j  , int n , int m){
        return (i < 0 || i >= n || j < 0 || j >=m) ;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size() ;
        int m = image[0].size() ;
        
        queue<pair<int, int>>  q ;
        
        vector<pair<int,int>>  directions = {{1,0}, {0, -1} , {0,1} , {-1,0}} ;
        int inColor = image[sr][sc] ;
        if(image[sr][sc] == newColor) return image ;
        q.push(make_pair(sr,sc)) ;
        image[sr][sc] = newColor ;
        
        while(!q.empty()){
            auto top = q.front() ;
            q.pop() ;
            
            for(auto it : directions){
                int nx = top.first + it.first ;
                int ny = top.second + it.second ;
                if(!isValid(nx , ny , n , m) && image[nx][ny] == inColor){
                   
                    q.push(make_pair(nx, ny)) ;
                     image[nx][ny] = newColor ;
                }
            }
            
        }
        
        return image ;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends