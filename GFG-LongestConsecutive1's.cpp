class Solution
{
    public:
    int maxConsecutiveOnes(int N)
    {
        int curr = 0, mx = 0;
        while(N > 0)
        {
            if(N&1)
            {
                curr++;
            }
            else
            {
                mx = max(mx, curr);
                curr = 0;
            }
            N >>= 1;
        }
        return max(mx, curr);
    }
};
