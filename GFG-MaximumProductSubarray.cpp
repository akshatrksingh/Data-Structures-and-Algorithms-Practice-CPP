class Solution
{
    public:
    	long long maxProduct(vector<int> arr, int n) 
    	{
    	    int i = 0, j = 0;
            long long prod = 1, m = INT_MIN;
            while(j < n)
            {
                if(arr[j] == 0 && prod < 0 && i < j)
                {
                    prod /= arr[i];
                    i++;
                    m = max(m, prod);
                }
                else if(arr[j] == 0)
                {
                    m = max(m, (long long)0);
                    prod = 1;
                    j++;
                    i = j;
                }
                else
                {
                    prod *= arr[j];
                    m = max(m, prod);
                    j++;
                }
            }
            while(prod < 0 && i < n-1)
            {
    	        prod /= arr[i];
    	        m = max(m, prod);
    	        i++;
    	    }
            return m;
    	}
};
