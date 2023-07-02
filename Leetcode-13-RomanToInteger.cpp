class Solution 
{
    public:
        int romanToInt(string s) 
        {
            int num = 0;
            unordered_map <char, int> mp{{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};

            for(int i = 0; i < s.size(); i++)
            {
                cout<<s[i+1]<<",";
                if(mp[s[i]] < mp[s[i+1]])
                {
                    num -= mp[s[i]];
                }
                else
                {
                    num += mp[s[i]];
                }
            }
            return num;
        }
};
