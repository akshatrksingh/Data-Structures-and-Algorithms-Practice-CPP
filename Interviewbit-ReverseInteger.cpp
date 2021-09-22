typedef long long ll;
int Solution::reverse(int A) 
{
    ll t, n = 0, r, c;
    if(A < 0)
    {
        t = -A;
        while(t > 0)
        {
            r = t%10;
            n = r+n*10;
            t /= 10;
        }
        if(-n < INT_MIN)
        {
            return 0;
        }
        else
        {
            return -n;
        }
    }
    else
    {
        t = A;
        while(t > 0)
        {
            r = t%10;
            n = r+n*10;
            t /= 10;
        }
        if(n > INT_MAX)
        {
            return 0;
        }
        else
        {
            return n;
        }
    }
}
