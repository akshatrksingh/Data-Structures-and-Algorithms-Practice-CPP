int Solution::maxArea(vector<int> &A) 
{
    int m = 0;
    auto left = A.begin();
    auto right = A.end()-1;
    while(left < right)
    {
        int hleft = *left;
        int hright = *right;
        m = max(m, min(hleft, hright)*((int)(right-left)));
        if(hleft < hright)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return m;
}
