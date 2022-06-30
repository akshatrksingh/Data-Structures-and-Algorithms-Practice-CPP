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
        * @return: if a person could attend all meetings
        */
        static bool cmp(Interval i1, Interval i2)
        {
            return i1.start < i2.start;
        }
        bool canAttendMeetings(vector<Interval> &intervals) 
        {
            if(intervals.size() == 0) 
            {
                return true;
            }
            sort(intervals.begin(), intervals.end(), cmp);                       // TC: O(n log n)
            for(int i = 0; i < intervals.size()-1; i++)
            {
                if(intervals[i].end > intervals[i+1].start)                      // overlapping
                {
                    return false;
                }
            }
            return true;
        }
};
