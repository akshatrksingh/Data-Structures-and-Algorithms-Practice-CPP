class Solution 
{
    public:
        int minCost(string col, vector<int> &time) 
        {
            int n = col.size();
            if(n == 1)
            {
                return 0;
            }
            int t = 0, prev = 0, curr = 1;
            while(curr < n)
            {
                if(col[prev] == col[curr])
                {
                    t += min(time[prev], time[curr]);
                    if(time[prev] < time[curr])
                    {
                        prev = curr;
                    }
                }
                else
                {
                    prev = curr;
                }
                curr++;
            }
            return t;
        }
};
