class Solution 
{
  public:
  
    vector<bool> vis;
    vector<int> parent;
    int cycle_start, cycle_end;
    
    bool isCyclicRecursion(int src, int par, vector<int> adjList[])
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
            if (isCyclicRecursion(nbr, parent[nbr], adjList))
            {
                return true;
            }
		}
		return false;
    }
    bool isCycle(int V, vector<int> adjList[]) 
    {
        vis.assign(V, false);
        parent.assign(V, -1);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && isCyclicRecursion(i, parent[i], adjList))
            {
                return true;
            }
        }
        return false;
    }
};
