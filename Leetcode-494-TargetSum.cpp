class Solution 
{
    public:
    int countOfSubsetsWithGivenSum(vector<int>arr, int sum)
        {
            int n = arr.size();
            vector<vector<int>> dp(n+1, vector<int>(sum+1));
            for(int i = 0; i < n+1; i++)
            {
                for(int j = 0; j < sum+1; j++)
                {
                    if(i == 0 && j == 0)
                    {
                        dp[i][j] = 1;          // {} is possible for sum = 0 if we are summing up only one no. i.e. 0
                    }
                    else if(i == 0)
                    {
                        dp[i][j] = 0;          // no subset is possible for sum = 0 if we are summing up positive nos.
                    }
                    else if(j == 0)
                    {
                        dp[i][j] = 1;          // {} is possible for sum = 0 if we are summing up nothing 
                    }
                }
            }
        
            for(int i = 1; i < n+1; i++)
            {
                for(int j = 0; j < sum+1; j++)   // initialisation for j is different for target sum as 0s are also allowed as valid element in the array
                {
                    if(arr[i-1] <= j)
                    {
                        dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];   
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n][sum]; 
        }
        int findTargetSumWays(vector<int>& nums, int target) 
        {
            
            int sum = 0 ;
            for(int i: nums) sum += i;
            if(target > sum || (sum+target)%2 != 0 || (sum+target) < 0) return 0;
            return countOfSubsetsWithGivenSum(nums, (target + sum)/2);
        }
    };
