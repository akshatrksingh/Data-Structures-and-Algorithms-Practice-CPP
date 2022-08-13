class Solution 
{
    public:
        void permuteRecursion(vector<int> &v, vector<bool> &vis, vector<int> &nums, set<vector<int>> &ans)
            {
                if(v.size() == nums.size())
                {
                    ans.insert(v);
                    return;
                }
                for(int i = 0; i < nums.size(); i++) 
                {
                    if(!vis[i]) 
                    {
                      v.push_back(nums[i]);
                      vis[i] = true;
                      permuteRecursion(v, vis, nums, ans);
                      vis[i] = false;
                      v.pop_back();
                    }
                }
            }
            vector<vector<int>> permuteUnique(vector<int> &nums) 
            {
                vector<int> v;
                vector<bool> vis(nums.size(), false);
                set<vector<int>> ans;
                permuteRecursion(v, vis, nums, ans);
                vector<vector<int>> ansUnique(ans.begin(), ans.end());
                return ansUnique;
            }
};
