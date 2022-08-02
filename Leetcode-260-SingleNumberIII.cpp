class Solution 
{
    public:
        vector<int> singleNumber(vector<int> &nums) 
        {
            int XOR = 0, idx;  
            for(int i: nums)
            {
                XOR ^= i;
            }
            /*
            XOR contains a^b where and b are the required numbers
            The bit 0 in XOR would imply a and b have the same digit at that place
            The bit 1 in XOR would imply a and b have different digits at that place
            There will be atleast one index where they differ because they are not the same
            Hence XOR will contain the bit 1 atleast once
            We could consider any such occurence of bit 1 to extract a and b
            Here we consider the rightmost such set bit
            */
            for(int i = 0; i < 32; i++)
            {
                if(XOR&(1<<i))  // Test if the ith bit is set
                {
                    idx = i;
                    break;
                }
            }
            
            /* 
            a and b differ at this set bit of XOR
            Only 1 of the numbers out of a and b would have bit 1 at idx 
            Let that number be a WLOG
            XOR only numbers where the bit at idx is set i.e. 1
            Thus we extract a
            */
            int a = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i]&(1<<idx))  // Test if the ith bit is set
                {
                    a ^= nums[i];
                }
            }
            
            int b = a^XOR;
            return {a, b};
        }
};
