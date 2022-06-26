class Solution 
{
    public:
        void specialDFSRecursion(vector<vector<char>>& grid, int i, int j, int nrow, int ncol)
        {
            if (i < 0 || j < 0 || i > (nrow - 1) || j > (ncol - 1) || grid[i][j] != '1')
            {
                return;
            }
            if (grid[i][j] == '1')
            {
                grid[i][j] = '2';  
                specialDFSRecursion(grid, i + 1, j, nrow, ncol);     
                specialDFSRecursion(grid, i - 1, j, nrow, ncol);     
                specialDFSRecursion(grid, i, j + 1, nrow, ncol);     
                specialDFSRecursion(grid, i, j - 1, nrow, ncol);     
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
                        grid[i][j] = '2';
                        cnt++;
                        specialDFSRecursion(grid, i + 1, j, nrow, ncol);     
                        specialDFSRecursion(grid, i - 1, j, nrow, ncol);     
                        specialDFSRecursion(grid, i, j + 1, nrow, ncol);     
                        specialDFSRecursion(grid, i, j - 1, nrow, ncol);    
                    }
                }
            }
            return cnt;
        }
};
