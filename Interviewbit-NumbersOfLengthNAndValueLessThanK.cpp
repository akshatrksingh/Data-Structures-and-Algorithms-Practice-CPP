vector<int> numToVec(string strnum)
{
    vector<int> digit;
    for(auto c: strnum)
    {
        digit.push_back(c-48);
    }
    return digit;
}

int Solution::solve(vector<int>& A, int b, int c)
{
    vector<int> digit = numToVec(to_string(c));
    int d = A.size(), lc = digit.size(), l;

    if (b > lc || d == 0)
    {
        return 0;
    }
 
    else if (b < lc) 
    {
        if (A[0] == 0 && b != 1)
        {
            return (d-1)*pow(d, b-1);
        }
        else
        {
            return pow(d, b);
        }
    }
 
    else 
    {
        int dp[b+1] = {0};
        int lower[11] = {0};
 
        for (int i = 0; i < d; i++)
        {
            lower[A[i]+1] = 1;
        }
        for (int i = 1; i <= 10; i++)
        {
            lower[i] += lower[i - 1];
        }
 
        bool flag = true;
        dp[0] = 0;
        for (int i = 1; i <= b; i++) 
        {
            l = lower[digit[i - 1]];
            dp[i] = dp[i-1]*d;
            if (i == 1 && A[0] == 0 && b != 1)
            {
                l = l - 1;
            }
            if (flag)
            {
                dp[i] += l;
            }
            flag &= lower[digit[i - 1] + 1] == lower[digit[i - 1]] + 1;  // Is digit[i - 1] present in A ?
        }
        return dp[b];
    }
}
