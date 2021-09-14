string Solution::solve(string A) 
{
    map<char, int> m;
    queue<char> q;
    string s;
    for(auto c :A)
    {
        m[c]++;
        q.push(c);
        while(!q.empty() && m[q.front()] > 1)   
        {
            q.pop();
        }
        if(!q.empty())                         
        {
            s.push_back(q.front());
        }
        else                                    
        {
            s.push_back('#');
        }
    }
    return s;
}
