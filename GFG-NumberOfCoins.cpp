class Solution 
{
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<vector<int>> dp(M+1, vector<int>(V+1));
	    for(int i = 0; i < M+1; i++)
        {
            for(int j = 0; j < V+1; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 0;          
                }
                else if(i == 0)
                {
                    dp[i][j] = INT_MAX-1;          // For i = 0 i.e. empty coins[] we logically need infinite coins for given sum 
                }
                else if(j == 0)
                {
                    dp[i][j] = 0;  
                }
            }
        }
        
	    for(int i = 1; i < M+1; i++)
	    {
	        for(int j = 1; j < V+1; j++)
	        {
	            if(coins[i-1] <= j)
	            {
	                dp[i][j] = min(1 + dp[i][j-coins[i-1]], dp[i-1][j]);
	            }
	            else
	            {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return (dp[M][V] == INT_MAX-1) ? -1 : dp[M][V];
	} 
};
