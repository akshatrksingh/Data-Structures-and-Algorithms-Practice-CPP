int Solution::findMinXor(vector<int> &A) 
{
    int m = INT_MAX;
    sort(A.begin(), A.end());
    for (auto it = A.begin(); it < A.end()-1; it++)
    {
        m = min(m, *it^*(it+1));
    }
    return m;
}
