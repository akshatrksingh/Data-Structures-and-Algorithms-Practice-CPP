class Solution 
{
    public:
        int maxTurbulenceSize(vector<int> &nums) 
        {
            int n = nums.size();
            if(n <= 1)
                return n;
            else if(n == 2)
                return (nums[0]==nums[1])? 1: 2;
            int local_mx = 1;                            // Important
            int global_mx = INT_MIN;
            for(int i = 2; i < n; i++)
        	{   
                if(nums[i-1] == nums[i])
                    local_mx = 0;                        // 0 local sign flips
                else if(nums[i-2] > nums[i-1] && nums[i-1] < nums[i] || nums[i-2] < nums[i-1] && nums[i-1] > nums[i])
                    local_mx++;
                else 
                    local_mx = 1;                        // 1 local sign flip     
                global_mx = max(global_mx, local_mx);    // # maximum sign flips
        	}
            return global_mx+1;                          // size of subarray = 1 + # # maximum sign flips
        }
};
