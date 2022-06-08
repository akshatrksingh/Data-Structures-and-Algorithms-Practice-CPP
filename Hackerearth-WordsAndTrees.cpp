#include<bits/stdc++.h>
using namespace std;

char val[100005];
int subtree[100005][26];
map<int, list<int>> l; 

void dfsRecursion(int src, map<int, bool> &vis)
{
	vis[src] = true;
	for(auto nbr: l[src])
	{
		if(!vis[nbr])
		{
			dfsRecursion(nbr, vis);
			for(int i = 0; i < 26; i++)
			{
				subtree[src][i] += subtree[nbr][i];
			}
		}
		
	}
	subtree[src][val[src]-'a']++;
}

void dfs(int src)
{
	map<int, bool> vis;
    for(auto a: l)
    {
        vis[a.first] = false;
    }
	dfsRecursion(src, vis);
}

int main()
{
	int n, q;
	cin>>n;
	cin>>q;
	for(int i = 1; i <= n; i++)
	{
		cin>>val[i];
	}
	for(int i = 1; i <= n-1; i++)
	{
		int x,y;
		cin>>x>>y;
		l[x].push_back(y);
		l[y].push_back(x);
	}
	dfs(1);
	while(q--)
	{
		int node;
		string s;
		cin>>node;
		cin>>s;
		int f[26] = {0};
		int ans = 0;
		for(int i = 0; i < s.size(); i++)
		{
			f[s[i]-'a']++;
		}
		for(int i = 0; i < 26; i++)
		{
			ans += max(0, f[i]-subtree[node][i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}