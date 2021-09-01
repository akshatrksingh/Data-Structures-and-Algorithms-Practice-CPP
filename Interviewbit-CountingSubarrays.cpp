int Solution::solve(vector<int> &v, int k) 
{
    int c = 0;
    int sum;
    for(auto i = v.begin(); i < v.end(); i++)
    {
        sum = 0;
        for(auto j = i; j < v.end(); j++)
        {
            sum += *j;
            if(sum < k)
            {
                c++;
            }
            else
            {
                break;
            }
        }
    }
    return c;
}
