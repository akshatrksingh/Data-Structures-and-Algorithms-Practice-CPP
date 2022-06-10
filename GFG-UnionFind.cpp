class Solution
{
    public:
    
    int find_set(int v, int parent[])    
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v], parent);
    }
    
    void union_( int a, int b, int parent[], int rank[]) 
    {
        int s1 = find_set(a, parent);
        int s2 = find_set(b, parent);
    
        if (s1 != s2) 
        {
            if(rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }   
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
    
    bool isConnected(int x,int y, int parent[], int rank[])
    {
        return find_set(x, parent) == find_set(y, parent);
    }
};
