#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> points(n, vector<int>(3));
    for(int day = 0; day < n; day++)
    {
        cin>>points[day][0]>>points[day][1]>>points[day][2];
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));    
    dp[0] = {points[0][0], points[0][1], points[0][2]};
    for(int day = 1; day < n; day++)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i != j)
                {
                    dp[day][j] = max(dp[day][j], dp[day-1][i]+ points[day][j]);
                }
            }
        }
    }
    cout<<max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]))<<"\n";
    return 0;
}