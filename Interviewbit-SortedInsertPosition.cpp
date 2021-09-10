int Solution::searchInsert(vector<int> &A, int B) 
{
    int lb = 0, mid, ub = A.size();

    while(lb <= ub)
    {
        mid = (lb+ub)/2;
        if(B == A[mid])
        {
            return mid;
        }
        else if(B < A[mid])
        {
            ub = mid-1;
        }
        else if(B > A[mid])
        {
            lb = mid+1;
        }
    }
    if(A[mid] < B)
    {
        return mid+1;
    }
    else
    {
        return mid;
    }
}
