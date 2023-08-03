/*
// Recursion
class Solution 
{
    public:
        
        int robRecursion(int idx, vector<int>& nums)
        {
            if(idx >= nums.size())
            {
                return 0;
            }
            return max(robRecursion(idx+1, nums), robRecursion(idx+2, nums)+nums[idx]);
        }
    
        int rob(vector<int>& nums) 
        {
            return robRecursion(0, nums);
        }
};
*/

// DP
class Solution 
{
    public:
        
        int robRecursion(int idx, vector<int>& nums, vector<int> &dp)
        {
            if(idx >= nums.size())
            {
                return 0;
            }
            if(dp[idx] != -1)
            {
                return dp[idx];
            }
            return dp[idx] = max(robRecursion(idx+1, nums, dp), robRecursion(idx+2, nums, dp)+nums[idx]);
        }
    
        int rob(vector<int>& nums) 
        {
            vector<int> dp(nums.size(), -1);
            return robRecursion(0, nums, dp);
        }
};
