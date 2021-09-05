class Solution 
{
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) 
        {
            int n = days.back()+1;
            int cost[n];
            cost[0] = 0;
            unordered_set<int> d(days.begin(),days.end());
            for(int i = 1; i < n; i++)
            {
                if(d.find(i) == d.end())
                {
                    cost[i] = cost[i-1];
                }
                else
                {
                    if(i >= 1)
                    {
                        cost[i] = cost[i-1] + costs[0]; 
                    }
                    if(i >= 7)
                    {
                        cost[i] = min(cost[i], cost[i-7]+costs[1]);
                    }
                    else 
                    {
                        cost[i] = min(cost[i], costs[1]); 
                    }
                    if(i >= 30)
                    {
                         cost[i] = min(cost[i], cost[i-30]+costs[2]);
                    }                    
                    else 
                    {
                        cost[i] = min(cost[i], costs[2]); 
                    }
                }
            }
            return cost[n-1];        
        }
};
