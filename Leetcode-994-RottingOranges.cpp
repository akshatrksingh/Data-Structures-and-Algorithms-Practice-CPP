class Solution 
{
    public:
        int orangesRotting(vector<vector<int>> &grid) 
        {
            queue<pair<int, int>> qrotten;
            int nrow = grid.size(), ncol = grid[0].size();
            int nfresh = 0, nminutes = 0, nrotten;
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                {
                    if(grid[i][j] == 2)
                    {
                        qrotten.push({i, j});
                    }
                    else if(grid[i][j] == 1)
                    {
                        nfresh++;
                    }
                }
            }
            
            
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            int x, y;
            
            while(!qrotten.empty())
            {
                nrotten =  qrotten.size();
                for(int i = 0; i < nrotten; i++)
                {
                    auto t = qrotten.front();
                    qrotten.pop();
                    for (int i = 0; i < 4; i++) 
                    {
                        x = t.first + dx[i];
                        y = t.second + dy[i];

                        // If reachable position is not yet visited and is inside grid, push that position into queue
                        if (x >= 0 && x < nrow && y >= 0 && y < ncol && grid[x][y] == 1) 
                        {
                            grid[x][y] = 2;
                            nfresh--;
                            qrotten.push({x, y});
                        }
                     }
                }
                if(!qrotten.empty())
                {
                    nminutes++;
                }
            }
            return (nfresh == 0) ? nminutes:-1; 
        }
};
