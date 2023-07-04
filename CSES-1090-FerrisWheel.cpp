#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin>>n>>x;
    int p[n];
    for(int i = 0; i < n; i++)
    {
        cin>>p[i];
    }
    sort(p, p+n);
    int left = 0, right = n-1;
    int res = 0;
    while(left < right)
    {
        if(p[left] + p[right] <= x)
        {
            res++;
            left++;
            right--;
        }
        else
        {
            res++;
            right--;
        }
    }
    if(left == right)
    {
        res++;
    }
    cout<<res<<"\n";
    return 0;
}