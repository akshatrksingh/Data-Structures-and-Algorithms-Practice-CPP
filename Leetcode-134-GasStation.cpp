class Solution 
{
    public:
        int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
        {
            int tot_gas = 0, tot_cost = 0;
            for(int g: gas)
            {
                tot_gas += g;
            }
            for(int c: cost)
            {
                tot_cost += c;
            }
            if(tot_gas < tot_cost)
            {
                return -1;
            }
            int beg = 0, tank = 0, n = gas.size();
            for(int i = 0; i < n; i++)
            {
                tank += gas[i]-cost[i];
                if(tank < 0)
                {
                    beg = i+1;
                    tank = 0;
                }
            }
            return beg;
        }
};
