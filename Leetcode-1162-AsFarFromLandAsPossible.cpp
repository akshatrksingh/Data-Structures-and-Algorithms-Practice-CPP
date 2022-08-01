class Solution 
{
    public:
        int maxDistance(vector<vector<int>> &grid) 
        {
            queue<pair<int, int>> q;
            int nrow = grid.size(), ncol = grid[0].size();
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i, j});
                    }
                }
            }
            
            if(q.size() == nrow*ncol || q.size() == 0)  // only land or only water
            {
                return -1;
            }
            
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            int x, y;
            int n, dist = 0;
            
            while(!q.empty())
            {
                n = q.size();
                for(int i = 0; i < n; i++)
                {
                    auto t = q.front();
                    q.pop();

                    for (int i = 0; i < 4; i++) 
                    {
                        x = t.first + dx[i];
                        y = t.second + dy[i];
                        if (x >= 0 && x < nrow && y >= 0 && y < ncol && grid[x][y] == 0) 
                        {
                            grid[x][y] = 2;
                            q.push({x, y});
                        }
                    }
                }
                if(!q.empty())
                {
                    dist++;
                }
            }
            return dist;
        }
};
