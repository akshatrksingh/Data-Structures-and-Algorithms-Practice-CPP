class Solution
{
  public:
   int smallestSumSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int local_mn = 0;
        int global_mn = INT_MAX;
        for(int i = 0; i < n;i++)
        {   
    	    local_mn = min(nums[i], nums[i] + local_mn);
            global_mn = min(global_mn, local_mn);
    	}
        return global_mn;
    }
};
