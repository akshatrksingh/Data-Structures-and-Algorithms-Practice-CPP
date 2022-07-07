#define mod 1003
class Solution
{
    public:
        int dp[201][201][2];
        int solve(string s, int i, int j, bool isTrue)
        {
            if(i > j) 
                return 0;
            if(dp[i][j][isTrue] != -1) 
                return dp[i][j][isTrue];
            if(i==j)
            {
                if(isTrue)
                    return s[i] == 'T';
                else
                    return s[i] == 'F';
            }
            int ans=0;
            for(int k = i+1; k < j; k += 2)
            {
                if(dp[i][k-1][1] == -1)                              // leftTrue
                    dp[i][k-1][1] = solve(s, i, k-1, true);
                if(dp[i][k-1][0] == -1)                              // leftFalse
                    dp[i][k-1][0] = solve(s, i, k-1, false);
                if(dp[k+1][j][1] == -1)
                    dp[k+1][j][1] = solve(s, k+1, j, true);          // rightTrue
                if(dp[k+1][j][0] == -1)
                    dp[k+1][j][0] = solve(s, k+1, j, false);         // rightFalse
                if(s[k] == '&')
                {
                    if(isTrue == true)
                        ans += (dp[k+1][j][1]*dp[i][k-1][1])%mod;
                    else
                        ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod + (dp[k+1][j][0]*dp[i][k-1][0])%mod)%mod;
                }
                else if(s[k] == '|')
                {
                    if(isTrue == true)
                        ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod + (dp[k+1][j][1]*dp[i][k-1][1])%mod)%mod;
                    else
                        ans += (dp[k+1][j][0]*dp[i][k-1][0])%mod;
                }
                else if(s[k] == '^')
                {
                    if(isTrue == true)
                        ans += ((dp[k+1][j][1]*dp[i][k-1][0])%mod + (dp[k+1][j][0]*dp[i][k-1][1])%mod)%mod;
                    else
                        ans += ((dp[k+1][j][1]*dp[i][k-1][1])%mod + (dp[k+1][j][0]*dp[i][k-1][0])%mod)%mod;
                }
            }
            return ans%mod;
        }
        int countWays(int n, string s)
        {
            memset(dp, -1, sizeof(dp));
            return solve(s, 0, n-1, true);
        }
};
