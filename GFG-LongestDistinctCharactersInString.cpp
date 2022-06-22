int longestSubstrDistinctChars(string s)
{
        int n = s.size();
        int i = 0, j = 0;
        int m = 1 ;
        int k;
        unordered_map<char, int> map;
        while(j < n)
        {
            map[s[j]]++;
            k = j-i+1;
            if(map.size() < k)
            {
                while(map.size() < k)
                {
                    map[s[i]]--;
                    if(map[s[i]] == 0)
                    {
                        map.erase(s[i]);
                    }
                    i++;
                    k = j-i+1;
                }
                if(map.size() == k)
                {
                    m = max(m, j-i+1);
                }
                j++;
            }
            else if(map.size() == k)
            {
                m = max(m, j-i+1);
                j++;
            }
        }
        return m;
}
