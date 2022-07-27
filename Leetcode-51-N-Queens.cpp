class Solution 
{
    public:
    
        vector<vector<string>> ans;
    
        bool isSafe(int row, int col, vector<string> &board, int n)
        {
            for(int j = 0; j < col; j++)                             // check this row on left side
            {
                if(board[row][j] == 'Q')
                {
                    return false;
                }
            }
            
            for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)   // check upper diagonal on left side
            {
                if (board[i][j] == 'Q')
                {
                    return false;
                }
            }
            
            for(int i = row, j = col; i < n && j >= 0; i++, j--)   // check lower diagonal on left side
            {
                if (board[i][j] == 'Q')
                {
                    return false;
                }
            }
            
            return true;
        }
    
        void backtrack(int col, vector<string> &board, int n)
        {
            if(col == n)
            {
                ans.push_back(board);
                return;
            }
            for(int row = 0; row < n; row++)
            {
                if(isSafe(row, col, board, n))
                {
                    board[row][col] = 'Q';
                    backtrack(col+1, board, n);
                    board[row][col] = '.';
                }
            }
        }
        
        vector<vector<string>> solveNQueens(int n) 
        {
            vector<string> board(n);
            string s(n, '.');
            for(int i = 0; i < n; i++)
            {
                board[i] = s;
            }
            backtrack(0, board, n);
            return ans;
        }
};
