class Solution
{
    public:
        bool find3Numbers(int nums[], int n, int target)
        {
            sort(nums, nums+n);
            for(int i = 0; i < n; i++)
            {
                int left = i+1, right = n-1;
                if (i > 0 && nums[i] == nums[i - 1])
                        continue;
                while(left < right)
                {
                    if(nums[i] + nums[left] + nums[right] == target)
                    {
                        return true;
                    }
                    else if(nums[i] + nums[left] + nums[right] > target)
                    {
                        right--;
                    }
                    else
                    {
                        left++;
                    }
                }
            }
            return false;
        }
};
