class Solution 
{
    public:
        vector<int> findClosestElements(vector<int>& arr, int k, int x) 
        {
            priority_queue<pair<int, int>> maxHeap;
            for(auto num: arr)                           // n elements => TC: O(n)
            {
                maxHeap.push({abs(num-x), num});         // push in max heap of k elements => TC: O(log k)
                if(maxHeap.size() > k)
                    maxHeap.pop();                       // pop from max heap of k elements => TC: O(log k)
            }                                            // Loop TC: O(n log k)
            vector<int> ans;
            ans.reserve(k);
            while(k--)                                   // k elements => TC: O(k)               
            {
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();                           // pop from max heap of k elements => TC: O(log k)
            }                                            // Loop TC: O(k log k)
            sort(ans.begin(), ans.end());                // Sort TC: O(k log k)
            return ans;                                  // Overall TC: O((n+k) log k) = O(n log k) since k <= n
        }
};
