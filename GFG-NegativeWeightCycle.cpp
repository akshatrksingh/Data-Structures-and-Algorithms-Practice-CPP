class Solution 
{
    public:
    	int isNegativeWeightCycle(int V, vector<vector<int>> edgeList)
    	{
    	   const int INF = 1e8; // INF = 100M, not 2^31-1 to avoid overflow
           vector<int> dist(V, INF);
           dist[0] = 0;
           for(int i = 0; i < V-1; i++)
           {
               for(auto edge: edgeList)        // edge: {u, v, weight}
               {
                   dist[edge[1]] = min(dist[edge[1]], dist[edge[0]]+edge[2]); 
               }
           }
           //above part is Bellman Ford algorithm
           
           int hasNegativeCycle = 0;
           for(int i = 0; i < V-1; i++)
           {
               for(auto edge: edgeList)        // edge: {u, v, weight}
               {
                   if(dist[edge[1]] > dist[edge[0]]+edge[2])
                   {
                       hasNegativeCycle = 1;
                   }
               }
           }
           return hasNegativeCycle;
    	}
};
