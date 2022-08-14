#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
        cin>>h[i]; 
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j <= i+k && j < n; j++)
        {
            dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]));
        }
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}