#include <bits/stdc++.h>
using namespace std;

long long pow(long long a, long long b, int m) 
{
    a %= m;
    long long res = 1;
    while (b > 0) 
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    long long a;
    long long b;
    int t;
	cin>>t;

    while(t--) 
    {
        cin>>a>>b;
        cout<<pow(a, b, 10)<<"\n";
    }
}
