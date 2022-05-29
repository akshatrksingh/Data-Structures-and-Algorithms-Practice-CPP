// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) 
    {
        long int num;
        long int lb = 1 , mid, ub = n;
        while(lb <= ub)
        {
            mid = (lb+ub)/2;
            if(!isBadVersion(mid))
            {
                lb = mid+1;
            }
            else
            {
                num = mid;
                ub = mid-1;
            }
        }
        return (int)num;   
    }
};
