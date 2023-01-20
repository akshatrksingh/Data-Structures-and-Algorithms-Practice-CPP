class Solution 
{
    public:
        string minWindow(string s, string t) 
        {
            unordered_map <char, int> freq;
            for(char c: t)
            {
                freq[c]++;
            }
            int ans = INT_MAX, beg = 0;
            int n = s.size();
            int cnt = freq.size();
            int i = 0, j = 0;
            while(j < n)
            {
                if(freq.find(s[j]) != freq.end())
                {
                    freq[s[j]]--;
                    if(freq[s[j]] == 0)
                    {
                        cnt--;
                    }
                }
                while(cnt == 0)
                {
                    if(ans > j-i+1)
                    {
                        ans = j-i+1;
                        beg = i;
                    }
                    if(freq.find(s[i]) != freq.end())
                    {
                        freq[s[i]]++;
                        if(freq[s[i]] == 1)
                        {
                            cnt++;
                        }
                    }
                    i++;
                }
                j++;
            }
            return (ans == INT_MAX)?"":s.substr(beg, ans);
        }
};
