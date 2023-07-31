class Solution
{
    public:
        vector<int> bellman_ford(int V, vector<vector<int>>& edgeList, int src)
        {
            const int INF = 1e8; 
            vector<int> dist(V, INF);
            dist[src] = 0;
            
            // Relax all edges V - 1 times
            for (int i = 0; i < V - 1; ++i)
            {
                for (const auto& edge : edgeList)
                {
                    int u = edge[0];
                    int v = edge[1];
                    int weight = edge[2];
                    
                    if (dist[u] + weight < dist[v])
                    {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
            
            // Check for negative cycles
            for (const auto& edge : edgeList)
            {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                if (dist[u] + weight < dist[v])
                {
                    // Negative cycle found, return -1
                    return {-1};
                }
            }
            
            return dist;
        }
};
