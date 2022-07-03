class Solution 
{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) 
        {
            unordered_map<int, int> freq;
            for(auto i: nums)                                     // n elements => TC: O(n)
            {
                freq[i]++;
            }
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
            for(auto it = freq.begin(); it != freq.end(); it++)  // n elements => TC: O(n)
            {
                minHeap.push(make_pair(it->second, it->first));  // push in min heap of k elements => TC: O(log k)
                if(minHeap.size() > k)
                    minHeap.pop();                               // pop from min heap of k elements => TC: O(log k)
            }                                                    // Loop TC: O(n log k)
            vector<int> ans;
            ans.reserve(k);
            while(k--)                                           // k elements => TC: O(k)
            {
                ans.push_back(minHeap.top().second);             
                minHeap.pop();                                   // pop from min heap of k elements => TC: O(log k)
            }                                                    // Loop TC: O(k log k)
                                                                 // Overall TC: O((n+k) log k) = O(n log k)
            return ans;
        }
};
