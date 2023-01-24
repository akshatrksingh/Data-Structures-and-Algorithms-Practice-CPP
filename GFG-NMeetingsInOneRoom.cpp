class Solution
{
    public:
    
        static bool cmp(pair<int, int> a, pair<int, int> b)
        {
            return a.second < b.second;
        }
    
        int maxMeetings(int start[], int end[], int n)
        {
           vector<pair<int, int>> v;
           for(int i = 0; i < n; i++)
           {
               v.push_back({start[i], end[i]});
           }
           sort(v.begin(), v.end(), cmp);
           int cnt = 1;
           for(int j = 1, i = 0; j < n; j++)
           {
               if(v[j].first > v[i].second)
               {
                   cnt++;
                   i = j;
               }
           }
           return cnt;
        }
};
