#define PSI pair <string, int>

class Compare
{
    public:
        bool operator()(PSI &a, PSI &b)
        {
            if(a.second == b.second)
            {
                return a.first > b.first;
            }
            else
            {
                return a.second < b.second;
            }
        }
};

class Solution 
{
    public:
        vector<string> topKFrequent(vector<string>& words, int k) 
        {
            unordered_map<string, int> freq;
            for(string &word: words)
            {
                freq[word]++;
            }
            unordered_set<string> s(words.begin(), words.end());
            priority_queue<PSI, vector<PSI>, Compare> pq;
            for(const string &word: s)
            {
                pq.push({word, freq[word]});
            }
            vector<string> ans;
            while(k--)
            {
                ans.push_back(pq.top().first);
                pq.pop();
            }
            return ans;
        }
};
