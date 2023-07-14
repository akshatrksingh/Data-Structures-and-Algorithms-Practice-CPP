#define PII pair<int, int>

class Compare
{
    public:
        bool operator()(PII &a, PII &b)
        {
            if (a.second == b.second)
            {
                return a.first < b.first;
            }
            else
            {
                return a.second > b.second;
            }
        }
};

class Solution
{
    public:
        int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
        {
            int n = profits.size();
            priority_queue<PII, vector<PII>, Compare> pq;    // inc capital
            for (int i = 0; i < n; i++)
            {
                pq.push({profits[i], capital[i]});
            }
            priority_queue<int> available;
            while (k--)
            {
                while (!pq.empty() && pq.top().second <= w)
                {
                    available.push(pq.top().first);
                    pq.pop();
                }
                if (available.empty())
                {
                    break; // No projects available
                }
                w += available.top();
                available.pop();
            }
            return w;
        }
};
