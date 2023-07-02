class Solution 
{
    public:
        int lengthOfLastWord(string s) 
        {
            s += ' ';
            int n = s.size(), idx = -1, cnt= 0;
            for(int i = 0; i < n-1; i++)
            {
                if(s[i] == ' ' && s[i+1] != ' ')
                {
                    idx = i;
                }
            }
            for(int i = idx+1; i < n && s[i] != ' '; i++)
            {
                cnt++;
            }
            return cnt;
        }
};
