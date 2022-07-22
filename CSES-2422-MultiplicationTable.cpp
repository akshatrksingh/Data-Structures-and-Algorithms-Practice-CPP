// https://usaco.guide/problems/cses-2422-multiplication-table/solution#explanation
#include <bits/stdc++.h>
using namespace std;

bool isValid(long long n, long long mid)
{
    long long leq = 0;
    for (int i = 1; i <= n; i++)
	{
		leq += min(n, mid/i);
	}    
    return leq >= (n*n +1)/2;
}

int main()
{
    long long n;
    cin>>n;
    long long lb = 1, ub = n*n, mid;
    long long res = -1;
    while (lb <=  ub)
	{
		mid = lb + (ub-lb)/2;
		
		if(isValid(n, mid))
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