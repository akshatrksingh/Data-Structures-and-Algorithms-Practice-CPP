string Solution::convert(string s, int n) 
{
    vector<vector<char>> arr(n);
    auto it = s.begin();
    while(it < s.end())
    {
        for(int i = 0; i < n; i++)
        {
            if(it == s.end())
                break;
            arr[i].push_back(*it);
            it++;
        }
        for(int i = n-2; i > 0; i--)
        {
            if(it == s.end())
                break;
            arr[i].push_back(*it);
            it++;
        }
    }
    string st = "";
    for(auto x: arr)
    {
        for(auto y: x)
        {
            st += y;
        }
    }
    return st;
}
