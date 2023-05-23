class Solution 
{
    public:
        int findMin(vector<int>& nums) 
        {
            int n = nums.size();
            int lb = 0, ub = n - 1;

            if (nums[lb] < nums[ub] || n ==1) 
            {
                return nums[lb];
            }

            while (lb < ub) 
            {
                int mid = lb+(ub-lb)/2;
                if (nums[mid] < nums[ub]) 
                {
                    ub = mid;
                } 
                else if (nums[mid] > nums[ub])
                {
                    lb = mid+1;
                } 
                else    // duplicates
                {
                    ub--;
                }
            }
            return nums[lb];
        }
};
