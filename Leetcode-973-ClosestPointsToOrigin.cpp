class Solution 
{
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
        {
            priority_queue<pair<int, vector<int>>> maxHeap;
            for(int i = 0; i < points.size(); i++)
            {
                maxHeap.push({points[i][0]*points[i][0] + points[i][1]*points[i][1], {points[i][0], points[i][1]}});
                if(maxHeap.size() > k)
                    maxHeap.pop();
            }
            vector<vector<int>> ans;
            while(maxHeap.size() > 0)
            {
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
            return ans;
        }
};
