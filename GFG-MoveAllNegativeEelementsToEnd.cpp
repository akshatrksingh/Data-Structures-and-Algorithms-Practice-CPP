class Solution
{
    public:
    void segregateElements(int a[],int n)
    {
        int b[n];
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(a[i] >= 0)
            {
                b[c++] = a[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(a[i] < 0)
            {
                b[c++] = a[i];
            }
        }
        for(int i = 0; i < n; i++)
        {
            a[i] = b[i];
        }
    }
};
