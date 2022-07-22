class Solution 
{
    public:
        bool isValid(vector<int> A, int N, int M, int max_days)
        {
            int day = 1;
            int sum = 0;
            for(int i = 0; i < N; i++)
            {
                if(A[i] > max_days)
                    return false;
                sum += A[i];
                if(sum > max_days)   // minimize max_days
                {
                    day++;
                    sum = A[i];
                }
                if(day > M)
                    return false;
            }
            return true;
        }
        int shipWithinDays(vector<int> &weights, int days) 
        {
            int lb = 0;
            int ub = accumulate(weights.begin(), weights.end(), 0);
            int res = -1;
            while(lb <= ub)
            {
                int mid = lb + (ub-lb)/2;
                if(isValid(weights, weights.size(), days, mid))
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
