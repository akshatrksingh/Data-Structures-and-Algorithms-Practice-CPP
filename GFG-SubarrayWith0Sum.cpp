class Solution
{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, bool> m;
        int prefSum = 0;
        for(int i = 0; i < n; i++)
        {
            prefSum += arr[i];
            if(m.find(prefSum) != m.end() || prefSum == 0)
                return true;
            else
                m[prefSum] = true;
        }
        return false;
    }
};
