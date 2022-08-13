class Solution
{
	public:
	        void permuteRecursion(string &v, vector<bool> &vis, string &s, set<string> &ans)
            {
                if(v.size() == s.size())
                {
                    ans.insert(v);
                    return;
                }
                for(int i = 0; i < s.size(); i++) 
                {
                    if(!vis[i]) 
                    {
                      v.push_back(s[i]);
                      vis[i] = true;
                      permuteRecursion(v, vis, s, ans);
                      vis[i] = false;
                      v.pop_back();
                    }
                }
            }
            vector<string> find_permutation(string s) 
            {
                string v;
                vector<bool> vis(s.size(), false);
                set<string> ans;
                permuteRecursion(v, vis, s, ans);
                vector<string> ansUnique(ans.begin(), ans.end());
                return ansUnique;
            }
};
