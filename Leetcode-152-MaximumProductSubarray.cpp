class Solution 
{
    public:
        int maxProduct(vector<int>& nums) 
        {
            int n = nums.size();
            int local_mx_pos = 1;
            int local_mn_neg = 1;
            int global_mx = INT_MIN;
            if(n == 1)
                return nums[0];
            for(int i = 0; i < n;i++)
        	{   
                if(nums[i] < 0)
                {
                    swap(local_mx_pos, local_mn_neg);
                }
                local_mn_neg = min(nums[i], nums[i]*local_mn_neg);
                local_mx_pos = max(nums[i], nums[i]*local_mx_pos);
                global_mx = max(global_mx, local_mx_pos);
        	}
            return global_mx;
        }
};
