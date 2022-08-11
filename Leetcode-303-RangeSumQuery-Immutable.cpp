class NumArray 
{
    public:
        vector<int> prefSum;
        NumArray(vector<int> &nums) 
        {
            int n = (nums.size());
            prefSum.clear();
            prefSum.resize(n+1);
            prefSum[0] = 0;
            for(int i = 1; i <= n; i++)
            {
                prefSum[i] = prefSum[i-1] + nums[i-1];
            }
        }

        int sumRange(int left, int right) 
        {
            return prefSum[right+1] - prefSum[left];
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
