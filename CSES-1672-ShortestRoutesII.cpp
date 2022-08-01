#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const long long INF = 1e17;
vector<vector<ll>> adjMatrix;
ll n, m;

void floydWarshall()
{
	for(int k = 1; k <= n; k++)
	{
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= n; j++)
	        {
	            adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k]+adjMatrix[k][j]);
	        }
	    }
	}
}
 
int main()
{
    int q;
    cin>>n>>m>>q; 
    adjMatrix.resize(n+1);

	for(int i = 0; i <= n; ++i)
	{
		adjMatrix[i].resize(n+1);
	}

    for(int i = 1; i <= n; ++i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			adjMatrix[i][j] = adjMatrix[j][i] = INF;
		}
	}

    ll a, b, c;
    for(int i = 0; i < m; i++)
    {
        cin>>a>>b>>c;
        adjMatrix[a][b] = adjMatrix[b][a] = min(c, adjMatrix[a][b]);
    }

    floydWarshall();
    
    for(int i = 0; i < q; ++i)
	{
		cin>>a>>b;
		if(adjMatrix[a][b] == INF) 
		{
            adjMatrix[a][b] = -1;
        }
		cout<<adjMatrix[a][b]<<"\n";
	}

	return 0;
}