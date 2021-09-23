bool vowel(char c)
{
    if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int Solution::solve(string S) 
{
    int c = 0;
    for(int i = 0; i < S.size(); i++)
    {
        if(vowel(S[i]))
        {
            c += S.size()-i;
        }
    }
    return c%10003;
}
