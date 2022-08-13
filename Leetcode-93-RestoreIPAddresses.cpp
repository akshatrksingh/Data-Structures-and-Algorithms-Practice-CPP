class Solution 
{
    public:
        void decomposeIpAddresses(string s, vector<string> &snippets, vector<string> &ipAddresses, int buildIndex)
        {
            if(buildIndex == s.size() && snippets.size() == 4)
            {
                ipAddresses.push_back(snippets[0] + '.'+ snippets[1] + '.' + snippets[2] + '.' + snippets[3]);
                return;
            }
            else if(buildIndex == s.size() || snippets.size() == 4)
            {
                return ;
            }
            for(int len = 1; len <= 3 && buildIndex + len <= s.size(); len++)
            {
                string snippet = s.substr(buildIndex, len);
                if((stoi(snippet) > 255) || (snippet.size() > 1 && snippet[0] == '0') )
                    break;
                snippets.push_back(snippet);
                decomposeIpAddresses(s, snippets, ipAddresses, buildIndex+len);
                snippets.pop_back();
            }
        }
        vector<string> restoreIpAddresses(string s) 
        {
            vector<string> ipAddresses;
            vector<string> snippets;
            decomposeIpAddresses(s, snippets, ipAddresses, 0);
            return ipAddresses;
        }
    };
