/*
class Solution 
{
    public:
       vector<vector<int>> subsets(vector<int> &nums) 
       {
            if (nums.empty()) 
            {
                return {{}};
            }
           
            int n = nums.back();
            nums.pop_back();
            vector<vector<int>> res = subsets(nums);
            int size = res.size();
            
            for (int i = 0; i < size; i++) 
            {
                res.push_back(res[i]);
                res.back().push_back(n);
            }
            return res;
        }
};
*/

class Solution 
{
    public:
        vector<vector<int>> subsets(vector<int>& nums) 
        {
            int n = nums.size();
            int totalSubsets = 1 << n;
            vector<vector<int>> result;

            for (int mask = 0; mask < totalSubsets; mask++) 
            {
                vector<int> subset;
                for (int i = 0; i < n; i++) 
                {
                    if ((mask >> i) & 1) 
                    {
                        subset.push_back(nums[i]);
                    }
                }
                result.push_back(subset);
            }

            return result;
        }
};
