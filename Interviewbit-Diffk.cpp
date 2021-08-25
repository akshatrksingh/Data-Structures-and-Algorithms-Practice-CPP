int Solution::diffPossible(vector<int> &arr, int k) 
{
    if(arr.size() == 1)
    {
        return 0;
    }

    int p1 = 0;
    int p2 = 1;
    while(p1 < p2 && p2 < arr.size())
    {
        if(arr[p2]-arr[p1] == k)
        {
            return 1;
        }
        else if(arr[p2]-arr[p1] < k)
        {
            p2++;
        }
        else
        {
            p1++;
            p2 = p1+1;
        }
    }
    return 0;
}
