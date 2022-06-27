class Solution 
{
    public:
	int minStepToReachTarget(vector<int> &KnightPos, vector<int>&TargetPos, int N)
	{
	    // Adjust to 0-based indexing
	    KnightPos[0]--;
	    KnightPos[1]--;
	    TargetPos[0]--;
	    TargetPos[1]--;
	    
	    bool vis[N][N];
        queue<vector<int>> q;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                vis[i][j] = false;
            }
        }
        
        q.push({KnightPos[0], KnightPos[1], 0});
        vis[KnightPos[0]][KnightPos[1]] = true;
      
        int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};
        int x, y;
        
        while (!q.empty()) 
        {
            auto t = q.front();
            q.pop();
      
            if(t[0] == TargetPos[0] && t[1] == TargetPos[1])
            {
                return t[2];
            }
            
            // For every reachable position from the current position
            for (int i = 0; i < 8; i++) 
            {
                x = t[0] + dx[i];
                y = t[1] + dy[i];
     
                // If reachable position is not yet visited and is inside board, push that position into queue
                if (x >= 0 && x < N && y >= 0 && y < N && !vis[x][y]) 
                {
                    vis[x][y] = true;
                    q.push({x, y, t[2] + 1});
                }
            }
        }
	}
};
