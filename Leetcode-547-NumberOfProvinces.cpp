class Solution 
{
    public:
        vector<int> vis;
        void dfsRecursion(int src, vector<vector<int>> adj)
        {
            vis[src] = 1;
            for (int i = 0; i < adj[src].size(); i++) 
            {
                if (adj[src][i] == 1 && !vis[i]) 
                {
                    dfsRecursion(i, adj);
                }
            }
        }
        int findCircleNum(vector<vector<int>>& isConnected) 
        {
            int V = isConnected.size();
            int numCC = 0;  // number of connected components in an undirected graph
            vis.assign(V, 0); // assign 0 for univisted and 1 for visited
            for(int i = 0; i < V; i++)
            {
                if(!vis[i])
                {
                    numCC++;
                    dfsRecursion(i, isConnected);
                }
            }
            return numCC;
        }
    };
