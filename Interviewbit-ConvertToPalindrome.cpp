int Solution::solve(string s) 
{
    int c = 0;
    auto it = s.begin();
    for(int i = 0; i < s.size()/2; i++)
    {
        if(s[i] != s[s.size()-i-1] && c == 0)
        {
            c++;
            s.erase(it);
            i--;
        }
        else if(s[i] != s[s.size()-i-1])
        {
            return 0;
        }
        it++;
    }
    return 1;
}
