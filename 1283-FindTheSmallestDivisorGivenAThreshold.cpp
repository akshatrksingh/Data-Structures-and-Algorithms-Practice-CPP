class Solution 
{
    public:
        bool isValid(vector<int> A, int N, int threshold, int max_divisor)
        {
            int sum = 0;
            for(int i = 0; i < N; i++)
            {
                sum += ceil(A[i]*1.0/max_divisor);
                if(sum > threshold)
                    return false;
            }
            return true;
        }
        int smallestDivisor(vector<int> &nums, int threshold) 
        {
            sort(nums.begin(), nums.end());
            int lb = 1;
            int ub = *max_element(nums.begin(), nums.end());
            int res = -1;
            while(lb <= ub)
            {
                int mid = lb + (ub-lb)/2;
                if(isValid(nums, nums.size(), threshold, mid))
                {
                    res = mid;
                    ub = mid-1;
                }
                else
                {
                    lb = mid+1;
                }
            }
            return res;
        }
};
