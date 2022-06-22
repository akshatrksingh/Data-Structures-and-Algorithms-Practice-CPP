/* The following sliding window technique would not work for arrays with negative elements
class Solution
{
    public:
    int lenOfLongSubarr(int arr[], int n, int k) 
    {
        int i = 0, j = 0;
        int sum = 0, m = 0;
        while(j < n)
        {
            sum += arr[j];
            if(sum < k)
            {
                j++;
            }
            else if(sum == k)
            {
                m = max(m, j-i+1);
                j++;
            }
            else if(sum > k)
            {
                while(sum > k)
                {
                    sum -= arr[i];
                    i++;
                }
                if(sum == K)
                {
                    m = max(m, j-i+1);
                }
                j++;
            }
        }
        return m;
    }
};
*/

// prefix sum
class Solution
{
    public:
    int lenOfLongSubarr(int arr[], int n, int k) 
    {
        int i = 0;
        int sum = 0, m = 0;
        unordered_map<int, int> map;
        while(i < n)
        {
            sum += arr[i];
            if(sum == k)
            {
                m = max(m, i+1);
            }
            if(map.find(sum-k) != map.end())
            {
                m = max(m, i-map[sum-k]);
            }
            if(map.find(sum) == map.end())
            {
                map[sum] = i;
            }
            i++;
        }
        return m;
    }
};
