class Solution 
{
    public:
        int snakesAndLadders(vector<vector<int>>& board) 
        {
            int n = board.size();
            int target = n * n;

            // Convert the board into a 1D array for easier indexing
            vector<int> flatBoard(target + 1);
            int idx = 1;
            bool reverse = false;
            for (int i = n - 1; i >= 0; i--) 
            {
                if (!reverse) 
                {
                    for (int j = 0; j < n; j++) 
                    {
                        flatBoard[idx++] = board[i][j];
                    }
                } 
                else 
                {
                    for (int j = n - 1; j >= 0; j--) 
                    {
                        flatBoard[idx++] = board[i][j];
                    }
                }
                reverse = !reverse;
            }

            // Perform BFS
            queue<int> q;
            vector<int> distance(target + 1, INT_MAX);
            distance[1] = 0;
            q.push(1);

            while (!q.empty()) 
            {
                int curr = q.front();
                q.pop();

                if (curr == target) 
                {
                    return distance[curr];
                }

                for (int i = 1; i <= 6; i++) 
                {
                    int next = curr + i;

                    if (next > target) 
                    {
                        break;
                    }

                    if (flatBoard[next] != -1)
                    {
                        next = flatBoard[next];
                    }

                    if (distance[next] == INT_MAX) 
                    {
                        distance[next] = distance[curr] + 1;
                        q.push(next);
                    }
                }
            }

            return -1;  // The destination square cannot be reached
        }
};
