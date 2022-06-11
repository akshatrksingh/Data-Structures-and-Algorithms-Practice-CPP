class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       vector<int> vis(V,0);
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q; // min heap
       int ans = 0;
       q.push({0,0});
       while(!q.empty())
       {
           auto best = q.top();   //edge with min weight
           q.pop();
           int to = best.second;
           int weight = best.first;
           if(vis[to]) 
           {
               continue;
           }
           ans += weight;
           vis[to]++;
           for(auto x: adj[to]) 
           {
               if(!vis[x[0]])
               {
                   q.push({x[1], x[0]});
               }
           }
       }
       return ans;
   }
};
