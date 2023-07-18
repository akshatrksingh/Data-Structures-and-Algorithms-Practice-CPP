class Solution 
{
  public:
  
    vector<bool> vis;
    // int cycle_start, cycle_end;
    
    bool isCyclicRecursion(int src, int par, vector<int> adjList[])
    {
        vis[src] = true;
        for(auto nbr: adjList[src])
		{
		    if(nbr == par) 
		    {   
		        continue; 
		    }
            if(vis[nbr] == 0) 
            {
                if (isCyclicRecursion(nbr, src, adjList))
                {
                    return true;
                }
            }
            else if(vis[nbr] == 1) 
            {
                // cycle_end = src;
                // cycle_start = nbr;
                return true;
            }
		}
		return false;
    }
    bool isCycle(int V, vector<int> adjList[]) 
    {
        vis.assign(V, false);
        for(int i = 0; i < V; i++)
        {
            if(!vis[i] && isCyclicRecursion(i, -1, adjList))
            {
                return true;
            }
        }
        return false;
    }
};
