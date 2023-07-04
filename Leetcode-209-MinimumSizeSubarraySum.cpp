class Solution 
{
    public:
        int minSubArrayLen(int target, vector<int>& nums) 
        {
            int n = nums.size();
            int i = 0, j = 0;
            int res = INT_MAX, sum = 0;

            while (j < n) 
            {
                sum += nums[j];
                while (sum >= target) 
                {
                    res = min(res, j-i+1);
                    sum -= nums[i];
                    i++;
                }
                j++;
            }

            if (res == INT_MAX)
                return 0;

            return res;
        }
};
