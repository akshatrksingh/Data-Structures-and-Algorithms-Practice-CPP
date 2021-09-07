string Solution::solve(string s) 
{
    bool largest = true;
    bool smallest = true;
    int n = s.size();
    char c;
    string x = "", res="";
    for(auto it = s.begin(); it < s.end()-1; it++)
    {
        if(*it < *(it+1))
        {
            largest = false;
        }
        if(*it > *(it+1))
        {
            smallest = false;
        }
    }
    if(largest)
    {
        return "-1";
    }
    else if(smallest)
    {

        for(auto it = s.end()-2; it >= s.begin(); it--)
        {
            if(*it != *(it+1))
            {
                c = *it;
                *it = s[s.size()-1];
                s[s.size()-1] = c; 
                break;
            }
        }
        return s;
    }
    else
    {
        for(int i = n-1; i > 0; i--)
        {
            if(s[i-1] >= s[i])
            {
                x += s[i];
            }
            else
            {
                x += s[i];
                sort(x.begin(), x.end());
                for(int j = 0; j < x.size(); j++)
                {
                    if(x[j] > s[i-1])
                    {
                        c = x[j];
                        x[j] = s[i-1];
                        s[i-1] = c;
                        break;
                    }
                }
                for(int k = 0; k < s.size()-x.size(); k++)
                {
                    res += s[k];
                }
                for(int m = 0; m < x.size(); m++)
                {
                    res += x[m];
                }
                break;
            }
        }
    }
    return res;
}
