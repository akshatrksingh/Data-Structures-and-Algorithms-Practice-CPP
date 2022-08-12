class Solution 
{
    public:
        bool isCheck(string query, string pattern)
        {
            int i = 0;
            for(auto c: query)
            {
                if(c == pattern[i] && i < pattern.size()) 
                {
                    i++;
                }
                else if(c >='A' && c<='Z') 
                {
                    return false;
                }
            }
            if(i == pattern.size()) 
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        vector<bool> camelMatch(vector<string> &queries, string pattern) 
        {
            vector<bool> result;
            for(auto i: queries)
            {
                if(isCheck(i, pattern))
                {
                    result.push_back(true);
                }
                else
                {
                    result.push_back(false);
                }
            }
            return result;
        }
};
