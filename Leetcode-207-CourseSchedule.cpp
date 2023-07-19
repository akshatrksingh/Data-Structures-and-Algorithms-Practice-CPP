 /* The problem wants us to check if we can topologically sort the graph
    That is possible iff the graph has no cycles in the DAG
    We can detect cycles using DFS or BFS 
    Here, we are using DFS to detect cycle */
class Solution 
{
    public:
    
        vector<bool> vis;
        vector<bool> currPath;
    
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
            currPath[src] = false;
            return false;
        }
    
        bool canFinish(int numCourses, vector<vector<int>> &prerequisites) 
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
                if(!vis[i] && isCyclicRecursion(i, adjList))
                {
                    return false;
                }
            }
            return true;
        }
};
