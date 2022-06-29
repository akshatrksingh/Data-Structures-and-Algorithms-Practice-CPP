/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution 
{
    public:
        /**
        * @param intervals: an array of meeting time intervals
        * @return: the minimum number of conference rooms required
        */
        int minMeetingRooms(vector<Interval> &intervals) 
        {
            vector<int> start;                             // SC: O(n)
            vector<int> end;
            for (int i = 0; i < intervals.size(); i++)
            {
                start.push_back(intervals[i].start);
                end.push_back(intervals[i].end);
            }
            sort(start.begin(), start.end());
            sort(end.begin(), end.end());                  // TC: O(n log n)
            int i = 0, j = 0, curr = 0;
            int rooms = 1;
            while(i < start.size() && j < end.size())
            {
                if(start[i] < end[j])
                {
                    curr++;
                    i++;
                }
                else
                {
                    curr--;
                    j++;
                }
                rooms = max(rooms, curr);
            }
            return rooms;
        }
};
