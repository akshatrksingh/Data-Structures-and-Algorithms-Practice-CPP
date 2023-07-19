class Solution 
{
    public:
        bool isBipartite(vector<vector<int>>& adjList) 
        {
            int V = adjList.size();
            vector<int> color(V, INT_MAX); // unvisited
            queue<int> q;
            for(int i = 0; i < V; i++)     // in case disconnected graph
            {
                if(color[i] != INT_MAX)
                {
                    continue;
                }
                color[i] = 0;
                q.push(i);
                while(q.size())
                {
                    int f = q.front();
                    q.pop();
                    for(int nbr: adjList[f])
                    {
                        if(color[nbr] == INT_MAX)
                        {
                            color[nbr] = 1 - color[f];
                            q.push(nbr);
                        }
                        else if(color[nbr] == color[f])
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
};
