int Solution::solve(vector<int> &v, int k) 
{
    sort(v.begin(), v.end());
    int p1 = 0;
    int p2 = 1;
    while(p1 < v.size() && p2 < v.size())
    {
        if(v[p2]-v[p1] == k && p1 != p2) 
        {
            return 1;
        }
        else if(v[p2]-v[p1] < k)
        {
            p2++;
        }
        else
        {
            p1++;
        }
    }
    return 0;
}
