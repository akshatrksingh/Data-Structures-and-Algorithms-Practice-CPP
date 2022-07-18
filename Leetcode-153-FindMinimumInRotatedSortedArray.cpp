class Solution 
{
    public:
        int findMin(vector<int> &nums) 
        {
            int n = nums.size();
            int lb = 0 , mid, ub = n-1;
            int next, prev;
            if(nums[lb] < nums[ub] || n == 1)
            {
                return nums[0];
            }
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                prev = (mid-1+n)%n;
                next = (mid+1)%n;
                if(nums[mid] < nums[prev])
                {
                    return nums[mid];
                }
                else if(nums[mid] > nums[next])
                {
                    return nums[next];
                }
                else if(nums[lb] < nums[mid])    // remove the sorted half as min lies in the unsorted half
                {
                    lb = mid+1;
                }
                else if(nums[mid] < nums[ub])
                {
                    ub = mid-1;
                }
            }
            return 0;
        }
};
