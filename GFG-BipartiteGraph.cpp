class Solution 
{
    public:
        //Here, we are using modified BFS although DFS can be modified to be used too
    	bool isBipartite(int V, vector<int> adj[])
    	{
            vector<int> colour(V, INT_MAX);   // unvisited
            queue<int> q;
            for(int i = 0; i < V; i++)        // in case disconnected graph
            {
                if(colour[i] != INT_MAX) continue;
                colour[i] = 0;
                q.push(i);
                while(!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    
                    for(auto nbr: adj[v])
                    {
                        if(colour[nbr] == INT_MAX)
                        {
                            colour[nbr] = 1 - colour[v];      // instead of recording distance we just record two colors {0, 1}
                            q.push(nbr);
                        }
                        else if(colour[nbr] == colour[v])     // coloring conflict
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
    	}
};
