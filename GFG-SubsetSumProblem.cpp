// If the count of subsets with th given Sum sum has been asked then 2d int vector instead of 2d bool vector and + instead of || in the linec commented with **
class Solution
{   
    public:
        bool isSubsetSum(vector<int>arr, int sum)
        {
            int n = arr.size();
            vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
            for(int i = 0; i < n+1; i++)
            {
                for(int j = 0; j < sum+1; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        dp[i][j] = true;          // {} is possible for sum = 0 if we are summing up only one no. i.e. 0
                    }
                    else if(i == 0)
                    {
                        dp[i][j] = false;          // no subset is possible for sum = 0 if we are summing up positive nos.
                    }
                    else if(j == 0)
                    {
                        dp[i][j] = true;          // {} is possible for sum = 0 if we are summing up nothing 
                    }
                    else if(arr[i-1] <= j)
                    {
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];   // **
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][sum]; 
        }
};
