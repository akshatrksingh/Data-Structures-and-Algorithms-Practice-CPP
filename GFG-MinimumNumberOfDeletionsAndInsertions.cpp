class Solution
{
	public:
	int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];        
        memset(dp, -1, sizeof(dp));
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
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else if(s1[i-1] != s2[j-1])
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[x][y]; 
    }
	int minOperations(string s1, string s2) 
	{
	    int len = lcs(s1.size(), s2.size(), s1, s2);
	    int del = s1.size()-len;
	    int ins = s2.size()-len;
	    return del+ins;
	} 
};
