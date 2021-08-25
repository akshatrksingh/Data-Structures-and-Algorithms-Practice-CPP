vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) 
{
    auto v1 = A;
    auto v2 = B;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    vector<int> v;
    int p1 = 0, p2 = 0;
    while(p1 < v1.size() && p2 < v2.size())
    {
        if(v1[p1] == v2[p2])
        {
            v.push_back(v1[p1]);
            p1++;
            p2++;
        } 
        else if(v1[p1] < v2[p2])
        {
            p1++;
        }
        else
        {
            p2++;
        }
    }
    return v;
}
