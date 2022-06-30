class Solution
{
    public:
        static bool cmp(vector<int> i1, vector<int> i2)
        {
            return i1[0] < i2[0];
        }
        int eraseOverlapIntervals(vector<vector<int>>& intervals)
        {
            if(intervals.size() < 2)
            {
                return 0;
            }
            sort(intervals.begin(), intervals.end());                       // TC: O(n log n)
            int prevEnd = intervals[0][1];
            int num = 0;
            for(int i = 1; i < intervals.size(); i++)
            {
                if(prevEnd <= intervals[i][0])
                {
                    prevEnd = intervals[i][1];
                }
                else if(prevEnd > intervals[i][0])
                {
                    prevEnd = min(prevEnd, intervals[i][1]);
                    num++;
                }
            }
            return num;
        }
};
