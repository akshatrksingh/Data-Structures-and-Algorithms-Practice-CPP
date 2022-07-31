class Solution
{
    public:
        
        void solve(int a, int b, vector<vector<int>> &maze, int n, vector<string> &ans, vector<vector<bool>> &vis, string path)
        {
            if(a == n-1 && b == n-1)
            {
                ans.push_back(path);
                return;
            }
            
            //Not the typical x-y plane
            /*
            y - right
            x - down
            */
            // Right, Left, Down, Up
            int dx[] = {0, 0, 1, -1};
            int dy[] = {1, -1, 0, 0};
            string stepDir = "RLDU";  
            
            for(int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];
                if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !vis[x][y])
                {
                    vis[a][b] = true;
                    solve(x, y, maze, n, ans, vis, path+stepDir[i]);
                    vis[a][b] = false;
                }
            }
        }
        
        vector<string> findPath(vector<vector<int>> &maze, int n) 
        {
            vector<string> ans;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(maze[0][0] == 1)
                solve(0, 0, maze, n, ans, vis, "");
            return ans;
        }
};
