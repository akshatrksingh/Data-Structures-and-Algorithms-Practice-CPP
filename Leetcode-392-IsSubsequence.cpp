class Solution 
{
    public:
        bool isSubsequence(string s, string t) 
        {
            int ns = s.size(), nt = t.size();
            int i = 0;
            int p1 = 0, p2 = 0;
            while(p1 < ns && p2 < nt)
            {
                if(s[p1] != t[p2])
                {
                    p2++;
                }
                else
                {
                    p1++;
                    p2++;
                }
            }
            return p1 == ns;
        }
};
