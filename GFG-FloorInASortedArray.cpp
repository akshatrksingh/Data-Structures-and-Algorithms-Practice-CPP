class Solution
{
  public:
    int findFloor(vector<long long> v, long long n, long long x)
    {
        int lb = 0, ub = n-1, mid;
        int ans = -1;
        while(lb <= ub)
        {
            mid = lb + (ub-lb)/2;
            if(v[mid] <= x)
            {
                ans = max(ans, mid);
            }
            if(v[mid] < x)
            {
                lb = mid+1;
            }
            else
            {
                ub = mid-1;
            }
        }
        return ans;
    }
};
