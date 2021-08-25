void Solution::sortColors(vector<int> &A) 
{
    int p0 = 0, p2 = A.size()-1, p = 0;
    while(p <= p2)
    {
        if(A[p] == 0)
        {
            swap(A[p0++], A[p++]);
        }
        else if(A[p] == 2)
        {
            swap(A[p2--], A[p]);
        }
        else
        {
            p++;
        }
    }
}
