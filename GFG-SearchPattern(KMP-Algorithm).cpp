lass Solution
{
    public:
        vector<int> compute_pi(string s) 
        {
            int n = s.length();
            vector<int> pi(n);
            pi[0] = 0;
            for (int i = 1; i < n; i++) 
            {
                int j = pi[i-1]; 
                while (j > 0 && s[j] != s[i]) 
                {
                    j = pi[j-1];
                }
                if (s[j] == s[i]) 
                {
                    pi[i] = j+1;
                }   
                else
                {
                    pi[i] = 0;
                }
            }
            return pi;
        }
        vector<int> search(string pat, string txt)
        {
            int n = pat.length(), m = txt.length();
            string s = pat+"#"+txt;
            vector<int> pi = compute_pi(s), ans;
            for (int i = n+1; i <= n+m; i++) 
            {
                if (pi[i] == n) 
                {
                    ans.push_back(i-2*n+1);   // i - (n - 1) - (n + 1) = i - 2*n for 0-based indexing but here 1-based indexing has been asked 
                }
            }
            return ans;
        }
     
};
