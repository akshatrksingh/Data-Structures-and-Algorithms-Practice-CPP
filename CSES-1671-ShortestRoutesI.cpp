#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
vector<vector<pll>> adjList(100005);
int n, m;
 
void dijkstra()
{
    const ll INF = 1e17; 
    vector<ll> dist(n, INF);
    vector<bool> processed(n, false);   // optimize by flagging nodes popped from the priority queue
    priority_queue<pll, vector<pll>, greater<pll>> q; // min heap
    dist[0] = 0;
    q.push({0, 0});     // {distance, node}      
    while(!q.empty())
    {
        auto best = q.top();   // greedy: get shortest unvisited vertex
        q.pop();
        ll u = best.second;
        if (processed[u]) 
            continue;
        processed[u] = true;
        for(auto nbr: adjList[u]) 
        {
            ll v = nbr.first;
            ll weight = nbr.second;
            if(dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;     // relax operation
                q.push({dist[v], v});           // enqueue better pair
            }
        }
    }
    for(auto d: dist)
    {
        cout<<d<<" ";
    }
}
 
int main()
{
    int a, b, c;
    cin>>n>>m; 
 
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        adjList[a-1].push_back({b-1, c});
    }
    dijkstra();
 
	return 0;
}