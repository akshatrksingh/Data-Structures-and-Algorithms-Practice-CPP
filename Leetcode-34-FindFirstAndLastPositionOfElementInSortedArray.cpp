class Solution 
{
    public:
        vector<int> searchRange(vector<int> &nums, int target) 
        {
            int lb = 0 , mid, ub = nums.size()-1, res = -1;
            vector<int> v;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == target)
                {
                    res = mid;
                    ub = mid-1;
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
            v.push_back(res);
            lb = 0;
            ub = nums.size()-1;
            res = -1;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == target)
                {
                    res = mid;
                    lb = mid+1;
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
            v.push_back(res);
            return v;
        }
};g
