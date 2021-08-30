int Solution::lengthOfLastWord(const string s) 
{
    int c = 0;
    for(auto it = s.end()-1; it >= s.begin(); it--)
    {
        if(*it != ' ')
            c++;
        else if(c > 0)
            break;
    }
    return c;
}
