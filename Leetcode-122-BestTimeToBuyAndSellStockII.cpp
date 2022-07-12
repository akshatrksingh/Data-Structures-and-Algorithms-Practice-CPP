// We can build a similar solution as https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
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
        	    local_mx = max(local_mx, prices[i]-prices[i-1]+local_mx);
                global_mx = max(global_mx, local_mx);  // Infact we do not need global_mx here as local_mx is monotonically increasing in each iteration
        	}
            return global_mx;  // return local_mx;
        }
};
/*
class Solution 
{
    public:
        int maxProfit(vector<int> &prices) 
        {
            int n = prices.size();
            int profit = 0;
            for(int i = 1; i < n;i++)
        	{   
        	    profit += max(0, prices[i]-prices[i-1]);       // Buy high, Sell Low ; Buy yesterday for lesser price and sell today for more price
        	}
            return profit;  
        }
};
*/
