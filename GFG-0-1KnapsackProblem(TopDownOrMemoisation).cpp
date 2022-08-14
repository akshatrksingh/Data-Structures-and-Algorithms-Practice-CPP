class Solution
{
    public:
        int solve(int index, int wt_left, int wt[], int val[], vector<vector<int>> &dp) 
        {
            if(index < 0 || wt_left == 0)
                return 0;
            if(dp[index][wt_left] != -1)
                return dp[index][wt_left];
            if(wt[index] <= wt_left)    // CHOOSE THE ITEM AT INDEX
                return dp[index][wt_left] = max(val[index] + solve(index-1, wt_left-wt[index], wt, val, dp),
                           solve(index-1, wt_left, wt, val, dp));
            else                        // DO NOT CHOOSE THE ITEM AT INDEX
                return dp[index][wt_left] = solve(index-1, wt_left, wt, val, dp);
            
        }                       
        int knapSack(int W, int wt[], int val[], int n) 
        {
            vector<vector<int>>dp(n+1, vector<int>(W+1,-1));
            return solve(n-1, W, wt, val, dp);
        }
};
