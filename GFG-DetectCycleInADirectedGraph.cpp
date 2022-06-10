class Solution 
{
  public:
    bool isCyclicRecursion(int src, bool vis[],  bool currPath[], vector<int> adj[])
    {
        vis[src] = true;
        currPath[src] = true;
        for(auto nbr: adj[src])
		{
		    if(currPath[nbr])
		    {
		        return true;
		    }
		    if(!vis[nbr])
		    {
		        if(isCyclicRecursion(nbr, vis, currPath, adj))
		        {
		            return true;
		        }
		 	}
		 }
		 currPath[src] = false;
		 return false;
    }
    
    bool isCyclic(int V, vector<int> adj[]) 
    {
        bool *vis = new bool[V];          // if you take map here it results in TLE
        bool *currPath = new bool[V];     // if you take map here it results in TLE
        for(int i = 0; i < V; i++)
        {
            vis[i] = false;
            currPath[i] = false;
        }
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && isCyclicRecursion(i, vis, currPath, adj))
            {
                return true;
            }
        }
        return false;
    }
};
