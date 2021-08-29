int Solution::singleNumber(const vector<int> &v) 
{
    int  c1, num = 0;
    for(int i = 31; i >= 0; i--)
    {
        c1 = 0;
        for(auto j: v)
        {
            if(j & (1<<i))
                c1++;
        }
        if(c1 % 2 != 0)
        {
            num += pow(2, i);
        }
    }
    return num;
}
