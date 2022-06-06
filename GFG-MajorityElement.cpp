class Solution{
  public:
    int majorityElement(int a[], int n)
    {
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[a[i]]++;
        }
        int mx1 = INT_MIN, mx2;
        for(auto n: m)
        {
            if(mx1 < n.second)
            {
                mx1 = n.second;
                mx2 = n.first;
            }
        }
        return (mx1>n/2)?mx2:-1;
    }
};
