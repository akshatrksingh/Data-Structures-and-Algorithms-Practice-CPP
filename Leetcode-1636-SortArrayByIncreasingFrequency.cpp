class Comparator 
{
    public:
      bool operator() (const pair<int, int> &a, const pair<int, int> &b) 
      {
        if (a.first == b.first) 
            return a.second < b.second;
        else
            return a.first > b.first;
      }
};
class Solution 
{
    public:
        vector<int> frequencySort(vector<int>& nums) 
        {
            unordered_map<int, int> freq;
            for(int num: nums)
            {
                freq[num]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> minHeap;
            for(auto it = freq.begin(); it != freq.end(); it++)
            {
                minHeap.push(make_pair(it->second, it->first));
            }
            vector<int> ans;
            while(!minHeap.empty())
            {
                int freq = minHeap.top().first;
                int num = minHeap.top().second;
                for(int i = 0; i < freq; i++)
                    ans.push_back(num);
                minHeap.pop();
            }
            return ans;
        }
};
