# Solution 

## [994. Rotting Oranges](https://leetcode.com/problems/rotting-oranges/)

### Description

    You are given an m x n grid where each cell can have one of three values:

    0 representing an empty cell,
    1 representing a fresh orange, or
    2 representing a rotten orange.
    Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

### Thought Process 

```
Logic to apply : It is necessary to note that the fresh oranges can become rotten if they come in contact of already rotten oranges. Also the way in which they can come in contact with already rotten oranges is that they should be adjacent to them. A fresh orange is considered adjacent if its is in top, bottom, left or right of the already rotten oranges. So breadth first approach can help us in finding out the minimum time in which the freah oranges can become rotten . 
Also it is important to note that the oranges might not become fully rotten . In that case we have to simply return -1 . To check for this condition we can keep a count on each time a orange becomes rotten. If the count of all the rotten oranges is equal to (n*m) - number of empty cells , then we can say that the all the oranges cannot become rotten .

Important Concept for traversing in matrix problems ;

dx = {-1 , 0 , 1 , 0 } ;
dy = {0 , 1 , 0 , -1 } ;

for(int i = 0 ; i < 4 ; i++){
    newX = x + dx[i] ;
    newY =  y + dy[i] ; 
}
```

```cpp
class nodes
{
public:
    int _x, _y, _time;

    nodes(int x, int y, int time)
    {
        _x = x;
        _y = y;
        _time = time;
    }
};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<nodes> q;
        int countOranges = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push(nodes(i, j, 0));
                }
                if (grid[i][j] != 0)
                    countOranges++;
            }
        }

        int ans = 0;
        int count = 0;
        while (!q.empty())
        {
            int x = q.front()._x;
            int y = q.front()._y;
            int time = q.front()._time;
            q.pop();
            count++;
            ans = max(ans, time);

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1)
                {
                    grid[newX][newY] = 2;
                    q.push(nodes(newX, newY, time + 1));
                }
            }
        }
        if (count == countOranges)
            return ans;
        return -1;
    }
};
```

