class Solution
{
    public:
    	int search(string pat, string txt) 
    	{
    	    unordered_map <char, int> freq;
    	    for(char c: pat)
    	    {
    	        freq[c]++;
    	    }
    	    int count = freq.size();  
    	    int ans = 0;
    	    int k = pat.size(), n = txt.size();
    	    int i = 0, j = 0;
            while(j < n)
            {
                if(freq.find(txt[j]) != freq.end())
                {
                    freq[txt[j]]--;
                    if(freq[txt[j]] == 0)
                    {
                        count--;
                    }
                }
                
                if(j-i+1 < k)
                {
                    j++;
                }
                else if(j-i+1 == k)
                {
                    ans += (count == 0)? 1:0;
                    if(freq.find(txt[i]) != freq.end())
                    {
                        freq[txt[i]]++;
                        if(freq[txt[i]] == 1)
                        {
                            count++;
                        }
                    }
                    i++;
                    j++;
                }
            }
            return ans;
    	}
};
