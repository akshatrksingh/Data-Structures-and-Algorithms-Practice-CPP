class Solution 
{
    public:
        uint32_t reverseBits(uint32_t n) 
        {
            uint32_t m = 0;
            for (int i = 0; i < 32; i++) 
            {
                m <<= 1;               // Left shift m by 1 to make space for the next bit
                m |= (n & 1);          // Set the least significant bit of m to the current bit of n
                n >>= 1;               // Right shift n by 1 to get the next bit
            }
            return m;
        }
};
