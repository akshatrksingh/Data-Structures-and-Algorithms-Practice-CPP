class Solution 
{
    public:
    
        void dfsRecursion(vector<vector<int>>& grid, int i, int j, int nrow, int ncol, int &temp)
        {
            if (i >= 0 && i < nrow && j >= 0 && j < ncol && grid[i][j] == 1) 
            {
                temp++;
                grid[i][j] = 2;  
                dfsRecursion(grid, i + 1, j, nrow, ncol, temp);     
                dfsRecursion(grid, i - 1, j, nrow, ncol, temp);     
                dfsRecursion(grid, i, j + 1, nrow, ncol, temp);     
                dfsRecursion(grid, i, j - 1, nrow, ncol, temp);     
            }
        }
        
        int maxAreaOfIsland(vector<vector<int>>& grid) 
        {
            int nrow = grid.size();
            int ncol = grid[0].size();
            int area = 0;
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        int temp = 0;
                        dfsRecursion(grid, i, j, nrow, ncol, temp);
                        area = max(area, temp);
                    }
                }
            }
            return area;
        }
};
