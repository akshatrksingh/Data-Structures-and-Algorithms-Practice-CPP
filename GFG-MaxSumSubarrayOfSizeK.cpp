class Solution
{   
    public:
        long maximumSumSubarray(int k, vector<int> &arr , int n)
        {
            int i = 0, j = 0;
            long sum = 0, m = INT_MIN;
            while(j < n)
            {
                sum += arr[j];
                if(j-i+1 < k)
                {
                    j++;
                }
                else if(j-i+1 == k)
                {
                    m = max(m, sum);
                    sum -= arr[i];
                    i++;
                    j++;
                }
            }
            return m;
        }
};
