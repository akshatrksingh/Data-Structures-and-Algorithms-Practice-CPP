int Solution::numSetBits(unsigned int num) 
{
    int c = 0;
    for(int i = 31; i >= 0; i--)
    {
        if(num & (1<<i))
        c++;
    }
    return c;
}
