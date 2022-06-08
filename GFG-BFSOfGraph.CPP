class Solution 
{
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        vector<int> bfs;
        int src = 0, i = 0;
        map<int, bool> vis;
        queue<int> q;
        while(V--)
        {
            vis[i++] = false;
        }
        q.push(src);
        vis[src] = true;
        
        while(!q.empty())
        {
            int v = q.front();
            q.pop();
            bfs.push_back(v);
            for(auto nbr: adj[v])
            {
                if(!vis[nbr])
                {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
        return bfs;
    }
};
