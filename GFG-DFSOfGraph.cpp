class Solution 
{
  public:
    vector<int> dfs;
    void dfsRecursion(int src, map<int, bool> &vis, vector<int> adj[])
	{
	     dfs.push_back(src);
		 vis[src] = true;
		 for(auto nbr: adj[src])
		 {
		 	if(!vis[nbr])
		 	{
		 		dfsRecursion(nbr, vis, adj);
		 	}
		 }
	}
    vector<int> dfsOfGraph(int V, vector<int> adj[]) 
    {
        int src = 0, i = 0;
        map<int, bool> vis;
        while(V--)
        {
        	vis[i++] = false;
        }
		dfsRecursion(src, vis, adj);
		return dfs;
    }
};
