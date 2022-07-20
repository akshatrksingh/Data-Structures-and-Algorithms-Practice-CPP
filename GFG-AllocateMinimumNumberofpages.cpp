class Solution 
{
    public:
    bool isValid(int A[], int N, int M, int mx)
    {
        int student = 1;
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
            if(sum > mx)
            {
                student++;
                sum = A[i];
            }
            if(student > M)
                return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        if(N < M)
            return -1;
        int lb = *max_element(A, A+N);
        int ub = accumulate(A, A+N, 0);
        int res = -1;
        while(lb <= ub)
        {
            int mid = lb + (ub-lb)/2;
            if(isValid(A, N, M, mid))
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
