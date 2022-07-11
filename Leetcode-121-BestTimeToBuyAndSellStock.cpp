class Solution 
{
    public:
        int maxProfit(vector<int> &prices) 
        {
            int n = prices.size();
            int local_mx = 0;
            int global_mx = 0;
            for(int i = 1; i < n;i++)
        	{   
        	    local_mx = max(0, prices[i]-prices[i-1]+local_mx);
                global_mx = max(global_mx, local_mx);
        	}
            return global_mx;
        }
};
