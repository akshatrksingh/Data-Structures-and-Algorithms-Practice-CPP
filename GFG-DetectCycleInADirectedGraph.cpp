class Solution 
{
  public:
    
    vector<bool> vis;
    vector<bool> currPath;

    bool isCyclicRecursion(int src, vector<int> adjList[])
    {
        vis[src] = true;
        currPath[src] = true;
        for(auto nbr: adjList[src])
		{
		    if(currPath[nbr])
		    {
		        return true;
		    }
		    if(!vis[nbr])
		    {
		        if(isCyclicRecursion(nbr, adjList))
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
        vis.assign(V, false);
        currPath.assign(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && isCyclicRecursion(i, adj))
            {
                return true;
            }
        }
        return false;
    }
};
