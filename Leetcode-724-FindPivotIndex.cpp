class Solution 
{
    public:
        vector<int> prefSum;
        int pivotIndex(vector<int> &nums) 
        {
            int n = nums.size();
            prefSum.clear();
            prefSum.resize(n+1);
            prefSum[0] = 0;
            for(int i = 1; i <= n; i++)
            {
                prefSum[i] = prefSum[i-1] + nums[i-1];
            }
            
            int leftSum, rightSum;
            for(int i = 1; i <= n; i++)
            {
                leftSum = prefSum[i]-nums[i-1];
                rightSum = prefSum[n]-prefSum[i];
                if(leftSum == rightSum)
                {
                    return i-1;
                }
            }
            return -1;
        }
};
