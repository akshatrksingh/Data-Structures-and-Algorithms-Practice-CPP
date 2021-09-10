vector<int> Solution::searchRange(const vector<int> &A, int B) 
{
    vector<int> s;
    if(binary_search(A.begin(), A.end(), B))
    {
        s.push_back(lower_bound(A.begin(), A.end(), B)-A.begin());
        s.push_back(upper_bound(A.begin(), A.end(), B)-A.begin()-1);
        return s;
    }
    else
    {
        return {-1, -1};
    }
}
