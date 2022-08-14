class Solution
{
    public:                   
       int solve(int item, int wt_left, int wt[], int val[], vector<vector<int>> &dp) 
        {
            if(item < 0 || wt_left == 0)
                return 0;
            if(dp[item][wt_left] != -1)
                return dp[item][wt_left];
            if(wt[item] <= wt_left)    // CHOOSE THE ITEM AT INDEX
                return dp[item][wt_left] = max(val[item] + solve(item-1, wt_left-wt[item], wt, val, dp),
                           solve(item-1, wt_left, wt, val, dp));
            else                        // DO NOT CHOOSE THE ITEM AT INDEX
                return dp[item][wt_left] = solve(item-1, wt_left, wt, val, dp);
            
        }                       
        int knapSack(int w, int wt[], int val[], int n) 
        {
            vector<vector<int>> dp(n+1, vector<int>(w+1, -1));
            return solve(n-1, w, wt, val, dp);
        }
};
