int Solution::cntBits(vector<int> &v) 
{
    int s = 0, cnt;
    for (int i = 31; i >= 0; i--) 
    {
        cnt = 0;
        for (auto it = v.begin(); it < v.end(); it++)
        {
            if((*it)&(1<<i))
            {
                cnt++;
            }
        }
        s += ((cnt*(v.size()-cnt)*2) % (int)(pow(10, 9)+7));
        s %= (int)(pow(10, 9)+7);
    }
    return s%(int)(pow(10, 9)+7);
}
