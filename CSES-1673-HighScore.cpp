#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int>> edgeList;
int n, m;
 
void bellmanFord()
{
    const ll INF = 1e17;
    const ll NINF = INF*(-1);
    vector<ll> dist(n, INF);
    dist[0] = 0;
	for(int i = 0; i < n-1; i++)
	{
		for(auto edge: edgeList)
		{
			int u = edge[0];
			int v = edge[1];
			int d = edge[2];
            if(dist[u] == INF) continue;  
			dist[v] = min(dist[v], d+dist[u]);
			dist[v] = max(dist[v], NINF);
		}
	} 
    
	for(int i = 0; i < n-1; i++)
	{
		for(auto edge: edgeList)
		{
			int u = edge[0];
			int v = edge[1];
			int d = edge[2];
            if(dist[u] == INF) continue;
			if(dist[u]+d < dist[v])
			{
                dist[v] = NINF;
			}
		}
	}

    if(dist[n-1] == NINF)
	{
		cout << -1 << endl;
	} 
	else
    {
        cout << dist[n-1] * (-1) << endl;
    }
}
 
 
int main()
{
	cin >> n >> m;
	edgeList.resize(m);
	for(int i = 0; i < m; ++i)
	{
		vector<int> edge(3);
		cin >> edge[0] >> edge[1] >> edge[2];
        edge[0] -= 1;     // change indexing
        edge[1] -= 1;     // change indexing
		edge[2] *= -1;    // SSLP to SSSP
		edgeList[i] = edge;
	}
 
	bellmanFord();
	
}