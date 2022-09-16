class Solution 
{
    public:
        vector<int> spiralOrder(vector<vector<int>> &matrix) 
        {
            int n = matrix.size();
            int m = matrix[0].size();
            int left = 0, right = m-1, bottom = n-1, top = 0;
            vector<int> res;
            string direction = "right";
            while(left <= right && top <= bottom)
            {
                if(direction == "right")
                {
                    for(int i = left; i <= right; i++) 
                    {
                        res.push_back(matrix[top][i]);
                        direction = "down";
                    }
                top++;
                }
                if(direction == "down")
                {
                    for(int i = top; i <= bottom; i++) 
                    {
                        res.push_back(matrix[i][right]);
                        direction = "left";
                    }
                right--;
                }
                if(direction == "left")
                {
                    for(int i = right; i >= left; i--) 
                    {
                        res.push_back(matrix[bottom][i]);
                        direction = "up";
                    }
                bottom--;
                }
                if(direction == "up")
                {
                    for(int i = bottom; i >= top; i--) 
                    {
                        res.push_back(matrix[i][left]);
                        direction = "right";
                    }
                }
                left++;
            }
            return res;
        }
};
