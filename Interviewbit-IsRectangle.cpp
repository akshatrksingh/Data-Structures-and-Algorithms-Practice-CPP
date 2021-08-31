int Solution::solve(int A, int B, int C, int D) 
{
    int l = max(A, (max(B, max(C, D))));
    int b = min(A, (min(B, min(C, D))));
    vector<int> v = {A, B, C, D};
    return (count(v.begin(), v.end(), l) == 2 && count(v.begin(), v.end(), b) == 2) || (count(v.begin(), v.end(), l) == 4);
}
