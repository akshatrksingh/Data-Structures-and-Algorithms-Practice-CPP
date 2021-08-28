int Solution::maxSubArray(const vector<int> &v) 
{
    int max = INT_MIN;
    int sum;
    for(auto i = v.begin(); i < v.end(); i++)
    {
        sum += *i;
        if(sum > max)
        {
            max = sum;
        }
        if(sum < 0)
        {
            sum = 0;
        }
    }
    return max;
}
