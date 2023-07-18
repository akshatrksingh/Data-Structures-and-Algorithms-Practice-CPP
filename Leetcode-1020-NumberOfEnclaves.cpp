class Solution 
{
    public:
        void dfsRecursion(vector<vector<int>>& grid, int i, int j, int nrow, int ncol) 
        {
            if (i >= 0 && i < nrow && j >= 0 && j < ncol && grid[i][j] == 1) 
            {
                grid[i][j] = 2; 
                dfsRecursion(grid, i + 1, j, nrow, ncol);
                dfsRecursion(grid, i - 1, j, nrow, ncol);
                dfsRecursion(grid, i, j + 1, nrow, ncol);
                dfsRecursion(grid, i, j - 1, nrow, ncol);
            }
        }

        int numEnclaves(vector<vector<int>>& grid) 
        {
            int nrow = grid.size();
            int ncol = grid[0].size();
            int numLandCells = 0;

            // Traverse the boundary and perform DFS on land cells connected to the boundary
            for (int i = 0; i < nrow; i++) 
            {
                for (int j = 0; j < ncol; j++) 
                {
                    if (i == 0 || i == nrow - 1 || j == 0 || j == ncol - 1) 
                    {
                        if (grid[i][j] == 1) 
                        {
                            dfsRecursion(grid, i, j, nrow, ncol);
                        }
                    }
                }
            }

            // Count the remaining land cells after DFS traversal
            for (int i = 0; i < nrow; i++) 
            {
                for (int j = 0; j < ncol; j++) 
                {
                    if (grid[i][j] == 1) 
                    {
                        numLandCells++;
                    }
                }
            }

            return numLandCells;
        }
};
