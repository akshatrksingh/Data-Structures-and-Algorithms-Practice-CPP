class Solution 
{
    public:
        int minimumTotal(vector<vector<int>> &triangle) 
        {
            int height = triangle.size();
            int base = triangle[height-1].size();
            int dp[height][base];
            for(int i = 0; i < height; i++)
            {
                for(int j = 0; j < base; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        dp[i][j] = triangle[i][j];
                    }
                    else if(j == 0)
                    {
                        dp[i][j] = triangle[i][j]+dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j] = INT_MAX;
                    }
                }
            }
            for(int i = 1; i < height; i++)
            {
                for(int j = 1; j <= i; j++)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1])+triangle[i][j];
                }
            }
            int mn = INT_MAX;
            for(int i = 0; i < base; i++)
            {
                mn = min(mn, dp[height-1][i]);
            }
            return mn;
        }
};
