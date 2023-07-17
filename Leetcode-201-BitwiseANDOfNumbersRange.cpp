class Solution 
{
    public:
        int rangeBitwiseAnd(int left, int right) 
        {
            if(left == 0)
            {
                return 0;
            }
            if((int)log2(left) != (int)log2(right))    // power of 2 lies between left and right 
            {
                return 0;
            }
            int res = left;
            while(left < right)
            {
                res &= ++left;
            }
                return res;
        }
    };
