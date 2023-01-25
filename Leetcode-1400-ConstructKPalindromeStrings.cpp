class Solution 
{
    public:
        bool canConstruct(string s, int k) 
        {
            if(s.size() < k)
            {
                return false;
            }
            unordered_map<char, int> freq;
            for(char c: s)
            {
                freq[c]++;
            }
            int odd = 0;
            for(auto a: freq)
            {
                if(a.second % 2 != 0)
                {
                    odd++;
                }
            }
            return odd <= k;
        }
};
