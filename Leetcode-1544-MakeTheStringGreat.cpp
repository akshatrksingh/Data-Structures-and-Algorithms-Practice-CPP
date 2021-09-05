class Solution 
{
    public:
    int c = 0;
    string makeGood(string s) 
    {
        string gs;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] - s[i+1] != 32 && s[i+1] - s[i] != 32)
            {
                gs.push_back(s[i]);
            }
            else
            {
                c++;
                i++;
            }
        }
        if(c != 0)
        {
            c = 0;
            return makeGood(gs);
        }
        return gs;
    }
};
