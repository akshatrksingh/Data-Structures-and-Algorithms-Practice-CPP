class Solution 
{
public:
    void dfsRecursion(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int nrow, int ncol, bool& isSubIsland) 
    {
        if (i >= 0 && i < nrow && j >= 0 && j < ncol && grid2[i][j] == 1) 
        {
            if (grid1[i][j] != 1)
                isSubIsland = false;

            grid2[i][j] = 2;
            dfsRecursion(grid1, grid2, i + 1, j, nrow, ncol, isSubIsland);
            dfsRecursion(grid1, grid2, i - 1, j, nrow, ncol, isSubIsland);
            dfsRecursion(grid1, grid2, i, j + 1, nrow, ncol, isSubIsland);
            dfsRecursion(grid1, grid2, i, j - 1, nrow, ncol, isSubIsland);
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int nrow = grid2.size();
        int ncol = grid2[0].size();
        int subIslandsCount = 0;

        for (int i = 0; i < nrow; i++) 
        {
            for (int j = 0; j < ncol; j++) 
            {
                if (grid2[i][j] == 1) 
                {
                    bool isSubIsland = true;
                    dfsRecursion(grid1, grid2, i, j, nrow, ncol, isSubIsland);
                    if (isSubIsland)
                        subIslandsCount++;
                }
            }
        }

        return subIslandsCount;
    }
};
