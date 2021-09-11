int Solution::search(const vector<int> &A, int B) 
{
    vector<int> v;
    bool flag = false;
    for(auto it = A.begin(); it < A.end()-1; it++)
    {
        if(*(it+1) < *it || flag == true)
        {
            flag = true;
            v.push_back(*(it+1));
        }
    }
    if(flag == false)
    {
        return lower_bound(A.begin(), A.end(), B)-A.begin();
    }
    int vn = v.size(), an = A.size();
    for(int i = 0; i < an-vn; i++)
    {
        v.push_back(A[i]);
    }
    if(binary_search(v.begin(), v.end(), B) == false)
    {
        return -1;
    }
    int ind = lower_bound(v.begin(), v.end(), B)-v.begin();
    if(B > A[an-1])
    {
        return ind-vn;
    }
    else
    {
        return ind+an-vn;
    }
}
