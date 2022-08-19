#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adjList, int n, int src, vector<bool> &vis, vector<int> &dp)
{
    vis[src] = true;
    for(int nbr: adjList[src])
    {
        if(!vis[nbr])
        {
            dfs(adjList, n, nbr, vis, dp);
        }
        dp[src] = max(dp[src], 1+dp[nbr]);
    }
}

void longestPath(vector<vector<int>> &adjList, int n)
{
    vector<int> dp(n+1, 0);
    vector<bool> vis(n+1, false);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(adjList, n, i, vis, dp);
        }
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) 
    {
        mx = max(mx, dp[i]);
    }
    cout<<mx<<"\n";
}         

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adjList(n+1);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }
    longestPath(adjList, n);
    return 0;
}