#include <bits/stdc++.h>
using namespace std;

void lcs(string s1, string s2)
{
    int x = s1.size(), y = s2.size();
    vector<vector<int>> dp(x+1, vector<int>(y+1, -1));     
    for(int i = 0; i <= x; i++)
    {
        for(int j = 0; j <= y; j++)
        {
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= y; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else if(s1[i-1] != s2[j-1])
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    int i = x, j = y;
    string s = "";
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1] > dp[i-1][j]) 
                j--;
            else
                i--;
        }
    }
    reverse(s.begin(), s.end());
    cout<<s<<"\n";
}         

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    lcs(s1, s2);
    return 0;
}