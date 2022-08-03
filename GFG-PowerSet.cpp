class Solution
{
	public:
		vector<string> AllPossibleStrings(string s)
		{
		    int n = s.size();
		    vector<string> v;
		    for(int num = 0; num < (1 << n); num++)
            {
                string sub;
                for(int bit = 0; bit < n; bit++)
                {
                    if(num & (1 << bit))
                    {
                        sub += s[bit];
                    }
                }
                if(sub != "")
                    v.push_back(sub);
            }  
            sort(v.begin(), v.end());
            return v;
		}
};
