int LCSof3(string s1, string s2, string s3, int x, int y, int z)
{
        int dp[x+1][y+1][z+1];        
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < x+1; i++)
        {
            for(int j = 0; j < y+1; j++)
            {
                for(int k = 0; k < z+1; k++)
                {
                    if(i == 0 || j == 0 || k == 0)
                    {
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
        for(int i = 1; i < x+1; i++)
        {
            for(int j = 1; j < y+1; j++)
            {
                for(int k = 1; k < z+1; k++)
                {
                    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
                    {
                        dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    }
                    else 
                    {
                        dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                    }
                }
            }
        }
        return dp[x][y][z]; 
}
