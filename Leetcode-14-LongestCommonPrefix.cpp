class Solution 
{
    public:
        
        string intersection(string &s1, string &s2)
        {
            int i = 0, n1 = s1.size(), n2 = s2.size(), n = min(n1, n2);
            string in = "";
            while(i < n && s1[i] == s2[i])
            {
                in += s1[i];
                i++;
            }
            return in;
        }
        
        string longestCommonPrefix(vector<string>& str) 
        {
            int n = str.size();
            if(n == 0)
            {
                return "";
            }
            string pre = str[0], tmp;
            for(int i = 1; i < n; i++)
            {
                pre = intersection(pre, str[i]);
            }
            return pre;
        }
};
