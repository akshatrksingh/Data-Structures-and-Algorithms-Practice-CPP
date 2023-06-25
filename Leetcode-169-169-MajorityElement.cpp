class Solution 
{
    public:
        int majorityElement(vector<int>& nums) 
        {
            unordered_map<int, int> freq;
            int m = INT_MIN;
            for(int i: nums)
            {
                freq[i]++;
                m = max(m, freq[i]);
            }
            for(auto it = freq.begin(); it != freq.end(); it++)
            {
                if(it->second == m)
                {
                    return it->first;
                }
            }
            return 0;
        }
};
