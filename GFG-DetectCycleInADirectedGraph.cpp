class Solution 
{
  public:
  
    vector<int> colour;
    vector<int> parent;
    int cycle_start, cycle_end;
    
    bool isCyclicRecursion(int src, vector<int> adjList[])
    {
        colour[src] = 1;                // mark visited
        for(auto nbr: adjList[src])
		{
		    if (colour[nbr] == 0)          // check if unvisited
		    {
                parent[nbr] = src;
                if (isCyclicRecursion(nbr, adjList))
                {
                    return true;
                }
            } 
            else if (colour[nbr] == 1)      // check if visited
            {
                cycle_end = src;
                cycle_start = nbr;
                return true;
            }
		}
		colour[src] = 2;                 // mark exited
		return false;
    }
    bool isCyclic(int V, vector<int> adjList[]) 
    {
        colour.assign(V, 0);   // Mark colours from {0, 1, 2} according to unvisited, visited, and exited accordingly
        parent.assign(V, -1);
        for(int i = 0; i < V; i++)
        {
            if(colour[i] == 0 && isCyclicRecursion(i, adjList))
            {
                return true;
            }
        }
        return false;
    }
};
