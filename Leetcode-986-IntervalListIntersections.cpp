class Solution 
{
    public:
        vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)         
        {
            vector<vector<int>> intersection;                         // SC: O(M+N)
            int p1 = 0, p2 = 0;
            while(p1 < firstList.size() && p2 < secondList.size())    // TC: O(M+N)       
            {
                if(firstList[p1][0] <= secondList[p2][1] && secondList[p2][0] <= firstList[p1][1])        // overlapping - start of each list should be lesser than end of the other list
                {
                    intersection.push_back({max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])});
                }
                if(firstList[p1][1] > secondList[p2][1])              // Remove the interval with the smallest endpoint
                {
                    p2++;
                }
                else
                {
                    p1++;
                }
            }
            return intersection;
        }
};
