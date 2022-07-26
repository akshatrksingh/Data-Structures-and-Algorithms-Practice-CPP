// Cycle detection and cycle retrieval
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adjList(100000);
vector<int> vis;
vector<int> parent;
int cycle_start, cycle_end;

bool roundTripRecursion(int src, int par, vector<vector<int>> &adjList)
{
    vis[src] = true;
    for(auto nbr: adjList[src])
	{
	    if(nbr == par) 
		{   
	        continue; 
	    }
        if(vis[nbr]) 
        {
            cycle_end = src;
            cycle_start = nbr;
            return true;
        }
        parent[nbr] = src;
        if (roundTripRecursion(nbr, parent[nbr], adjList))
        {
            return true;
        }
    }
	return false;
}

void printCycle()
{
    vector<int> cycle;
    cycle.push_back(cycle_start);
    for(int v = cycle_end; v != cycle_start; v = parent[v])
    {
        cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());

    cout<<cycle.size()<<endl;
    for(auto v : cycle)
    {
        cout<<v+1<<" ";
    }
    cout<<endl;
}

void roundTrip(vector<vector<int>> &adjList, int V)
{
    vis.assign(V, false);
    parent.assign(V, -1);
    for(int i = 0; i < V; i++)
    {
        if(!vis[i] && roundTripRecursion(i, parent[i], adjList))
        {
           printCycle();
           return;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
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
    roundTrip(adjList, n);
	return 0;
}