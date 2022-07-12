class Solution 
{
    public:
        int maxSubarraySumCircular(vector<int> &nums) 
        {
            int n = nums.size();
            int local_mx = 0, local_mn = 0;
            int global_mx = INT_MIN, global_mn = INT_MAX;
            int total = 0;
            for(int i = 0; i < n;i++)
        	{   
        	    local_mx = max(nums[i], nums[i] + local_mx);
                local_mn = min(nums[i], nums[i] + local_mn);
                global_mx = max(global_mx, local_mx);
                global_mn = min(global_mn, local_mn);
                total += nums[i];
        	}
            return (global_mx > 0) ? max(global_mx, total-global_mn) : global_mx;
            /*
            If all numbers are negative, maxSum = max(A) and minSum = sum(A).
            In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
            According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
            So we return the maxSum to handle this corner case.

            */
        }
};
