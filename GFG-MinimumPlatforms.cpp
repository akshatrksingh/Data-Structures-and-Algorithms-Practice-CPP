class Solution
{
    public:
        
        int findPlatform(int arr[], int dep[], int n)
        {
            sort(arr, arr+n);
            sort(dep, dep+n);
            int temp = 1, plat = 1;
            int i = 0, j = 1;
            while(i < n && j < n)
            {
                if(dep[i] >= arr[j])
                {
                    temp++;
                    j++;
                }
                else
                {
                    temp--;
                    i++;
                }
                plat = max(plat, temp);
            }
            return plat;
        }
};
