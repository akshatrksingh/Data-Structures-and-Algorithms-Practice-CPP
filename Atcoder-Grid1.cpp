#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> &grid, int h, int w)
{
    vector<vector<long long>> dp(h, vector<long long>(w, 0));
    for(int i = 0; i < h; i++)
    {
        if(grid[i][0] == '.')
        {
            dp[i][0] = 1;
        }
        else
        {
            break;
        }
    }
    for(int j = 0; j < w; j++)
    {
        if(grid[0][j] == '.')
        {
            dp[0][j] = 1;
        }
        else
        {
            break;
        }
    }
    for(int i = 1; i < h; i++)
    {
        for(int j = 1; j < w; j++)
        {
            if(grid[i][j] == '.')
            {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%((int)1e9+7);
            }
        }
    }
    cout<<dp[h-1][w-1]%((int)1e9+7)<<"\n";
}         

int main()
{
    int h, w;
    cin>>h>>w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++)
    {
        cin>>grid[i];
    }
    solve(grid, h, w);
    return 0;
}