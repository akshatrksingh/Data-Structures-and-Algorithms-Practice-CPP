class Solution 
{
    public:
        int maxAbsoluteSum(vector<int> &nums) 
        {
            int n = nums.size();
            int local_mx = 0, local_mn = 0;
            int global_mx = INT_MIN, global_mn = INT_MAX;
            for(int i = 0; i < n;i++)
            {   
                  local_mx = max(nums[i], nums[i] + local_mx);
                  local_mn = min(nums[i], nums[i] + local_mn);
                  global_mx = max(global_mx, local_mx);
                  global_mn = min(global_mn, local_mn);
            }
            return abs(global_mn)>global_mx ? abs(global_mn): global_mx;
        }
};
