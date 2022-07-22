class Solution 
{
    public:
        bool isValid(int n, int m, int mid, int k)
        {
            int leq = 0;
            for (int i = 1; i <= m; i++)
            {
                leq += min(n, mid/i);
            }    
            return leq >= k;
        }
        int findKthNumber(int m, int n, int k) 
        {
            int lb = 1, ub = m*n, mid;
            int res = -1;
            while (lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(isValid(n, m, mid, k))
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
