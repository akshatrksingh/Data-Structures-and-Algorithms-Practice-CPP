/*
If instead of the length of the LCS, the LCS itself has to be returned, use backtracking after finding the dp[][] for length
int i = m, j = n;
string s = "";
while(i > 0 && j > 0)
{
    if(a[i-1] == b[i-1])
    {
        s.push_back(a[i-1]);
        i--;
        j--;
    }
    else
    {
        if(t[i][j-1] > t[i-1][j]) 
            j--;
        else
           i--;
    }
}
*/
class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
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
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
            }
        }
        return dp[x][y]; 
    }
};
