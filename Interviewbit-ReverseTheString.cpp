string trim(string x) 
{
    int beg = 0, end = x.size()-1;
    for(int i = 0; i < x.size(); i++) 
    {
        if(x[i] != ' ') 
        {
            beg = i;
            break;
        }
    }
    for(int i = x.size()-1; i >= 0; i--) 
    {
        if(x[i] != ' ')
        {
            end = i;
            break;
        }
    }
    string y = "";
    for(int i = beg; i <= end; i++) 
        {
            y += x[i];
        }
    return y;
}

string Solution::solve(string A) 
{
    int sp = 0;
    int i = 0;
    string s, word = "";
    if(A[s.size()-1] != ' ')
    { 
        A += ' ';
    }
    for(auto c: A)
    {
        if(c >= 65 && c <= 122)
        {
            word += c;
            i = 0;
        }
        else
        {
            sp++;
            if(i == 1)
            {
                continue;
            }
            s = word + " " + s;
            word = "";
            i = 1;
        }

    }
    if(sp == 0)
    {
        return trim(A);
    }
    else
    {
        return trim(s);
    }
}
