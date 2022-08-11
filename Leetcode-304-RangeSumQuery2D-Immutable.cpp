class NumMatrix 
{
    public:
        vector<vector<int>> prefSum;
        NumMatrix(vector<vector<int>> &matrix) 
        {
            int r = matrix.size(), c = matrix[0].size();
            prefSum.clear();
            prefSum.resize(r+1, vector<int>(c+1));
            for(int i = 0; i <= r; i++)
            {
                prefSum[i][0] = 0;
            }
            for(int j = 0; j <= c; j++)
            {
                prefSum[0][j] = 0;
            }
            for(int i = 1; i <= r; i++)
            {
                for(int j = 1; j <= c; j++)
                {
                    prefSum[i][j] = matrix[i-1][j-1] + prefSum[i][j-1] + prefSum[i-1][j] - prefSum[i-1][j-1];
                }
            }
        }

        int sumRegion(int row1, int col1, int row2, int col2) 
        {
            return prefSum[row2+1][col2+1] - prefSum[row1][col2+1] - prefSum[row2+1][col1] + prefSum[row1][col1];
        }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
