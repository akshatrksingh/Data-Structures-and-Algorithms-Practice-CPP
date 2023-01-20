class Solution 
{
    public:
        bool canJump(vector<int>& nums) 
        {
            int n = nums.size(), reach = 0, i;
            for(i = 0; i < n && i <= reach; i++)
            {
                reach = max(reach, nums[i]+i);
            }
            return i == n;
        }
};
