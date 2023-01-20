class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& str) 
        {
            if(str.size() == 0)
            {
                return "";
            }
            string pre = str[0], s;
            for(int i = 1; i < str.size(); i++)
            {
                string s = str[i], tmp;
                if(pre.size() > s.size())
                {
                    tmp = s;
                    s = pre;
                    pre = tmp;
                }
                for(int j = 0; j < s.size(); j++)
                {
                    if(pre[j] != s[j])
                    {
                        pre = s.substr(0, j);
                        break;
                    }
                }
            }
            return pre;
        }
};
