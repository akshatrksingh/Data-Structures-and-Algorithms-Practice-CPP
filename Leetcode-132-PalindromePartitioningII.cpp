// Optimized Top-down
class Solution 
{
    public:
            int dp[2001][2001];
            bool isPalindrome (string &s, int i, int j)
            {
                while(i<j)
                {
                    if(s[i] != s[j]) 
                        return false;
                    i++; j--;
                }
                return true;
            }
            int solve(string &s, int i, int j)
            {
                if(i >= j)
                    return 0;
                if(dp[i][j] != -1)
                    return dp[i][j];
                if(isPalindrome(s, i, j))
                    return 0;
                int mn = INT_MAX, left, right;
                for (int k = i; k < j; k++)
                {
                    if (isPalindrome(s, i, k))
                    {
                        int temp_ans = 1 + solve(s, k + 1, j);
                        mn = min(mn, temp_ans);
                    }
                }
                return dp[i][j] = mn;
            }
            int minCut(string s) 
            {
                memset(dp, -1, sizeof(dp));
                return solve(s, 0, s.size()-1);
            }
};
