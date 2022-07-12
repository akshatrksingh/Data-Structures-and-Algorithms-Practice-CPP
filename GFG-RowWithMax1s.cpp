class Solution
{
    public:
    	int rowWithMax1s(vector<vector<int>> arr, int n, int m) 
    	{
    	    int mx = 0;
    	    int rmx = -1;
    	    for(int row = 0; row < n; row++)
    	    {
    	        int ones = 0;
    	        for(auto num: arr[row])
    	        {
    	            if(num == 1)
    	                ones++;
    	        }
    	        if(ones > mx)
    	        {
    	            rmx = row;
    	            mx = ones;
    	        }
    	    }
    	    return rmx;
    	}
};
