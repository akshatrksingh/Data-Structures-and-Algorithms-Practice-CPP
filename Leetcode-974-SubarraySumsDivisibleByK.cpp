class Solution 
{
    public:
        int subarraysDivByK(vector<int> &nums, int k) 
        {
            unordered_map<int, int> m;
            int prefSum = 0, ans = 0, rem;
            m[0] = 1;
            for(int i = 0; i < nums.size(); i++)
            {
                prefSum += nums[i];
                rem = prefSum%k;
                if(rem < 0)
                    rem += k;
                if(m.find(rem) != m.end())
                    ans += m[rem];
                m[rem]++;     
            }
            return ans;
        }
};
