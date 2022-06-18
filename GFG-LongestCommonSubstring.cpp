class Solution
{
    public:
    int longestCommonSubstr (string s1, string s2, int x, int y)
    {
        vector<vector<int>> dp(x+1, vector<int>(y+1,-1));
        for(int i = 0; i < x+1; i++)
        {
            for(int j = 0; j < y+1; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < x+1; i++)
        {
            for(int j = 1; j < y+1; j++)
            {
                if(s1[i-1] != s2[j-1])
                {
                    dp[i][j] = 0; 
                }
                else
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
        }
        int mx = INT_MIN;
        for(auto p: dp)
        {
            for(auto q: p)
            {
                mx = max(mx, q);
            }
        }
        return mx; 
    }
};
