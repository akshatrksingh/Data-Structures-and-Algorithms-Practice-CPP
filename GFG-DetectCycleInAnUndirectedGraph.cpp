class Solution 
{
  public:
    bool isCyclicRecursion(int src, bool vis[],  int parent, vector<int> adj[])
    {
        vis[src] = true;
        for(auto nbr: adj[src])
		{
		    if(!vis[nbr])
		    {
		        if(isCyclicRecursion(nbr, vis, src, adj))
		        {
		            return true;
		        }
		     }
		    else if(nbr != parent)
		    {
	            return true;
	        }
		 	
		}
		return false;
    }
    bool isCycle(int V, vector<int> adj[]) 
    {
        
        bool *vis = new bool[V];         
        for(int i = 0; i < V; i++)
        {
            vis[i] = false;
        }
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && isCyclicRecursion(i, vis, -1, adj))
            {
                return true;
            }
        }
        return false;
    }
};
