#include <bits/stdc++.h>
using namespace std;

int solve(int item, int val_left, int wt[], int val[], vector<vector<int>> &dp) 
{
    if(val_left == 0)
        return 0;
    if(item < 0)
        return 1e9+1;
    if(dp[item][val_left] != -1)
        return dp[item][val_left];
    if(val[item] <= val_left)    // CHOOSE THE ITEM AT INDEX
        return dp[item][val_left] = min(wt[item] + solve(item-1, val_left-val[item], wt, val, dp),
                                        solve(item-1, val_left, wt, val, dp));
    else                         // DO NOT CHOOSE THE ITEM AT INDEX
        return dp[item][val_left] = solve(item-1, val_left, wt, val, dp);
}         

int main()
{
    int n, w;
    cin>>n>>w;

    int val[n];
    int wt[n];

    for(int i = 0; i < n; i++)
    {
        cin>>wt[i]>>val[i];
    }

    int max_value = 1e5;
    vector<vector<int>> dp(n+1, vector<int>(max_value+1,-1));
    for(int i = max_value; i >= 0; i--)
    {
        //cout<<i<<" ";
        if(solve(n-1, i, wt, val, dp) <= w)
        {
            cout<<i<<"\n";
            break;
        }
    }

    return 0;
}