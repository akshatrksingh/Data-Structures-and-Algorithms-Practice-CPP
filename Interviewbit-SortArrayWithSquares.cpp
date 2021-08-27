vector<int> Solution::solve(vector<int> &v) 
{ 
    vector <int> s;
    vector <int> p;
    vector <int> n;
    for(int i: v)
    {
        if(i >= 0)
            p.push_back(i*i);
        else
            n.push_back(i*i);
        
    }
    reverse(n.begin(), n.end());
    auto pb = p.begin(), nb = n.begin(), pe = p.end(), ne = n.end();
    while(pb < pe && nb < ne)
    {
        if(*pb < *nb)
        {
            s.push_back(*pb++);
        }
        else
        {
            s.push_back(*nb++);
        }
    }
    while(pb < pe)
    {
        s.push_back(*pb++);
    }
    while(nb < ne)
    {
        s.push_back(*nb++);
    }
    return s;
}
