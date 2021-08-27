vector<int> Solution::maxset(vector<int> &v) 
{
    vector<int> s1, s2;
    long sum1 = 0, sum2 = -1;
    for(long i: v)
    {
        if(i >= 0)
        {
            s1.push_back(i);
            sum1 += i;
        }
        else 
        {
            if(sum1 > sum2 )
            {
                s2 = s1;
                sum2 = sum1;
            }
            else if(sum1 == sum2 && s1.size() > s2.size())
            {
                s2 = s1;
                sum2 = sum1;
            }
            sum1 = 0;
            s1.clear();
        }
    }
    if(sum1 > sum2)
    {
        s2 = s1;
        sum2 = sum1;
    }
    else if(sum1 == sum2 && s1.size() > s2.size())
    {
        s2 = s1;
        sum2 = sum1;
    }
    return s2;
}
