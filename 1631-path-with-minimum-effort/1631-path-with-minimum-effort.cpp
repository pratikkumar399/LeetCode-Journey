class Solution {
public:
    
    bool isValid(int i , int j , int n , int m){
        if(i >= 0 and i< n and j>=0 and j <m) return true ;
        return false ;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        // since we are going to use dijksta for it 
        priority_queue<pair<pair<int,int> , int> , vector<pair<pair<int,int> , int>> , greater<pair<pair<int,int> , int>>> pq;
        
        // priority_queue<pair<int, pair<int, int>>,
        //                vector<pair<int, pair<int, int>>>,
        //                greater<pair<int, pair<int, int>>>>
        vector<vector<int>> dist(n , vector<int> (m , 1e9)) ;
        dist[0][0] = 0 ;
        pq.push({{0 , 0} , 0}) ;
        vector<int> dis = {-1, 0 , 1, 0 , -1} ;
        
        while(!pq.empty()){
            auto it = pq.top() ;
            int x =it.first.first ;
            int y = it.first.second ;
            auto diff = it.second ;
            pq.pop() ;
            
            if(x == n-1 and y == m-1) return diff ;
            
            for(int i = 0 ; i < 4 ; i++){
                int nx = x + dis[i] ;
                int ny = y + dis[i+1] ;
                
                if(isValid(nx , ny , n , m )){
                    int nEffort =  max(abs (heights[x][y] - heights[nx][ny]) , diff) ;
                    
                    if(nEffort < dist[nx][ny]){
                        dist[nx][ny] = nEffort ;
                        pq.push({{nx,ny} , nEffort}) ;
                    }
                }
            }
            
            
        }
        
        return 0 ;
        
        
    }
};

