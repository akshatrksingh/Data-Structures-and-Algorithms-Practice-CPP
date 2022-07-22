class Solution 
{
    public:
        int mySqrt(int x) 
        {
            long long lb = 0, mid, ub = x, res;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(mid*mid == x)
                {
                    return mid;
                }
                else if(mid*mid < x)
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
