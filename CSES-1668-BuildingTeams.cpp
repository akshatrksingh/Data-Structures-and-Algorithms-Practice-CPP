// Is the graph biparite? If yes, color them
#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<vector<int>>adjList(100000);

void buildingTeams(vector<vector<int>> &adjList, int V)
{
    const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow
    vector<int> colour(V, INF);
    queue<int> q; 

    for(int i = 0; i < V; i++) // in case disconnected graph
    {
        if(colour[i] != INF) 
            continue;
        colour[i] = 1;
        q.push(i);

        while(!q.empty())
        {
            int v = q.front();
            q.pop();

            for(auto nbr: adjList[v])
            {
                if(colour[nbr] == INF)
                {
                    colour[nbr] = (colour[v] == 1)? 2 : 1; // instead of recording distance we just record two colors {1, 2}
                    q.push(nbr);
                }
                else if(colour[nbr] == colour[v])
                {
                    cout<<"IMPOSSIBLE";
                    return;
                }
            }

        }
    } 
    for(auto c: colour)
    {
        cout<<c<<" ";
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
    buildingTeams(adjList, n);
	return 0;
}