int Solution::solve(vector<int> &A, int B) 
{
    if(A[0] > B)
    {
        return 0;
    }
    else 
    {
        return upper_bound(A.begin(), A.end(), B)-A.begin();
    }
}
