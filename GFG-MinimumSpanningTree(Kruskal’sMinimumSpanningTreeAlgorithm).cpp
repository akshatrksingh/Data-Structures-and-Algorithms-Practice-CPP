//cp-algorithms.com/graph/mst_kruskal_with_dsu.html
class Solution
{
	public:
	vector<int> parent, rank;
	struct Edge 
	{
        int u, v, weight;
        Edge(int u, int v, int weight)
        {
            this->u = u;
            this->v = v;
            this->weight = weight;
        }
        bool operator<(Edge const& other) 
        {
            return weight < other.weight;
        }
    };
    void make_set(int v) 
    {
        parent[v] = v;
        rank[v] = 0;
    }
    int find_set(int v) 
    {
        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b) 
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b) 
        {
            if (rank[a] < rank[b])
            {
                swap(a, b);
            }
            parent[b] = a;
            if (rank[a] == rank[b])
            {
                rank[a]++;
            }
        }
    }
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<Edge> edgelist;
        int ans = 0;
        parent.resize(V);
        rank.resize(V);
        for (int i = 0; i < V; i++)
        {
            make_set(i);
        }
        for(int i = 0; i < V; i++)
        {
           for(auto j : adj[i])
           {
               edgelist.push_back(Edge(i, j[0], j[1]));
           }
        }
        sort(edgelist.begin(), edgelist.end());
        for (auto edge : edgelist) 
        {
            if (find_set(edge.u) != find_set(edge.v)) 
            {
                union_sets(edge.u, edge.v);
                ans += edge.weight;
            }
        }
        return ans;
    }
};
