class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
       const int INF = 1e9; // INF = 1B, not 2^31-1 to avoid overflow
       vector<int> dist(V, INF);
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // min heap
       dist[src] = 0;
       q.push({0, src});     // {distance, node}      
       while(!q.empty())
       {
           auto best = q.top();   
           q.pop();
           int u = best.second;
           for(auto x: adj[u]) 
           {
               int v = x[0];
               int weight = x[1];
               if(dist[v] > dist[u] + weight)
               {
                    dist[v] = dist[u] + weight;     // relax operation
                    q.push({dist[v], v});           // enqueue better pair
                }
           }
       }
       return dist;
    }
};
