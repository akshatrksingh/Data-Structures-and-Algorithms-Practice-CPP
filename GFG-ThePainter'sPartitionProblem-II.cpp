class Solution
{
  public:
    bool isValid(int arr[], int n, int k, long long mx)
    {
        int painter = 1;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            if(sum > mx)
            {
                painter++;
                sum = arr[i];
            }
            if(painter > k)
                return false;
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long lb = *max_element(arr, arr+n);
        long long ub = accumulate(arr, arr+n, 0LL);
        long long res = -1;
        while(lb <= ub)
        {
            long long mid = lb + (ub-lb)/2;
            if(isValid(arr, n, k, mid))
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
