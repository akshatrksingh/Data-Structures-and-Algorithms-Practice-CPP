/*
Recursive Tree Diagram: https://lh5.googleusercontent.com/_HggDGd3RQxtGztkBl-RiWG1-30xybzsuKdwkFHD72hYudulc9gpcujvsMYRp0Rh6jTN7J_m-kM2hL7uV6vjMTICcy3MzHQQcu1kHHVlQCu9emq8YfRj5gsNfwDFBuVNqd4Md68u
*/

class Solution 
{
    public:
        void permuteRecursion(vector<int> &v, vector<bool> &vis, vector<int> &nums, vector<vector<int>> &ans)
        {
            if(v.size() == nums.size())
            {
                ans.push_back(v);
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
        vector<vector<int>> permute(vector<int> &nums) 
        {
            vector<int> v;
            vector<bool> vis(nums.size(), false);
            vector<vector<int>> ans;
            permuteRecursion(v, vis, nums, ans);
            return ans;
        }
};
