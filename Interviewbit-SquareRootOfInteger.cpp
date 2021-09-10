int Solution::sqrt(int A) 
{
    if(A == 0)
    {
        return 0;
    }
    int mid;
    long long sqmid, lb = 1, ub = A;
    while(lb <= ub)
    {
        sqmid = lb*ub;
        mid = pow(sqmid, 0.5);
        if(sqmid == A)
        {
            return mid;
        }
        else if(sqmid < A)
        {
            lb = mid+1;
        }
        else
        {
            ub = mid-1;
        }
    }
    return mid;
}
