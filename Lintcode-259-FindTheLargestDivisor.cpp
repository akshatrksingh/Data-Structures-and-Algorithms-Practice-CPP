class Solution 
{
    public:
        bool isValid(vector<int> A, int N, int threshold, int min_divisor)
        {
            int sum = 0;
            for(int i = 0; i < N; i++)
            {
                sum += ceil(A[i]*1.0/min_divisor);  // maximize min_divisor
            }
            if(sum < threshold)
                return false;
            return true;
        }
        int findDivisor(vector<int> &nums, int threshold) 
        {
            int lb = 1;
            int ub = *max_element(nums.begin(), nums.end());
            int res = -1;
            while(lb <= ub)
            {
                int mid = lb + (ub-lb)/2;
                if(isValid(nums, nums.size(), threshold, mid))
                {
                    res = mid;
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            return res;
        }
};
