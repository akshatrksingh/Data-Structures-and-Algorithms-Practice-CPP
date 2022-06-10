class Solution 
{
    public:
        void floodFillRecursion(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor) 
        {
            int R = image.size();
            int C = image[0].size();
            if(sr >= 0 && sc >= 0 && sr < R && sc < C && image[sr][sc] == oldColor) 
            {
                image[sr][sc] = newColor;
                floodFillRecursion(image, sr, sc+1, oldColor, newColor);
                floodFillRecursion(image, sr, sc-1, oldColor, newColor);
                floodFillRecursion(image, sr+1, sc, oldColor, newColor);
                floodFillRecursion(image, sr-1, sc, oldColor, newColor);
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) 
        {
            int oldColor = image[sr][sc];
            if(oldColor == newColor) return image;
            floodFillRecursion(image, sr, sc, oldColor, newColor);
            return image;
        }
};
