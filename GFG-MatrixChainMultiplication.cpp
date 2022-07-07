class Solution
{
    public:
        int solve(int arr[], int i, int j)
        {
            if(i >= j)
                return 0;
            int mn = INT_MAX;
            for(int k = i; k < j; k++)
            {
                int temp_ans = solve(arr, i, k) + solve(arr, k+1, j) + arr[i-1]*arr[k]*arr[j];
                mn = min(mn, temp_ans);
            }
            return mn;
        }
        int matrixMultiplication(int n, int arr[])
        {
            int dp[n+1][n+1];
            memset(dp, -1, sizeof(dp));
            solve(arr, 1, n-1);
        }
};
