class Solution 
{
    public:
        int longestCommonSubseq(int x, int y, string s1, string s2)
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
        int longestPalindromeSubseq(string s) 
        {
            string rev = "";
            for(char c: s)
                rev = c + rev;
            return longestCommonSubseq(s.size(), rev.size(), s, rev);
        }
        int minInsertions(string s) 
        {
            return s.size()-longestPalindromeSubseq(s);
        }
};
