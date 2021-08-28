int Solution::solve(vector<int> &v) 
{
    int max = INT_MIN;
    int min = INT_MAX;
    for(auto i: v)
    {
        if(i > max)
        {
            max = i;
        }
        if(i < min)
        {
            min = i;
        }
    }
    return max+min;
}
