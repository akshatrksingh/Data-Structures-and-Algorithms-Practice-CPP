class Solution 
{
    public:
       vector<vector<int>> subsets(vector<int>& nums) 
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
