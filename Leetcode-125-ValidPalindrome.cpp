class Solution 
{
    public:
        
        string modify(string &s)
        {
            int n = s.size();
            string x = "";
            for(int i = 0; i < n; i++)
            {
                if(s[i] >= 'a' && s[i] <= 'z')
                {
                    x += s[i];
                }
                else if(s[i] >= 'A' && s[i] <= 'Z')
                {
                    x += s[i] + 32;
                }
                else if(s[i] >= '0' && s[i] <= '9')
                {
                    x += s[i];
                }
            }
            return x;
        }
        
        bool isPalindrome(string s) 
        {
            s = modify(s);
            int n = s.size();
            int p1 = 0, p2 = n-1;
            while(p1 < p2)
            {
                if(s[p1++] != s[p2--])
                {
                    return false;
                }
            }
            return true;
        }
};
