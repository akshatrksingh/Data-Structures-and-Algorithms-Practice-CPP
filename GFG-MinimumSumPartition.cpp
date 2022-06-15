class Solution
{

  public:
        vector<bool> isSubsetSum(int arr[], int sum, int n)
        {
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
                        dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];   
                    }
                    else
                    {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
            return dp[n];    //In subset sum problem we return dp[n][sum] but here we return dp[n] i.e. the entire last row
        }  
    	int minDifference(int arr[], int n)  
    	{ 
    	    int sum = 0;
    	    for(int i = 0; i < n; i++) 
    	    {
    	        sum += arr[i];
    	    }
    	    int mn = INT_MAX;
    	    vector<bool> b = isSubsetSum(arr, sum, n);   // last row of dp[][]
    	    vector<int> v;
    	    for(int i = 0; i <= b.size()/2; i++)
    	    {
    	        if(b[i]) v.push_back(i);                 // v has elements of last row of dp[][] that are true until the middle column i.e. basically candidates for S1 (WLOG S1 <= S2)
      	    } 
    	    for(int i = 0; i < v.size(); i++) 
    	    {
    	        mn = min(mn, abs(sum-2*v[i]));           // Consider S1 & S2 to be the sets, S1 = sum - S2, so to min(abs(S2 - S1)) we min(abs(sum - 2S1))
    	    }
    	    return mn;
    	} 
};
