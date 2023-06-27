class Solution 
{
    public:
        int hIndex(vector<int>& c) 
        {
            int n = c.size(), h = 0;
            sort(c.begin(), c.end(), greater<int>());
            for(int i = 0; i < n; i++)
            {
                if(c[i] >= i+1) 
                {
                     h = i+1;
                }
            }
            return h;
        }
};
