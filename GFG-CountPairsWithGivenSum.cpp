class Solution
{   
    public:
        int getPairsCount(int arr[], int n, int k) 
        {
            int ans = 0;
            unordered_map<int, int> freq;
            for(int i = 0; i < n; i++)
            {
                ans += freq[k-arr[i]];
                freq[arr[i]]++; 
            }
            return ans;
        }
};
