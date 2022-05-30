queue<int> rev(queue<int> q)
{
    queue<int> r;
    stack<int> s;
    int n = q.size();
    for(int i = 0; i < n; i++)
    {
        s.push(q.front());
        q.pop();
    }
    for(int i = 0; i < n; i++)
    {
        r.push(s.top());
        s.pop();
    }
    return r;
}
