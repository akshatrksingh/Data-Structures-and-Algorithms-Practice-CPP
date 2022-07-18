class Solution
{
    public:	
    	/* if x is present in arr[] then returns the count
    		of occurrences of x, otherwise returns 0. */
    	int count(int nums[], int n, int x) 
    	{
    	    int lb = 0 , mid, ub = n-1;
    	    int first = -1;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == x)
                {
                    first = mid;
                    ub = mid-1;
                }
                else if(nums[mid] < x)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            lb = 0;
            ub = n-1;
            int last = -1;
            while(lb <= ub)
            {
                mid = lb + (ub-lb)/2;
                if(nums[mid] == x)
                {
                    last = mid;
                    lb = mid+1;
                }
                else if(nums[mid] < x)
                {
                    lb = mid+1;
                }
                else
                {
                    ub = mid-1;
                }
            }
            return (first == -1)? 0: last-first+1;
    	}
};
