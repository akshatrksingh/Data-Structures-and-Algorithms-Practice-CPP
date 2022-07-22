class Solution 
{
    public:
        bool isValid(vector<int> nums, int n, int m, int max_sum)
        {
            int subarray = 1;
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                if(nums[i] > max_sum)
                    return false;
                sum += nums[i];
                if(sum > max_sum)   // minimize max_pages
                {
                    subarray++;
                    sum = nums[i];
                }
                if(subarray > m)
                    return false;
            }
            return true;
        }
        int splitArray(vector<int> &nums, int m) 
        {
            int lb = 0;
            int ub = accumulate(nums.begin(), nums.end(), 0);
            int res = -1;
            while(lb <= ub)
            {
                int mid = lb + (ub-lb)/2;
                if(isValid(nums, nums.size(), m, mid))
                {
                    res = mid;
                    ub = mid-1;
                }
                else
                {
                    lb = mid+1;
                }
            }
            return res;
        }
};
