class Solution 
{
    public:
        int liveNeighbours(vector<vector<int>> &board, int i, int j, int r, int c)
        {
            int cnt = 0;
            if(i-1 >= 0 && board[i-1][j] == 1)
                cnt++;
            if(j-1 >= 0 && board[i][j-1] == 1)
                cnt++;
            if(i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] == 1)
                cnt++;
            if(i+1 < r && board[i+1][j] == 1)
                cnt++;
            if(j+1 < c && board[i][j+1] == 1)
                cnt++;
            if(i+1 < r && j+1 < c && board[i+1][j+1] == 1)
                cnt++;
            if(i-1 >= 0 && j+1 < c && board[i-1][j+1] == 1)
                cnt++;
            if(i+1 < r && j-1 >= 0 && board[i+1][j-1] == 1)
                cnt++;
            return cnt;
        }
        void gameOfLife(vector<vector<int>> &board) 
        {
            vector<vector<int>> copy = board;
            int r = board.size(), c = board[0].size();
            for(int i = 0; i < r; i++)
            {
                for(int j = 0; j < c; j++)
                {
                    int ln = liveNeighbours(copy, i, j, r, c);
                    if(board[i][j] == 0 && ln == 3)
                        board[i][j] = 1;
                    else if(board[i][j] == 1 && (ln < 2 || ln > 3))
                        board[i][j] = 0;
                }
            }
        }
};
