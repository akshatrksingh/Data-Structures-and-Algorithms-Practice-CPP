class Solution
{
    public:
        void permutationRecursion(string &v, vector<bool> &vis, string s, vector<string> &ans)
        {
            if(v.size() == s.size())
            {
                ans.push_back(v);
                return;
            }
            for(int i = 0; i < s.size(); i++) 
            {
                if(!vis[i]) 
                {
                  v.push_back(s[i]);
                  vis[i] = true;
                  permutationRecursion(v, vis, s, ans);
                  vis[i] = false;
                  v.pop_back();
                }
            }
        }
        vector<string> permutation(string s) 
        {
            string v;
            sort(s.begin(), s.end());
            vector<bool> vis(s.size(), false);
            vector<string> ans;
            permutationRecursion(v, vis, s, ans);
            //sort
            return ans;
        }
        // TC: O(N! * N)
};
