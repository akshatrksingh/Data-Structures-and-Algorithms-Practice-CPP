class Solution 
{
    public:
        string shortestCommonSupersequence(string s1, string s2) 
        {
            int x = s1.size(), y = s2.size();
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
            // Tabulation table for longest common subsequence
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
            // Getting the shortest common subsequence using the longest common subsequence
            int i = x, j = y;
            string res ="";
            while(i > 0 && j > 0)
            {
                if(s1[i-1] == s2[j-1])
                {
                    res.push_back(s1[i-1]);
                    i--;
                    j--;
                }
                else
                {
                    if(dp[i-1][j] > dp[i][j-1])
                    {
                        res.push_back(s1[i-1]);    // extra for Shortest Common Supersequence
                        i--;
                    } 
                    else
                    {
                        res.push_back(s2[j-1]);    // extra for Shortest Common Supersequence
                        j--;
                    }
                }
            }
            while(i > 0)    // if s1 characters are still left
            {
                res.push_back(s1[i-1]);
                i--;
            }
            while(j > 0)    // if s2 characters are still left
            {
                res.push_back(s2[j-1]);
                j--;

            }
            reverse(res.begin(),res.end());
            return res;
        }
};
