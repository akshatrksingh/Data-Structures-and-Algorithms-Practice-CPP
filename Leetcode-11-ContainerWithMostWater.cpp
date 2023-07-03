/*

// TLE
class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int n = height.size(), water = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    water = max(water, (j-i)*min(height[i], height[j]));
                }
            }
            return water;
        }
};

*/

class Solution 
{
    public:
        int maxArea(vector<int>& height) 
        {
            int n = height.size(), water = 0;
            int p1 = 0, p2 = n-1;
            while(p1 < p2)
            {
                water = max(water, (p2-p1)*min(height[p1], height[p2]));
                if(height[p1] < height[p2])
                {
                    p1++;
                }
                else
                {
                    p2--;
                }
            }
            return water;
        }
};
