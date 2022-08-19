#include <bits/stdc++.h>
using namespace std;

void solve(vector<double> &prob, int n)
{
    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));  
    // dp[i][j] => prob of j heads in i tosses
    dp[1][0] = 1-prob[1];
    dp[1][1] = prob[1];
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            dp[i+1][j+1] += dp[i][j]*prob[i+1];
            dp[i+1][j] += dp[i][j]*(1-prob[i+1]);
        }
    }
    double ans = 0;
    for(int j = n; j > n/2; j--)
    {
        ans += dp[n][j];
    }
    cout<<setprecision(10)<<ans<<"\n";
}         

int main()
{
    int n;
    cin>>n;
    vector<double> prob(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin>>prob[i];
    }
    solve(prob, n);
    return 0;
}