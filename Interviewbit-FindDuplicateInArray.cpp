int Solution::repeatedNumber(const vector<int> &v) 
{
    int n = v.size(), t;
    int b[n] = {0};
    for(auto it = v.begin(); it < v.end(); it++)
    {
        b[*it]++;
        if(b[*it] > 1)
            return *it;
    }
    return -1;
}
