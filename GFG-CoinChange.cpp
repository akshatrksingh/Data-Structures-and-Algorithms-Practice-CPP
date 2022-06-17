/*
Unbounded Knapsack problem
int val[] -> (removed since not needed)
int wt[] -> int coins[]
n -> m  // size of item array
W -> n  // target
*/
class Solution 
{
  public:
    long long int count(int coins[], int m, int n) 
    {
        long long int cnt = 0;
        vector<vector<long long int>> dp(m+1, vector<long long int>(n+1));
        for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j < n+1; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;          // {} is possible for total n = 0 cents if we are summing up only one no. i.e. 0
                }
                else if(i == 0)
                {
                    dp[i][j] = 0;          // no subset is possible for total n = 0 cents if we are summing up positive nos.
                }
                else if(j == 0)
                {
                    dp[i][j] = 1;          // {} is possible for total n = 0 cents if we are summing up nothing 
                }
            }
        }
        for(int i = 1; i < m+1; i++)
        {
            for(int j = 1; j < n+1; j++)
            {
                if(coins[i-1] <= j)
                {
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[m][n]; 
    }
};
