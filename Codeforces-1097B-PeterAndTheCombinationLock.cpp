#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin>>n;
    m = n;
    int a[n];
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    while(m--)
    {
        int sum;
        for(int num = 0; num < (1 << n); num++)
        {
            sum = 0;
            for(int bit = 0; bit < n; bit++)
            {
                if(num & (1 << bit))
                {
                    sum += a[bit];
                }
                else
                {
                    sum -= a[bit];
                }
            }
            if(sum % 360 == 0)
            {
                flag = true;
                break;
            }
        }
    }  
    if(flag)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
  return 0;
}