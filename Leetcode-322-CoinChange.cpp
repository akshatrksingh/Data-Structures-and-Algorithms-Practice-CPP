Implement Stack using Queuesclass Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = amount+1;
        vector<int> arr(n, n);
        arr[0] = 0;
        for(int i = 1; i < n; i++)
        {
            for(auto c: coins)
            {
                if(i-c >= 0)
                {
                    arr[i] = min(arr[i-c]+1, arr[i]);
                }
            }
        }
        if(arr[n-1] == n)
        {
            return -1;
        }
        else
        {
            return arr[n-1];
        }
    }
};
