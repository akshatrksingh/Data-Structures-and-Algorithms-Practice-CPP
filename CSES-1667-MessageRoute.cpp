// SSSP on unweighted graph
#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>>adjList(100000);

void printPath(vector<int> &parent, int j)
{
    if (j == -1)
        return;
    printPath(parent, parent[j]);
    cout<<j+1<<" ";
}

void messageRoute(vector<vector<int>> &adjList, int V)
{
    const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow
    vector<int> dist(V, INF);
    vector<int> parent(V, -1);
    queue<pair<int,int>> q; 
    dist[0] = 0;
    q.push({0, 0});     // {distance, node}      
    while(!q.empty())
    {
        auto next = q.front();   
        q.pop();
        int u = next.second;
        for(auto v: adjList[u]) 
        {
            if(dist[v] > dist[u] + 1)
            {
                parent[v] = u;
                dist[v] = dist[u] + 1;     // relax operation
                q.push({dist[v], v});           // enqueue better pair
            }
        }
    }
    if(dist[V-1] == INF)
    {
        cout<<"IMPOSSIBLE";
    }
    else 
    {
        cout<<dist[V-1]+1<<endl;
        printPath(parent, V-1);
    }

}

int main()
{
    int n, m, a, b;
    cin>>n>>m; 
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b;
        adjList[a-1].push_back(b-1);
        adjList[b-1].push_back(a-1);
    }
    messageRoute(adjList, n);
	return 0;
}