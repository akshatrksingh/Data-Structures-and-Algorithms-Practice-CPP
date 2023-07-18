/*
// BFS
class Solution 
{
    public:
        int numIslands(vector<vector<char>>& grid) 
        {
            int nrow = grid.size();
            int ncol = grid[0].size();
            int cnt = 0;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (int i = 0; i < nrow; i++) 
            {
                for (int j = 0; j < ncol; j++) 
                {
                    if (grid[i][j] == '1') 
                    {
                        cnt++;
                        grid[i][j] = '2';

                        queue<pair<int, int>> q;
                        q.push({i, j});

                        while (!q.empty()) 
                        {
                            int currRow = q.front().first;
                            int currCol = q.front().second;
                            q.pop();

                            for (auto dir : directions) 
                            {
                                int newRow = currRow + dir.first;
                                int newCol = currCol + dir.second;

                                if (newRow >= 0 && newRow < nrow && newCol >= 0 && newCol < ncol && grid[newRow][newCol] == '1') 
                                {
                                    q.push({newRow, newCol});
                                    grid[newRow][newCol] = '2';
                                }
                            }
                        }
                    }
                }
            }
            return cnt;
        }
};
*/

// DFS
class Solution 
{
    public:
        void dfsRecursion(vector<vector<char>>& grid, int i, int j, int nrow, int ncol)
        {
            if (i >= 0 && i < nrow && j >= 0 && j < ncol && grid[i][j] == '1') 
            {
                grid[i][j] = '2';  
                dfsRecursion(grid, i + 1, j, nrow, ncol);     
                dfsRecursion(grid, i - 1, j, nrow, ncol);     
                dfsRecursion(grid, i, j + 1, nrow, ncol);     
                dfsRecursion(grid, i, j - 1, nrow, ncol);     
            }
        }
        int numIslands(vector<vector<char>>& grid) 
        {
            int nrow = grid.size();
            int ncol = grid[0].size();
            int cnt = 0;
            for (int i = 0; i < nrow; i++)
            {
                for (int j = 0; j < ncol; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        dfsRecursion(grid, i, j, nrow, ncol);    
                        cnt++;
                    }
                }
            }
            return cnt;
        }
};
