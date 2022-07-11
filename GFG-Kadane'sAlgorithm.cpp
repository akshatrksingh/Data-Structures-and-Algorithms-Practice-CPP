class Solution
{
    public:
        long long maxSubarraySum(int nums[], int n)
        {
            int local_mx = 0;
            int global_mx = INT_MIN;
            for(int i = 0; i < n;i++)
        	{   
        	    local_mx = max(nums[i], nums[i] + local_mx);
                global_mx = max(global_mx, local_mx);
        	}
            return global_mx;
        }
};
