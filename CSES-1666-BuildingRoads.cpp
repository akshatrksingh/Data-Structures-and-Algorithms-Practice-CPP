#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>>adjList(100000);

void buildingRoadsRecursion(vector<vector<int>> &adjList, int src, int V)
{
    vis[src] = 1;
    for (auto i: adjList[src]) 
    {
        if (!vis[i]) 
        {
            buildingRoadsRecursion(adjList, i, V);
        }
    }
}

void buildingRoads(vector<vector<int>> &adjList, int V)
{
    int numCC = 0;  // number of connected components in an undirected graph
    vis.assign(V, 0); // assign 0 for univisted and 1 for visited
    vector<int> v;  
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            v.push_back(i);
            buildingRoadsRecursion(adjList, i, V);
        }
    }
    int numRoads = v.size()-1; // v.size() is the number of connected components
    cout<<numRoads<<endl;
    for(int i = 0; i < numRoads; i++)
    {
        cout<<v[i]+1<<" "<<v[i+1]+1<<endl;
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
    buildingRoads(adjList, n);
	return 0;
}