class Solution 
{
    public:
        vector<int> singleNumber(vector<int>& nums) 
        {
            int xorResult = 0;
            for (int num : nums) 
            {
                xorResult ^= num;
            }

            int rightmostSetBit = 1;
            while ((rightmostSetBit & xorResult) == 0) 
            {
                rightmostSetBit <<= 1;                  // Left shift to find the next set bit
            }

            int num1 = 0, num2 = 0;
            for (int num : nums) 
            {
                if ((num & rightmostSetBit) != 0) 
                {
                    num1 ^= num;
                } 
                else 
                {
                    num2 ^= num;
                }
            }

            return {num1, num2};
        }
};
