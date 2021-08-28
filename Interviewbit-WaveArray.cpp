vector<int> Solution::wave(vector<int> &v) 
{
    sort(v.begin(), v.end());
    if(v.size() == 1)
    {
        return v;
    }
    for(auto it = v.begin(); it < v.end()-1; it += 2)
    {
        swap(*it, *(it+1));
    }
    return v;
}
