int Solution::removeElement(vector<int> &v, int k) 
{
    int p1 = 0;
    for (int p2 = 0; p2 < v.size(); p2++) 
    {
        if (v[p2] != k) 
        {
            v[p1] = v[p2];
            p1++;
        }
    }
    return p1;
}
