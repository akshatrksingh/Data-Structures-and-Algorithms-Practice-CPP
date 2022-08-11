class Solution 
{
    public:
        int subarraySum(vector<int> &nums, int k) 
        {
            unordered_map<int, int> m;
            int prefSum = 0, ans = 0, x;
            for(int i = 0; i < nums.size(); i++)
            {
                m[prefSum]++;     // m[0] = 1 (why?)
                prefSum += nums[i];
                x = prefSum-k;
                if(m.find(x) != m.end())
                    ans += m[x];
            }
            return ans;
        }
};
