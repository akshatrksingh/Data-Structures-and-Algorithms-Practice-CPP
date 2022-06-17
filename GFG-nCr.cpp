// If nPr instead of nCr then P(n, r) = r* P(n-1, r-1)+ P(n-1, r)  
class Solution
{
    public:
        int nCr(int n, int r)
        {
            vector<vector<int>> dp(n+1, vector<int>(r+1));
            int p = pow(10, 9)+7;
            for(int i = 0; i < n+1; i++)
            {
                for(int j = 0; j < r+1; j++)
                {
                    if(i == j || j == 0)
                    {
                        dp[i][j] = 1;    //C(n, n) = C(n, 0) =1
                    }
                }
            }
            /*
                r --->
            n   0 1 2   .. r
            | 0 1
            v 1 1 1 
              2 1   1
                ..    1 ..
              n 1  .....   1
            
            */
            for(int i = 2; i < n+1; i++)
            {
                for(int j = 1; j < r+1; j++)
                {
                    dp[i][j] = (dp[i-1][j-1]%p + dp[i-1][j]%p)%p;    // C(n, r) = C(n-1, r-1) + C(n-1, r) but large numbers involved hence C(n, r)%p = [ C(n-1, r-1)%p + C(n-1, r)%p ] % p
                }
            }
            return dp[n][r];
        }
};
