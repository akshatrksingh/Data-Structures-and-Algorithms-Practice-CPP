int Solution::power(string s) 
{
    unsigned long long int num = 0;
    for (int i = 0; i < s.length(); i++) 
    {
        num = num*10+(s[i]-'0');
    }
    if(num == 1)
        return 0;
    while(num > 1)
    {
        if(num%2 == 0)
        {
            num /= 2;
        }
        else
        {
            return 0;
        }
    }
    return 1;
}
