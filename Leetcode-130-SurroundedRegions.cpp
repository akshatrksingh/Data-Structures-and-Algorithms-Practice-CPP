class Solution 
{
    public:
        void solve(vector<vector<char>>& board) 
        {
            if (board.empty()) 
            {
                return;
            }

            int m = board.size();
            int n = board[0].size();

            // Mark 'O' cells on the borders and their connected cells as 'B'
            
            for (int i = 0; i < m; i++) 
            {
                if (board[i][0] == 'O') 
                {
                    markRegion(board, i, 0);
                }
                if (board[i][n - 1] == 'O') 
                {
                    markRegion(board, i, n - 1);
                }
            }

            for (int j = 0; j < n; j++) 
            {
                if (board[0][j] == 'O') 
                {
                    markRegion(board, 0, j);
                }
                if (board[m - 1][j] == 'O') 
                {
                    markRegion(board, m - 1, j);
                }
            }

            // Convert remaining 'O' cells (unmarked regions) to 'X' and restore 'B' cells to 'O'
            for (int i = 0; i < m; i++) 
            {
                for (int j = 0; j < n; j++) 
                {
                    if (board[i][j] == 'O') 
                    {
                        board[i][j] = 'X';
                    } 
                    else if (board[i][j] == 'B') 
                    {
                        board[i][j] = 'O';
                    }
                }
            }
        }

        void markRegion(vector<vector<char>>& board, int row, int col) 
        {
            int m = board.size();
            int n = board[0].size();

            if (row >= 0 && row < m && col >= 0 && col < n && board[row][col] == 'O') 
            {

                board[row][col] = 'B';  
                markRegion(board, row - 1, col);  
                markRegion(board, row + 1, col);  
                markRegion(board, row, col - 1);  
                markRegion(board, row, col + 1);  
            }
        }
};
