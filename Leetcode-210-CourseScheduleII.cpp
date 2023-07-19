class Solution 
{
    public:
        
        vector<bool> vis;
        vector<bool> currPath;
        list<int> ordering;
    
        bool isCyclicRecursion(int src, vector<int> adj[])
        {
            vis[src] = true;
            currPath[src] = true;
            for(auto nbr: adj[src])
            {
                if(currPath[nbr])
                {
                    return true;
                }
                if(!vis[nbr])
                {
                    if(isCyclicRecursion(nbr, adj))
                    {
                        return true;
                    }
                }
            }
            ordering.push_front(src);
            currPath[src] = false;
            return false;
        }
    
        vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) 
        {
            //Convert the given edge list to adjacency list
            vector<int> adjList[numCourses];
            for(auto edge: prerequisites)
            {
                adjList[edge[1]].push_back(edge[0]);
            }
            
            vis.assign(numCourses, false);
            currPath.assign(numCourses, false); 
            
            for(int i = 0; i < numCourses; i++)
            {
                vis[i] = false;
                currPath[i] = false;
            }
            for(int i = 0; i < numCourses; i++)
            {
                if(!vis[i] && isCyclicRecursion(i, adjList))
                {
                    return {};
                }
            }
            vector<int> v(ordering.begin(), ordering.end());
            return v;
        }
};
