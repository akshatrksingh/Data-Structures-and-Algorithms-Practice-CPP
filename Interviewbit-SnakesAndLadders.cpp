class Solution 
{
public:
    pair<int, int> getCoordinate(int curr, int n) 
    {
        int r = (curr-1)/n;
        int c = (curr-1)%n;
        if(r%2) 
        {
            c = (n-1)-c;
        }
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int next, row, col;
        queue<int> q;
        map<int, int> dist;
        int n = board.size();
        reverse(board.begin(), board.end());
        q.push(1);
		dist[1] = 0;
        for(int i = 2; i <= n*n; i++)
        {
            dist[i] = INT_MAX;
        }
        while(!q.empty()) 
        {
            int curr = q.front();
			q.pop();
            for(int i = 1; i <= 6; i++)
            {
                auto [row, col] =getCoordinate(curr+i, n);
                next = (board[row][col] == -1)?(curr+i):board[row][col];
                if(next == n*n)
                {
                    return dist[curr]+1;
                }
                if(dist[next] == INT_MAX)
                {
                    q.push(next);
                    dist[next] = dist[curr]+1;
                }
            }
        }
        return -1;
    }
};
