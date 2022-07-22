#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long lb = 1, ub = n*n, mid, leq;
    long long res = -1;
    while (lb <=  ub)
	{
		mid = lb + (ub-lb)/2;
        leq = 0;
		for (int i = 1; i <= n; i++)
		{
			leq += min(n, mid/i);
		}
		if (leq >= (n*n +1)/2)
		{
            res = mid;
			ub = mid-1;
		}
		else
		{
			lb = mid+1;
		}
	}
	cout<<res<<endl;
	return 0;
}