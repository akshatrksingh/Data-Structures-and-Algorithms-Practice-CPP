unsigned int Solution::reverse(unsigned int num) 
{
    int tmp = num;
    for(int i = 0; i <= 31; i++)
    {
        if(num&(1<<i))
        {
            tmp |= 1<<(31-i);
        }
        else
        {
            tmp &= ~(1<<(31-i));
        }
    }
    return tmp;
}
