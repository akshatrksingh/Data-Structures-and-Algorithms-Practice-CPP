class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int l = 0, r = n-1;
        for(int i = l; i <= r; i++)
        {
            if(a[i] == 0) 
            {
                swap(a[i], a[l++]);
            }
            else if(a[i] == 2)
            {
                swap(a[i--], a[r--]);
            }
        }
    }
};
