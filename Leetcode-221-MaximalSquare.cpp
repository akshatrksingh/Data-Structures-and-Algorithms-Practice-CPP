class Solution 
{
    public:
        int maximalSquare(vector<vector<char>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            int dp[m+1][n+1];
            for(int row = 0; row < m+1; row++)
            {
                for(int col = 0; col < n+1; col++)
                {
                    if(row == 0 || col == 0)
                    {
                        dp[row][col] = 0;
                    }
                    else
                    {
                        dp[row][col] = grid[row-1][col-1]-'0';
                    }
                }
            }
            int mx  = 0;
            for(int row = 1; row < m+1; row++)
            {
                for(int col = 1; col < n+1; col++)
                {
                    if(dp[row][col] == 1)
                    {
                        dp[row][col] = 1 + min(dp[row-1][col-1], min(dp[row-1][col], dp[row][col-1]));
                        mx = max(mx, dp[row][col]);
                    }
                }
            }
            return mx*mx;
        }
};
