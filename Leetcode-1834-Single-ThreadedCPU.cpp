class Solution 
{
    public:

        struct T
        {
            int idx;
            int et;
            int pt;
        };

        static bool cmp(T a, T b)
        {
            return a.et < b.et;
        }

        vector<int> getOrder(vector<vector<int>> &tasks) 
        {
            vector<int> res;
            int n = tasks.size();
            vector<T> v;
            for(int i = 0; i < n; i++)
            {
                T t;
                t.idx = i;
                t.et = tasks[i][0];
                t.pt = tasks[i][1];
                v.push_back(t);
            }
            sort(v.begin(), v.end(), cmp);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
            int i = 0;
            long curr = 0;
            while(i < n || !minHeap.empty())
            {
                if(minHeap.empty() && curr < v[i].et)
                {
                    curr = v[i].et;
                }
                while(i < n && curr >= v[i].et)
                {
                    minHeap.push({v[i].pt, v[i].idx});
                    i++;
                }
                auto top = minHeap.top();
                minHeap.pop();
                curr += top.first;
                res.push_back(top.second);
            }
            return res;
        }
};
