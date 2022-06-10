class Solution
{
	public:
	    
    	void dfsRecursion(int src, map<int, bool> &vis, vector<int> adj[], list<int> &ordering)
    	{
    		 vis[src] = true;
    		 for(auto nbr: adj[src])
    		 {
    		 	if(!vis[nbr])
    		 	{
    		 		dfsRecursion(nbr, vis, adj, ordering);
    		 	}
    		 }
    		 ordering.push_front(src);
    	}
        void dfsOfGraph(int V, vector<int> adj[], list<int> &ordering) 
        {
            map<int, bool> vis;
            for(int i = 0; i < V; i++)
            {
            	vis[i] = false;
            }
            for(int i = 0; i < V; i++)
            {
                if(!vis[i])
                {
                    dfsRecursion(i, vis, adj, ordering);
                }
            }        
        }
    	vector<int> topoSort(int V, vector<int> adj[]) 
    	{
    	    list<int> ordering;
    	    dfsOfGraph(V, adj, ordering);
    	    vector<int> v{begin(ordering), end(ordering)};
    	    return v;
    	}
};
