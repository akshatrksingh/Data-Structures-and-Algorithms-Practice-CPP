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
       vector<vector<int>> subsetsWithDup(vector<int> &nums) 
       {
           sort(nums.begin(), nums.end());
           vector<vector<int>> v = subsets(nums);
           set<vector<int>> s(v.begin(), v.end());
           v.assign(s.begin(), s.end());
           return v;
       }
};
