class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        int lb = 0 , mid, ub = nums.size()-1;
        while(lb <= ub)
        {
            mid = (lb+ub)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[mid] < target)
            {
                lb = mid+1;
            }
            else
            {
                ub = mid-1;
            }
        }
        return -1;
    }
};
