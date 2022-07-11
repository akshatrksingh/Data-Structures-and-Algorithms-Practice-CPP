class Solution 
{
    public:
        int maxSubArray(vector<int>& nums) 
        {
            int n = nums.size();
            int mx = nums[0];
            for(int i = 1; i < n; i++)
            {
                nums[i] = max(nums[i-1]+nums[i], nums[i]);
                mx = max(mx, nums[i]);
            }
            return mx;
        }
};
