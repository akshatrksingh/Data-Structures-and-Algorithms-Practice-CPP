class Solution 
{
    public:
        int searchInsert(vector<int>& nums, int target) 
        {
            int n = nums.size();
            int lb = 0, mid, ub = n-1;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == target)
                {
                    return mid;
                }
                else if(nums[mid] > target)
                {
                    ub = mid-1;
                }
                else
                {
                    lb = mid+1;
                }
            }
            return lb;
        }
};
