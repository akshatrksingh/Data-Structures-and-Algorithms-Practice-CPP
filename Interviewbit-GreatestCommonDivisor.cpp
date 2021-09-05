int Solution::gcd(int n1, int n2) 
{
    if(n1 < n2)
    {
        return gcd(n2, n1);
    }

    if(n2 == 0)
    {
        return n1;
    }

    return gcd(n2, n1%n2);
}
