class Solution
{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> m;
        int prefSum = 0;
        for(int i = 0; i < n; i++)
        {
            prefSum += arr[i];
            if(m.find(prefSum) != m.end() || prefSum == 0)
                return true;
            else
                m[prefSum]++;
        }
        return false;
    }
};
