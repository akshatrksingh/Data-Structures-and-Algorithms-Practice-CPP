class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& str) 
        {
            string s1 = str[0], s2, tmp = "";
            for(int i = 1; i < str.size(); i++)
            {
                s2 = str[i];
                if(s1.size() > s2.size())
                {
                    tmp = s1;
                    s1 =s2;
                    s2 = tmp;
                }
                for(int j = 0; j < s2.size(); j++)
                {
                    if(s1[j] != s2[j])
                    {
                        s1 = s2.substr(0, j);
                        break;
                    }
                }
            }
            return s1;
        }
};
