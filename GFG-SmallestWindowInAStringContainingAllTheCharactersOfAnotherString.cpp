class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
            unordered_map <char, int> freq;
    	    for(char c: p)
    	    {
    	        freq[c]++;
    	    }
    	    int count = freq.size();  
    	    string ans = s, tmp = "";
    	    int n = s.size();
    	    int i = 0, j = 0;
            while(j < n)
            {
                if(freq.find(s[j]) != freq.end())
                {
                    freq[s[j]]--;
                    if(freq[s[j]] == 0)
                    {
                        count--;
                    }
                }
                while(count == 0)
                {
                    tmp = s.substr(i, j-i+1);
                    if(tmp.size() < ans.size())
                    {
                        ans = tmp;
                    }
                    if(freq.find(s[i]) != freq.end())
                    {
                        freq[s[i]]++;
                        if(freq[s[i]] == 1)
                        {
                            count++;
                        }
                    }
                    i++;
                }
                j++;
            }
            return (tmp=="")?"-1":ans;
    }
};
