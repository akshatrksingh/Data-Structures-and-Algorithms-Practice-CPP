class Solution 
{
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) 
        {
            vector<vector<int>> merged;                                     // SC: O(n)
            sort(intervals.begin(), intervals.end());                       // TC: O(n log n)
            for(auto interval: intervals)
            {
                if(merged.empty() || merged.back()[1] < interval[0])        // non-overlapping
                {
                    merged.push_back(interval);
                }
                else
                {
                    merged.back()[1] = max(merged.back()[1], interval[1]);   // merging the overlapping intervals
                }
            }
            return merged;
        }
};
