class Solution 
{
    public:
        vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) 
        { 
            vector<vector<int>> res;
            for(int i = 0; i < intervals.size(); i++)
            {
                if(newInterval[0] <= intervals[i][1] && intervals[i][0] <= newInterval[1])  // overlapping - start of each list should be <= end of the other list
                {
                    newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
                }
                else if(newInterval[0] > intervals[i][1])
                {
                    res.push_back(intervals[i]);
                }
                else if(intervals[i][0] > newInterval[1])
                {
                    res.push_back(newInterval);
                    while(i < intervals.size())
                    {
                        res.push_back(intervals[i]);
                        i++;
                    }
                    return res;
                }
            }
            res.push_back(newInterval);
            return res;
        }
};
