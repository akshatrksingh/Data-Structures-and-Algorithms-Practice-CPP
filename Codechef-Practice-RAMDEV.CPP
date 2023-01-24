#include <bits/stdc++.h>
using namespace std;

int main() 
{
	long long l, b, n, ans = 0;
	cin>>l>>b>>n;
	for(int i = 0; i < n; i++)
	{
	    long long L, B;
	    cin>>L>>B;
	    ans += max((L/l)*(B/b), (L/b)*(B/l));
	}
	cout<<ans;
	return 0;
}
