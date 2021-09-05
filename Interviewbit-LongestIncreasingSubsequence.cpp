int Solution::lis(const vector<int> &v) 
{
    int n = v.size(), m = 1;
    vector<int> arr(n, 1);
    for(int j = 1; j < n; j++)
    {
        for(int i = 0; i < j; i++)
        {
            if(v[i] < v[j])
            {
                arr[j] = max(arr[j], arr[i]+1);
            }
        }
        m = max(m, arr[j]);
    }
    return m;
}
