/*
//BFS
class Solution 
{
    public:
        vector<vector<int>> findFarmland(vector<vector<int>>& land) 
        {
            int nrow = land.size();
            int ncol = land[0].size();
            vector<vector<int>> res;
            
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (int i = 0; i < nrow; i++) 
            {
                for (int j = 0; j < ncol; j++) 
                {
                    vector<int> temp(4);
                    if (land[i][j] == 1) 
                    {
                        temp = {i, j, i, j};
                        land[i][j] = 2;

                        queue<pair<int, int>> q;
                        q.push({i, j});

                        while (!q.empty()) 
                        {
                            int currRow = q.front().first;
                            int currCol = q.front().second;
                            q.pop();

                            for (auto dir : directions) 
                            {
                                int newRow = currRow + dir.first;
                                int newCol = currCol + dir.second;

                                if (newRow >= 0 && newRow < nrow && newCol >= 0 && newCol < ncol && land[newRow][newCol] == 1) 
                                {
                                    q.push({newRow, newCol});
                                    land[newRow][newCol] = 2;
                                    temp[2] = max(temp[2], newRow);
                                    temp[3] = max(temp[3], newCol);
                                }
                            }
                        }
                        res.push_back(temp);
                    }
                }
            }
            return res;
        }
};
*/
// DFS
class Solution 
{
    public:
    
        void dfsRecursion(vector<vector<int>>& land, int i, int j, int nrow, int ncol, vector<int>& temp)
        {
            if (i >= 0 && i < nrow && j >= 0 && j < ncol && land[i][j] == 1) 
            {
                land[i][j] = 2;  
                dfsRecursion(land, i + 1, j, nrow, ncol, temp);     
                dfsRecursion(land, i - 1, j, nrow, ncol, temp);     
                dfsRecursion(land, i, j + 1, nrow, ncol, temp);     
                dfsRecursion(land, i, j - 1, nrow, ncol, temp);
                temp[2] = max(temp[2], i);
                temp[3] = max(temp[3], j);
            }
        }
        
        vector<vector<int>> findFarmland(vector<vector<int>>& land) 
        {
            int nrow = land.size();
            int ncol = land[0].size();
            vector<vector<int>> res;
            for(int i = 0; i < nrow; i++)
            {
                for(int j = 0; j < ncol; j++)
                {
                    vector<int> temp(4);
                    if(land[i][j] == 1)
                    {
                        land[i][j] = 2;
                        temp = {i, j, i, j};
                        dfsRecursion(land, i + 1, j, nrow, ncol, temp);
                        dfsRecursion(land, i, j + 1, nrow, ncol, temp);
                        dfsRecursion(land, i - 1, j, nrow, ncol, temp);
                        dfsRecursion(land, i, j - 1, nrow, ncol, temp);
                        res.push_back(temp);
                    }
                }
            }
            return res;
        }
};
