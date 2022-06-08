class Solution 
{
  public:
    vector<vector<int>> printGraph(int V, vector<int> adj[]) 
    {
        vector<int> w;
        vector<vector<int>> v;
        for(int i = 0; i < V; i++)
        {
          w.push_back(i);
          for(int n: adj[i])
          {
            w.push_back(n);
          }
          v.push_back(w);
          w.clear();
        }
        return v;
    }
};
