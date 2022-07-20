class Solution 
{
    public:
        int findPeakElement(vector<int> &nums)
        {
            int n = nums.size();
            if(n == 1)
                return 0;
            if(nums[0] > nums[1]) 
                return 0;
            if(nums[n-1] > nums[n-2]) 
                return n-1;
            int lb = 1 , mid, ub = n-2;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(mid > 0 && mid < n-1)
                {
                    if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])
                    {
                        return mid;
                    }
                    else if(nums[mid-1] < nums[mid])
                    {
                        lb = mid+1;
                    }
                    else
                    {
                        ub = mid-1;
                    }
                }
                
            }
            return -1;
        }
};
