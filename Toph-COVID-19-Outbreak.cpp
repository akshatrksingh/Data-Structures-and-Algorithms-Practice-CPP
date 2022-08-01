#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long, long> pll;

vector<vector<pll>> adjList(1000005);
vector<ll> trucks(1000005);

ll dfs(ll src, ll par)
{
    ll cnt = trucks[src];
    for(auto to: adjList[src])
    {
        ll node = to.first;
        ll capacity = to.second;
        if(node != par)
        {
            ll t = dfs(node, src);
            cnt += min(capacity, t);
        }
    }
    return cnt;
}

int main() 
{
	ll N, Z;
    cin>>N>>Z;
    adjList.resize(N+1);
    trucks.resize(N+1);
    int U, V, Y;
    for(ll i = 0; i < N-1; i++)
    {
        cin>>U>>V>>Y;
        adjList[U].push_back({V, Y});
        adjList[V].push_back({U, Y});
    }
    for(ll i = 1; i <= N; i++)
    {
        cin>>trucks[i];
    }
    cout<<dfs(Z, Z);
    return 0;
}
